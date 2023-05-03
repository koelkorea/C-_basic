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

// ����ü STU : �л� �������� ��������... 
//  - �̸� : ���ڿ�(string �ƴϰ�, char �迭�� �ޱ⿡ char �����ͺ���)
//  - ��ȭ��ȣ : ���ڿ�(string �ƴϰ�, char �迭�� �ޱ⿡ char �����ͺ���)
typedef struct STU {
	char* name;
	char* phoneNumber;
}STU;

typedef STU NodeElement;

// ����ü Node : �л� ���� ����ü�� STU�� �����ͷ� �޴� linkedList... ���� Node
//  - value : STU ����ü (������ �ƴ� = ����ü ��ü�� ����� ��)
//  - link  : ���� �����Ͱ� ��ġ�� ����� �ּҸ� �� Node����ü ������ ����
struct Node {

	// (�߿�) new Node�� �ϸ� �ڵ����� �Ҵ�
	NodeElement value;
	Node* link;
};

void PrintMenu(int& menu);
bool InsertNode(Node*& head, NodeElement data);
bool DeleteNode(Node*& head, int deleteNodenum);
bool DeleteAll(Node*& head);
bool PrintList(Node*& head);

void cinclear(int n) {

	if (cin.fail()) {
		cin.clear();
		cin.ignore(n, '\n');
	}
}

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

// �л����� LinkedList�� ������ head
//  : �Ҽ� STU����.. link�� 1��° ��尡 ������ �� ����ּ�.. ������ NULL
Node* LinkedHead = new Node;

int main() {

	// ----------------------------------[Node ����ü ���� STU����ü�� new Node;�� �ϸ� �ڵ����� ���� �� ������ �Ҵ�Ǵ°� ����]-----------------------------

	// �� �Է°� ũ�⿡ �ش��ϴ� ����ũ�⸦ ���� char�迭�� ����� ����, �ϴ� �Է°� ��ü�� �ޱ� ���� ���� �迭�� �ϳ� ����� �ش�
	char* inputName = (char*) "���";
	char* inputPhoneNumber = (char*) "��ȭ��ȣ";

	// �̸��� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
	LinkedHead->value.name = new char[strlen(inputName) + 1];

	// �����迭�� �Էµ� �̸� ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
	for (int j = 0; j <= strlen(inputName); j++) {
		LinkedHead->value.name[j] = inputName[j];

	}

	// ��ȭ��ȣ�� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
	LinkedHead->value.phoneNumber = new char[strlen(inputPhoneNumber) + 1];

	// �����迭�� �Էµ� ��ȭ��ȣ ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
	for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
		LinkedHead->value.phoneNumber[j] = inputPhoneNumber[j];
	}

	cout << "-------Node ����ü ���� STU����ü�� new Node;�� �ϸ� �ڵ����� ���� �� ������ �Ҵ�Ǵ°�?--------- " << endl << endl;
	cout << " ->> new STU���� ���Էµ� LinkedList �������� ������ �Է�" << endl;
	cout << " ->> (name) : "  << LinkedHead->value.name << ", (phoneNumber) : " << LinkedHead->value.phoneNumber << endl << endl;
	cout << "-------[���] �ȿ� ����ü�� �ִ� ����ü�� new�� �����ϸ�, ���� ����ü�� �˾Ƽ� �� ��������--------" << endl << endl;

	//--------------------------------------------------------------------------------------------------------------------------------------------------------

	// LinkedList�� head�� link�� �ϴ� NULL �ʱ�ȭ.. (��ϵ� �л������� ����)
	LinkedHead->link = NULL;

	// �޴����� ��ȣ �޾��� ���� (�ʱⰪ 0)
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

