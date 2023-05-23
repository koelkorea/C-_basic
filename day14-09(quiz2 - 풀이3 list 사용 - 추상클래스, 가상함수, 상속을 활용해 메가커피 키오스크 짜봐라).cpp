// quiz2 - 추상클래스, 가상함수, 상속을 활용해 메가커피 키오스크 짜봐라
//  1. 메뉴선택 여러개
//  2. 선택 끝나면, 주문내역과 총 합계금액 출력 
//  3. 그 후 고객정보(이름, 전화번호) 입력 받으면
//  4. 주문번호 부여

//  상속구조
//   -> 고객 <- 메뉴 <- 커피, 스무디, 에이드 등

// 풀이3 - list 컨테이너 클래스 객체로 풀이
#include <string>
#include <iostream>
#include <list>

using namespace std;

class menu;

class Customer {

private:
	// 주문번호 뿌리는 용도
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

// static 초기화
int Customer::nextOrderNum = 0;

// 모든 메뉴의 원형
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

	// 메뉴에 해당되는 녀석을 고객의 menulist 동적객체배열에 추가
	virtual void pickMenu(Customer* customer) {		}

	// 메뉴정보 보여주기
	virtual void show() {
		cout << "메뉴 : " << menuName << endl;
		cout << "가격 : " << price << endl;
	}
};

void Customer::showAllMenu() {

	if (orderlist->size() == 0) {
		cout << " ->> (경고!) 주문리스트에 올라온게 없습니다! 메뉴를 추가해주세요!" << endl;
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

// 커피 클래스 = menu 자식class 
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

	// 메뉴에 해당되는 녀석을 고객의 menulist 동적객체배열에 추가
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> " << getMenuName() << "이(가) 메뉴에 추가되었습니다." << endl << endl;
	}

	virtual void show() {
		cout << "메    뉴 : " << getMenuName() << endl;
		cout << "가    격 : " << getprice() << endl;
		cout << "원 산 지 : " << coffieKindName << endl;
	}
};

// 쥬스, 스무디, 에이드 클래스 = menu 자식class 
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

	// 메뉴에 해당되는 녀석을 고객의 menulist 동적객체배열에 추가
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> " << getMenuName() << "이(가) 메뉴에 추가되었습니다." << endl << endl;
	}

	virtual void show() {
		cout << "메    뉴 : " << getMenuName() << endl;
		cout << "가    격 : " << getprice() << endl;
		cout << "원 재 료 : " << fruit << endl;
	}
};

// 프라페 클래스 = menu 자식class 
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

	// 메뉴에 해당되는 녀석을 고객의 menulist 동적객체배열에 추가
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> " << getMenuName() << "이(가) 메뉴에 추가되었습니다." << endl << endl;
	}

	virtual void show() {
		cout << "메    뉴 : " << getMenuName() << endl;
		cout << "가    격 : " << getprice() << endl;
		cout << "토    핑 : " << ingredient << endl;
	}
};


// 차 클래스 = menu 자식class 
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

	// 메뉴에 해당되는 녀석을 고객의 menulist 동적객체배열에 추가
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> " << getMenuName() << "이(가) 메뉴에 추가되었습니다." << endl << endl;
	}

	virtual void show() {
		cout << "메    뉴 : " << getMenuName() << endl;
		cout << "가    격 : " << getprice() << endl;
		cout << "차 종 류 : " << teaKind << endl;
	}
};

// 디저트 클래스 = menu 자식class 
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

	// 메뉴에 해당되는 녀석을 고객의 menulist 동적객체배열에 추가
	virtual void pickMenu(Customer* customer) {
		customer->getOrderlist()->push_back(this);
		cout << " ->> (알림) " << getMenuName() << "이(가) 메뉴에 추가되었습니다!!!" << endl << endl;
	}

	virtual void show() {
		cout << "메    뉴 : " << getMenuName() << endl;
		cout << "가    격 : " << getprice() << endl;
		cout << "유    형 : " << type << endl;
	}
};

menu* coffieMenu() {

	cout << "[커피 메뉴 일람]" << endl;
	cout << "1. 에스프레소" << endl;
	cout << "2. 아메리카노" << endl;
	cout << "3. 바닐라라떼" << endl;
	cout << "4. 초콜릿라떼" << endl;
	cout << "5. 카라멜 마끼아또" << endl;
	cout << "6. 콜드브루" << endl;
	cout << "99. 이전으로..." << endl;
	cout << " ->> 메뉴를 입력해주세요 : ";

	int menuNum = 0;
	cin >> menuNum;

	menu* tmp = NULL;

	switch (menuNum) {
	case 1:
		tmp = new coffie("에스프레소", 1500, "에티오피아");
		break;
	case 2:
		tmp = new coffie("아메리카노", 1500, "인도네시아");
		break;
	case 3:
		tmp = new coffie("바닐라라떼", 2500, "가나");
		break;
	case 4:
		tmp = new coffie("초콜릿라떼", 2500, "터키");
		break;
	case 5:
		tmp = new coffie("카라멜 마끼아또", 2500, "브라질");
		break;
	case 6:
		tmp = new coffie("콜드브루", 2500, "수단");
		break;
	default:
		system("cls");
		break;
	}

	return tmp;
}


