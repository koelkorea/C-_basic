// quiz2 - 추상클래스, 가상함수, 상속을 활용해 메가커피 키오스크 짜봐라
//  1. 메뉴선택 여러개
//  2. 선택 끝나면, 주문내역과 총 합계금액 출력 
//  3. 그 후 고객정보(이름, 전화번호) 입력 받으면
//  4. 주문번호 부여

//  상속구조
//   -> 고객 <- 메뉴 <- 커피, 스무디, 에이드 등

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