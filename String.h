#include <iostream>
#include <algorithm>
#include "string"
#include "map"
using namespace std;


namespace String
{
	
	void Test0()
	{
		// 1. 构造函数
		string s1();  // si = ""
		string s2("Hello");  // s2 = "Hello"
		string s3(4, 'K');  // s3 = "KKKK"
		string s4("12345", 1, 3);  //s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串

		// 类没有接收一个整型参数或一个字符型参数的构造函数。下面的两种写法是错误的：
		// string s1('K');
		// string s2(123);
	}

	void Test1()
	{
		// 2. 对 string 对象赋值

		// 可以用 char* 类型的变量、常量，以及 char 类型的变量、常量对 string 对象进行赋值。
		string s1, s2;
		s1 = "Hello";  // s1 = "Hello"
		s2 = 'K';	// s2 = "K”


		//string 类还有 assign 成员函数，可以用来对 string 对象赋值。assign 成员函数返回对象自身的引用。
		string s3("12345"), s4;
		s4.assign(s1);  // s3 = s1;
		cout << "0 s4:" << s4 << endl;

		s4.assign(s3, 1, 2);  // s4 = "23"，即 s1 的子串(1, 2);
		cout << "1 s4:" << s4 << endl;

		s4.assign(4, 'K');  // s4 = "KKKK";
		s4.assign("abcde", 2, 4);  // s4 = "cde"，即 "abcde" 的子串(2, 3);
		cout << "s3:"<<s3 <<endl;
		cout << "2 s4:" << s4 <<endl;
	}


	void Test2()
	{
		//	3. 求字符串的长度
		//	length 成员函数返回字符串的长度。size 成员函数可以实现同样的功能。

		string s = "10000";
		cout << s.size() <<endl;
		cout << s.length() <<endl;

	}

	void Test3()
	{
		// 4. string对象中字符串的连接
		// 除了可以使用+和+=运算符对 string 对象执行字符串的连接操作外，string 类还有 append 成员函数，可以用来向字符串后面添加内容。append 成员函数返回对象自身的引用。
		string s1("123"), s2("abc");
		s1.append(s2);  // s1 = "123abc"
		cout << "0 s1:" << s1 << endl;
		s1.append(s2, 1, 2);  // s1 = "123abcbc"
		cout << "1 s1:" << s1 << endl;
		s1.append(3, 'K');  // s1 = "123abcbcKKK"
		cout << "2 s1:" << s1 << endl;
		s1.append("ABCDE", 2, 3);  // s1 = "123abcbcKKKCDE"，添加 "ABCDE" 的子串(2, 3)
		cout << "3 s1:" << s1 << endl;

	}

	void Test4()
	{
		// 5. string对象的比较
		/*
		除了可以用 <、<=、==、!=、>=、> 运算符比较 string 对象外，string 类还有 compare 成员函数，可用于比较字符串。compare 成员函数有以下返回值：
			小于 0 表示当前的字符串小；
			等于 0 表示两个字符串相等；
			大于 0 表示另一个字符串小。
		*/

		string s1("hello"), s2("hello, world");
		int n = s1.compare(s2);
		cout << "0 n:" << n << endl;
		n = s1.compare(1, 2, s2, 0, 3);  //比较s1的子串 (1,2) 和s2的子串 (0,3)
		cout << "1 n:" << n << endl;
		n = s1.compare(0, 2, s2);  // 比较s1的子串 (0,2) 和 s2
		cout << "2 n:" << n << endl;
		n = s1.compare("Hello");
		cout << "3 n:" << n << endl;
		n = s1.compare(1, 2, "Hello");  //比较 s1 的子串(1,2)和"Hello”
		cout << "4 n:" << n << endl;
		n = s1.compare(1, 2, "Hello", 1, 2);  //比较 s1 的子串(1,2)和 "Hello" 的子串(1,2)
		cout << "5 n:" << n << endl;

	}
	void Test5()
	{
		//6. 求 string 对象的子串
		//substr 成员函数可以用于求子串(n, m)，从 下标 n 到 n+m-1 之前的字符串  原型如下：

		// string substr(int n = 0, int m = string::npos) const;

		//调用时，如果省略 m 或 m 超过了字符串的长度，则求出来的子串就是从下标 n 开始一直到字符串结束的部分。

		string s1 = "thisBisBok";
		cout << "1 :" << s1 << endl;
		string s2 = s1.substr(2, 4); 
		cout << "2 :" << s2 << endl;
		s2 = s1.substr(2);  
		cout << "3 :" << s2 << endl;
		s2 = s1.substr(3, 1);
		cout << "4 :" << s1 << endl;
		cout << "4 :" << s2 << endl;

		cout << endl;
		string s3 = "1234567";
		cout << s3.substr(0,0) << endl;
		cout << s3.substr(0,1) << endl;
		cout << s3.substr(0) << endl;



		//string t = s.substr(0, n);
		//for (int i = t.size(); i >= 0; --i)
		//{
		//	s += t[i];
		//}
	}

