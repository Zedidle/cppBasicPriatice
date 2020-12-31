#include <iostream>
using namespace std;


namespace Decltype {
	
	// 尾置返回允许我们在参数列表之后声明返回类型
	template <typename It>
	auto fcn(It beg, It end) -> decltype(*beg) {
		// 处理序列
		return *beg;    // 返回序列中一个元素的引用
	}

	// 为了使用模板参数成员，必须用 typename
	template <typename It>
	auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type {
		// 处理序列
		return *beg;    // 返回序列中一个元素的拷贝
	}

	void Test()	{
		cout << "Decltype Test" << endl;
		int a = 8, b = 3;	
		auto c = a + b;	// 运行时需要实际执行a+b，哪怕编译时就能推导出类型
		decltype(a + b) d = 100; // 编译器类型推导

		cout << d << endl;

	}
}