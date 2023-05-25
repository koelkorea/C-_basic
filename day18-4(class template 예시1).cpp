// ���ø�(Template)
//  : function or class�� �ڷ� Ÿ�Կ� ���� ���������� �ٽ� �ۼ����� �ʾƵ�, parameter�� �ڷ����� Ȯ���ϰ� ������ �ܰ迡�� parameter �ڷ����� �´� function or class �������ִ� Ʋ�μ� �۵�
//    -> (�߿�) ������ �ܰ迡�� �۵��� = ���ø��� ���� ���� ������ �ӵ��� ������ <-> ���α׷� ó�� �ӵ��� ���� X
//        -> JAVA�� ���ʸ���(generics)�� ������ ��� (��! ���ʸ����� ������ ���������� Ÿ�� check��� �߰�)

//   # ���ø� ��� ����?
//      : ��¥ ����� ���� ���´ٸ�? �ڵ��� �ϼ����� ��������, �������� ���꼺 ȿ���� �����ϱ� ���� 
//         -> �̷��� ������ STL(Standard Template Library)ó�� ������ ���̺귯���� �Բ��� �ó����� ���� ����

//   # ���ø��� ���� 	   
//     2. Ŭ���� ���ø�(class Template)
//        : Ŭ������ �Ϲ����� ������ ����, Ŭ������ ��� ������ ��� �Լ��� ���� '������ �ڷ���' ���� ���ڷ� �޾� ���� Ŭ������ �����ϴ� Ʋ

//          ex1) template <value�ڷ��� �����̳ʿ�Ҹ�>    
//               -> ���� �����̳� class ��ü�� �����ϸ�, �� ������ value�ڷ����� ������ �ڷ������� ����

//          ex2) �����̳�Ŭ������ <value�ڷ���> ��ü�� = new �����̳�Ŭ������(); ���ĵ� ���� ���� ����


//Ŭ���� ���ø� ����1
#include <iostream>
using namespace std;

// Ŭ���� ���ø�
template <typename T>

class Dummy {
    private:
        T a;
    public:
        Dummy(T a);
        inline void SetA(T a);
        inline T GetA() const;
};

// �Լ� ���ø�
template <typename T>

Dummy<T>::Dummy(T a) : a(a) {}

// �Լ� ���ø�
template <typename T>

inline void Dummy<T>::SetA(T a) { this->a = a; }

// �Լ� ���ø�
template <typename T>

inline T Dummy<T>::GetA() const { return a; }

int main() {

    Dummy<int> d1(10);
    cout << d1.GetA() << endl;     // 10

    Dummy<int> d2('A');
    cout << d2.GetA() << endl;     // 'A' = 65

    Dummy<char> d3('A');
    cout << d3.GetA() << endl;     // 'A' = 65

    Dummy<double> d4(3.14);
    cout << d4.GetA() << endl;     // 3.14

    Dummy<const char*> d5("C++");
    cout << d5.GetA() << endl;     // "C++"

    return 0;
}