// 객체
//  : 선언된 클래스에 변수를 선언하면 하나의 객체라고 함

//   # class? 객체? 인스턴스 변수?
//     : 자료형(class, 객체형) 변수(객체, 인스턴스 변수)

//ACT act_1, act_2, act_3, act_4, act_5, act_6;
//객체 1, 객체 2, 객체 3, 객체 4, 객체 5, 객체 6,

//   # 왜 이런 구분을 하나?
//     : 

// class와 객체화를 통한 삼각형 구하기 예시
#include <iostream>
using namespace std;
class Triangle {
public:
	int base, height; //밑변, 높이
	void SetTriangle(int _base, int _height);
	double GetArea();
};
void Triangle::SetTriangle(int _base, int _height) {
	base = _base;
	height = _height;
}
double Triangle::GetArea() {
	return base * height / 2.0;
}
int main() {
	cout << "밑변 : ";
	int base;
	cin >> base;

	cout << "높이 : ";
	int height;
	cin >> height;

	Triangle t; //삼각형 클래스
	t.SetTriangle(base, height);

	cout << "삼각형의 넓이는 " << t.GetArea() << "입니다.\n";
}
