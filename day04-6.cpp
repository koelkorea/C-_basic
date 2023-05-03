// new, delete�� �̿��� c++�� �����Ҵ�, ���� ������� 'linked list'�� ���� ������ ����� ���� �ڵ带 �ۼ��ض�
// 1. �л� ���� ���
// 2. �л� ���� ����
// 3. �л� ���� ��ü ����Ʈ ���
// 4. ��ü����
// 5. ����
// -> �޴������Ͽ� �����ϰ�

#include <iomanip>    // setw() �ڸ��� ���
#include <cstring>    
#include <iostream>

using namespace std;

typedef struct STU {
	char* name;
	char* phoneNumber;
}STU;

typedef STU NodeElement;

struct Node {
	NodeElement value;
	Node* link;
};

void PrintMenu(int& menu);
bool InsertNode(Node*& head, NodeElement data);
bool DeleteNode(Node*& head, NodeElement data, int deleteNodenum);
bool DeleteAll(Node*& head);
bool PrintList(Node*& head);

void cinput(int& n) {
	while (!(cin >> n)) {
		cin.clear();

		while (cin.get() != '\n') {
			continue;
		}
	}
}

void cinput(char& n) {
	while (!(cin >> n)) {
		cin.clear();

		while (cin.get() != '\n') {
			continue;
		}
	}
}

void cinclear(int n) {

	if (cin.fail()) {
		cin.clear();
		cin.ignore(n, '\n');
	}
}

Node* LinkedHead = new Node;

int main() {

	LinkedHead->value;
	LinkedHead->link = NULL;

	int menuNum = 0;
	
	while (1) {

		cout << "1. �л� ���� ���" << endl;
		cout << "2. �л� ���� ����" << endl;
		cout << "3. �л� ���� ��ü ����Ʈ ���" << endl;
		cout << "4. �л� ���� ��ü����" << endl;
		cout << "5. ���α׷� ����" << endl << endl;
		cout << "�޴���ȣ ���� :";

		cin >> menuNum;
		

		PrintMenu(menuNum);

	}

	return 0;

}

