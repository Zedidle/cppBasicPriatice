#include <iostream>
using namespace std;


namespace Align
{
	
	struct Test
	{
		int b;
		short c;
		char a;
	};


	void Test()
	{
		cout << "alignof int:" << alignof(int) << endl;
		cout << "alignof short:" << alignof(short) << endl;
		cout << "alignof long:" << alignof(long) << endl;
		cout << "alignof char:" << alignof(char) << endl;
	}
}
