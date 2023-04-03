#pragma once

#include "iostream"
using namespace std;
#include "vector"

namespace Derived
{
	class A
	{
		//int a1;
		int a2;
	};
	
	class B : public A
	{
		int b1;
		int b2;
	};

	class C : public A
	{
		int c1;
		int c2;
	};

	class D : public B, public C
	{

	};

	void Test()
	{
		D d;
		cout << "sizeof(int): " << sizeof(int) << endl;
		cout << "sizeof(d): " << sizeof(d) << endl;
	}

}
