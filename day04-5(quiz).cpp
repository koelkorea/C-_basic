// new, delete�� �̿��� c++�� �����Ҵ�, ���� ������� ������ ����� ���� �ڵ带 �ۼ��ض�
// 1. �л� �� �Է� �ޱ�
// 2. �л� �� ��ŭ STU �޸� ���� ���� �Ҵ�
// 3. �� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
// 4. �̸�, ��ȭ��ȣ ���� ���ڿ� ���̸�ŭ �����Ҵ�
// 5. �� �л� �̸�, ��ȭ��ȣ ���� ��� ���

#include <iomanip>    // setw() �ڸ��� ���
#include <cstring>    
#include <iostream>

using namespace std;

typedef struct STU {
	char* name;
	char* phoneNumber;
}STU;

int main() {

	// 1. �л� �� �Է� �ޱ�
	int studentCnt;

	cout << "���ϴ� �л� ���� �Է����ֽʼ� : ";
	cin >> studentCnt;

	// 2. �л� �� ��ŭ ������ ���� �� �޸� ���� ���� �Ҵ�
	// char �����ͺ����� new �����ڸ� ���� �޸𸮿� �Ҵ��ϰ�, �� �����ּҸ� �����ͺ����� ���� (= �� ������ ������ char�迭�� �ּҰ��� call by reference ������ �������� ������ �Ѱ���)
	//  : �ڷ��� * ������ = new �ڷ���;   <->   malloc(byte ũ��), calloc ���� ���� ���ž� �ٸ�
	STU* student = new STU[studentCnt];

	cout << endl << "[�л����� ����]" << endl << endl;

	char name[5];
	char phoneNumber[13];

	// 3. �� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
	for (int i = 0; i < studentCnt; i++) {

		cout << "�л� " << setw(3) << i + 1 << "���� �̸��� �Է����ּ��� : ";
		cin >> name;

		// 4. �̸�, ��ȭ��ȣ ���� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
		student[i].name = new char[strlen(name) + 1];

		for (int j = 0; j <= strlen(name); j++) {
			student[i].name[j] = name[j];
		}

		cout << "�л� " << setw(3) << i + 1 << "���� ��ȭ��ȣ�� �Է����ּ��� : ";
		cin >> phoneNumber;

		// 4. �̸�, ��ȭ��ȣ ���� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
		student[i].phoneNumber = new char[strlen(name) + 1];

		for (int j = 0; j <= strlen(phoneNumber); j++) {
			student[i].phoneNumber[j] = phoneNumber[j];
		}
		
	}

	// 5. �� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
	for (int i = 0; i < studentCnt; i++) {

		cout << endl << "�л� " << setw(3) << i + 1 << "�� ����" << endl;
		cout << " ->> �̸� : " << student[i].name << endl;
		cout << " ->> ��ȭ��ȣ : " << setw(3) << student[i].phoneNumber << endl;
	}

	for (int i = 0; i < studentCnt; i++) {
		delete[] student[i].name;
		delete[] student[i].phoneNumber;
	}

	// int �迭 �޸� ��������
	//  : delete ������;  <->   free ���� ���� ���ž� �ٸ�
	delete[] student;

	return 0;

}