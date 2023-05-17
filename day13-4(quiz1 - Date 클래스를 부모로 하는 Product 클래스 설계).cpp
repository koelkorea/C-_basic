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

#include <string>
#include <iostream>
#include <cstdlib>
#include <malloc.h>
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
		string name;
		string manufacturer;
		int price;

	public:

		~Product() {};

		// ��ǰ Ŭ������ ������� �ʱ�ȭ�� ����ϴ� �Լ� (���⼭�� �����ڿ� ���� �θ������ ��� �� ȣ���� �������� �ʴ°ɷ�..)
		void init(string _name, string _manufacturer, int _price, int _year, int _month, int _day) {

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

		// get�Լ� : ��ǰ��, ������, ����
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
			cout << "�� ǰ �� : "  << name << endl;
			cout << "������ü : " << manufacturer << endl;
			cout << "��    �� : " << price << " $" << endl;
			cout << "�������� : " << getYear() << "�� " << getMonth() << "�� " << getDay() << "��" << endl;
			cout << endl;
		}
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

int main() {

	cout << "[��ǰ ��� ���α׷�]�� �۵�!" << endl << endl;

	int flag = 0;
	int input_try = 0;
	int product_num = 0;

	Product* arr[100];

	while (flag != 1) {

		int inputNum = 0;

		cout << "�Է��� ��ǰ�� ������? : " << endl;
		cin >> inputNum;
		while (cin.get() != '\n');

		Product* hotDeal_list = new Product[inputNum];

		for (int i = 0; i < inputNum; i++) {

			product_num++;

			cout << endl << "��ǰ " << product_num << "�� ����� �����մϴ�!" << endl;

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


			hotDeal_list[i].init(name, manufacturer, price, year, month, day);

			cout << " ->> (�˸�) ��ǰ����� �Ϸ�Ǿ����ϴ�. (��ǰ�� : " << hotDeal_list[i].getName() << ")" << endl;

		}

		arr[input_try] = hotDeal_list;

		cout << endl << " (����) ���Ƚ����ŭ ��� �Ϸ�\n          ->> ��� ����Ͻðڽ��ϱ�? (�����ϰ� �����ø� 1�� �����ּ���) : " << endl;
		cin >> flag;

		input_try++;
	}

	for (int i = 0; i < input_try; i++) {
		
		int each_num = (int) _msize(arr) ;

		for (int j = 0; j < each_num; j++) {

			arr[i][j].showInfo();
		}
	}

	return 0;
}