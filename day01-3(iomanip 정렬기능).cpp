#include <iostream>
#include<iomanip>  // left, right, setw(int : ĭ��) : cout�� ���� ����ϰ�, left�� right ���� �� set(int)�� ����, ĭ���� �ش��ϴ� ������ ���� �� �������� ������ ������(= ����������)? ���������� ������ ������(= ��������)�� ����

using namespace std;  // std:: ��������

int main() {

	cout << left;

	for (int i = 1; i <= 100; i++) {

		if (i % 2 == 0) {
			cout << right;
			cout << setw(5) << i;
			cout << endl;
		}
		else {
			cout << left;
			cout << setw(5) << i << "|";
		}
	}

	cout << endl;

	return 0;
}