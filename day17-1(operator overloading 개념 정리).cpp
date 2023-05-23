// 연산자 오버로딩 (operlator overloading)
//  : (중요!) 일반적으로 흔히 연산을 위해 사용하는 연산자(+, -, / ...)들도 사실은 'operator연산자'라는 함수명을 가지고 있는 함수와 같음
//     -> 이 녀석들의 선언부에 parameter의 구성으로 사용자가 작성한 class 객체들을 사용해서 overloading이? 가능함!!!
//        (= 사용자는 원시형 자료형을 사용한 연산자 외에도, class 객체를 사용할 시 연산자를 활용한 연산 법칙을 창조할 수 있음!!)


//   # 연산자의 종류
//      1. 오버로딩 불가능한 연산자
//         - .                 : class 객체의 멤버영역에 접근하라는 의미
//         - .*                : class 객체의 멤버 포인터
//         - ::                : 범위 지정자
//         - ? true : false    : 3항 연산자
//         - sizeof            : 변수나 객체의 Byte 크기 계산
//         - typeid            : 변수나 객체의 자료형을 도출하는 RTTI 연산자
//         - static_cast       : type 정적 casting
//         - dynamic_cast      : type 동적 casting
//         - const_cast        : type 상수 casting
//         - retinterpret_cast : 포인터 type끼리 casting 허용 

//      2. class의 멤버함수로만 오버로딩 가능 연산자
//         - =   : 대입 연산자
//         - ()  : 함수 호출 연산자
//         - []  : 배열 접근 연산자
//         - ->  : 역참조하여 class 객체 멤버영역 접근 포인터 연산자

//      3. 그 외 대부분의 연산자는 비트연산자(<<, >>), 단항 연산자(++, --) 포함해서 overloading 가능


//   # 연산자 함수(operator function)의 특징
//      1. 연산자의 함수명은 [operator + '연산자'] 형식으로 이뤄짐
//      2. (중요!) 비슷한 선언부의 내용이라면, 멤버함수 쪽이 전역함수보다 우선순위를 가지고 호출됨
//      3. (중요!) 흔히 쓰는 '변수(객체) + 변수(객체)'와 같은 연산자는 연산자함수를 호출코드를 간추린 것이다

//         ex) 객체1.operator+(객체2)  ->   객체1 + 객체2

//      4. 단항 연산자를 연산자로 중첩해서 쓰는것도 가능은 함 (물론 추천할리가 없음)

//         ex) ++++++++++p1; == (++(++(++(++(++p1)))));
//             -> [[[[p1.operator++()].operator++()].operator++())].operator++())].operator++(); 로 호출하는 것과 같음


//   # 연산자 함수(operator function) 호출 형식 case

//      1. 일반 연산자 호출
//         : (중요!) p1.operator+(p2) == p1 + p2 로 요약 가능
// 
//         - 함수명으로 호출 (= 함수명이나 객체까지 명확하게 선언해야해서, 사용자 의도대로 정확한 함수가 호출됨)
//         
//           ex1) [멤버 연산자 함수] 호출 형식
//                : 객체1.연산자함수명(객체2) 
// 
//                Point p1(1, 1), p2(2, 2);
//                Point p3 = p1.operator+(p2);
//         
//           ex2) [전역 연산자 함수] 호출
//                : (중요!) 전역연산자함수명(객체1, 객체2) 
// 
//                Point p1(1, 1), p2(2, 2);
//                Point p3 = operator+(p1, p2); 
//         
//         - 연산자 이용 호출 (= 비슷한 선언부의 내용이라면, 멤버함수 쪽이 전역함수보다 우선순위를 가지고 호출됨)
//         
//           ex) Point p1(1, 1), p2(2, 2);
//               Point p3 = p1 + p2;         <- 모양새가 유사한 선언부라 멤버함수로나 전역함수로나 둘 다 성립된다 한다면, 멤버함수 쪽이 더 우선권을 가짐

//      2. 단항 연산자 호출
//         : (중요!) p1.operator++()     ==  ++p1
//                   p1.operator--(int)  ==  p1--  로 요약 가능

//          a. 전치(전위) 연산자   ex) ++객체명, --객체명
//             : 해당 줄에서 먼저 ++ --가 붙은 변수나 객체에 지정된 연산(+1, -1이 예시)처리
//                -> 그 후 변경된 값으로 다음 연산을 진행

//          b. 후치(후위) 연산자   ex) 객체명++, 객체명--
//             : 해당 줄에서 연산이 모두 종료된 뒤
//                -> 그 후 ++ --가 붙은 변수나 객체에 지정된 연산(+1, -1이 예시)처리

//         - 단항 연산자 함수명으로 호출 (= 함수명이나 객체까지 명확하게 선언해야해서, 사용자 의도대로 정확한 함수가 호출됨)
//            -> (중요!) parameter 무 : 유 = 전위연산자 : 후위연산자 
//         
//               ex1) 전치(전위) 멤버 연산자 함수 호출
//                    Point p1(1, 1);
//                    Point p3 =  p1.operator++();
//               
//               ex2) 후치(후위) 멤버 연산자 함수 호출 
//                    Point p1(1, 1);
//                    Point p3 =  p1.operator-- (int);
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
//          -> (중요!) parameter 무 : 유 = 전위연산자 : 후위연산자  로 구분!
// 
//             - 전치(전위) 연산자 오버로딩
//                : operator++() {  내용  }  or   operator--() {  내용  }
               
//             - 후치(후위) 연산자 오버로딩
//                : operator++(자료형 parameter) {  내용  }  or   operator--(자료형 parameter) {  내용  }


//   # (중요!) 연산자 오버로딩(operator overloading)시 주의사항
//      1. 가급적 연선자의 기능을 그 어떤 사람이 보더라도 같은 의미로 통할 수 있도록 작성
//          -> 객체에 따라 같은 연산자를 다른 방식으로 처리하는 식으로 작성하지 말라는 것
//      2. 연산자의 우선순위와 결합성은 바뀌지 않음
//      3. defalut parameter 설정이 불가능!
//      4. 연산자의 기본 기능(원시형 변수를 반환하는 연산자 같은거)을 오버로딩 할 수는 없음



// 연산자 오버로딩 & 단항 연산자 오버로딩 예시
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

            // 연산자- 멤버함수를 호출한 객체의 x, y값에 1씩 더하고 나서
            //  -> 객체 그 자신을 point 레퍼런스객체 형식으로 리턴
            x += 1;
            y += 1;

            //반환값이 호출 객체 자기자신의 포인터를 역참조하여 호출 객체 자기자신을 반환
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


};
