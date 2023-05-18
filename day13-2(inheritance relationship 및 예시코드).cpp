﻿﻿// 클래스 상속(class inheritance) 
//  : 기존에 존재하는 class의 모든 멤버속성들을 물려받고
//     -> 이를 베이스로 새로운 기능(= 함수)이나 속성(= 데이터)을 추가하여 확장된 새로운 클래스를 구현이 가능한 객체지향언어의 특성
//         -> 참고로 부모의 멤버함수의 경우는 오버라이드하여 새로 작성이 가능함


//   # 상속 이해 필수 용어
//      1. 부모 클래스 (base, super, parent class)
//          : 어떤 클래스가 상속관계를 통해 특정 클래스의 멤버속성의 기반이 되는 경우에 상위 클래스로 분류될때 붙여지는 이름
//            (= 베이스, 상위, 슈퍼, 기초 class 라고도 불림)

//      2. 자식 클래스(derived, sub, child class)
//         : 어떤 클래스가 상속관계를 통해 특정 클래스의 멤버속성의 기반으로 새롭게 작성되는 경우에 하위 클래스로 분류될때 붙여지는 이름
//            (= 파생, 하위 클래스 라고도 불림)


//   # 자식 클래스의 구성
//      = 부모 클래스의 모든 멤버 + 자식클래스 추가 멤버 ( 속성 : data + 기능 : function )


//   # 상속의 유형별 분류
//     1. 단일 상속(single inheritance)
//         : 부모 클래스가 1개인 경우의 자식 클래스의 상속 
// 
//     2. 다중 상속(multiple inheritance)
//         : 부모 클래스가 n개인 경우의 자식 클래스의 상속 
//            -> (중요!) 다중상속이면 자식클래스 선언시 먼저 선언한 부모class부터 호출! 


//   # class 상속 특징 
//     1. 클래스 간의 계층적 관계를 구성함 (= 모듈화, 다형성의 기반)
//         -> 기존에 작성된 공통적인 부분을 기초 클래스에 설계함 (= 효과적으로 재활용하는 기발함)
//         -> 반면 새로운 데이터, 연산은 자식 클래스에 설계하여 구현
// 
//     2. 자식 클래스의 특성
//         a. 부모 클래스의 모든 멤버를 사용 가능하며, 멤버함수는 오버라이드도 가능함
//         b. 자식 클래스는 필요한 만큼 멤버변수나 함수를 추가해도 문제없음
//         c. (중요!) 단! 자식 클래스는 반드시 자신만의 생성자가 필요함 (물론 기본으로 주어짐)
//         d. 상속관계 작성시, 부모 클래스와의 접근제어자 관계 규정 X면, 기본값이 private
// 
//     3. 상속할 클래스는 복수개도 가능은 함 (= 다중 상속)
//         -> 구성이 ㅈ같아짐으로 후기언어에서는 배제


