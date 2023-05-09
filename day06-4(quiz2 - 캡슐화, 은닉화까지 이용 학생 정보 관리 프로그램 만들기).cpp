//  #getter, setter�� class�����͸� ���� ������
//    1. ����Լ� get, set �������� get, set�� ���� ������� ���� �� ������ �ٺ������� ���� �����.. ������ ����� �ް��� �� ����..
//    2. class ��ü�� ��ȿ���� = ���������� ��ȿ�������� �������..(= ��ü�� ������ �����̱� ����)
//    3. (�߿�!) C++���� class �����Ϳ� new�����ڸ� ���� �����Ҵ��� ���� ����?
//        :  C++���� �����Ҵ��̶� ũ�Ⱑ �ʿ��Ҷ����� ���������� ������ �� �ִٴ� ������ �ǹ�������, �ٸ� �������δ� {}�� ������ ���� �ʰ� ���α׷����� �޸𸮸� �����ϱ� ������ �������� �ǹ���
//          (= C++���� new �����ڸ� ���� ������ü�μ� �����Ҵ��� �����Ѵٸ�, 2���� ������ �Ѿ� ���������� ������ü�� �ƴ϶� {}�� �Ѱ踦 �Ѿ� �ش� ��ü�� ������ ������ �����ϴ�!)
//             -> �����Ҵ��� �޸𸮿� �����ϱ� ���ؼ��� �� �ڷ����� �ּҰ��� �ʿ��� = C++���� new �����ڸ� �޴� �ڷ����� '�����ͺ���'�� ����
//    4. 3�� ������ ���ϸ�, main()���� ����� class�� ��ü�� ���ؼ��� �����Ҵ��̰� �׳� �����̰� ����� ����

// class�� getter, setter ������� �̿��� c++�� �����Ҵ�, ���� ������� 'linked list'�� ���� ������ ����� ���� �ڵ带 �ۼ��ض�
// 1. �л� ���� ���
// 2. �л� ���� ����
// 3. �л� ���� ��ü ����Ʈ ���
// 4. ��ü����
// 5. ����
// -> �޴������Ͽ� �����ϱ�

#include <iostream>
#include <iomanip>

using namespace std;

// �л� ������ ��� class
class student {

	// ��������� �̸�, ������ private�� �ܺο��� ���ٺҰ�
	private:
		char* name;
		char* phone;

	// �л����� class�� ��������� �����ϴ� ����Լ��� public
	public:

		// �л� class �ʱ�ȭ �Լ�
		//  -> �� ������� ���� NULL
		inline void init() {
			name = NULL;
			phone = NULL;
		}

		// �ش� �л� Ŭ������ char*�� �����Ҵ� �� ������� 2�� ���� ���������ϴ� �Լ�
		//  -> ��� 2�� ���� NULL�̸�, �����ϰ� �ʰ� ��ġ (= �����Ϳ� ��ϵ� �ּҰ��� NULL�ε� �� ������ �ǰ���?)
		inline void DeleteData() {

			if (name != NULL) {
				delete[] name;
			}

			if (phone != NULL) {
				delete[] phone;
			}
		}

		// char �����ͺ��� name�� �� �ּҰ� return�Լ�
		inline char* getName() {
			return name;
		}

		// char �����ͺ��� phone�� �� �ּҰ� return�Լ�
		inline char* getPhone() {
			return phone;
		}

		// char �����ͺ��� name�� �� �ּҰ��� parameter�� ���� �ɷ� �������ִ� boolean �Լ�
		inline bool setName(char* _name) {
			name = _name;
			return true;
		}

		// char �����ͺ��� phone�� �� �ּҰ��� parameter�� ���� �ɷ� �������ִ� boolean �Լ�
		inline bool setPhone(char* _phone) {
			phone = _phone;
			return true;
		}
};

// linkedList�� ������ �Ǵ� Node�� ���������� studentŬ������ �����ͺ����� ä��
//  -> �̰ɷ� student ��ü�� ���� �� �����Ҵ��� ��ȹ
typedef student* NodeElement;

// linkedList�� ������ �Ǵ� Node ������ ��� class
class Node {

	// ��������� �����(student Ŭ���� �����ͺ���), ���� Node��ü�� �ּҰ��� ��� Node Ŭ���� �����ͺ����� private�� �ܺο��� ���ٺҰ�
	private:
		NodeElement value;
		Node* link;

	// ��� Node class�� ��������� �����ϴ� ����Լ��� public
	public:

		// Node class �ʱ�ȭ �Լ�
		//  -> �� ������� ���� NULL
		void init() {
			value = NULL;
			link = NULL;
		}

		// �ش� Node Ŭ������ Node*�� �����Ҵ� �� ������� 2�� ���� ���������ϴ� �Լ�
		//  -> ��� 2�� ���� NULL�̸�, �����ϰ� �ʰ� ��ġ (= �����Ϳ� ��ϵ� �ּҰ��� NULL�ε� �� ������ �ǰ���?)
		void Delete() {

			if (value != NULL) {
				delete value;
			}

			if (link != NULL) {
				delete link;
			}
		}