	void Test6()
	{
		// 7. 交换两个string对象的内容

		// swap 成员函数可以交换两个 string 对象的内容。例如：
		string s1("West"), s2("East");
		cout << s1 <<" "<< s2 <<endl;
		s1.swap(s2);  // s1 = "East"，s2 = "West"
		cout << s1 << " " << s2 << endl;

	}

	void Test7()
	{
		// 8. 查找子串和字符
		/*
		string 类有一些查找子串和字符的成员函数，它们的返回值都是子串或字符在 string 对象字符串中的位置（即下标）。
		如果查不到，则返回 string::npos。string: :npos 是在 string 类中定义的一个静态常量。这些函数如下：
			find：从前往后查找子串或字符出现的位置。
			rfind：从后往前查找子串或字符出现的位置。

			find_first_of：从前往后查找何处出现另一个字符串中包含的字符。例如：
				s1.find_first_of("abc");  //查找s1中第一次出现"abc"中任一字符的位置

			find_last_of：从后往前查找何处出现另一个字符串中包含的字符。
			find_first_not_of：从前往后查找何处出现另一个字符串中没有包含的字符。
			find_last_not_of：从后往前查找何处出现另一个字符串中没有包含的字符。
		*/

		string s1("Source Code");
		int n;
		if ((n = s1.find('u')) != string::npos) //查找 u 出现的位置
			cout << "1) " << n << "," << s1.substr(n) << endl;
		//输出 l)2,urce Code
		if ((n = s1.find("Source", 3)) == string::npos)
			//从下标3开始查找"Source"，找不到
			cout << "2) " << "Not Found" << endl;  //输出 2) Not Found
		if ((n = s1.find("Co")) != string::npos)
			//查找子串"Co"。能找到，返回"Co"的位置
			cout << "3) " << n << ", " << s1.substr(n) << endl;
		//输出 3) 7, Code
		if ((n = s1.find_first_of("ceo")) != string::npos)
			//查找第一次出现或 'c'、'e'或'o'的位置
			cout << "4) " << n << ", " << s1.substr(n) << endl;
		//输出 4) l, ource Code
		if ((n = s1.find_last_of('e')) != string::npos)
			//查找最后一个 'e' 的位置
			cout << "5) " << n << ", " << s1.substr(n) << endl;  //输出 5) 10, e
		if ((n = s1.find_first_not_of("eou", 1)) != string::npos)
			//从下标1开始查找第一次出现非 'e'、'o' 或 'u' 字符的位置
			cout << "6) " << n << ", " << s1.substr(n) << endl;
		//输出 6) 3, rce Code
		if ((n = s1.find_last_not_of("eou")) != string::npos)
			cout << "7) " << n << ", " << s1.substr(n) << endl; // //输出 7) 9, de

	}


