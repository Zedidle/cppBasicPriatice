#include <iostream>
#include <vector>
#include <string>
using namespace std;



namespace Array2d
{
	template <typename T>
	class Array2d {
	
		public:
			Array2d(T IniValue, int x, int y)
			{
				vector<vector<T>> _Array2(y, vector<T>(x, IniValue));
				Array2 = _Array2;
			}

			void SetValue(T value, int x, int y);
			T GetValue(int x, int y);

			void ShowAllValue()
			{
				for (int i = 0; i < Array2.size(); i++)//输出二维动态数组 
				{
					for (int j = 0; j < Array2[i].size(); j++)
					{
						cout << Array2[i][j] << " ";
					}
					cout << "\n";
				}
			}
		
		private:
			vector<vector<T>> Array2;
	};

	template <typename T>
	void Array2d<T>::SetValue(T value, int x, int y)
	{
		if (x > Array2.size()-1)
		{
			cout << "超出行数" << endl;
			return;
		}
		if (y > Array2[0].size()-1)
		{
			cout << "超出列数" << endl;
			return;
		}
		Array2[x][y] = value;
	}

	template <typename T>
	T Array2d<T>::GetValue(int x, int y)
	{
		if (x > Array2.size()-1)
		{
			cout << "超出行数" << endl;
			return T();
		}
		if (y > Array2[0].size()-1)
		{
			cout << "超出列数" << endl;
			return T();
		}
		return Array2[x][y];
	}







	void Test()
	{
		Array2d<int> Arr(1, 5, 5);
		Arr.SetValue(5, 1, 1);
		cout << Arr.GetValue(1, 1) << endl;
		Arr.ShowAllValue();

		Array2d<string> Arr2("H", 5, 5);
		Arr2.SetValue("G", 1, 1);
		Arr2.ShowAllValue();
	}
}