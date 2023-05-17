// quiz1 : 상속을 이용한 클래스를 설계하라
//  -> 날짜와 관련된 개념을 설정하는 Date 클래스의 멤버변수와 함수 리스트를 작성하고, 이를 이용해 자식클래스로 Product 클래스를 생성함.. 조건은 다음과 같음

// ★ Date클래스 디자인
//    1. private 멤버변수
//      - 년
//      - 월
//      - 일
//    
//    2. public 멤버 함수
//      - 생성자 - 인수가 없는 기본 생성자를 이용한다.Date()
//      - 년, 월, 일 설정함수 set
//      - 년, 월, 일 리턴함수 get
// 
// ★ Product클래스 디자인 : Date클래스 상속
//    1. private 멤버변수
//      - 상품명
//      - 제조사
//      - 가격
// 
//    2. public 멤버 함수
//      - 생성자 - 인수가 없는 기본 생성자를 이용한다.
//      - SetProduct - 상품명, 제조사, 가격, 년, 월, 일 초기화
//      - 상품명, 제조사, 가격, 제조일자 설정함수 set
//      - 상품명, 제조사, 가격 리턴함수 get
//      - 상품정보 출력 함수

// 풀이4 - product 객체포인터만 받는 vector 사용 (생성자 사용x)
//  -> 길이가변적 동적배열 vector 클래스를 사용

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
class Date {

private:
	// 년, 월, 일
	int year, month, day;

public:
	// set함수 : 년, 월, 일 설정함수
	void setYear(int _year) {
		year = _year;
	}

	void setMonth(int _month) {
		month = _month;
	}

	void setDay(int _day) {
		day = _day;
	}

	// get함수 : 년, 월, 일 설정함수
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
	// 현재 등록된 상품수, 일련번호(현재 등록된 상품수를 받을 예정), 상품명, 제조사, 가격
	static int currentNum;
	int num;
	string name;
	string manufacturer;
	int price;

public:

	~Product() {};

	// 상품 클래스의 멤버변수 초기화를 담당하는 함수 (여기서는 생성자에 관해 부모생성자 상속 및 호출은 생각하지 않는걸로..)
	void init(string _name, string _manufacturer, int _price, int _year, int _month, int _day) {

		num = ++currentNum;
		name = _name;
		manufacturer = _manufacturer;
		price = _price;

		setDate(_year, _month, _day);
	}

	// set함수 : 상품명, 제조사, 가격, 제조일자
	void setName(string _name) {
		name = _name;
	}

	void setManufacturer(string _manufacturer) {
		manufacturer = _manufacturer;
	}

	void setPrice(int _price) {
		price = _price;
	}

	// 부모클래스 초기화 관련 생성자로 처리 가능하나.. (여기서는 생성자에 관해 부모생성자 상속 및 호출은 생각하지 않는걸로..)
	void setDate(int _year, int _month, int _day) {

		setYear(_year);
		setMonth(_month);
		setDay(_day);
	}

	// get함수 : 일련번호(static), 상품명, 제조사, 가격
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

	// 상품 정보 출력
	void showInfo() {
		cout << endl;
		cout << "일련번호 : " << num << endl;
		cout << "상 품 명 : " << name << endl;
		cout << "제조업체 : " << manufacturer << endl;
		cout << "가    격 : $ " << price << endl;
		cout << "제조일자 : " << getYear() << "년 " << getMonth() << "월 " << getDay() << "일" << endl;
		cout << endl;
	}
};

// 현재 제품번호 부여용 초기화
int Product::currentNum = 0;

//---------------------------------------------------기존 cin.clear를 발전시킨 메서드 cinput--------------------------------------------
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
		cout << "(알림) 입력이 잘못되었습니다. 다시 입력하세요!" << endl << endl;
	}
}

void cinput(char& n) {
	while (!(cin >> n)) {
		cinclear();
		cout << "(알림) 입력이 잘못되었습니다. 다시 입력하세요!" << endl << endl;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------

int main() {

	cout << "[상품 등록 프로그램]을 작동!" << endl << endl;

	// 종료여부 flag
	int flag = 0;

	// product 객체포인터만을 받는 가변길이 동적배열 vector 선언
	//  -> (중요) 크기는 선언하지 않는게, 그렇게 하면 stack용 push_back 실행시에 선언한 크기 + 1 위치에 값 입력)
	vector<Product*> items;

	while (flag != 1) {

		// 이번 loop에 입력할 상품의 수
		int inputNum = 0;

		cout << "입력할 제품의 갯수는? : " << endl;
		cin >> inputNum;
		while (cin.get() != '\n');

		for (int i = 0; i < inputNum; i++) {

			cout << endl << "일련번호 " << Product::getCurrentNum() + 1 << "번 등록을 시작합니다!" << endl;

			Product* newItem = new Product;

			string name = "";
			string manufacturer = "";
			int price = 0;
			int year = 0;
			int month = 0;
			int day = 0;

			cout << " ->> 상 품 명 : ";
			cin >> name;
			while (cin.get() != '\n');

			cout << " ->> 제조업체 : ";
			cin >> manufacturer;
			while (cin.get() != '\n');

			cout << " ->> 가   격 : ";
			cin >> price;
			while (cin.get() != '\n');

			cout << " ->> 제조일자 (YYYY MM DD 형식으로.. 0은 빼고) : ";
			cin >> year >> month >> day;
			while (cin.get() != '\n');

			newItem->init(name, manufacturer, price, year, month, day);

			// vector에 값을 추가한 class객체는 이를 깊은 복사화 함 = 값이 추가된 {}에 구애받지 않고 값이 제대로 저장됨
			//  -> 물론 여기서 받는 객체포인터는 그 위치에 new를 통한 객체 내용 동적할당이 완료된 상태라 아무래도 상관은 없음.. 하지만 제너릭스에 클래스로만 놔도 문제없이 저장된다는점 알아두자
			items.push_back(newItem);

			cout << " ->> (알림) 제품등록이 완료되었습니다. (상품명 : " << newItem->getName() << ")" << endl;

		}

		cout << endl << " (주의) 등록횟수만큼 등록 완료\n          ->> 계속 등록하시겠습니까? (종료하고 싶으시면 1을 눌러주세요) : " << endl;
		cin >> flag;
	}

	// 종료 후 등록한 상품정보 조회 (staic 변수로 객체배열 index 조회)
	for (int i = 0; i < Product::getCurrentNum(); i++) {
		items[i]->showInfo();
	}

	return 0;
}