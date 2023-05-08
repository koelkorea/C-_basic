//   # C++의 파일 분할 (header.h / source.cpp / main.cpp)과 class의 관계
//     : 헤더 파일(.h)   : class의 선언부, inline 함수 작성
//     : 소스 파일(.cpp) : fuction이나 class의 fuction 정의부 작성
//     : 메인 파일(.cpp) : main()함수 작성

//main.cpp
#include <iostream>
#include "day05-3의 헤더.h"
using namespace std;
int main() {
	ACT act_1;
	act_1.Init_act(1234, "5678", "christopher", 10000);
	act_1.showData();       //잔액조회 멤버 함수 호출
	act_1.deposit();        //입금 멤버 함수 호출
	act_1.withdraw();       //출금 멤버 함수 호출
	act_1.showData();       //잔액조회 멤버 함수 호출
	return 0;
}
