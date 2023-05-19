// Up casting
//  : 다형성의 원리에 따라 '컨트롤 클래스 개념'을 사용한 부모 class포인터 변수를 통해, 하위 class 객체를 생성하고 그 주소값을 받아도 통제 가능하게 하는것 

// 컨트롤 클래스 (Control Class)
//  : 프로젝트 내부에 존재하는 상속 관계에 놓인 다양한 클래스들을 모두 총괄적 제어하기 위한, 객체지향 중 상속, 다형성 원칙에 입각한 class 개념
//     -> 이를 통해 up casting 형식으로 부모class포인터를 이용해 자식 class 객체를 생성하고 그 주소값을 받아 통제 가능함 

//   # (컨트롤 클래스) Up casting 형식
//      : 상위클래스명* 변수명 = new 하위 클래스

//   # (컨트롤 클래스) Up casting 이점
//      : [다형성]으로 요약 가능
//         1. 부모 class 객체 포인터로도 그 아래 후손 class들 기반의 객체를 모두를 가리킬 수 있음
//         2. 자식 class 객체를 추가, 삭제 할 경우에도 수정이 거의 없다

//   # (컨트롤 클래스) Up casting 문제점
//      : (중요!) [부모 class 객체포인터의 특징 및 한계]으로 요약 가능
//        -> 부모 class의 객체 포인터로 자식 class 객체가 위치한 메모리 위치값을 저장할 수 있지만, BUT! 부모포인터로 자식고유의 멤버에는 호출 및 접근 불가능
//            1. override된 자식 class의 멤버함수를 호출하고 싶어도 닥치고 부모것이 호출됨
//            2. 부모 class변수로 받은 생성자 주소 덕분에, delete시 부모 class 소멸자로 작동함...
//               (= 하위class의 소멸자는 호출 X = 자식 class 멤버데이터 찌꺼기는 메모리에 남아있음 = 헐크버스터 잔해 안 치우고, 토니스타크만 퇴근한 꼴)

//   # (복습) class 객체포인터
//      : class 객체의 주소값을 저장하는 class 포인터 변수
//         -> 동적 할당된 메모리는 같은 class타입의 포인터만이 접근가능

//            ex) Class* p = new Class;
//                 -> Class* p : 객체 포인터 변수 p
//                 -> new Class : new가 Class 생성자 함수를 호출하고, 그 생성자가 객체 생성 후 멤버를 초기화하면, new연산자를 통해 힙영역에 메모리 할당 후 그 시작주소 값울 리턴

// 컨트롤 클래스를 통한 Up casting 문제점1
//  -> override된 자식 class의 멤버함수를 호출하고 싶어도, 자신의 멤버함수 밖에 접근하지 못하는 컨트롤 클래스인 부모 class포인터..
#include <iostream>
using namespace std;

class A {

    public:
        void func1() { cout << "call : A\n"; }
};

class B :public A {

    public:
        void func2() { cout << "call : B\n"; }
};

class C :public B {

    public:
        void func3() { cout << "call : C\n"; }
};

int main() {

    // 부모 CLASS포인터 A를 통해, 자식인 B, C의 주소도 저장 가능
    A* ap = new A;
    A* bp = new B;
    A* cp = new C;

    // A클래스 자신의 멤버함수에는 접근 가능함
    ap->func1();

    // 단! 부모 class 포인터변수로는 자식 class를 향한 멤버 접근 불가
    bp->func1();
    cp->func1();

    delete ap, bp, cp;

    return 0;
}