	void Test8()
	{
		// 9. 替换子串
		// replace 成员函数可以对 string 对象中的子串进行替换，返回值为对象自身的引用。
		string s1("Real Steel");
		s1.replace(1, 3, "123456", 2, 4);  //用 "123456" 的子串(2,4) 替换 s1 的子串(1,3)
		cout << s1 << endl;  //输出 R3456 Steel
		string s2("Harry Potter");
		s2.replace(2, 3, 5, '0');  //用 5 个 '0' 替换子串(2,3)
		cout << s2 << endl;  //输出 HaOOOOO Potter
		int n = s2.find("OOOOO");  //查找子串 "00000" 的位置，n=2
		s2.replace(n, 5, "XXX");  //将子串(n,5)替换为"XXX"
		cout << s2 << endl;  //输出 HaXXX Potter
	}

	void Test9()
	{
		// 10. 删除子串
		// erase 成员函数可以删除 string 对象中的子串，返回值为对象自身的引用。
		string s1("Real Steel");
		s1.erase(1, 3);  //删除子串(1, 3)，此后 s1 = "R Steel"
		s1.erase(5);  //删除下标5及其后面的所有字符，此后 s1 = "R Ste"

	}

	void Test10()
	{
		// 11. 插入字符串
		// insert 成员函数可以在 string 对象中插入另一个字符串，返回值为对象自身的引用。
		string s1("Limitless"), s2("00");
		s1.insert(2, "123");  //在下标 2 处插入字符串"123"，s1 = "Li123mitless"
		s1.insert(3, s2);  //在下标 2 处插入 s2 , s1 = "Li10023mitless"
		s1.insert(3, 5, 'X');  //在下标 3 处插入 5 个 'X'，s1 = "Li1XXXXX0023mitless"


	}

	void Test11()
	{
		// 12. 将 string 对象作为流处理
		// 使用流对象 istringstream 和 ostringstream，可以将 string 对象当作一个流进行输入输出。使用这两个类需要包含头文件 sstream。

		string src("Avatar 123 5.2 Titanic K");
		//istringstream istrStream(src); //建立src到istrStream的联系
		//string s1, s2;
		//int n;  double d;  char c;
		//istrStream >> s1 >> n >> d >> s2 >> c; //把src的内容当做输入流进行读取
		//ostringstream ostrStream;
		//ostrStream << s1 << endl << s2 << endl << n << endl << d << endl << c << endl;
		//cout << ostrStream.str();

	}

	void Test12()
	{
		// 13. 用 STL 算法操作 string 对象
		// string 对象也可以看作一个顺序容器，它支持随机访问迭代器，也有 begin 和 end 等成员函数。STL 中的许多算法也适用于 string 对象。下面是用 STL 算法操作 string 对象的程序示例。
		string s("afgcbed");
		string::iterator p = find(s.begin(), s.end(), 'c');
		if (p != s.end())
			cout << p - s.begin() << endl;  //输出 3
		sort(s.begin(), s.end());
		cout << s << endl;  //输出 abcdefg
		next_permutation(s.begin(), s.end());
		cout << s << endl; //输出 abcdegf
	}


	void Test()
	{
		//Test0();
		//Test1();
		//Test2();
		//Test3();
		//Test4();
		Test5();
		//Test6();
		//Test7();
		//Test8();
		//Test9();
		//Test10();
		//Test11();
		//Test12();


		//int text1 = 10086;
		//string ss = to_string(text1);
		//cout << (ss[0] > ss[1]) << endl;
		//cout << (ss[2] <= ss[3]) << endl;
		//cout << (ss[4] > ss[3]) << endl;

		//cout << ss << endl;
		//ss[4] = '9';
		//cout << ss << endl;
		//ss[4] -= 1;
		//cout << ss << endl;
		//cout << stoi(ss) << endl;


		


	/*	vector<int> nums(26, 0);
		string s = "fdsvctedsacxwejhvnwtre";
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			nums[s[i] - 'a'] += 1;
		}
		for (int i = 0; i < n; i++)
		{
			cout << nums[i] << endl;
		}*/


		//string sss;
		//sss += to_string(15432523);
		//cout << sss << endl;
		//sss.erase(sss.begin(), sss.begin()+1);

		//while (sss.size() > 0)
		//{
		//	cout << sss << endl;
		//	sss.erase(sss.begin(), sss.begin() + 1);
		//}
	}


}