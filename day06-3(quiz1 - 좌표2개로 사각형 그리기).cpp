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

    for (int j = 1; j <= up_left.get_y() + diff.get_y(); j++) {

        for (int i = 1; i <= up_left.get_x() + diff.get_x(); i++) {

            if (j >= up_left.get_y()) {

                if (i >= up_left.get_x()) {
                    cout << "d";
                }
                else {
                    cout << " ";
                }

            }
            else {
                break;
            }
        }

        cout << endl;
    }

}