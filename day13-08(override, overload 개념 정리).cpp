// 오버라이드 (Override)
//  : 자식class의 동명 동매개변수인 멤버함수의 재정의
//    (= 자식class의 멤버함수의 선언문 형식이 부모class의 멤버함수와 완벽히 일치하는 경우, 자식class의 멤버함수를 다른 기능으로 내용을 수정하는 것)
//        -> 보통 부모class와 개념은 비슷하나, 동작이 달라야 하는 경우에만 사용 
// 
//            ex) 사람의 '일하다' <-> 목수의 '일하다'

//                 class human                 { void Work(int x) { cout << "사람이 일함"; } }
//                 class salaryman : human     { void Work(int x) { cout << "월급받기 위해 일하는 직장인"; } }
//                 class carpener  : salaryman { void Work(int x) { cout << "목수는 목재를 다듬는 직장인"; } }
//                 class owner     : human     { void Work(int x) { cout << "사업 번창을 위해 일하는 사장님"; } }

// 오버로딩(Overloading)
//  : 동명의 함수지만 선언부 구성이 다른 함수들의 중복정의
//    (= 함수의 이름만 같고, 매개변수의 타입, 개수가 다르게 해서 다른 함수로 인식하게 하는 것)

//       ex) 사람이 '도구를 가지고' 일하다 <-> 사람이 '도구 없이' 일하다

//            class human { void Work(string car)                 { cout << "운송작업"; } }
//                        { void Work(string hammer)              { cout << "철거작업"; } }
//                        { void Work(string computer)            { cout << "프로그래밍 작업"; } }
//                        { void Work(string hammer, string nail) { cout << "망치질 작업"; } }


// 상속과 override 코드 예시
#include <iostream>
using namespace std;

// A -> B -> C 흐름으로 상속이 진행되지만, 그들의 공통으로 가진 func() 멤버함수는 override되어 그 기능이 각각 다른 것 확인 가능
class A {
    public:
        void func() { cout << "A::func" << endl; }
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

    // 다형성의 원칙에 따라 ap = bp = cp = new C 가능 
    //  -> 애초에 C는 B와 A의 기반으로 작성된 최후손class이기에, A와 B가 C의 코어같은 존재 (헐크버스터 C를 움직이는 아이언맨 슈트 B, 그 슈트를 조종하는 토니스타크 A)
    C* cp = new C;
    B* bp = cp;
    A* ap = bp; 

    //객체 포인터 타입의 멤버 함수로 호출
    ap->func(); 
    bp->func();
    cp->func();

    delete ap, bp, cp;

    return 0;
}
