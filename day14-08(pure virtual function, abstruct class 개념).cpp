// 3. 가상함수 (virtual function)

//   - 순수가상함수 (pure virtual function)
//     : 자식 class에서 override된 함수에 부모 class 객체포인터가 접근 및 호출하기 위한 목적으로 선언된, 선언부만 있고 정의부가 없는 가상함수(= virtual function)
//        -> (중요!) 단! 어떤 class에 순수가상함수를 선언해 두면, 그를 상속한 클래스도 반드시 순수가상함수를 최소한 선언해야 함 (= interface적 특성을 지님)

//     # 순수가상함수 (pure virtual function) 형식
//        : virtual void Speak() = 0
//           -> 쉽게 말해, virtual 함수에 정의부 내용이 없으면, 그게 순수가상함수

//     # 순수가상함수 특징
//        : 일단 선언해 두면, 자손 class에서 최소 반드시 선언은 해줘야 함 (= interface적 특성을 지님)
//           -> (중요!) 반면 일단 가상함수(virtual function)에 {}만 쳐두어도 굳이 안 그래도 됨. 


//   - 추상 클래스 (abstract class)
//     : 어렵게 생각하지 말고, 그냥 override 자식멤버를 호출할 수 있는 순수가상함수 (pure virtual function)를 멤버함수로 가지고 있는 class... 
//        -> 순수가상함수를 품는 부모 class로 이를 통해 부모는 자식 class에서 override된 함수에 부모 class 객체포인터로 접근가능함
//            -> (중요!) 목적이 목적이니 만큼, 추상클래스는 객체로 생성은 불가능함!!!


// quiz1의 각각의 동물 울음소리와 걸음을 animal을 선조로 해서 override해서 표현하는걸 추상클래스를 사용해서 해결해라
#include <iostream>
#include <iomanip>

using namespace std;

// 추상클래스 (abstract class) Animal
//  -> 다형성 원리를 적용하여, 부모가 자식에 접근가능하게 하려면, override의 원형인 부모의 멤버함수를 virtual 함수인 순수가상함수로 만들어야 하기 때문 
class Animal {

	public:
		// 가상함수 (virtual function)를 통해 앞으로 자식들이 speak(), walk()를 override하면 그걸 부모라도 호출이 가능함 
		//  -> 순수가상함수는 여기서는 쓰지 않겠음
		virtual	void speak() {
			cout << "    >> 조물주 say : ..... " << endl;
		};

		virtual void walk() {
			cout << "    >> 조물주 say : 4발로 걷는게 동물의 기본.." << endl;
		};

		virtual ~Animal() {
			cout << "[베이스 소멸자]\n";
		}
};

class Dog : public Animal {

	public:
		void speak() {
			cout << "    >> [override] 왈왈왈~~ 컹컹컹!!!" << endl;
		};

		Dog() {
			cout << "[Dog 생성자]\n";
		}

		~Dog() {
			cout << "[Dog 소멸자]\n";
		}
};

class Cat : public Animal {

	public:
		void speak() {
			cout << "    >> [override] 나는 나옹이다옹~" << endl;
		};

		Cat() {
			cout << "[Cat 생성자]\n";
		}

		~Cat() {
			cout << "[Cat 소멸자]\n";
		}
};

class Pig : public Animal {

	public:
		void speak() {
			cout << "    >> [override] 돼지는 꿀꿀꿀꿀 ~ " << endl;
		};

		Pig() {
			cout << "[Pig 생성자]\n";
		}

		~Pig() {
			cout << "[Pig 소멸자]\n";
		}
};

class Duck : public Animal {

	public:
		void speak() {
			cout << "    >> [override] 오리, 꽥꽥~ 오리, 꽥꽥~ " << endl;
		};

		void walk() {
			cout << "    >> [override] 2발로 걷는 경우가 바로 우리 조류지" << endl;
		};

		Duck() {
			cout << "[Duck 생성자]\n";
		}

		~Duck() {
			cout << "[Duck 소멸자]\n";
		}
};

class Human : public Animal {

	public:
		void speak() {
			cout << "    >> [override] 안녕하세요~ Hello ~ Bonjour ~ 곤니치와~ .... " << endl;
		};

		void walk() {
			cout << "    >> [override] 2발로 걷는 경우가 바로 우리 영장류지" << endl;
		};

		Human() {
			cout << "[Human 생성자]\n";
		}

		~Human() {
			cout << "[Human 소멸자]\n";
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