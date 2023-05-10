//   # this�����͸� Ȱ���ϱ� ��ȿ�� ���
//      1. ����Լ��� parameter�� ��������� �̸��� ���� ���
//          ex) class B {
//                 int i, j;
//                 void Set(int i, int j) {      <- ���� ��������� parameter�� �̸��� i , j�� ����
//                    this->i = i;               <- this->i ��� ������ �� �� ������ ���� �ذ� ����
//                    this->j = j; 
//                 }

//      2. ����Լ����� �Լ��� ȣ���� ��ü�� �� ��ü�� ��ȯ�ϴ� ���
//          -> ��.. �̰� �� ��ü�� ���� ���� ��� �˾�? ��� ���ϰ�
//             -> �ش� Ŭ���� �����ͺ��� �������� ��ü�� �ּҰ��� �޴� this�� �������� ��ü�� *this�� return�ϸ� ��! 

// this�����͸� Ȱ���ϱ� ��ȿ�� ��� 2���� ����
#include <iostream>
using namespace std;

// ���� Ŭ����
class Calc {

    private:
        int m_Value = 0;

    public:

        Calc& Add(int value) { 
            m_Value += value; 
            return *this; 
        }

        Calc& Sub(int value) {
            m_Value -= value; 
            return *this; 
        }

        Calc& Mul(int value) {
            m_Value *= value;
            return *this; 
        }

        int GetValue() {
            return m_Value; 
        }
};

int main() {

    Calc obj1;

    // Add(10)�� ��� -> ����� Calc��ü -> �� calc ��ü�� sub(5) �ݿ� �� Calc��ü ���� -> �� calc ��ü�� Mul(4) �ݿ� �� Calc��ü ����
    obj1.Add(10).Sub(5).Mul(4);

    // ����� 20
    cout << obj1.GetValue() << endl; 

    return 0;
}
