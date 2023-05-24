// operlator overloading 사용한 stream cout 클래스 디자인 예시코드
//  -> 이를 통해 print 객체의 출력기능을 비트연산자를 통해 쉽게 쓸수 있음
#include <stdio.h>

// namespace std; == namespace psk;
namespace psk {

    class o_str {

        public:
            o_str& operator<<(const char* const str) { printf("%s", str); return *this; }
            o_str& operator<< (int i) { printf("%d", i);  return *this; }
            o_str& operator<< (double d) { printf("%f", d); return *this; }
            o_str& operator<< (char c) { printf("%c", c); return *this; }
    };

    //객체 생성 ( cout == print )
    o_str print;

    // endl == endline
    const char* const endline = "\n"; 
}

// namespace std; == namespace psk;
using namespace psk; 

// endl == endline
using psk::endline; 

// cout == print 
using psk::print; 

int main() {
    print << "Hello World" << ", " << 3.14 << ", " << endline;
    print << 100 << ", " << 'Q' << endline;
    return 0;
}
