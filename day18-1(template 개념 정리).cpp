﻿// 템플릿(Template)
//  : function이나 class의 수많은 overloading 버전들을 개별적으로 작성을 하기 귀찮기에, 포괄적으로 그들의 parameter로 범용적인 자료형이 들어간다고 가정하고 작성한 일종의 funtcion들을 작성하는 공용 양식
//      -> (중요) 컴파일러에 의해 컴파일 과정에서 템플릿을 동반하여 선언된 function or class를 호출하는 코드가 발견되는 경우, 그들이 사용한 자료형에 해당하는 overloading 버전들을 모두 자동으로 쭉 생성해 줌 (= 암시적 구체화)
//          -> 컴파일 단계에서 function이나 class멤버들을 직접 생성하기에, function나 class에 템플릿을 많이 적용하는 만큼 쓰면 컴파일 속도가 느려짐
//              <-> 컴파일 단계에서 코드를 추가하는 것이기에, 그 이후 프로그램 처리 속도랑은 관계 X


//   # 템플릿의 탄생 배경
//      (기) : 객체지향 프로그래밍(OOP) 패러다임이 대세가 되어, class 객체 자료형을 작성하는 방식에 원칙과 표준이 생김 (표준화, 상속, 다형성, 캡슐화)
//      (승) : 그 중 다형성의 원칙에 따라, 동명의 함수지만 parameter의 종류나 개수가 완전히 같지 않으면 다른 함수로 취급함으로서, 같은 함수를 다양한 경우에서 사용가능하게 해주는 overloading이 널리 쓰이기 시작함
//      (전) : overloading 함수들을 작성하다 보니, parameter에 따른 경우의 수가 뒤지게 많다는 점과 그렇게 작성된 함수들이 정작 내용은 자료형만 바꿔 적용하면 전혀 다른게 없는 경우가 많다는 점을 발견
//      (결) : 일반화 프로그래밍(Generic Programming) 패러다임적 관점을 받아들여, 1번 작성하고 나면 비슷한 내용의 overloading 함수들을 포괄할 수 있는 일타쌍피를 노릴 수 있는 양식을 만들고자 하는 움직임 발생
//               -> 결론 : 그렇게 만들어진 function 작성에 편의성을 제공하는 양식이 '템플릿(Template)' 되시겠다!


//   # (배경지식) 프로그래밍 패러다임
//      : 프로그래밍을 하는데 있어 어떤 가치나 철학에 기준에 둔 방법론을 제시하는 가치관이자 트랜드
// 
//       1. 객체지향 프로그래밍(Objective Oriented Programming)
//           : 데이터로 표현할 어떤 추상적인 대상을 구체적으로 고유 속성과 기능을 가진 객체로 정의하는 식으로 가정한 뒤
//              -> 그렇게 다양한 객체들을 최대한 공통된 속성이나 기능을 가진 카테고리로 묶어서 계보화 시켜 표준화(속성, 기능)한 뒤
//                 -> 검증된 코드의 재사용을 통해 유지보수를 최적화하는데 집중한 [데이터 중점] 방법론
//                     -> (단점) 다양한 자료형 덕분에 overloading 문제 같이 범용코드 짜기가 드럽게 힘듦 + 크고 복잡한 상속 계보가 꼬이면 고치기 어렵다는 단점이 있음
//
//       2. 일반화 프로그래밍(Generic Programming)
//           : 최대한 다양한 자료형을 모두 포괄적으로 처리하는 방향으로 코드를 설계해야 한다는 [알고리즘 중점] 방법론
//              -> 템플릿(Template)은 이러한 일반화 프로그래밍의 사상적 영향을 받아 탄생한 결과물


//   # (중요!) 템플릿 작동하는 과정
//      1. 템플릿 정의
//          : 템플릿 양식을 적용하기 원하는 class나 function 앞에 template <typename T1 ...>을 작성시, 'T1 ~ TN'은 해당 함수나, 클래스의 생성자 및 멤버함수 선언에 사용되는 parameter 타입들의 갯수와 실제 선언부에 들어가는 그들의 자료형이 위치하는 부분에 해당함
//            (= 어디 위에다 template을 작성하냐? 에 따라 템플릿의 종류가 'function template' or 'class template' 나뉨) 

