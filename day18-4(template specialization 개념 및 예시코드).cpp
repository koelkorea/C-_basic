// (템플릭) 특수화 (specialization)
//  : 기존에 템플릿이 작성된 함수(멤버함수, 생성자 포함)를 호출할때 특정 자료형을 parameter로 가져오는 경우에는 '전혀 다른 알고리즘으로 처리(= override)'하라는 개념
//     -> 쉽게 말해, 작성된 함수 템플릿이나 클래스 템플릿에 대한 특정 자료형에 한해 예외 처리 override를 하는 것을 의미
//        -> 템플릿의 명시적 구체화(explicit instantiation)를 작성할 때 템플릿 특수화 문법을 사용함


//   # 특수화 된 함수 템플릿 정의 형식
//      : template<> 자료형 function명 <typename>(parameters...) { 함수 정의 }
//                --                   ----------
//            (생략가능!)           (조건부 생략가능!)              <- (중요!) 특수화 된 함수 템플릿도 정의건 생성이건 function명 옆의 <자료형.. > 부분은 '유추할 수 있는 경우에 한해서' 생략이 가능함 
//                                    -> BUT 사용 추천                          -> 단! 특수화 된 템플릿이면 가급적이면 <자료형> 정보를 작성하거나, 최소한 parameter로 들어간 값의 자료형을 명시라도 명확히 하는 것이 에러 방지나 예측에 유용함 

//         ex) template <typename T> void swap(T a, T b);    <- 기존 입력된 함수 템플릿 
//             template void swap<int>(int a, int b);        <- 프로그래머가 직접 (템플릿) 특수화(specialization) 코드를 입력하여, swap함수를 int 자료형을 받는 형태로 내용을 구체화를 시키라고 수동 지시 


//   # (중요) 특수화 템플릿 종류별 호출 및 생성하는 형식
//      : 기존의 템플릿 작성과 유사하지만, 단지 특수화 템플릿에 선언된 function여서 특정한 자료형만 parameter로 들어가는 경우 override된 내용을 출력함 (= class 생성자 함수는 고려하지 않음)
//          -> (중요) 특수화 템플릿은 기존 템플릿 호출 및 생성과 비슷하게, function or class명 옆의 <자료형>을 생략은 가능하나, '유추할 수 있는 경우에 한해서'만 가능함...
//             -> BUT! 가급적이면 해당 parameter의 자료형을 명시해 놓는 쪽이 컴파일러로 하여금 일반이나 특수화 된 함수 템플릿 중 무엇을 호출해야 하는지 명확하게 하므로 오작동 가능성을 낮출수 있음


//   # (중요) 함수의 특징
//      1. 템플릿이 아닌 function, 함수 템플릿, 명시적 특수화 함수 템플릿, 3가지 전부 같은 function명이란 가정하여 override가 가능함
//      2. 단! 실행의 우선순위는 다음과 같음 
//          : 일반함수 > 템플릿 특수화 함수 > 템플릿 함수


//   # 특수화( specialization) 사용시 주의사항
//      1. (중요) class 생성자 함수는 사용이 불가능 함 (= 생성자 함수는 typename 자료형을 쓰는 템플릿에서 내용을 바꾸는 override가 불가능 함)
//          -> class 멤버함수는 특수화가 가능함 (애초에 함수 템플릿 만이 대상)
//              -> 단! 부분 특수화는 불가능

//      2. 특수화 함수 템플릿 정의 시 <> 생략 가능 여부
//          - template<>의 <>는 생략 가능
//          - 2번째 <자료형>인, function명 <자료형>의 생략은 '유추가능 여부'라는 조건부로 가능하나, 가급적 써주는 게 에러 방지나 결과예측에 유용함

//      3. 특수화 함수 템플릿 정의 시 <> 생략 가능 여부
//          - function명 <자료형>의 생략은 '유추가능 여부'라는 조건부로 가능하나, 가급적 써주는 게 에러 방지나 결과예측에 유용함


