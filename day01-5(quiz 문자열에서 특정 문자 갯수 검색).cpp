// quiz : a���ڿ��� �Է¹ް� -> �˻����� �Է� -> �װ��� ��ҹ��� ���� ��� �����Ͽ� ������ �˻��ض�
 
// c++���� ���ڿ��� ���� �����ؼ� �Է¹޴�(enterŰ�� ����) �Լ� 
//  : cin.getline(�迭��, ĭ��);

// c++���� ���ڿ� �Է½� ����Ű �ߺ��� �����ִ� ���
//-------------------------------------------------------
// 1. cin.fail(), cin.clear() ���
//  -> cin.fail() : std::cin�� �����ߴ��� ���θ� 0 1�� üũ
//  -> cin.clear(): std::cin�� ���� ��Ʈ���� �ʱ�ȭ
//  -> cin.ignore(n) : �Է� n�� ���ۺ���(= �׳� ��������)

//  if (cin.fail()) {
//  	cin.clear();
//  }

//-------------------------------------------------------
// 2. cin.get() ��� : �Է� ������ ���� 1���� �Է¹���
//  cin.get();

#include <iostream>
#include <iomanip>  // left, right, setw(int : ĭ��) : cout�� ���� ����ϰ�, left�� right ���� �� set(int)�� ����, ĭ���� �ش��ϴ� ������ ���� �� �������� ������ ������(= ����������)? ���������� ������ ������(= ��������)�� ����

using namespace std;  // std:: ��������

int main() {

	char input[50] = {0};
	char code = 0;

	while (1) {

		cout << "���ڿ� �Է� : ";
		cin.getline(input, 50);

		// c++���� ���ڿ� �Է½� ����Ű �ߺ��� �����ִ� ���
		//-------------------------------------------------------
		// 1. cin.fail(), cin.clear() ���
		//  -> cin.fail() : std::cin�� �����ߴ��� ���θ� 0 1�� üũ
		//  -> cin.clear(): std::cin�� ���� ��Ʈ�� ���� �����

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1);
		}

		//-------------------------------------------------------
		// 2. cin.get() ��� : �Է� ������ ���ڸ� �Է¹���
		// cin.get();

		cout << "�˻����� �Է� : ";
		cin >> code;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1);
		}

		int index = 0;
		int result = 0;

		// �ҹ��� -> �빮��
		if (code >= 97 && code <= 122) {

			for (int i = 0; input[i] != '\0'; i++) {

				if (input[i] == code || input[i] == (code - 32) ) {

					result++;
				}
			}

			cout << " ->> �˻�����[" << (char)code << "(" << (char)(code - 32) << ")]�� ������[" << result << "]�� �Դϴ�." << endl << endl;
		}
		// �빮�� -> �ҹ���
		else if (code >= 65 && code <= 90) {

			for (int i = 0; input[i] != '\0'; i++) {

				if (input[i] == code || input[i] == (code + 32) ) {

					result++;
				}
			}

			cout << " ->> �˻�����[" << (char)code << "(" << (char)(code + 32) << ")]�� ������[" << result << "]�� �Դϴ�." << endl << endl;
		}
		else {

			cout << " ->> �����ڸ� �Է��ض�..." << endl << endl;
		}

		cin.ignore(1);
	}

	return 0;
}