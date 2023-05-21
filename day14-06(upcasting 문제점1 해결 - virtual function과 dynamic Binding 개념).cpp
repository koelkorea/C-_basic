// 3. 가상함수 (virtual function)

//   - 가상함수 (virtual function)
//     : 부모 class에서 선언되지만, 하위 class에서 override 하여 호출할 수 있는 멤버함수
//        -> 이를 통해 부모 class 객체포인터로 선언하고, 자식 class 객체를 할당하는 up casting을 하는 경우에 동명이함수인 override된 자식class의 멤버함수에 접근 및 호출 가능  
//            -> (중요) C++ 은 기본적으로 정적 바인딩으로 적용되고, [동적 바인딩(Dynamic Binding)]을 수행 하려면 'virtual' 예약어를 사용하게 끔 설계

//     # 가상함수 (virtual function) 형식
//        : virtual 타입명 멤버함수명(parameters...) {  정의부 내용;  }

//     # 가상함수 작동 개념 (from 동적 바인딩(Dynamic Binding) )
//        : 객체의 멤버함수 호출시, 그 함수 앞에 virtual 이라는 예약어가 붙어 있는 경우?
//           -> 해당 class 객체 포인터가 가리키고 있는 게, 어떤 class를 기반으로 하는지의 맥락을 확인하고 어떤 class의 멤버함수를 호출할지 결정함
//              -> (중요) 이를 통해, 상위 class의 원형 멤버함수에 virtual을 선언해 둘시, upCasting하여 override 된 자식 class의 멤버함수에 가상함수 테이블을 통해 접근이 쌉가능함
//                  -> 가상함수 테이블(Virtual Function Table, VTable) 참고..


//   - 가상함수 테이블(Virtual Function Table, VTable)
//    : 가상함수를 가지는 class의 객체가 생성될 시, 그 class의 가상함수들에 대한 포인터들을 저장하고 있는 테이블
//       -> 이 테이블은 각 class 타입에 해당하는 가상함수들에 대한 포인터를 저장
//          -> 이를 통해 런타임에서 컨트롤 클래스 개념을 사용한 upCasting을 활용할 시, 실제 class 객체의 타입에 맞는 override된 올바른 자식 class의 가상함수를 호출하게 해줌
//             -> 바인딩 (Binding)에서 동적 바인딩(Dynamic Binding) 개념 참고

//     # (중요) 가상함수 테이블 이점
//        : [다형성] 구현으로 요약 가능 
//          1. 동적 바인딩 가능
//          2. upcasting 개념을 코드에 사용하여, 부모 class 포인터를 통해 자식 class 객체를 생성한 뒤, 호환성 문제없이 코드의 유지보수가 쉬워짐


//   - 바인딩 (Binding)
//     : (중요) 프로그램 실행 중 어떤 함수를 호출할 시 어떻게 해당 함수의 정의부를 연결해서 실행해야 하는지에 대한 방법론 (mechanism)

//       1. 정적 바인딩(Static Binding)
//           : [컴파일 과정] 에서 함수를 호출하는 코드 발견시, 그 호출하는 객체의 class나 포인터의 타입이 무엇인지를 보고 결정함
//              -> 컴파일 과정에서 함수와 관련된 모든게 결정으로 요약 가능
//                  -> 속도 fast + 타입 error 문제 조기 발견 가능
//                     -> But! 컴파일 과정에서 결정이 되고 그 이후 변경이 불가능 (= 내용 변경되면 그냥 코드를 다 바꿔야 함)
//                         -> 유지보수가 ㅈ같다 = 동적 바인딩(Dynamic Binding)의 등장 계기

//       2. 동적 바인딩(Dynamic Binding)
//           : [프로그램 실행 중] 함수를 호출할 때, class 객체의 가상함수 테이블(Virtual Function Table, VTable)을 사용하여 맥락에 맞게 필요한 class의 멤버함수를 유연하게 호출
//               -> 이를 통해, 컨트롤 클래스 개념을 통해 upcasting을 해서 자식 class 객체의 override된 멤버함수에 접근하라고 하면, 컴퓨터는 찰떡같이 그 자식class의 멤버함수에 접근하게 함
//                   -> (중요!) 유도리가 조금이라도 어긋나게 되어 예상치 못한 class 타입으로 인해 안정성이 저하됨


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