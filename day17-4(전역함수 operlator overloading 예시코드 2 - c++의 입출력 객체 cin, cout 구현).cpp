
/*  cin으로 Point 객체 입력 / cout으로 Point 객체 출력
     - cin은 istream 클래스의 객체, cout은 ostream 클래스의 객체.
     - istream이나 ostream 클래스의 변경이 불가능 (멤버함수에 의한 연산자 오버로딩이 불가능)
        -> 전역함수의 의한 오버로딩으로 처리
*/
#include <iostream>
using namespace std;

class Point {

	private:
		int x, y;

	public:
		Point(int x = 0, int y = 0) : x(x), y(y) {}
		inline void SetX(int x) { this->x = x; }
		inline void SetY(int y) { this->y = y; }
		inline int GetX() const { return x; }
		inline int GetY() const { return y; }

		// friend 전역함수
		friend ostream& operator<<(ostream& out, Point& p); 
		friend istream& operator>>(istream& in, Point& p);
};

// 전역함수 정의부 구현
// : 출력class인 ostream class객체의 << 연산자
ostream& operator<<(ostream& out, Point& p) {
	out << p.x << ", " << p.y; 
	return out; 
} 

// 전역함수 정의부 구현
// : 입력class인 istream class객체의 << 연산자
istream& operator>>(istream& in, Point& p) {
	in >> p.x >> p.y;
	return in; 
}

int main() {
	int x, y;
	cout << "\n x, y좌표 입력 (공백구분) : ";
	cin >> x >> y;

	//객체 생성
	Point p1(x, y); 

	// cout으로 point  객체 출력
	cout << "p1( " << p1 << ")\n";  

	// 전역함수로 선언되어 있는지라, 멤버함수 쓰는 cout.opearator<<(p1); 불가능
	//  -> 전역함수에 의한 오버로딩으로 해결
	operator<<(cout, p1);

	Point p2;
	cout << "\n x, y좌표 입력 (공백구분) : ";

	// 전역함수에 의한 오버로딩으로 해결
	cin >> p2; 

	// cout으로 point 객체 출력
	cout << "p2( " << p2 << ")\n";

	// 전역함수로 선언되어 있는지라, 멤버함수 쓰는 cout.opearator>>(p2); 불가능
	//  -> 전역함수에 의한 오버로딩으로 해결
	operator<<(cout, p2);

	return 0;
}
