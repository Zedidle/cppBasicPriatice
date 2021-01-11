#include <iostream>
using namespace std;

namespace Malloc
{


	// malloc 测试
	void Test1() {

		cout << gcd(10, 4) <<endl;
		cout <<endl;
		int* p = (int*)malloc(100 * sizeof(int));
		int* head = p;
		//cout << p << endl;
		//cout << p+1 <<endl;
		for (int i = 0; i < 100; i++) {
			*p = i;
			++p;
		}
		p = head;
		for (int i = 0; i < 100; i++) {
			cout << *p <<endl;
			++p;
		}
	}





	// 测试智能指针

	template<typename T>
	class auto_release_ptr
	{
	public:
		auto_release_ptr(T* t) :_t(t) {};
		~auto_release_ptr()
		{
			delete _t;
		};

		T* getPtr()
		{
			return _t;
		}

	private:
		T* _t;
	};

	void Test()
	{
		for (int i = 1; i <= 10000000; i++)
		{
			int32_t* ptr = new int32_t[3];
			ptr[0] = 1;
			ptr[1] = 2;
			ptr[2] = 3;
			//delete ptr;     //假设忘记了释放内存,将会导致占用500M内存·
		}

		for (int i = 1; i <= 10000000; i++)
		{
			auto arp = auto_release_ptr<int32_t>(new int32_t[3]);
			int32_t* ptr = arp.getPtr();
			ptr[0] = 1;
			ptr[1] = 2;
			ptr[2] = 3;
		}
	}

}