//            - typename타입
//               : 하단에 선언될 함수나, 클래스의 생성자 및 멤버함수의 선언부의 parameter들의 자료형 그 자체를 의미 (과거에는 보통 class가 주된 자료형이라 template <class Type>으로 적었음)
//                  -> 1번째 <>안의 구문 의미
//                      : <typename T1, ... >의 의미는 일종의 typedef와 같은 의미로 T1은 typename로 치환되는 관계임을 의미 

//            - (중요) 템플릿 정의 형식 (class, function 전부 공용.. 단지 어디 위에 적냐? 가 종류를 가름 문제)
//               1. 함수 템플릿(function Template)
//                   : template <typename T1, ... > function명(T1 변수명, ...) { 내용 }
//                      -> (1번째 <> 생략시) template function명(T1 변수명, ...) { 내용 } 를 의미

//               2. 클래스 템플릿(class Template)
//                   : template <typename T1, ... > class명(T1 변수명, ...) { 멤버변수; 멤버함수; } 
//                      -> (1번째 <> 생략시) template class명(T1 변수명, ...) { 멤버변수; 멤버함수; } 를 의미

//            - 템플릿 정의시 특징
//               1. 템플릿을 적을 class나 function의 선언에 쓰이는 <> 안에 위치할 parameter의 자료형 선언부 위치에는 템플릿에 적은 '템플릿 parameter명'을 써야 함
//               2. <>안의 class나 function의 parameter의 자료형을 지칭하는, '템플릿 parameter명'은 일반적으로 템플릿 기호 T로 표기
//                   -> 이를 class나 function의 선언부에 자료형 위치에 사용
//               3. (중요) template는 1개당 1개의 함수나 class를 담당함 (= 템플릿 선언부 하나로 모든 function나 class를 다 통제할 수 없음) 
//               4. 템플릿 선언시 <> 안에 작성하는 '템플릿 매개변수(parameter)'의 수는 복수 개도 상관없음
//                   -> (중요) 심지어 rest parameter 개념으로 템플릿 파라미터 팩(template parameter pack)도 사용 가능
//               5. 템플릿 정의시 function명 <T1...> { 내용 }, class명 <T1...> { 멤버변수; 멤버함수; } 처럼, <T1...>가 생략됨
//               6. 템플릿을 통해 class나 function의 자료형 선언을 쉽게 통제할 수 있기 때문에, C++을 포함한 각종 언어의 기본 라이브러리에도 많이 쓰임  (= 당연히 STL에서도 적용됨)


//            - 템플릿의 종류
//               1. 함수 템플릿(function Template)
//                  : 한번 작성하면 다양한 자료 타입을 적용할 수 있는 범용적인 function을 제작하고자, 템플릿 형식에 선언된 typename 변수를  function 선언부, 정의부에 사용해 작성한 경우

//               2. 클래스 템플릿(class Template)
//                  : 한번 작성하면 다양한 자료 타입을 적용할 수 있는 범용적인 class을 제작하고자, 템플릿 형식에 선언된 typename 변수를 class 선언부의 멤버변수나 멤버함수, 생성자함수에 사용하여 작성한 경우
//                     -> class 템플릿을 사용하여 작성한 class의 경우, class를 생성할때는 <>를 써도 되지만, 생성한 이후 멤버함수를 호출할때는 이미 멤버변수의 자료형이 정해졌기에 <>를 쓰지 않음

//            - 템플릿 parameter (템플릿 정의시에 보이는 1번째 <>)
//               : 템플릿 정의시 1번째 <> 안에 들어가는 'typename T1 ...'를 '템플릿 parameter' 라고 함
//                  -> 특징
//                      1. (중요!) <> 안에 적힌 typename타입 변수 T1 ~ TN은 실제 함수나, 클래스의 생성자 및 멤버함수의 선언부의 parameter들중 가변 자료형이 기입하는 부분을 지칭함
//                      2. (중요!) 해당 함수나, 클래스의 생성자 및 멤버함수 선언부의 각 parameter가 독립적으로 기능하는 경우, 그만큼 많은 템플릿 parameter의 typename 변수가 필요함
//                      3. rest parameter 형식의 템플릿 파라미터 팩(template parameter pack) 작성 또한 가능
//                          -> (응용!) 재귀함수를 통해 함수에 적용될 parameter를 하나씩 줄여나가기도 가능함 (이 경우 재귀로 돌릴 parameter와 실제 함수 내용에 쓸 parameter의 변수명을 구분해서 작성해야 함

