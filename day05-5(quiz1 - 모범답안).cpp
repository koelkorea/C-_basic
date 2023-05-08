#include <iostream>
#include <cmath>
using namespace std;
class figure {
public:
    float width, height; //��(����), ����(����)
    char shape;
    void Setfigure(int _width, int _height, char _shape);
    void print_rectangular();
    void print_right_triangle();
    void print_left_triangle();
    void print_isosceles_triangle();
};

void figure::Setfigure(int _width, int _height, char _shape) {
    width = _width;
    height = _height;
    shape = _shape;
}

void figure::print_rectangular() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << shape;
        }
        cout << endl;
    }
    cout << endl << endl;
}

void figure::print_right_triangle() {

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < (i / (height / width)); j++) {
            cout << shape;
        }

        cout << endl;
    }
    cout << endl << endl;
}

void figure::print_left_triangle() {

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < (width - ceil(i / (height / width))); j++) {
            cout << " ";
        }

        for (int j = 0; j < (i / (height / width)); j++) {
            cout << shape;
        }

        cout << endl;
    }
    cout << endl << endl;
}

void figure::print_isosceles_triangle() {

    for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < ceil((width / 2 - ceil(i / (height / width) / 2))); j++) {
            cout << " ";
        }

        for (int j = 0; j < (i / (height / width) / 2); j++) {
            cout << shape;
        }

        for (int j = 0; j < trunc(i / (height / width) / 2.0001); j++) {
            cout << shape;
        }

        cout << endl;
    }
    cout << endl << endl;
}

int main() {
    cout << "��(����) : ";
    float width;
    cin >> width;

    cout << "����(����) : ";
    float height;
    cin >> height;

    cout << "��� ��� : ";
    char shape;
    cin >> shape;

    figure t; //���� Ŭ����

    t.Setfigure(width, height, shape);
    t.print_rectangular();
    t.print_right_triangle();
    t.print_left_triangle();
    t.print_isosceles_triangle();

    return 0;
}
