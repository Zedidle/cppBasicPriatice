#include <iostream>
using namespace std;

namespace Typedef
{

	// 若定义了与 Student 同名函数，则 Student 只代表函数，不代表结构体; （不管定义在struct前还是后）
	// 此时typedef的作用更是体现了出来
	void Student()
	{
		cout << "I'm a student." << endl;
	}

	typedef struct Student {
		int age;
	} S;



	typedef class Teacher
	{

		public:
			string Name;
			Teacher(string name);
	} T;

	//typedef Teacher T;
	T::Teacher(string name) :Name(name) {};

	void Teacher()
	{
		cout << "I'm a teacher." << endl;
	}


	void Test()
	{
		S s;
		//Student s; // 错误，Student仅代表函数
		Student();
		s.age = int();
		cout << "s.age:" << s.age << endl;

		T t("Z");
		cout << "t.Name:" << t.Name << endl;
		Teacher();

		struct Student s2;  // 如果非要用Student这个名字来实例化，则在前面加个struct
		s2.age = 10;
		cout << "s2.age:" << s2.age << endl;
		//class Teacher t2; // 错误，class却不可以


		cout << endl << endl;
		cout << sizeof(int) << endl;
	}

}