// 클래스 (class)
//  : 구현하려는 대상의 속성을 묶어서 자료화를 하고, 자료들(멤버변수)과 해당 자료들과 관련된 함수(멤버함수)를 그룹화한 자료형 단위 (이걸로 c++은 진정한 객체지향언어의 길로 접어듬)
//     -> c++의 구조체(멤버함수 추가)의 진화형이라고 생각하면 됨


//   # C 구조체 vs C++ 구조체 vs 클래스(class)
//     : (중요) 핵심은 구조체는 '캡슐화'만 구현되어 있고, 클래스는 객체지향언어로서 4가지 특징(추상화, 캡슐화 + 은닉화, 상속, 다형성)이 다 구현됨

//        - C 구조체     : 오직 자료들(멤버변수)만 그룹화(캡슐화)한 자료형
//        - C++ 구조체   : 자료들(멤버변수)과  해당 자료들과 관련된 함수(멤버함수)까지 그룹화(캡슐화)한 자료형
//        - 클래스       : C++ 구조체의 특징을 다 가짐 + 객체지향언어로서 4가지 특징(추상화, 캡슐화 + 은닉화(접근제어자 사용), 상속, 다형성) 다 구현된 자료형 단위


//   # 클래스(class) 선언 형식 (접근제어자가 생김)
//      : class 클래스명 {
// 	      
//            private:
//                변수1;
//                ....;
//                변수n;
// 	      
//            protected:
// 	      
//            public:
//                변수3;
//                변수 연산 함수1;
//                변수 연산 함수2;
//                변수 연산 함수3;
//                …;
//        };

//      ex) class ACT {

//               private:
//                   int ACTId;           
//                   char pw[5];          
//                   char name[20];       
//                   int bal;     
     
//               public:
//                   void Init_act(int actid, const char* pw, const char* name, int bal);
//                   void showData();
//                   void deposit(); 
//                   void withdraw();
//          };

//   # 접근제어자
//     : 클래스의 멤버변수의 변조 방지를 위해 코드 실행 중 접근위치에 따라 멤버변수의 값에 접근여부에 따른 제어권한을 의미 
//        -> 사실상 public과 private만 널리 사용되며, 이들이 getter setter 디자인패턴과 연관 

//       - private     : 해당 클래스 내에서만 해당 클래스의 멤버들에 접근할 수 있음 (= 오로지 클래스 선언시 미리 작성한 멤버변수 초기화 값과 멤버함수를 통해서만 값의 변조가 가능)
//       - protected   : 상속관계에서 해당 클래스의 멤버들에 접근허용 (= 해당 클래스와 상속관계에 이는 클래스가 선언될 때라면, 해당 멤버변수의 값에 접근 및 변조나 멤버함수의 사용이 가능) 
//       - public      : 어디서든 일단 멤버변수나 멤버메서드가 호출되거나 참조되면, 언제라도 해당 멤버변수의 값에 접근 및 변조나 멤버함수의 사용을 허용함 (사실상 자동문임)


// class  VS C++ 구조체 (구조체 { 멤버 변수들..., 멤버 함수들 선언 + 정의 } ) 예시
//  : ATM 구현 예시 코드를 통해 보는 차이점
#include <iostream>
#include <cstring>

using namespace std;

//-----------------------------------[C++ ver1 : 구조체 with  멤버함수 선언 + 정의]------------------------------- 

// 고객의 계좌 구조체
struct ACT_CPP1 {

    int ACTId;              // 계좌번호
    char pw[5];             // 비밀번호
    char name[20];          // 이름
    int bal;                // 잔액

    // 계좌의 정보 출력 (계좌 구조체의 멤버함수)
    void showData_cpp1() {
        cout << "\n계좌번호 : " << ACTId << endl;
        cout << name << " 회원님의 잔액은 " << bal << "입니다.\n";
    }

    // 계좌의 입금기능 (계좌 구조체의 멤버함수)
    void deposit_cpp1() {

        int m;

        cout << "\n입금금액 입력 : ";
        cin >> m;

        // 입력한 m의 금액을 바로 멤버변수 bal에 +
        bal += m;

        cout << "\t\t" << m << "원 입금완료.\n";
    }

    // 계좌의 출금 출력 (계좌 구조체의 멤버함수)
    void withdraw_cpp1() {

        int m;

        cout << "\n출금금액 입력 : ";
        cin >> m;

        // 입력한 m의 금액을 바로 멤버변수 bal에 -
        bal -= m;

        cout << "\t\t" << m << "원 출금완료.\n";
    }

};

//-----------------------------------[C++ ver2 : 구조체 with 멤버함수 선언, 정의부는 구조체 밖에서 :: 연산자 사용]------------------------------- 
//   # (c++ 추가 + 중요) c++에서 :: 연산자
//     : scope resolution 연산자 (namespace, class, struct 등 자기 영역(scope)이 있는 자료형의 경우, 그 특정 자료형 안의 멤버(변수, 함수 다 포함)를 찾아 참조하라는 의미)
//       -> (결론) namespace명::식별자, 구조체명::멤버함수(), 전부 같은 맥락으로 이해하면 됨

// [구조체 선언 구간]
struct ACT_CPP2 {

    int ACTId;              // 계좌번호
    char pw[5];             // 비밀번호
    char name[20];          // 이름
    int bal;                // 잔액

