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
	// STU ����ü �����ͺ����� new �����ڸ� ���� �޸𸮿� �Է��� �л����� �ش��ϴ� ��ŭ�� ũ�⸦ ���� STU����ü �迭�� �Ҵ��ϰ�, �� �����ּҸ� �����ͺ����� ���� 
	// (= �� ������ ������ STU ����ü�� �ּҰ��� call by reference ������ �������� ������ �Ѱ���)
	//  : �ڷ��� * ������ = new �ڷ���;   <->   malloc(byte ũ��), calloc ���� ���� ���ž� �ٸ�
	STU* student = new STU[studentCnt];

	cout << endl << "[�л����� ����]" << endl << endl;

	// �� �Է°� ũ�⿡ �ش��ϴ� ����ũ�⸦ ���� char�迭�� ����� ����, �ϴ� �Է°� ��ü�� �ޱ� ���� ���� �迭�� �ϳ� ����� �ش�
	char inputName[13];
	char inputPhoneNumber[13];

	// 3. �� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
	for (int i = 0; i < studentCnt; i++) {

		cout << "�л� " << setw(3) << i + 1 << "���� �̸��� ��ȭ��ȣ�� �Է����ּ��� : ";
		cin >> inputName >> inputPhoneNumber;

		// 4. �̸�, ��ȭ��ȣ ���� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
		student[i].name = new char[strlen(inputName) + 1];

		// �����迭�� �Էµ� �̸� ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
		for (int j = 0; j <= strlen(inputName); j++) {
			student[i].name[j] = inputName[j];

		}

		// 4. �̸�, ��ȭ��ȣ ���� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
		student[i].phoneNumber = new char[strlen(inputPhoneNumber) + 1];

		// �����迭�� �Էµ� ��ȭ��ȣ ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
		for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
			student[i].phoneNumber[j] = inputPhoneNumber[j];
		}

	}

	// 5. �� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
	for (int i = 0; i < studentCnt; i++) {

		cout << endl << "�л� " << setw(3) << i + 1 << "�� ����" << endl;
		cout << " ->> �̸� : " << student[i].name << endl;
		cout << " ->> ��ȭ��ȣ : " << setw(3) << student[i].phoneNumber << endl;

		delete[] student[i].name;
		delete[] student[i].phoneNumber;
	}

	// int �迭 �޸� ��������
	//  : delete ������;  <->   free ���� ���� ���ž� �ٸ�
	delete[] student;

	return 0;

}