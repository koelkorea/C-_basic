// 3. �����Լ� (virtual function)

//   - ���������Լ� (pure virtual function)
//     : �ڽ� class���� override�� �Լ��� �θ� class ��ü�����Ͱ� ���� �� ȣ���ϱ� ���� �������� �����, ����θ� �ְ� ���Ǻΰ� ���� �����Լ�(= virtual function)
//        -> (�߿�!) ��! � class�� ���������Լ��� ������ �θ�, �׸� ����� Ŭ������ �ݵ�� ���������Լ��� �ּ��� �����ؾ� �� (= interface�� Ư���� ����)

//     # ���������Լ� (pure virtual function) ����
//        : virtual void Speak() = 0
//           -> ���� ����, virtual �Լ��� ���Ǻ� ������ ������, �װ� ���������Լ�

//     # ���������Լ� Ư¡
//        : �ϴ� ������ �θ�, �ڼ� class���� �ּ� �ݵ�� ������ ����� �� (= interface�� Ư���� ����)
//           -> (�߿�!) �ݸ� �ϴ� �����Լ�(virtual function)�� {}�� �ĵξ ���� �� �׷��� ��. 


//   - �߻� Ŭ���� (abstract class)
//     : ��ư� �������� ����, �׳� override �ڽĸ���� ȣ���� �� �ִ� ���������Լ� (pure virtual function)�� ����Լ��� ������ �ִ� class... 
//        -> ���������Լ��� ǰ�� �θ� class�� �̸� ���� �θ�� �ڽ� class���� override�� �Լ��� �θ� class ��ü�����ͷ� ���ٰ�����
//            -> (�߿�!) ������ �����̴� ��ŭ, �߻�Ŭ������ ��ü�� ������ �Ұ�����!!!


// quiz1�� ������ ���� �����Ҹ��� ������ animal�� ������ �ؼ� override�ؼ� ǥ���ϴ°� �߻�Ŭ������ ����ؼ� �ذ��ض�
#include <iostream>
#include <iomanip>

using namespace std;

// �߻�Ŭ���� (abstract class) Animal
//  -> ������ ������ �����Ͽ�, �θ� �ڽĿ� ���ٰ����ϰ� �Ϸ���, override�� ������ �θ��� ����Լ��� virtual �Լ��� ���������Լ��� ������ �ϱ� ���� 
class Animal {

	public:
		// �����Լ� (virtual function)�� ���� ������ �ڽĵ��� speak(), walk()�� override�ϸ� �װ� �θ�� ȣ���� ������ 
		//  -> ���������Լ��� ���⼭�� ���� �ʰ���
		virtual	void speak() {
			cout << "    >> ������ say : ..... " << endl;
		};

		virtual void walk() {
			cout << "    >> ������ say : 4�߷� �ȴ°� ������ �⺻.." << endl;
		};

		virtual ~Animal() {
			cout << "[���̽� �Ҹ���]\n";
		}
};

class Dog : public Animal {

	public:
		void speak() {
			cout << "    >> [override] �пп�~~ ������!!!" << endl;
		};

		Dog() {
			cout << "[Dog ������]\n";
		}

		~Dog() {
			cout << "[Dog �Ҹ���]\n";
		}
};

class Cat : public Animal {

	public:
		void speak() {
			cout << "    >> [override] ���� �����̴ٿ�~" << endl;
		};

		Cat() {
			cout << "[Cat ������]\n";
		}

		~Cat() {
			cout << "[Cat �Ҹ���]\n";
		}
};

class Pig : public Animal {

	public:
		void speak() {
			cout << "    >> [override] ������ �ܲܲܲ� ~ " << endl;
		};

		Pig() {
			cout << "[Pig ������]\n";
		}

		~Pig() {
			cout << "[Pig �Ҹ���]\n";
		}
};

class Duck : public Animal {

	public:
		void speak() {
			cout << "    >> [override] ����, �в�~ ����, �в�~ " << endl;
		};

		void walk() {
			cout << "    >> [override] 2�߷� �ȴ� ��찡 �ٷ� �츮 ������" << endl;
		};

		Duck() {
			cout << "[Duck ������]\n";
		}

		~Duck() {
			cout << "[Duck �Ҹ���]\n";
		}
};

class Human : public Animal {

	public:
		void speak() {
			cout << "    >> [override] �ȳ��ϼ���~ Hello ~ Bonjour ~ ���ġ��~ .... " << endl;
		};

		void walk() {
			cout << "    >> [override] 2�߷� �ȴ� ��찡 �ٷ� �츮 �������" << endl;
		};

		Human() {
			cout << "[Human ������]\n";
		}

		~Human() {
			cout << "[Human �Ҹ���]\n";
		}
};

int main() {

	int flag;
	Animal* any;

	while (1) {

		cout << "1. dog  2. cat  3. pig   4. duck   5. human   0. exit" << endl;
		cout << " ->> Please, choice yours ~ : ";
		cin >> flag;

		switch (flag) {

		case 1:
		{
			any = new Dog();
			break;
		}
		case 2:
		{
			any = new Cat();
			break;
		}
		case 3:
		{
			any = new Pig();
			break;
		}
		case 4:
		{
			any = new Duck();
			break;
		}
		case 5:
		{
			any = new Human();
			break;
		}
		default:
			exit(0);
			break;
		}

		any->speak();
		any->walk();

		delete any;

		cout << endl;
	}

	return 0;
}