
// <모범답안>
// class를 활용하여 다음의 기능을 가진 코드를 작성해라
// 1. point1 (X,Y) 입력받기 
// 2. point2 (X,Y) 입력받기 
// 3. 1, 2에 해당하는 내부 채우기

// <모범답안>
// class를 활용한 도형 그리기 코드 작성
#include <iostream>
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

        if (x == -1 || y == -1) break;

        point pos1;

        if (!pos1.init_pos(x, y)) {
            cout << "pos1 초기화 실패" << endl;
            system("pause");
            continue;
        }

        cout << "2번 좌표를 입력하세요 (x y, 공백 구분, 범위:0~500, 종료:-1) : ";
        cin >> x >> y;

        if (x == -1 || y == -1) break;

        point pos2;

        if (!pos2.init_pos(x, y)) {
            cout << "pos2 초기화 실패" << endl;
            system("pause");
            continue;
        }

        rectangle rec1;

        if (!rec1.init_rectangle(pos1, pos2)) cout << "rec1 초기화 실패" << endl;

        rec1.subtract_point();
        rec1.show_rectangle();

        system("pause");
    }
    return 0;
}

bool rectangle::init_rectangle(point& ul, point& lr) {
    int flag_x = 0, flag_y = 0;

    if (ul.get_x() > lr.get_x()) {
        low_right.set_x(ul.get_x());
        up_left.set_x(lr.get_x());
        flag_x++;
    }
    else {
        up_left.set_x(ul.get_x());
        low_right.set_x(lr.get_x());
        flag_x++;
    }
    if (ul.get_y() > lr.get_y()) {
        up_left.set_y(ul.get_y());
        low_right.set_y(lr.get_y());
        flag_y++;
    }
    else {
        low_right.set_y(ul.get_y());
        up_left.set_y(lr.get_y());
        flag_y++;
    }
    if (flag_x && flag_y) return true;
    else return false;
}

void rectangle::subtract_point()
{
    diff.set_x(low_right.get_x() - up_left.get_x());
    diff.set_y(up_left.get_y() - low_right.get_y());
    cout << diff.get_x() << ", " << diff.get_y() << endl;
}

void rectangle::show_rectangle() {
    cout << endl << endl << endl << endl << endl;
    for (int i = 0; i < up_left.get_x(); i++) cout << "  ";
    cout << up_left.get_x() << "," << up_left.get_y() << endl;
    for (int i = 0; i < up_left.get_y() - low_right.get_y(); i++) {
        for (int i = 0; i < up_left.get_x(); i++) cout << "  ";
        for (int i = 0; i < low_right.get_x() - up_left.get_x(); i++) cout << "■";
        cout << endl;
    }
    for (int i = 0; i < low_right.get_x(); i++) cout << "  ";
    cout << low_right.get_x() << "," << low_right.get_y() << endl;
    for (int i = 0; i < low_right.get_y() - 1; i++) cout << endl;
}

bool point::init_pos(int x_pos, int y_pos) {
    if (0 > x_pos || 500 < x_pos) {
        cout << "X좌표 범위를 벗어났습니다.(0~500)" << endl;
        return false;
    }
    if (0 > y_pos || 500 < y_pos) {
        cout << "X좌표 범위를 벗어났습니다.(0~500)" << endl;
        return false;
    }
    x = x_pos;
    y = y_pos;
    return true;
}

int point::get_x() {
    return x;
}

int point::get_y() {
    return y;
}

bool point::set_x(int x_pos) {
    if (0 > x_pos || 500 < x_pos) {
        cout << "X좌표 범위를 벗어났습니다.(0~500)" << endl;
        return false;
    }
    x = x_pos;
    return true;
}

bool point::set_y(int y_pos) {
    if (0 > y_pos || 500 < y_pos) {
        cout << "Y좌표 범위를 벗어났습니다.(0~500)" << endl;
        return false;
    }
    y = y_pos;
    return true;
}
