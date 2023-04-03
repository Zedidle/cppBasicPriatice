#pragma once
#include "iostream"
using namespace std;


namespace Inherit
{
	
	class Base {
		public:
			void pub_men();
		protected:
			int prot_mem;
		private:
			char priv_mem;
	};


	struct Pub_Derv : public Base {
		int f() { return prot_mem; }
		//char g(){ return priv_mem; }

	};

	struct Priv_Derv : private Base { // 通过private继承，Base的所有成员都在该类写为private;
		int f() { return prot_mem; }
	};

	struct Derived_from_Public: public Pub_Derv
	{
		int use_base(){ return prot_mem; }
	};
	struct Derived_from_Private : public Priv_Derv
	{
		//int use_base() { return prot_mem; } // 由于Priv_Derv 通过 private继承的Base，因此不能再此调用prot_mem了;
	};

	void Test()
	{
		
	}
}