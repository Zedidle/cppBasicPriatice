#include <iostream>
#include <vector>
#include "test.h"
using namespace std;


namespace Static
{


	static int S;

	class A
	{
	public:
		A() {}
			
		public:
			static int value;
			static void SetValue(int v)
			{
				value = v;
			}
			static void PrintValue()
			{
				cout << "PrintValue:" << value << endl;
			}
	};
	int A::value;  // 默认值初始化为 0


	class B
	{
	public:
		B(int v2 = 0):value2(v2) {}

	public:
		int value2;
		static int value;
		static void SetValue(int v)
		{
			value = v;
			//value2 = 2 * v; // 不能访问
			//PrintValue(); // 不能访问
		}
		void PrintValue()
		{
			cout << "PrintValue:" << value  << endl;
			cout << "PrintValue2:" << value2  << endl;
		}
	};
	int B::value;

	static void Test()
	{
		cout << S <<endl;

		A::SetValue(20);
		A::PrintValue();
		A a;
		a.PrintValue();
		A a2;
		a2.PrintValue();
		B b;
		b.SetValue(2);
		b.PrintValue();


	}

	static void Test2() {
		Test();
	}
}