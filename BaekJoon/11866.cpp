#include <iostream>
using namespace std;

class Queue {
public:
	int* qArr; // 큐 배열
	int size; // 큐 배열 사이즈
	int front;
	int back;

	Queue(int size) {
		this->size = size;
		qArr = new int[size];
		front = 0;
		back = 0;
	}

	void deleteQueue() {
		delete[] qArr;
	}

	void push(int data) {
		if (back != size) {
			qArr[back++] = data;
			back %= size; // size 범위 내에서 순환
		}
	}

	int pop() {
		if (front != size) {
			int value = qArr[front++];
			front %= size;
			return value;
		}
	}
};
int main() {

	int n; // 사람 수
	int k; // (k <= n)

	cin >> n >> k;
	Queue q(n);

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k; j++) {
			q.push(q.pop());
		}
		if (i == n - 1) {
			cout << q.pop() << ">";
		}
		else {
			cout << q.pop() << ", ";
		}
	}

	q.deleteQueue();
	return 0;
}