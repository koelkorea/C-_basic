// quiz : a문자열을 입력받고 -> 검색문자 입력 -> 그것을 대소문자 변경 모두 포함하여 갯수를 검색해라
 
// c++에서 문자열을 띄어쓰기 포함해서 입력받는(enter키가 기준) 함수 
//  : cin.getline(배열명, 칸수);

// c++에서 문자열 입력시 엔터키 중복을 막아주는 방법
//-------------------------------------------------------
// 1. cin.fail(), cin.clear() 사용
//  -> cin.fail() : std::cin이 실패했는지 여부를 0 1로 체크
//  -> cin.clear(): std::cin에 들어온 스트림을 초기화
//  -> cin.ignore(n) : 입력 n개 버퍼비우기(= 그냥 지워버림)

//  if (cin.fail()) {
//  	cin.clear();
//  }

//-------------------------------------------------------
// 2. cin.get() 사용 : 입력 값에서 문자 1개만 입력받음
//  cin.get();

#include <iostream>
#include <iomanip>  // left, right, setw(int : 칸수) : cout과 같이 사용하고, left나 right 선언 후 set(int)를 쓰면, 칸수에 해당하는 공백을 생성 후 왼쪽으로 공백을 보내냐(= 오른쪽정렬)? 오른쪽으록 공백을 보내냐(= 왼쪽정렬)를 구분

using namespace std;  // std:: 생략가능

int main() {

	char input[50] = {0};
	char code = 0;

	while (1) {

		cout << "문자열 입력 : ";
		cin.getline(input, 50);

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
		// 2. cin.get() 사용 : 입력 값에서 문자만 입력받음
		// cin.get();

		cout << "검색문자 입력 : ";
		cin >> code;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1);
		}

		int index = 0;
		int result = 0;

		// 소문자 -> 대문자
		if (code >= 97 && code <= 122) {

			for (int i = 0; input[i] != '\0'; i++) {

				if (input[i] == code || input[i] == (code - 32) ) {

					result++;
				}
			}

			cout << " ->> 검색문자[" << (char)code << "(" << (char)(code - 32) << ")]의 갯수는[" << result << "]개 입니다." << endl << endl;
		}
		// 대문자 -> 소문자
		else if (code >= 65 && code <= 90) {

			for (int i = 0; input[i] != '\0'; i++) {

				if (input[i] == code || input[i] == (code + 32) ) {

					result++;
				}
			}

			cout << " ->> 검색문자[" << (char)code << "(" << (char)(code + 32) << ")]의 갯수는[" << result << "]개 입니다." << endl << endl;
		}
		else {

			cout << " ->> 영문자만 입력해라..." << endl << endl;
		}

		cin.ignore(1);
	}

	return 0;
}