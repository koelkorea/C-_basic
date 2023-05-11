//  - class의 멤버함수 상수화
//     : 상수화 선언된 멤버함수의 스코프 {}안에서는 오로지 멤버변수들의 값을 참조만 가능함 
//       (= (중요) 다시 말해 해당 함수 내에서는 모든 멤버변수는 상수처럼 인식)
//           ->  당연히 멤버변수의 값에 변동을 줄수 있는 일반함수를 호출하거나, 역참조 방지를 위해 멤버변수의 주소값조차 return이 허용되지 않음)
// 
//      # class의 멤버함수 표기법
//         : 자료형 함수명(parameter) const{ 내용 };  
// 	  
//           ex) void show() const { 
//                  cout << setw(10) << number << ' ' << setw(15) << name << endl;       <- 오로지 맴버변수 참조만 가능
//               }

//      # 상수화된 class의 멤버함수 작성시 주의
//         1. 멤버변수의 수정x
//         2. 일반함수 호출 x
//         3. 멤버변수의 주소값 리턴 x

//      # 상수화된 class의 멤버함수의 사용 목적?
//         : 가장 큰 목적은 class 객체의 상태를 변경하지 않는 함수를 정의 
//            -> 1. 멤버변수의 불변성을 보장 = 접근제어자를 통한 멤버변수 접근 권한 통제를 더 확실히 보장이 가능함
//               2. 프로그래머가 객체의 내부 상태를 변경할 수 없도록 보장함으로써 코드의 안정성을 높일 수 있음
//                  (= 1, 2를 종합하면 객체를 보다 쉽게 병렬화하거나, 캐싱하거나, 재사용하는 등의 최적화를 쉽게 할 수 있다는 결론에 이름)

// 상수 class 멤버함수 사용 예시 코드
#include <iostream>
#include <iomanip>// setw
#include <cstring>

using namespace std;

class Student {

    private:

        const int number;
        char name[20];
        int age;

    public:

        Student(int Num, const char* pN, int a) : number(Num) {
            //number = Num;
            strcpy_s(name, strlen(pN) + 1, pN);
            age = a;
        }

        // 상수 class 멤버함수 예시 (멤버변수 값의 참조만 가능.. 그 외 어떤 멤버변수 변조를 위한 가능성이 있는 행위(멤버변수 포인터, 일반함수 호출) 금지)
        void Show() const {
            //age = 22;   <- 멤버변수 수정 불가능
            cout << setw(10) << number << ' ' << setw(15) << name << ' ' << setw(5) << age << endl;
        }

};
int main() {

    Student s1(20221234, "michelin", 21);
    Student s2(20231234, "christopher", 20);

    s1.Show();
    s2.Show();

    return 0;
}
