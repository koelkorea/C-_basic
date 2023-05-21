// quiz2 : ������ ���� �����Ҹ��� ������ animal�� ������ �ؼ� override�ؼ� ǥ���ض�

#include <iostream>
#include <iomanip>

using namespace std;

class Animal {
	public:
		void speak() {
			cout << "    >> ������ say : ..... " << endl;
		};

		void walk() {
			cout << "    >> ������ say : 4�߷� �ȴ°� ������ �⺻.." << endl;
		};
};

class Dog : public Animal {
	public:
		void speak() {
			cout << "    >> [override] �пп�~~ ������!!!" << endl;
		};
};

class Cat : public Animal {
	public:
		void speak() {
			cout << "    >> [override] ���� �����̴ٿ�~" << endl;
		};
};

class Pig : public Animal {
	public:
		void speak() {
			cout << "    >> [override] ������ �ܲܲܲ� ~ " << endl;
		};
};

class Duck : public Animal {
	public:
		void speak() {
			cout << "    >> [override] ����, �в�~ ����, �в�~ " << endl;
		};
		void walk() {
			cout << "    >> [override] 2�߷� �ȴ� ��찡 �ٷ� �츮 ������" << endl;
		};
};

class Human : public Animal {
public:
	void speak() {
		cout << "    >> [override] �ȳ��ϼ���~ Hello ~ Bonjour ~ ���ġ��~ .... " << endl;
	};
	void walk() {
		cout << "    >> [override] 2�߷� �ȴ� ��찡 �ٷ� �츮 �������" << endl;
	};
};

int main() {

	int flag;

	while (1) {

		cout << "1. dog  2. cat  3. pig   4. duck   5. human   0. exit" << endl;
		cout << " ->> Please, choice yours ~ : ";
		cin >> flag;

		switch (flag) {

		case 1:
		{
			Dog* any = new Dog();
			any->speak();
			any->walk();
			delete any;
			break;
		}
		case 2:
		{
			Cat* any = new Cat();
			any->speak();
			any->walk();
			delete any;
			break;
		}
		case 3:
		{
			Pig* any = new Pig();
			any->speak();
			any->walk();
			delete any;
			break;
		}
		case 4:
		{
			Duck* any = new Duck();
			any->speak();
			any->walk();
			delete any;
			break;
		}
		case 5:
		{
			Human* any = new Human();
			any->speak();
			any->walk();
			delete any;
			break;
		}
		default:
			exit(0);
			break;
		}

		cout << endl;
	}

	return 0;
}