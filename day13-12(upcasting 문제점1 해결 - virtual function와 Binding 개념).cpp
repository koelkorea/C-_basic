// 가상함수 (virtual function)
// 
//객체 포인터가 가리키는 객체의 클래스를 보고 호출할 함수 결정
//최상위 클래스에 virtual 선언시 하위 클래스 모두 가상함수 적용
//<객체 포인터 타입과 상관없이!!>

//형식 : virtual 반환 타입 함수명(매개변수) { 정의부 …; }

// 바인딩 (Binding)
//  : 함수 호출과 정의를 연결하는 방법

//   # 정적 바인딩(Static Binding)

//객체나 포인터의 타입을 보고 호출할 함수를 결정한다.
//컴파일 과정에서 타입에 대한 정보, 호출될 함수가 결정. (속도가 빠르다.)
//타입 에러로 인한 문제를 조기에 발견할 수 있어 안정적이다.
//컴파일 과정에서 결정이 되고 그 이후 변경이 불가능 

//   # 동적 바인딩(Dynamic Binding)
//객체의 가상함수 Table을 사용한다.
//프로그램 실행 중 필요한 객체의 함수를 호출. (객체의 타입에 유연성)
//변수의 예상치 못한 타입으로 인해 안정성이 저하된다.

//C++ 은 기본적으로 정적 바인딩으로 적용되고,
//동적 바인딩을 수행 하려면 'virtual'을 사용.

// day13-09 코드 수정
//  -> 부모 class포인터의 자식 멤버 접근을 가능하게 하는 virtual 예제
#include <iostream>
using namespace std;

class A {
    public:
        // override 대상 함수의 최상위 선조의 멤버함수에 virtual 예약어를 붙어주면, 접근 가능
        virtual void func() { cout << "A::func" << endl; }
        // void func() { cout << "A::func" << endl; }
    };

class B : public A {
    public:
        void func() { cout << "B::func" << endl; }
    };

class C : public B {
    public:
        void func() { cout << "C::func" << endl; }
    };

int main() {

    // 부모 CLASS포인터 A를 통해, 자식인 B, C의 주소도 저장 가능
    C* cp = new C;
    B* bp = cp;
    A* ap = bp; 

    // (중요) virtual 예약어를 통해, 객체 포인터가 가리키는 클래스의 멤버 함수로 호출
    ap->func();
    bp->func();
    cp->func();

    delete cp;

    return 0;
}
