// quiz : a문자열을 입력받고 -> 검색문자 입력 -> 그것을 대소문자 변경 모두 포함하여 갯수를 검색해라

// c++에서 문자열을 띄어쓰기 포함해서 입력받는(enter키가 기준) 함수 
//  : cin.getline(배열명, 칸수);

// c++에서 문자열 입력시 엔터키 중복을 막아주는 방법
//-------------------------------------------------------
// 1. cin.fail(), cin.clear() 사용
//  -> cin.fail() : std::cin이 실패했는지 여부를 0 1로 체크
//  -> cin.clear(): std::cin에 들어온 스트림 값을 비어줌
//  -> cin.ignore(n) : 입력 n개 버퍼비우기

//  if (cin.fail()) {
//  	cin.clear();
//  }

//-------------------------------------------------------
// 2. cin.get() 사용 : 입력 값에서 문자 1개만 입력받음
//  cin.get();

#include <iostream>
#include <iomanip>  // left, right, setw(int : 칸수) : cout과 같이 사용하고, left나 right 선언 후 set(int)를 쓰면, 칸수에 해당하는 공백을 생성 후 왼쪽으로 공백을 보내냐(= 오른쪽정렬)? 오른쪽으록 공백을 보내냐(= 왼쪽정렬)를 구분

using namespace std;  // std:: 생략가능

// if문으로 공학단위 변환기 만들기
int main() {

	int 메인선택;
	char 내부메뉴선택;
	int 숫자값 = 0;
	float 결과값;

	while (1) {

		cout << "[원하는 기능의 메뉴번호를 입력해주세요]" << endl;
		cout << " 1. inch <-> cm" << endl;
		cout << " 2. 화씨 <-> 섭씨"<< endl << endl;

		cin >> 메인선택;

		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1);
		}

		if (메인선택 == 1) {

			cout << endl;
			cout << "원하는 기능 코드를 입력해주세요." << endl;
			cout << " a. inch <-> cm" << endl;
			cout << " b. cm <-> inch" << endl << endl;

			cin >> 내부메뉴선택;

			cin.get();

			if (cin.fail()) {
				cin.clear();
			}

			if (내부메뉴선택 == 'a') {

				cout << endl;
				cout << "INCH값을 입력해줘라 : ";
				cin >> 숫자값;
				결과값 = 숫자값 * 2.54;

				cout << " ->> 당신이 입력한 " << 숫자값 << "inch = " << 결과값 << "cm" << endl << endl;

			}
			else if (내부메뉴선택 == 'b') {

				cout << endl;
				cout << "CM값을 입력해줘라 : ";
				cin >> 숫자값;
				결과값 = 숫자값 / 2.54;

				cout << " ->> 당신이 입력한 " << 숫자값 << "cm = " << 결과값 << "inch" << endl << endl;
			}
			else {
				cout << " ->> a, b둘 중 하나만 입력하라고..." << endl;
			}

		}
		else if (메인선택 == 2) {

			cout << "원하는 기능 코드를 입력해주세요." << endl;
			cout << " a. °F(화씨) <-> °C(섭씨)" << endl;
			cout << " b. °C(섭씨) <-> °F(화씨)" << endl << endl;

			cin >> 내부메뉴선택;

			cin.get();

			if (cin.fail()) {
				cin.clear();
			}

			if (내부메뉴선택 == 'a') {

				cout << endl;
				cout << "°F(화씨)값을 입력해줘라 : ";

				cin >> 숫자값;
				결과값 = (숫자값 - 32) * 5.0 / 9.0;

				cout << " ->> 당신이 입력한 " << 숫자값 << "°F = " << 결과값 << "°C" << endl << endl;
			}
			else if (내부메뉴선택 == 'b') {

				cout << endl;
				cout << "°C(섭씨)값을 입력해줘라 : ";
				cin >> 숫자값;
				결과값 = (float)숫자값 * 9 / 5 + 32;

				cout << " ->> 당신이 입력한 " << 숫자값 << "°C = " << 결과값 << "°F" << endl << endl;
			}
			else {
				cout << " ->> a, b둘 중 하나만 입력하라고..." << endl;
			}

		}
		else {

			cout << " ->> 1, 2둘 중 하나만 입력하라고..." << endl;
		}

		cin.clear();

		//printf("당신이 원하는 결과값 : %2.7f \n\n", 결과값);
		cout << "---------------------------------------------------------------------" << endl;
	}

	return 0;
}