//   # 클래스간 상속관계를 적용 할 수 있는 조건 
//      : A가 자손, B가 부모로 간주 (= B class를 상속해서, A 클래스 만들기 가능한 논리구조)
//         -> (핵심) 다중 상속 ㅈ같으니까, is만 있는거로 간주하는게 정신건강에 이로움! 
// 
//      1. A is B (= 이다)
//         : 개별 존재 개체들을 요소의 단위 기준으로 놓고, 그들을 구분하는 개념들을 세세하게 나누고, 포괄적인 개념 <-> 개체 중 어디에 더 가까운지를 기준으로 상속관계를 만듦
// 
//           -> 부모 클래스 B로 표기되는 경우가 많은 CLASS
//               : 대분류에 해당하는 개념일수록 상위클래스 (= 모든 실체를 포괄하는 단 하나의 개념이 가장 최고 선조 클래스)
// 
//           -> 자식 클래스 A로 표기되는 경우가 많은 CLASS
//               : 소분류에 해당하는 개념일수록 하위클래스 (= 실체하는 것은 가장 후손에 해당하는 클래스)
// 
//      
//           ex) 학생은 사람이다 (= 사람 class를 상속해서, 학생 클래스 만들기 가능)
//               사과는 과일이다
//               토끼는 동물이다
// 
//           ex) is 상속 관계도 예시 (<-> Has 상속 관계도)
//               -> (중요!) is 기반의 상속관계는 모든 class의 조상 역할을 하는 class가 하나 있고, 확장된 개념들이 자손으로 주렁주렁 달리는 식으로 관계트리가 이뤄짐
//
//                            과일(최선조)
//                        -------------------
//                     복숭아             파충류 
//                  --   --  --        --   --   --
//                천도  백도 천도     캠밸  머루  거봉            
//      
//      2. A Has B (= 포함관계)
//         : 존재들의 특성 자체들을 요소의 단위 기준으로 놓고, 원시형 변수나 분자마냥 분리할 수 없는 특성들을 나열하여 최선조들로 설정하고, 하위 존재이자 특성들은 이들을 [다중상속]하는 하위클래스로 간주하는 식으로 상속관계를 만듦
//           (= 대충 4원소론의 물, 불, 흙, 공기과 같이 모든 존재의 근간을 이루는 녀석이 있다면, 그 녀석들이 최선조 class로 간주됨.. 실제로 엠페도클레스도 생물은 이들이 얼마나 조합되냐고 구분했음)
//         
//           -> 부모 클래스 B로 표기되는 경우가 많은 CLASS
//               : 쪼개질 수 없고, 모든 존재의 근원이 되는 특성에 가까운 개념 (= 더 분리될 수 없는 특성 혹은 개념들 모두가 최선조)
// 
//           -> 자식 클래스 A로 표기되는 경우가 많은 CLASS
//               : 많은 특성을 가지고 있거나 포함하는 복합적인 존재나 개념 (= 실체하는 존재나 개념 중에서도 가장 포괄적인 개념이 가장 후손에 해당하는 클래스)
// 
// 
//           ex) 교실엔 책상이 포함되어 있음 (= 책상 class를 상속해서, 교실 클래스 만들기 가능)
//               숲엔 나무가 포함되어 있음
//               상품엔 제조일자가 포함되어 있음
// 
// 
//           ex) Has 상속 관계도 예시 (<-> is 상속 관계도)
//               -> (중요!) Has 기반의 상속관계는 모든 class의 최후손 class가 하나 있고, 그 후손을 구성하는 선조들이 쪼개질 수 없을 때까지 주렁주렁 달리는 식으로 관계트리가 이뤄짐
//
//                 불    흙    물   공기   공허  에너지  (최선조 list)
//                  ----- -----      |       ------
//                 마그마  대지       |      중력, 인력   
//                     ----- --------------------
//                      태양        지구
//                        ------------
//                            행성


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


//      - 상속된 자식class의 생성자의 초기화리스트(initial list)의 부모class 생성자 대입되는 경우? 의 자식 객체 생성 과정

//         1. 해당 케이스 생성자의 의미 및 자식 객체 생성 과정
//           : 자식class의 생성자 함수 중 :을 써서 일부 parameter들을 생성자 함수에 호출(= 대입)하는 경우, 초기화 리스트(Initialize List)의 원칙으로
//              -> 1단계) 자식 class 생성자의 정의부 실행전에, 자식의 기반인 부모class의 생성자 함수를 먼저 호출하는데 일부 parameter를 사용하여 부모 객체를 생성하고 부모의 멤버변수를 초기화하는데 사용
//              -> 2단계) 그 부모class도 자신의 부모가 존재하는 경우, 부모의 생성자도 마찬가지로 자신의 부모 생성자를 초기화 리스트(Initialize List) 방식으로 호출하면, 마찬가지로 함수 stack 이 쌓이며, 결국 최선조의 객체가 먼저 생성됨
//              -> 3단계) 그렇게 [최후손 class 선언부 -> ... -> 최선조 객체의 선언부, 정의부 실행 -> ... -> 최후손 class 정의부 실행] 패턴대로 생성자 함수가 실행된 결과 자식 class객체가 탄생함

