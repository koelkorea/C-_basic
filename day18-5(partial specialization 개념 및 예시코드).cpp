// (템플릭) 부분 특수화(Partial specialization)
//  : 특수화 된 템플릿 parameter가 typename이외에 다른 자료형이 존재하여, 2개 이상의 자료형이 선언된 경우 템플릿 parameter 중 일부만 특수화 함
//     -> 부분 특수화를 많이 할 경우 절대적 소스코드가 늘어날 수는 있지만, 결국 목적코드로 생성되는 기계어 코드의 양은 같음
//         ex) template <typename T, int count> void display <T, count> (T value) {  내용  }
//              -> [일반 function]을 대상으로, 특수화 함수 템플릿의 <>안의 템플릿 parameter가 'typename + 일반 자료형'으로 구성되어 있는 경우


//   # 부분 특수화 템플릿 정의 형식
//      : template 자료형 함수명 <typename T, ... , 자료형1 변수명1, .... >(T value...) { 함수 정의 }
//                               ------------------------------------------
//                                          (생략 불가능!)                       <- (중요!) 이 부분을 적어줘야 이것이 부분 특수화 템플릿임을 컴파일러가 인지함

//         ex) template <typename T> void display(T value);                            <- 기존 입력된 함수 템플릿 
//             template <typename T, int count> void display(T value) {  내용  }       <- 부분 특수화 함수 템플릭 선언


//   # (중요) 부분 특수화 (함수) 템플릿 종류별 호출 및 생성하는 형식
//      : function명 <실제typename1, ... , 고정변수값1(or 고정타입변수명1, ...> (parameter1, ....);
//                   ----------------------------------------------------------
//                                           (생략 불가능!)                       <- (중요!) 반드시 이 부분을 적어줘야 고정된 템플릿 파라미터인 고정변수값1 or 고정타입변수명1...의 값을 받아서, 부분 특수화 함수 템플릿의 내용을 실행이 가능함
//                                                                                            -> (중요!) 반드시 호출시 선언된[템플릿 parameter]의 갯수와 자료형에 맞는 타입명과 값을 가진 고정된 타입의 데이터들을 <>안에 입력해야 함

//        ex) int a = 10;
//            display <char, 10>('A');                                                 <- 호출시 <char, 10>와 같은 부분을 선언부의 <typename T, int count>와 맞게 적어줘야 함 
//            display <double, a)('A')


//   # 부분 특수화(Partial specialization) 사용시 주의사항
//      1. (중요!) 오로지 [일반 function]에 한해서만, 부분 특수화 템플릿은 사용 가능함 
//                (= class와 연관된 멤버함수나 생성자 함수나 부분 특수화 사용 X)

//      2. (중요!) 부분 특수화 된 함수 템플릿을 선언하면, 반드시 호출시 선언된 [템플릿 parameter]의 갯수와 자료형에 맞는 데이터를 <>안에 입력해야 함
//                 (= 메인 템플릿의 템플릿 변수가 2개의 경우, 사용자는 반드시 템플릿 매개변수를 2개 전달)

//          ex) template <typename T, int count> void display(T value) {  내용  }       <- 부분 특수화 함수 템플릭 선언
//              display <char, 10>('A');                                                <- 호출시 <char, 10>와 같은 부분을 선언부의 <typename T, int count>와 맞게 적어줘야 함

//      3. 2번의 이유로 부분 특수화(Partial specialization)에서 default parameter는 표시하지 않음  
//         -> 어차피 정의건 선언이건 부분 특수화 템플릿에서는 모든 종류의 <자료형>의 템플릿 parameter를 생략하지 말고 입력해야 하므로..
//             -> 메인 템플릿에 정의된대로 선언시 <>에 반드시 입력된 템플릿 parameter들을 그대로 받음

//      4. 부분 특수화(Partial specialization)에서 Typename 자료형인 parameter 객체 T의 타입이 결정되는 방식을 주의 
//          -> 다른 특수화 된 함수 템플릿과 overload 된 선언부의 내용이 중복되는 경우 예측하지 못해 의도하지 못한 상황이 발생함을 주의하라는 의미

//      5. 부분 특수화를 많이 할 경우 절대적 소스코드가 늘어날 수는 있지만, 결국 목적코드로 생성되는 기계어 코드의 양은 같음


// 부분 특수화 예시
#include <iostream>
using namespace std;

// 부분 특수화 : 특수화 된 템플릿 parameter가 typename이외에 다른 자료형이 존재하여, 2개 이상의 자료형이 선언된 경우 템플릿 parameter 중 일부만 특수화 함
//  ->[일반 function]을 대상으로, 특수화 함수 템플릿의 <>안의 템플릿 parameter가 'typename + 일반 자료형'으로 구성되어 있는 경우

// 템플릿 parameter가 가변인자 T외의 int 변수로 구성되어 있지만, 가변인자만 paramter로 받는 함수 display()
//  -> 내용 실행을 위해서는 2번쨰 템플릿 paramter의 값도 정해져야 하므로, 부분 특수화 된 함수 템플릿 호출시 2번째 <>는 반드시 작성되어야 함
//      -> 템플릿 호출시 <>안에 2번쨰 인자로는 count의 값을 넣어줌 (= 반드시 작성되어야 함) 
template <typename T, int count>
void display(T value) {
	for (int i = 0; i < count; i++) cout << value << ' ';
	cout << endl;
}

int main() {

	int a = 10;

	// 템플릿 parameter가 가변인자 T외의 int 변수로 구성되어 있지만, 가변인자만 paramter로 받는 함수 display()
	//  -> 내용 실행을 위해서는 2번쨰 템플릿 paramter의 값도 정해져야 하므로, 부분 특수화 된 함수 템플릿 호출시 2번째 <>는 반드시 작성되어야 함
	//      -> 템플릿 호출시 <>안에 2번쨰 인자로는 count의 값을 넣어줌 (= 반드시 작성되어야 함) 

	display<int, 5>(0);      //  <int, 5> 반드시 작성
	display<char, a>('A');   //  <char, a> 반드시 작성
	display<double, 3>(3.4); //  <double, 3> 반드시 작성
	return 0;
}