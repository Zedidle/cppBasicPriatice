#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;

namespace Template
{
	// ===================================================
	// 函数模板测试
	template<typename T, typename T1>
	void SayHello(T a, T1 b) {
		cout << "SayHello0:" << a << "，" << b << endl;
	}
	template<>
	void SayHello(float a, float b) { // 不知如何用上
		cout << "SayHello1:" << a << "，" << b << endl;
	}
	template<>
	void SayHello(double a, int b) {
		cout << "SayHello2:" << a << "，" << b << endl;
	}
	template<>
	void SayHello(int a, double b) {
		cout << "SayHello3:" << a << "，" << b << endl;
	}
	template<>
	void SayHello(int& a, int& b) {	// 不知如何用上
		cout << "SayHello4:" << a << "，" << b << endl;
	}
	template<>
	void SayHello(int* a, int* b) {
		cout << "SayHello5:" << *a << "，" << *b << endl;
	}

	void Test6() {
		SayHello('a', 'b'); // 0 默认
		SayHello(5, 55);	// 0 默认
		SayHello(10.2, 5);	// 2 最匹配 double, int
		SayHello(5, 55.5);  // 3 最匹配 int, double
		int a = 100, b = 200;
		int *pa = &a, *pb = &b;
		SayHello(a, b);		// 0 默认；
		SayHello(pa, pb);	// 5 同样匹配，最特殊的优先，有 * ；
	}


	// ================================================
	// 特例化的是成员，而不是类
	template <typename T> struct Foo {
		Foo(const T &t = T()): mem(t){}
		void Bar() {
			cout << "BarBar" <<endl;
		}
		T mem;
		// Foo 的其他成员
	};

	template<>
	void Foo<int>::Bar() {
		cout <<"int BarBar" <<endl;
	}

	void Test5() {
		Foo<string> fs;
		fs.Bar();
		Foo<int> fi;
		fi.Bar();
	}



	// =============================================================

	// 模板，最特化匹配
	template<typename T0, typename T1, typename T2>
	struct S {
		void id(){ cout<< "General" << endl; }
	};

	template<typename T0, typename T1>
	struct S<T0, T1, char>{
		void id() { cout << "Special case #1" << endl; }
	};

	template<typename T0>
	struct S<T0, char, char>{
		void id() { cout << "Special case #2" << endl; }
	};

	template<typename T>
	struct S<int, T, T>{
		void id() { cout << "Special case #3" << endl; }
	};

	template<typename T>
	struct S<int*, T*, T*> {
		void id() { cout << "Special case #4" << endl; }
	};

	template<typename T>
	struct S<int&, T&, T&> {
		void id() { cout << "Special case #5" << endl; }
	};


	template <typename T>
	T GetMax(T a, T b) { 
		cout << "原版: " << endl;
		cout << typeid(T).name() << endl;
		return a > b ? a : b;
	}

	template <typename T>
	T GetMax(T* a, T* b) {
		cout << "重载: " << endl;
		cout << typeid(T).name() << endl;
		return *a > * b ? *a : *b;
	}

	template <>
	char GetMax(char* a, char* b) {
		cout << "模板函数全特化: " << endl;
		return *a > * b ? *a : *b;
	}

	char GetMax(char* a, char* b) {
		cout << "普通函数: " << endl;
		return *a > * b ? *a : *b;
	}

	template <>
	int GetMax(int a, int b) {
		cout << "int 模板函数全特化: " << endl;
		return a > b ? a : b;
	}

	int GetMax(int a, float b) {
		cout << "int 普通函数: " << endl;
		return a > b ? a : b;
	}



	void Test4() {
		S<float, float, float>().id(); // General
		S<char, char, int>().id();	// General
		S<int, int, char>().id();	// Special case#1
		S<char, char, char>().id();	// Special case#2
		S<int, int, int>().id();	// Special case#3
		S<int*, int*, int*>().id();	// Special case#4
		S<int&, int&, int&>().id();	// Special case#5
		//S<int, char, char>().id(); // 编译器无法决定模板的特殊性顺序

		cout << endl;

		char a = 'k';
		char b = 'p';
		cout << GetMax(a, b) << endl;  // 会选择 1；
		cout << GetMax(&a, &b) << endl;  // 会选择 2 非模板函数具有优先权；
		// 同名模板函数构成重载关系，在调用时，根据实参类型，编译器会选择最匹配的模板函数进行实例化；

		int i2 = 10, i3 = 20;
		cout << GetMax(i2, i3) << endl;
	}


	// =============================================================

	// 指针常数和常数指针

	template<typename T> void f(T a) {
		cout << a << endl;
	};
	template<typename T> void f(const T* a) {
		cout << a << endl;
	};
	template<typename T> void g(T a) {
		cout << a << endl;
	};
	template<typename T> void g(T* a) {
		cout << *a << endl;
	};


