#include "iostream"
using namespace std;
#include "vector"



namespace Delegate
{

	
	// ================================================================================================
	// 原理：
	class A
	{
		public:
			void Func(int i) {
				cout << "A:" << i << endl;
			}

			int Add2(int a, int b) {
				return a + b;
			}
	};

	

	// 用*pFuncxxx 的方式定义一个A里面的函数；需要知道函数在类看来就是直接一个指向代码区函数地址的指针；
	// 要理解定义函数指针的方式有多么的坑
	void (A::*pFunc)(int) = &A::Func;  // 在A里面申请了pFunc指针指向Func的入口；
	int (A::*pFunc_Add2)(int, int) = &A::Add2;

	void Test44() {
		cout << "44" << endl;
	}
	void (*void_Test)() = Test44;  // 实际上只有 void 为返回类型， *void_Test 是关键名字， ()说明是一个函数且不用参数
	void (*void_Test2)() = &Test44;  // 实际上只有 void 为返回类型， *void_Test 是关键名字， ()说明是一个函数且不用参数

	int Test45() {
		return 45;
	}
	int (*int_Test)() = Test45;
	int (*int_Test2)() = &Test45;

	int Test46(int a, int b) {
		return 46 + a * b;
	}
	int (*int_Test_2)(int, int) = Test46;
	int (*int_Test2_2)(int, int) = &Test46;

	void Test()
	{
		// 原理： 
		// 第一种方式是通过对象本身来调用，第二种方式是通过对象指针来调用，两种方式的效果都是一样的。
		// .*和->*都是特殊的操作符，不必纠结于它们奇怪的样子，只要知道它们只用于调用成员函数指针就行了。
		cout << "原理：" << endl;
		A a;
		(a.*pFunc)(10);
		//A* pa = &a;  // 这样也行
		A* pa = new A();
		(pa->*pFunc)(11);

		cout << endl;
		cout << (pa->*pFunc_Add2)(10, 20) << endl;  // *pFunc_Add2:拿到 A::Add2 函数的入口地址... 

		cout << endl;
		(*void_Test)();
		void_Test();
		cout << endl;

		cout << (*int_Test)() << endl;
		cout << int_Test2() << endl;
		cout << endl;

		cout << (*int_Test_2)(20, 40) << endl;
		cout << (*int_Test2_2)(20, 40) << endl;
		cout << endl;


	}





	// ==================================================================================================

	// 第一步：使用类模板，单播委托
	// 要调用一个成员函数，仅仅有成员函数指针是不够的，还需要一个对象指针，所以要用一个类将两者绑到一起。由于对象的类型是无穷多的，所以这里必须使用类模板：
	template <typename T>
	class DelegateHandler {
	public:
		DelegateHandler(T* pT, void (T::* pFunc)(int)):  m_pT(pT), m_pFunc(pFunc) { }

		void Invoke(int value)
		{
			(m_pT->*m_pFunc)(value);
		}

	private:
		T* m_pT;
		void (T::* m_pFunc)(int);
	};

	// 到这里产生了一个问题：如果希望调用的目标是非成员函数，怎么办？上面的类模板无法调用非成员函数，不过使用模板偏特化就可以解决这个问题：
	template<>
	class DelegateHandler<void> {
	public:
		DelegateHandler(void (*pFunc)(int))
			: m_pFunc(pFunc) { }

		void Invoke(int value) {
			(*m_pFunc)(value);
		}

	private:
		void (*m_pFunc)(int);
	};

	void Test1(){
		// 第一步： 类模板做法
		cout << "第一步： 类模板做法" << endl;

		A a;
		DelegateHandler<A> DelegateHandler_A(&a, &A::Func);
		DelegateHandler_A.Invoke(100);
	}









	// ================================================================================================

	class B
	{
	public:
		void Func(int i)
		{
			cout << "B:" << i << endl;
		}
	};

	void HandleVoidFunc0()
	{
		cout << "HandleVoidFunc0:" << 1000 << endl;
	}

	void HandleVoidFunc(int i)
	{
		cout << "HandleVoidFunc:" << i << endl;
	}


	// 第二步：使用多态， 多播委托
	class IDelegateHandler{  // 为了实现多态的抽象类
	public:
		virtual ~IDelegateHandler() {}
		virtual void Invoke(int i) = 0; // 注意这里的是单参数 int；
	};

	template<typename T>
	class DelegateHandler2 : public IDelegateHandler{ // 模板可以实现多个类的同种函数的同时调用

	public:
		DelegateHandler2(T* pT, void (T::* pFunc)(int)) : m_pT(pT), m_pFunc(pFunc) { }
		virtual void Invoke(int value) override {
			(m_pT->*m_pFunc)(value);
		}

	private:
		T* m_pT;
		void (T::* m_pFunc)(int);

	};

	// 类模板特化
	template<>
	class DelegateHandler2<void> : public IDelegateHandler {

	public:
		DelegateHandler2(void (*pFunc)(int)) : m_pFunc(pFunc) { }
		virtual void Invoke(int i) override {
			(*m_pFunc)(i);
		}
	private:
		void (*m_pFunc)(int);
	};

