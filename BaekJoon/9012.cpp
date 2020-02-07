#include <iostream>
#include <string>
using namespace std;

class stack {

public:

	string* sArray; // ���ù迭
	int size; // ���ù迭 ������
	int top; // ���� ž

	void makeStack(int s) {
		size = s;
		sArray = new string[size];
		top = 0;
	}

	void deleteStack() {
		delete[] sArray;
	}

	void Push(char data) {
		sArray[top++] = data;
	}

	void Pop() {
		sArray[--top].clear();
	}

	string Top() {
		return sArray[top - 1];
	}

	void show() {
		cout << "***************************" << endl;
		for (int i = 0; i < size; i++) {
			cout << sArray[i] << endl;
		}
		cout << "***************************" << endl;
	}
};

int main() {

	int t; // �Է� ������ ��
	string* inputArr; // �Է� ������ ����
	string* outputArr; // ��� ������ ����
	stack s; // ���� ����ü

	cin >> t;
	inputArr = new string[t];
	outputArr = new string[t];
	for (int i = 0; i < t; i++) {
		cin >> inputArr[i];
		outputArr[i] = "YES";
	}

	for (int i = 0; i < t; i++) {
		s.makeStack(inputArr[i].length());
		for (int j = 0; j < s.size; j++) {
			char input = inputArr[i].at(j);
			if (s.top == 0) { // ���� ���������
				if (input == '(') {
					s.Push(input);
				}
				else if (input == ')') {
					outputArr[i] = "NO";
					break;
				}
			}
			else { // ���� ������� ������
				if (input == '(') {
					s.Push(input);
				}
				else if (input == ')') {
					if (s.Top() == "(") {
						s.Pop();
					}
					else {
						outputArr[i] = "NO";
						break;
					}
				}
			}
		}

		if (s.top) {
			outputArr[i] = "NO";
		}
		s.deleteStack();
	}

	for (int i = 0; i < t; i++) {
		cout << outputArr[i] << endl;
	}

	delete[] inputArr;
	delete[] outputArr;

	return 0;
}