		// Node Ŭ���� �����ͺ��� value�� �� �ּҰ� return�Լ�
		inline NodeElement getValue() {
			return value;
		}

		// Node Ŭ���� �����ͺ��� link�� �� �ּҰ� return�Լ�
		inline Node* getlink() {
			return link;
		}

		// Node Ŭ���� �����ͺ��� value�� �� �ּҰ��� parameter�� ���� �ɷ� �������ִ� �Լ�
		inline void setValue(NodeElement data) {
			value = data;
		}

		// Node Ŭ���� �����ͺ��� link�� �� �ּҰ��� parameter�� ���� �ɷ� �������ִ� �Լ�
		inline void setlink(Node* _link) {
			link = _link;
		}
};

// linkedList�� ������ �ּҸ� ��ȭ���ִ� ��� Node�� ��ġ���� ��� class
class SingleList {

	// ��������� 1���� Node��ü�� ��ġ�� �ּҰ��� ��� Node Ŭ���� �����ͺ����� head�� private�� �ܺο��� ���ٺҰ�
	private:
		Node* head;

	// ��� Node class�� ��������� �����ϴ� ����Լ��� public
	public:

		// (�߿�) ���� �ϴ� ������ �����ؾ� ��(head����� ��ġ�� NULL�̸� �ȵ�)
		void init() {
			head = new Node;
			head->init();
		}

		// �ش� Node Ŭ������ Node*�� �����Ҵ� �� ������� 2�� ���� ���������ϴ� �Լ�
		//  -> ����� head�� NULL�̸�, �����ϰ� �ʰ� ��ġ (= �����Ϳ� ��ϵ� �ּҰ��� NULL�ε� �� ������ �ǰ���?)
		void Delete() {

			if (head != NULL) {
				delete head;
				head = NULL;
			}
		}

		// student ��ü �����ͺ����� parameter�� ������, linkedList�� �� student ��ü�� ������ �ش��ϴ� ��� �߰��� �����ϸ� �����Ͽ� true ��� �Լ�
		bool InsertNode(NodeElement data);

		// ��µ� ����Ʈ�� ���� ������ int�� parameter�� ������, linkedList�� �� ������ student ��ü�� ������ �ش��ϴ� ��� �߰��� �����Ͽ� true ��� �Լ�
		bool DeleteNode(int deleteNodenum);

		// linkedList�� head���� ����ؼ�, ������ ����� student ��ü�� ������ ������ְ�, ��¿Ϸ�� �� �л����� ��� �Լ� 
		int PrintList();

		// linkedList�� ��� Node ���� �� student��ü �����ϱ�
		bool DeleteAll();

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

			// student ��ü �ν��Ͻ� ������ �����Ҵ��Ͽ� ���� ��, �� ��ġ�� student Ŭ���� �����Ϳ� ����
			//  -> ���� �Է��ϴ� �л�����(�̸�, ����)�� ���� ���α׷��� ���� ������ �����ϰ� ������ �������� �����Ҵ�
			student* eachStudent = new student;

			// �����Ҵ��� student�� �ν��Ͻ��� ��������� �̸�, ������ NULL������ �ʱ�ȭ
			eachStudent->init();

			// �̸�, ���� �����迭�� �Է�
			cout << " ->> " << setw(3) << i + 1 << "��°�� �Է��� �л��� '�̸�'�� '��ȭ��ȣ'�� �Է����ּ��� : ";
			cin >> inputName >> inputPhoneNumber;

			//------------------------------[Node�� ����� STU ����ü�� �Է��� �̸�, ���� �ű��]---------------------------

			// �̸��� ���ڿ� ���̸�ŭ char�� �����迭�� �޸𸮿� �Ҵ��ϰ�, �� �����ּҰ��� �����Ҵ�� student �ν��Ͻ� ��ġ�� setName()�� patameter�� ���� �� ������ ����
			//  -> �ش� student �ν��Ͻ��� ��������� char �������� name�� ���� �� �����Ҵ� char�����迭 �����ּҰ����� ����
			eachStudent->setName(new char[strlen(inputName) + 1]);

			// �����迭�� �Էµ� �̸� ���ڿ��� student �ν��Ͻ��� ��������� char �������� name�� ��ġ�� ���� ���������� 1�ھ� ����
			for (int j = 0; j <= strlen(inputName); j++) {
				eachStudent->getName()[j] = inputName[j];
			}

			// �̸��� ���ڿ� ���̸�ŭ char�� �����迭�� �޸𸮿� �Ҵ��ϰ�, �� �����ּҰ��� �����Ҵ�� student �ν��Ͻ� ��ġ�� setPhone()�� patameter�� ���� �� ������ ����
			//  -> �ش� student �ν��Ͻ��� ��������� char �������� phone�� ���� �� �����Ҵ� char�����迭 �����ּҰ����� ����
			eachStudent->setPhone(new char[strlen(inputPhoneNumber) + 1]);

