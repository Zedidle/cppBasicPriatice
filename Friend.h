#include <iostream>
using namespace std;


namespace Friend
{

	
	class CA {
		public:
			friend class CB;
			friend class CC;
			friend void ShowAge(CA a);
			friend int ShowAge2(CA a);
			void SetAge(int age)
			{
				m_age = age;
			}
		private:
			int m_age;
	};

	class CB
	{
		public:
		void ShowAge(CA a)
		{
			cout << "a.age: " << a.m_age <<endl;
		}
		void ShowAge2(CA a)
		{
			cout << "a.age: " << a.m_age  + 200<< endl;
		}
	};

	class CC
	{
	public:
		void ShowAge(CA a)
		{
			cout << "a.age: " << a.m_age << endl;
		}
		int ShowAge2(CA a)
		{
			cout << "a.age: " << a.m_age + 100 << endl;
			return 0;
		}
		virtual int ShowAge3(CA a)
		{
			cout << "a.age: " << a.m_age + 300 << endl;
			return 0;
		}
	};

	class DC : public CC {
		public:
			virtual int  ShowAge3(CA a) override {
				//cout << "a.age: " << a.m_age + 1000 << endl; // 由于友元的不可传递性； 无法访问 a.m_age + 1000；
				return 0;
			}
	};

	void ShowAge(CA a){
		cout << "a.age: " << a.m_age << endl;
	}


	void Test()
	{

		// 友元的自由无限制
		CA a;
		a.SetAge(777);
		CB b;
		b.ShowAge(a);
		CC c;
		c.ShowAge(a);

		b.ShowAge2(a);
		c.ShowAge2(a);
		c.ShowAge3(a);

		DC d;
		d.ShowAge2(a);

		ShowAge(a);
	}
}
