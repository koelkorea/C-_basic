
// 동적할당 pointer 변수를 가지는 class와 생성자, 소멸자 예시
#include <iostream>
using namespace std;

class A {

    private:

        int* p;

    public:

        A(int _a) {
            p = new int;
            *p = _a;
            cout << "생성자 " << *p << "호출\n";
        }

        ~A() {
            cout << "~소멸자 " << *p << "호출\n";
            delete p;
        }
};

void fun() {
    A ob2(2);
}

// 객체의 유효범위는 지역변수와 같다, 블록이 끝나면 메모리 상에서 소멸됨
void main() {

    A ob1(1);
    fun();
    A ob3(3);
}
