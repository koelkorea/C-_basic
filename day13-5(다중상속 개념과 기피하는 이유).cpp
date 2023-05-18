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


//   # 상속의 유형별 분류
//     1. 단일 상속(single inheritance)
//         : 부모 클래스가 1개인 경우의 자식 클래스의 상속 
// 
//     2. 다중 상속(multiple inheritance)
//         : 부모 클래스가 n개인 경우의 자식 클래스의 상속 


//   # 클래스간 상속관계를 적용 할 수 있는 조건 
//      : A가 자손, B가 부모로 간주 (= B class를 상속해서, A 클래스 만들기 가능한 논리구조)
//         -> (핵심) 다중 상속 ㅈ같으니까, is만 있는거로 간주하는게 정신건강에 이로움!       
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
//      : Class 클래스명 : 접근제어자 부모클래스명1, ... ,  접근제어자 부모클래스명n {  내용   }
//         -> 다중 상속의 경우 ','를 사용, 상속받을 기초 클래스를 여러 개 가능하나..  권장 X

//        ex) 단일상속
//            class Student : public Person {           <- Student 클래스는 Person 클래스를 부모로 두고 상속 
//            
//               private:
//                   int student_id_;
//            
//               public:
//                   Student(int sid, char* name, int age) : Person(name, age) {  내용  }
//            };


//        ex) 다중상속 
//            class School : public Buliding, public ClassRoom, public Office {           <- School 클래스는 Buliding, ClassRoom, Office 클래스를 모두 부모로 두고 상속 
//            
//            };


//   # 다중 상속의 문제점
//     : 여러 개의 기초 클래스가 가진 멤버를 모두 상속받을 수 있다는 점에서 유용한 방법이지만, 단일 상속에 비해 다양한 문제를 발생

//       1. 상속받은 여러 기초 클래스에 같은 이름의 멤버가 존재할 가능성
//           ex) A::a = _a; B::a = _a; C::a = _a;
// 
//       2. 하나의 클래스를 간접적으로 두 번 이상 상속받을 가능성이 존재
//          (= virtual public Base 이슈)
// 
//       3. 추상 클래스를 쓰지 않는 이상, 부모 클래스 포인터변수로 해당 자식클래스를 가리킬 수 없음
//           -> 해당 자식 클래스 객체는 근본적으로 전혀 다른 계보의 부모클래스 타입들이 복수개로 이뤄짐 = 1개의 부모로는 그 자식의 모든 DNA를 알수 없다는 것 의미
//              (= 다중 상속을 쓰는 클래스는 일반적으로 OOP의 다형성의 혜택을 누릴 수 없기에 쉽게 역참조가 불가능하다는거 의미)
//
//       4. (점점 복잡하고 큰 서비스 코드에서) 1, 2, 3의 환장의 콜라보로 유연성이 너무 ㅄ + 스파게티 그 자체라 유지 관리가 불가능이 가까움
//
//       5. 반면, 단일 상속만 사용하여 잘 설계된 class는 약간의 수정으로 수많은 요청사항을 쉽게 이룩할 수 있음


// 다중상속 class 예시코드(Derived - Base_1, Base_2 다중상속)와 생성자 호출도 관련 예시코드
#include <iostream>
using namespace std;

class Base_1 {

	private:
		int _base_1;

	public:
		Base_1() : _base_1(20) {
			cout << "default 베이스 1 생성" << endl;
		}

		~Base_1() {
			cout << "베이스 1 소멸" << endl << endl;
		}

		Base_1(int n) : _base_1(n) {
			cout << "매개변수 베이스 1 생성" << endl;
		}

		void ShowBaseData() {
			cout << _base_1 << endl;
		}
};

class Base_2 {

	private:
		int _base_2;

	public:
		Base_2() : _base_2(40) {
			cout << "default 베이스 2 생성" << endl;
		}

		~Base_2() {
			cout << "베이스 2 소멸" << endl;
		}

		Base_2(int n) : _base_2(n) {
			cout << "매개변수 베이스 2 생성" << endl;
		}

		void ShowBaseData() {
			cout << _base_2 << endl;
		}
};

class Derived : public Base_1, public Base_2 {

	private:
		int _derived;

	public:
		Derived() : _derived(30) {
			cout << "default 파생 생성" << endl;
		}

		~Derived() {
			cout << "파생 소멸" << endl;
		}

		Derived(int n) : _derived(n) {
			cout << "매개변수 1 파생 생성" << endl;
		}

		Derived(int n1, int n2) : Base_1(n1), _derived(n2) {
			cout << "매개변수 2 파생 생성" << endl;
		}

		Derived(int n1, int n2, int n3) : Base_1(n1), Base_2(n2), _derived(n3) {
			cout << "매개변수 3 파생 생성" << endl;
		}

		void ShowDerviedData() {
			Base_1::ShowBaseData(); Base_2::ShowBaseData(); cout << _derived << endl;
		}
};
int main() {
	Derived dr1;             //case1 : default 객체 생성
	dr1.ShowDerviedData();    cout << endl << endl;
	Derived dr2(12);         //case2 : 매개변수 1개 객체 생성
	dr2.ShowDerviedData();    cout << endl << endl;
	Derived dr3(23, 24);     //case2 : 매개변수 2개 객체 생성
	dr3.ShowDerviedData();    cout << endl << endl;
	Derived dr4(23, 24, 25); //case3 : 매개변수 3개 객체 생성
	dr4.ShowDerviedData();    cout << endl << endl;
	return 0;
}
