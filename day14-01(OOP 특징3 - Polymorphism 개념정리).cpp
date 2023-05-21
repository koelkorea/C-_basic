// 다형성 (Polymorphism)
//  : 프로그램 언어의 각 요소들(상수, 변수, 오브젝트, 함수, 메소드 등)이 다양한 자료형(type)에 속하는 것이 허가된다는 성질

//    -> 대충 어떤 객체의 속성(변수)이나 기능(함수)이 상황에 따라 여러 가지 형태를 가질 수 있다는 내용이며, 다음과 같은 것들이 가능해짐
//        1. 자식 class는 부모에게서 물려받은 멤버함수를 override(재정의) 할 수 있음
//        2. 부모 class 객체포인터로 자식 class 객체를 통제하고, 관련 멤버함수를 호출도 가능함

//    -> 단! 1, 2의 실현을 둘 다 동시에 기능하도록 하기 위해서는 가상함수(virtual function) 개념이 필요.. 이를 가능하게 하려면 '동적 바운딩'이 가능하게 조치해야 함


//     <-> 단형성(monomorphism)
//          : 프로그램 언어의 각 요소가 한가지 형태만 가지는 성질


// 1. 오버라이드 (Override)  <-> 오버로딩(Overloading)

//   - 오버라이드 (Override)
//     : 자식class의 동명 동매개변수인 멤버함수의 재정의
//       (= 자식class의 멤버함수의 선언문 형식이 부모class의 멤버함수와 완벽히 일치하는 경우, 자식class의 멤버함수를 다른 기능으로 내용을 수정하는 것)
//           -> 보통 부모class와 개념은 비슷하나, 동작이 달라야 하는 경우에만 사용 
//     
//               ex) 사람의 '일하다' <-> 목수의 '일하다'
       
//                    class human                 { void Work(int x) { cout << "사람이 일함"; } }
//                    class salaryman : human     { void Work(int x) { cout << "월급받기 위해 일하는 직장인"; } }
//                    class carpener  : salaryman { void Work(int x) { cout << "목수는 목재를 다듬는 직장인"; } }
//                    class owner     : human     { void Work(int x) { cout << "사업 번창을 위해 일하는 사장님"; } }
     
//   - 오버로딩(Overloading)
//     : 동명의 함수지만 선언부 구성이 다른 함수들의 중복정의
//       (= 함수의 이름만 같고, 매개변수의 타입, 개수가 다르게 해서 다른 함수로 인식하게 하는 것)
       
//          ex) 사람이 '도구를 가지고' 일하다 <-> 사람이 '도구 없이' 일하다
       
//               class human { void Work(string car)                 { cout << "운송작업"; } }
//                           { void Work(string hammer)              { cout << "철거작업"; } }
//                           { void Work(string computer)            { cout << "프로그래밍 작업"; } }
//                           { void Work(string hammer, string nail) { cout << "망치질 작업"; } }


// 2. Up casting
//  : 다형성의 원리에 따라 '컨트롤 클래스 개념'을 사용한 부모 class포인터 변수를 통해, 하위 class 객체를 생성하고 그 주소값을 받아도 통제 가능하게 하는것 

//   - 컨트롤 클래스 (Control Class)
//     : 프로젝트 내부에 존재하는 상속 관계에 놓인 다양한 클래스들을 모두 총괄적 제어하기 위한, 객체지향 중 상속, 다형성 원칙에 입각한 class 개념
//        -> 이를 통해 up casting 형식으로 부모class포인터를 이용해 자식 class 객체를 생성하고 그 주소값을 받아 통제 가능함 
     
//     # (컨트롤 클래스) Up casting 형식
//        : 상위클래스명* 변수명 = new 하위 클래스
     
//     # (컨트롤 클래스) Up casting 이점
//        : [다형성]으로 요약 가능
//           1. 부모 class 객체 포인터로도 그 아래 후손 class들 기반의 객체를 모두를 가리킬 수 있음
//           2. 자식 class 객체를 추가, 삭제 할 경우에도 수정이 거의 없다
     
//     # (컨트롤 클래스) Up casting 문제점
//        : (중요!) [부모 class 객체포인터의 특징 및 한계]으로 요약 가능
//          -> 부모 class의 객체 포인터로 자식 class 객체가 위치한 메모리 위치값을 저장할 수 있지만, BUT! 부모포인터로 자식고유의 멤버에는 호출 및 접근 불가능
//              1. override된 자식 class의 멤버함수를 호출하고 싶어도 닥치고 부모것이 호출됨
//              2. 부모 class변수로 받은 생성자 주소 덕분에, delete시 부모 class 소멸자로 작동함...
//                 (= 하위class의 소멸자는 호출 X = 자식 class 멤버데이터 찌꺼기는 메모리에 남아있음 = 헐크버스터 잔해 안 치우고, 토니스타크만 퇴근한 꼴)
     
//     # (복습) class 객체포인터
//        : class 객체의 주소값을 저장하는 class 포인터 변수
//           -> 동적 할당된 메모리는 같은 class타입의 포인터만이 접근가능
     
//              ex) Class* p = new Class;
//                   -> Class* p : 객체 포인터 변수 p
//                   -> new Class : new가 Class 생성자 함수를 호출하고, 그 생성자가 객체 생성 후 멤버를 초기화하면, new연산자를 통해 힙영역에 메모리 할당 후 그 시작주소 값울 리턴


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


//   - 가상 소멸자 함수(Virtual destructor function)
//     : 가상 함수의 원리를 적용하여, up casting하여 생성된 자식 class객체를 생성당시 사용한 부모 class포인터로 지울수 있게 하는 소멸자 함수
//        -> 사용하게 될 시, 상속 관계 계층 구조상 최후손 클래스 소멸자부터 최상위 클래스 소멸자까지 모두 호출하게 되어 모두를 지우게 하는 원리
//   
//     # 가상 소멸자 함수(Virtual destructor function) 형식
//        : virtual ~클래스명() {  내용  };
//           -> 최상위 class 소멸자에만 virtual을 추가로 선언해도, 하위 class 까지 모두 가상 소멸자 적용되게 설계함


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
     
     
//   - 순수가상함수 (pure virtual function)
//     : 자식 class에서 override된 함수에 부모 class 객체포인터가 접근 및 호출하기 위한 목적으로 선언된, 선언부만 있고 정의부가 없는 가상함수(= virtual function)
//        -> (중요!) 단! 어떤 class에 순수가상함수를 선언해 두면, 그를 상속한 클래스도 반드시 순수가상함수를 최소한 선언해야 함 (= interface적 특성을 지님)
     
//     # 순수가상함수 (pure virtual function) 형식
//        : virtual void Speak() = 0
//           -> 쉽게 말해, virtual 함수에 정의부 내용이 없으면, 그게 순수가상함수
     
//     # 순수가상함수 특징
//        : 일단 선언해 두면, 자손 class에서 최소 반드시 선언은 해줘야 함 (= interface적 특성을 지님)
//           -> (중요!) 반면 일단 가상함수(virtual function)에 {}만 쳐두어도 굳이 안 그래도 됨. 
     
     
//   - 추상 클래스 (abstract class)
//     : 어렵게 생각하지 말고, 그냥 override 자식멤버를 호출할 수 있는 순수가상함수 (pure virtual function)를 멤버함수로 가지고 있는 class... 
//        -> 순수가상함수를 품는 부모 class로 이를 통해 부모는 자식 class에서 override된 함수에 부모 class 객체포인터로 접근가능함
//            -> (중요!) 목적이 목적이니 만큼, 추상클래스는 객체로 생성은 불가능함!!!