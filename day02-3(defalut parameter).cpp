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
//      -> (주의!) 이 녀석을 썼을때, 해당 함수로 커버되는 범위의 같은 함수명 기반 overloading된 다른 함수를 쓰면, 어떤 함수를 불러야할지 컴퓨터에 혼동을 주게 됨.. 

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

//  # Default Parameter 사용시 주의사항
//    : 이 사안들을 지키지 않는다면 충돌이 나 버림
//       1. parameter의 디폴트 값은 parameter의 선언부 중 오른쪽에 위치한 녀석에서부터 차례대로 할당
//       2. Default Parameter로 작성한 overloading 함수가 존재하는 상황에서, 해당 함수로 커버되는 parameter구성을 가지는 같은 함수명 기반 overloading된 다른 함수를 쓰면, 어떤 함수를 불러야할지 컴퓨터에 혼동을 주게 됨

//          ex) 1을 어긴 예시

//              int sum(int a = 0, int b = 0, int c=0, int d, int e) {
//                  return a + b + c + d + e;
//              }

// 2를 어긴 예시
#include <iostream>
using namespace std;

void call(int a) {
	cout << "인수 1개 호출\n";
}

// 
void call(int a, int b = 0) {
	cout << "인수 2개 호출\n";
}

int main() {
	// call(1);       <- 이 경우 1번째 함수를 호출해야 하나?? 아니면 2번째의 defalut parameter를 생성해야 하나?
	call(2, 3);
	return 0;
}
