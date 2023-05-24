// 템플릿(Template)
//  : function or class를 자료 타입에 따라 개별적으로 다시 작성하지 않아도, parameter의 자료형을 확인하고 컴파일 단계에서 parameter 자료형에 맞는 function or class 제작하주는 틀로서 작동
//    -> (중요) 컴파일 단계에서 작동함 = 템플릿을 많이 쓰면 컴파일 속도가 느려짐 <-> 프로그램 처리 속도는 관계 X
//        -> JAVA의 제너릭스(generics)와 유사한 기능 (단! 제너릭스는 컴파일 과정에서의 타입 check기능 추가)

//   # 템플릿 사용 이유?
//      : 진짜 제대로 만들어만 놓는다면? 코드의 완성도가 높아지고, 유지보수 생산성 효율도 증가하기 때문 
//         -> 이러한 장점이 STL(Standard Template Library)처럼 검증된 라이브러리와 함께면 시너지가 대폭 증가

//   # 템플릿의 종류
//     1. 함수 템플릿(function Template)
//        : 함수의 일반적인 동작을 정의, 함수 호출 시에 '지정된 자료형' 만을 인자로 받아 실제 함수를 생성하는 틀
// 	   
//          ex) list(initializer_list<Type> IList, const Allocator& Al);
// 	   
//     2. 클래스 템플릿(class Template)
//        : 클래스의 일반적인 구조를 정의, 클래스의 멤버 변수와 멤버 함수에 대해 '지정된 자료형' 만을 인자로 받아 실제 클래스를 생성하는 틀
	   
//          ex1) template <value자료형 컨테이너요소명>    
//               -> 이후 컨테이너 class 객체를 생성하면, 그 내부의 value자료형을 지정한 자료형으로 구현
	   
//          ex2) 컨테이너클래스명 <value자료형> 객체명 = new 컨테이너클래스명(); 형식도 같은 역할 수행


//   # 컨테이너 클래스에서의 템플릿(Template) 용도
//      : <자료형> 을 의미하는 기호로 일종의 list나 vector와 같은 가변형 동적배열이나, list계열의 linkedList를 특정 class의 객체배열로 사용하기 위해 입력 자료형을 지정하는 역할을 함 
//         -> 쉽게 말해, C언어에서 컨테이너 class 구현할때, node나 list 내부의 value값의 타입을 'typedef value자료형 컨테이너명_element;' 식으로 구현한걸 정식으로 기능화
//            (= 이를 통해 동일한 코드를 다양한 데이터 타입에 대해 재사용하기 쉬워진 효과를 같는 것 또한 동일)


//   # 템플릿 사용시 주의사항
//      1. 가능한 다양한 자료형에 대해 포괄적으로 적용할 수 있는 범용적인 함수를 제작
//      2. 자료형을 템플릿 기호로 표기시에는 일반적으로 T를 사용
//      3. 컴파일 단계에서 만들어지기 때문에, 컴파일 시간이 늘어나게 되는건 감안해야 함
//      4. 함수의 호출 구문으로 parameter의 자료형을 확인하고 자료형 별로 함수를 제작해야 함 (오버로딩)


// 특수화 (Template specialization)
//  : 어떤 템플릿의 특정 패턴에서 별도의 처리가 하고 싶을 경우 사용함

//메인 템플릿의 템플릿 변수가 2개의 경우
//사용자는 반드시 템플릿 매개변수를 2개 전달(기본값이 없다면)

//   # 특수화의 종류
//      1. 템플릿 특수화 (Template specialization)
//          : 특정 자료형을 parameter로 받을 떄, 기존 템플릿의 내용을 따르지 않고 function이나 class생성자의 기능을 다르게 하고 싶은 경우 사용

//      2. 부분 특수화 (Partial specialization)
//          : 템플릿의 parameter가 여러 개일 경우, parameter 중 일부만 특수화 시킴

//템플릿에서는 인자의 수는 메인 템플릿 인자 수와 다를 수 있다.
//특수화를 많이 할 경우 소스코드가 늘어날 수는 있지만
//결국 목적코드로 생성되는 기계어 코드의 양은 같음

//   # 특수화(specialization) 사용시 주의사항
//      1. 부분 특수화에서 T의 타입이 결정되는 방식을 주의
//      2. 부분 특수화에서 default parameter는 표시하지 않음 (= 메인 템플릿에 정의 값을 그대로 받음)
//      3. 템플릿 특수화는 class에서 특정 멤버함수를 특수화 할 수 있으나, 부분 특수화는 아예 불가능


// 템플릿 사용 예시
#include <iostream>
#include <cstring>
using namespace std;

// == template <class T1>
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
