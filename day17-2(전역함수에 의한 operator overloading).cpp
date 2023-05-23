//�����Լ��� ���� �����ε�
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
    }//��ȯ���� ȣ�� ��ü�ڱ� �ڽ�
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
    friend Point operator+(int value, const Point& r); //�����Լ��� �ڽ��� ����Լ�ó�� �� �� �ִ�.
    friend Point operator-(int value, const Point& r); //�����Լ��� �ڽ��� ����Լ�ó�� �� �� �ִ�.
};
Point operator+(int value, const Point& r) { return Point(r.x + value, r.y + value); } // Value + Point
Point operator-(int value, const Point& r) { return Point(r.x - value, r.y - value); } // Value + Point
int main() {
    int x, y;
    cout << "ù ��° x, y��ǥ �Է� : ";
    cin >> x >> y;
    Point p1(x, y);
    Point p2 = 10 + p1; //10.operator+(p1) //�Ұ��� -> operator+(10, p1) //�����Լ� �����ε����� �ذ�
    cout << "p1(" << p1.GetX() << ", " << p1.GetY() << ")\n";
    cout << "p2(" << p2.GetX() << ", " << p2.GetY() << ")\n";
    ++++++p1;
    cout << p1.GetX() << ", " << p1.GetY() << "\n";
    p1++;
    cout << p1.GetX() << ", " << p1.GetY() << "\n";
    return 0;
}
