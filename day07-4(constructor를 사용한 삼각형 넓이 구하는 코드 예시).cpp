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
        // ������ {}�ȿ� parameter�� ���� ���� ����
        Triangle(double _base, double _height) {
            base = _base;
            height = _height;
            cout << "2. constructor call with parameter\n";
        }

        // �ʱ�ȭ ����Ʈ(Initialize List)�� ����� :������ ���� ������ ���� �� ����
        Triangle(double _base, double _height, int flag) : base(_base), height(_height) {
            cout << "3. constructor call with parameter (by Initialize List)\n";
            cout << "    -> flag �Ķ���ʹ� �⺻ ������ �Լ��� ������ ���� ���� ����ϴ�!\n";
        }

        // --------------------------------------- [���� �ʱ�ȭ �Լ��� ���� �ʱ�ȭ ��]------------------------------------------------
        void initialize();
        void initialize(double _base, double _height);
        //-------------------------------------------------------------------------------------------------------------------------

        double getArea();
};

// --------------------------------------- [���� �ʱ�ȭ �Լ��� ���� �ʱ�ȭ ��]------------------------------------------------
void Triangle::initialize() {
    base = 0;
    height = 0;
}

void Triangle::initialize(double _base, double _height) {
    base = _base;
    height = _height;
}
//-------------------------------------------------------------------------------------------------------------------------

double Triangle::getArea() {
    return base * height / 2;
}

int main() {

    double b, h;

    cout << "�غ� �Է� : ";
    cin >> b;

    cout << "���� �Է� : ";
    cin >> h;

    // 1. ���� Ŭ���� ���� ���� ��, �ʱ�ȭ �Լ��� ����� ������� �� ����  
    Triangle tri1; 
    tri1.initialize(b, h);

    // 2. Ŭ���� �����ڸ� ���� ������� �� ������ Ŭ������ ��ü�� �����ϱ�
    Triangle tri2(b * 2, h * 3); 
    Triangle tri3(b * 10, h * 10);

    cout << "�ﰢ�� tri1�� ���̴� " << tri1.getArea() << "�Դϴ�.\n";
    cout << "�ﰢ�� tri2�� ���̴� " << tri2.getArea() << "�Դϴ�.\n";
    cout << "�ﰢ�� tri3�� ���̴� " << tri3.getArea() << "�Դϴ�.\n";
    return 0;
}
