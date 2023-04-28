// Function Overloading
//  : 함수명이 같더라도, 매개변수(인수)의 자료 형이나 개수가 다르다면? 
//    -> 다른 함수로 판정하는 것 

//       ex) [오버로딩X시의 함수명 전부 다름]               [오버로딩 가능시 함수명은 같을 수 있음]                         
//           char max_char(char a, char b);          ->   char max(char a, char b);
//           int max_int(int a, int b);              ->   int max(int a, int b);
//           double max_double(double a, double b);  ->   double max(double a, double b);

//  # (중요) 리턴 타입은 오버로딩과 무관

//  # C언어 VS C++ 에서의 함수 호출
//    - C언어
//       : 오버로딩 사용 X
//          -> 함수명만 가지고 호출 = 같은 함수명 BUT 다른 매개변수(parameter)인 함수 사용 불가
// 
//    - C++
//       : 오버로딩 사용 O
//          -> 함수명 + 매개변수(parameter)의 정보를 함께 가지고 호출 = 같은 함수명 BUT 다른 parameter인 함수까지 판별

//  # Overloading 함수 호출 순서
//    (1) Exactly Matching 
//        : 전달하는 매개변수와 정확하게 일치하는 타입이 있는지 찾음
//    (2) Promotion
//        : 파라미터로 들어간 데이터의 손실이 없는 방향으로의 return하여 변환이 가능한 함수가 있는지 찾음
//          ex) 파라미터가 int->double 전달 시, 데이터의 손실 없음.. 따라서 double형 찾아 호출
//    (3) Standard Conversion
//        : 표준 타입들 간에는 암시적인 형 변환이 발생 
//          ex) 파라미터가 double->int 전달 시, 그래도 데이터의 손실이 있지만 int형 찾아 호출
//    (4) User Define Conversion Operator
//        : 사용자가 정의한 변환 연산자가 있다면 이것을 사용해서 변환을 한 후, 함수를 찾음
//    (5) Variable Argument Function(파라미터에 ...가 들어가는 경우)
//        : '…' 가변 파라미터를(‘...’) 매개변수로 갖는 함수는 파라미터의 타입이나 개수에 상관없이 호출

// (중요!) Default Parameter	  <- JS에도 존재
//  : 매개변수에 기본 값을 이미 부여하여 존재하는 함수
//    -> if 함수 호출 시 전달되는 값이 있다면?
//       -> o : 파라미터에 전달된 값으로 대체
//       -> x : 미리 부여된 파라미터 자신의 기본 값을 사용

//  # Default Parameter 표기법
//     : 파라미터 선언부의 오른쪽 숫자들부터 원하는 값을 디폴트 값으로 할당함
//       -> Why? 이렇게 하지 않으면, Function Overloading 체계가 꼬여서 제대로 함수를 인식해서 호출하지 못함

//    ex) int sum(int a, int b, int c = 0, int d = 0, int e = 0) {
//	 		return a + b + c + d + e;
//        }

//  # Default Parameter의 이점
//    : 다형성의 원칙에 의거, 하나의 함수를 작성했음에도 Default Parameter가 선언된 파라미터에 값을 몇개를 주냐에 따라, 다양한 경우에 맞춰 다른 함수로 인식되게 할 수 있음

//      ex) [Default Parameter가 없음]               =>               [Default Parameter를 쓰면, 이 함수로 3가지 경우 커버가 전부 가능함] 
// 
//          int sum(int a, int b) {                                   int sum(int a, int b, int c = 0, int d = 0, int e = 0) {
//				return a + b;                                              return a + b + c + d + e;
//          }														  }
// 		    
//          int sum(int a, int b, int c) {
//          	return a + b + c;
//          }
// 		    
//          int sum(int a, int b, int c, int d) {
//          	return a + b + c + d;
//          }


// 동일한 이름으로 함수 작성, 사용 확인하기
#include <iostream>
using namespace std;

int sum(char a, char b) {
	return a + b;
}

int sum(int a, int b) {
	return a + b;
}

double sum(double a, double b) {
	return a + b;
}

void call(int a) {

	cout << "인수 1개 호출\n";
}

void call(int a, int b) {

	cout << "인수 2개 호출\n";
}


int main() {

	char char_a = 'A', char_b = 'B';
	int int_a = 50, int_b = 30;
	double double_a = 12.3456, double_b = 45.6789;

	cout << "문자 합계 : " << sum(char_a, char_b) << endl;
	cout << "정수 합계 : " << sum(int_a, int_b) << endl;
	cout << "실수 합계 : " << sum(double_a, double_b) << endl;

	call(1);
	call(2, 3);

	return 0;
}