//                      ex1) [가변 자료형이 1가지 뿐일 템플릿 작성 예시]
			            
//                           template <typename T> void swap(T a, T b) { 내용 };             <- template <typename T> void swap<T>(T a, T b); 가 전체코드이며 <T>가 생략됨
//                            -> 만약 a, b의 parameter의 자료형을 독립적으로 지정하고 싶다면?
//                                -> template <typename T1, typename T2> void swap(T1 a, T2 b); 이렇게 템플릿 parameter 변수를 따로 지정해주고, 함수나 클래스의 선언부에 적히는 parameter의 자료형으로 각각 선언해야 함
			            
//                      ex2) [가변 자료형이 복수 가지인 템플릿 작성 예시]
			            
//                           template <typename T1, typename T2> void swap(T1 a, T2 b) { 내용 };
//                           int a, string b                                                  <- a, b가 같은 타입의 자료형이 아니기에, 각각의 자료형을 따로 지정해줄 T1, T2가 따로 존재하게 됨
//                           swap(a, b);                                                      <- swap<int, string>(a, b); 가 전체코드이며 <int, string>가 생략됨

//                      ex3) [가변 자료형의 갯수가 정해지지 않은 템플릿 파라미터 팩(template parameter pack) 적용 템플릿 작성 예시]

//                           template <typename ... T1> void print(T1 ... args) { 내용 };     <- rest paramter 형식 적용
//                           print(1, 2, "Hello", 'a');                                       <- print<int, int, string, int>(1, 2, "Hello", 'a'); 가 전체코드이며 <int, int, string, int>가 생략됨
  

//      2.1 (핵심!) 템플릿 인스턴스화 = 암시적 구체화 (implicit Instantiation)
//          : 작성된 템플릿을 참고, 컴파일 시점에서 컴파일러는 그 곳의 function or class를 호출 및 생성하는 코드들을 색출한 뒤, 그들이 사용한 자료형에 해당하는 overloading 버전들을 모두 자동으로 쭉 생성해 줌 
//             -> 컴파일 시점에서 만들어진 템플릿을 참고하여, 호출 및 생성하는 코드의 자료형에 맞는 구조로 function이나 class를 구체화시켜 작성하여 대응한다고 생각하면 편함
//                 -> 미리 class나 function을 작성해둔게 아니고, 컴파일 단계에서 템플릿 리스트에 있는 function나 class들을 사용하는 자료형에 한해서만 overloading 버전들로 모두 다 다시 쭉 적어내는 셈
//                    (= 당연히 컴파일 시간이 더 걸릴 수 밖에 없음)

//            - (중요) 템플릿 호출 형식 (선언부는 상단 참고)
//               1. 함수 템플릿(function Template)
//                   : function명 <실제typename1, ...> (parameter1, ....);

//                     ex) template <typename T> void swap(T a, T b);   <- (함수 템플릿 정의) template <typename T> void swap<T>(T a, T b); 가 전체코드이며 <T>가 생략됨
//                         int a, b;
//                         swap(a, b);                                  <- (함수 템플릿 호출) swap<int>(a, b); 가 전체코드이며 <int>가 생략됨
//                         void swap(int a, int b)                      <- int를 paramter로 둔 swap 호출이 발견되면, void swap(T a, T b)의 paramter 자료형을 int로 구체화시켜 override한 함수 코드를 생성해 주는게 암시적 구체화

//               2. 클래스 템플릿(class Template)
//                   : class명 <실제typename1, ...> 객체명 = new class명(parameter1, ....);
//                      -> (중요) class 생성자와 멤버함수의 경우 parameter로 들어가는 변수명이 class 멤버변수와 같을수가 없으므로, 선언만 해두고 정의부는 다른 함수 템플릿으로 뺴서 제작함

