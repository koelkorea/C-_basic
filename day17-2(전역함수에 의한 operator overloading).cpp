//   # 연산자 함수(operator function) 호출 형식 case

//      1. 일반 연산자 호출
//         : (중요!) p1.operator+(p2) == p1 + p2 로 요약 가능
//             -> 문제점 : 연산에 상수가 들어가는 경우? 
//                 -> 상수는 객체나 변수가 아님 = 객체의 멤버함수(연산자함수 포함)를 사용할 수 없음  
// 
//         - 함수명으로 호출 (= 함수명이나 객체까지 명확하게 선언해야해서, 사용자 의도대로 정확한 함수가 호출됨)
//         
//            ex1) [멤버 연산자 함수] 호출 형식
//                  : 객체1.연산자함수명(객체2) 
//                  
//                  Point p1(1, 1), p2(2, 2);
//                  Point p3 = p1.operator+(p2);
//            
//            ex2) [전역 연산자 함수] 호출
//                  : (중요!) 전역연산자함수명(객체1, 객체2) 
//                  
//                  Point p1(1, 1), p2(2, 2);
//                  Point p3 = operator+(p1, p2); 
//         
//         - 연산자 이용 호출 (= 비슷한 선언부의 내용이라면, 멤버함수 쪽이 전역함수보다 우선순위를 가지고 호출됨)
//         
//            ex) Point p1(1, 1), p2(2, 2);
//                Point p3 = p1 + p2;         <- 모양새가 유사한 선언부라 멤버함수로나 전역함수로나 둘 다 성립된다 한다면, 멤버함수 쪽이 더 우선권을 가짐

//      2. 단항 연산자 호출
//         : (중요!) p1.operator++()     ==  ++p1
//                   p1.operator--(int)  ==  p1--  로 요약 가능

//         - 단항 연산자 종류
//            1. 전치(전위) 연산자   ex) ++객체명, --객체명
//               : 해당 줄에서 먼저 ++ --가 붙은 변수나 객체에 지정된 연산(+1, -1이 예시)처리
//                  -> 그 후 변경된 값으로 다음 연산을 진행

//            2. 후치(후위) 연산자   ex) 객체명++, 객체명--
//               : 해당 줄에서 연산이 모두 종료된 뒤
//                  -> 그 후 ++ --가 붙은 변수나 객체에 지정된 연산(+1, -1이 예시)처리


//         - 전치(전위) 연산자 vs 후치(후위) 연산자 차이점
//            1. 전치(전위) 연산자
//                : (중요) 연산자로 중첩해서 쓰는것도 가능은 함 (물론 추천할리가 없음)
//                   -> How? 전치연산자 함수의 경우는 특수하게 반드시 자기 자신을 call by reference 개념으로 반환함
//                           (= 자기 자신을 향한 연산을 계속 가능)

//                 ex) ++++++++++p1; == (++(++(++(++(++p1)))));
//                     -> [[[[p1.operator++()].operator++()].operator++())].operator++())].operator++(); 로 호출하는 것과 같음

//            2. 후치(후위) 연산자
//                : 연산자로 중첩해서 써도 효과는 1번만 적용됨!
//                   -> 다른 연산자 함수와 마찬가지로 함수 내의 지역객체를 만들어서 값을 계산해 이걸 call by value 개념으로 원본을 복사한 값을 기반으로 반환하기 때문
//                      (= 백날 중첩해봐야 원본 대상에는 1도 문제없고 마지막 1번의 연산만 대입됨)


//         - 단항 연산자 함수명으로 호출 (= 함수명이나 객체까지 명확하게 선언해야해서, 사용자 의도대로 정확한 함수가 호출됨)
//            -> (중요!) parameter 무 : 유 = 전위연산자 : 후위연산자 
//         
//               ex1) 전치(전위) 멤버 연산자 함수 호출
//                    Point p1(1, 1);
//                    Point p3 =  p1.operator++();
//               
//               ex2) 후치(후위) 멤버 연산자 함수 호출 
//                    Point p1(1, 1);
//                    Point p3 =  p1.operator-- (int);         <- int parameter의 존재가 후위 단항 연산자임을 보여줌
//         
//         - 단항 연산자 연산자 이용 호출 (= 비슷한 선언부의 내용이라면, 멤버함수 쪽이 전역함수보다 우선순위를 가지고 호출됨)

//               ex1) 전치(전위) 전역 연산자 함수 호출
//                    Point p1(1, 1);
//                    Point p3 =  ++p1;
//               
//               ex2) 후치(후위) 전역 연산자 함수 호출
//                    Point p1(1, 1), p2(2, 2);
//                    Point p3 = p1--;


//   # 연산자 오버로딩 (operlator overloading) 선언 및 정의 구조
//      1. 일반 연산자 오버로딩
//          : operator연산자(자료형 parameters){  내용  } 

//      2. 단항 연산자 오버로딩 
//          -> (중요!) (int parameter 무 : 유) = (전위연산자 : 후위연산자) 로 구분!
// 
//             - 전치(전위) 연산자 오버로딩
//                : operator++() {  내용  }  or   operator--() {  내용  }

//             - 후치(후위) 연산자 오버로딩
//                : operator++(자료형 parameter) {  내용  }  or   operator--(자료형 parameter) {  내용  }


// 전역 연산자 함수 오버로딩 및 멤버함수 제끼고 호출하는 방법과 과정 (day17-1 코드에 추가 내용 덧붙힘)
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

        //후치 연산자 ++ 오버로딩 (parameter가 int가 쓰인거로 구분)
        Point operator++(int) {

            Point temp;

            // 전위 연산자++ 멤버함수를 호출한 객체의 x, y값에 1씩 더하고 나서 
            //  -> 그 x,y 값을 멤버로 가진 tmp라는 point class 객체를 반환
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