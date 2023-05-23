// quiz2 - �߻�Ŭ����, �����Լ�, ����� Ȱ���� �ް�Ŀ�� Ű����ũ ¥����
//  1. �޴����� ������
//  2. ���� ������, �ֹ������� �� �հ�ݾ� ��� 
//  3. �� �� ������(�̸�, ��ȭ��ȣ) �Է� ������
//  4. �ֹ���ȣ �ο�

//  ��ӱ���
//   -> �� <- �޴� <- Ŀ��, ������, ���̵� ��

// Ǯ��3 - list �����̳� Ŭ���� ��ü�� Ǯ��
#include <string>
#include <iostream>
#include <list>

using namespace std;

class menu;

class Customer {

private:
	// �ֹ���ȣ �Ѹ��� �뵵
	static int nextOrderNum;

	string name;
	string cellphone;

	int orderNum;
	list<menu*>* orderlist;

public:
	Customer(string _name, string _cellphone, list<menu*>* _orderlist) {
		name = _name;
		cellphone = _cellphone;
		orderNum = ++nextOrderNum;
		orderlist = _orderlist;
	}

	~Customer() {
		delete[] orderlist;
	}

	string getName() {
		return name;
	}

	string getCellphone() {
		return cellphone;
	}

	int getOrderNum() {
		return orderNum;
	}

	list<menu*>* getOrderlist() {
		return orderlist;
	}

	void showAllMenu();
	int howMuch();
};

// static �ʱ�ȭ
int Customer::nextOrderNum = 0;

// ��� �޴��� ����
class menu {

private:
	string menuName;
	int price;

public:
	menu() {
		menuName = "NULL";
		price = 0;
	}

	menu(string _menuName, int _price) {
		menuName = _menuName;
		price = _price;
	}

	//virtual ~menu();

	string getMenuName() {
		return menuName;
	}

	int getprice() {
		return price;
	}

	void setMenuName(string _menuName) {
		menuName = _menuName;
	}

	void setprice(int _price) {
		price = _price;
	}

	// �޴��� �ش�Ǵ� �༮�� ���� menulist ������ü�迭�� �߰�
	virtual void pickMenu(Customer* customer) {		}

	// �޴����� �����ֱ�
	virtual void show() {
		cout << "�޴� : " << menuName << endl;
		cout << "���� : " << price << endl;
	}
};

void Customer::showAllMenu() {

	if (orderlist->size() == 0) {
		cout << " ->> (���!) �ֹ�����Ʈ�� �ö�°� �����ϴ�! �޴��� �߰����ּ���!" << endl;
	}

	for (int i = 0; i < orderlist->size(); i++) {

		// (*orderlist->begin())->show();
		orderlist->front()->show();
		orderlist->push_back(orderlist->front());
		orderlist->pop_front();

		cout << endl;
	}

}

int Customer::howMuch() {

	int result = 0;

	for (int i = 0; i < orderlist->size(); i++) {
		// result += (*orderlist->begin())->getprice();
		result += orderlist->front()->getprice();
		orderlist->push_back(orderlist->front());
		orderlist->pop_front();
	}

	return result;
}

// Ŀ�� Ŭ���� = menu �ڽ�class 
class coffie : public menu {

private:
	string coffieKindName;

public:
	coffie(string _menuName, int _price, string _coffieKindName) : menu(_menuName, _price) {
		coffieKindName = _coffieKindName;
	}

	string getCoffieKindName() {
		return coffieKindName;
	}

	void setCoffieKindName(string _coffieKindName) {
		coffieKindName = _coffieKindName;
	}

	// �޴��� �ش�Ǵ� �༮�� ���� menulist ������ü�迭�� �߰�
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> " << getMenuName() << "��(��) �޴��� �߰��Ǿ����ϴ�." << endl << endl;
	}

	virtual void show() {
		cout << "��    �� : " << getMenuName() << endl;
		cout << "��    �� : " << getprice() << endl;
		cout << "�� �� �� : " << coffieKindName << endl;
	}
};

// �꽺, ������, ���̵� Ŭ���� = menu �ڽ�class 
class juice_smoothy_ade : public menu {

private:
	string fruit;

public:
	juice_smoothy_ade(string _menuName, int _price, string _fruit) : menu(_menuName, _price) {
		fruit = _fruit;
	}

	string getFruit() {
		return fruit;
	}

	void setFruit(string _fruit) {
		fruit = _fruit;
	}

	// �޴��� �ش�Ǵ� �༮�� ���� menulist ������ü�迭�� �߰�
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> " << getMenuName() << "��(��) �޴��� �߰��Ǿ����ϴ�." << endl << endl;
	}

	virtual void show() {
		cout << "��    �� : " << getMenuName() << endl;
		cout << "��    �� : " << getprice() << endl;
		cout << "�� �� �� : " << fruit << endl;
	}
};