//                     ex) template <typename T> class Dummy(T a);                            <- (클래스 템플릿 정의) template <typename T> class Dummy<T>(T a); 가 전체코드이며 <T>가 생략됨
//                         template <typename T> T Dummy<T>::SetA(T a1) { a = a1};            <- (함수 템플릿 정의) 멤버함수 SetA()는 파라미터의 변수명이 클래스의 멤버변수와 달라야 하므로 따로 함수 템플릿으로 정의함

//                         Dummy d1(10);                                                      <- (생성자 함수를 통한 클래스 템플릿 호출) Dummy d1 <int>(10); 가 전체코드이며 템플릿 parameter를 투입하는 <int>가 코드에서 생략됨
//                                                                                                 -> int를 paramter로 둔 swap 호출이 발견되었기에 Dummy생성자 함수의 paramter 자료형을 int로 구체화시켜 override한 함수 코드를 생성해 주는게 암시적 구체화
//                         d1.SetA();                                                         <- (템플릿이 존재하는 클래스의 멤버함수 호출) 

//            - 템플릿 호출시 특징
//               1. 템플릿 선언시 <실제typename1, ...> 부분은 생략해도 상관없음 
//                  (= 어차피 컴파일러가 호출된 코드를 읽어서 알아서 처리하기 때문)

//               2. (중요) class 생성자와 멤버함수의 경우 parameter로 들어가는 변수명이 class 멤버변수와 같을수가 없으므로, 선언만 해두고 정의부는 다른 함수 템플릿으로 뺴서 제작함

//               3. 실질적으로 사용하는 빈도가 높은 라이브러리를 다루는 프로그래머가 가장 많이 쓸 템플릿 기능
//                   -> 주로 특정한 자료형 형식만을 input받기 위한 객체 배열이나 컨테이너 클래스에서 사용

//                      ex) 컨테이너클래스명 <value자료형> 객체명 = new 컨테이너클래스명(); 형식
//                           : <value자료형>의 의미 = 특정 class 형식을 컨테이너 class 객체를 이루는 요소로 사용하기 위해 입력 자료형을 지정하는 역할을 함 
//                              -> 쉽게 말해, C언어에서 컨테이너 class 구현할때, node나 list 내부의 value값의 타입을 'typedef value자료형 컨테이너명_element;' 식으로 구현한걸 정식으로 기능화
//                                 (= 이를 통해 동일한 코드를 다양한 데이터 타입에 대해 재사용하기 쉬워진 효과를 같는 것 또한 동일하나, 코드의 수정이 필요한 typedef보다 쓰기도 쉬움)


//      2.2 명시적 구체화(explicit instantiation)
//          : 사용자가 직접 원하는 function이나 class에다 template 키워드와 함께 템플릿 parameter를 명시하는 [(템플릿) 특수화(specialization)]를 통해 원하는 특정 자료형에 대한 인스턴스화를 시키라고 수동 지시하는 행위 
//             <-> 호출, 생성이 확정된 function 템플릿, class 템플릿들에 한해서만, 사용하는 자료형에 해당하는 overloading 버전들만 모두 자동으로 쭉 생성해주는 암시적 구체화 (implicit Instantiation)와 다름

//            ex) template <typename T> void swap(T a, T b);
//                template void swap<int>(int a, int b);       <- 프로그래머가 직접 (템플릿) 특수화(specialization) 코드를 입력하여, swap함수를 int 자료형을 받는 형태로 내용을 구체화를 시키라고 수동 지시 
//                                                                  -> 반드시 특수화(specialization)에 대해서 공부할것

//      3. (템플릿) 구체화된 코드 생성
//          : 컴파일러가 2번의 과정을 통해 생성된 인스턴스의 구체화된 코드를 통해, 실제 데이터 타입에 대한 작업을 수행하는 함수, 클래스 또는 객체를 생성함 

//      4. 컴파일 및 링크
//          :  컴파일러는 템플릿을 사용하여 생성된 구체화된 코드를 컴파일하고, 필요한 경우 링크 단계에서 이 코드를 최종 실행 파일에 연결


