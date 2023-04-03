#include <iostream>
#include <algorithm>
#include "string"
#include "map"
#include <ctime>
#include <windows.h>  //在Linux和Mac下要换成 unistd.h 头文件
using namespace std;


namespace Copy
{
	class Base {
		public:
			Base():m_a(0), m_b(0){}
			Base(const  Base&obj);
			Base(int a, int b): m_a(a), m_b(b){}

		public:
			int getCount() const { return m_count; }
			time_t getTime() const { return m_time; }

			void Print() {
				cout << m_a << ", " << m_b << endl;
			}

		private:
			int m_a;
			int m_b;
			time_t m_time;
			static int m_count;
	};

	int Base::m_count = 0;
	Base::Base(const Base& obj) {
		this->m_a = obj.m_a;
		this->m_b = obj.m_b;
		this->m_count ++;
		this->m_time = time((time_t*) NULL);
	};

	

	//变长数组类
	class Array {
		public:
			Array(int len);
			Array(const Array& arr);  //拷贝构造函数
			~Array();
		public:
			int operator[](int i) const { return m_p[i]; }  //获取元素（读取）
			int& operator[](int i) { return m_p[i]; }  //获取元素（写入）
			int length() const { return m_len; }
		private:
			int m_len;
			int* m_p;
	};
	Array::Array(int len) : m_len(len) {
		m_p = (int*)calloc(len, sizeof(int));
	}
	Array::Array(const Array& arr) {  //拷贝构造函数
		this->m_len = arr.m_len;
		this->m_p = (int*)calloc(this->m_len, sizeof(int));
		memcpy(this->m_p, arr.m_p, m_len * sizeof(int));
	}


	Array::~Array() { free(m_p); }
	//打印数组元素
	void printArray(const Array& arr) {
		int len = arr.length();
		for (int i = 0; i < len; i++) {
			if (i == len - 1) {
				cout << arr[i] << endl;
			}
			else {
				cout << arr[i] << ", ";
			}
		}
	}



	void Test() {
		int a = 10;
		int b = a; //  浅拷贝
		Base obj1(10, 20);


		Array arr1(10);
		for (int i = 0; i < 10; i++) {
			arr1[i] = i;
		}

		Array arr2 = arr1;
		arr2[5] = 100;
		arr2[3] = 29;

		printArray(arr1);
		printArray(arr2);


		cout << endl;
		cout << "obj1: count = " << obj1.getCount() << ", time = " << obj1.getTime() << endl;

		Sleep(3000); 

		Base obj2 = obj1;
		cout << "obj2: count = " << obj2.getCount() << ", time = " << obj2.getTime() << endl;

		obj2.Print();

	}



}