menu* smoothlyAdeJuiceMenu() {

	cout << "[스무디 & 프라페 & 주스 일람]" << endl;
	cout << "1. 레몬쥬스" << endl;
	cout << "2. 레몬에이드" << endl;
	cout << "3. 자몽쥬스" << endl;
	cout << "4. 자몽에이드" << endl;
	cout << "5. 녹차 프라페" << endl;
	cout << "6. 쿠키 프라페" << endl;
	cout << "99. 이전으로..." << endl;
	cout << " ->> 메뉴를 입력해주세요 : ";

	int menuNum = 0;
	cin >> menuNum;

	menu* tmp = NULL;

	switch (menuNum) {
	case 1:
		tmp = new juice_smoothy_ade("레몬쥬스", 2000, "레몬");
		break;
	case 2:
		tmp = new juice_smoothy_ade("레몬에이드", 2500, "레몬");
		break;
	case 3:
		tmp = new juice_smoothy_ade("자몽쥬스", 2000, "자몽");
		break;
	case 4:
		tmp = new juice_smoothy_ade("자몽에이드", 2500, "자몽");
		break;
	case 5:
		tmp = new juice_smoothy_ade("녹차 프라페", 3500, "녹차");
		break;
	case 6:
		tmp = new juice_smoothy_ade("쿠키 프라페", 3500, "쿠키");
		break;
	default:
		system("cls");
		break;
	}

	return tmp;
}

menu* teaFlaffeMenu() {

	cout << "[프라페 & 차 일람]" << endl;
	cout << "1. 녹차 프라페" << endl;
	cout << "2. 쿠키 프라페" << endl;
	cout << "3. 딸기 쿠기 프라페" << endl;
	cout << "4. 얼그레이" << endl;
	cout << "5. 녹차" << endl;
	cout << "6. 캐모마일" << endl;
	cout << "99. 이전으로..." << endl;
	cout << " ->> 메뉴를 입력해주세요 : ";

	int menuNum = 0;
	cin >> menuNum;

	menu* tmp = NULL;

	switch (menuNum) {
	case 1:
		tmp = new frappe("녹차 프라페", 3000, "녹차");
		break;
	case 2:
		tmp = new frappe("쿠키 프라페", 3000, "쿠키");
		break;
	case 3:
		tmp = new frappe("딸기 쿠기 프라페", 3000, "딸기, 쿠키");
		break;
	case 4:
		tmp = new tea("얼그레이", 1000, "얼그레이");
		break;
	case 5:
		tmp = new tea("녹차", 1000, "녹차");
		break;
	case 6:
		tmp = new tea("캐모마일", 1000, "캐모마일");
		break;
	default:
		system("cls");
		break;
	}

	return tmp;
}

menu* desertMenu() {

	cout << "[디저트 일람]" << endl;
	cout << "1. 쿠키" << endl;
	cout << "2. 크로플" << endl;
	cout << "3. 케이크" << endl;
	cout << "4. 핫도그" << endl;
	cout << "5. 크로슈무슈" << endl;
	cout << "99. 이전으로..." << endl;
	cout << " ->> 메뉴를 입력해주세요 : ";

	int menuNum = 0;
	cin >> menuNum;

	menu* tmp = NULL;

	switch (menuNum) {
	case 1:
		tmp = new frappe("쿠키", 1000, "쿠키");
		break;
	case 2:
		tmp = new frappe("크로플", 2000, "크로플");
		break;
	case 3:
		tmp = new frappe("케이크", 5000, "케이크");
		break;
	case 4:
		tmp = new tea("핫도그", 4500, "핫도그");
		break;
	case 5:
		tmp = new tea("크로슈무슈", 4000, "크로슈무슈");
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

	Customer* customer = new Customer("이니셜", "010-2222-1111", orderlistPoint);

	while (1) {

		cout << "[메가커피 Kiosk]" << endl;
		cout << "1. 커피" << endl;
		cout << "2. 스무디 & 에이드 & 주스" << endl;
		cout << "3. 프라페 & 차" << endl;
		cout << "4. 디저트" << endl;
		cout << "5. 계산할 총 금액" << endl;
		cout << "6. 종료" << endl;
		cout << " ->> 메뉴를 입력해주세요 : ";

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
			cout << "[주문번호 " << customer->getOrderNum() << "번]" << endl;
			cout << "고 객 명 : " << customer->getName() << " 고객님" << endl;
			cout << "전화번호 : " << customer->getCellphone() << endl << endl;
			customer->showAllMenu();
			cout << " ->> 주문 총 금액 : " << customer->howMuch() << "원" << endl << endl;
		}
		else if (flag == 6) {

			cout << "키오스크를 종료합니다!~";
			exit(0);
		}

	}


}