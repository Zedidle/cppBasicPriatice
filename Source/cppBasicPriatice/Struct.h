#include <iostream>
#include <vector>
using namespace std;


// 相较class，struct的默认继承权限和默认成员访问权限都是public

namespace Struct
{
	struct Cup
	{
		float Height = 10;
		void GetHeight()
		{
			cout << Height << endl;
		}
	};


	void Test()
	{
		Cup* cup = new Cup();
		cup->GetHeight();
	}
}