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

// �Լ� ���ø� ����2
#include <iostream>
using namespace std;

template <typename T>

// ���ø� �⺻�� �Լ�
void print(T n) { 
	cout << "������ �μ� 1�� => ";
	cout << n << endl;
}

// ���ø� �Ķ���� ��
template <typename T1, typename... T2> 

// �Լ� �ĸ����� ��
void print(T1 arg, T2... args) {
	cout << "�����μ� => ";
	cout << arg << endl;
	print(args...);
}

int main() {
	print(1.2345);
	print(1, 2.5, "C++");
	print(1, 2, "Hello", 'a', 32.14, 78, 56, "apple");
	return 0;
}
