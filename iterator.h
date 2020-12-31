#include <iostream>
#include "list"
#include "vector"
#include "deque"
#include "set"
#include "algorithm"
using namespace std;


namespace Iterator {


	void print_int(int i) {
		cout << i << " ";
	}


	int square(int i) {
		return i * i;
	}

	bool isPrime(int num) {
		return num==5;
	}


	void Test() {
		list<int> coll1;

		for (int i = 1; i <= 9; ++i) {
			coll1.push_back(i);
		}

		vector<int> coll2;
		copy(coll1.begin(), coll1.end(), back_inserter(coll2));

		//deque<int> coll3;
		//copy(coll1.begin(), coll1.end(), front_inserter(coll3)); // 可能还没有实现

		//set<int> coll4;
		//copy(coll1.begin(), coll1.end(), inserter(coll4, coll4.begin()));  // 可能还没有实现

		cout << endl;
		for (int i = 0; i < coll1.size(); i++) {
			cout << coll2[i] << " ";
		}
		//cout << endl;
		//for (int i = 0; i < coll1.size(); i++) {
		//	cout << coll3[i] << " ";
		//}
		//cout << endl;
		//set<int>::const_iterator pos4;
		//for (pos4 = coll4.begin(); pos4 != coll4.end(); pos4++) {
		//	cout<< *pos4 <<" ";
		//}


		cout << endl<< endl;

		//vector<string> coll;
		//copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter((coll));
		//sort(coll.begin(), coll.end());
		//unique_copy(coll.begin(), coll.end(), ostream_iterator<string>(cout, "\n"));

		//list<int> list2;
		//for (int i = 0; i <= 6; ++i) {
		//	list2.push_back(i);
		//	list2.push_front(i);
		//}
		//cout << "pre:";
		//copy(list2.begin(), list2.end(), ostream_iterator<int>(cout, " "));
		//cout << endl;
		//remove(list2.begin(), list2.end(), 3);


		vector<int> coll5;
		for (int i = 0; i <= 9; i++) {
			coll5.push_back(i);
		}

		// for_each 函数参数操作
		for_each(coll5.begin(), coll5.end(), print_int);
		cout << endl;

		vector<int> coll6;
		// transform
		transform(coll5.begin(), coll5.end(), back_inserter(coll6), square);
		for_each(coll6.begin(), coll6.end(), print_int);
		cout << endl << endl;


		list<int> coll7;
		for (int i = 0; i < 24; i++) {
			coll7.push_back(i);
		}
		list<int>::iterator pos7;
		pos7 = find_if(coll7.begin(), coll7.end(), isPrime); // 返回第一个满足 isPrime = true 的迭代器
		if (pos7 != coll7.end()) {
			cout << *pos7 << " is first 。。。" << endl;
		}




	}
}