void PrintMenu(int& menu) {

	if (menu == 1) {

		// -----------------------------------------------------[�л� ���� STU ���� & �ۼ�]--------------------------------------------------------------------------
		// 1. �л� �� �Է� �ޱ�
		int studentCnt;

		cout << "���� �Է��� �л� ���� �Է����ֽʼ� : ";
		cin >> studentCnt;

		// �� �Է°� ũ�⿡ �ش��ϴ� ����ũ�⸦ ���� char�迭�� ����� ����, �ϴ� �Է°� ��ü�� �ޱ� ���� ���� �迭�� �ϳ� ����� �ش�
		char inputName[20];
		char inputPhoneNumber[20];

		// 3. �� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
		for (int i = 0; i < studentCnt; i++) {

			// 2. �л� �� ��ŭ ������ ���� �� �޸� ���� ���� �Ҵ�
			// STU ����ü �����ͺ����� new �����ڸ� ���� �޸𸮿� �Է��� �л����� �ش��ϴ� ��ŭ�� ũ�⸦ ���� STU����ü �迭�� �Ҵ��ϰ�, �� �����ּҸ� �����ͺ����� ���� 
			// (= �� ������ ������ STU ����ü�� �ּҰ��� call by reference ������ �������� ������ �Ѱ���)
			//  : �ڷ��� * ������ = new �ڷ���;   <->   malloc(byte ũ��), calloc ���� ���� ���ž� �ٸ�
			STU* student = new STU;

			cout << setw(3) << i + 1 << "��°�� �Է��� �л��� '�̸�'�� '��ȭ��ȣ'�� �Է����ּ��� : ";
			cin >> inputName >> inputPhoneNumber;

			// 4. �̸�, ��ȭ��ȣ ���� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
			student->name = new char[strlen(inputName) + 1];

			// �����迭�� �Էµ� �̸� ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
			for (int j = 0; j <= strlen(inputName); j++) {
				student->name[j] = inputName[j];

			}

			// 4. �̸�, ��ȭ��ȣ ���� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
			student->phoneNumber = new char[strlen(inputPhoneNumber) + 1];

			// �����迭�� �Էµ� ��ȭ��ȣ ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
			for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
				student->phoneNumber[j] = inputPhoneNumber[j];
			}

			if (InsertNode(LinkedHead, *student) == true) {

				cout << " >>>> (�˸�) �л� " << i + 1 << "�� ������ �Է� �Ϸ�.." << endl << endl;
			}
			else {
				cout << " >>>> (�˸�) �л� " << i + 1 << "�� ������ �Է� ����!" << endl << endl;
			}

		}

	}
	else if (menu == 2) {

		int deleteNodenum = 0;

		PrintList(LinkedHead);

		cout << "�� ��° ��带 ����� �����Ű���? : ";
		cin >> deleteNodenum;

		Node* tmp = LinkedHead;

		for (int i = 0; i < deleteNodenum; i++) {
			tmp = tmp->link;
		}

		STU* deleteStudentInfo = new STU;

		*deleteStudentInfo = tmp->value;

		if (DeleteNode(LinkedHead, *deleteStudentInfo, deleteNodenum) == true) {

			cout << " >>>> (�˸�)" << deleteNodenum << "��° �л� ���� ���� �Ϸ�!" << endl << endl;
		}
		else {
			cout << " >>>> (�˸�)" << deleteNodenum << "��° �л� ���� ���� ����!" << endl << endl;
		}
	}
	else if (menu == 3) {

		if (PrintList(LinkedHead) == true) {

			cout << " >>>> (�˸�) �л� ���� ��¿Ϸ�!" << endl << endl;
		}
		else {
			cout << " >>>> (�˸�) �л� ������ ���ų�, ����� ����!" << endl << endl;
		}

	}
	else if (menu == 4) {

		if (DeleteAll(LinkedHead) == true) {

			cout << " >>>> (�˸�) �л� ���� ��ü �����Ϸ�!" << endl << endl;
		}
		else {
			cout << " >>>> (�˸�) �л� ������ ���ų�, ��ü ���� ����!" << endl << endl;
		}

	}
	else if (menu == 5) {
		cout << " >>>> (�˸�) �л����� ���α׷��� �����մϴ�..." << endl << endl;
		exit(0);
	}

}

bool InsertNode(Node*& head, NodeElement data) {

	bool flag = false;

	if (data.name != NULL && data.phoneNumber != NULL) {

		Node* tmp = head;

		while (tmp->link != NULL) {

			flag = true;
			tmp = tmp->link;
		}

		Node* studentLinked = new Node;

		studentLinked->value.name = data.name;
		studentLinked->value.phoneNumber = data.phoneNumber;

		studentLinked->link = NULL;

		tmp->link = studentLinked;

		flag = true;
	}

	return flag;
}

bool DeleteNode(Node*& head, NodeElement data, int deleteNodenum) {

	bool flag = false;

	if (deleteNodenum == 1) {

		head->link = head->link->link;
		delete head->link;

		flag = true;

	}else{

		Node* tmp = head;

		for (int i = 1; i <= deleteNodenum; i++) {

			tmp = tmp->link;

			if (i == deleteNodenum - 1) {

				if (tmp->link->link != NULL) {

					tmp->link = tmp->link->link;
				}
				else {
					tmp->link = NULL;
				}

			}
			else if (i == deleteNodenum) {
				delete tmp;
			}
		}
		flag = true;
	}

	return flag;
}

bool PrintList(Node*& head) {

	bool flag = false;
	int studentNum = 0;

	Node* tmp = head;

	while (tmp->link != NULL) {

		flag = true;
		tmp = tmp->link;
		
		cout << endl << "�л� " << setw(3) << ++studentNum << "�� ����" << endl;
		cout << " ->> �̸� : " << tmp->value.name << endl;
		cout << " ->> ��ȭ��ȣ : " << setw(3) << tmp->value.phoneNumber << endl;
	}

	cout << endl;

	return flag;
}

bool DeleteAll(Node*& head) {

	bool flag = false;

	Node* tmp = head;
	Node* tmpForDelete = head;

	while (tmp->link != NULL) {

		flag = true;
		tmpForDelete = tmp;
		tmp = tmp->link;

		delete tmpForDelete;
	}

	head->link = NULL;

	return flag;

}