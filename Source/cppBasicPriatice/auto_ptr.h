#pragma once
#include "iostream"
using namespace std;


namespace Autoptr{
	class A_Test{
		public:
			void SayHello(){
				cout << "A_Test Hello" << endl;
			}
			~A_Test() {
				cout << "A_Test Destruct" << endl;
			}
	};

	void bad_print(auto_ptr<A_Test> ptr) {
		ptr->SayHello();
	}

	void bad_print_const(const auto_ptr<A_Test> ptr) {
		ptr->SayHello();
	}

	void Test()
	{
		auto_ptr<A_Test> ptr1(new A_Test);
		//auto_ptr<A_Test> ptr2 = new A_Test; // Error
		ptr1->SayHello();

		auto_ptr<A_Test> ptr2(ptr1); // 移交控制权
		ptr2->SayHello();

		//const auto_ptr<A_Test> ptr3(new A_Test); // 不再允许移交控制权，既不能作为右值，也不能被赋值
		auto_ptr<A_Test> ptr3(new A_Test);
		ptr3->SayHello();
		ptr3 = ptr2; // 导致ptr3原先的A_Test对象被delete，且移交ptr2的对象的控制权给ptr3；

		cout << endl;
		// 函数的auto_ptr参数依然会导致 移交控制权
		//bad_print(ptr2);
		ptr3->SayHello(); // 已经移交控制权，报错！！
		
		cout << endl;



	}
}