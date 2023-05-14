// 생성자(Constructor)
//  : 객체의 [생성]과 동시에 호출하는 '클래스명'과 동일한 이름의 함수, 객체의 동적할당 연산자인 new와 함께 사용하며 초기화 과정의 편리함까지 더해줌
//    -> 원래 calloc, malloc, realloc를 대체한, 'new 클래스명'는 사실 'new 클래스명()'과 같은 의미인 기본 생성자(default Constructor) 함수 
//       (= 생성자 개념이 더 큰 개념 포함)

//   # 생성자 함수 선언, 정의법
//
//      1. 일반적인 초기화 방법 
//          : 그냥 void 함수라고 생각하되, 생성자 함수의 존재의의 자체가 생성된 객체의 멤버변수 초기화에 있다고 생각하면 편함
//             -> 클래스명(자료형 parameter명...) { 멤버변수 = parameter 사용하거나 가공한 값 }											
//                       
//                ex) class A 멤버는 다음과 같다 가정 ( int a; double b; char c; )
//                    
//                    A (int _a, double _b, char _c) {
//                        a = _a;
//                        b = _b;
//                        c = _a;
//                    }
//
//      2. 초기화 리스트(Initialize List) 
//          : (중요!) 콜론(:)을 이용하는 초기화법, 정의부보다 우선하여 실행된다는 장점이 있어, const 멤버변수의 초기화에 쓰임                        
//             -> 클래스명(자료형 parameter명...) : 가담O 멤버변수(parameter명) , ...  { 가담X 멤버변수 = parameter 사용하거나 가공한 값 }												
//                                                            
//                ex) class A 멤버는 다음과 같다 가정 ( int a; double b; char c; )
//		          
//                    A (int _a, double _d, char _c) : a(_a), c(_c) {
//                        b = _b;
//                    }


//   # 선언, 정의한 생성자 함수 종류 및 호출법
//
//      1. defalut constructor
//
//        - defalut constructor 정의
//           : (중요!) class에 아무것도 안 적어도 무조건 기본으로 존재하는 parameter 없는 생성자함수
//              -> 단! 정의부는 비어있기에, 내용이 필요하면 채워야함
//
//        - defalut constructor 호출법
//           : 클래스명 * 클래스포인터명 = new 클래스명;     
//             클래스명 * 클래스포인터명 = new 클래스명();   
//
//             ex) point* ptr_pos_1 = new point;
//                 point* ptr_pos_1 = new point();
//
//      2. (일반) constructor
//            
//        - (일반) constructor 정의
//           : defalut constructor 이외, 오버로딩한 생성자 함수 (= parameter 구성에 따라 이론상 무한개의 생성자함수 선언도 가능함)
//              -> 보통은 parameter를 멤버변수 값으로 대입하기 위해 사용
//
//        - (일반) constructor 호출법
//           : 클래스명* 클래스포인터명 = new 클래스명(parameter....);   
//
//             ex) point* ptr_pos_1 = new point(1, 1); 


// 삼각형 class의 멤버변수와 그 넓이를 구하는 메서드를 사용하는 과정을 통해 보여주는 생성자 사용법 3가지 방식
#include <iostream>
using namespace std;

// 삼각형 class
class Triangle {

    public:

        double base, height;

        // 1. defalut constructor 정의
        //  : (중요!) class에 아무것도 안 적어도 무조건 기본으로 존재하는 parameter 없는 생성자함수
        Triangle() {

            // 단!정의부는 비어있기에, 내용이 필요하면 채워야함
            base = 0;
            height = 0;
            cout << "1. constructor call\n";
        }

        // 2. 생성자 {}안에 parameter에 따른 변수 주입
        Triangle(double _base, double _height) {
            base = _base;
            height = _height;
            cout << "2. constructor call with parameter\n";
        }

        // 3. 초기화 리스트(Initialize List)
        //  : (중요!) 콜론(:)을 이용하는 초기화법, 정의부보다 우선하여 실행된다는 장점이 있어, const 멤버변수의 초기화에 쓰임
        //     -> 클래스명(자료형 parameter명...) : 가담O 멤버변수(parameter명), ...  { 가담X 멤버변수 = parameter 사용하거나 가공한 값 }
        Triangle(double _base, double _height, int flag) : base(_base), height(_height) {
            cout << "3. constructor call with parameter (by Initialize List)\n";
            cout << "    -> flag 파라미터는 기본 생성자 함수와 구분을 짓기 위해 썼습니다!\n";
        }

        // --------------------------------------- [기존 초기화 함수를 통한 초기화 법]------------------------------------------------
        void initialize();
        void initialize(double _base, double _height);
        //-------------------------------------------------------------------------------------------------------------------------

        double getArea() {
            return base * height / 2;
        }
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