//   # 템플릿의 특징
//     1. 컴파일 단계에서 function이나 class멤버들을 직접 생성하기에, function나 class에 템플릿을 많이 적용하는 만큼 쓰면 컴파일 속도가 느려짐
//     2. 컴파일 단계에서 코드를 추가하는 것이기에, 그 이후 프로그램 처리 속도랑은 관계 X
//     3. JAVA에서는 이를 제너릭스(generics)라고 부름
//         -> 제너릭스(generics) = 템플릿 + 컴파일 과정에서 객체 자료형 타입 check 추가
//     4. (장점) 수많은 경우의 수에 맞춰 적어야 할 overloading 버전 작성을 일괄적으로 처리하는거라, 제대로만 만들어 두면 편의성이나 코드 완성도나 전부 높아질 수 밖에 없음
//     5. (단점) 포괄적인 함수나 클래스의 정의부만 양식으로 적어주는거라 예측하지 못한 자료형으로 인해 안정성은 떨어질 수 밖에 없음
//     6. (중요!) 템플릿이 호출될 시 function이나 class나 어떤 종류라도 전부 호출 될때, '함수명<호출에 쓰인 parameter 자료형>(parameter1,... )' 에서 <호출에 쓰인 parameter 자료형>을 수행함 (= 없으면 컴파일러가 만들어줌)


//   # 안정성이 부족함에도 템플릿 사용 이유?
//      : 포괄적인 함수나 클래스의 정의부만 양식으로 적어주는거라 예측하지 못한 자료형으로 인해 안정성은 떨어질 수 밖에 없다? 팩트임
//         -> BUT! 진짜 제대로 만들어만 놓는다면? 코드의 완성도가 높아지고, 코드를 사용하기도 쉬운지라 유지보수 생산성 효율도 증가하기 때문 
//            -> 이러한 장점이 STL(Standard Template Library)처럼 성능과 안정성이 검증된 라이브러리와 함께면 시너지가 대폭 증가함
//               (= 만들기는 어려운데, 일단 제대로만 만들어서 안정성이 검증되면, 그떄부터는 그냥 가져다 쓰면 된다는 의미)


//   # 템플릿 사용시 주의사항
//      1. 가능한 다양한 자료형에 대해 포괄적으로 적용할 수 있도록 함수 내용이 범용적인 자료형을 포괄할 수 있도록 설계해야 함
//      2. 템플릿의 범용 자료형을 의미하는 typename 자료형을 템플릿 기호로 표기시에는 일반적으로 T를 사용
//      3. 컴파일 단계에서 만들어지기 때문에, 컴파일 시간이 늘어나게 되는건 감안해야 함
//      4. 함수의 호출 구문으로 parameter의 자료형을 확인하고 자료형 별로 함수를 제작해야 함 (오버로딩)
//      5. (중요!) 함수 템플릿이나 class 템플릿이나 호출 및 생성시 <>안에 자료형 정보를 생략하건 생략하지 않건 그 의미하는 바에 차이는 없으나(컴파일 과정에서 처리), 가급적이면 자료형 정보를 명시하는 것이 프로그래머 입장에서 편함
//          -> 특수화시에 override 된 함수가 각각 다른 내용을 가질 경우 이를 구분하는데 유용
//      6. (중요) class 생성자와 멤버함수의 경우 parameter로 들어가는 변수명이 class 멤버변수와 같을수가 없으므로, 선언만 해두고 정의부는 다른 함수 템플릿으로 뺴서 제작함


// (템플릭) 특수화 (specialization)
//  : 기존에 템플릿이 작성된 함수(멤버함수, 생성자 포함)를 호출할때 특정 자료형을 parameter로 가져오는 경우에는 '전혀 다른 알고리즘으로 처리(= override)'하라는 개념
//     -> 쉽게 말해, 작성된 함수 템플릿이나 클래스 템플릿에 대한 특정 자료형에 한해 예외 처리 override를 하는 것을 의미
//        -> 템플릿의 명시적 구체화(explicit instantiation)를 작성할 때 템플릿 특수화 문법을 사용함


//   # 특수화 된 템플릿 정의 형식
//      : template<> 자료형 함수명 <typename>(parameters...) { 함수 정의 }
//         -> 애초에 모든 종류의 함수만이 대상

//         ex) template <typename T> void swap(T a, T b);    <- 기존 입력된 함수 템플릿 
//             template void swap<int>(int a, int b);        <- 프로그래머가 직접 (템플릿) 특수화(specialization) 코드를 입력하여, swap함수를 int 자료형을 받는 형태로 내용을 구체화를 시키라고 수동 지시 


