// quiz : 대문자 -> 소문자 , 소문자 -> 대문자 해주는 코드를 c++의 std를 이용해서 작성해라

// c++에서 문자열 입력시 엔터키 중복을 막아주는 방법
//-------------------------------------------------------
// 1. cin.fail(), cin.clear() 사용
//  -> cin.fail() : std::cin이 실패했는지 여부를 0 1로 체크
//  -> cin.clear(): std::cin에 들어온 스트림 값을 비어줌
//  -> cin.ignore(n) : 입력 n개 버퍼비우기(= 그냥 지워버림)

//  if (cin.fail()) {
//  	cin.clear();
//  }

//-------------------------------------------------------
// 2. cin.get() 사용 : 입력 값에서 문자 1개만 입력받음
//  cin.get();

#include<iostream>
#include<iomanip>  // left, right, setw(int : 칸수) : cout과 같이 사용하고, left나 right 선언 후 set(int)를 쓰면, 칸수에 해당하는 공백을 생성 후 왼쪽으로 공백을 보내냐(= 오른쪽정렬)? 오른쪽으록 공백을 보내냐(= 왼쪽정렬)를 구분

using namespace std;  // std:: 생략가능

int main() {

	char code = 0;

	while (1) {

		cout << "대문자/소문자 둘 중 하나 입력 : ";
		cin >> code;

		// c++에서 문자열 입력시 엔터키 중복을 막아주는 방법
		//-------------------------------------------------------
		// 1. cin.fail(), cin.clear() 사용
		//  -> cin.fail() : std::cin이 실패했는지 여부를 0 1로 체크
		//  -> cin.clear(): std::cin에 들어온 스트림 값을 비어줌
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1);
		}

		//-------------------------------------------------------
		// 2. cin.get() 사용 : 입력 값에서 문자 1개만 입력받음
		cin.get();

		// 조건문 if

		// 소문자 -> 대문자
		if (code >= 97 && code <= 122) {

			cout << left << setw(2);
			cout << code << "---->" << right << setw(2) << (char)(code - 32) << endl << endl;
		}

		// 대문자 -> 소문자
		else if (code >= 65 && code <= 90) {

			cout << left << setw(2);
			cout << code << "---->" << right << setw(2) << (char)(code + 32) << endl << endl;
		}
		else {

			cout << " ->> 영문자만 입력해라..." << endl << endl;
		}

	}

	return 0;
}