//   # 상속 관계에 놓인 class의 형식
//      : Class 클래스명 : 접근제어자 부모클래스명1, ... ,  접근제어자 부모클래스명n {  내용  }
//         -> 다중 상속의 경우 ','를 사용, 상속받을 기초 클래스를 여러 개 가능하나..  권장 X

//             ex) 단일상속
//                 class Student : public Person {           <- Student 클래스는 Person 클래스를 부모로 두고 상속 
//                 
//                    private:
//                        int student_id_;
//                 
//                    public:
//                        Student(int sid, char* name, int age) : Person(name, age) {  내용  }
//                 };


//             ex) 다중상속 
//                 class School : public Buliding, public ClassRoom, public Office {           <- School 클래스는 Buliding, ClassRoom, Office 클래스를 모두 부모로 두고 상속 
//                 
//                 };

//      - class간 상속관계 작성시 접근제어자 (안 적어두면 기본값 private로 적힘)
//         : 쉽게 말해, 부모의 멤버변수를 최소 어느정도 수준으로 접근권한을 규정할거냐? 로 이해하면 ㅇㅋ
//            -> public으로 상속하면 부모멤버의 접근제어자 모두 그대로 가져오고, private은 부모멤버에 대해서는 전부 private로 엄격히 가겠다는 의미
//               (= (중요) 부모멤버가 private인건 원래부터 자식이 어떻게 해볼 수 없다는것 의미 ! )
// 
//               1. 'class 자식클래스 : public 부모클래스' 의 의미
//                   : 부모클래스의 멤버변수에 적힌 접근제어자를 자식도 '그대로' 계승받음
// 		         
//               2. 'class 자식클래스 : protected 부모클래스' 의 의미
//                   : 부모클래스의 멤버변수에 적힌 접근제어자 중 'public에 해당하는 내용들은 자식은 protected'로 계승받음
//                     (= 부모클래스의 멤버변수 중 private, protected의 접근제어자는 똑같이 이어받음)
// 		         
//               3. 'class 자식클래스 : private 부모클래스' 의 의미
//                   : 부모클래스의 멤버변수에 적힌 접근제어자 중 public, protected에 해당하는 내용들은 자식은 '깡그리 private'로 계승받음
//                     (= 부모클래스의 멤버변수 중 private의 접근제어자는 똑같이 이어받음)

//                   ex) 부모가 다음과 같은 경우, 상속시 접근제어자에 따라 자식이 규정하는 물려받은 멤버변수의 접근제어자 
//                       class parents {            
//                       
//                          private:				      <- 부모 멤버가 private이면 자식이 이를 제어 불가능
//                              int private1;		 
//                              int private2;	
// 		         
//                          protected:				   public:
//                              int protected1;	       int public1;
//                              int protected2;	       int public2;
//                       };

//                       (1) class private_child : private parents 의 경우 규정하는 부모멤버의 제어접근자
//                            -> private:
//                                 int protected1;	       
//                                 int protected2;	       
//                                 int public1;
//                                 int public2;

//                       (2) class protected_child : protected parents 의 경우 규정하는 부모멤버의 제어접근자
//                            -> protected:
//                                 int protected1;	       
//                                 int protected2;	       
//                                 int public1;
//                                 int public2;

//                       (3) class public_child : public parents 의 경우 규정하는 부모멤버의 제어접근자
//                            -> protected:				   public:
//                                 int protected1;	       int public1;	       
//                                 int protected2;	       int public2;	       


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
