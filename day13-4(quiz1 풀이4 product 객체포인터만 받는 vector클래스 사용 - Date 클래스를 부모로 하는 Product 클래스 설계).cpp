// quiz1 : ����� �̿��� Ŭ������ �����϶�
//  -> ��¥�� ���õ� ������ �����ϴ� Date Ŭ������ ��������� �Լ� ����Ʈ�� �ۼ��ϰ�, �̸� �̿��� �ڽ�Ŭ������ Product Ŭ������ ������.. ������ ������ ����

// �� DateŬ���� ������
//    1. private �������
//      - ��
//      - ��
//      - ��
//    
//    2. public ��� �Լ�
//      - ������ - �μ��� ���� �⺻ �����ڸ� �̿��Ѵ�.Date()
//      - ��, ��, �� �����Լ� set
//      - ��, ��, �� �����Լ� get
// 
// �� ProductŬ���� ������ : DateŬ���� ���
//    1. private �������
//      - ��ǰ��
//      - ������
//      - ����
// 
//    2. public ��� �Լ�
//      - ������ - �μ��� ���� �⺻ �����ڸ� �̿��Ѵ�.
//      - SetProduct - ��ǰ��, ������, ����, ��, ��, �� �ʱ�ȭ
//      - ��ǰ��, ������, ����, �������� �����Լ� set
//      - ��ǰ��, ������, ���� �����Լ� get
//      - ��ǰ���� ��� �Լ�

// Ǯ��4 - product ��ü�����͸� �޴� vector ��� (������ ���x)
//  -> ���̰����� �����迭 vector Ŭ������ ���

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
class Date {

private:
	// ��, ��, ��
	int year, month, day;

public:
	// set�Լ� : ��, ��, �� �����Լ�
	void setYear(int _year) {
		year = _year;
	}

	void setMonth(int _month) {
		month = _month;
	}

	void setDay(int _day) {
		day = _day;
	}

	// get�Լ� : ��, ��, �� �����Լ�
	int getYear() {
		return year;
	}

	int getMonth() {
		return month;
	}

	int getDay() {
		return day;
	}
};

class Product : public Date {

private:
	// ���� ��ϵ� ��ǰ��, �Ϸù�ȣ(���� ��ϵ� ��ǰ���� ���� ����), ��ǰ��, ������, ����
	static int currentNum;
	int num;
	string name;
	string manufacturer;
	int price;

public:

	~Product() {};

	// ��ǰ Ŭ������ ������� �ʱ�ȭ�� ����ϴ� �Լ� (���⼭�� �����ڿ� ���� �θ������ ��� �� ȣ���� �������� �ʴ°ɷ�..)
	void init(string _name, string _manufacturer, int _price, int _year, int _month, int _day) {

		num = ++currentNum;
		name = _name;
		manufacturer = _manufacturer;
		price = _price;

		setDate(_year, _month, _day);
	}

	// set�Լ� : ��ǰ��, ������, ����, ��������
	void setName(string _name) {
		name = _name;
	}

	void setManufacturer(string _manufacturer) {
		manufacturer = _manufacturer;
	}

	void setPrice(int _price) {
		price = _price;
	}

	// �θ�Ŭ���� �ʱ�ȭ ���� �����ڷ� ó�� �����ϳ�.. (���⼭�� �����ڿ� ���� �θ������ ��� �� ȣ���� �������� �ʴ°ɷ�..)
	void setDate(int _year, int _month, int _day) {

		setYear(_year);
		setMonth(_month);
		setDay(_day);
	}

	// get�Լ� : �Ϸù�ȣ(static), ��ǰ��, ������, ����
	static int getCurrentNum() {
		return currentNum;
	}

	string getName() {
		return name;
	}

	string getManufacturer() {
		return manufacturer;
	}

	int getPrice() {
		return price;
	}

	// ��ǰ ���� ���
	void showInfo() {
		cout << endl;
		cout << "�Ϸù�ȣ : " << num << endl;
		cout << "�� ǰ �� : " << name << endl;
		cout << "������ü : " << manufacturer << endl;
		cout << "��    �� : $ " << price << endl;
		cout << "�������� : " << getYear() << "�� " << getMonth() << "�� " << getDay() << "��" << endl;
		cout << endl;
	}
};

// ���� ��ǰ��ȣ �ο��� �ʱ�ȭ
int Product::currentNum = 0;

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

	cout << "[��ǰ ��� ���α׷�]�� �۵�!" << endl << endl;

	// ���Ῡ�� flag
	int flag = 0;

	// product ��ü�����͸��� �޴� �������� �����迭 vector ����
	//  -> (�߿�) ũ��� �������� �ʴ°�, �׷��� �ϸ� stack�� push_back ����ÿ� ������ ũ�� + 1 ��ġ�� �� �Է�)
	vector<Product*> items;

	while (flag != 1) {

		// �̹� loop�� �Է��� ��ǰ�� ��
		int inputNum = 0;

		cout << "�Է��� ��ǰ�� ������? : " << endl;
		cin >> inputNum;
		while (cin.get() != '\n');

		for (int i = 0; i < inputNum; i++) {

			cout << endl << "�Ϸù�ȣ " << Product::getCurrentNum() + 1 << "�� ����� �����մϴ�!" << endl;

			Product* newItem = new Product;

			string name = "";
			string manufacturer = "";
			int price = 0;
			int year = 0;
			int month = 0;
			int day = 0;

			cout << " ->> �� ǰ �� : ";
			cin >> name;
			while (cin.get() != '\n');

			cout << " ->> ������ü : ";
			cin >> manufacturer;
			while (cin.get() != '\n');

			cout << " ->> ��   �� : ";
			cin >> price;
			while (cin.get() != '\n');

			cout << " ->> �������� (YYYY MM DD ��������.. 0�� ����) : ";
			cin >> year >> month >> day;
			while (cin.get() != '\n');

			newItem->init(name, manufacturer, price, year, month, day);

			// vector�� ���� �߰��� class��ü�� �̸� ���� ����ȭ �� = ���� �߰��� {}�� ���ֹ��� �ʰ� ���� ����� �����
			//  -> ���� ���⼭ �޴� ��ü�����ʹ� �� ��ġ�� new�� ���� ��ü ���� �����Ҵ��� �Ϸ�� ���¶� �ƹ����� ����� ����.. ������ ���ʸ����� Ŭ�����θ� ���� �������� ����ȴٴ��� �˾Ƶ���
			items.push_back(newItem);

			cout << " ->> (�˸�) ��ǰ����� �Ϸ�Ǿ����ϴ�. (��ǰ�� : " << newItem->getName() << ")" << endl;

		}

		cout << endl << " (����) ���Ƚ����ŭ ��� �Ϸ�\n          ->> ��� ����Ͻðڽ��ϱ�? (�����ϰ� �����ø� 1�� �����ּ���) : " << endl;
		cin >> flag;
	}

	// ���� �� ����� ��ǰ���� ��ȸ (staic ������ ��ü�迭 index ��ȸ)
	for (int i = 0; i < Product::getCurrentNum(); i++) {
		items[i]->showInfo();
	}

	return 0;
}