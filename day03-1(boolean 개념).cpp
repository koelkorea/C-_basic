// Boolean
//  : true = 1�� false = 0�� ���� ���� 1byte�� ������ ����
//     -> 1�� 0���� ���� ������ �Ǻ��ϴ� �۾��� �� �� ���������� ó��

// Boolean�� ����..��
#include <iostream>
using namespace std;

// +, - �Ǻ� �Լ�
bool positiveNumber(int number) {

	if (number > 0) {
		// 1
		return true; 
	}
	else {
		// 0
		return false; 
	}
}

// +, - �Ǻ� �Լ�
bool nagetiveNumber(int number) {

	if (number < 0) {
		// 1
		return true;
	}
	else {
		// 0
		return false;
	}
}

// �빮�� �Ǻ�
bool isUpper(char ch) {

	if (ch >= 'Z' && ch <= 'A') {
		// 1
		return true;
	}
	else {
		// 0
		return false;
	}
}

// �빮�� �Ǻ�
bool isLower(char ch) {

	if (ch >= 'z' && ch <= 'a') {
		// 1
		return true;
	}
	else {
		// 0
		return false;
	}
}


int main() {

	//--------------------bool ���� ����------------------------
	bool start = -10.125;
	bool stop = 0;

	start = 0;

	cout << "bool �ڷ����� �� byte? : " << sizeof(bool) << "byte!" << endl;
	cout << "true & false�� ��? : " << true << " " << false << endl;



	while (1) {

		//----------------------���� �Ǻ�----------------------------
		int num;

		cout << endl << "���� �Է� : ";
		cin >> num;

		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(1, '\n');
		}

		// +, - �Ǻ� �Լ� ���
		if (num == 0) {
			cout << " ->> 0 �Դϴ�." << endl;
		}
		else if (positiveNumber(num)) {
			cout << " ->> ���� ���� �Դϴ�." << endl;
		}
		else if (nagetiveNumber(num)) {
			cout << " ->> ���� ���� �Դϴ�." << endl;
		}
		else {
			cout << " ->> ���ڰ� �ƴϹ��̴�." << endl;
		}

		//----------------------���ĺ� �Ǻ�----------------------------
		char ch;
		cout << endl << "���� �Է� : ";
		cin >> ch;

		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(1, '\n');
		}

		// ��/�ҹ��� �Ǻ�
		if (isUpper(ch)) {
			cout << " ->> �ҹ��� �Դϴ�." << endl;
		}
		else if (isLower(ch)) {
			cout << " ->> �빮�� �Դϴ�." << endl;
		}
		else {
			cout << " ->> ���ĺ��� �ƴϹ��̴�." << endl;
		}
	}

	return 0;
}
