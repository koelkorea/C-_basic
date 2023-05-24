//   # (중요!) 연산자 오버로딩(operator overloading)시 주의사항
//      1. 가급적 연선자의 기능을 그 어떤 사람이 보더라도 같은 의미로 통할 수 있도록 작성
//          -> 객체에 따라 같은 연산자를 다른 방식으로 처리하는 식으로 작성하지 말라는 것
//      2. 연산자 간의 우선순위와 결합성은 바뀌지 않음
//      3. defalut parameter 설정이 불가능!
//      4. (중요!) 기본 선언되어 제공되는 연산자함수나, 본래부터 있었던 class 내부의 경우에는 그 멤버 연산자함수를 오버로딩 불가능!
//          ->  전역함수의 의한 오버로딩으로 처리해서 해결 가능
// 
//              ex) istream이나 ostream 클래스의 멤버연산자함수에 대한 내용은 건들수 없음 (= 멤버함수에 의한 두 class의 비트연산자 오버로딩이 불가능)
//                   -> (중요) ostream&, istream&을 반환하는 전역 연산자함수operator<<에 의한 오버로딩으로 처리가능

//   # 전역 연산자함수를 쓰는 이유
//      1. 본래부터 있었던 class 내부의 경우에는 그 멤버 연산자함수를 오버로딩하여 추가하는 것이 불가능하기 때문임
//          -> 그래서 전역함수로 이를 채워넣는 식으로 해결함
//      2. 어떤 객체나 변수가 될 수 없는 상수가 1번째 연산대상으로 연산에 들어가는 경우에는, 멤버 연산자함수가 호출이 불가능하기 때문
//          -> 단순히 모든 연산대상을 변수건 상수건 상관없이 overloading 해서 parameter로 넣어 추가 선언 및 정의하면 장떙인, 전역 연산자함수 사용


// [전역 연산자함수 overloading 예시코드1 - 본래부터 있었던 class 내부의 경우에는 그 멤버 연산자함수를 오버로딩하여 추가하는 것이 불가능한 case]
// 
// friend 전역함수와 operator overloading을 통해, ostream과 iostream class의 비트연산자(<<, >>) overloading하기
//  : cin은 istream 클래스의 객체, cout은 ostream 클래스의 객체 == 그 두 class의 연산자의 내용을 overloading 해서 추가해줘야 함
// 
//   1. '<<' overloading 시작 이유 
//      : istream 객체 cin과 ostream 객체 cout의 비트연산자(<<, >>)는 사용자 정의 class 객체에 대해서 어떠한 선언도 되어있지 않음 = 비트연산자 백날 써봐야 사용자 class객체는 입/출력 씨알도 안 먹힘
// 
//   2. 조치해야 하는 것
//      : ostream과 iostream이 사용자 class객체를 외부영역에서 연산대상으로 삼을 경우, 이를 수행할 수 있도록 비트연산자(<<. >> )함수에 대한 overloading된 내용을 작성
//         -> 최종적으로 외부영역에서 사용자 정의 class 객체에 대해서도 cin, cout 객체가 비트연산자를 통해 입,출력이 가능하도록 조치하기

// cin으로 사용자 정의 class Point의 객체의 내용을 입력 / cout으로 사용자 정의 class Point의 객체의 내용을 출력가능하게, ostream과 iostream class의 비트연산자(<<, >>)함수를 overloading하는 예시코드
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
		//  ->  istream이나 ostream 클래스의 멤버연산자함수에 대한 내용은 건들수 없음 (= 멤버함수에 의한 두 class의 비트연산자 오버로딩이 불가능)
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
