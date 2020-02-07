#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int num; // 좌표 개수
	cin >> num;
	vector<vector<int>> dots(num, vector<int>(2, 0)); // 입력받을 좌표
	for (int i = 0; i < num; i++) {
		cin >> dots[i][1] >> dots[i][0];
	}
	sort(dots.begin(), dots.end());

	for (int i = 0; i < num; i++) {
		cout << dots[i][1] <<  " " << dots[i][0] << endl;
	}

	return 0;
}