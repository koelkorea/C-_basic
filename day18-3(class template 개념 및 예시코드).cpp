// 클래스 템플릿 case별 예시코드
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------------
// (예시1) 멤버함수의 정의부를 따로 빼서 함수 템플릿으로 정의하는 클래스 템플릿 예시
//   -> 사실 멤버함수 paramter명과 멤버변수만 다르게 해주거나 this를 쓰면 되니 굳이 이럴 필요없음 (= 예시2로 직행해도 됨)

// Dummy 클래스 템플릿
//  -> 템플릿 parameter인 T가 어떤 자료형을 가르키냐에 따라 멤버변수와 멤버함수의 parameter의 자료형 모두를 결정하는 구조 
template <typename T>
class Dummy {

    private:
        T a;

    public:
        // 단, 원칙적으로 멤버함수의 parameter명과 멤버변수는 달라야 하므로... 멤버함수들은 정의부에 해당하는 내용은 따로 외부로 빼서 함수 템플릿을 사용하여 재정의
        Dummy(T a);                    // Dummy<T>(T a); 와 같음
        inline void SetA(T a);         // inline void SetA<T>(T a); 와 같음
        inline T GetA() const;         // inline T GetA()<T> const; 와 같음
};

// 생성자 함수 - 함수 템플릿 사용 + 초기화 리스트 (Initialize List) 사용하여 정의부 작성
template <typename T>
Dummy<T>::Dummy(T a) : a(a) {}         // Dummy<T>::Dummy<T>(T a) : a(a) {} 와 같음

// set 멤버함수 - 함수 템플릿 사용해서 정의부 작성
template <typename T>
inline void Dummy<T>::SetA(T a) {       // inline void Dummy<T>::SetA<T>(T a) {} 와 같음
    this->a = a; 
}

// get 멤버함수 - 함수 템플릿 사용해서 정의부 작성
template <typename T>
inline T Dummy<T>::GetA() const {        // inline T Dummy<T>::GetA<T>() const {} 와 같음
    return a; 
}


//-----------------------------------------------------------------------------------------------------------------------
// (예시2) 클래스 템플릿 하나로 멤버함수의 자료형까지 규정 + 템플릿 parameter가 복수개인 클래스 템플릿 예시
//   -> this를 써도 되고, 멤버변수 != paramter명 해도 됨

// dosomething 클래스 템플릿
//  -> 템플릿 parameter인 T1, T2가 어떤 자료형을 가르키냐에 따라 멤버변수와 멤버함수의 parameter의 a, b의 자료형을 결정하는 구조 
template <typename T1, typename T2>
class dosomething {

    private:
        T1 a;
        T2 b;

    public:       

        dosomething() : a(0), b(0) {};
        dosomething(T1 a, T2 b) : a(a), b(b) {}  // dosomething<T1, T2>(T1 a, T2 b); 와 같음

        inline T1 getA() const {                 // inline T1 getA<T1>() const; 와 같음
            return a;
        }

        inline T2 getB() const {                 // inline T2 getB<T2>() const; 와 같음
            return b;
        }

        inline void setA(T1 a) {                 // inline void setA<T1>(T1 a); 와 같음
            this->a = a;
        }

        inline void setB(T2 b) {                 // inline void setB<T2>(T2 b); 와 같음
            this->b = b;
        }
};

// 생성자 함수 - 함수 템플릿 사용 + 초기화 리스트 (Initialize List) 사용하여 정의부 작성
//template <typename T1, typename T2>
//dosomething<T1, T2>::dosomething() : a(0), b(0) {}

// 생성자 함수 - 함수 템플릿 사용 + 초기화 리스트 (Initialize List) 사용하여 정의부 작성
//template <typename T1, typename T2>
//dosomething<T1, T2>::dosomething(T1 a, T2 b) : a(a), b(b) {}


int main() {

    //-----------------------------------------------------------------------------------------------------------------------
    // (예시1) 멤버함수의 정의부를 따로 빼서 함수 템플릿으로 정의하는 클래스 템플릿 예시
    //   -> (중요) 생성자 함수를 통해, 템플릿 typename이 선언되었음
    //      (= 따라서 같은 템플릿 paramter를 사용하는 멤버함수를 호출시에는 굳이 <실제 자료형>을 넣지 않아도, 컴파일러가 명확히 class 생성자 떄 사용한 자료형을 사용해서 템플릿 호출 부분을 작성)

    Dummy<int> d1(10);
    cout << d1.GetA() << endl;     // d1.GetA<int>() = 숫자 10

    Dummy<int> d2('A');
    cout << d2.GetA() << endl;     // d1.GetA<int>() = 숫자 'A' = 65

    Dummy<char> d3('A');
    cout << d3.GetA() << endl;     // d1.GetA<char>() = 문자 'A' = 65

    Dummy<double> d4(3.14);
    cout << d4.GetA() << endl;     // d1.GetA<double>() = 실수 3.14

    Dummy<const char*> d5("C++");
    cout << d5.GetA() << endl;     // d1.GetA<char*>() = 문자열 "C++"

    //-----------------------------------------------------------------------------------------------------------------------
    // (예시2) 클래스 템플릿 하나로 멤버함수의 자료형까지 규정 + 템플릿 parameter가 복수개인 클래스 템플릿 예시
    //   -> (중요) 생성자 함수를 통해, 템플릿 typename이 선언되었음
    //      (= 따라서 같은 템플릿 paramter를 사용하는 멤버함수를 호출시에는 굳이 <실제 자료형>을 넣지 않아도, 컴파일러가 명확히 class 생성자 떄 사용한 자료형을 사용해서 템플릿 호출 부분을 작성)

    dosomething<int, int> f1(1, 10);
    cout << "d1 = " << f1.getA() << ", " << f1.getB() << endl;

    dosomething<int, char> f2('A', 'B');
    cout << "d2 = " << f2.getA() << ", " << f2.getB() << endl;

    dosomething<char, char> f3('A', 'B');
    cout << "d3 = " << f3.getA() << ", " << f3.getB() << endl;

    dosomething<double, char> f4(3.14, 'Q');
    cout << "d4 = " << f4.getA() << ", " << f4.getB() << endl;

    dosomething<const char*, const char*> f5("C++", "Well done");
    cout << "d5 = " << f5.getA() << ", " << f5.getB() << endl;

    return 0;
}