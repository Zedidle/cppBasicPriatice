#include <iostream>
#include <algorithm>
#include "string"
#include "queue"
using namespace std;


namespace Queue {





	void Test() {
		queue<int> q;
		for (int i=0; i< 10;i++) {
			q.push(i);
		}
		//for (int i = 0; i < 10; i++) {
		//	cout << q.front() << endl;
		//	q.pop();
		//}
		while (q.size()) {
			cout << q.front() << endl;
			q.pop();
		}
	}
}