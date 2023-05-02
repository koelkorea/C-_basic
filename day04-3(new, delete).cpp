// 정적할당
//  : Compile(컴파일)시 할당될 메모리 크기가 결정 - Stack 영역과 Data 영역에 할당되는 메모리는 모두 정적 할당 - 전역 변수, 지역 변수, 정적 변수 모두 컴파일 시 할당될 정적 할당

// 동적 할당 (new 연산자 사용)
//  : Runtime(실행)중에 메모리가 할당 - 동적 할당된 메모리는 Heap영역에 할당 - Heap메모리 = 동적 메모리 할당


//  # C++동적 할당 형식
//    1. c++ 메모리 동적할당 (malloc, calloc -> new 자료형 예약어를 통한 힙영역에 생성)
//       : 자료형 * 변수명 = new 자료형;   <->   malloc(byte 크기), calloc 등을 쓰던 과거아 다름

//         ex) (일반변수) int* ip = new int;  ,  (배열)  int* ip = new int[5];

//    2. c++ 메모리 동적할당 해제(free -> delete 변수명 예약어를 통한 힙영역 메모리 회수)
//       : delete 변수명;  <->   free 등을 쓰던 과거아 다름

//         ex) (일반변수) delete ip;          ,  (배열) delete[] ip;


//  # new 연산자 의미 
//     : 메모리의 힙 영역에 동적 할당된 시작주소가 어딘지를 리턴해주는 연산자 (= c언어의 realloc, malloc, calloc 등의 함수를 통한 동적할당을 완전히 대체... 기능까지)
//        -> (중요) 기존 c언어의 동적할당 함수와 작동방식이 같음
//            = 이걸 받는 변수도 주소값을 저장하는 포인터변수여야 함
//            = 동적 할당된 데이터 형과 같은 타입의 포인터변수로 이 동적 메모리의 주소값을 받아야 함
//            = 동적으로 할당된 메모리는 반드시 해제가 필요
//              ->  delete 연산자 (c언어의 free 동적해제 대체) 등장

//  # Memory(메모리) 영역 할당주체에 따른 구분 
//    1. Heap
//       : 프로그래머에 의해 할당 및 해제가 이뤄지는 영역으로.. 동적으로 생성되는 자료형 데이터들이 위치하는 영역이고 거기 저장되는 값들도 실질적으로 저장되는 영역임
//          -> Stack과 사실상 전체적으로 같은 메모리 공간을 갈라먹는 처지.. (stack이 크면, heap이 작아지고... 그 반대로 가능)

//    2. stack, data
//       : Stack 영역과 Data 영역은 시스템에 의해 할당되고 해제되는 영역,



// new 예약어와 delete 예약어를 통한 동적배열 메모리 할당 및 해제 예시
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

	cout << "대문자 개수 입력 : ";

	int alphaCnt;
	cin >> alphaCnt;

	// char 포인터변수에 new 연산자를 통한 메모리에 할당하고, 그 시작주소를 포인터변수에 대입 (= 힙 영역에 생성된 char배열의 주소값을 call by reference 형식의 레버런스 변수로 넘겨줌)
	//  : 자료형 * 변수명 = new 자료형;   <->   malloc(byte 크기), calloc 등을 쓰던 과거아 다름
	char* sentence = new char[alphaCnt];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < alphaCnt; i++) {

		// 동적할당 된 배열에 대문자 생성 
		sentence[i] = ( rand() % 26 ) + 65;
		cout << sentence[i] << ' ';
	}

	// char 배열 메모리 동적해제
	//  : delete 변수명;  <->   free 등을 쓰던 과거아 다름
	delete[] sentence;

	return 0;

}