// 템플릿 특수화 예시1
#include <iostream>
#include <cstring>
using namespace std;

// 함수 템플릿
template <typename T>
T Max(const T a, const T b) {
    return a > b ? a : b;
}

// 템플릿 특수화1 : char* 형(문자열 포인터)에 대해서 특수화
template <>
char* Max<char*>(char* a, char* b) {
    cout << "char* Max <char*> (char* a, char* b)" << endl;
    return strcmp(a, b) > 0 ? a : b; // 문자 a <-> z 비교
}

// 템플릿 특수화2 : const char* 형(상수 문자열 포인터)에 대해서 특수화
template <>
const char* Max<const char*>(const char* a, const char* b) {
    cout << "const char* Max <const char*> (const char* a, const char* b)" << endl;
    return strlen(a) > strlen(b) ? a : b; // 문자열 길이 비교
}

//특수화하는 자료형 정보를 생략하건 생략하지 않건 그 의미하는 바에 차이는 없으나,(컴파일 과정에서 처리)
//가급적이면 자료형 정보를 명시하는 것이 뜻을 명확히 하는 방법
int main() {
    cout << Max(11, 15) << endl; //Max<int>(11, 15) <int> 생략
    cout << Max('T', 'Q') << endl; //Max<char>('T', 'Q') <char> 생략
    cout << Max(3.5, 7.5) << endl; //Max<double>(3.5, 7.5) <double> 생략

    char str1[] = "Simple", str2[] = "Balance";

    cout << Max(str1, str2) << endl << endl; //Max<char*>(str1, str2) <char*> 생략
    cout << Max<char*>(str1, str2) << endl;
    cout << Max<const char*>(str1, str2) << endl;

    return 0;
}