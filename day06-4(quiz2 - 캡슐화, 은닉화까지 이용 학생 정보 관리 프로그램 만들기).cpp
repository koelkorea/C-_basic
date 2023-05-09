// getter, setter ������� �̿��� c++�� �����Ҵ�, ���� ������� 'linked list'�� ���� ������ ����� ���� �ڵ带 �ۼ��ض�
// 1. �л� ���� ���
// 2. �л� ���� ����
// 3. �л� ���� ��ü ����Ʈ ���
// 4. ��ü����
// 5. ����
// -> �޴������Ͽ� �����ϱ�

#include <iostream>
#include <iomanip>

using namespace std;

class student {
	private:
		char* name;
		char* phone;

	public:
		inline void init() {
			name = NULL;
			phone = NULL;
		}

		inline void DeleteData() {

			if (name != NULL) {
				delete[] name;
			}

			if (phone != NULL) {
				delete[] phone;
			}
		}

		inline char* getName() {
			return name;
		}

		inline char* getPhone() {
			return phone;
		}

		inline bool setName(char* _name) {
			name = _name;
			return true;
		}

		inline bool setPhone(char* _phone) {
			phone = _phone;
			return true;
		}
};

typedef student* NodeElement;

class Node {
	private:
		NodeElement value;
		Node* link;

	public:
		void init() {
			value = NULL;
			link = NULL;
		}

		void Delete(){

			delete value;
			delete link;
		}

		inline NodeElement getValue() {
			return value;
		}

		inline Node* getlink() {
			return link;
		}

		inline void setValue(NodeElement data) {
			value = data;
		}

		inline void setlink(Node* _link) {
			link = _link;
		}
};

class SingleList {
	private:
		Node* head;

	public:
		void init() {
			head = NULL;
		}

		void Delete() {
			delete head;
			head = NULL;
		}

		bool InsertNode(NodeElement data);
		bool DeleteNode(int deleteNodenum);
		bool DeleteAll();
		int PrintList();
};

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

// �޴� �Է�ȭ�鿡�� �޴��� ������ ���Ǻη� �������
void PrintMenu(int& menu, SingleList& head) {

	// 1. �л����� �Է±��
	if (menu == 1) {

		// -----------------------------------------------------[�л� ���� STU ���� & �ۼ�]--------------------------------------------------------------------------
		// �л� �� �Է� �ޱ�
		int studentCnt;

		cout << endl << "[1��. �л��������� �Է±��]" << endl << endl << "���� �Է��� �л� ���� �Է����ֽʼ� : ";
		cinput(studentCnt);

		// �� �Է°� ũ�⿡ �ش��ϴ� ����ũ�⸦ ���� char�迭�� ����� ����, �ϴ� �Է°� ��ü�� �ޱ� ���� ���� �迭�� �ϳ� ����� �ش�
		char inputName[100];
		char inputPhoneNumber[100];

		// �Է��� �л� ����ŭ �̸�, ��ȭ��ȣ �Է¹ޱ�
		for (int i = 0; i < studentCnt; i++) {

			student* eachStudent = new student;
			
			eachStudent->init();

			cout << " ->> " << setw(3) << i + 1 << "��°�� �Է��� �л��� '�̸�'�� '��ȭ��ȣ'�� �Է����ּ��� : ";
			cin >> inputName >> inputPhoneNumber;

			//------------------------------[Node�� ����� STU ����ü�� �Է��� �̸�, ���� �ű��]---------------------------

			// �̸��� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
			eachStudent->setName(new char[strlen(inputName) + 1]);

			// �����迭�� �Էµ� �̸� ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
			for (int j = 0; j <= strlen(inputName); j++) {
				eachStudent->getName()[j] = inputName[j];

			}

			// ��ȭ��ȣ�� ���ڿ� ���̸�ŭ �����Ҵ� (NULL ���ڵ� �����ؾ�..)
			eachStudent->setPhone(new char[strlen(inputPhoneNumber) + 1]);

			// �����迭�� �Էµ� ��ȭ��ȣ ���ڿ��� ���� ���� ���ڿ��� 1�ھ� ����
			for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
				eachStudent->getPhone()[j] = inputPhoneNumber[j];
			}

			//--------------------------------------------------------------------------------------------------------------

			// �Է� �޼��忡 �Է��� �л� �ش� ������, Linked�� ������ head����� �����ּҰ��� ������ Node�����ͺ����� param���� ����
			//  -> ���� ���� ���ο����� �˸� �޶����� ��
			if (head.InsertNode(eachStudent) == true) {
				cout << "\t>>>> (�˸�) �л� " << i + 1 << "�� ������ �Է� �Ϸ�.." << endl << endl;
			}
			else {
				cout << "\t>>>> (�˸�) �л� " << i + 1 << "�� ������ �Է� ����!" << endl << endl;
			}

		}

	}
	// 2. Ư�� �л��� ���� �������
	else if (menu == 2) {

		// ����Ʈ�� �л� �� ����
		int deleteFlag = head.PrintList();

		// ����Ʈ�� �л��� 1�� �̻� ������ ��, �����л� ������� ����!
		if (deleteFlag != 0) {

			// ������ �л��� ���°�� ������ ���� ����
			int deleteNodenum = 0;

			cout << endl << "[2��. ���� �л����� �Է±��]" << endl;

			// �ּ��� 1���� ������ �л��� index �Է¹޴µ�, �� ���� 0���� ũ�鼭, deleteFlag�� ������ ���ų� Ŀ���� (= ���� ���� �л�index�� �Է¹������ ��)
			do {
				cout << endl << " ->> �� ��° �л��� ������ ����� �����Ű���? : ";
				cinput(deleteNodenum);

				if (deleteNodenum <= 0 && deleteNodenum > deleteFlag) {
					cout << endl << "\t>>>> (���) 0���� ũ��, �����ϴ� �л���ȣ�� ���� �Է����ּ���!" << endl;
				}

			} while (deleteNodenum <= 0 && deleteNodenum > deleteFlag);

			// ���� �޼��忡  Linked�� ������ head����� ���� �л��� ���°�� �ִ��� ���θ� param���� ����
			//  -> ���� ���� ���ο����� �˸� �޶����� ��
			if (head.DeleteNode(deleteNodenum) == true) {

				cout << "\t>>>> (�˸�) " << deleteNodenum << "��° �л� ���� ���� �Ϸ�!" << endl << endl;
			}
			else {
				cout << "\t>>>> (�˸�) " << deleteNodenum << "��° �л� ���� ���� ����!" << endl << endl;
			}
		}
		// ����Ʈ�� �л��� 0���̸�, ���� �Ұ� ����
		else {
			cout << "\t>>>> (�˸�) ���� ������ �л� ������ �������� ����!" << endl << endl;
		}
	}
	// 3. ��ü �л����� ��±��
	else if (menu == 3) {

		// ����Ʈ�� �л��� 1�� �̻� ������ ��, �������� ���
		if (head.PrintList() != 0) {

			cout << "\t>>>> (�˸�) �л� ���� ��¿Ϸ�!" << endl << endl;
		}
		else {
			cout << "\t>>>> (�˸�) �л� ������ �����ϴ�.." << endl << endl;
		}

	}
	// 4. ��ü �л����� �������
	else if (menu == 4) {

		// ���� ���� ���ο� ����, �������� ���
		if (head.DeleteAll() == true) {

			cout << "\t>>>> (�˸�) �л� ���� ��ü �����Ϸ�!" << endl << endl;
		}
		else {
			cout << "\t>>>> (�˸�) �л� ������ ���ų�, ��ü ���� ����!" << endl << endl;
		}

	}
	else if (menu == 5) {

		// ���� ���� ���������� LinkedList�� head�� �Ҵ�� �޸� ������ �������� 
		head.DeleteAll();
		head.Delete();

		cout << "\t>>>> (�˸�) �л����� ���α׷��� �����մϴ�..." << endl << endl;

		exit(0);
	}

}

