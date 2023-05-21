// namespace(�̸�����)
//	: ���� ������Ʈ�� ������ �� or ������ ������Ʈ�� ������ �� �ߺ��Ǵ� ��ҷ� ���� �浹�� ���� ���� ����
//	  -> using namespace std�� �߰��� ����
//
//   # namespace �ۼ��� (= �����)
//      : namespace namespace�� {  ����Ÿ�� namespace�Լ���() {  ����  }  }


//   # ���� �Ϸ�� namespace�� ��ü �� �Լ� ȣ���ϴ� 3���� ��� (= ����)
//      : namespace �ȿ� ���� �� ����� �ٷ� ȣ���� �Ұ��� -> �ݵ�� ��� namespace�� ���� ��������� ���� �� ���

//     1. namespace��::�ĺ��ڸ� ���  
//        ex) std::cout 
//            (= std�� namespace���� cout�̶�� ��ü�� ���� )
//               -> cin�� cout�� ��Ȯ�ϰԴ� iostream,  ostream Ŭ������ ��ü�� std�ȿ� �̹� ����Ǿ� ����

//     2. using ���þ ����Ͽ� �̸� ���� ���� Ư�� �ɺ�(symbol) ���
//        ex) using std::cout; 
//            (= ������ cout�̶�� ��Ī�� ����, std���� cout ��ü��� �����ϱ�)

//     3. using ���þ ����Ͽ� �̸� ���� ���� ��� �ɺ� ��� (�ٵ� ���� ������)
//        ex) using namespace std; 
//            (= ������ ����ڰ� �������� �ʰ� ���̺귯������ ���� ������ ��ü�� �Լ��� ������, std��� namespace���� �ĺ��ڰ� �ִ��� ���� ��ó�ض�


//   # (�߿�) namespace Ư¡
//     1. �ϳ��� ���Ͽ� ���� ���� namespace ��� ����
//     2. ���� �� ���Ͽ� 1���� namespace ���� ��� ����
//     3. ǥ�� �������
//         : C++ǥ�ؾ����� C�� �⺻ ������ϵ� �ٽ� ���� (= ���� ������� C�� �⺻ �������, ��� �ɺ��� std��� �̸� ���� �ȿ� ���� ��)

//            ex) iostream.h -> iostream     <- iostream ��������� ��� Ŭ������ ��ü, �Լ����� std��� �̸� ���� �ȿ� ����
//                stdlib.h   -> cstdlib
//                string.h   -> cstring
//                math.h     -> cmath


//   # (c++ �߰� + �߿�) c++���� :: ������
//     : scope resolution ������ (namespace, class, struct �� �ڱ� ����(scope)�� �ִ� �ڷ����� ���, �� Ư�� �ڷ��� ���� ���(����, �Լ� �� ����)�� ã�� �����϶�� �ǹ�)
//       -> (���) namespace��::�ĺ���, ����ü��::����Լ�(), ���� ���� �ƶ����� �����ϸ� ��
//            -> BUT! 'namespace��::�ĺ���', 'class��::static������� or static����Լ�' �� ȣ���̳� �����ϴ� ��ɿ� �����     <->    ����ü��::����Լ�()�� '�Լ� ���Ǻ�'�� ���� ( <-> ������ ����ü or Ŭ���� ������.����Լ�() )


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

// namespace B�� ���ؼ��� using ��ɾ� ���
using namespace B;

int main() {

	// namespace A�� �Լ� BUBLE() ȣ��
	A::BUBLE();

	// namespace B�� BUBLE() ȣ��
	BUBLE();

	A::pop();
	pop();

	return 0;
}