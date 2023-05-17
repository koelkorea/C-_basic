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

#include <string>
#include <iostream>
#include <cstdlib>
#include <malloc.h>
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
		string name;
		string manufacturer;
		int price;

	public:

		~Product() {};

		// 상품 클래스의 멤버변수 초기화를 담당하는 함수 (여기서는 생성자에 관해 부모생성자 상속 및 호출은 생각하지 않는걸로..)
		void init(string _name, string _manufacturer, int _price, int _year, int _month, int _day) {

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

		// get함수 : 상품명, 제조사, 가격
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
			cout << "상 품 명 : "  << name << endl;
			cout << "제조업체 : " << manufacturer << endl;
			cout << "가    격 : " << price << " $" << endl;
			cout << "제조일자 : " << getYear() << "년 " << getMonth() << "월 " << getDay() << "일" << endl;
			cout << endl;
		}
};

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

	int flag = 0;
	int input_try = 0;
	int product_num = 0;

	Product* arr[100];

	while (flag != 1) {

		int inputNum = 0;

		cout << "입력할 제품의 갯수는? : " << endl;
		cin >> inputNum;
		while (cin.get() != '\n');

		Product* hotDeal_list = new Product[inputNum];

		for (int i = 0; i < inputNum; i++) {

			product_num++;

			cout << endl << "제품 " << product_num << "번 등록을 시작합니다!" << endl;

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


			hotDeal_list[i].init(name, manufacturer, price, year, month, day);

			cout << " ->> (알림) 제품등록이 완료되었습니다. (상품명 : " << hotDeal_list[i].getName() << ")" << endl;

		}

		arr[input_try] = hotDeal_list;

		cout << endl << " (주의) 등록횟수만큼 등록 완료\n          ->> 계속 등록하시겠습니까? (종료하고 싶으시면 1을 눌러주세요) : " << endl;
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