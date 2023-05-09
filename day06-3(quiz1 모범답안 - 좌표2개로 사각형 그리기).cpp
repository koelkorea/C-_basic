
// <������>
// class�� Ȱ���Ͽ� ������ ����� ���� �ڵ带 �ۼ��ض�
// 1. point1 (X,Y) �Է¹ޱ� 
// 2. point2 (X,Y) �Է¹ޱ� 
// 3. 1, 2�� �ش��ϴ� ���� ä���

// <������>
// class�� Ȱ���� ���� �׸��� �ڵ� �ۼ�
#include <iostream>
using namespace std;

class point {
    private:
        int x, y; //x��ǥ, y��ǥ
    public:
        bool init_pos(int x_pos, int y_pos); // x, y �� �ʱ�ȭ
        int get_x(); // x�� �б�
        int get_y(); // y�� �б�
        bool set_x(int x_pos); // x�� ����
        bool set_y(int y_pos); // y�� ����
};
class rectangle {
    private:
        point up_left, low_right;//���� ��� ��ǥ 1, ������ �ϴ� ��ǥ 2
        point diff;//low_right - up_left ���� ��
    public:
        bool init_rectangle(point& ul, point& lr); // up_left, low_right �ʱ�ȭ
        void subtract_point();// diff = low_right - up_left ���� �� ���ϴ� �Լ�
        void show_rectangle();//�� �� ���� �簢�� �׸���
};

int main() {

    while (1) {
        system("cls");
        cout << "1�� ��ǥ�� �Է��ϼ��� (x y, ���� ����, ����:0~500, ����:-1) : ";
        int x, y;
        cin >> x >> y;

        if (x == -1 || y == -1) break;

        point pos1;

        if (!pos1.init_pos(x, y)) {
            cout << "pos1 �ʱ�ȭ ����" << endl;
            system("pause");
            continue;
        }

        cout << "2�� ��ǥ�� �Է��ϼ��� (x y, ���� ����, ����:0~500, ����:-1) : ";
        cin >> x >> y;

        if (x == -1 || y == -1) break;

        point pos2;

        if (!pos2.init_pos(x, y)) {
            cout << "pos2 �ʱ�ȭ ����" << endl;
            system("pause");
            continue;
        }

        rectangle rec1;

        if (!rec1.init_rectangle(pos1, pos2)) cout << "rec1 �ʱ�ȭ ����" << endl;

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
        for (int i = 0; i < low_right.get_x() - up_left.get_x(); i++) cout << "��";
        cout << endl;
    }
    for (int i = 0; i < low_right.get_x(); i++) cout << "  ";
    cout << low_right.get_x() << "," << low_right.get_y() << endl;
    for (int i = 0; i < low_right.get_y() - 1; i++) cout << endl;
}

bool point::init_pos(int x_pos, int y_pos) {
    if (0 > x_pos || 500 < x_pos) {
        cout << "X��ǥ ������ ������ϴ�.(0~500)" << endl;
        return false;
    }
    if (0 > y_pos || 500 < y_pos) {
        cout << "X��ǥ ������ ������ϴ�.(0~500)" << endl;
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
        cout << "X��ǥ ������ ������ϴ�.(0~500)" << endl;
        return false;
    }
    x = x_pos;
    return true;
}

bool point::set_y(int y_pos) {
    if (0 > y_pos || 500 < y_pos) {
        cout << "Y��ǥ ������ ������ϴ�.(0~500)" << endl;
        return false;
    }
    y = y_pos;
    return true;
}
