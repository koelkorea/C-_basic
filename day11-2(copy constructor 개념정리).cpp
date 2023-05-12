// Copy Constructor(복사 생성자)
//  : 자신과 같은 class타입의 객체를 parameter로 받을 수 있는 생성자
//     -> 이를 통해 parameter로 들어간 객체의 멤버변수를 고대로 (얕은) 복사를 해서 대입하고 초기화하여 class 객체 생성이 가능함

//   # (중요) Copy Constructor(복사 생성자) 특징
//     1. 누가 생성자 아니랄까봐, 멤버변수 값을 대입하는 void 함수와 비슷 (= return값 X)
//     2. 가만히 있어도 컴파일시 자동으로 생성해 즘
//     3. (중요) 단! 자동으로 생성된 복사 생성자가 정의부에 기본적인 복사내용까지 적용 <-> defalut 생성자, 소멸자는 따로 정의부에 내용 작성이 없다면? 빈 껍데기만 존재
//     4. (중요)parameter가 반드시 필요함
//          -> 반드시 parameter 자료형은 '레버런스 class객체' or  'class포인터변수' 로 들어가야함

//   # 복사 생성자 선언, 정의법
//      : 그냥 void 함수라고 생각하되, 따로 작성하지 않아도 당신이 생각한 그 객체간 얕은 복사를 수행한다고 보면 됨
//         -> 클래스명(const 클래스명&) { .... }											
//                   
//            ex) class Document {
//                    Document(const Document&) { ..... };
//                };

//   # 복사 생성자 호출법
//      : 일반 생성자랑 다른거 없으니 패스

//   # 복사 생성자를 프로그램이 호출하는 경우
//      1. class 객체를 선언하면서, 복사 생성자를 통해 객체로 초기화 하는 경우 (애초의 목적 가장 당연함)
//      2. 특정 함수의 parameter로 class 객체를 값으로 전달하는 경우
//         (= parameter 대상으로 선언부에 적힌, 그 객체의 내용을 call by value 방식으로 얕게 복사한 함수{} 끝나면 죽는 객체를 생성함..)
//      3. (C++17 개정으로 안 쓰임) 함수의 결과로 객체를 return 하는 경우
//          -> 그러니까 함수의 결과값인 return 객체를 main{}의 지역객체로 얕게 복사한다는 말...

// Copy Constructor(복사 생성자)호출하는 3가지 경우 설명 예시코드
#include <iostream>

using namespace std;

class A {

    private:
        int a;
        double d;
        char c;

    public:

        //생성자
        A(int _a = 0, double _d = 0, char _c = 0);

        //복사생성자
        A(A& r);                 

        //출력함수
        void Show();                        
};

void display_value(A a) { a.Show(); } //call by value
void display_ref(A& a) { a.Show(); }  //call by reference
void display_ptr(A* a) { a->Show(); } //call by reference
A creat_obj() { A obj(2, 6.87, 'B'); return obj; } //return by value ( C++17 개정으로 때에 따라 다름 )

int main() {

    A ob1(1, 3.54, 'A');
    A ob2(ob1);  //(1) 객체를 선언과 동시에 객체로 초기화 하는 경우 복사생성자가 호출됨
    A ob3 = ob1; //(1) 객체를 선언과 동시에 객체로 초기화 
    A ob4;

    ob4 = creat_obj();//(3) 객체를 리턴 시 값에 의해 리턴 하는 경우 (call by value – 반환 시 값을 복사 / C++17 개정으로 때에 따라 다름)
    ob1.Show();    
    ob2.Show();    
    ob3.Show();

    display_value(ob1); //(2) 함수의 매개변수로 객체를 값으로 전달한 경우 call by value
    display_ref(ob2);    display_ptr(&ob3);    display_ref(ob4); //(2) 함수의 매개변수로 객체를 레퍼런스(주소)로 전달한 경우 call by reference
    return 0;
}

A::A(int _a, double _d, char _c) : a(_a), d(_d), c(_c) { cout << "생성자 호출\n"; }

//반드시 레퍼런스나 포인터로 받아야 한다. 멤버 대 멤버 복사(객체간의 복사)
A::A(A& r) {
    this->a = r.a;
    this->d = r.d;
    this->c = r.c;
    cout << "복사 생성자 호출\n";
}

void A::Show() {
    cout << a << ' ' << d << ' ' << c << endl;
}

