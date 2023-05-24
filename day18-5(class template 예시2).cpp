// 템플릿(Template)
//  : function or class를 자료 타입에 따라 개별적으로 다시 작성하지 않아도, parameter의 자료형을 확인하고 컴파일 단계에서 parameter 자료형에 맞는 function or class 제작하주는 틀로서 작동
//    -> (중요) 컴파일 단계에서 작동함 = 템플릿을 많이 쓰면 컴파일 속도가 느려짐 <-> 프로그램 처리 속도는 관계 X
//        -> JAVA의 제너릭스(generics)와 유사한 기능 (단! 제너릭스는 컴파일 과정에서의 타입 check기능 추가)

//   # 템플릿 사용 이유?
//      : 진짜 제대로 만들어만 놓는다면? 코드의 완성도가 높아지고, 유지보수 생산성 효율도 증가하기 때문 
//         -> 이러한 장점이 STL(Standard Template Library)처럼 검증된 라이브러리와 함께면 시너지가 대폭 증가

//   # 템플릿의 종류 	   
//     2. 클래스 템플릿(class Template)
//        : 클래스의 일반적인 구조를 정의, 클래스의 멤버 변수와 멤버 함수에 대해 '지정된 자료형' 만을 인자로 받아 실제 클래스를 생성하는 틀

//          ex1) template <value자료형 컨테이너요소명>    
//               -> 이후 컨테이너 class 객체를 생성하면, 그 내부의 value자료형을 지정한 자료형으로 구현

//          ex2) 컨테이너클래스명 <value자료형> 객체명 = new 컨테이너클래스명(); 형식도 같은 역할 수행


//클래스 템플릿 예시2
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class dosomething{
	private:
		T1 a;
		T2 b;

	public:
		dosomething();
		dosomething(T1 a, T2 b);

		inline T1 getA() const {
			return a; 
		}

		inline T2 getB() const {
			return b; 
		}

		inline void setA(T1 a) {
			this->a = a; 
		}

		inline void setB(T2 b) {
			this->b = b; 
		}
};

template <typename T1, typename T2>
dosomething<T1, T2>::dosomething() : a(0), b(0) {}

template <typename T1, typename T2>
dosomething<T1, T2>::dosomething(T1 a, T2 b) : a(a), b(b) {}

int main(){

	dosomething<int, int> d1(1, 10);
	cout << "d1 = " << d1.getA() << ", " << d1.getB() << endl;

	dosomething<int, char> d2('A', 'B');
	cout << "d2 = " << d2.getA() << ", " << d2.getB() << endl;

	dosomething<char, char> d3('A', 'B');
	cout << "d3 = " << d3.getA() << ", " << d3.getB() << endl;

	dosomething<double, char> d4(3.14, 'Q');
	cout << "d4 = " << d4.getA() << ", " << d4.getB() << endl;

	dosomething<const char*, const char*> d5("C++", "Well done");
	cout << "d5 = " << d5.getA() << ", " << d5.getB() << endl;

	return 0;
}
