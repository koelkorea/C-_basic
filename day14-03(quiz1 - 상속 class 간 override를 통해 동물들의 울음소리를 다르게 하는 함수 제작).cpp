// quiz2 : 각각의 동물 울음소리와 걸음을 animal을 선조로 해서 override해서 표현해라

#include <iostream>
#include <iomanip>

using namespace std;

class Animal {
	public:
		void speak() {
			cout << "    >> 조물주 say : ..... " << endl;
		};

		void walk() {
			cout << "    >> 조물주 say : 4발로 걷는게 동물의 기본.." << endl;
		};
};

class Dog : public Animal {
	public:
		void speak() {
			cout << "    >> [override] 왈왈왈~~ 컹컹컹!!!" << endl;
		};
};

class Cat : public Animal {
	public:
		void speak() {
			cout << "    >> [override] 나는 나옹이다옹~" << endl;
		};
};

class Pig : public Animal {
	public:
		void speak() {
			cout << "    >> [override] 돼지는 꿀꿀꿀꿀 ~ " << endl;
		};
};

class Duck : public Animal {
	public:
		void speak() {
			cout << "    >> [override] 오리, 꽥꽥~ 오리, 꽥꽥~ " << endl;
		};
		void walk() {
			cout << "    >> [override] 2발로 걷는 경우가 바로 우리 조류지" << endl;
		};
};

class Human : public Animal {
public:
	void speak() {
		cout << "    >> [override] 안녕하세요~ Hello ~ Bonjour ~ 곤니치와~ .... " << endl;
	};
	void walk() {
		cout << "    >> [override] 2발로 걷는 경우가 바로 우리 영장류지" << endl;
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