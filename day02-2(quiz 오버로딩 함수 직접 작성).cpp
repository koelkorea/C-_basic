// 다음의 오버로딩 함수 작성해보기

// -square함수 오버로딩
//  1. int square(int a)
//      : 정수의 제곱을 구해 리턴 하는 함수
//  2. double square(double a)
//      : 실수의 제곱을 구해 리턴 하는 함수

// -Date함수 오버로딩
//  1. void date(int year, int month, int day)
//      : 년, 월, 일을 인수로 받아 날짜를 출력하는 함수(날짜 구분 기호는 '/')
//  2. void date(int year, int month, int day, char separate)
//      : 년, 월, 일과 구분 기호를 인수로 받아 날짜를 출력하는 함수
//  3. void date(const char* date)
//      : 문자열을 인수로 받아 날짜를 출력하는 함수

// -getTotal함수 오버로딩
//  1. int getTotal()
//      : 1 ~100 합계를 구해 리턴
//  2. int getTotal(int x)
//      : x ~100 합계를 구해 리턴
//  3. int getTotal(int x, int y)
//      : x ~ y 합계를 구해 리턴
#include <iostream>
using namespace std;

// ----------------------square함수 오버로딩------------------------------
int square(int a) {
	return a * a;
}

double square(double a) {
	return a * a;
}

// ----------------------Date함수 오버로딩---------------------------------
// 년, 월, 일을 인수로 받아 날짜를 출력하는 함수(날짜 구분 기호는 '/')
void date(int year, int month, int day) {
	cout << year << "/" << month << "/" << day << endl;
}

// 년, 월, 일과 구분 기호를 인수로 받아 날짜를 출력하는 함수
void date(int year, int month, int day, char separate) {
	cout << year << separate << month << separate << day << endl;
}

// 문자열을 인수로 받아 날짜를 출력하는 함수
void date(const char* date) {
	cout << date << endl;
}

// ----------------------getTotal함수 오버로딩---------------------------------
// 1 ~100 합계를 구해 리턴
int getTotal() {

	int result = 0;

	for (int i = 1; i <= 100; i++) {
		result += i;
	}

	return result;
}

// x ~100 합계를 구해 리턴
int getTotal(int x) {
	int result = 0;

	for (int i = 1; i <= x; i++) {
		result += i;
	}

	return result;
}

// x ~ y 합계를 구해 리턴
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

	// ----------------------square함수 오버로딩------------------------------
	cout << "----------------------square함수 오버로딩------------------------------\n";
	cout << "정수 입력 : ";
	cin >> input_int;
	cout << "정수 제곱값 : " << square(input_int) << endl;

	cout << "실수 입력 : ";
	cin >> input_double;
	cout << "실수 제곱값 : " << square(input_double) << endl;

	// ----------------------Date함수 오버로딩---------------------------------
	cout << "\n----------------------Date함수 오버로딩--------------------------------\n";
	date(2022, 04, 29);
	date(2022, 12, 01, '#');
	date("2023/11/05");

	// ----------------------getTotal함수 오버로딩---------------------------------
	cout << "\n----------------------Date함수 오버로딩--------------------------------\n";
	cout << getTotal() << endl;
	cout << getTotal(50) << endl;
	cout << getTotal(50, 500) << endl;

	return 0;
}