			// �����迭�� �Էµ� �̸� ���ڿ��� student �ν��Ͻ��� ��������� char �������� phone�� ��ġ�� ���� ���������� 1�ھ� ����
			for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
				eachStudent->getPhone()[j] = inputPhoneNumber[j];
			}

			//--------------------------------------------------------------------------------------------------------------

			// �� �Լ��� parameter�� LinkedList�� ����� �ּҸ� ������ head(SingleList Ŭ������ �ν��Ͻ�)�� ����Լ� insertNode�� eachstudent( �����Ҵ��Ͽ� ������� ���� ���� student Ŭ������ �ν��Ͻ�)�� parameter�� �־� ���� 
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
//    -> 'student ��ü �����ͺ���'�� parameter�� ������, linkedList�� �� student ��ü�� ������ �ش��ϴ� ��� �߰��� �����ϸ� �����Ͽ� true ��� �Լ�
bool SingleList::InsertNode(NodeElement data) {

	bool flag = false;

	// �Է��� �̸�, ��ȭ��ȣ�� NULL�� �ƴϸ�, �Է°��� ����
	if (data->getName() != NULL && data->getPhone() != NULL) {

		// ���� linkedlist�� ���������� ���� ��带 ã������ Node �����ͺ��� tmp (�� SingleList ��ü�� ��������� Node Ŭ���� �����ͺ����� head(head����� �ּҰ�)�� �ʱ�ȭ)
		Node* tmp = head;

		// head�� �پ��ִ� 1��° ��带 �ǹ��ϴ� tmp->getlink()�� �������� NULL�� ���ö�����, tmp�� Node�ּҰ��� tmp->getlink()->getLink()�� ����
		while (tmp->getlink() != NULL) {

			tmp = tmp->getlink();
		}

		// LinkedList�� �߰����� Node ��ü�� �����Ҵ��ϰ�, Node��ü�� ��ġ�� �޸� ��ġ�� Node ��ü �����ͺ��� studentLinkedNode�� ����
		Node* studentLinkedNode = new Node;

		// �ش� Node��ü�� ����������� Null�� �ʱ�ȭ
		studentLinkedNode->init();

		// (���� ��� link�� ����) ���� ���� Node�� �ּҰ��� ���� ������Node�� ��ġ���� ������ Node��ü �����ͺ��� tmp�� �������Ͽ� ������ setlink()�� parameter�� ����
		//  -> �� ������ ��忡 ����� Node�� �ּҰ��� link ���� ������ Node��ü�� ��ġ�� �ּҰ����� ���� 
		tmp->setlink(studentLinkedNode);

		// (���ο� ������ ��忡 value���� ����) parameter�� ���� ���޵� �Էµ� �̸�, �����̰� ��ġ�� student ��ü�� �ּҰ�
		//  -> �ش� student ��ü�� �ּҰ��� �� ������ ���� ������ Node ��ü�� value������ ����(studentLinkedNode�� �������Ͽ� ������ setlink()�� parameter�� ����)
		studentLinkedNode->setValue(data);

		flag = true;
	}

	return flag;
}

// 2. Ư�� �л��� ������ ��θ� �����ϴ� ���(�� �л������� �ִ� Node�� �޸� ����)
//    -> ��µ� ����Ʈ�� ���� ������ int�� parameter�� ������, linkedList�� �� ������ student ��ü�� ������ �ش��ϴ� ��� �߰��� �����Ͽ� true ��� �Լ�
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
			//  -> ���� ��带 �̸� �����ϴ� ����
			//     : 1��° ��尡 ������ ����϶��� head�� �������� �ش� ��尪�� ���� �� �ְ� ���� �����ϰ� �ϱ� ���� (�������� 1������� ��� head->getlink() �̷������� ����ó�� ����)
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

		// ������ ������, ���� ���� ���� (������ 0�ǹ� = ������� �ּҰ�)
		tmpForCursor = tmpForCursor->getlink();
	}

	// ��������� �ּҰ��� �� tmpForDelete�� �ּҸ� �̿��� Node ��ü�� �޸� ����
	delete tmpForDelete;


	return flag;
}

// 3. ��ü �л����� ��� (�� ���� �л��� �����ϴ����� ��ȯ)
//    -> linkedList�� head���� ����ؼ�, ������ ����� student ��ü�� ������ ������ְ�, ��¿Ϸ�� �� �л����� ��� �Լ� 
int SingleList::PrintList() {

	// ���� ����Ʈ�� �л����� ���� ����
	int studentNum = 0;

	// head�� �������� linked ����Ʈ�� ��ȸ�ϸ� ����� �ּҰ��� ���Ź��� Node������ ����
	Node* tmp = head;

	// ��忡 ����� �ٸ� ����� �ּҰ��� link�� NULL�� ������ �༮���� ����� �ּҰ��� ���� ����
	while (tmp->getlink() != NULL) {

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
//    -> linkedList�� ��� Node ���� �� student��ü �����ϱ�
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