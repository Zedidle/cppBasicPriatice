#include <iostream>
#include <algorithm>
#include <set> 
#include "list"
using namespace std;



/*
set<int> s    定义一个set容器 类型为int型
s.begin()         返回指向第一个元素的迭代器
s.clear()          清除所有元素
s.count()         返回某个值元素的个数
s.empty()        如果集合为空，返回true
s.end()           返回指向最后一个元素之后的迭代器，不是最后一个元素
s.erase()          删除集合中的元素
s.find()           返回一个指向被查找到元素的迭代器，如果没找到则返回end()
s.insert()          在集合中插入元素
s.size()            集合中元素的数目
s.swap()          交换两个集合变量
*/

namespace Set
{
	void Test()
	{
		set<int> Set;
		Set.insert(100);
		Set.insert(100);
		Set.insert(101);
		cout << Set.size() << endl;
		cout << endl;
		typedef set<int> MakeSet_int;
		MakeSet_int Set_int;
		MakeSet_int Set_int2;
		for (int i = 0; i < 10; ++i) {
			Set_int.insert(i);
		}
		//set<int>::const_iterator pos; 和下面一样
		//MakeSet_int::const_iterator pos;
		MakeSet_int::iterator pos;
		for (pos = Set_int.begin(); pos != Set_int.end(); pos++) {
			cout << *pos << " ";
		}


		//cout << endl;
		//typedef multiset<int> MakeMultiset_int;
		//MakeMultiset_int Multiset_int;
		//for (int i = 0; i < 10; ++i) {
		//	Multiset_int.insert(i);
		//	Multiset_int.insert(i);
		//}
		//MakeMultiset_int::iterator pos2;
		//for (pos2 = Multiset_int.begin(); pos2 != Multiset_int.end(); pos2++) {
		//	cout << *pos2 << " ";
		//}

		cout << endl;
		list<int> coll1;

		for (int i = 0; i < 10; ++i) {
			coll1.push_back(i);
		}
		vector<int> coll2(coll1.size());
		copy(coll1.begin(), coll1.end(), coll2.begin());
		for (int i = 0; i < 10; ++i) {
			cout << coll2[i] << endl;
		}




	}
}
