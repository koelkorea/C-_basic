// 캡슐화(Encapsulation)
//  : 객체의 속성(data)과 행위(methods)를 하나로 묶는 행위 (= 클래스 설계)
//     -> (중요) 이 과정에서 공개할 멤버와 숨길 멤버를 정해둘 수 있음 (= 은닉화) 

// 은닉화(Information hiding)
//  : class의 실제 구현 내용을 접근제어자를 통해 접근제어 권한에 차등을 둬서 외부에 숨기는 개념
//    -> (중요) 은닉화는 캡슐화를 구현하는 과정에 포함된 부분기능 같은 개념이라 생각하면 됨 ( 캡슐화 > 은닉화 )


//   # 접근제어자
//      : 클래스의 멤버변수의 변조 방지를 위해 코드 실행 중 접근위치에 따라 멤버변수의 값에 접근여부에 따른 제어권한을 의미 
//         -> 사실상 public과 private만 널리 사용되며, 이들이 getter setter 디자인패턴과 연관 
        
//        - private     : 해당 클래스 내에서만 해당 클래스의 멤버들에 접근할 수 있음 
//                        (= 오로지 클래스 선언시 미리 작성한 멤버변수 초기화 값과 멤버함수를 통해서만 값의 변조가 가능 == 은닉이 필요한 속성에 적용하게 됨)
//      
//        - protected   : 상속관계에서 해당 클래스의 멤버들에 접근허용 
//                        (= 해당 클래스와 상속관계에 있는 클래스가 선언될 때라면, 해당 멤버변수의 값에 접근 및 변조나 멤버함수의 사용이 가능) 
//      
//        - public      : 어디서든 일단 멤버변수나 멤버메서드가 호출되거나 참조되면, 언제라도 해당 멤버변수의 값에 접근 및 변조나 멤버함수의 사용을 허용함 (사실상 자동문임)
        
//   # getter, setter 디자인 패턴
//      : 접근제어자를 통해 class의 멤버변수의 값에 접근 및 변조나

//   # setter, getter = private 접근제어자를 통한 은닉화
//      : 클래스 멤버 변수를 외부에서 직접 수정 할 수 없으며, 멤버 함수로만 수정 하도록 만드는 방법으로 외부에서 접근을 막을 수 있다


//특징
//외부 객체는 객체 내부의 구조를 얻지 못한다
//객체가 노출해서 제공하는 필드와 메소드만 이용할 수 있다
//외부의 잘못된 사용으로 인해 객체가 손상되지 않도록 캡슐화하여 보호
//은닉과 노출은 접근제어 지시자로 분류
//클래스의 구성 범위를 어디까지 정의할 것인가 ?



// class를 활용하여 다음의 기능을 가진 코드를 작성해라
// 1. point1 (X,Y) 입력받기 
// 2. point2 (X,Y) 입력받기 
// 3. 1, 2에 해당하는 내부 채우기

// class를 활용한 도형 그리기 코드 작성
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class point {

private:
    int x, y; //x좌표, y좌표

public:
    bool init_pos(int x_pos, int y_pos); // x, y 값 초기화
    int get_x(); // x값 읽기
    int get_y(); // y값 읽기
    bool set_x(int x_pos); // x값 쓰기
    bool set_y(int y_pos); // y값 쓰기
};

class rectangle {

private:
    point up_left, low_right;//왼쪽 상당 좌표 1, 오른쪽 하단 좌표 2
    point diff;//low_right - up_left 차이 값
public:
    bool init_rectangle(point& ul, point& lr); // up_left, low_right 초기화
    void subtract_point();// diff = low_right - up_left 차이 값 구하는 함수
    void show_rectangle();//두 점 사이 사각형 그리기
};

int main() {

    while (1) {
        system("cls");
        cout << "1번 좌표를 입력하세요 (x y, 공백 구분, 범위:0~500, 종료:-1) : ";
        int x, y;
        cin >> x >> y;
        if (x == -1 || y == -1) {
            break;
        }

        point pos1;
        if (!pos1.init_pos(x, y)) {
            cout << "pos1 초기화 실패" << endl;
            system("pause");
            continue;
        }

        cout << "2번 좌표를 입력하세요 (x y, 공백 구분, 범위:0~500, 종료:-1) : ";
        cin >> x >> y;
        if (x == -1 || y == -1) {
            break;
        }

        point pos2;
        if (!pos2.init_pos(x, y)) {
            cout << "pos2 초기화 실패" << endl;
            system("pause");
            continue;
        }

        rectangle rec1;
        if (!rec1.init_rectangle(pos1, pos2)) {
            cout << "rec1 초기화 실패" << endl;
        }

        rec1.subtract_point();
        rec1.show_rectangle();
        system("pause");
    }
    return 0;
}

// x, y 값 초기화
bool point::init_pos(int x_pos, int y_pos) {
    x = x_pos;
    y = y_pos;

    return true;
}

// x값 읽기
int point::get_x() {
    return x;
}

// y값 읽기
int point::get_y() {
    return y;
}

// x값 쓰기
bool point::set_x(int x_pos) {
    x = x_pos;

    return true;
}

// y값 쓰기
bool point::set_y(int y_pos) {
    y = y_pos;

    return true;
}

// up_left, low_right 초기화
bool rectangle::init_rectangle(point& ul, point& lr) {

    // 2개의 점의 X축 정하기
    if (ul.get_x() < lr.get_x()) {
        up_left.set_x(ul.get_x());
        low_right.set_x(lr.get_x());
    }
    else if (ul.get_x() > lr.get_x()) {
        up_left.set_x(lr.get_x());
        low_right.set_x(ul.get_x());
    }
    else {
        return false;
    }

    // 2개의 점의 Y축 정하기
    if (ul.get_y() < lr.get_y()) {
        up_left.set_y(lr.get_y());
        low_right.set_y(ul.get_y());
    }
    else if (ul.get_y() > lr.get_y()) {
        up_left.set_y(ul.get_y());
        low_right.set_y(lr.get_y());
    }
    else {
        return false;
    }

    return true;
}

// diff = low_right - up_left 차이 값 구하는 함수
void rectangle::subtract_point() {
    diff.set_x(low_right.get_x() - up_left.get_x());
    diff.set_y(up_left.get_y() - low_right.get_y());
}

//두 점 사이 사각형 그리기
void rectangle::show_rectangle() {

    for (int i = 1; i <= diff.get_x(); i++) {

        for (int j = 1; j <= diff.get_y(); j++) {

            cout << "d";
        }

        cout << endl;
    }

}