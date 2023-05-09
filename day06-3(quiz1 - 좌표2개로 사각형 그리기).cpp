// class�� Ȱ���Ͽ� ������ ����� ���� �ڵ带 �ۼ��ض�
// 1. point1 (X,Y) �Է¹ޱ� 
// 2. point2 (X,Y) �Է¹ޱ� 
// 3. 1, 2�� �ش��ϴ� ���� ä���

// class�� Ȱ���� ���� �׸��� �ڵ� �ۼ�
#include <iostream>
#include <iomanip>
#include <cmath>

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
        if (x == -1 || y == -1) {
            break;
        }

        point pos1;
        if (!pos1.init_pos(x, y)) {
            cout << "pos1 �ʱ�ȭ ����" << endl;
            system("pause");
            continue;
        }

        cout << "2�� ��ǥ�� �Է��ϼ��� (x y, ���� ����, ����:0~500, ����:-1) : ";
        cin >> x >> y;
        if (x == -1 || y == -1) {
            break;
        }

        point pos2;
        if (!pos2.init_pos(x, y)) {
            cout << "pos2 �ʱ�ȭ ����" << endl;
            system("pause");
            continue;
        }

        rectangle rec1;
        if (!rec1.init_rectangle(pos1, pos2)) {
            cout << "rec1 �ʱ�ȭ ����" << endl;
        }

        rec1.subtract_point();
        rec1.show_rectangle();
        system("pause");
    }
    return 0;
}

// x, y �� �ʱ�ȭ
bool point::init_pos(int x_pos, int y_pos) {
    x = x_pos;
    y = y_pos;

    return true;
}

// x�� �б�
int point::get_x() {
    return x;
}

// y�� �б�
int point::get_y() {
    return y;
}

// x�� ����
bool point::set_x(int x_pos) {
    x = x_pos;

    return true;
}

// y�� ����
bool point::set_y(int y_pos) {
    y = y_pos;

    return true;
}

// up_left, low_right �ʱ�ȭ
bool rectangle::init_rectangle(point& ul, point& lr) {

    // 2���� ���� X�� ���ϱ�
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

    // 2���� ���� Y�� ���ϱ�
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

// diff = low_right - up_left ���� �� ���ϴ� �Լ�
void rectangle::subtract_point() {
    diff.set_x(low_right.get_x() - up_left.get_x());
    diff.set_y(up_left.get_y() - low_right.get_y());
}

//�� �� ���� �簢�� �׸���
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