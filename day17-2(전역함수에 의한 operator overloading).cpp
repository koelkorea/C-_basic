//전역함수에 의한 오버로딩
#include <iostream>
using namespace std;
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator+ (const Point& r) { // Point + Point
        Point temp;
        temp.x = this->x + r.x;
        temp.y = this->y + r.y;
        return temp;
    }
    Point operator- (const Point& r) {  // Point - Point
        Point temp;
        temp.x = this->x - r.x;
        temp.y = this->y - r.y;
        return temp;
    }
    Point& operator++() {
        x += 1;
        y += 1;
        return *this;
    }//반환값이 호출 객체자기 자신
    Point operator++(int) {
        Point temp;
        temp.x = x;
        temp.y = y;
        x += 1;
        y += 1;
        return temp;
    }
    inline int GetX() { return x; }
    inline int GetY() { return y; }
    friend Point operator+(int value, const Point& r); //전역함수를 자신의 멤버함수처럼 쓸 수 있다.
    friend Point operator-(int value, const Point& r); //전역함수를 자신의 멤버함수처럼 쓸 수 있다.
};
Point operator+(int value, const Point& r) { return Point(r.x + value, r.y + value); } // Value + Point
Point operator-(int value, const Point& r) { return Point(r.x - value, r.y - value); } // Value + Point
int main() {
    int x, y;
    cout << "첫 번째 x, y좌표 입력 : ";
    cin >> x >> y;
    Point p1(x, y);
    Point p2 = 10 + p1; //10.operator+(p1) //불가능 -> operator+(10, p1) //전역함수 오버로딩으로 해결
    cout << "p1(" << p1.GetX() << ", " << p1.GetY() << ")\n";
    cout << "p2(" << p2.GetX() << ", " << p2.GetY() << ")\n";
    ++++++p1;
    cout << p1.GetX() << ", " << p1.GetY() << "\n";
    p1++;
    cout << p1.GetX() << ", " << p1.GetY() << "\n";
    return 0;
}
