// 객체
//  : 선언된 클래스(class)를 호출하고, 이를 구체화 한 인스턴스 변수를 선언하면 그것을 하나의 객체라고 함

//   # class? 객체? 인스턴스 변수? 
//     : 대충 class는 원본 설계도, 객체는 그 설계도로 만들어질 수 있는 모든 추상화된 개체들, 인스턴스는 현실에 강림한 개체로 이해하면 됨
// 
//     1. class   
//       : 구현하려는 대상의 속성과 행위를 그룹화하고 규정한 자료형 단위로 개별 객체의 뼈대인 '설계도'와 같은 개념 
//          ex1) 이데아에 존재하는 개새끼  <- 플라톤이 현실 모든 개들의 기반이 되는 모든 속성을 가진다 주장
//          ex2) 기독교의 신께서 창조하시고자 하는 영적존재인 천사의 개념
// 
//     2. 객체    
//       : 그 class의 속성과 행위를 구체화시켜 만들어질 수 있는 모든 독립적 개체들의 개념
//          ex1) 이데아의 개새끼를 원형으로, 만들어질 수 있는 이론상으로 존재 가능한 범주의 모든 개새끼들
//          ex2) 생각하신 개념에 따라 신께서 창조하실 가능성이 있는 모든 범주의 개별 천사들 그 자체
//                   
//     3. 인스턴스
//       : class를 통해 만들어질 수 있는 객체가 구현되어 현실(= 메모리)상에 존재하는 경우
//          ex1) 이데아의 개새끼를 원형으로 한 객체 중 하나인 어떤 '말티즈' 개체인 멈뭄이가 우리집에 태어남
//          ex2) 실제로 창조되어 활동하는 13체의 천사장들

//   # 객체화
//     : 특정한 class의 내용을 구체적으로 구현하여, 하나의 독립된 개체(= 인스턴스)로 완성하는 과정을 의미
//        -> 대충 class를 인스턴스로 구체화시키거나, 이를 위해 멤버내용을 채우는 과정으로 이해해도 됨 
//            ex) car 클래스의 인스턴스로 'genesis'를 생성하여, car 클래스를 '객체화'하였음
// 
// 
//   # 왜 이런 구분을 하나?
//     : 끽해야 속성(변수)만 존재했던 C언어의 자료형들과 다르게, 객체지향언어인 C++에서는 class에 동사적 의미를 가지는 멤버함수가 존재하기 때문
//        -> class를 기반으로 한 변수인 인스턴스에게 멤버함수에 해당하는 내용을 수행하라고 명령하는 코드를 이해하기 위해서는, 해당 인스턴스를 어떤 행동(= 함수)의 대상이 되는 객체로서 이해하는게 빠르기 때문
//            ex) Car* asrada = new Car;
//                asrada.changeForm(ground);       <- 자동차인 아스라다에게 황무지 타입으로 형태를 바꾸는 동작을 취하라고 명령하는 의미로 받아들이면 편해짐

// class의 객체화를 통한 삼각형 구하기 예시
#include <iostream>
using namespace std;

// 삼각형 class
class Triangle {

public:

	//밑변, 높이
	int base, height;

	// 멤버함수
	void SetTriangle(int _base, int _height);
	double GetArea();
};

//  해당 삼각형 인스턴스의 밑변과, 높이값을 입력해주는 삼각형 class의 멤버함수 SetTriangle
void Triangle::SetTriangle(int _base, int _height) {
	base = _base;
	height = _height;
}

// 해당 삼각형 인스턴스의 넓이를 구해주는 삼각형 class의 멤버함수 GetArea
double Triangle::GetArea() {
	return base * height / 2.0;
}

int main() {

	// 밑변 입력
	cout << "밑변 : ";
	int base;
	cin >> base;

	// 높이 입력
	cout << "높이 : ";
	int height;
	cin >> height;

	// 삼격형 class기반의 인스턴스 t를 선언 및 초기화 (class 초기화는 생성자 없어도 됨)
	Triangle t;

	// 삼각형 class 인스턴스 t의 멤버변수인 밑변, 높이의 값을 입력받은 대로 입력해누는 함수 SetTriangle 실행
	t.SetTriangle(base, height);

	// 삼각형 class 인스턴스 t의 넓이를 표기
	cout << "삼각형의 넓이는 " << t.GetArea() << "입니다.\n";
}