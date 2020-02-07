#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int data;
	Node* next; // 가리키고 있는 노드
	Node* prev; // 나를 가리키는 노드
public:
	Node(int data, Node* next, Node* prev) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	int getData() {
		return data;
	}
	void setNext(Node* node) {
		next = node;
	}
	Node* getNext() {
		return next;
	}
	void setPrev(Node* node) {
		prev = node;
	}
	Node* getPrev() {
		return prev;
	}
};

class Deque {
public:
	Node* head; // 덱의 맨 앞
	Node* tail; // 덱의 맨 뒤
	int nums = 0; // 덱 크기

	void push_front(int x) {
		Node* node = new Node(x, NULL, NULL);
		if (nums) {
			head->setNext(node);
			node->setPrev(head);
			head = node;
		}
		else {
			head = tail = node;
		}
		nums++;
	}
	void push_back(int x) {
		Node* node = new Node(x, NULL, NULL);
		if (nums) {
			tail->setPrev(node);
			node->setNext(tail);
			tail = node;
		}
		else {
			head = tail = node;
		}
		nums++;
	}
	int pop_front() {
		if (nums) {
			Node* new_head;
			int value = head->getData();
			new_head = head->getPrev();
			delete head;
			head = new_head;
			nums--;
			return value;
		}
		else return -1;
	}
	int pop_back() {
		if (nums) {
			Node* new_tail;
			int value = tail->getData();
			new_tail = tail->getNext();
			delete tail;
			head = new_tail;
			nums--;
			return value;
		}
		else return -1;
	}
	int size() {
		return this->nums;
	}
	int empty() {
		if (nums) return 0;
		else return 1;
	}
	int front() {
		if (nums) return head->getData();
		else return -1;
	}
	int back() {
		if (nums) return tail->getData();
		else return -1;
	}
};

int main() {

	Deque d;
	int num; // 명령어 수
	string line; // 명령어
	int x; // 인자

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> line;
		if (line == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (line == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (line == "pop_front") {
			cout << d.pop_front() << endl;
		}
		else if (line == "pop_back") {
			cout << d.pop_back() << endl;
		}
		else if (line == "size") {
			cout << d.size() << endl;
		}
		else if (line == "empty") {
			cout << d.empty() << endl;
		}
		else if (line == "front") {
			cout << d.front() << endl;
		}
		else if (line == "back") {
			cout << d.back() << endl;
		}
	}

	return 0;
}