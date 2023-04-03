#include <iostream>
#include <algorithm>
#include "string"
#include "queue"
using namespace std;


namespace Queue {

	// deque 测试
	void Test1() {
		deque<int> dq;
		for (int i = 0; i < 100; i++) {
			if (i % 2 == 0) {
				dq.push_back(i);
			}else {
				dq.push_front(i);
			}

		}
		cout << dq[10] << endl;

		for (auto i : dq) {
			cout << i << " " << &i << endl;
		}


	}






	// queue 测试
	void Test() {
		queue<int> q;
		for (int i=0; i< 10;i++) {
			q.push(i);
		}
		//for (int i = 0; i < 10; i++) {
		//	cout << q.front() << endl;
		//	q.pop();
		//}
		//cout << q[10] << endl; // 无法随机读取，不是顺序存储
		while (q.size()) {
			cout << q.front() << endl;
			q.pop();
		}
	}
}