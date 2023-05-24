// 연산자 오버로딩 (operlator overloading)
//  : (중요!) 일반적으로 흔히 연산을 위해 사용하는 연산자(+, -, / ...)들도 사실은 'operator연산자'라는 함수명을 가지고 있는 함수와 같음
//     -> 이 녀석들의 선언부에 parameter의 구성으로 사용자가 작성한 class 객체들을 사용해서 overloading이? 가능함!!!
//        (= 사용자는 원시형 자료형을 사용한 연산자 외에도, class 객체를 사용할 시 연산자를 활용한 연산 법칙을 창조할 수 있음!!)


//   # 연산자의 종류
// 
//      1. 오버로딩 불가능한 연산자
//         - .                 : class 객체의 멤버영역에 접근하라는 의미
//         - .*                : class 객체의 멤버 포인터
//         - ::                : 범위 지정자
//         - ? true : false    : 3항 연산자
//         - sizeof            : 변수나 객체의 Byte 크기 계산
//         - typeid            : 변수나 객체의 자료형을 도출하는 RTTI 연산자
//         - static_cast       : type 정적 casting
//         - dynamic_cast      : type 동적 casting
//         - const_cast        : type 상수 casting
//         - retinterpret_cast : 포인터 type끼리 casting 허용 

//      2. class의 멤버함수로만 오버로딩 가능 연산자
//         - =   : 대입 연산자
//         - ()  : 함수 호출 연산자
//         - []  : 배열 접근 연산자
//         - ->  : 역참조하여 class 객체 멤버영역 접근 포인터 연산자

//      3. 그 외 대부분의 연산자는 비트연산자(<<, >>), 단항 연산자(++, --) 포함해서 overloading 가능
//          -> (중요) istream, ostream class의 객체인 std의 cin, cout 객체 역시 이 원리로 overloading


//   # 연산자 함수(operator function)의 특징
// 
//      1. 연산자의 함수명은 [operator + '연산자'] 형식으로 이뤄짐

//         ex) operator+(), operator*(), operator>>()

//      2. (중요!) 흔히 쓰는 '변수(객체) + 변수(객체)'와 같은 연산자는 연산자함수를 호출코드를 간추린 것이다

//         ex) 객체1.operator+(객체2)  ->   객체1 + 객체2

//      3. (중요!) 연산자함수로 호출하지 않고, 연산자만을 통해 축약호출을 한 경우에 그것이 어떤 class의 멤버연산자함수 호출인지? 전역연산자함수 호출인지 어떻게 구분하고, 우선권을 주냐?
//          -> 어떤 경우던 일단 멤버연산자함수에 해당하는 내용이 있는지 찾아볼 우선권을 부여함

//          - 연산자 축약 호출시, 호출할 연산자함수 찾는 로직 설명
//             a. 먼저, 연산대상 1번째에 쓰이는 대상의 자료형이나 class명을 기준으로 잡음 
//             b. 그 class의 멤버연산자함수 중 parameter로 들어가는 자료형들과 연산대상 2번째 이후의 대상의 자료형이나 class이 유사한 선언부가 있는지 체크함
//             c. 여기서 parameter 구성과 2번째 이후의 연산대상의 자료형 구성이 일치하는 멤버연산자함수 함수가 존재하는가?
//                 -> YES : 멤버연산자함수 구성으로 호출 
//                    NO  : 전역연산자함수를 뒤져봐서 있다면, 전역연산자함수로 호출함 (없으면, 컴파일 단계에서 에러로 잡아줌)     


// [멤버 연산자함수 overloading 예시코드]
// stream 클래스의 cout 객체의 비트연산자 <<를 operlator overloading을 사용하여 디자인한 예시코드
//  -> 이를 통해 print 객체의 console 출력기능을 비트연산자를 통해 쉽게 쓸수 있음
#include <stdio.h>

// namespace std; == namespace psk;
namespace psk {

    class o_str {

        public:
            // o_str class의 멤버 연산자함수 operator<<를 다양한 연산대상 case에 맞춰 대비해 overloading함 

            // o_str class 객체에 char포인터를 이용한 문자열 2번째 연산대상(paramter)으로 넣어 비트연산자 <<를 통한 연산하는 멤버함수 operator<<() 
            //  -> 이 경우 printf("%s", str) 로 문자열을 console창에 출력하고, o_str class객체 자신을 반환함
            o_str& operator<<(const char* const str) {
                printf("%s", str); 
                return *this; 
            }

            // o_str class 객체에 int 값을 2번째 연산대상(paramter)으로 넣어 비트연산자 <<를 통한 연산하는 멤버함수 operator<<() 
            //  -> 이 경우 printf("%d", i) 로 숫자를 console창에 출력하고, o_str class객체 자신을 반환함
            o_str& operator<< (int i) {
                printf("%d", i);
                return *this; 
            }

            // o_str class 객체에 double 값을 2번째 연산대상(paramter)으로 넣어 비트연산자 <<를 통한 연산하는 멤버함수 operator<<() 
            //  -> 이 경우 printf("%f", d) 로 숫자를 console창에 출력하고, o_str class객체 자신을 반환함
            o_str& operator<< (double d) {
                printf("%f", d);
                return *this
            }

            // o_str class 객체에 char를 이용한 문자를 2번째 연산대상(paramter)으로 넣어 비트연산자 <<를 통한 연산하는 멤버함수 operator<<() 
            //  -> 이 경우 printf("%c", c) 로 문자열을 console창에 출력하고, o_str class객체 자신을 반환함
            o_str& operator<< (char c) {
                printf("%c", c);
                return *this; 
            }
    };

    // class 내부에서 o_str 자신의 객체를 미리 생성 
    //  -> 이를 통해 cout 대신 print를 써도 됨
    o_str print;

    // class 내부에서 char포인터변수 endline을 통해 줄 바꿈 문자열 "\n"를 쉽게 사용하도록 함
    //  -> 이를 통해 endl대신 endline을 써도 "\n"을 출력하게 됨
    const char* const endline = "\n"; 
}

// namespace std; == namespace psk;
using namespace psk; 

// using 명령어를 통해 psk::endline를 쓰지 않아도, 바로 psk namespace영역의 endline이라는 변수를 쓸수 있음 (= endl 안써도 됨)
using psk::endline; 

// using 명령어를 통해 psk::endline를 쓰지 않아도, 바로 psk namespace영역의 print이라는 변수를 쓸수 있음 (= cout 안써도 됨)
using psk::print; 

int main() {

    // full연산자함수 호출식으로 바꿀시
    //  -> print.operator<<("Hello World").(", ").(3.14).(", ").(endline (= "\n") ); 와 같음
    print << "Hello World" << ", " << 3.14 << ", " << endline;

    // full연산자함수 호출식으로 바꿀시
    //  -> print.operator<<(100).(", ").('3.14).('Q').(endline (= "\n") ); 와 같음
    print << 100 << ", " << 'Q' << endline;

    return 0;
}
