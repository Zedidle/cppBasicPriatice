#include <iostream>
using namespace std;

namespace Malloc
{

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