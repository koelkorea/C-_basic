// ���ø�(Template)
//  : function or class�� �ڷ� Ÿ�Կ� ���� ���������� �ٽ� �ۼ����� �ʾƵ�, parameter�� �ڷ����� Ȯ���ϰ� ������ �ܰ迡�� parameter �ڷ����� �´� function or class �������ִ� Ʋ�μ� �۵�
//    -> (�߿�) ������ �ܰ迡�� �۵��� = ���ø��� ���� ���� ������ �ӵ��� ������ <-> ���α׷� ó�� �ӵ��� ���� X
//        -> JAVA�� ���ʸ���(generics)�� ������ ��� (��! ���ʸ����� ������ ���������� Ÿ�� check��� �߰�)

//   # ���ø� ��� ����?
//      : ��¥ ����� ���� ���´ٸ�? �ڵ��� �ϼ����� ��������, �������� ���꼺 ȿ���� �����ϱ� ���� 
//         -> �̷��� ������ STL(Standard Template Library)ó�� ������ ���̺귯���� �Բ��� �ó����� ���� ����

//   # ���ø��� ����
//     1. �Լ� ���ø�(function Template)
//        : �Լ��� �Ϲ����� ������ ����, �Լ� ȣ�� �ÿ� '������ �ڷ���' ���� ���ڷ� �޾� ���� �Լ��� �����ϴ� Ʋ
// 	   
//          ex) list(initializer_list<Type> IList, const Allocator& Al);

// �Լ� ���ø� ����1
#include <iostream>
using namespace std;

template <typename T1, typename T2, typename T3>

void showData(T1 a, T2 b, T3 c) {
    cout << endl;
    cout << a << "\t" << b << "\t" << c << endl;
    cout << typeid(a).name() << "\t" << typeid(b).name() << "\t" << typeid(c).name() << endl;
}

int main() {
    showData(10, 20, 30);
    showData('A', 'B', 'C');
    showData(10, 3.14, "C++");
    return 0;
}
