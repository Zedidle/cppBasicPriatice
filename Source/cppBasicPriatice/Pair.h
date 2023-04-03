#pragma once
#include "iostream"
using namespace std;


namespace Pair
{
	void foo(pair<int, const char*> e) {
		cout << "f: " << e.first << ", " << e.second << endl;
	}

	void Test()
	{
		pair<int, int> b = {20, 40};
		pair<int, int> a(b);
		pair<int, string> c = make_pair(0, "a"); // make_pair 十分有用
		pair<int, string> d = {1, "b"}; // 一样有用
		pair<int, const char> e = {1, 'c'}; // 一样有用
		pair<int, const char*> f = {1, "ccc"}; // 一样有用
		cout << a.first << ", " << a.second << endl;
		cout << b.first << ", " << b.second << endl;
		cout << c.first << ", " << c.second << endl;
		cout << d.first << ", " << d.second << endl;
		cout << e.first << ", " << e.second << endl;
		cout << f.first << ", " << f.second << endl;
		foo({2, "fff"});
	}
}