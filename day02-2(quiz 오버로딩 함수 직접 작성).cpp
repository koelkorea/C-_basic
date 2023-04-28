// ������ �����ε� �Լ� �ۼ��غ���

// -square�Լ� �����ε�
//  1. int square(int a)
//      : ������ ������ ���� ���� �ϴ� �Լ�
//  2. double square(double a)
//      : �Ǽ��� ������ ���� ���� �ϴ� �Լ�

// -Date�Լ� �����ε�
//  1. void date(int year, int month, int day)
//      : ��, ��, ���� �μ��� �޾� ��¥�� ����ϴ� �Լ�(��¥ ���� ��ȣ�� '/')
//  2. void date(int year, int month, int day, char separate)
//      : ��, ��, �ϰ� ���� ��ȣ�� �μ��� �޾� ��¥�� ����ϴ� �Լ�
//  3. void date(const char* date)
//      : ���ڿ��� �μ��� �޾� ��¥�� ����ϴ� �Լ�

// -getTotal�Լ� �����ε�
//  1. int getTotal()
//      : 1 ~100 �հ踦 ���� ����
//  2. int getTotal(int x)
//      : x ~100 �հ踦 ���� ����
//  3. int getTotal(int x, int y)
//      : x ~ y �հ踦 ���� ����
#include <iostream>
using namespace std;

// ----------------------square�Լ� �����ε�------------------------------
int square(int a) {
	return a * a;
}

double square(double a) {
	return a * a;
}

// ----------------------Date�Լ� �����ε�---------------------------------
// ��, ��, ���� �μ��� �޾� ��¥�� ����ϴ� �Լ�(��¥ ���� ��ȣ�� '/')
void date(int year, int month, int day) {
	cout << year << "/" << month << "/" << day << endl;
}

// ��, ��, �ϰ� ���� ��ȣ�� �μ��� �޾� ��¥�� ����ϴ� �Լ�
void date(int year, int month, int day, char separate) {
	cout << year << separate << month << separate << day << endl;
}

// ���ڿ��� �μ��� �޾� ��¥�� ����ϴ� �Լ�
void date(const char* date) {
	cout << date << endl;
}

// ----------------------getTotal�Լ� �����ε�---------------------------------
// 1 ~100 �հ踦 ���� ����
int getTotal() {

	int result = 0;

	for (int i = 1; i <= 100; i++) {
		result += i;
	}

	return result;
}

// x ~100 �հ踦 ���� ����
int getTotal(int x) {
	int result = 0;

	for (int i = 1; i <= x; i++) {
		result += i;
	}

	return result;
}

// x ~ y �հ踦 ���� ����
int getTotal(int x, int y) {

	int result = 0;

	for (int i = x; i <= y; i++) {
		result += i;
	}

	return result;

}

int main() {

	int input_int;
	double input_double;

	// ----------------------square�Լ� �����ε�------------------------------
	cout << "----------------------square�Լ� �����ε�------------------------------\n";
	cout << "���� �Է� : ";
	cin >> input_int;
	cout << "���� ������ : " << square(input_int) << endl;

	cout << "�Ǽ� �Է� : ";
	cin >> input_double;
	cout << "�Ǽ� ������ : " << square(input_double) << endl;

	// ----------------------Date�Լ� �����ε�---------------------------------
	cout << "\n----------------------Date�Լ� �����ε�--------------------------------\n";
	date(2022, 04, 29);
	date(2022, 12, 01, '#');
	date("2023/11/05");

	// ----------------------getTotal�Լ� �����ε�---------------------------------
	cout << "\n----------------------Date�Լ� �����ε�--------------------------------\n";
	cout << getTotal() << endl;
	cout << getTotal(50) << endl;
	cout << getTotal(50, 500) << endl;

	return 0;
}
