
// �����Ҵ� pointer ������ ������ class�� ������, �Ҹ��� ����
#include <iostream>
using namespace std;

class A {

    private:

        int* p;

    public:

        A(int _a) {
            p = new int;
            *p = _a;
            cout << "������ " << *p << "ȣ��\n";
        }

        ~A() {
            cout << "~�Ҹ��� " << *p << "ȣ��\n";
            delete p;
        }
};

void fun() {
    A ob2(2);
}

// ��ü�� ��ȿ������ ���������� ����, ����� ������ �޸� �󿡼� �Ҹ��
void main() {

    A ob1(1);
    fun();
    A ob3(3);
}
