// class ��ü�迭
//  : class ��ü�� ���� �� �ʿ��� ��� �迭�� ����

// class ��ü ������ �迭
//  : ���״�� class��ü�����ͺ����θ� �̷��� �迭
//     -> ��ü�����Ͱ� ������ �ʿ��� ��� ����ϸ�, �̴� �����Ҵ�Ǿ� �����Ǵ� class��ü�� ���ٴ� �ǹ̷� �޾Ƶ��ϼ� ����

//   # (�η�) �ı� ������ ��� �� ���̵��
//      : class ��ü�迭�� �������� ���̸� ���� �����ϰ� �ϸ�, ����� ���������� ������ �����ϴ� ��ü���� ���� ������ ������
//        But! ���䵵 ����������, �׸� ���� �����Ҵ�� �޸� ������ �ϳ��ϳ� �� �Ű�Ἥ �� �ϱ⵵ ���� ������ ¥����
//         -> (Ÿ����) ������ �����ϰ�, list�� ��������Ǵ� �ڷᱸ�� class�� �ż�����! 
//             : �׳� �������� ���̸� ���డ���� � �ڷ����̶� �޴� list ������ ����, ���༺ ������ ������ class��ü�� ����� �����ϴ� �ɷ� ����..
//               �������� ���� ���� class��ü �����͵��� �ִٸ�, �¸� ���������� �����ϸ�, ���� ������ �� �ʿ� ���ݾ�?


// class ��ü�迭 ����� 2���� ��� ����
//  1. �ϳ��ϳ� class ��ü �����ϰ�, class ��ü�迭 ���� -> �׷��� ���� ��ü���� �ϳ��ϳ� �ݺ������� �迭�� �־���
//  2. class��ü�迭 �ϳ��� ������ �ΰ� -> �ݺ������� �����ڸ� �̿��ؼ� ��ü�迭 ������ �־���
#include <iostream>
using namespace std;

//  1�� �뵵 class
class classArray_without_constructor {

    private:
        int a;

    public:
        classArray_without_constructor() {
            cout << "classArray_without_constructor ������ ȣ��\n"; 
        }

        void Set(int _a) {
            a = _a; 
            cout << "classArray_without_constructor �� ����  "; 
        }

        void Show(int i) {
            cout << "classArray_without_constructor[" << i << "] = " << a << endl; 
        }
};

//  2�� �뵵 class(parameter 1��)
class classArray_with_constructor1 {

    private:
        int a;

    public:
        classArray_with_constructor1() {
            cout << "classArray_with_constructor1 ������ ȣ��\n";
        }

        classArray_with_constructor1(int _a) {
            a = _a; 
            cout << _a << "classArray_with_constructor1 ������ ȣ��\n";
        }

        ~classArray_with_constructor1() {
            cout << "classArray_with_constructor1 �Ҹ��� ȣ��\n";
        }

        void Set(int _a) {
            a = _a; 
            cout << "classArray_with_constructor1 �� ����  ";
        }

        void Show(int i) {
            cout << "classArray_with_constructor1[" << i << "] = " << a << endl;
        }
};

//  2�� �뵵 class(parameter 2��)
class classArray_with_constructor2 {

private:
    int a, b;

public:

    classArray_with_constructor2() {
        cout << "classArray_with_constructor2 ������ ȣ��\n";
    }

    classArray_with_constructor2(int _a, int _b) {
        a = _a;
        b = _b;
        cout << _a << "classArray_with_constructor2 ������ ȣ��\n";
    }

    ~classArray_with_constructor2() {
        cout << "classArray_with_constructor2 �Ҹ��� ȣ��\n";
    }

    void Set(int _a) {
        a = _a;
        cout << "classArray_with_constructor2 �� ����  ";
    }

    void Show(int i) {
        cout << "classArray_with_constructor2[" << i << "] : " << "a =  " << a << ", b = " << b << endl; 
    }

};

int main() {

    //  1. �ϳ��ϳ� class ��ü �����ϰ�, class ��ü�迭 ���� -> �׷��� ���� ��ü���� �ϳ��ϳ� �ݺ������� �迭�� �־���
    classArray_without_constructor ob1, ob2, ob3, ob4, ob5;

    // class ��ü�迭 ���� 
    classArray_without_constructor ob[5];

    for (int i = 0; i < 5; i++) {
        ob[i].Set(i + 1);
        ob[i].Show(i);
    }

    //-------------------------------------------------------------------------------------------------------------

    //  2. (������ 1��) class��ü�迭 �ϳ��� ������ �ΰ� -> �ݺ������� �����ڸ� �̿��ؼ� ��ü�迭 ������ �־���
    classArray_with_constructor1 obj[5] = { classArray_with_constructor1(6), classArray_with_constructor1(7), classArray_with_constructor1(8), classArray_with_constructor1(9), classArray_with_constructor1(10) }; //��ü�迭 �ʱ�ȭ ���

    for (int i = 0; i < 5; i++) {
        obj[i].Show(i);
    }

    for (int i = 0; i < 5; i++) {
        obj[i] = classArray_with_constructor1(i * 10);
    }

    for (int i = 0; i < 5; i++) {
        obj[i].Show(i);
    }

    //  2. (������ 2��) class��ü�迭 �ϳ��� ������ �ΰ� -> �ݺ������� �����ڸ� �̿��ؼ� ��ü�迭 ������ �־���

    //��ü�迭 ����ȭ�� �ʱ�ȭ ���
    // classArray_with_constructor2 obc[5] = { {1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50} }; 

    //��ü�迭 ������ ��� �ʱ�ȭ ���
    classArray_with_constructor2 obc[5] = { classArray_with_constructor2(1, 10), classArray_with_constructor2(2, 20), classArray_with_constructor2(3, 30), classArray_with_constructor2(4, 40), classArray_with_constructor2(5, 50) };

    for (int i = 0; i < 5; i++) {
        obc[i].Show(i);
    }

    for (int i = 0; i < 5; i++) {
        obc[i] = classArray_with_constructor2(i + 10, i * 10);
    }

    for (int i = 0; i < 5; i++) {
        obc[i].Show(i);
    }

    return 0;
}
