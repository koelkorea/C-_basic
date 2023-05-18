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

// 
#include <string>
#include <iostream>
using namespace std;

// 사람 class - 생성자, 멤버함수
class human {

	protected:
		string name;
		string phone;

		human(string _name, string _phone) {
			name = _name;
			phone = _phone;
		}
};

// 학생 class - 생성자, 멤버함수
class student : protected human {

	protected:
		unsigned long studentId;
		string major;

		student(string _name, string _phone, unsigned long _studentId, string _major) : human(_name, _phone){
			studentId = _studentId;
			major = _major;
		}
};

// 졸업생 class - 생성자, 멤버함수
class graduate : protected student {

	public:
		string job;

		graduate(string _name, string _phone, unsigned long _studentId, string _major, string _job) : student(_name, _phone, _studentId, _major) {
			job = _job;
		}

		void showStudentInfo() {
			cout << "[졸업생 정보]" << endl;
			cout << "성    명 : " << name << endl;
			cout << "전화번호 : " << phone << endl;
			cout << "학    번 : " << studentId << endl;
			cout << "전    공 : " << major << endl;
			cout << "직    업 : " << job << endl;
		}
};

int main() {
	graduate graduateStudent("michelin", "010-1234-5678", 202312345, "Economics", "worker");
	graduateStudent.showStudentInfo();

	return 0;
}