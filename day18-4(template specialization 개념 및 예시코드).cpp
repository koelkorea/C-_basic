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