	class DelegateHandlers { 
		vector<IDelegateHandler*> handlers;  // 通过多态搞它一手 
		public:
			void Push(IDelegateHandler* handle) {
				handlers.push_back(handle);
			}
			void Invoke(int i) {  // 所以这里也必须是单参数
				// 多播委托调用
				for (auto it = handlers.cbegin(); it != handlers.cend(); ++it) {
					(*it)->Invoke(i); // 其实还是Invoke还是让他们调用自己的Invoke；
				}
			}
	};

	void Test2(){
		// 第二步：使用多态， 实现 多播委托
		cout << endl;
		cout << "第二步：使用多态， 目标是 多目标的委托" << endl;
		A a;
		B b;
		DelegateHandler2<A> DelegateHandler2_A(&a, &A::Func);
		DelegateHandler2<B> DelegateHandler2_B(&b, &B::Func);
		DelegateHandler2<void> DelegateHandler2_void(HandleVoidFunc);

		DelegateHandlers handlers;
		handlers.Push(&DelegateHandler2_A);
		handlers.Push(&DelegateHandler2_B);
		handlers.Push(&DelegateHandler2_void);
		handlers.Invoke(17); 
	}



// ================================================================================================

// 第三步：使用宏， 这应该是也是 UE4的做法
/* 关键点：
	1. 对 __VA_ARGS__ 的理解 （可变参数宏）
	2. 对宏定义的理解（编译的 预处理 阶段：文件包含 - 条件编译 - 宏展开）
*/
// 函数参数的声明可以只有类型而没有名称，但是为了在函数内使用参数，该参数必须有名称
#define DECLARE_PARAMS(...) __VA_ARGS__	 // 形参列表
#define DECLARE_ARGS(...) __VA_ARGS__	 // 实参列表

	//0个参数的委托
#define DELEGATE0(retType, name) \
		DECLARE_DELEGATE(retType, name, DECLARE_PARAMS(void), )
			
	//1个参数的委托
#define DELEGATE1(retType, name, p1) \
		DECLARE_DELEGATE( \
			retType, \
			name, \
			DECLARE_PARAMS(p1 a), \
			DECLARE_ARGS(a))

	//2个参数的委托
#define DELEGATE2(retType, name, p1, p2) \
		DECLARE_DELEGATE( \
			retType, \
			name, \
			DECLARE_PARAMS(p1 a, p2 b), \
			DECLARE_ARGS(a, b))

	//3个参数的委托
#define DELEGATE3(retType, name, p1, p2, p3) \
		DECLARE_DELEGATE( \
			retType, \
			name, \
			DECLARE_PARAMS(p1 a, p2 b, p3 c), \
			DECLARE_ARGS(a, b, c))

	//4个参数的委托
#define DELEGATE4(retType, name, p1, p2, p3, p4) \
		DECLARE_DELEGATE( \
			retType, \
			name, \
			DECLARE_PARAMS(p1 a, p2 b, p3 c, p4 d), \
			DECLARE_ARGS(a, b, c, d))


#define DECLARE_DELEGATE(retType, name, params, args)								\
		class I##name {                                                               \
		public:                                                                       \
			virtual ~I##name() { }                                                    \
			virtual retType Invoke(params) = 0;                                       \
		};                                                                            \
		template<typename T>                                                          \
		class name : public I##name {                                                 \
		public:                                                                       \
			name(T* pType, retType (T::*pFunc)(params))                               \
				: m_pType(pType), m_pFunc(pFunc) { }                                  \
			retType Invoke(params) {                                                  \
				return (m_pType->*m_pFunc)(args);                                     \
			}                                                                         \
		private:                                                                      \
			T* m_pType; \
			retType (T::*m_pFunc)(params);											\
		};                                                                            \
		template<>                                                                    \
		class name<void> : public I##name {                                           \
		public:                                                                       \
			name(retType (*pFunc)(params))                                            \
				: m_pFunc(pFunc) { }                                                  \
			retType Invoke(params) {                                                  \
				return (*m_pFunc)(args);                                              \
			}                                                                         \
		private:                                                                      \
			retType (*m_pFunc)(params);                                               \
		};\
		class DelegateHandlers_##name {												\
			vector<I##name*> handlers; 												\
		public:																		\
			void Push(I##name * handle) {											\
				handlers.push_back(handle);											\
			}																		\
			void Invoke(params) {													\
				for (auto it = handlers.cbegin(); it != handlers.cend(); ++it) {	\
					(*it)->Invoke(args);											\
				}																	\
			}																		\
		};																			\
		

	DELEGATE0(void, Delegate0_Void);   // 声明了代理
	DELEGATE1(void, Delegate1_Void, int);

	void Test3(){
		cout << endl;
		cout << "第三步：使用宏" << endl;
		Delegate0_Void<void> Void_Handler0(HandleVoidFunc0);  // 这就定义了一个 Void_Handler0 的代理，意味着返回值void，参数为空；
		Void_Handler0.Invoke();
		cout << endl;

		Delegate1_Void<void> Void_Handler1(HandleVoidFunc);
		Void_Handler1.Invoke(100);
		cout << endl;

		A a; B b;
		Delegate1_Void<A> A_Handler1(&a, &A::Func);
		Delegate1_Void<B> B_Handler1(&b, &B::Func);
		A_Handler1.Invoke(10);
		B_Handler1.Invoke(100);


		//DelegateHandlers_Delegate1_Void handlers;
		//handlers.Push(A_Handler1); // 为什么不行呢？
		//handlers.Push(B_Handler1);
		//handlers.Invoke(10);

	}


}