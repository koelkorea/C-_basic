//ACT 클래스의 정의부를 위한 파일
#include <iostream>
#include <cstring>
#include "day05-3의 헤더.h"
using namespace std;
void ACT::Init_act(int _actid, const char* _PW, const char* _NAME, int _BAL) {
	ACTId = _actid;
	strcpy_s(pw, strlen(_PW) + 1, _PW);
	strcpy_s(name, strlen(_NAME) + 1, _NAME);
	bal = _BAL;
}
void ACT::showData() {
	cout << "\n계좌번호 : " << ACTId << endl;
	cout << name << " 회원님의 잔액은 " << bal << "입니다.\n";
}
void ACT::deposit() {
	int m;
	cout << "\n입금금액 입력 : ";
	cin >> m;
	bal += m;
	cout << "\t\t" << m << "원 입금완료.\n";
}
void ACT::withdraw() {
	int m;
	cout << "\n출금금액 입력 : ";
	cin >> m;
	bal -= m;
	cout << "\t\t" << m << "원 출금완료.\n";
}
