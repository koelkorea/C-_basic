// string 클래스
//  : 그 동안 char[] 형식으로 접근하느라 ㅈㄹ맞게 까다로웠던, 문자열을 본격적으로 객체로 사용하기 위해 제작된 namespace std 안의 class 타입
//     -> 단! char 배열을 사용하는 근본 자체는 변하지는 않는게, 멤버변수인 allocator class객체가 기존 char*를 사용한 동적배열 방식의 메모리 동적할당 및 해제를 해주기 때문


//   #  C언어와 C++에서 문자열을 저장하는 자료형
// 
//      - C언어 char 사용
//         : char 변수명[숫자] = "문자열 상수(\0)"  or '문자 상수 값'
// 
//           ex) char str1[15] = "Hello World!(\0)"      <- 거의 null문자가 세트로 붙음
//               char str2[15] = 'Hello World!'

//      - C++는 string 사용
//         : string 변수명("문자열 상수")  or  string 변수명 = "문자열 상수";
// 
//           ex) string str1("Hello World!");         <- 파라미터로 입력하는 법
//               str2 = "Hello World!";               <- 직접 문자열 값 대입하는 법


//   #  C++의 string 클래스의 멤버구조 해체
//      : 간단히 말해, C++에서 개별 string객체는 자신이 위치한 문자열 포인터값과 거기 저장된 문자열의 갯수 및 크기가 얼만지에 대한 정보를 제공함
//        (= 그러니까 string 객체가 직접 문자열 값을 저장하는게 아니라, 객체가 가진 데이터는 문자열을 추출하기 위한 일종의 metadata라 생각하면 편함) 
// 
//      -----------------------------------------------------------------------------------------------------
//      #include <string>

//      namespace std {                        <- (중요!) 그 입/출력 관련 비트연산자를 사용하는 cin, cout 객체와 같은 namespace에 위치
//       
//          class string {
//              unsigned __int64 size;         <- 멤버변수1 : size      (= 저장 가능 문자열의 개수 -> 2^64개)
//              unsigned __int64 capacity;     <- 멤버변수2 : capacity  (= 저장 가능 총 용량 크기 -> 2^64 byte)
//              allocator<char> allocator;     <- 멤버변수2 : allocator (= 문자열 배열에 대한 메모리 할당 및 해제를 관리하는 class객체)
//          };
//      }
//      ---------------------------------------------------------------------------------------------------------

//   #  string 클래스의 Constructor(생성자)의 종류
//       -> 문자열 저장은 깊은 복사 전제

//      1. string 객체명();
//          :  default 생성자로 빈문자열이 저장
// 
//      2. string 객체명(const char* 포인터변수명);
//          : 해당 char 포인터 위치에 존재하는 "문자열 상수(\0)" 를 입력
// 
//      3. string 객체명(const char* 포인터변수명, 숫자n or size크기자료형 변수명)	;
//          : 해당 char 포인터 위치의 문자열의 시작 ~ n개까지 초기화
//            -> (중요) char 포인터 위치의 문자열 길이가 초기화할 크기 n보다 작아도 됨)
// 
//      4. string 객체명(const string & 레퍼런스변수명);
//          : string 클래스의 복사 생성자
//            ->  이미 존재하는 string 객체의 문자열 내용을 깊은 복사하여 대입
// 
//      5. string 객체명(const string & 레퍼런스변수명, index자료형 begin, index자료형 end = npos)	
//          : string 클래스의 복사 생성자 확장판
//            -> 이미 존재하는 string 객체의 문자열 내용중 index가 begin ~ end까지에 해당하는 문자들만 따로 추출하여, 깊은 복사하여 대입
//                ex) string ex(str, 3, 4) == str[3] ~ str[4] = ex의 문자열
// 
//      6. string 객체명(숫자n or size크기자료형 변수명, char 변수명);
//          : 문자 C를 n개로 구성한 문자열을 대입하여 초기화한 string 객체 생성
// 
//      7. string 객체명(const char* 시작포인터변수명, const char* 도착포인터변수명)	
//          : 시작포인터변수명에 기록된 char 포인터 위치를 시작으로 도착포인터변수명에 기록된 char 포인터 위치를 끝으로 한 문자열 내용을 깊은 복사하여 저장하는 string 객체 생성
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex의 문자열
// 
//      8. string 객체명(Iter begin, Iter end)	
//          : Iterator begin에 기록된 char 포인터 위치를 시작으로 Iterator end 기록된 char 포인터 위치를 끝으로 한 문자열 내용을 깊은 복사하여 저장하는 string 객체 생성
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex의 문자열
//             -> Iterater : 포인터처럼 기능하는 반복자 class변수로 이해하면 됨

//   # string::npos의 의미
//      :  find() 함수 수행 시에 찾는 문자열이 없을 때 반환되는 상수 -1을 의미


// string 생성자 정리 예시코드
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
