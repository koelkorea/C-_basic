// c++.cpp : c++ 파일 확장자, 이 파일에는 'main' 함수가 기본적으로 포함됨

#include <iostream>   // cin, cout, clog, cerr    <- stdio.h의 scanf, printf 대체

int main() {

	int age = 0;

	// << , >> 비트연산자 = 스트림연산자 : 화살표 방향은 스트림의 흐름을 의미 (이걸로 입력시 공백이 포함된 문자열은 못 받음)

	std::cout << "문자열을 입력해줘라\n";
	std::cin >> age;                  // std::cin >> 변수명 : 해당 변수명에 임의적 데이터를 입력함(>>로 입력시 공백이 포함된 문자열은 못 받음)
	std::cout << "Hello World\n";     // std::cout << "내용" : 해당 "내용"을 출력해줌
	std::cout << age;                 // std::cout << "변수명" : 해당 변수명에 입력된 내용을 출력해줌
	std::cout << std::endl;           // endl : \n의 의미

	return 0;
}
