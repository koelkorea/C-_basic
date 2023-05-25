// 템플릿 특수화 예시1
#include <iostream>
using namespace std;

template <typename T>
int GetSize(T data) {
	cout << typeid(data).name() << " 타입 함수 호출\n";
	return sizeof(data); //data의 바이트(byte)를 리턴
}

// 템플릿 특수화1 : char* 형에 대해서 특수화
template < >
int GetSize <char*>(char* data) {
	cout << typeid(data).name() << " 타입 함수 템플릿 특수화1\n";
	return strlen(data) + 1; //data 문자열의 길이를 리턴
}

// 템플릿 특수화2 : const char* 형에 대해서 특수화
template < >
int GetSize <const char*>(const char* data) {
	cout << typeid(data).name() << " 타입 함수 템플릿 특수화2\n";
	return strlen(data) + 1; //data 문자열의 길이를 리턴
}
int main() {
	cout << GetSize(5) << "바이트\n";
	cout << GetSize(3.14) << "바이트\n";
	cout << GetSize('A') << "바이트\n";
	cout << GetSize((char*)"Hello World") << "바이트\n";
	cout << GetSize("Hello World") << "바이트\n";
	return 0;
}