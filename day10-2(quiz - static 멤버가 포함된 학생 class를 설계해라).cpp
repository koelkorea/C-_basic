// static �������, ����Լ��� ���Ե� student class�� �����ض�, ������ ������ ����
// 
// 1. private�������
//     - �й�
//     - �̸�
//     - ����
//     - �л��� (static �������)

// 2. public ����Լ�
//     - student ������           : �й��� 20230000���� ���ʷ� 1�� ���� �ǵ��� ����
//     - (const) print_info()     : �л� ���� ���
//     - (static) print_std_cnt() : �л� �� ���

#include <iostream>
#include <iomanip>

using namespace std;

// �л� Ŭ����
class student {

	private : 

		// �й�
		int studentNum;
		// �̸�
		char* name;
		// ����
		int age;

		// ���� �� �й�(static)
		static int currentStudentNum;
		// ���� �л� ��(static)
		static int theNumOfStudent;

	public :

		student(char* _name, int _age) {
			theNumOfStudent++;
			studentNum = currentStudentNum++;
			name = _name;
			age = _age;
		}

		const void print_std_cnt() {
			cout << endl;
			cout << "       [�й� " << studentNum << "�� �л� ����]" << endl;
			cout << "        - �̸� " << *name << "�� �л� ����" << endl;
			cout << "        - ���� " << age << "�� �л� ����" << endl << endl;
		}

		static void print_info() {
			cout << " ->> [�߿�] ���� ��ϵ� �л����� �� " << theNumOfStudent << "�Դϴ�!" << endl << endl;
		}

		inline char* getName() {

			return name;
		}

};

int student::currentStudentNum = 20230000;
int student::theNumOfStudent = 0;

//---------------------------------------------------���� cin.clear�� ������Ų �޼��� cinput--------------------------------------------
void cinclear() {
	if (cin.fail()) {
		cin.clear();
		while (cin.get() != '\n');
	}
	else while (cin.get() != '\n');
}

void cinput(int& n) {
	while (!(cin >> n)) {
		cinclear();
		cout << "(�˸�) �Է��� �߸��Ǿ����ϴ�. �ٽ� �Է��ϼ���!" << endl << endl;
	}
}

void cinput(char& n) {
	while (!(cin >> n)) {
		cinclear();
		cout << "(�˸�) �Է��� �߸��Ǿ����ϴ�. �ٽ� �Է��ϼ���!" << endl << endl;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------

int main() {

	int flag = 0;

	while(flag == 0){

		// �л� �� �Է� �ޱ�
		int studentCnt;

		cout << endl << "[�л��������� �Է±��]" << endl << endl << "���� �Է��� �л� ���� �Է����ֽʼ� : ";
		cinput(studentCnt);

		// �� �Է°� ũ�⿡ �ش��ϴ� ����ũ�⸦ ���� char�迭�� ����� ����, �ϴ� �Է°� ��ü�� �ޱ� ���� ���� �迭�� �ϳ� ����� �ش�
		char inputName[100];
		int inputAge;

		// �Է��� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
		for (int i = 0; i < studentCnt; i++) {

			// �̸�, ���� �����迭�� �Է�
			cout << " ->> " << setw(3) << i + 1 << "��°�� �Է��� �л��� '�̸�'�� '����'�� �Է����ּ��� : ";
			cin >> inputName >> inputAge;

			// 'name' char ũ�⸸ŭ�� �����迭�� �޸𸮿� �Ҵ��Ͽ� ���� ��,  
			//  -> �׵��� char �����Ͱ��� ������ �Լ��� parameter�� �����Ͽ� student ��ü �ν��Ͻ��� ������� ������ �����Ͽ� ��ü ����
			//     (= ���� �Է��ϴ� �л�����(�̸�, ����)�� ���� ���α׷��� ���� ������ �����ϰ� ������ �������� �����Ҵ� + ��ü �������� ��Ʈ�޴��� �Ϸ��ϴ� ���� ���)
			student* eachStudent = new student(new char[strlen(inputName) + 1], inputAge);

			// strcpy_s �Լ��� ���� ���ڿ� ����
			strcpy_s(eachStudent->getName(), strlen(inputName) + 1, inputName);

			// ����Լ� ����
			eachStudent->print_std_cnt();
		}

		// static ����Լ� ����
		student::print_info();

		cout << "(�ȳ�!) ���� �Ϸ�Ǿ����ϴ�. ����Ͻðڽ��ϱ�? (����ϰ� �����ø� 0�� �Է����ּ���)";
		cin >> flag;

	}

	return 0;
}