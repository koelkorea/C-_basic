//   # 접근제어자 (복습)
//      : 클래스의 멤버변수의 변조 방지를 위해 코드 실행 중 접근위치에 따라 멤버변수의 값에 접근여부에 따른 제어권한을 의미 
//         -> 사실상 public과 private만 널리 사용되며, 이들이 getter setter 디자인패턴과 연관 

//        - private     : 해당 클래스 내에서만 해당 클래스의 멤버들에 접근할 수 있음 
//                        (= 오로지 클래스 선언시 미리 작성한 멤버변수 초기화 값과 멤버함수를 통해서만 값의 변조가 가능 == 은닉이 필요한 속성에 적용하게 됨)
//      
//        - protected   : 상속관계에서 해당 클래스의 멤버들에 접근허용 
//                        (= 해당 클래스와 상속관계에 있는 클래스가 선언될 때라면, 해당 멤버변수의 값에 접근 및 변조나 멤버함수의 사용이 가능) 
//      
//        - public      : 어디서든 일단 멤버변수나 멤버메서드가 호출되거나 참조되면, 언제라도 해당 멤버변수의 값에 접근 및 변조나 멤버함수의 사용을 허용함 (사실상 자동문임)

#include <iostream>

using namespace std;

class Base {

    //선언된 클래스만 접근 가능
    private:   
        int a;

    //선언된 클래스 + 상속된 클래스에서 접근 가능 (요즘은 은닉화 개념 복잡해지는거도 싫어서, 그냥 protect 안 씀)
    protected: 
        int b;

    // 어디서나 접근 가능.. 
    //  -> 요즘 보통 private이건, protect건 멤버변수는 public 영역에 get set형식으로 접근가능하게 하는 방식을 씀 
    public:
        void Set_a(int _a) { a = _a; }
        void Set_b(int _b) { b = _b; }
        int Get_a() { return a; }
        int Get_b() { return b; }
};

class Derived : public Base {

    private:
        int c;

    public:

        void Set(int _a, int _b, int _c) {

            // c는 자식 클래스 자신의 변수이므로 접근 가능
            c = _c;

            // a는 부모 클래스의 private 멤버로 상속받아도 접근 불가능
            //  -> 따라서 a를 초기화 해주는 Set_a함수를 통해 a값 초기화
            // a = _a;
            Set_a(_a);

            // b는 protected 멤버로 상속 받아 접근 가능
            b = _b;       
        }

        int Mul() {

            // a는 private 멤버로 상속받아도 접근 불가능
            //  -> Get_a()로 대체
            // return a * b * c;   
            return Get_a() * b * c;
        }
};

int main() {

    //객체 생성 시 부모에게서 상속된 멤버까지 모두 메모리 할당
    Derived ob;       

    ob.Set(5, 4, 5);

    cout << ob.Mul() << endl;

    return 0;
}
