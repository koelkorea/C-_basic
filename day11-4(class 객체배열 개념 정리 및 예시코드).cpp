// class 객체배열
//  : class 객체가 여러 개 필요할 경우 배열로 선언

// class 객체 포인터 배열
//  : 말그대로 class객체포인터변수로만 이뤄진 배열
//     -> 객체포인터가 여러개 필요한 경우 사용하며, 이는 동적할당되어 생성되는 class객체가 많다는 의미로 받아들일수 있음

//   # (부록) 후기 언어들의 고민 및 아이디어
//      : class 객체배열을 동적으로 길이를 조절 가능하게 하면, 충분히 가변적으로 갯수가 증감하는 객체들을 쉽게 저장이 가능함
//        But! 개념도 복잡해지고, 그를 통해 동적할당된 메모리 영역을 하나하나 다 신경써서 뭘 하기도 ㅈㄴ 귀찮고 짜증남
//         -> (타협점) 포인터 배제하고, list만 동적신축되는 자료구조 class로 신설하자! 
//             : 그냥 동적으로 길이를 신축가능한 어떤 자료형이라도 받는 list 개념을 만들어서, 신축성 갯수가 예상디는 class객체는 여기다 저장하는 걸로 가자..
//               전역으로 쓰고 싶은 class객체 데이터들이 있다면, 걔를 전역변수로 선언하면, 굳이 포인터 쓸 필요 없잖아?


// class 객체배열 만드는 2가지 방법 예시
//  1. 하나하나 class 객체 선언하고, class 객체배열 선언 -> 그렇게 만든 객체들을 하나하나 반복문으로 배열에 넣어줌
//  2. class객체배열 하나만 선언해 두고 -> 반복문으로 생성자를 이용해서 객체배열 공간에 넣어줌
#include <iostream>
using namespace std;

//  1번 용도 class
class classArray_without_constructor {

    private:
        int a;

    public:
        classArray_without_constructor() {
            cout << "classArray_without_constructor 생성자 호출\n"; 
        }

        void Set(int _a) {
            a = _a; 
            cout << "classArray_without_constructor 값 설정  "; 
        }

        void Show(int i) {
            cout << "classArray_without_constructor[" << i << "] = " << a << endl; 
        }
};

//  2번 용도 class(parameter 1개)
class classArray_with_constructor1 {

    private:
        int a;

    public:
        classArray_with_constructor1() {
            cout << "classArray_with_constructor1 생성자 호출\n";
        }

        classArray_with_constructor1(int _a) {
            a = _a; 
            cout << _a << "classArray_with_constructor1 생성자 호출\n";
        }

        ~classArray_with_constructor1() {
            cout << "classArray_with_constructor1 소멸자 호출\n";
        }

        void Set(int _a) {
            a = _a; 
            cout << "classArray_with_constructor1 값 설정  ";
        }

        void Show(int i) {
            cout << "classArray_with_constructor1[" << i << "] = " << a << endl;
        }
};

//  2번 용도 class(parameter 2개)
class classArray_with_constructor2 {

private:
    int a, b;

public:

    classArray_with_constructor2() {
        cout << "classArray_with_constructor2 생성자 호출\n";
    }

    classArray_with_constructor2(int _a, int _b) {
        a = _a;
        b = _b;
        cout << _a << "classArray_with_constructor2 생성자 호출\n";
    }

    ~classArray_with_constructor2() {
        cout << "classArray_with_constructor2 소멸자 호출\n";
    }

    void Set(int _a) {
        a = _a;
        cout << "classArray_with_constructor2 값 설정  ";
    }

    void Show(int i) {
        cout << "classArray_with_constructor2[" << i << "] : " << "a =  " << a << ", b = " << b << endl; 
    }

};

int main() {

    //  1. 하나하나 class 객체 선언하고, class 객체배열 선언 -> 그렇게 만든 객체들을 하나하나 반복문으로 배열에 넣어줌
    classArray_without_constructor ob1, ob2, ob3, ob4, ob5;

    // class 객체배열 선언 
    classArray_without_constructor ob[5];

    for (int i = 0; i < 5; i++) {
        ob[i].Set(i + 1);
        ob[i].Show(i);
    }

    //-------------------------------------------------------------------------------------------------------------

    //  2. (생성자 1개) class객체배열 하나만 선언해 두고 -> 반복문으로 생성자를 이용해서 객체배열 공간에 넣어줌
    classArray_with_constructor1 obj[5] = { classArray_with_constructor1(6), classArray_with_constructor1(7), classArray_with_constructor1(8), classArray_with_constructor1(9), classArray_with_constructor1(10) }; //객체배열 초기화 방법

    for (int i = 0; i < 5; i++) {
        obj[i].Show(i);
    }

    for (int i = 0; i < 5; i++) {
        obj[i] = classArray_with_constructor1(i * 10);
    }

    for (int i = 0; i < 5; i++) {
        obj[i].Show(i);
    }

    //  2. (생성자 2개) class객체배열 하나만 선언해 두고 -> 반복문으로 생성자를 이용해서 객체배열 공간에 넣어줌

    //객체배열 간략화된 초기화 방법
    // classArray_with_constructor2 obc[5] = { {1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50} }; 

    //객체배열 생성자 사용 초기화 방법
    classArray_with_constructor2 obc[5] = { classArray_with_constructor2(1, 10), classArray_with_constructor2(2, 20), classArray_with_constructor2(3, 30), classArray_with_constructor2(4, 40), classArray_with_constructor2(5, 50) };

    for (int i = 0; i < 5; i++) {
        obc[i].Show(i);
    }

    for (int i = 0; i < 5; i++) {
        obc[i] = classArray_with_constructor2(i + 10, i * 10);
    }

    for (int i = 0; i < 5; i++) {
        obc[i].Show(i);
    }

    return 0;
}
