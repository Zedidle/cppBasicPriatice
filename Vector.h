#include "iostream"
using namespace std;


namespace Vector
{

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