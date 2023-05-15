// string 클래스
//  : 그 동안 char[] 형식으로 접근하느라 ㅈㄹ맞게 까다로웠던, 문자열을 본격적으로 객체로 사용하기 위해 제작된 namespace std안의 class 타입


//C style
//char str[15] = "Hello World!(\0)"
//(큰 따옴표 : "문자열 상수(\0)", 작은 따옴표 : '문자 상수 값')

//C++ style
//string str1("Hello World!"), str2 = "Hello World!";

//#include <string>
//namespace std {
//    class string {
//        unsigned __int64 size;         <- 저장된 문자열의 개수 = 2^64개의 문자열
//        unsigned __int64 capacity;     <- 저장 가능한 총 용량 = 2^64개의 문자열
//        allocator<char> allocator;     <- 배열에 대한 메모리 할당 및 해제를 관리
//    };
//}

//Constructor(생성자)

//Constructor(생성자)	의미
//객체명()	크기가 0인 default 생성자
//객체명(const char* s)	"문자열 상수(\0)"
//객체명(const string & str)	string 객체의 복사 생성자
//객체명(size_type n, char c)	문자 C를 n개 구성한 문자열
//객체명(const char* s, size n)	문자열 상수에서 n개까지 초기화
//s의 문자열 길이 < n 가능
//    template<class Iter>
//객체명(Iter begin, Iter end)	begin ≤ 문자열 < end 초기화
//    Iterater : 반복자, 포인터
//    객체명(const string& str, size pos, size n = npos)	str[pos] ≤ 문자열 < str[n]


//String(문자열) 입력

//C style
// : char 자료형 배열 사용한 문자열 입력(= 기본적으로는 정적할당)
//char name[15];
//cin >> name; // 공백문자 전까지 14(+'\0')개 저장 가능. [ 큐에 '\n' 남김 ]
//while (cin.get() != '\n');
//cin.get(name, 15); // 1행 입력 받기 [ 큐에 '\n' 남김 ]
//cin.getline(name, 15); // 1행 입력 받기 [ '\n'(Enter) 버림 ]
//cin.getline(name, 15, ':'); // 1행 입력 받기 [ ':' 버림 ]

//C++ style
// : string class를 통한 문자열 입력 (= 동적할당)
// 
//입력 받은 문자열 자동 크기 조절
//string fullname;
//cin >> fullname; // 공백문자 전까지 저장 가능. [ 큐에 '\n' 남김 ]
//while (cin.get() != '\n');
//getline(cin, fullname); // 1행 입력 받기 [ '\n'(Enter) 버림 ]
//getline(cin, fullname, ':'); // 1행 입력 받기 [ ':' 버림 ]

//제한 요소 : unsigned __int64(2 ^ 64)저장 가능한 문자열 개수, 메모리 크기


// String(문자열)의 Method(멤버 함수) = 객체.Method();

//  - 문자열의 특정 위치의 문자 반환
//    1. char& at(size_t n)
//        : 문자열 n칸 반환 (0 ≤ 문자열 < End)
//    2. char& operator[] (size_t n)
//        : 문자열 n칸 반환(0 ≤ 문자열 < End)
//    3. char& front()
//        : 문자열[0]칸에 해당하는 부분의 문자 반환
//    4. char& back()
//        : 문자열[End]칸에 해당하는 부분의 문자 반환

//문자열 길이 관련 반환
//size_t size() const == size_t length() const : 문자열 길이 반환
//void resize(size_t n) : 문자열 길이 n개 맞춤(str.size() < n : 공백, n < str.size() : 삭제)void resize(size_t n, char c) : 공백을 문자 c로 설정
//string substr(size_t st = 0, size_t len = npos) const : st부터 len개 반환
//string & replace(size_t st, size_t len, const string & str) : st~len 위치로 str 끼워 넣기
//bool empty() const : 비었는지 확인하는 함수(size == 0 : true)