int main() {

	// �л����� LinkedList�� ������ head ����
	//  : �Ҽ� STU����.. link�� 1��° ��尡 ������ �� ����ּ�.. ������ NULL
	SingleList LinkedHead;

	// LinkedList�� head�� link�� �ϴ� NULL �ʱ�ȭ.. (��ϵ� �л������� ����)
	LinkedHead.init();

	// �޴����� ��ȣ �޾��� ���� (�ʱⰪ 0)
	int menuNum = 0;

	while (1) {

		cout << "1. �л� ���� ���" << endl;
		cout << "2. �л� ���� ����" << endl;
		cout << "3. �л� ���� ��ü ����Ʈ ���" << endl;
		cout << "4. �л� ���� ��ü����" << endl;
		cout << "5. ���α׷� ����" << endl << endl;
		cout << "�޴���ȣ ���� :";

		cinput(menuNum);
		PrintMenu(menuNum, LinkedHead);

	}

	return 0;

}




// 1. ���� �л��� �̸�, ��ȭ��ȣ�� ���� student Ŭ������ �����ͷ� ��� Node�� �����ϰ� �� ��带 linked����Ʈ�� �߰� 
bool SingleList::InsertNode(NodeElement data) {

	bool flag = false;

	// �Է��� �̸�, ��ȭ��ȣ�� NULL�� �ƴϸ�, �Է°��� ����
	if (data->getName() != NULL && data->getPhone() != NULL) {

		// ���� linkedlist�� ���������� ���� ��带 ã������ Node �����ͺ��� tmp (head����� �ּҰ����� �ʱ�ȭ)
		Node* tmp = head;
		
		// head�� �پ��ִ� ��带 �ǹ��ϴ� tmp->link�� �������� NULL�� ���ö�����, tmp�� Node�ּҰ��� tmp->link�� ����
		while (tmp->getlink() != NULL) {

			tmp = tmp->getlink();
		}

		// �߰����� STU ����ü(new Node �� �� ���� ����)�� ������ linkedlist ����
		Node* studentLinkedNode = new Node;
		studentLinkedNode->init();

		// ���� ���� Node�� �ּҰ��� ���� �������� link�� ����
		tmp->setlink(studentLinkedNode);

		// ���� �߰��� �л��� �̸�, ��ȭ��ȣ�� Node�� ����� STU�� �߰� + �߰��� ����� ���� Node �ּҰ��� NULL
		studentLinkedNode->setValue(data);

		flag = true;
	}

	return flag;
}

