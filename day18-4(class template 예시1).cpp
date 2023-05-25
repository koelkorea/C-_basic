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


//클래스 템플릿 예시1
#include <iostream>
using namespace std;

// 클래스 템플릿
template <typename T>

class Dummy {
    private:
        T a;
    public:
        Dummy(T a);
        inline void SetA(T a);
        inline T GetA() const;
};

// 함수 템플릿
template <typename T>

Dummy<T>::Dummy(T a) : a(a) {}

// 함수 템플릿
template <typename T>

inline void Dummy<T>::SetA(T a) { this->a = a; }

// 함수 템플릿
template <typename T>

inline T Dummy<T>::GetA() const { return a; }

int main() {

    Dummy<int> d1(10);
    cout << d1.GetA() << endl;     // 10

    Dummy<int> d2('A');
    cout << d2.GetA() << endl;     // 'A' = 65

    Dummy<char> d3('A');
    cout << d3.GetA() << endl;     // 'A' = 65

    Dummy<double> d4(3.14);
    cout << d4.GetA() << endl;     // 3.14

    Dummy<const char*> d5("C++");
    cout << d5.GetA() << endl;     // "C++"

    return 0;
}