// quiz2 - �߻�Ŭ����, �����Լ�, ����� Ȱ���� �ް�Ŀ�� Ű����ũ ¥����
//  1. �޴����� ������
//  2. ���� ������, �ֹ������� �� �հ�ݾ� ��� 
//  3. �� �� ������(�̸�, ��ȭ��ȣ) �Է� ������
//  4. �ֹ���ȣ �ο�

//  ��ӱ���
//   -> �� <- �޴� <- Ŀ��, ������, ���̵� ��

#include <string>
using namespace std;

class Customer {

	private:
		string name;
		string cellphone;

		int pickingNum;
		menu orderlist[];

	public:
		void pickMenu(menu _menu) {

		}
};

class menu {

	private:
		string menuName;
		int price;

	public:
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
};

class coffie : public menu {

	private:
		string coffieKindName;

	public:
		string getCoffieKindName() {
			return coffieKindName;
		}

		void setCoffieKindName(string _coffieKindName) {
			coffieKindName = _coffieKindName;
		}
};

class juice_smoothy_ade : public menu {

	private:
		string fruit;
};

class tea : public menu {

	private:
		string teaName;
};

class desert : public menu {

	private:
		string type;
};