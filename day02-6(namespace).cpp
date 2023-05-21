// namespace(이름공간)
//	: 대형 프로젝트를 진행할 때 or 이전에 프로젝트를 가져올 때 중복되는 요소로 인한 충돌을 막기 위한 도구
//	  -> using namespace std를 추가한 이유
//
//   # namespace 작성법 (= 선언법)
//      : namespace namespace명 {  리턴타입 namespace함수명() {  내용  }  }


//   # 정의 완료된 namespace의 객체 및 함수 호출하는 3가지 방법 (= 사용법)
//      : namespace 안에 선언 된 멤버는 바로 호출이 불가능 -> 반드시 어느 namespace에 속한 멤버인지를 밝힌 후 사용

//     1. namespace명::식별자를 사용  
//        ex) std::cout 
//            (= std인 namespace에서 cout이라는 객체를 지정 )
//               -> cin과 cout은 정확하게는 iostream,  ostream 클래스의 객체로 std안에 이미 선언되어 있음

//     2. using 지시어를 사용하여 이름 공간 안의 특정 심볼(symbol) 사용
//        ex) using std::cout; 
//            (= 앞으로 cout이라는 명칭을 보면, std안의 cout 객체라고 생각하기)

//     3. using 지시어를 사용하여 이름 공간 안의 모든 심볼 사용 (근데 많이 위험함)
//        ex) using namespace std; 
//            (= 앞으로 사용자가 선언하지 않고 라이브러리에도 없는 변수나 객체나 함수를 만나면, std라는 namespace안의 식별자가 있는지 보고 대처해라


//   # (중요) namespace 특징
//     1. 하나의 파일에 여러 개의 namespace 사용 가능
//     2. 여러 개 파일에 1개의 namespace 또한 사용 가능
//     3. 표준 헤더파일
//         : C++표준안으로 C의 기본 헤더파일들 다시 제작 (= 새로 만들어진 C의 기본 헤더들은, 모든 심볼이 std라는 이름 공간 안에 선언 됨)

//            ex) iostream.h -> iostream     <- iostream 헤더파일은 모든 클래스와 객체, 함수들이 std라는 이름 공간 안에 정의
//                stdlib.h   -> cstdlib
//                string.h   -> cstring
//                math.h     -> cmath


//   # (c++ 추가 + 중요) c++에서 :: 연산자
//     : scope resolution 연산자 (namespace, class, struct 등 자기 영역(scope)이 있는 자료형의 경우, 그 특정 자료형 안의 멤버(변수, 함수 다 포함)를 찾아 참조하라는 의미)
//       -> (결론) namespace명::식별자, 구조체명::멤버함수(), 전부 같은 맥락으로 이해하면 됨
//            -> BUT! 'namespace명::식별자', 'class명::static멤버변수 or static멤버함수' 는 호출이나 참조하는 기능에 가까움     <->    구조체명::멤버함수()는 '함수 정의부'에 쓰임 ( <-> 참조는 구조체 or 클래스 변수명.멤버함수() )


#include <iostream>
using namespace std;

namespace A {
	void BUBLE() {
		cout << "A::BUBLE\n";
	}
	void pop() {
		cout << "A::POP\n";
	}
}

namespace B {
	void BUBLE() {
		cout << "B::BUBLE\n";
	}
	void pop() {
		cout << "B::POP\n";
	}
}

// namespace B에 대해서만 using 명령어 사용
using namespace B;

int main() {

	// namespace A의 함수 BUBLE() 호출
	A::BUBLE();

	// namespace B의 BUBLE() 호출
	BUBLE();

	A::pop();
	pop();

	return 0;
}