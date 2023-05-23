//   # ������ �Լ�(operator function) ȣ�� ���� case

//      1. �Ϲ� ������ ȣ��
//         : (�߿�!) p1.operator+(p2) == p1 + p2 �� ��� ����
// 
//         - �Լ������� ȣ�� (= �Լ����̳� ��ü���� ��Ȯ�ϰ� �����ؾ��ؼ�, ����� �ǵ���� ��Ȯ�� �Լ��� ȣ���)
//         
//           ex1) [��� ������ �Լ�] ȣ�� ����
//                : ��ü1.�������Լ���(��ü2) 
// 
//                Point p1(1, 1), p2(2, 2);
//                Point p3 = p1.operator+(p2);
//         
//           ex2) [���� ������ �Լ�] ȣ��
//                : (�߿�!) �����������Լ���(��ü1, ��ü2) 
// 
//                Point p1(1, 1), p2(2, 2);
//                Point p3 = operator+(p1, p2); 
//         
//         - ������ �̿� ȣ�� (= ����� ������� �����̶��, ����Լ� ���� �����Լ����� �켱������ ������ ȣ���)
//         
//           ex) Point p1(1, 1), p2(2, 2);
//               Point p3 = p1 + p2;         <- ������ ������ ����ζ� ����Լ��γ� �����Լ��γ� �� �� �����ȴ� �Ѵٸ�, ����Լ� ���� �� �켱���� ����


//   # ������ �����ε� (operlator overloading) ���� �� ���� ����
//      1. �Ϲ� ������ �����ε�
//          : operator������(�ڷ��� parameters){  ����  } 


// ���� ������ �Լ� �����ε� �� ����Լ� ������ ȣ���ϴ� ����� ���� (day17-1 �ڵ忡 �߰� ���� ������)
#include <iostream>
using namespace std;

class Point {

    private:
        int x, y;

    public:
        Point(int x = 0, int y = 0) : x(x), y(y) {}

        // point class ��ü�� +������ �� ��쿡 ���� �����ε�
        Point operator+ (const Point& r) {

            Point temp;

            // parameter�� �־��� Point class �������� ��ü r�� x, y���� ������+ ����Լ��� ȣ���� ��ü�� x, y���� ���ϰ� ���� 
            //  -> �� x,y ���� ����� ���� tmp��� point class ��ü�� ��ȯ
            temp.x = this->x + r.x;
            temp.y = this->y + r.y;

            return temp;
        }

        // point class ��ü�� -������ �� ��쿡 ���� �����ε�
        Point operator- (const Point& r) {

            Point temp;

            // parameter�� �־��� Point class �������� ��ü r�� x, y���� ������- ����Լ��� ȣ���� ��ü�� x, y���� ���ϰ� ���� 
            //  -> �� x,y ���� ����� ���� tmp��� point class ��ü�� ��ȯ
            temp.x = this->x - r.x;
            temp.y = this->y - r.y;

            return temp;
        }

        // ��ġ ������ ++ �����ε� (parameter�� ����)
        Point& operator++() {

            // ������- ����Լ��� ȣ���� ��ü�� x, y���� 1�� ���ϰ� ����
            //  -> ��ü �� �ڽ��� point ���۷�����ü �������� ����
            x += 1;
            y += 1;

            //��ȯ���� ȣ�� ��ü �ڱ��ڽ��� �����͸� �������Ͽ� ȣ�� ��ü �ڱ��ڽ��� ��ȯ
            return *this;
        }

        //��ġ ������ ++ �����ε� (parameter�� int�� ���ΰŷ� ����)
        Point operator++(int) {

            Point temp;

            // ���� ������++ ����Լ��� ȣ���� ��ü�� x, y���� 1�� ���ϰ� ���� 
            //  -> �� x,y ���� ����� ���� tmp��� point class ��ü�� ��ȯ
            temp.x = x;
            temp.y = y;

            x += 1;
            y += 1;

            return temp;
        }

        inline int GetX() { return x; }
        inline int GetY() { return y; }

        // (point class ��� ������+�Լ��� ����) int���� point ��ü�� ������� �ϴ� ���� ������ +�Լ��� �ڽ��� ����Լ�ó�� �� �� ����
        friend Point operator+(int value, const Point& r); 

        // (point class ��� ������-�Լ��� ����) int���� point ��ü�� ������� �ϴ�  ���� ������ -�Լ��� �ڽ��� ����Լ�ó�� �� �� ����
        friend Point operator-(int value, const Point& r); 
};

// [���� ������ �Լ�]
//  : (�߿�!) �Լ������� ȣ�� �Ϸ��� '�����������Լ���(parameter1, parameter2);' �� ���� �������� ȣ��
//   
// point ��ü�� ������� �ϴ� ���� ������ +�Լ�
Point operator+(int value, const Point& r) {

    // value ���� x, y�� ���� ���� ����� parameter�� ���� Point ������ ��ü�� ��ȯ
    return Point(r.x + value, r.y + value); 
} 

// point ��ü�� ������� �ϴ� ���� ������ -�Լ�
Point operator-(int value, const Point& r) {

    // value ���� x, y�� ���� �� ����� parameter�� ���� Point ������ ��ü�� ��ȯ
    return Point(r.x - value, r.y - value); 
}

int main() {

    int x, y;
    cout << "ù ��° x, y��ǥ �Է� : ";
    cin >> x >> y;

    Point p1(x, y);

    // (�߿�!) int�� Point class��ü�� +�ϴ� point class ��� ������+ �Լ��� �������� ����
    //  -> ��� ������ �Լ� �� �ش��ϴ� �༮ �����Ƿ�, ���� ������ �Լ� �� �ش��ϴ� �༮�� ã�� ȣ��
    Point p2 = 10 + p1; 
    // (�Լ��� ȣ��) Point p2 = operator+(10, p1);

    cout << "p1(" << p1.GetX() << ", " << p1.GetY() << ")\n";
    cout << "p2(" << p2.GetX() << ", " << p2.GetY() << ")\n";


    // ++++++p1; == (++(++(++p1)))));
    //  -> [[[[p1.operator++()].operator++()].operator++())]; �� ȣ���ϴ� �Ͱ� ����
    ++++++p1;

    cout << p1.GetX() << ", " << p1.GetY() << "\n";

    p1++;
    cout << p1.GetX() << ", " << p1.GetY() << "\n";

    return 0;
}