// �޴� �Է�ȭ�鿡�� �޴��� ������ ���Ǻη� �������
void PrintMenu(int& menu) {

	// 1. �л����� �Է±��
	if (menu == 1) {

		// -----------------------------------------------------[�л� ���� STU ���� & �ۼ�]--------------------------------------------------------------------------
		// �л� �� �Է� �ޱ�
		int studentCnt;

		cout << "���� �Է��� �л� ���� �Է����ֽʼ� : ";
		cin >> studentCnt;

		// �� �Է°� ũ�⿡ �ش��ϴ� ����ũ�⸦ ���� char�迭�� ����� ����, �ϴ� �Է°� ��ü�� �ޱ� ���� ���� �迭�� �ϳ� ����� �ش�
		char inputName[100];
		char inputPhoneNumber[100];

		// �Է��� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
		for (int i = 0; i < studentCnt; i++) {

			// STU ����ü �����ͺ����� new �����ڸ� ���� �޸𸮿� �Է��� �л����� �ش��ϴ� ��ŭ�� ũ�⸦ ���� STU����ü �迭�� �Ҵ��ϰ�, �� �����ּҸ� �����ͺ����� ���� 
			// (= �� ������ ������ STU ����ü�� �ּҰ��� call by reference ������ �������� ������ �Ѱ���)
			//  : �ڷ��� * ������ = new �ڷ���;   <->   malloc(byte ũ��), calloc ���� ���� ���ž� �ٸ�
			STU* student = new STU;

			cout << " ->> "  << setw(3) << i + 1 << "��°�� �Է��� �л��� '�̸�'�� '��ȭ��ȣ'�� �Է����ּ��� : ";
			cin >> inputName >> inputPhoneNumber;

			//------------------------------[Node�� ����� STU ����ü�� �Է��� �̸�, ���� �ű��]---------------------------

			// �̸��� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
			student->name = new char[strlen(inputName) + 1];

			// �����迭�� �Էµ� �̸� ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
			for (int j = 0; j <= strlen(inputName); j++) {
				student->name[j] = inputName[j];

			}

			// ��ȭ��ȣ�� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
			student->phoneNumber = new char[strlen(inputPhoneNumber) + 1];

			// �����迭�� �Էµ� ��ȭ��ȣ ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
			for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
				student->phoneNumber[j] = inputPhoneNumber[j];
			}

			//--------------------------------------------------------------------------------------------------------------

			// �Է� �޼��忡 �Է��� �л� �ش� ������, Linked�� ������ head����� �����ּҰ��� ������ Node�����ͺ����� param���� ����
			//  -> ���� ���� ���ο����� �˸� �޶����� ��
			if (InsertNode(LinkedHead, *student) == true) {

				cout << "   >>>> (�˸�) �л� " << i + 1 << "�� ������ �Է� �Ϸ�.." << endl << endl;
				delete student;
			}
			else {
				cout << "   >>>> (�˸�) �л� " << i + 1 << "�� ������ �Է� ����!" << endl << endl;
				delete student;
			}

		}

	}
	// 2. Ư�� �л��� ���� �������
	else if (menu == 2) {

		// ���� ��ϵ� ��� �л����� ������ ������
		//  -> ����Ʈ ����� �����ϸ�?
		if (PrintList(LinkedHead) == true) {

			// ������ �л��� ���°�� ������ ���� ����
			int deleteNodenum = 0;

			cout << "�� ��° ��带 ����� �����Ű���? : ";
			cin >> deleteNodenum;

			// ���� �޼��忡  Linked�� ������ head����� ���� �л��� ���°�� �ִ��� ���θ� param���� ����
			//  -> ���� ���� ���ο����� �˸� �޶����� ��
			if (DeleteNode(LinkedHead, deleteNodenum) == true) {

				cout << "      >>>> (�˸�)" << deleteNodenum << "��° �л� ���� ���� �Ϸ�!" << endl << endl;
			}
			else {
				cout << "      >>>> (�˸�)" << deleteNodenum << "��° �л� ���� ���� ����!" << endl << endl;
			}
		}
		//  -> ����Ʈ ����� ���н�?
		else {
			cout << "      >>>> (�˸�) ���� ������ �л� ������ �������� ����!" << endl << endl;
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

		delete LinkedHead;
		exit(0);
	}

}

