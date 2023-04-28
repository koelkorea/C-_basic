// Function Overloading
//  : �Լ����� ������, �Ű�����(�μ�)�� �ڷ� ���̳� ������ �ٸ��ٸ�? 
//    -> �ٸ� �Լ��� �����ϴ� �� 

//       ex) [�����ε�X���� �Լ��� ���� �ٸ�]               [�����ε� ���ɽ� �Լ����� ���� �� ����]                         
//           char max_char(char a, char b);          ->   char max(char a, char b);
//           int max_int(int a, int b);              ->   int max(int a, int b);
//           double max_double(double a, double b);  ->   double max(double a, double b);

//  # (�߿�) ���� Ÿ���� �����ε��� ����

//  # C��� VS C++ ������ �Լ� ȣ��
//    - C���
//       : �����ε� ��� X
//          -> �Լ��� ������ ȣ�� = ���� �Լ��� BUT �ٸ� �Ű�����(parameter)�� �Լ� ��� �Ұ�
// 
//    - C++
//       : �����ε� ��� O
//          -> �Լ��� + �Ű�����(parameter)�� ������ �Բ� ������ ȣ�� = ���� �Լ��� BUT �ٸ� parameter�� �Լ����� �Ǻ�

//  # Overloading �Լ� ȣ�� ����
//    (1) Exactly Matching 
//        : �����ϴ� �Ű������� ��Ȯ�ϰ� ��ġ�ϴ� Ÿ���� �ִ��� ã��
//    (2) Promotion
//        : �Ķ���ͷ� �� �������� �ս��� ���� ���������� return�Ͽ� ��ȯ�� ������ �Լ��� �ִ��� ã��
//          ex) �Ķ���Ͱ� int->double ���� ��, �������� �ս� ����.. ���� double�� ã�� ȣ��
//    (3) Standard Conversion
//        : ǥ�� Ÿ�Ե� ������ �Ͻ����� �� ��ȯ�� �߻� 
//          ex) �Ķ���Ͱ� double->int ���� ��, �׷��� �������� �ս��� ������ int�� ã�� ȣ��
//    (4) User Define Conversion Operator
//        : ����ڰ� ������ ��ȯ �����ڰ� �ִٸ� �̰��� ����ؼ� ��ȯ�� �� ��, �Լ��� ã��
//    (5) Variable Argument Function(�Ķ���Ϳ� ...�� ���� ���)
//        : '��' ���� �Ķ���͸�(��...��) �Ű������� ���� �Լ��� �Ķ������ Ÿ���̳� ������ ������� ȣ��

// (�߿�!) Default Parameter	  <- JS���� ����
//  : �Ű������� �⺻ ���� �̹� �ο��Ͽ� �����ϴ� �Լ�
//    -> if �Լ� ȣ�� �� ���޵Ǵ� ���� �ִٸ�?
//       -> o : �Ķ���Ϳ� ���޵� ������ ��ü
//       -> x : �̸� �ο��� �Ķ���� �ڽ��� �⺻ ���� ���

//  # Default Parameter ǥ���
//     : �Ķ���� ������� ������ ���ڵ���� ���ϴ� ���� ����Ʈ ������ �Ҵ���
//       -> Why? �̷��� ���� ������, Function Overloading ü�谡 ������ ����� �Լ��� �ν��ؼ� ȣ������ ����

//    ex) int sum(int a, int b, int c = 0, int d = 0, int e = 0) {
//	 		return a + b + c + d + e;
//        }

//  # Default Parameter�� ����
//    : �������� ��Ģ�� �ǰ�, �ϳ��� �Լ��� �ۼ��������� Default Parameter�� ����� �Ķ���Ϳ� ���� ��� �ֳĿ� ����, �پ��� ��쿡 ���� �ٸ� �Լ��� �νĵǰ� �� �� ����

//      ex) [Default Parameter�� ����]               =>               [Default Parameter�� ����, �� �Լ��� 3���� ��� Ŀ���� ���� ������] 
// 
//          int sum(int a, int b) {                                   int sum(int a, int b, int c = 0, int d = 0, int e = 0) {
//				return a + b;                                              return a + b + c + d + e;
//          }														  }
// 		    
//          int sum(int a, int b, int c) {
//          	return a + b + c;
//          }
// 		    
//          int sum(int a, int b, int c, int d) {
//          	return a + b + c + d;
//          }


// ������ �̸����� �Լ� �ۼ�, ��� Ȯ���ϱ�
#include <iostream>
using namespace std;

int sum(char a, char b) {
	return a + b;
}

int sum(int a, int b) {
	return a + b;
}

double sum(double a, double b) {
	return a + b;
}

void call(int a) {

	cout << "�μ� 1�� ȣ��\n";
}

void call(int a, int b) {

	cout << "�μ� 2�� ȣ��\n";
}


int main() {

	char char_a = 'A', char_b = 'B';
	int int_a = 50, int_b = 30;
	double double_a = 12.3456, double_b = 45.6789;

	cout << "���� �հ� : " << sum(char_a, char_b) << endl;
	cout << "���� �հ� : " << sum(int_a, int_b) << endl;
	cout << "�Ǽ� �հ� : " << sum(double_a, double_b) << endl;

	call(1);
	call(2, 3);

	return 0;
}
