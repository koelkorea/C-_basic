// 3. 가상함수 (virtual function)

//   - 가상함수 (virtual function)
//     : 부모 class에서 선언된 함수지만, 그를 기점으로 상속받는 하위 class의 override된 함수들까지 호출할 수 있도록 하는 종류의 함수
//       (= 가상함수을 기반으로 상속을 기반으로 다형성을 가진 class 객체들은 컨트롤클래스에서 완전히 통제 가능하게 됨)
//           -> 가상함수를 통해 부모 class 객체포인터는 자식 class 객체에 접근하는 것 이외에, 자식 class 객체에 위치한 동명이함수인 override된 자식class의 멤버함수에 접근 및 호출까지 가능함
//              -> (중요) C++ 은 기본적으로 정적 바인딩으로 적용되고, [동적 바인딩(Dynamic Binding)]을 수행 하려면 'virtual' 예약어를 사용하게 끔 설계

//      # 가상함수 (virtual function) 형식
//         : virtual 타입명 멤버함수명(parameters...) {  정의부 내용;  }

//      # 가상함수 작동 개념 (from 동적 바인딩(Dynamic Binding) )
//         : 어떤 class 객체의 멤버함수 호출시, 그 함수 앞에 virtual 이라는 예약어가 붙어 있는 경우?
//            -> 해당 class 객체 포인터의 기반 class를 기준으로, 모든 후손 class의 해당 멤버함수를 호출할 주소값이 어딘지를 싹다 뒤져서, class별로 멤버함수의 위치를 포인터로 저장하고 table 형식으로 정리함
//               -> 해당 class 객체 포인터가 가리키고 있는 게, 계보 내의 어떤 class를 기반으로 하는지의 맥락을 확인하여 table의 내용을 참고해서 어떤 class의 멤버함수를 호출할지 결정함
//                   -> (중요) 이를 통해, 상위 class의 원형 멤버함수에 virtual을 선언해 둘시, 그 상위 class포인터를 통해 override 된 자식 class의 멤버함수의 호출이 쌉가능함
//                        -> 가상함수 테이블(Virtual Function Table, VTable) 참고..

//      # 가상함수 사용 tip
//         : override가 빈번한 멤버함수는 선조고 후손이고 할거없이 모두 virtual 떡칠을 하는게 좋음
//            -> 이유 1) 어떤 class를 선언해서, 후손 class 객체의 멤버를 호출할지 모르기 때문
//               이유 2) 상속 계보가 길어지면, 어떤 멤버가 virtual인지 까먹는 지경이 되서 일일히 찾아봐야 하기 때문임.. (= virtual 떡칠을 하면, 그냥 한 눈에 분간이 감)


//   - 가상함수 테이블(Virtual Function Table, VTable)
//     : 각 class 별로 보유하고 있는 가상함수들을 정리하여, 해당 클래스의 가상함수들 각각을 호출할 위치가 어딘지에 대한 포인터 값들을 저장하고 있는 테이블
//        -> 가상함수 테이블은 각 class 타입에 해당하는 가상함수들에 대한 포인터를 저장
//           -> 런타임에서 컨트롤 클래스 개념을 사용한 upCasting을 활용할 시, 부모 class객체포인터를 역참조한 멤버함수()로 호출해도 부모class 객체포인터가 가르키는 실제 class 객체의 멤버함수를 찾아내 호출함
//              (= 이를 통해 override된 올바른 자식 class의 가상함수를 부모 class객체 포인터를 통해서도 호출이 가능함)

//      # (중요) 가상함수 테이블 이점
//         : [다형성] 구현으로 요약 가능 
//           1. 동적 바인딩 가능
//               -> 바인딩(Binding)에서 동적 바인딩(Dynamic Binding) 개념 참고
//           2. upcasting 개념을 코드에 사용하여, 부모 class 포인터를 통해 자식 class 객체를 생성한 뒤, 호환성 문제없이 코드의 유지보수가 쉬워짐


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