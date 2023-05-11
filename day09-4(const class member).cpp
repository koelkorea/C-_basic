//  - class의 멤버변수 상수화
//     : C++에서는 클래스의 멤버변수를 선언할 때 초기화 값을 대입하는거 자체가 허용 X되는 점에서 문제 발생
//       (= 생성자 함수를 통해 class 객체의 동적 할당과 동시에 값을 대입하려고 해봐야, 이미 객체가 생성되는 과정에서 먼저 상수인 멤버변수가 쓰레기값을 가지고 초기화를 마쳐버리게 됨)
//          -> 생성자 선언을 통해 객체가 만들어 지기 전에 상수에 초기화된 값을 대입할 수 있어야 하는 방법이 필요함..
//              -> 초기화 리스트(Initialize List)를 통해  ":" 콜론을 사용한 멤버변수 초기화값을 대입하는 방법은 생성자 함수의 정의부보다 먼저 수행된다는 점을 이용함
// 
//      # class의 멤버변수 상수화 예시
// 	  
//           ex) class TMP{
//                  const int const_int;                <- 초기화 불가능
//                  TMP(int num) : const_int(num) { }

// class 멤버상수 코드 사용 예시 코드
#include <iostream>
#include <cstring>

class Student {

    private:

        // const 멤벼변수 존재시
        const int number;
        char name[20];
        int age;

    public:

        // [class 멤버상수를 초기화하려면, 일반 생성자로는 불가능]
        // Student(int Num, const char* pN, int a) {
        //     number = Num;
        //     strcpy_s(name, strlen(pN) + 1, pN);
        //     age = a;
        // }

        // 초기화 리스트(Initialize List) 방식으로 class 멤버상수 number를 :생성자를 통해 기입하면 가능
        Student(int Num, const char* pN, int a) : number(Num) {
            //number = Num;   <- 물론 이 방법으로는 여전히 접근 및 수정이 불가능
            strcpy_s(name, strlen(pN) + 1, pN);
            age = a;
        }
};

int main() {

    Student s1(20221234, "michelin", 21);
    Student s2(20231234, "christopher", 20);

    return 0;
}
