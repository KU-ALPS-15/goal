#include <iostream>
#include <string>
using namespace std;

class stack {

public:

	string* sArray; // 스택배열
	int size; // 스택배열 사이즈
	int top; // 스택 탑

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

	int t; // 입력 데이터 수
	string* inputArr; // 입력 데이터 저장
	string* outputArr; // 출력 데이터 저장
	stack s; // 스택 구조체

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
			if (s.top == 0) { // 스택 비어있으면
				if (input == '(') {
					s.Push(input);
				}
				else if (input == ')') {
					outputArr[i] = "NO";
					break;
				}
			}
			else { // 스택 비어있지 않으면
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