#include "iostream"
#include <stdio.h>
#include <string.h>
#include "test.h"
using namespace std;

namespace PAR
{
	// 指针常量和常量指针
	void Test3() {
		cout << endl;
		const int i = 10;
		int i2 = 11;
		const int *p = &i;  // 常量指针

		printf("%d\n", *p); // 10
		p = &i2;  // 由于是常量指针，所以可以被再次赋值
		printf("%d\n", *p); // 11

		cout << endl;
		const int * const p2 = &i; // 常量常指针
		printf("%d\n", *p2); // 10
		//p2 = &i2; // 由于是常指针，所以不能被再次赋值
		printf("%d\n", *p2); // 10

		cout << endl;

		test_Test0();
	}









// ================================================

	void change(string& x) {
		// &会改变外部内存，避免形参拷贝
		x = "cd";
	}

	void fun(int* x) {

		*x += 5;

	}

	class A {
		public:
			A() = default;
			A(int n):Num(n){}
			int Num;

			bool operator > (const A*& a2)
			{
				return Num > a2->Num;
			}

			// 只是两个指针地址的比较，无法调用到 A::operator >； 而且优先级高于 A*&
			// 因此绝对不能这么写
			//bool operator > (const A* a2) 
			//{
			//	return Num > a2->Num;
			//}

			bool operator > (const A& a2)
			{
				return Num > a2.Num;
			}
	};

	int get_max(int i, int j)
	{
		return i > j ? i : j;
	}

	int get_min(int i, int j)
	{
		return i > j ? j : i;
	}

	int compare(int i, int j, bool flag)
	{
		int ret;

		//这里定义了一个函数指针，就可以根据传入的flag，灵活地决定其是指向求大数或求小数的函数
		//便于方便灵活地调用各类函数
		int (*p)(int, int);
		if (flag)
			p = get_max;
		else
			p = get_min;

		ret = p(i, j);
		return ret;
	}

	void check(char* a, char* b, int (*cmp)(const char*, const char*)){
		printf("Testing for equality.\n");
		//表达式(*cmp)(a,b)调用strcmp，由cmp指向库函数strcmp()，由a和b作调用strcmp()的参数。
		//调用时，与声明的情况类似，必须在*cmp周围使用一对括号，使编译程序正确操作，
		//同时这也是一种良好的编码风格，指示函数是通过指针调用的，而不是函数名。
		if ((*cmp)(a, b) == 0)
			printf("Equal\n");
		else
			printf("Not Equal\n");
	}




	// ====================================================================
	// 定义函数指针

	//int (*funcPtr)();
	 //int (*const funcPtr)();  // 或者需要一个静态的函数指针；

	int foo() {
		return 5;
	}
	int goo() {
		return 6;
	}
	int hoo(int x) {
		return x + 100;
	}
	int add(int a, int b) {
		return a + b;
	}
	int sub(int a, int b) {
		return a - b;
	}
	void func(int e, int d, int(*f)(int a, int b)) {
		cout << f(e, d) << endl;
	}



	// 来看看这个简单的冒泡排序
	//template<typename T>
	//void bubblesort(T* a, int n) {
	//	bool sorted = false;
	//	while (!sorted) {
	//		sorted = true;
	//		for (int i = 0; i < n - 1; i++) {
	//			if (a[i] > a[i - 1]) {
	//				swap(a[i], a[i + 1]);
	//				sorted = false;
	//			}
	//		}
	//		n--;
	//	}
	//}