// 2. Ư�� �л��� ������ ��θ� �����ϴ� ���(�� �л������� �ִ� Node�� �޸� ����)
bool SingleList::DeleteNode(int deleteNodenum) {

	bool flag = true;

	// ����ڰ� 0�� �Է�������, ������ ���ϵ��� ��ġ (���� ���ʿ� 0 < deleteNodenum < print�� ���� return�� �̵��� ��ġ)
	if (deleteNodenum == 0) {

		// ����� �Բ� false�Է�
		cout << "\t>>>> (���!) 0��° �����ʹ� �������� �ʴ� �������̹Ƿ� ������ �� �����ϴ�." << endl;
		return flag = false;
	}

	// ����� �ּҰ��� ���� Ŀ���μ� linkedList�� ���������
	Node* tmpForCursor = head;

	// ���� ����� �ּҰ��� ������ linkedList�� ��������� (NULL�� �ʱ�ȭ ���ѳ���.. tmpForCursor�� ���� ���� ���ϴ� ������.. �� �ʱⰪ�� head�� �������� ����� ���� head�� �������� ����)
	Node* tmpForDelete = NULL;

	// linkedList ��� = 0, deleteNodenum�� �ش��ϴ� Ƚ����ŭ link�� Ÿ��, tmpForDelete���� ���� ����
	for (int i = 0; i < deleteNodenum; i++) {

		// ������ ����� ��ġ ���� ��ġ�� ��忡 ������ ���?
		if (i == deleteNodenum - 1) {

			// ������ ����� �ּҸ� ���� tmpForDelete�� ��������� �ּҸ� ����(���� �� ����� link�� �Էµ� �ּҰ�)
			tmpForDelete = tmpForCursor->getlink();

			// ������ ����� ���� ��尡 ������ ��尡 �ƴ϶��? (= ������ ��尡 ����Ʈ�� �߰��� ��ġ)
			if (tmpForCursor->getlink()->getlink() != NULL) {

				// ���� �� ����� link���� ������� ���� ����� �ּҷ� ����
				tmpForCursor->setlink(tmpForCursor->getlink()->getlink());
			}
			// ������ ����� ���� ��尡 ������ �����? (= ������ ��尡 ����Ʈ�� ���� ��ġ)
			else {

				// ������ ��� ��������� link�� NULL�� ����
				tmpForCursor->setlink(NULL);
			}

		}

		// ��� = 0�̰�, ������ ������, ���� ���� ����
		tmpForCursor = tmpForCursor->getlink();
	}

	// ��������� �ּӰ��� �� tmpForDelete�� �ּҸ� �̿��� �޸� ����
	delete tmpForDelete;


	return flag;
}

// 3. ��ü �л����� ��� (�� ���� �л��� �����ϴ����� ��ȯ)
int SingleList::PrintList() {

	// ���� ����Ʈ�� �л����� ���� ����
	int studentNum = 0;

	// head�� �������� linked ����Ʈ�� ��ȸ�ϸ� ����� �ּҰ��� ���Ź��� Node������ ����
	Node* tmp = head;

	// ��忡 ����� �ٸ� ����� �ּҰ��� link�� NULL�� ������ �༮���� ����� �ּҰ��� ���� ����
	while (tmp != NULL) {

		tmp = tmp->getlink();

		// �л����� ������ ++�����ڷ�..
		cout << endl << "�л� " << setw(3) << ++studentNum << "�� ����" << endl;
		cout << " ->> �̸� : " << tmp->getValue()->getName() << endl;
		cout << " ->> ��ȭ��ȣ : " << setw(3) << tmp->getValue()->getPhone() << endl;
	}

	cout << endl;

	// ����� �л������� �ִ��� ����
	return studentNum;
}

// 4. ��ü �л����� ����
bool SingleList::DeleteAll() {

	bool flag = false;

	// head�� ����Ű�� link�� �ּҰ��� �ٸ� ����� �ּҰ��� ����
	Node* tmpForNext = head->getlink();
	Node* tmpForDelete = NULL;

	// ���ʿ� 1��° ��尡 �������� �ʴ´ٸ�, �޼��带 ���������� �ʰ�, link�� NULL�� ����忡 �����ϸ� �ߴ�
	//  -> 1�� �̻��� �л����� ��尡 �����Ѵٸ�? ��ȸ�ϸ鼭 ����
	while (tmpForNext != NULL) {

		// ���� ���������� true��
		flag = true;

		// ���� ��带 ������ ����� �ּҸ� ���� �����ͺ����� ����
		tmpForDelete = tmpForNext;

		// Ŀ������ link�� ����� ���� ����� �ּҰ��� ����
		tmpForNext = tmpForNext->getlink();

		// ������带 �޸𸮿� �Ҵ�� �������� �����켭 ����
		delete tmpForDelete;
	}

	// �� ����������, head�� link ����� null��..
	head->init();

	return flag;

}