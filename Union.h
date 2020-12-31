#include <iostream>
using namespace std;

#include "string"

static union {
	int i;
	double d;
};

namespace Union
{
	union UnionTest {
		UnionTest() : i(10){};
		int i;
		double d;
		float f;
		int arr[10];
	};


	void Test()
	{
		UnionTest u;

		union {
			int i;
			double d;
		};

		u.d = 100; // u 的其它属性会变回系统默认值
		u.f = 10.0f; // u 的其它属性会变回系统默认值
		u.i = 23; // u 的其它属性会变回系统默认值
		u.arr[0] = 23;
		std::cout << u.i << std::endl;  // 输出 UnionTest 联合的 i
		std::cout << u.d << std::endl;  // 输出 UnionTest 联合的 d
		std::cout << u.arr[0] << std::endl;  // 输出 UnionTest 联合的 f
		cout << endl;

		::i = 20;
		std::cout << ::i << std::endl;  // 输出全局静态匿名联合的 i
		std::cout << ::d << std::endl;  // 输出全局静态匿名联合的 d
		cout << endl;

		i = 30;
		std::cout << i << std::endl;    // 输出局部匿名联合的 i
		std::cout << d << std::endl;    // 输出局部匿名联合的 d



		

		cout << "sizeof(UnionTest):" << sizeof(UnionTest) << endl; // 4 * 10
		
		//cout << "sizeof(short):" << sizeof(short) << endl; // 2
		//cout << "sizeof(int):" << sizeof(int) << endl; // 4
		//cout << "sizeof(double):" << sizeof(double) << endl; // 8
		//cout << "sizeof(long):" << sizeof(long) << endl; // 4
		//cout << "sizeof(float):" << sizeof(float) << endl; // 4
	}
}
