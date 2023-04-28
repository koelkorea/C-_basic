// namespace(이름공간)
//	: 대형 프로젝트를 진행할 때 or 이전에 프로젝트를 가져올 때 중복되는 요소로 인한 충돌을 막기 위한 도구
//	  -> using namespace std를 추가한 이유
//
//   # namespace 작성법 (= 선언법)

//     ex) namespace namespace명 {
//            리턴타입 namespace함수명() {
//               내용
//            }
//         }

//   # 정의 완료된 namespace 호출하는 3가지 방법 (= 사용법)
//     1. namespace명::식별자를 사용[std::cout; ]
//        :  
//     2. using 지시어를 사용하여 이름 공간 안의 특정 심볼(symbol) 사용[using std::cout; ]
//        :
//     3. using 지시어를 사용하여 이름 공간 안의 모든 심볼 사용[using namespace std; ]
// 
//	이름 공간 안에 선언 된 멤버는 바로 호출이 불가능
//	반드시 어느 이름 공간에 속한 멤버인지를 밝힌 후 사용
//	(using namespace 이름공간명;)
//
//	iostream 헤더파일은 모든 클래스와 객체, 함수들이 std라는 이름 공간 안에 정의
//	
//	
//	
//	::연산자(영역 지정 연산자)는 멤버에 접근할 때 사용하는 연산자다.
//
//
//	namespace
//	하나의 파일에 여러 개의 namespace를 쓸 수 있다.
//
//
//
//
//
//
//
//	여러 개 파일에 한 개의 namespace를 쓸 수 있다.
//
//
//
//
//
//	표준 헤더파일
//	C++표준안으로 C의 기본 헤더파일들도 다시 만들었다.
//	iostream.h->iostream | stdlib.h->cstdlib
//	string.h->cstring | math.h->cmath
//	모든 심볼이 std라는 이름 공간 안에 선언되어 있는지 아닌지의 차이

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

using namespace B;

int main() {

	A::BUBLE();
	BUBLE();
	A::pop();
	pop();

	return 0;
}