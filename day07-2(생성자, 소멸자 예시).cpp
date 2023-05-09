// 생성자, 소멸자 예시

// 생성자 1호출
// 생성자 2호출
// ~소멸자 2호출
// 생성자 3호출
// ~소멸자 3호출
// ~소멸자 1호출
#include <iostream>
using namespace std;

class A {
private:
    int a;
public:
    A(int _a) {
        a = _a;
        cout << "생성자 " << a << "호출\n";
    }
    ~A() {
        cout << "~소멸자 " << a << "호출\n";
    }
};

void fun() {
    A ob2(2);
}

// 객체의 유효범위는 지역변수와 같다, 블록이 끝나면 메모리 상에서 소멸됨
void main() {

    // 클래스 A의 기반이 된 A를 생성자 함수를 통해 생성
    A ob1(1);

    // 
    fun();


    A ob3(3);
}