//   # (중요) 특수화 템플릿 종류별 호출 및 생성하는 형식
//      : 기존의 템플릿 작성과 유사하지만, 단지 특수화 템플릿에 선언된 function여서 특정한 자료형만 parameter로 들어가는 경우 override된 내용을 출력함 (= class 생성자 함수는 고려하지 않음)
//          -> (중요) 특수화 템플릿도 기존 템플릿 호출 및 생성과 마찬가지로 <>안에 자료형 정보를 생략하건 생략하지 않건 그 의미하는 바에 차이는 없음
//             -> BUT! <>안의 내용을 적는 것이 특수화된 템플릿 함수나 클래스임을 명확히 하는 방법이기에 적는걸 추천함


//   # (중요) 함수의 특징
//      1. 템플릿이 아닌 function, 함수 템플릿, 명시적 특수화 함수 템플릿, 3가지 전부 같은 function명이란 가정하여 override가 가능함
//      2. 단! 실행의 우선순위는 다음과 같음 
//          : 일반함수 > 템플릿 특수화 함수 > 템플릿 함수

//   # 특수화( specialization) 사용시 주의사항
//      1. (중요) class 생성자 함수는 사용이 불가능 함 (= 생성자 함수는 typename 자료형을 쓰는 템플릿에서 내용을 바꾸는 override가 불가능 함)
//          -> class 멤버함수는 특수화가 가능함
//              -> 단! 부분 특수화는 불가능

//      2. (중요) 특수화 작성 시, template<> 선언시 <>는 생략 가능



// (템플릭) 부분 특수화(Partial specialization)
//  : 특수화 된 템플릿 parameter가 typename이외에 다른 자료형이 존재하여, 2개 이상의 자료형이 선언된 경우 템플릿 parameter 중 일부만 특수화 함
//     -> 부분 특수화를 많이 할 경우 절대적 소스코드가 늘어날 수는 있지만, 결국 목적코드로 생성되는 기계어 코드의 양은 같음

//         ex) template <typename T, int count> void display(T value) {  내용  }
//              -> [일반 function]을 대상으로, 특수화 함수 템플릿의 <>안의 템플릿 parameter가 'typename + 일반 자료형'으로 구성되어 있는 경우


//   # 부분 특수화 템플릿 선언 형식
//      : template 자료형 함수명 <typename T, ... , 자료형1 변수명1, .... >(T value...) { 함수 정의 }

//         ex) template <typename T> void display(T value);                            <- 기존 입력된 함수 템플릿 
//             template <typename T, int count> void display(T value) {  내용  }       <- 부분 특수화 함수 템플릭 선언


//   # (중요) 특수화 템플릿 종류별 호출 및 생성하는 형식
//      : 부분 특수화 된 함수 템플릿을 선언하면, 기존의 함수 템플릿 호출과 비슷하나, 반드시 호출시 선언된 [템플릿 parameter]의 갯수와 자료형에 맞는 데이터를 <>안에 입력해야 함
//          -> (중요) 특수화 템플릿도 기존 템플릿 호출 및 생성과 마찬가지로 <>안에 자료형 정보를 생략하건 생략하지 않건 그 의미하는 바에 차이는 없음

//         ex) display <char, 10>('A');                                                 <- 호출시 <char, 10>와 같은 부분을 선언부의 <typename T, int count>와 맞게 적어줘야 함


//   # 부분 특수화(Partial specialization) 사용시 주의사항
//      1. (중요!) 오로지 [일반 function]에 한해서만, 부분 특수화 템플릿은 사용 가능함 
//                (= class와 연관된 멤버함수나 생성자 함수나 부분 특수화 사용 X)

//      2. (중요!) 부분 특수화 된 함수 템플릿을 선언하면, 반드시 호출시 선언된 [템플릿 parameter]의 갯수와 자료형에 맞는 데이터를 <>안에 입력해야 함
//                 (= 메인 템플릿의 템플릿 변수가 2개의 경우, 사용자는 반드시 템플릿 매개변수를 2개 전달)

