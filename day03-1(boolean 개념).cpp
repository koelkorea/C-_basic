// Boolean
//  : true = 1와 false = 0의 값을 갖는 1byte인 데이터 형식
//     -> 1과 0으로 참과 거짓을 판별하는 작업을 좀 더 직관적으로 처리

// Boolean의 예시..들
#include <iostream>
using namespace std;

// +, - 판별 함수
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

// +, - 판별 함수
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

// 대문자 판별
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

// 대문자 판별
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

	//--------------------bool 설명 예시------------------------
	bool start = -10.125;
	bool stop = 0;

	start = 0;

	cout << "bool 자료형은 몇 byte? : " << sizeof(bool) << "byte!" << endl;
	cout << "true & false의 값? : " << true << " " << false << endl;



	while (1) {

		//----------------------숫자 판별----------------------------
		int num;

		cout << endl << "정수 입력 : ";
		cin >> num;

		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(1, '\n');
		}

		// +, - 판별 함수 사용
		if (num == 0) {
			cout << " ->> 0 입니다." << endl;
		}
		else if (positiveNumber(num)) {
			cout << " ->> 양의 정수 입니다." << endl;
		}
		else if (nagetiveNumber(num)) {
			cout << " ->> 음의 정수 입니다." << endl;
		}
		else {
			cout << " ->> 숫자가 아니므이다." << endl;
		}

		//----------------------알파벳 판별----------------------------
		char ch;
		cout << endl << "문자 입력 : ";
		cin >> ch;

		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(1, '\n');
		}

		// 대/소문자 판별
		if (isUpper(ch)) {
			cout << " ->> 소문자 입니다." << endl;
		}
		else if (isLower(ch)) {
			cout << " ->> 대문자 입니다." << endl;
		}
		else {
			cout << " ->> 알파벳이 아니므이다." << endl;
		}
	}

	return 0;
}
