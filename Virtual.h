#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

#define Area(x) (x * x)

int Test2() {
	return 102;
}

namespace Virtual
{
	

	class Virtualbase
	{

	public:

		virtual void Demon() = 0; //prue virtual function
		virtual void Base() { cout << "this is farther class" << endl; }
		void Hello3() {
			cout << "Virtualbase, Hello3 world" << endl;
		}

		private:
			virtual void Hello() {
				//cout << "Virtualbase, hello world" << endl;
			}
			void Hello2() {
				cout << "Virtualbase, Hello2 world" << endl;
			}
	};
	

	//sub class
	class SubVirtual :public Virtualbase
	{

	public:

		void Demon() {
			cout << " this is SubVirtual!" << endl;
		}

		void Base() {
			cout << "this is subclass Base" << endl;
		}
		virtual void Hello() override {
			__super::Hello3();
			cout << "SubVirtual, hello world" << endl;
		}
	};


	class Base {
	public:
		Base() {
			cout << "Base构造" << endl;
		}
		virtual ~Base() {
			cout << "Base虚析构" << endl;
		}

		virtual void f1() {
			cout << "Base::f1()" << endl;
		}
		void f2() {
			cout << "Base::f2()" << endl;
		}
		virtual void f3() {
			cout << "Base::f3()" << endl;
			//cout << data << endl;	
		}
		int data = 5;
		static void fn() {
		}
	};


	class Base1
	{
	public:
		int base1_1;
		int base1_2;
		virtual void base1_fun1() {}
	private:
		virtual void base1_fun2() {}
	};

	class Base2
	{
	public:
		int base2_1;
		int base2_2;

		virtual void base2_fun1() {}
	private:
		virtual void base2_fun2() {
			cout << "B2, base2_fun2" << endl;
		}
	};

	class Derive1 : public Base1
	{
	public:
		int derive1_1;
		int derive1_2;
	};


	class Derive2 : public Base1
	{
	public:
		int derive1_1;
		int derive1_2;

		// 覆盖基类函数
		virtual void base1_fun1() {}
	};

	class Derive3 : public Base1
	{
	public:
		int derive1_1;
		int derive1_2;

		// 覆盖基类函数
		virtual void derive1_fun1() {}
	};

	class Derive4 : public Base1, public Base2
	{
	public:
		int derive1_1;
		int derive1_2;

		// 基类虚函数覆盖
		virtual void base1_fun1() {}
		virtual void base2_fun2() {
			//Base2::base2_fun2(); // 无法访问基类的private;
			cout <<"D4, base2_fun2" << endl;

		}

		// 自身定义的虚函数
		virtual void derive1_fun1() {}
		virtual void derive1_fun2() {}
	};

	class Derive5 : public Derive1, public Derive2
	{
			
	};

	void Test()
	{
		Base1 b1;
		Base1 b2;
		Derive1 d1;
		Derive2 d2;
		Derive3 d3;
		Derive3* pd3 = &d3;
		pd3->derive1_fun1();
		Derive4 d4;
		d4.base2_fun2();
		Derive5 d5;

		cout << endl << "SubV: ";
		SubVirtual SubV;
		SubV.Hello();
		//SubV.Hello2();

		return;
		//Virtualbase VB;  // 由于BaseVirtual有纯虚函数，因此是抽象类，不能直接实例化
		//SubVirtual VS;
		//VS.Base();
		//VS.Demon();

		cout << sizeof(Base) << endl;

		Base* p1 = new Base();
		Base* p2 = new Base();
		cout << p1->fn << endl;		// 静态成员函数可以直接获取地址
		cout << Base::fn << endl;	// 静态成员函数可以直接获取地址

	//	cout << &Base::f1 << endl;	// 编译器将void(__thiscall A::*)()类型转换为bool类型
		printf("Base::f1()地址:%p\n", &Base::f1);
		printf("Base::f1()地址:%p\n", &Base::f1);
		printf("Base::f2()地址:%p\n", &Base::f2);
		printf("Base::fn()地址:%p\n", &Base::fn);

		cout << "p1对象地址: " << (p1) << endl;
		cout << "p1虚函数表首地址: " << (int*)(p1) << endl;
		cout << "p1虚函数表中第1个虚函数地址: " << (int*)*(int*)(p1) << endl;
		cout << "p1虚函数表中第2个虚函数地址: " << ((int*)*(int*)(p1)+1) << endl;
		cout << "p1虚函数表中第3个虚函数地址: " << ((int*)*(int*)(p1)+2) << endl;
		cout << "p1虚函数表中第4个虚函数地址: " << ((int*)*(int*)(p1)+3) << endl;

		cout << endl;
		cout << "p2对象地址: " << (p2) << endl;
		cout << "p2虚函数表首地址: " << (int*)(p2) << endl;
		cout << "p2虚函数表中第1个虚函数地址: " << (int*)*(int*)(p2) << endl;
		cout << "p2虚函数表中第2个虚函数地址: " << ((int*)*(int*)(p2)+1) << endl;
		cout << "p2虚函数表中第3个虚函数地址: " << ((int*)*(int*)(p2)+2) << endl;
		cout << "p2虚函数表中第4个虚函数地址: " << ((int*)*(int*)(p2)+3) << endl;

		cout << endl;

		typedef void(*PFUN)();

		PFUN pfBase = (PFUN) * ((int*)*(int*)p1 + 0);	// 析构
		PFUN pf1 = (PFUN) * ((int*)*(int*)p1 + 1);	// f1
		PFUN pf2 = (PFUN) * ((int*)*(int*)p1 + 2);	// f2
		PFUN pfnull = (PFUN) * ((int*)*(int*)p1 + 3);	//0x00
		pf1();
		pf2();	// 如果函数中有类成员变量，这样调用会出错。普通变量不会。和this指针有关。
	}
}