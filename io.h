#include <iostream>
#include <vector>
#include <algorithm>
#include "string"
using namespace std;


namespace IO
{

	int GetNum1(int num)
	{
		int r = 0;
		while (num > 0)
		{
			if (num % 2 == 1)
			{
				++r;
			}
			num = num >> 1;
		}
		return r;
	}


	void Test()
	{
		// 如果不是getline，一个cin>> 不能有空格,有的话会传到下一个cin
		//string name;
		//string city;
		//cout << "Please enter your name: ";
		//cin >> name;
		//cout << "Enter the city you live in: ";
		//cin >> city;
		//cout << "Hello, " << name << endl;
		//cout << "You live in " << city << endl;


		//cout << endl << endl;

		// getline 的作用：允许输入空格连接
		//string name2;
		//string city2;
		//cout << "Please enter your name: ";
		//getline(cin, name2);
		//cout << "Enter the city you live in: ";
		//getline(cin, city2);
		//cout << "Hello, " << name2 << endl;
		//cout << "You live in " << city2 << endl;


		//cout << GetNum1(63) << endl;
		//int t;
		//int n = 4;
		//vector <int> a;
		//while (cin >> t && n-- > 0)
		//{
		//	cout << t << endl;
		//	a.push_back(t);
		//}
		//sort(a.begin(), a.end());
		//for (auto value : a)
		//{
		//	cout << value <<" ";
		//}


		string str;
		vector<string> str_vec;

		while (getline(cin, str))
		{
			string tmp;
			for(int i=0;i<str.size();i++)
			{
				cout << str[i] << endl;
			}
		}
	}
}