	void Test3() {
		int i = 30;
		int *p = &i;
		const int ci = 20, *p2 = &ci;
		g(42); g(p); g(ci); g(p2);
		cout << endl;
		f(42); f(p); f(ci); f(p2);
	}

	// =======================================================



	// DebugDelete

	class DebugDelete {
	public:
		DebugDelete(std::ostream& s = std::cerr) : os(s) { }
		template <typename T> void operator() (T* p) const {
			os << "deleting unique_ptr" << std::endl;
			delete p;
		}
	private:
		std::ostream& os;
	};

	template<unsigned N, unsigned M>
	int less(const char(&p1)[N], const char(&p2)[M]) {
		return strcmp(p1, p2);
	}

	template <typename T, typename F = less<T>>
	int compare(const T& v1, const T& v2, F f = F()) {
		if (f(v1, v2)) return -1;
		if (f(v2, v1)) return 1;
		return 0;
	}



	template <typename T> int compare(const T& v1, const T& v2) {
		if (less<T>()(v1, v2)) return -1;
		if (less<T>()(v2, v1)) return 1;
		return 0;
	}

	void Test2() {
		cout << "Test2" << endl;
		cout << less("ZhZi", "mon") << endl;
		
		double* p = new double;
		DebugDelete d;	// 可像delete 表达式一样使用的对象
		d(p);	// 调用 DebugDelete::operator()(double*), 释放p
		int* ip = new int;
		// 在一个临时DebugDelete对象上调用operator()(int*);
		DebugDelete()(ip);

	}










	// =====================================================

	// Stack / Student 对模板的最基础运用
	template <typename T>
	class Stack {
	private:
		vector<T> elems;     // 元素 

	public:
		void push(T const&);  // 入栈
		void pop();               // 出栈
		T top() const;            // 返回栈顶元素
		bool empty() const {       // 如果为空则返回真。
			return elems.empty();
		}
	};

	template <class T>
	void Stack<T>::push(T const& elem)
	{
		// 追加传入元素的副本
		elems.push_back(elem);
	}

	template <class T>
	void Stack<T>::pop()
	{
		if (elems.empty()) {
			throw out_of_range("Stack<>::pop(): empty stack");
		}
		// 删除最后一个元素
		elems.pop_back();
	}

	template <class T>
	T Stack<T>::top() const
	{
		if (elems.empty()) {
			throw out_of_range("Stack<>::top(): empty stack");
		}
		// 返回最后一个元素的副本 
		return elems.back();
	}




	class Student
	{

	private:
		string Name;

	public:
		Student();
		Student(string n);
		Student(const Student& s)
		{
			Name = s.Name;
		}


		string GetName();

		Student& operator+(const Student& s)
		{
			Name.append(s.Name);
			return *this;
		}

		Student& operator-(const Student& s)
		{
			Name = "";
			return *this;
		}


	};

	Student::Student() {}
	Student::Student(string n)
	{
		Name = n;
	}

	string Student::GetName()
	{
		return Name;
	}

	template <typename T>
	void swap(T& x, T& y)
	{
		T t = x;
		x = y;
		y = t;
	}

	template<typename T1, typename T2>
	T2 Catch(T1 op, T2 t2, T2 t3)
	{
		if (op)
		{
			return t2 + t3;
		}
		else
		{
			return t2 - t3;
		}
	}


	void Test()
	{
		// 模板类
		try {
			Template::Stack<int>  intStack;  // int 类型的栈 
			Template::Stack<string> stringStack;    // string 类型的栈 

			// 操作 int 类型的栈 
			intStack.push(7);
			cout << intStack.top() << endl;

			// 操作 string 类型的栈 
			stringStack.push("hello");
			cout << stringStack.top() << std::endl;
			stringStack.pop();
			stringStack.pop();
		}
		catch (exception const& ex) {
			cerr << "Exception: " << ex.what() << endl;
			//return -1;
		}

		// 运算符重载、模板函数
		cout << endl;
		int x = 5, y = 10;
		cout << "x:" << x << "  y:" << y << endl;
		//
		Template::swap<int>(x ,y);
		cout << "x:" << x << "  y:" << y << endl;

		cout << endl;
		string s1 = "zzz", s2 = "fff";
		cout << "s2:" << s2 << "  s1:" << s1 << endl;

		Template::swap<string>(s2, s1);
		cout << "s2:" << s2 << "  s1:" << s1 << endl;
		cout << endl << endl;


		cout << "Catch: " << Template::Catch(true, 10, 15) << endl;
		cout << "Catch: " << Template::Catch(false, 10, 15) << endl;
		cout << endl << endl;

		Student A("Z"), B("A");
		Student C = A;
		Student* D = new Student("KK");
		cout << "S Catch: " << Template::Catch(false, A, B).GetName() << endl;
		cout << "S Catch: " << Template::Catch(true, A, B).GetName() << endl;
		cout << "S Catch: " << Template::Catch(true, C, C).GetName() << endl;
	}

	// =====================================================

}





