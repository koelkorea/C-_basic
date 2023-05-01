// 우리가 poiner가 아니라 reference를 써야 하는 이유?
//  : reference 변수는 그 자체가 모태가 되는 원본 변수의 주소값까지 가지고 있는 변수임을 착안
// 
//    -> 이점1)  함수 선언시에 parameter로 reference변수를 타입으로 선언하는 경우, 변수를 대입할때 그 값을 call by reference 개념으로 주소값에 존재하는 값 그 자체를 넘기게 됨
//               (= 포인터 개념을 생각하지 않기에, call by reference라는 목적만 기억하면 다른 시행착오 없이 깔끔하고 쉽게 함수 선언이 가능하다!..)
//                   -> (중요!) 해당 함수가 받는 param은 reference 변수지만, 호출할때 대입하는 param은 깔끔하게 일반 변수로 해도 무방하다.. 
//                             (= 쉽게 말해, 굳이 다른 reference 변수를 만드는 수고를 안해도 된다 이말이다..)        
// 
//       이점2) 포인터를 쓰면 포인터 연산을 통해 메모리공간을 자유롭게 활보가능 = 쓰는 사람의 혼란을 야기..
//              (= 하지만 특정 변수의 위치값만을 의미하는 reference변수는 죽었다 깨어다도 그 주소외의 다른 주소를 쓸수는 없음)

//   # (중요) reference 변수의 단점
//     : 포인터 연산이 불가능해, 배열이나 문자열 같은 필연적으로 메모리 공간을 여러개를 쓰는 자료형을 다루기는 불편함

// quiz 
// 1. 문자, 정수, 실수 값을 swap하는 함수 reference를 구현...
// 2. 문자열 swap하는 함수 pointer 기반으로 구현...
#include <iostream>
#include <iomanip>
using namespace std;

// --------------------reference 변수를 parameter로 받는 함수----------------------
//  -> 이 경우는 호출시 넘긴 parameter가 call by reference 형식으로 작동하여 원본값에 영향을 미치는 형태가 됨

// int swap
void swap(int& p1, double& p2) {
    int tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

// char swap
void swap(char& p1, char& p2) {
    char tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

// double swap
void swap(double& p1, double& p2) {
    double tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

// --------------------pointer 변수를 parameter로 받는 함수----------------------

// char배열(= 문자열) swap
void swap(char* p1, char* p2) {

    // 두 문자열의 다음 포인터의 역참조 값이 모두 NULL이면 값 교환을 멈춘다
    while (*p1 != NULL || *p2 != NULL) {

        char tmp;
        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;

        p1++;
        p2++;
    }

}

int main() {

    int int1, int2 = 0;
    char char1, char2 = 0;
    double double1, double2 = 0.0;
    char char_array1[50], char_array2[50] = { 0 };

    cout << "int값 2개를 입력해라 : ";
    cin >> int1 >> int2;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
    }

    cout << "char값 2개를 입력해라 : ";
    cin >> char1 >> char2;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
    }

    cout << "double값 2개를 입력해라 : ";
    cin >> double1 >> double2;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
    }

    cin.ignore(sizeof(double2), '\n');

    cout << "문자열 char_array1 입력(50자 제한) : " ;
    cin.getline(char_array1, 50);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(50, '\n');
    }

    cout << "문자열 char_array2 입력(50자 제한) : " ;
    cin.getline(char_array2, 50);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(50, '\n');
    }

    cout << endl <<  "--------------------------[원본값 모음]-------------------------" << endl;
    cout << "int1 = " << int1 << " , int2 = " << int2 << endl;
    cout << "char1 = " << char1 << " , char2 = " << char2 << endl;
    cout << "double1 = " << double1 << " , double2 = " << double2 << endl;
    cout << "char_array1 = " << char_array1 << endl;
    cout << "char_array2 = " << char_array2 << endl << endl;

    swap(int1, int2);
    swap(char1, char2);
    swap(double1, double2);
    swap(char_array1, char_array2);

    cout << "--------------------------[swap 결과값 모음]-------------------------" << endl;
    cout << "int1 = " << int1 << " , int2 = " << int2 << endl;
    cout << "char1 = " << char1 << " , char2 = " << char2 << endl;
    cout << "double1 = " << double1 << " , double2 = " << double2 << endl;
    cout << "char_array1 = " << char_array1 << endl;
    cout << "char_array2 = " << char_array2 << endl << endl;

    return 0;
}