// ������ Ŭ���� = menu �ڽ�class 
class frappe : public menu {

private:
	string ingredient;

public:
	frappe(string _menuName, int _price, string _ingredient) : menu(_menuName, _price) {
		ingredient = _ingredient;
	}

	string getIngredient() {
		return ingredient;
	}

	void setIngredient(string _ingredient) {
		ingredient = _ingredient;
	}

	// �޴��� �ش�Ǵ� �༮�� ���� menulist ������ü�迭�� �߰�
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> " << getMenuName() << "��(��) �޴��� �߰��Ǿ����ϴ�." << endl << endl;
	}

	virtual void show() {
		cout << "��    �� : " << getMenuName() << endl;
		cout << "��    �� : " << getprice() << endl;
		cout << "��    �� : " << ingredient << endl;
	}
};


// �� Ŭ���� = menu �ڽ�class 
class tea : public menu {

private:
	string teaKind;

public:
	tea(string _menuName, int _price, string _teaKind) : menu(_menuName, _price) {
		teaKind = _teaKind;
	}

	string getTeaKind() {
		return teaKind;
	}

	void setTeaKind(string _teaKind) {
		teaKind = _teaKind;
	}

	// �޴��� �ش�Ǵ� �༮�� ���� menulist ������ü�迭�� �߰�
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> " << getMenuName() << "��(��) �޴��� �߰��Ǿ����ϴ�." << endl << endl;
	}

	virtual void show() {
		cout << "��    �� : " << getMenuName() << endl;
		cout << "��    �� : " << getprice() << endl;
		cout << "�� �� �� : " << teaKind << endl;
	}
};

// ����Ʈ Ŭ���� = menu �ڽ�class 
class desert : public menu {

private:
	string type;

public:
	desert(string _menuName, int _price, string _type) : menu(_menuName, _price) {
		type = _type;
	}

	string getType() {
		return type;
	}

	void setType(string _type) {
		type = _type;
	}

	// �޴��� �ش�Ǵ� �༮�� ���� menulist ������ü�迭�� �߰�
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> (�˸�) " << getMenuName() << "��(��) �޴��� �߰��Ǿ����ϴ�!!!" << endl << endl;
	}

	virtual void show() {
		cout << "��    �� : " << getMenuName() << endl;
		cout << "��    �� : " << getprice() << endl;
		cout << "��    �� : " << type << endl;
	}
};

menu* coffieMenu() {

	cout << "[Ŀ�� �޴� �϶�]" << endl;
	cout << "1. ����������" << endl;
	cout << "2. �Ƹ޸�ī��" << endl;
	cout << "3. �ٴҶ��" << endl;
	cout << "4. ���ݸ���" << endl;
	cout << "5. ī��� �����ƶ�" << endl;
	cout << "6. �ݵ���" << endl;
	cout << "99. ��������..." << endl;
	cout << " ->> �޴��� �Է����ּ��� : ";

	int menuNum = 0;
	cin >> menuNum;

	menu* tmp = NULL;

	switch (menuNum) {
	case 1:
		tmp = new coffie("����������", 1500, "��Ƽ���Ǿ�");
		break;
	case 2:
		tmp = new coffie("�Ƹ޸�ī��", 1500, "�ε��׽þ�");
		break;
	case 3:
		tmp = new coffie("�ٴҶ��", 2500, "����");
		break;
	case 4:
		tmp = new coffie("���ݸ���", 2500, "��Ű");
		break;
	case 5:
		tmp = new coffie("ī��� �����ƶ�", 2500, "�����");
		break;
	case 6:
		tmp = new coffie("�ݵ���", 2500, "����");
		break;
	default:
		system("cls");
		break;
	}

	return tmp;
}


menu* smoothlyAdeJuiceMenu() {

	cout << "[������ & ������ & �ֽ� �϶�]" << endl;
	cout << "1. �����꽺" << endl;
	cout << "2. �����̵�" << endl;
	cout << "3. �ڸ��꽺" << endl;
	cout << "4. �ڸ����̵�" << endl;
	cout << "5. ���� ������" << endl;
	cout << "6. ��Ű ������" << endl;
	cout << "99. ��������..." << endl;
	cout << " ->> �޴��� �Է����ּ��� : ";

	int menuNum = 0;
	cin >> menuNum;

	menu* tmp = NULL;

	switch (menuNum) {
	case 1:
		tmp = new juice_smoothy_ade("�����꽺", 2000, "����");
		break;
	case 2:
		tmp = new juice_smoothy_ade("�����̵�", 2500, "����");
		break;
	case 3:
		tmp = new juice_smoothy_ade("�ڸ��꽺", 2000, "�ڸ�");
		break;
	case 4:
		tmp = new juice_smoothy_ade("�ڸ����̵�", 2500, "�ڸ�");
		break;
	case 5:
		tmp = new juice_smoothy_ade("���� ������", 3500, "����");
		break;
	case 6:
		tmp = new juice_smoothy_ade("��Ű ������", 3500, "��Ű");
		break;
	default:
		system("cls");
		break;
	}

	return tmp;
}

