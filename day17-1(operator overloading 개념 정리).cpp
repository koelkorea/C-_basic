//연산자 오버로딩
//객체도 기본 자료형(int, double, char…)처럼 다양한 연산을 하기 위함.
//형식 : operator + "연산자 조합" 함수의 이름을 정의
//
//호출 형식
//함수 이름 호출
//Point p1(1, 1), p2(2, 2);
//p1.operator+(p2);
//연산자 이용 호출
//Point p1(1, 1), p2(2, 2);
//
//Point p3 = p1 + p2;
//
//p1. operator+ (p2)  == p1 + p2
//
//멤버함수 오버로딩
//p1.operator+(p2);
//
//전역함수 오버로딩
//operator+(p1, p2); 교환법칙
//
//멤버함수가 전역함수보다 우선시 호출

//단항 연산자 오버로딩
//전치(전위) 연산자
//해당 줄에서 먼저 연산처리 후변경된 값으로 다음을 진행.Point p1(1, 1);++p1; 
// p1.operator++();
//++++++++++p1;

//(++(++(++(++(++p1))))); 같다

//[[[[p1.operator++()].operator++()].operator++())].operator++())].operator++()

//후치(후위) 연산자
//< int : 후치 연산자 구분 키워드 >
//해당 줄 연산 모두 종료 후 증감.임시 객체의 값으로 해당 줄 연산
//호출한 객체의 값은 증감 처리.Point p1(1, 1), p2;


//p1++;
// p1.operator++();
//p2 = p1++;
//p1( 2 , 2 ), p2( 1 , 1 )



// 오버로딩 불가능 연산자
//.                       멤버 접근
//.*                      멤버 포인터
//::                      범위 지정자
//? :                     3항 연산자
//sizeof                  Byte 크기 계산
//typeid                  RTTI 연산자
//static_cast             type casting
//dynamic_cast             type casting
//const_cast              type casting
//retinterpret_cast       type casting

// 멤버함수로만 오버로딩 가능 연산자
//=                       대입 연산자
//()                      함수 호출 연산자
//[]                      배열 접근 연산자
//->                      멤버 접근 포인터 연산자


//연산자 오버로딩 주의사항
//
//함수의 기능을 그 어떤 사람이 보더라도 같은 의미로 통할 수 있도록 작성
//(= 직관적이고 일반적으로!객체에 따라 같은 연산자를 다르게 처리하면.......)
//연산자의 우선순위와 결합성은 바뀌지 않는다.
//매개변수의 디폴트 값 설정이 불가능하다
//연산자의 기본 기능을 오버로딩 할 수는 없다.


// 연산자 오버로딩 & 단항 연산자 오버로딩 예시
class Point {

    private:
        int x, y;

    public:
        Point(int x = 0, int y = 0) : x(x), y(y) {}

        Point operator+ (const Point& r) {
            Point temp;

            temp.x = this->x + r.x;
            temp.y = this->y + r.y;

            return temp;
        }
        Point operator- (const Point& r) {

            Point temp;

            temp.x = this->x - r.x;
            temp.y = this->y - r.y;

            return temp;
        }

        // 전치 연산자 오버로딩
        Point& operator++() {

            x += 1;
            y += 1;

            //반환값이 호출 객체자기 자신
            return *this;
        }

        //후치 연산자 오버로딩
        Point operator++(int) {

            Point temp;

            temp.x = x;
            temp.y = y;

            x += 1;
            y += 1;

            return temp;
        }


};
