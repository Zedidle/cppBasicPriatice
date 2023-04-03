#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;


namespace Functor {
	
	class PrintInt {
		public:
			void operator() (int elem) const {
				cout << elem << " ";
			}
	};

	void Add10(int& elem) {
		elem += 10;
	}

	template<int v>
	void Add(int& elem) {
		elem += v;
	}

	class AddValue {
		private:
			int theValue;
	public:
		AddValue(int v) : theValue(v) {}

		void operator()(int& elem) const {
			elem += theValue;
		}

	};


	void Test() {
		vector<int > coll;
		for (int i = 1; i <= 9; i++) {
			coll.push_back(i);
		}

		// 其实就可以把PrintInt()当作一个函数；
		for_each(coll.begin(), coll.end(), PrintInt());
		cout << endl;

		for_each(coll.begin(), coll.end(), Add10);
		for_each(coll.begin(), coll.end(), PrintInt());
		cout << endl;

		for_each(coll.begin(), coll.end(), Add<10>);
		for_each(coll.begin(), coll.end(), PrintInt());
		cout << endl;
		cout << endl;



		list<int> coll2;
		for (int i = 1; i <= 9; i++) {
			coll2.push_back(i);
		}
		for_each(coll2.begin(), coll2.end(), PrintInt());
		cout << endl;
		for_each(coll2.begin(), coll2.end(), AddValue(10));
		for_each(coll2.begin(), coll2.end(), PrintInt());

		cout << endl;
		for_each(coll2.begin(), coll2.end(), AddValue(*coll2.begin()));
		for_each(coll2.begin(), coll2.end(), PrintInt());



	}

}

