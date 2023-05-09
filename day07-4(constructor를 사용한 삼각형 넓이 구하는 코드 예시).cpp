#include <iostream>
using namespace std;
class Triangle {
public:

    double base, height;

    Triangle() {
        base = 0;
        height = 0;
        cout << "1. constructor call\n";
    }

    //Triangle(double _base, double _height) : base(_base), height(_height) {

    //}

    Triangle(double _base, double _height) {
        base = _base;
        height = _height;
        cout << "2. constructor call with parameter\n";
    }

    void initialize();
    void initialize(double _base, double _height);
    double getArea();
};
void Triangle::initialize() {
    base = 0;
    height = 0;
}
void Triangle::initialize(double _base, double _height) {
    base = _base;
    height = _height;
}
double Triangle::getArea() {
    return base * height / 2;
}
int main() {
    double b, h;
    cout << "�غ� �Է� : ";
    cin >> b;
    cout << "���� �Է� : ";
    cin >> h;
    Triangle tri; //Ŭ���� ���� ���� + ������  
    //Triangle tri(b, h); //Ŭ���� ������ ���� ����
    tri.initialize(b, h);  //�ʱ�ȭ
    cout << "�ﰢ���� ���̴� " << tri.getArea() << "�Դϴ�.\n";
    return 0;
}
