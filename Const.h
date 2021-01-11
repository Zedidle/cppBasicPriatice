#include <iostream>
#include <vector>
using namespace std;


namespace Const
{
	class A
	{
	private:
		int b;

	public:
		const int a = 100;                // 常对象成员，只能在初始化列表赋值
		// 构造函数
		A() : a(0) { };
		A(int x) : a(x) { };        // 初始化列表

		// const可用于对重载函数的区分
		//int getValue();             // 普通成员函数
		int getValue() const;       // 常成员函数，不得修改类中的任何数据成员的值
	};

	int A::getValue() const
	{	
		return b;
	}

	void Test1()
	{
		// 对象
		A b;                        // 普通对象，可以调用全部成员函数、更新常成员变量
		const A a;                  // 常对象，只能调用常成员函数
		const A* p = &a;            // 指针变量，指向常对象
		const A& q = a;             // 指向常对象的引用

		A* cc = new A(10);
		cout << "cc->a:" << cc->a << endl;

		// 指针
		char greeting[] = "Hello";
		char* p1 = greeting;                // 指针变量，指向字符数组变量
		const char* p2 = greeting;          // 指针变量，指向字符数组常量（const 后面是 char，说明指向的字符（char）不可改变）
		char* const p3 = greeting;          // 自身是常量的指针，指向字符数组变量（const 后面是 p3，说明 p3 指针自身不可改变）
		const char* const p4 = greeting;    // 自身是常量的指针，指向字符数组常量
	}



	static void Test()
	{
		//vector<const int> Arr;
		//Arr.push_back(1);
		//Arr.push_back(2);
		////Arr[1] = 3; // 不允许改变
		//Arr.pop_back();
		//Arr.push_back(3);
		//cout << "Arr:" << Arr[0] << Arr[1] <<endl;

		int a = 1, b = 2;
		int* const p1 = &a;  // 自身是常量的指针
		const int* p2 = &a;  // 指向常量的指针

		//p1 = &b; // 不可修改
		a = 10;
		p2 = &b;
		cout << "*p1:" << *p1 << endl;
		cout << "*p2:" << *p2 << endl;
	}


}