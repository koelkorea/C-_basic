#include <iostream>
using namespace std;
class Triangle {
public:

    double base, height;

    Triangle() {
        base = 0;
        height = 0;
        cout << "1. constructor call\n";
    }

    //Triangle(double _base, double _height) : base(_base), height(_height) {

    //}

    Triangle(double _base, double _height) {
        base = _base;
        height = _height;
        cout << "2. constructor call with parameter\n";
    }

    void initialize();
    void initialize(double _base, double _height);
    double getArea();
};
void Triangle::initialize() {
    base = 0;
    height = 0;
}
void Triangle::initialize(double _base, double _height) {
    base = _base;
    height = _height;
}
double Triangle::getArea() {
    return base * height / 2;
}
int main() {
    double b, h;
    cout << "밑변 입력 : ";
    cin >> b;
    cout << "높이 입력 : ";
    cin >> h;
    Triangle tri; //클래스 변수 선언 + 생성자  
    //Triangle tri(b, h); //클래스 생성자 변수 선언
    tri.initialize(b, h);  //초기화
    cout << "삼각형의 넓이는 " << tri.getArea() << "입니다.\n";
    return 0;
}
