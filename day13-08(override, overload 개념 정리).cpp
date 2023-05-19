// �������̵� (Override)
//  : �ڽ�class�� ���� ���Ű������� ����Լ��� ������
//    (= �ڽ�class�� ����Լ��� ���� ������ �θ�class�� ����Լ��� �Ϻ��� ��ġ�ϴ� ���, �ڽ�class�� ����Լ��� �ٸ� ������� ������ �����ϴ� ��)
//        -> ���� �θ�class�� ������ ����ϳ�, ������ �޶�� �ϴ� ��쿡�� ��� 
// 
//            ex) ����� '���ϴ�' <-> ����� '���ϴ�'

//                 class human                 { void Work(int x) { cout << "����� ����"; } }
//                 class salaryman : human     { void Work(int x) { cout << "���޹ޱ� ���� ���ϴ� ������"; } }
//                 class carpener  : salaryman { void Work(int x) { cout << "����� ���縦 �ٵ�� ������"; } }
//                 class owner     : human     { void Work(int x) { cout << "��� ��â�� ���� ���ϴ� �����"; } }

// �����ε�(Overloading)
//  : ������ �Լ����� ����� ������ �ٸ� �Լ����� �ߺ�����
//    (= �Լ��� �̸��� ����, �Ű������� Ÿ��, ������ �ٸ��� �ؼ� �ٸ� �Լ��� �ν��ϰ� �ϴ� ��)

//       ex) ����� '������ ������' ���ϴ� <-> ����� '���� ����' ���ϴ�

//            class human { void Work(string car)                 { cout << "����۾�"; } }
//                        { void Work(string hammer)              { cout << "ö���۾�"; } }
//                        { void Work(string computer)            { cout << "���α׷��� �۾�"; } }
//                        { void Work(string hammer, string nail) { cout << "��ġ�� �۾�"; } }


// ��Ӱ� override �ڵ� ����
#include <iostream>
using namespace std;

// A -> B -> C �帧���� ����� ���������, �׵��� �������� ���� func() ����Լ��� override�Ǿ� �� ����� ���� �ٸ� �� Ȯ�� ����
class A {
    public:
        void func() { cout << "A::func" << endl; }
};

class B : public A {
    public:
        void func() { cout << "B::func" << endl; }
 };

class C : public B {
    public:
        void func() { cout << "C::func" << endl; }
};

int main() {

    // �������� ��Ģ�� ���� ap = bp = cp = new C ���� 
    //  -> ���ʿ� C�� B�� A�� ������� �ۼ��� ���ļ�class�̱⿡, A�� B�� C�� �ھ�� ���� (��ũ������ C�� �����̴� ���̾�� ��Ʈ B, �� ��Ʈ�� �����ϴ� ��Ͻ�Ÿũ A)
    C* cp = new C;
    B* bp = cp;
    A* ap = bp; 

    //��ü ������ Ÿ���� ��� �Լ��� ȣ��
    ap->func(); 
    bp->func();
    cp->func();

    delete ap, bp, cp;

    return 0;
}
