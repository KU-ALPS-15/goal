#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Stack {

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

	string input; // �Է� ���ڿ� ����
	string change; // �ٲ� ���ڿ� ����
	Stack s;
	regex reg("[a-zA-Z]");
	string result;

	while (true) {
		result = "yes";
		getline(cin, input, '.');

		if (input.empty()) {
			break;
		}
		else {
			change = regex_replace(input, reg, "");
		}

		s.makeStack(change.length());
		for (int i = 0; i < s.size; i++) {
			char input = change.at(i);
			if (s.top == 0) { // ���� ���������
				if (input == '(' || input == '[') {
					s.Push(input);
				}
				else if (input == ')' || input == ']') {
					result = "no";
					break;
				}
			}
			else { // ���� ������� ������
				if (input == '(' || input == '[') {
					s.Push(input);
				}
				else if (input == ')') {
					if (s.Top() == "(") {
						s.Pop();
					}
					else {
						result = "no";
						break;
					}
				}
				else if (input == ']') {
					if (s.Top() == "[") {
						s.Pop();
					}
					else {
						result = "no";
						break;
					}
				}
			}
		}

		s.deleteStack();
		cout << result << endl;
		while (getchar() != '\n') {} // �Է� ���� �ʱ�ȭ
	}

	return 0;
}