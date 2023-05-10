//   # this포인터를 활용하기 유효한 경우
//      1. 멤버함수의 parameter가 멤버변수와 이름이 같은 경우
//          ex) class B {
//                 int i, j;
//                 void Set(int i, int j) {      <- 각각 멤버변수와 parameter의 이름이 i , j로 같음
//                    this->i = i;               <- this->i 라면 구분이 될 수 있으니 쉽게 해결 가능
//                    this->j = j; 
//                 }

//      2. 멤버함수에서 함수를 호출한 객체를 그 자체를 반환하는 경우
//          -> 하.. 이거 그 객체가 뭔지 내가 어떻게 알아? 라고 안하고
//             -> 해당 클래스 포인터변수 형식으로 객체의 주소값을 받는 this를 역참조한 객체값 *this을 return하면 됨! 

// this포인터를 활용하기 유효한 경우 2번의 예시
#include <iostream>
using namespace std;

// 계산기 클래스
class Calc {

    private:
        int m_Value = 0;

    public:

        Calc& Add(int value) { 
            m_Value += value; 
            return *this; 
        }

        Calc& Sub(int value) {
            m_Value -= value; 
            return *this; 
        }

        Calc& Mul(int value) {
            m_Value *= value;
            return *this; 
        }

        int GetValue() {
            return m_Value; 
        }
};

int main() {

    Calc obj1;

    // Add(10)을 계산 -> 계산결과 Calc객체 -> 그 calc 객체에 sub(5) 반영 후 Calc객체 리턴 -> 그 calc 객체에 Mul(4) 반영 후 Calc객체 리턴
    obj1.Add(10).Sub(5).Mul(4);

    // 결과값 20
    cout << obj1.GetValue() << endl; 

    return 0;
}
