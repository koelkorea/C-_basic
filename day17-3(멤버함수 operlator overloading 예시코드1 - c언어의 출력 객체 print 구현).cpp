// operlator overloading ����� stream cout Ŭ���� ������ �����ڵ�
//  -> �̸� ���� print ��ü�� ��±���� ��Ʈ�����ڸ� ���� ���� ���� ����
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

    //��ü ���� ( cout == print )
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