//문자열 수정(내용 바꾸기 or 추가 or 삭제)
//void clear() : 문자열을 지우는 함수(capacity 유지)
//iterator erase(iterator st, iterator end) : st~end 문자열 제거
//iterator erase(iterator iter) : 문자열[iter] 제거
//string & erase(size_type offset = 0, size_type count = npos) : offset부터 count개 제거
//void push_back(char c) : 맨 뒤에 문자 c 추가 함수
//void pop_back() : 맨 뒤에 있는 문자 1개 제거 함수

//문자열 메모리
//size_t capacity() const; 문자열 저장 가능한 용량(메모리 크기, bytes) 반환
//void shrink_to_fit() : capacity(메모리)를 줄이는 함수
//void reserve(size_t n = 0) : capacity를 할당 함수(메모리 확보)

//C style 변환
//const char* c_str() const : 문자열(+\0) 상수 반환[C style]
//const value_type* data() const noexcept; 문자열을 null로 끝나는 문자 배열로 변환
//value_type* data() noexcept;

//문자열 처리
//int compare(const string& str2) const : 문자열 비교(객체.변수 : > +, = 0, < -반환)
//int compare(size_t st, size_t len, const string& str2) const
//int compare(size_t st, size_t len, const string& str2, size_t st2, size_t len2) const
//void swap(string& str1, string& str2) : str1과 str2를 교환
//size_t copy(char* arr, size_t len, size_t st = 0) const : 복사, 복사된 길이 반환
//size_t find(const string& str, size_t st = 0) const : 객체 내 문자열 검색, 인덱스 반환
//size_t find(const char* arr, size_t st = 0) const : 객체 내 문자열 검색, 실패 npos 반환

//문자열 위치 접근 iterator(반복자, 포인터 주소)
//const_iterator begin() const : 객체[0]의 주소 반환[반복자(iterator 포인터)]
//const_iterator end() const : 객체[End + 1] 주소 반환[반복자(iterator 포인터)]

//문자열 연산자 오버로딩
//String + String
//string & operator+(char _ch) :
//string & operator+(const char* const _ptr) :
//string & operator+(const string & _Right) :
//string & operator+(initializer_list<char> &_ilist) :
//String = String
//string & operator=(char _ch) :
//string & operator=(const char* const _ptr) :
//string & operator=(const string & _Right) :
//string & operator=(initializer_list<char> &_ilist) :
//String[n]
//char& operator[] (const size_t n) :
//const char& operator[] (const size_t n) const :




#include <iostream>
#include <string>
using namespace std;


int main() {// 생성자 

    char ary[] = "The sun will shine on us again.";

    // 1. string()
    //  -> str1 == str1() == ''
    string str1;

    // 2. string(const char * const s)
    //  -> str2(ary) == 'hi!'
    string str2("hi!");

    // 3. string(char * s)
    //  -> str_2(ary) == 'The sun will shine on us again.'
    string str_2(ary);

    // 4. string(const string &str)
    //  -> str3(str2) == 'hi!'
    string str3(str2);

    // 6. string(size_type n, char c);
    //  -> str4(5, 'k') == 'kkkkk'
    string str4(5, 'k');

    // 7. string(const char* s, size_type n)
    //  ->  str5("Korea", 10) == 'Korea'
    string str5("Korea", 10);

    // 8. string(Iter begin, Iter end),(char* begin, char* end)
    //  -> str6(ary + 4, ary + 24) == 'sun will shine on us'
    string str6(ary + 4, ary + 24);

    // 9. string(const string& str, size pos, size n=npos)
    //  -> str7(str_2, 4, 14) == 'sun will shine'
    string str7(str_2, 4, 14);

    // 10. string(const char * str, size pos, size n=npos)
    //  -> str_7("new world string", 4, 5) == 'world'
    string str_7("new world string", 4, 5);

    cout << "=======================================" << endl;
    cout << "str 01  " << str1 << endl;
    cout << "str 02  " << str2 << endl;
    cout << "str 002 " << str_2 << endl;
    cout << "str 03  " << str3 << endl;
    cout << "str 04  " << str4 << endl;
    cout << "str 05  " << str5 << endl;
    cout << "str 06  " << str6 << endl;
    cout << "str 07  " << str7 << endl;
    cout << "str 007 " << str_7 << endl;
    cout << "=======================================" << endl;
    return 0;
}
