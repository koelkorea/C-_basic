//ACT Ŭ������ ���Ǻθ� ���� ����
#include <iostream>
#include <cstring>
#include "day05-3�� ���.h"
using namespace std;
void ACT::Init_act(int _actid, const char* _PW, const char* _NAME, int _BAL) {
	ACTId = _actid;
	strcpy_s(pw, strlen(_PW) + 1, _PW);
	strcpy_s(name, strlen(_NAME) + 1, _NAME);
	bal = _BAL;
}
void ACT::showData() {
	cout << "\n���¹�ȣ : " << ACTId << endl;
	cout << name << " ȸ������ �ܾ��� " << bal << "�Դϴ�.\n";
}
void ACT::deposit() {
	int m;
	cout << "\n�Աݱݾ� �Է� : ";
	cin >> m;
	bal += m;
	cout << "\t\t" << m << "�� �ԱݿϷ�.\n";
}
void ACT::withdraw() {
	int m;
	cout << "\n��ݱݾ� �Է� : ";
	cin >> m;
	bal -= m;
	cout << "\t\t" << m << "�� ��ݿϷ�.\n";
}
