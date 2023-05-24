// 템플릿(Template)
//  : function or class를 자료 타입에 따라 개별적으로 다시 작성하지 않아도, parameter의 자료형을 확인하고 컴파일 단계에서 parameter 자료형에 맞는 function or class 제작하주는 틀로서 작동
//    -> (중요) 컴파일 단계에서 작동함 = 템플릿을 많이 쓰면 컴파일 속도가 느려짐 <-> 프로그램 처리 속도는 관계 X
//        -> JAVA의 제너릭스(generics)와 유사한 기능 (단! 제너릭스는 컴파일 과정에서의 타입 check기능 추가)

//   # 템플릿 사용 이유?
//      : 진짜 제대로 만들어만 놓는다면? 코드의 완성도가 높아지고, 유지보수 생산성 효율도 증가하기 때문 
//         -> 이러한 장점이 STL(Standard Template Library)처럼 검증된 라이브러리와 함께면 시너지가 대폭 증가

//   # 템플릿의 종류
//     1. 함수 템플릿(function Template)
//        : 함수의 일반적인 동작을 정의, 함수 호출 시에 '지정된 자료형' 만을 인자로 받아 실제 함수를 생성하는 틀
// 	   
//          ex) list(initializer_list<Type> IList, const Allocator& Al);

// 함수 템플릿 예시2
#include <iostream>
using namespace std;

template <typename T>

// 템플릿 기본형 함수
void print(T n) { 
	cout << "마지막 인수 1개 => ";
	cout << n << endl;
}

// 템플릿 파라미터 팩
template <typename T1, typename... T2> 

// 함수 파리미터 팩
void print(T1 arg, T2... args) {
	cout << "가변인수 => ";
	cout << arg << endl;
	print(args...);
}

int main() {
	print(1.2345);
	print(1, 2.5, "C++");
	print(1, 2, "Hello", 'a', 32.14, 78, 56, "apple");
	return 0;
}