// 템플릿 특수화 case별 예시코드
#include <iostream>
#include <cstring>
using namespace std;

//-------------------------------------------------------------------------------------
// Max 함수 템플릿
template <typename T>
T Max(const T a, const T b) {
    return a > b ? a : b;
}

// Max 함수 템플릿 특수화1 : char* 형(문자열 포인터)에 대해서 특수화
template <>
char* Max<char*>(char* a, char* b) {
    cout << "char* Max <char*> (char* a, char* b)" << endl;
    return strcmp(a, b) > 0 ? a : b; // 문자 a <-> z 비교
}

// Max 함수 템플릿 특수화2 : const char* 형(상수 문자열 포인터)에 대해서 특수화
template <>
const char* Max<const char*>(const char* a, const char* b) {
    cout << "const char* Max <const char*> (const char* a, const char* b)" << endl;
    return strlen(a) > strlen(b) ? a : b; // 문자열 길이 비교
}

//-------------------------------------------------------------------------------------
// GetSize 함수 템플릿
template <typename T>
int GetSize(T data) {
    cout << typeid(data).name() << " 타입 함수 호출\n";
    return sizeof(data); //data의 바이트(byte)를 리턴
}

// GetSize 템플릿 특수화1 : char* 형에 대해서 특수화
template < >
int GetSize <char*>(char* data) {
    cout << typeid(data).name() << " 타입 함수 템플릿 특수화1\n";
    return strlen(data) + 1; //data 문자열의 길이를 리턴
}

// GetSize 템플릿 특수화2 : const char* 형에 대해서 특수화
template < >
int GetSize <const char*>(const char* data) {
    cout << typeid(data).name() << " 타입 함수 템플릿 특수화2\n";
    return strlen(data) + 1; //data 문자열의 길이를 리턴
}

// 특수화하는 자료형 정보를 생략하건 생략하지 않건 그 의미하는 바에 차이는 없으나,(컴파일 과정에서 처리) 가급적이면 자료형 정보를 명시하는 것이 뜻을 명확히 하는 방법
//  -> 간혹 string, char* or int, char, string 와 같은 부분에서 미묘하게 예측 못하는 결과가 나올 수 있음
//      -> 만약, 특수화 함수 템플릿 호출시 템플릿 파라미터의 자료형을 포함하지 않았다면, 함수 파라미터로 넣은 자료형이라도 명확히 해주도록 하자 (= 그럼 컴파일러가 잘 참고해줌) 
int main() {

    //----------------------------------------------------------------------------------
    cout << Max(11, 15) << endl;            // Max<int>(11, 15);와 같음
    cout << Max('T', 'Q') << endl;          // Max<char>('T', 'Q');와 같음
    cout << Max(3.5, 7.5) << endl;          // Max<double>(3.5, 7.5);와 같음

    char str1[] = "Simple", str2[] = "Balance";

    cout << Max(str1, str2) << endl << endl; // Max<char*>(str1, str2);와 같음
    cout << Max<char*>(str1, str2) << endl;
    cout << Max<const char*>(str1, str2) << endl;

    //----------------------------------------------------------------------------------
    cout << GetSize(5) << "바이트\n";                          // GetSize<int>(5);와 같음
    cout << GetSize(3.14) << "바이트\n";                       // GetSize<double>(3.14);와 같음
    cout << GetSize('A') << "바이트\n";                        // GetSize<char>(3.14);와 같음
    cout << GetSize((char*)"Hello World") << "바이트\n";       // <- 만약, 특수화 함수 템플릿 호출시 템플릿 파라미터의 자료형을 포함하지 않았다면, 함수 파라미터로 넣은 자료형이라도 명확히 해주도록 하자 (= 그럼 컴파일러가 잘 참고해줌) 
    cout << GetSize("Hello World") << "바이트\n";              //     ex) "Hello World"의 자료형이 string인지 char[]인지 char* const인지 이 경우는 알 수 없음 (이 경우 프로그램의 환경설정의 우선순위가 작용함)

    return 0;
}