// 1. ���� �л��� �̸�, ��ȭ��ȣ�� ���� STU����ü�� �����ͷ� ��� Node�� �����ϰ� �� ��带 linked����Ʈ�� �߰� 
bool InsertNode(Node*& head, NodeElement data) {

	bool flag = false;

	// �Է��� �̸�, ��ȭ��ȣ�� NULL�� �ƴϸ�, �Է°��� ����
	if (data.name != NULL && data.phoneNumber != NULL) {

		// ���� linkedlist�� ���������� ���� ��带 ã������ Node �����ͺ��� tmp (head����� �ּҰ����� �ʱ�ȭ)
		Node* tmp = head;

		// head�� �پ��ִ� ��带 �ǹ��ϴ� tmp->link�� �������� NULL�� ���ö�����, tmp�� Node�ּҰ��� tmp->link�� ����
		while (tmp->link != NULL) {

			tmp = tmp->link;
		}

		// �߰����� STU ����ü(new Node �� �� ���� ����)�� ������ linkedlist ����
		Node* studentLinked = new Node;

		// ���� ���� Node�� �ּҰ��� ���� �������� link�� ����
		tmp->link = studentLinked;

		// ���� �߰��� �л��� �̸�, ��ȭ��ȣ�� Node�� ����� STU�� �߰� + �߰��� ����� ���� Node �ּҰ��� NULL
		studentLinked->value.name = data.name;
		studentLinked->value.phoneNumber = data.phoneNumber;
		studentLinked->link = NULL;

		flag = true;
	}

	return flag;
}

// 2. Ư�� �л��� ������ ��θ� �����ϴ� ���(�� �л������� �ִ� Node�� �޸� ����)
bool DeleteNode(Node*& head, int deleteNodenum) {

	bool flag = false;

	// 1��°�� ����� ��带 �����ϴ� ���
	if (deleteNodenum == 1) {

		// Node �����ͺ����� ���� head�� link�� 1���� ��� �ּ� ����
		Node* tmp = head->link;

		// head�� ����� Node�ּҸ� ���� 2��° ����� �ּҰ����� ���� (= ��������)
		head->link = head->link->link;

		// ���� 1���� ��� �ּҸ� ã�ư��� �� ����� �޸𸮸� ����
		delete tmp;

		flag = true;

	}
	else {

		Node* tmpForNext = head;
		Node* tmpForDelete = NULL;

		for (int i = 1; i <= deleteNodenum; i++) {

			tmpForNext = tmpForNext->link;
			
			// ������ ����� ��ġ ���� ��ġ�� ��忡 ������ ���?
			if (i == deleteNodenum - 1) {

				// ������ ����� �ּҸ� ���� tmpForDelete�� ��������� �ּҸ� ����(���� �� ����� link�� �Էµ� �ּҰ�)
				tmpForDelete = tmpForNext->link;

				// ������ ����� ���� ��尡 ������ ��尡 �ƴ϶��? (= ������ ��尡 ����Ʈ�� �߰��� ��ġ)
				if (tmpForNext->link->link != NULL) {

					// ���� �� ����� link���� ������� ���� ����� �ּҷ� ����
					tmpForNext->link = tmpForNext->link->link;
				}
				// ������ ����� ���� ��尡 ������ �����? (= ������ ��尡 ����Ʈ�� ���� ��ġ)
				else {

					// ������ ��� ��������� link�� NULL�� ����
					tmpForNext->link = NULL;
				}

			}
			// ������ ��� ��ġ�� �����ϴ� ���
			//  -> ��������� �ּӰ��� �� tmpForDelete�� �ּҸ� �̿��� �޸� ����
			else if (i == deleteNodenum) {

				delete tmpForDelete;
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

	Node* tmpForNext = head->link;
	Node* tmpForDelete = head;

	while (tmpForNext != NULL) {

		flag = true;

		tmpForDelete = tmpForNext;
		tmpForNext = tmpForNext->link;

		delete tmpForDelete;
	}

	head->link = NULL;

	return flag;

}