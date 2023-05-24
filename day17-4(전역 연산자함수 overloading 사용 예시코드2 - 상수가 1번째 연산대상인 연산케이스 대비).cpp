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


// [전역 연산자함수 overloading 예시코드2 -  어떤 객체나 변수가 될 수 없는 상수가 1번째 연산대상으로 연산에 들어가는 경우에는, 멤버 연산자함수가 호출이 불가능한 case]
// 상수가 1번째 연산대상으로 잡힌 case를 위해, 전역 연산자함수 오버로딩 작성 및 멤버함수 제끼고 호출하는 과정 (day17-1 코드에 추가 내용 덧붙힘)
#include <iostream>
using namespace std;

class Point {

    private:
        int x, y;

    public:
        Point(int x = 0, int y = 0) : x(x), y(y) {}

        // point class 객체로 +연산을 할 경우에 대한 오버로딩
        Point operator+ (const Point& r) {

            Point temp;

            // parameter로 주어진 Point class 레버런스 객체 r의 x, y값을 연산자+ 멤버함수를 호출한 객체의 x, y값에 더하고 나서 
            //  -> 그 x,y 값을 멤버로 가진 tmp라는 point class 객체를 반환
            temp.x = this->x + r.x;
            temp.y = this->y + r.y;

            return temp;
        }

        // point class 객체로 -연산을 할 경우에 대한 오버로딩
        Point operator- (const Point& r) {

            Point temp;

            // parameter로 주어진 Point class 레버런스 객체 r의 x, y값을 연산자- 멤버함수를 호출한 객체의 x, y값에 더하고 나서 
            //  -> 그 x,y 값을 멤버로 가진 tmp라는 point class 객체를 반환
            temp.x = this->x - r.x;
            temp.y = this->y - r.y;

            return temp;
        }

        // 전치 연산자 ++ 오버로딩 (parameter가 없음)
        Point& operator++() {

            // (중요) 연산자++ 멤버함수를 호출한 객체의 x, y값에 1씩 더하고 나서
            //  -> 전치연산자는 객체 그 자신을 point 레퍼런스객체 형식으로 반환하는 특수성이 존재
            x += 1;
            y += 1;

            // (중요) 전치연산자는 반환값이 호출 객체 자기자신의 포인터를 역참조하여 호출 객체 자기자신을 반환하는 특수성이 존재
            // (= 자기 자신을 향한 연산을 계속 가능함)
            return *this;
        }

        // 후치 연산자 ++ 오버로딩 (parameter가 int가 쓰인거로 구분)
        //  -> (중요!) 후치 연산자의 경우 중첩 사용은 가독성과 예측 가능성 문제가 생기기에, 객체 자신의 레버런스변수를 반환하지 않음
        Point operator++(int) {

            Point temp;

            // 전위 연산자++ 멤버함수를 호출한 객체의 x, y값에 1씩 더하고 나서 
            //  -> 그 x,y 값을 멤버로 가진 tmp라는 point class 객체를 반환
            //     (= 원본 대상에는 1도 문제없고 마지막 1번의 연산만 대입됨)
            temp.x = x;
            temp.y = y;

            x += 1;
            y += 1;

            return temp;
        }

        inline int GetX() { return x; }
        inline int GetY() { return y; }

        // (point class 멤버 연산자+함수에 없음) int값과 point 객체를 대상으로 하는 전역 연산자 +함수를 자신의 멤버함수처럼 쓸 수 있음
        friend Point operator+(int value, const Point& r);

        // (point class 멤버 연산자-함수에 없음) int값과 point 객체를 대상으로 하는  전역 연산자 -함수를 자신의 멤버함수처럼 쓸 수 있음
        friend Point operator-(int value, const Point& r);
};

// [전역 연산자 함수]
//  : (중요!) 함수명으로 호출 하려면 '전역연산자함수명(parameter1, parameter2);' 와 같은 형식으로 호출
//   
// point 객체를 대상으로 하는 전역 연산자 +함수
Point operator+(int value, const Point& r) {

    // value 값을 x, y에 각각 더한 결과를 parameter로 넣은 Point 생성자 자체를 반환
    return Point(r.x + value, r.y + value);
}

// point 객체를 대상으로 하는 전역 연산자 -함수
Point operator-(int value, const Point& r) {

    // value 값을 x, y에 각각 빼 결과를 parameter로 넣은 Point 생성자 자체를 반환
    return Point(r.x - value, r.y - value);
}

int main() {

    int x, y;
    cout << "첫 번째 x, y좌표 입력 : ";
    cin >> x >> y;

    Point p1(x, y);

    // (중요!) int와 Point class객체를 +하는 point class 멤버 연산자+ 함수가 존재하지 않음
    //  -> 멤버 연산자 함수 중 해당하는 녀석 없으므로, 전역 연산자 함수 중 해당하는 녀석을 찾아 호출
    Point p2 = 10 + p1;
    // (함수명 호출) Point p2 = operator+(10, p1);

    cout << "p1(" << p1.GetX() << ", " << p1.GetY() << ")\n";
    cout << "p2(" << p2.GetX() << ", " << p2.GetY() << ")\n";


    // ++++++p1; == (++(++(++p1)))));
    //  -> [[[[p1.operator++()].operator++()].operator++())]; 로 호출하는 것과 같음
    ++++++p1;

    cout << p1.GetX() << ", " << p1.GetY() << "\n";

    p1++;
    cout << p1.GetX() << ", " << p1.GetY() << "\n";

    return 0;
}