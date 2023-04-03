#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace T1
{
	template <class T>
	T twice(T t) {
		return t * 2;
	}
	std::string twice(std::string t) {
		return t + t;
	}

	// 打印一个vector
	template<class T>
	void print(vector<T> const& a) {
		cout << "{";
		for (size_t i = 0; i < a.size(); i++) {
			cout << a[i];
			if (i != a.size() - 1) {
				cout << ", ";
			}
		}
		cout << "}" << endl;
	}

	template <class T>
	ostream& operator <<(ostream& os, vector<T> const& a) {
		os << "{";
		for (size_t i = 0; i < a.size(); i++) {
			os << a[i];
			if( i != a.size() - 1)
				os << ", ";
		}
		os << "}";
		return os;
	}


	void Test() {
		//cout << twice(21) << endl;
		//cout << twice(3.14f) << endl;
		//cout << twice(2.718) << endl;
		//cout << twice("hello") << endl;

		vector<int> a = {1, 4, 2, 8, 5, 7};
		vector<double> b = {3.14, 2.567, 0.618};
		//print(a);
		//print(b);

		//cout << a << endl;
		//cout << b << endl;

		cout << is_same_v<int *const, const int*> << endl;


		

	}
}