//          ex) template <typename T, int count> void display(T value) {  내용  }       <- 부분 특수화 함수 템플릭 선언
//              display <char, 10>('A');                                                 <- 호출시 <char, 10>와 같은 부분을 선언부의 <typename T, int count>와 맞게 적어줘야 함


//      3. 2번의 이유로 부분 특수화(Partial specialization)에서 default parameter는 표시하지 않음  
//         (= 어차피 무조건 템플릿 parameter를 입력해야 하므로, 메인 템플릿에 정의된대로 선언사 <>에 반드시 입력된 템플릿 parameter들을 그대로 받음)

//      4. 부분 특수화(Partial specialization)에서 Typename 자료형인 parameter 객체 T의 타입이 결정되는 방식을 주의 
//          -> 다른 함수 템플릿과 함수명과 선언 내용이 중복되는 경우 예측하지 못하는 상황이 발생함을 주의하라는 의미

//      5. 부분 특수화를 많이 할 경우 절대적 소스코드가 늘어날 수는 있지만, 결국 목적코드로 생성되는 기계어 코드의 양은 같음










//표준 템플릿 라이브러리(STL, Standard Template Library)
//템플릿들의 집합
//컨테이너(Container) : 자료구조
//이터레이터(Iterator) : 데이터 접근 객체
//함수 객체(Function Object) : 함수 역할의 객체
//알고리즘(Algorithm) : 알고리즘 함수(정렬, 검색, 비교, … 등)
//
//이터레이터(Iterator : 반복자, 포인터)
//일반화 프로그램에서 데이터를 접근하는 객체
//배열, 연결리스트, 큐 등 다양함(컨테이너 or 알고리즘)에 얽매이지 않고 저장된 data를 접근할 수 있는 일반화된 표현
//
//Container<data>::iterator itr = Container.begin(), itr1, itr2;
//데이터 값을 접근 할 수 있다.[내용 참조 기능 : (*itr)]
//다른 이터레이터에 대입 할 수 있다.[대입 가능 : itr1 = itr]
//다른 이터레이터와 비교 할 수 있다.[비교 가능 : itr == itr1, itr != itr2]
//컨테이너의 모든 원소를 접근 할 수 있다.[증감 연산 : ++itr, itr++]
//
//_Fn for_each(_InIt _First, _InIt _Last, _Fn _Func)
//함수포인터 for_each(시작 ITR, 종단 ITR, 함수 포인터)



// 함수 템플릿 예시1
#include <iostream>
#include <cstring>
using namespace std;

// == template <class T1>     <- 과거에는 class라고 했지만, 이미 예약어 class가 존재하니 햇살려서 이렇게 함
template <typename T1>

void f_swap(T1& val1, T1& val2) {
	T1 temp = val1;
	val1 = val2;
	val2 = temp;
	cout << typeid(val1).name() << " swap call\n"; // typeid(val1).name() == val1의 자료형
}

template <class T1>

void str_swap(T1& p1, T1& p2) {
	T1 temp;
	strcpy_s(temp, strlen(p1) + 1, p1);
	strcpy_s(p1, strlen(p2) + 1, p2);
	strcpy_s(p2, strlen(temp) + 1, temp);
	cout << typeid(p1).name() << " swap call\n";
}

int main() {
	int i1 = 123, i2 = 456;
	cout << "변경 전 : " << i1 << ", " << i2 << " / ";
	f_swap(i1, i2);
	cout << "변경 후 : " << i1 << ", " << i2 << endl << endl;

	double d1 = 12.34, d2 = 56.78;
	cout << "변경 전 : " << d1 << ", " << d2 << " / ";
	f_swap(d1, d2);
	cout << "변경 후 : " << d1 << ", " << d2 << endl << endl;

	char c1 = 'A', c2 = 'B';
	cout << "변경 전 : " << c1 << ", " << c2 << " / ";
	f_swap(c1, c2);
	cout << "변경 후 : " << c1 << ", " << c2 << endl << endl;

	char str1[255] = "C++ language", str2[255] = "Well done!";
	cout << "변경 전 : " << str1 << ", " << str2 << " / ";
	str_swap(str1, str2);
	cout << "변경 후 : " << str1 << ", " << str2 << endl << endl;

	return 0;
}