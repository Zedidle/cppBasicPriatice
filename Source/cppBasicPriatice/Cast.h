#include <iostream>
using namespace std;


namespace Cast
{

	// ====================================
	// const_cast 
	class B {
	public:
		int m_iNum;
		B() {}
	};


	void const_Test(){
		const int i = 100;
		int i2 = const_cast<int&>(i);
		//i = 101;	// 仍是常量，无法修改
		cout << "&i:" <<&i <<endl;
		i2 = 102;
		cout << "&i2:" <<&i2 <<endl;



		cout << endl;
		const B b1;  // 意思只是没法通过 b1这个入口来写，只能读 
		cout << "&b1 地址:" << &b1 << endl;
		cout << "b1.m_iNum:" << b1.m_iNum << endl;
		//b1.m_iNum = 200;  // 无法修改，对象是常量
		B b2 = const_cast<B&>(b1); // 额外申请了一块内存
		b2.m_iNum = 200;
		cout << "&b2 额外申请了一块地址内存:" << &b2 << endl;
		cout << "b1.m_iNum:" << b1.m_iNum << endl;

		B* b3 = const_cast<B*>(&b1); // b3指针 指向内存是b1数据的内存，却能写
		b3->m_iNum = 300;
		cout << "&b3 额外的指针地址内存:" << &b3 << endl;
		cout << "b3:" << b3 << endl; 
		cout << "b1.m_iNum:" << b1.m_iNum << endl;

		B& b4 = const_cast<B&>(b1); // b4引用 所在内存是b1数据的内存，却能写
		b4.m_iNum = 400;
		cout << "&b4 并没有额外内存:" << &b4 << endl;
		cout << "b1.m_iNum:" << b1.m_iNum << endl;
	}





	class Base {
		public:
		virtual void SayHello() {
			cout << "Base Hello" <<endl;
		} 
	};

	class Driver: public Base {
		public:
			virtual void SayHello() override {
				cout << "Driver Hello" << endl;
			}
	};

	// =====================================
	// static_cast
	void static_Test() {
		int i = 100;
		float i2 = static_cast<float>(i);
		double i3 = static_cast<double>(i);

		cout << "i:" << i <<endl;
		cout << "i2:" << i2 <<endl;
		cout << "i3:" << i3 <<endl;

		cout << endl;
		Base* b = new Base;
		Driver* d = new Driver;

		b->SayHello();
		d->SayHello();
		cout <<endl;
		Base* bb = static_cast<Base*>(d);
		Driver* dd = static_cast<Driver*>(b);
		bb->SayHello();
		dd->SayHello();
	}





	// ====================================
	// dynamic_cast
	void dynamic_Test() {

	}



	// ====================================
	// reinterpret_cast
	void reinterpret_Test() {

	}
}