//         2. 해당 케이스의 작성 형식 예시
//           : Class 클래스명 : 접근제어자 부모클래스명1, ... ,  접근제어자 부모클래스명n {
//                클래스명(int param1, .... ,  int paramN) : 부모클래스명1(param1...), .. ,  부모클래스명n(paramN...) 
//             }
// 	    
//             ex) 다중상속 클래스의 생성자에서의 부모생성자를 초기화리스트에 쓴 경우
//                  -> School 클래스 생성자를 작성하면, 그 부모들인 Buliding, ClassRoom, Office 생성자가 먼저 호출되어 그들의 객체가 생성됨
// 	    
//                 class School : public Buliding, public ClassRoom, public Office {           <- School 클래스는 Buliding, ClassRoom, Office 클래스를 모두 부모로 두고 상속 
//                 
//                     School(int _width, int _height, int _students_size, int _class_size, int _teacher_size, string _school_name) : Buliding(_width, _height), ClassRoom(_students_size), Office(_teacher_size) {
//                          school_name = _school_name;
//                     }
//                 };


//   # (복습) 초기화 리스트(Initialize List) 
//      : (중요!) 콜론(:)을 이용하는 초기화법, 정의부보다 우선하여 실행된다는 장점이 있어, const 멤버변수의 초기화에 쓰임                        
//         -> 클래스명(자료형 parameter명...) : 가담O 멤버변수(parameter명) , ...  { 가담X 멤버변수 = parameter 사용하거나 가공한 값 }												
//                                                        
//            ex) class A 멤버는 다음과 같다 가정 ( int a; double b; char c; )
//	        
//                A (int _a, double _d, char _c) : a(_a), c(_c) {
//                    b = _b;
//                }

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


// Person 클래스을 부모 클래스로 삼아 상속관계를 통해 만들어진 student 클래스
#include <iostream>
#include <cstring>

using namespace std;

// 부모 클래스 Person
class Person {

    private:
        char* name_;
        int age_;

    public:

        Person(char* name, int age) {

            int len = strlen(name) + 1;
            name_ = new char[len];

            strcpy_s(name_, strlen(name) + 1, name);
            age_ = age;

            cout << "베이스 클래스 생성 완료\n";
        }

        ~Person() {
            delete[] name_;
            cout << "베이스 클래스 소멸 완료\n";
        }

        void ShowPersonInfo() { cout << "name :" << name_ << "\nage :" << age_ << endl; }
};

// 상속 관계에 놓인 class의 형식
//  -> Class 클래스명 : 접근제어자 부모클래스명1 {  내용   }

// 자식 클래스 Student
class Student : public Person {

    private:
        int student_id_;

    public:

        // 자식클래스 생성자 작성시 부모 생성자의 어떤 생성자 함수가 관련되는지 상속관계를 선언해 놔야함
        //  -> 자식 클래스 student는 부모클래스의 생성자가 기반이 되기에, 부모객체부터 생성 후 거기에 자식의 멤버들을 구성하는 구조
        Student(int sid, char* name, int age) : Person(name, age) {
            student_id_ = sid;
            cout << "파생 클래스 생성 완료\n";
        }

        ~Student() { 
            cout << "파생 클래스 소멸 완료\n"; 
        }

        void ShowStdInfo() { 
            cout << "Student number :" << student_id_ << endl; 

            // 부모로 부터 ShowPersonInfo()의 멤버함수 또한 이어받기에 사용가능
            //  -> 오버라이드 하면 자식 자신의 방식대로 사용 가능
            this->ShowPersonInfo(); 
        }
};

int main() {

    Student std_1(20230000, (char*)"michelin", 20);
    std_1.ShowStdInfo();
    return 0;
}

// ---------------------------------  <- 생성
// 베이스 클래스 생성 완료
// 파생 클래스 생성 완료
// ---------------------------------  <- 실행
// Student number : 20230000
// name : michelin
// age : 20
// ---------------------------------  <- 소멸
// 파생 클래스 소멸 완료
// 베이스 클래스 소멸 완료
// ---------------------------------