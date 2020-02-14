#include <iostream>
using namespace std;

int arr[130][130];
int white; // �߶��� �Ͼ�� ������ ����
int blue; // �߶��� �Ķ��� ������ ����

void check(int s, int x, int y) {
	int color = arr[x][y];
	for (int i = x; i < s + x; i++) {
		for (int j = y; j < s + y; j++) {
			if (arr[i][j] != color) {
				check(s / 2, x, y);
				check(s / 2, x + s / 2, y);
				check(s / 2, x, y + s / 2);
				check(s / 2, x + s / 2, y + s / 2);
				return;
			}
		}
	}
	if (color == 0) { white++; }
	else if (color == 1) { blue++; }
}

int main() {

	int size; // �� ���� ����
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> arr[i][j];
		}
	}

	check(size, 0, 0);

	cout << endl;
	cout << white << endl;
	cout << blue << endl;

	return 0;
}