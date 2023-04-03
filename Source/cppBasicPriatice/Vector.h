#include "iostream"
#include "numeric"
using namespace std;


namespace Vector
{


	void Test5() {
		vector<int> vec;
		for (int i = 0; i < 10; i++) {
			vec.emplace_back(i);
		}
	}



	// reverse 的测试
	void Test4() {
		
		cout << (-3) % 2 << endl;

		//vector<short> vec2;
		//vec2.resize(1000);
		//iota(vec2.begin(), vec2.end(), 1);
		//for (auto i : vec2) {
		//	cout << i << " ";
		//}


		cout << endl;

		vector<short> vec;
		for (int i = 0; i < 100; i++) {
			vec.push_back(i);
		}
		for (auto i: vec) {
			cout << i << " ";
		}
		cout <<endl;
		reverse(vec.begin(), vec.end());
		for (auto i : vec) {
			cout << i << " ";
		}
	}


	void Test3() {
		//	研究 size() 和 capacity() 的区别；
		vector<short> vec(102);
		cout << "Init:" << endl;
		cout << "size:" << vec.size() << endl;
		cout << "capacity:" << vec.capacity() << endl;
		cout << endl;
		
		vec.push_back(10); // 因为当前size = capacity，因此会触发扩容，让capacity扩大0.5倍；
		cout << "after push_back:" << endl;
		cout << "size:" << vec.size() << endl;
		cout << "capacity:" << vec.capacity() << endl;
		cout << endl;

		vec.resize(80); // 改变 size 而不改变 capacity；
		cout << "after resize:" << endl;
		cout << "size:" << vec.size() << endl;
		cout << "capacity:" << vec.capacity() << endl;
		cout << endl;

		vec.reserve(400);   // 超出的实际使用部分就会称为缓冲区 -> capacity = 400；
		cout << "after reserve:" << endl;
		cout << "size:" << vec.size() << endl;
		cout << "capacity:" << vec.capacity() << endl;
		cout << endl;

		vec.erase(vec.begin(), vec.begin()+4); // 只会改变size；
		cout << "after erase:" << endl;
		cout << "size:" << vec.size() << endl;
		cout << "capacity:" << vec.capacity() << endl;
		cout << endl;

		if (0) {
			//vec.clear(); // 只会改变size；
			//cout << "after clear:" << endl;
			//cout << "size:" << vec.size() << endl;
			//cout << "capacity:" << vec.capacity() << endl;
			//cout << endl;
		}
		else {


			//decltype(vec) vec2;
			//swap(vec, vec2);  // 通过swap可以释放内存
			//cout << "after swap:" << endl;
			//cout << "1 size:" << vec.size() << endl;
			//cout << "1 capacity:" << vec.capacity() << endl;
			//cout << "2 size:" << vec.size() << endl;
			//cout << "2 capacity:" << vec.capacity() << endl;
			cout << endl;
		}



	}





	void Test2()
	{
		vector<int> arr = {1,2,3};
		//arr.push_back(1);
		//arr.push_back(2);
		//arr.push_back(3);

		arr.insert(arr.begin()+1, 4);
		arr.erase(arr.begin(), arr.begin() + 1);
		arr.pop_back();
		for (auto a : arr)
		{
			cout << a << " " ;
		}
		cout << endl << endl;

		//vector<vector<int>> arr2;
		//arr2.push_back({10, 2});
		//arr2.push_back({10, 2});
		//arr2.push_back({10, 2});

		//for (int i = 0; i < arr2.size(); i++)
		//{
		//	for (int j = 0; j < arr2[i].size(); j++)
		//	{
		//		cout << arr2[i][j] << " ";
		//	}
		//	cout << endl;
		//}
	
		//vector<vector<int>> result = { {1,3}, {3,4} };
		//for (int i = 0; i < result.size(); i++)
		//{
		//	for (int j = 0; j < result[i].size(); j++)
		//	{
		//		cout << result[i][j] << " ";
		//	}
		//	cout << endl;
		//}
	
		vector<int> vector_a(128);
		vector_a['a'] = 100;
		cout << vector_a['a'] << endl;
		// 即：char 可以转为 int 型，是它的ascll码
		cout << int('a') << endl;
		cout << int('b') << endl;

	}




	void Test()
	{
		vector<int> arr(100);
		cout << "arr.size():" << arr.size() << endl; // 100
		cout << "arr.capacity():" << arr.capacity() << endl;  // 100

		for (int i = 0; i < 100; ++i)
		{
			arr[i] = i;
		}
		cout << "arr.size():" << arr.size() << endl; // 100
		cout << "arr.capacity():" << arr.capacity() << endl;  // 100

		for (int i = 0; i < 100; ++i)
		{
			arr.push_back(i);
		}

		cout << "arr.size():" << arr.size() << endl; // 200
		cout << "arr.capacity():" << arr.capacity() << endl;  // 225

		arr.clear();
		cout << "Clear" << endl;
		cout << "arr.size():" << arr.size() << endl; // 0
		cout << "arr.capacity():" << arr.capacity() << endl;  // 225 ??

		for (int i = 0; i < 100; ++i)
		{
			arr.push_back(i);
		}
		cout << "arr.size():" << arr.size() << endl; // 100
		cout << "arr.capacity():" << arr.capacity() << endl;  // 225 ??



		cout << endl << endl;
		int nnn = 4;
		vector<pair<int, int>> tmp(nnn); 
		for (int i = 0; i < nnn; i++) {
			cin >> tmp[i].first;
			tmp[i].second = i;
		}
		sort(tmp.begin(), tmp.end()); // 对于pair的排序，只针对first
		for (int i = 0; i < nnn; i++) {
			cout << tmp[i].first << ", " << tmp[i].second << endl;
		}

	}
}