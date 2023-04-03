#include <iostream>
#include <fstream>
#include <cstdlib> //qsort在此头文件中声明
using namespace std;
const int MAX_NUM = 1000;
int a[MAX_NUM]; //存放文件中读入的整数
int MyCompare(const void* e1, const void* e2)
{ //用于qsort的比较函数
	return *((int*)e1) - *((int*)e2);
}


namespace File
{
	void Test()
	{
		int total = 0;//读入的整数个数
		ifstream srcFile("filetext/in.txt", ios::in); //以文本模式打开in.txt备读
		if (!srcFile) { //打开失败
			cout << "error opening source file." << endl;
			return ;
		}
		cout << "srcFile.rdbuf：" << srcFile.rdbuf() << endl;


		ofstream destFile("filetext/out.txt", ios::out); //以文本模式打开out.txt备写
		if (!destFile) {
			srcFile.close(); //程序结束前不能忘记关闭以前打开过的文件
			cout << "error opening destination file." << endl;
			return;
		}

		int x;
		while (srcFile >> x) //可以像用cin那样用ifstream对象
			a[total++] = x;
		qsort(a, total, sizeof(int), MyCompare); //排序

		for (int i = 0; i < total; ++i)
			destFile << a[i] << " "; //可以像用cout那样用ofstream对象

		destFile.close();
		srcFile.close();
	}

	void Test2()
	{
		int x, sum = 0;
		ifstream srcFile("filetext/in.txt", ios::in); //以文本模式打开in.txt备读
		if (!srcFile) { //打开失败
			cout << "error opening source file." << endl;
			return;
		}
		ofstream destFile("filetext/out.txt", ios::out); //以文本模式打开out.txt备写
		if (!destFile) {
			srcFile.close(); //程序结束前不能忘记关闭以前打开过的文件
			cout << "error opening destination file." << endl;
			return;
		}
		//可以像用cin那样用ifstream对象
		while (srcFile >> x) {
			sum += x;
			//可以像 cout 那样使用 ofstream 对象
			destFile << x << " ";
		}

		cout << "sum：" << sum << endl;
		destFile.close();
		srcFile.close();
	}

}