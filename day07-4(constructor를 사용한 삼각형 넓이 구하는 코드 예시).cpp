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
        // 생성자 {}안에 parameter에 따른 변수 주입
        Triangle(double _base, double _height) {
            base = _base;
            height = _height;
            cout << "2. constructor call with parameter\n";
        }

        // 초기화 리스트(Initialize List)를 사용한 :연산자 통한 생성자 선언 및 정의
        Triangle(double _base, double _height, int flag) : base(_base), height(_height) {
            cout << "3. constructor call with parameter (by Initialize List)\n";
            cout << "    -> flag 파라미터는 기본 생성자 함수와 구분을 짓기 위해 썼습니다!\n";
        }

        // --------------------------------------- [기존 초기화 함수를 통한 초기화 법]------------------------------------------------
        void initialize();
        void initialize(double _base, double _height);
        //-------------------------------------------------------------------------------------------------------------------------

        double getArea();
};

// --------------------------------------- [기존 초기화 함수를 통한 초기화 법]------------------------------------------------
void Triangle::initialize() {
    base = 0;
    height = 0;
}

void Triangle::initialize(double _base, double _height) {
    base = _base;
    height = _height;
}
//-------------------------------------------------------------------------------------------------------------------------

double Triangle::getArea() {
    return base * height / 2;
}

int main() {

    double b, h;

    cout << "밑변 입력 : ";
    cin >> b;

    cout << "높이 입력 : ";
    cin >> h;

    // 1. 기존 클래스 변수 선언 후, 초기화 함수를 사용한 멤버변수 값 대입  
    Triangle tri1; 
    tri1.initialize(b, h);

    // 2. 클래스 생성자를 통해 멤버변수 값 대입한 클래스의 객체를 선언하기
    Triangle tri2(b * 2, h * 3); 
    Triangle tri3(b * 10, h * 10);

    cout << "삼각형 tri1의 넓이는 " << tri1.getArea() << "입니다.\n";
    cout << "삼각형 tri2의 넓이는 " << tri2.getArea() << "입니다.\n";
    cout << "삼각형 tri3의 넓이는 " << tri3.getArea() << "입니다.\n";
    return 0;
}