menu* teaFlaffeMenu() {

	cout << "[������ & �� �϶�]" << endl;
	cout << "1. ���� ������" << endl;
	cout << "2. ��Ű ������" << endl;
	cout << "3. ���� ��� ������" << endl;
	cout << "4. ��׷���" << endl;
	cout << "5. ����" << endl;
	cout << "6. ĳ����" << endl;
	cout << "99. ��������..." << endl;
	cout << " ->> �޴��� �Է����ּ��� : ";

	int menuNum = 0;
	cin >> menuNum;

	menu* tmp = NULL;

	switch (menuNum) {
	case 1:
		tmp = new frappe("���� ������", 3000, "����");
		break;
	case 2:
		tmp = new frappe("��Ű ������", 3000, "��Ű");
		break;
	case 3:
		tmp = new frappe("���� ��� ������", 3000, "����, ��Ű");
		break;
	case 4:
		tmp = new tea("��׷���", 1000, "��׷���");
		break;
	case 5:
		tmp = new tea("����", 1000, "����");
		break;
	case 6:
		tmp = new tea("ĳ����", 1000, "ĳ����");
		break;
	default:
		system("cls");
		break;
	}

	return tmp;
}

menu* desertMenu() {

	cout << "[����Ʈ �϶�]" << endl;
	cout << "1. ��Ű" << endl;
	cout << "2. ũ����" << endl;
	cout << "3. ����ũ" << endl;
	cout << "4. �ֵ���" << endl;
	cout << "5. ũ�ν�����" << endl;
	cout << "99. ��������..." << endl;
	cout << " ->> �޴��� �Է����ּ��� : ";

	int menuNum = 0;
	cin >> menuNum;

	menu* tmp = NULL;

	switch (menuNum) {
	case 1:
		tmp = new frappe("��Ű", 1000, "��Ű");
		break;
	case 2:
		tmp = new frappe("ũ����", 2000, "ũ����");
		break;
	case 3:
		tmp = new frappe("����ũ", 5000, "����ũ");
		break;
	case 4:
		tmp = new tea("�ֵ���", 4500, "�ֵ���");
		break;
	case 5:
		tmp = new tea("ũ�ν�����", 4000, "ũ�ν�����");
		break;
	default:
		system("cls");
		break;
	}

	return tmp;
}


int main() {

	list<menu*> orderlist;
	list<menu*>* orderlistPoint = &orderlist;

	Customer* customer = new Customer("�̴ϼ�", "010-2222-1111", orderlistPoint);

	while (1) {

		cout << "[�ް�Ŀ�� Kiosk]" << endl;
		cout << "1. Ŀ��" << endl;
		cout << "2. ������ & ���̵� & �ֽ�" << endl;
		cout << "3. ������ & ��" << endl;
		cout << "4. ����Ʈ" << endl;
		cout << "5. ����� �� �ݾ�" << endl;
		cout << "6. ����" << endl;
		cout << " ->> �޴��� �Է����ּ��� : ";

		int flag = 0;
		cin >> flag;

		cout << endl;

		if (flag == 1) {
			menu* tmp = coffieMenu();

			if (tmp != NULL) {
				tmp->pickMenu(customer);
			}
		}
		else if (flag == 2) {
			menu* tmp = smoothlyAdeJuiceMenu();

			if (tmp != NULL) {
				tmp->pickMenu(customer);
			}
		}
		else if (flag == 3) {
			menu* tmp = teaFlaffeMenu();

			if (tmp != NULL) {
				tmp->pickMenu(customer);
			}
		}
		else if (flag == 4) {
			menu* tmp = desertMenu();

			if (tmp != NULL) {
				tmp->pickMenu(customer);
			}
		}
		else if (flag == 5) {

			cout << "-------------------------------------------------------------------" << endl;
			cout << "[�ֹ���ȣ " << customer->getOrderNum() << "��]" << endl;
			cout << "�� �� �� : " << customer->getName() << " ����" << endl;
			cout << "��ȭ��ȣ : " << customer->getCellphone() << endl << endl;
			customer->showAllMenu();
			cout << " ->> �ֹ� �� �ݾ� : " << customer->howMuch() << "��" << endl << endl;
		}
		else if (flag == 6) {

			cout << "Ű����ũ�� �����մϴ�!~";
			exit(0);
		}

	}


}