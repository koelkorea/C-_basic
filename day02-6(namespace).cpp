// namespace(�̸�����)
//	: ���� ������Ʈ�� ������ �� or ������ ������Ʈ�� ������ �� �ߺ��Ǵ� ��ҷ� ���� �浹�� ���� ���� ����
//	  -> using namespace std�� �߰��� ����
//
//   # namespace �ۼ��� (= �����)

//     ex) namespace namespace�� {
//            ����Ÿ�� namespace�Լ���() {
//               ����
//            }
//         }

//   # ���� �Ϸ�� namespace ȣ���ϴ� 3���� ��� (= ����)
//     1. namespace��::�ĺ��ڸ� ���[std::cout; ]
//        :  
//     2. using ���þ ����Ͽ� �̸� ���� ���� Ư�� �ɺ�(symbol) ���[using std::cout; ]
//        :
//     3. using ���þ ����Ͽ� �̸� ���� ���� ��� �ɺ� ���[using namespace std; ]
// 
//	�̸� ���� �ȿ� ���� �� ����� �ٷ� ȣ���� �Ұ���
//	�ݵ�� ��� �̸� ������ ���� ��������� ���� �� ���
//	(using namespace �̸�������;)
//
//	iostream ��������� ��� Ŭ������ ��ü, �Լ����� std��� �̸� ���� �ȿ� ����
//	
//	
//	
//	::������(���� ���� ������)�� ����� ������ �� ����ϴ� �����ڴ�.
//
//
//	namespace
//	�ϳ��� ���Ͽ� ���� ���� namespace�� �� �� �ִ�.
//
//
//
//
//
//
//
//	���� �� ���Ͽ� �� ���� namespace�� �� �� �ִ�.
//
//
//
//
//
//	ǥ�� �������
//	C++ǥ�ؾ����� C�� �⺻ ������ϵ鵵 �ٽ� �������.
//	iostream.h->iostream | stdlib.h->cstdlib
//	string.h->cstring | math.h->cmath
//	��� �ɺ��� std��� �̸� ���� �ȿ� ����Ǿ� �ִ��� �ƴ����� ����

#include <iostream>
using namespace std;

namespace A {
	void BUBLE() {
		cout << "A::BUBLE\n";
	}
	void pop() {
		cout << "A::POP\n";
	}
}

namespace B {
	void BUBLE() {
		cout << "B::BUBLE\n";
	}
	void pop() {
		cout << "B::POP\n";
	}
}

using namespace B;

int main() {

	A::BUBLE();
	BUBLE();
	A::pop();
	pop();

	return 0;
}