#include <iostream>
using namespace std;

int Test() {
	return 10l;
}

#define Area(x) (x * x)
//#define Factorial(x) (Area(x) * Test2() * x-1 * x)  // Test2() 是从Virtual读到的，在Main.cpp中，include顺序Define.h在Virtual.h之后。
#define Factorial(x) (Area(x) * Test() * x-1 * x)


#define Conn(x,y) x##y
#define CONS(a,b)  int(a##a##b) 
#define ToChar(x) #@x
#define ToString(x) #x

// 可变参数的宏 __VA_ARGS__
#define test1(...) printf(__VA_ARGS__)
#define test2(fmt, ...) printf(fmt, __VA_ARGS__)


namespace Define
{
	void GetArea(int x)
	{
		cout << Area(x) << endl;
	}

	void GetFactorial(int x)
	{
		cout << Factorial(x) << endl;
	}



	void Test()
	{
		Define::GetArea(10);
		Define::GetFactorial(10);
		cout << Conn("AA", "BB") << endl;
		cout << ToChar("2d") << endl;
		cout << ToString("AAAdsadsadewedqw") << endl;
		cout << CONS("A", "B") << endl;
		cout << endl << endl;

		int i = 10;
		float f = 3.1415926;
		const char* s = "Hello, zedidle!";
		test1("test1: i = %d, f = %g, s = %s\n", i, f, s);
		test2("test2: i = %d, f = %g, s = %s\n", i, f, s);
	}
}