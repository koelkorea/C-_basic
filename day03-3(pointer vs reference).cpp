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

// pointer와 reference로 구현한 동일 함수
#include <iostream>
using namespace std;

// reference 변수를 parameter로 받는 함수
void input(int& p1, double& p2) {
    // int& p1 = a2, double& p2 = d2
    cout << "정수입력 : ";
    cin >> p1;
    cout << "실수입력 : ";
    cin >> p2;
}

// pointer 변수를 parameter로 받는 함수
void input(int* p1, double* p2) {
    // int* p1 = &a1, double* p2 = &d1
    cout << "정수입력 : ";
    cin >> *p1;
    cout << "실수입력 : ";
    cin >> *p2;
}

int main() {

    cout << "[pointer로 만든 동일 함수]" << endl;

    int a1;
    double d1;
    input(&a1, &d1);
    cout << a1 << ", " << d1 << endl << endl;

    cout << "[reference로 만든 동일 함수]" << endl;

    int a2;
    double d2;

    // 해당 함수가 받는 param은 reference 변수지만, 호출할때 대입하는 param은 깔끔하게 일반 변수로 해도 무방하다.. 
    // (= 쉽게 말해, 굳이 다른 reference 변수를 만드는 수고를 안해도 된다 이말이다..)
    input(a2, d2);
    cout << a2 << ", " << d2 << endl;


    return 0;
}