    // (중요) 멤버함수를 선언 (정의는 구조체 외부에서)
    void showData_cpp2();  // 계좌정보 출력
    void deposit_cpp2();   // 입금 함수 & 출력
    void withdraw_cpp2();  // 출금 함수 & 출력
};

// [구조체 함수 정의 구간]
// -> 구조체명::메서드1(parmater..) 형식 사용
void ACT_CPP2::showData_cpp2() {

    cout << "\n계좌번호 : " << ACTId << endl;
    cout << name << " 회원님의 잔액은 " << bal << "입니다.\n";
}

void ACT_CPP2::deposit_cpp2() {

    int m;

    cout << "\n입금금액 입력 : ";
    cin >> m;

    // 입력한 m의 금액을 바로 멤버변수 bal에 +
    bal += m;
    cout << "\t\t" << m << "원 입금완료.\n";
}

void ACT_CPP2::withdraw_cpp2() {

    int m;

    cout << "\n출금금액 입력 : ";
    cin >> m;

    // 입력한 m의 금액을 바로 멤버변수 bal에 -
    bal -= m;
    cout << "\t\t" << m << "원 출금완료.\n";
}



//-----------------------------------[class를 통한 구현]------------------------------- 
//   # (c++ 추가 + 중요) c++에서 :: 연산자
//     : scope resolution 연산자 (namespace, class, struct 등 자기 영역(scope)이 있는 자료형의 경우, 그 특정 자료형 안의 멤버(변수, 함수 다 포함)를 찾아 참조하라는 의미)
//       -> (결론) namespace명::식별자, 구조체명::멤버함수(), 전부 같은 맥락으로 이해하면 됨


// [class 선언 구간]
class ACT {

    // 멤버변수 (private에 집중되었지만, 사실 멤버함수도 사용가능)
    private:
        int ACTId;              //계좌번호
        char pw[5];             //비밀번호
        char name[20];          //이름
        int bal;                //잔액

     // 멤버함수 (public에 집중되었지만, 사실 멤버함수도 사용가능)
    public:
        void Init_act(int _actid, const char* _PW, const char* _NAME, int _BAL);
        void showData(); //계좌정보 출력
        void deposit(); //입금 함수 & 출력
        void withdraw();//출금 함수 & 출력
};


//[class 멤버 함수 정의 구간]
// -> class명::메서드1(parmater..) 형식 사용

// 클래스 초기화 함수 추가
void ACT::Init_act(int _actid, const char* _PW, const char* _NAME, int _BAL) {
    ACTId = _actid;
    strcpy_s(pw, _PW);
    strcpy_s(name, _NAME);
    bal = _BAL;
}

void ACT::showData() {
    cout << "\n계좌번호 : " << ACTId << endl;
    cout << name << " 회원님의 잔액은 " << bal << "입니다.\n";
}

void ACT::deposit() {
    int m;
    cout << "\n입금금액 입력 : ";
    cin >> m;
    bal += m;
    cout << "\t\t" << m << "원 입금완료.\n";
}

void ACT::withdraw() {
    int m;
    cout << "\n출금금액 입력 : ";
    cin >> m;
    bal -= m;
    cout << "\t\t" << m << "원 출금완료.\n";
}

int main() {

    cout << "\n\n--------------------[c++의 구조체1(구조체에 맴버함수 선언 + 정의)로 구현한 파트]--------------------\n\n";

    ACT_CPP1 act_2 = { 4567, "1234", "kane", 60000 };

    // 구조체변수명.멤버함수명() 으로 일일히 파라미터 안 넘겨도 구조체 멤버변수간 교류가 가능 (만약 다른 외부변수가 필요하면, paramemter로 던져주면 됨) 
    act_2.showData_cpp1();       // 잔액조회 함수 호출
    act_2.deposit_cpp1();        // 입금함수 호출
    act_2.withdraw_cpp1();       // 출금함수 호출
    act_2.showData_cpp1();       // 잔액조회 함수 호출

    cout << "\n\n--------------------[c++의 구조체2(구조체에 맴버함수 선언 + 정의는 ::연산자 사용하여 외부에서)로 구현한 파트]--------------------\n\n";

    ACT_CPP2 act_3 = { 7894, "2345", "sonny", 90000 };

    // 구조체변수명.멤버함수명() 으로 일일히 파라미터 안 넘겨도 구조체 멤버변수간 교류가 가능 (만약 다른 외부변수가 필요하면, paramemter로 던져주면 됨) 
    //  <-> 구조체명::메서드1(parmater..)
    //       : 구조체 외부에서 멤버함수 정의할 때 쓰는 녀석
    act_3.showData_cpp2();       // 잔액조회 함수 호출
    act_3.deposit_cpp2();        // 입금함수 호출
    act_3.withdraw_cpp2();       // 출금함수 호출
    act_3.showData_cpp2();       // 잔액조회 함수 호출

    cout << "\n\n--------------------[class(맴버함수 선언 + 정의는 ::연산자 사용하여 외부에서)로 구현한 파트]--------------------\n\n";

    ACT act_1;

    // class 초기화 함수 추가로 class 값 초기화
    act_1.Init_act(1234, "5678", "christopher", 10000);

    act_1.showData();            // 잔액조회 함수 호출
    act_1.deposit();             // 입금함수 호출
    act_1.withdraw();            // 출금함수 호출
    act_1.showData();            // 잔액조회 함수 호출

    return 0;
}