	template <typename T>
	bool ascending(T x, T y) {
		return x > y;
	}
	template <typename T>
	bool descending(T x, T y) {
		return x < y;
	}
	template<typename T>
	void bubblesort(T* a, int n, bool(*cmpfunc)(T, T) = ascending) {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 0; i < n - 1; i++)
				if (cmpfunc(a[i], a[i + 1])) {
					std::swap(a[i], a[i + 1]);
					sorted = false;
				}
			n--;
		}
	}


	// 函数指针练习
	void Test2() {
		int (*funcPtr)() = foo; // funcPtr 现在指向了函数foo
		cout << funcPtr() << endl;
		funcPtr = goo;			// funcPtr 现在又指向了函数goo
		cout << funcPtr() << endl;
		cout << endl;

		int (*funcPtr1)() = foo;  // 可以
		//double (*funcPtr2)() = goo;  // 错误！返回值不匹配！
		int (*funcPtr2)() = goo; // 可以
		//funcPtr1 = hoo; // 错误，因为参数不匹配，funcPtr1只能指向不含参数的函数，而hoo含有int型的参数
		int (*funcPtr3)(int) = hoo; // 可以，所以应该这么写

		int (*funcPtr4)() = &foo;  // 可以，其实会隐式转换为&foo


		cout << funcPtr1() << endl;
		cout << funcPtr2() << endl;
		cout << funcPtr3(50) << endl;
		cout << (*funcPtr3)(50) << endl;
		cout << funcPtr4() << endl;

		cout << endl;
		// 把函数作为参数传入另一个函数
		func(10, 9, add);
		func(10, 9, sub);

		cout << endl;
		cout << "冒泡" << endl;
		int a[8] = { 5,2,5,7,1,-3,99,56 };
		//bubblesort<int>(a, 8);
		bubblesort<int>(a, 8, ascending);
		for (auto e : a)
			std::cout << e << " ";
		cout << endl;

		bubblesort<int>(a, 8, descending);
		for (auto e : a)
			std::cout << e << " ";
		cout << endl;

		bubblesort<int>(a, 8);
		for (auto e : a)
			std::cout << e << " ";
		cout << endl;
	}


	// ====================================================================





	void Test1() {
		int p = 100;
		int* p2 = &p;
		int p3 = *p2;

		cout << p << endl;
		cout << p2 << endl;
		cout << *&p2 << endl;
		cout << *p2 << endl;
		cout << p3 << endl;
		cout << endl;

		cout << compare(10, 20, false) << endl;
		cout << compare(10, 20, true) << endl;

		cout << endl;

		char s1[80] = "233333", s2[80] = "455555";
		int (*p6)(const char*, const char*);
		//int (*p)(int a, int b);

		// 将库函数strcmp的地址赋值给函数指针p
		p6 = strcmp;

		printf("Check. \n");
		check(s1, s2, p6);
		
		// int* f(int i, int j);
		// int (*p)(int i, int j);
		// 前者是返回值是指针的函数；后者是一个指向函数的指针。

	}


	void Test() {
		int a = 12;
		int b;
		int* p;
		int** ptr;

		p = &a;
		ptr = &p;

		*p = 50;
		cout << *p << endl;
		cout << **ptr << endl;

		**ptr = 100;
		cout << *p << endl;
		cout << **ptr << endl;

		//string x = "ab";
		//change(x);
		//cout << x << endl;


		int y = 0;
		fun(&y);
		cout << "y = " << y <<endl; 


		//vector<A*> Array(100000, nullptr); // 占内存 16 * 100000 B = 1600000 B  = 1600KB = 1.6 MB
		//vector<A*> Array0; 
		//cout << "sizeof(Array0):" << sizeof(Array0) << endl;  
		//cout << "sizeof(Array):" << sizeof(Array) << endl;  

		//cout << " sizeof(A*):" << sizeof(A*) << endl;  // 4
		//for (int i = 0; i < Array.size(); ++i)
		//{
		//	Array[i] = new A(rand() % 100000);
		//}
		//for (int i = 0; i < Array.size(); ++i)
		//{
		//	cout << i << ": " << Array[i]->Num << " " << endl;
		//	delete Array[i];
		//	cout << "After delete, Array[i]->Num:" << Array[i]->Num <<endl; // 统一释放，指向 空
		//	Array[i] = nullptr;
		//	cout << "After set nullptr, Array[i]:" << Array[i] << endl;
		//}


		// 引用确实不太适合这种场景，会有错误
		//vector<A&> Array2(100000);
		//for (int i = 0; i < Array2.size(); ++i)
		//{
		//	Array2[i] = A(rand() % 100000);
		//}
		//for (int i = 0; i < Array2.size(); ++i)
		//{
		//	cout << i << ": " << Array2[i].Num << " " << endl;
		//}



		// 试试二维数组
		//vector<vector<A*>> Array3;
		//int row = 100, line = 100;
		//for (int i = 0; i < row; ++i)
		//{
		//	vector<A*> temp;
		//	for (int j = 0; j < row; ++j)
		//	{
		//		temp.push_back(new A(rand()%(row * line)));
		//	}
		//	Array3.push_back(temp);
		//}
		//for (int i = 0; i < row; ++i)
		//{
		//	vector<A*> temp = Array3[i];
		//	for (int j = 0; j < row; ++j)
		//	{
		//		cout << "Array3[i][j]->Num:" << temp[j]->Num << endl;
		//	}
		//}
		//for (int i = 0; i < row; ++i)
		//{
		//	for (int j = 0; j < row; ++j)
		//	{
		//		cout << "Array3[i][j]->Num:" << Array3[i][j]->Num << endl;
		//		delete Array3[i][j];
		//		cout << "After delete, Array3[i][j]->Num:" << Array3[i][j]->Num << endl;

		//	}
		//}


		//cout << "A(3) > A(4) :" << bool(A(3) > A(4)) << endl;

		A* a1 = new A(30);
		A* a2 = new A(50);
		cout << a1 << endl; // 地址更高
		cout << a2 << endl;
		cout << endl;
		cout << &a1 << endl;
		cout << &a2 << endl;

		cout << "a1>a2 :" << bool(a1 > a2) << endl;  // 只是两个指针地址的比较，无法调用到 A::operator >
		cout << "*a1>*a2 :" << bool(*a1 > *a2) << endl;  // 成功调用：A::operator > (const A& a)
		cout << "&a1>&a2 :" << bool(&a1 > &a2) << endl;  // 只是两个指针地址的比较，无法调用到 A::operator >
		cout << "new A(100) > new A(200) :" << bool(new A(100) > new A(200)) << endl;  // 只是两个指针地址的比较，无法调用到 A::operator >

		system("pause");
	}
}