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
//      -> (����!) �� �༮�� ������, �ش� �Լ��� Ŀ���Ǵ� ������ ���� �Լ��� ��� overloading�� �ٸ� �Լ��� ����, � �Լ��� �ҷ������� ��ǻ�Ϳ� ȥ���� �ְ� ��.. 

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

//  # Default Parameter ���� ���ǻ���
//    : �� ��ȵ��� ��Ű�� �ʴ´ٸ� �浹�� �� ����
//       1. parameter�� ����Ʈ ���� parameter�� ����� �� �����ʿ� ��ġ�� �༮�������� ���ʴ�� �Ҵ�
//       2. Default Parameter�� �ۼ��� overloading �Լ��� �����ϴ� ��Ȳ����, �ش� �Լ��� Ŀ���Ǵ� parameter������ ������ ���� �Լ��� ��� overloading�� �ٸ� �Լ��� ����, � �Լ��� �ҷ������� ��ǻ�Ϳ� ȥ���� �ְ� ��

//          ex) 1�� ��� ����

//              int sum(int a = 0, int b = 0, int c=0, int d, int e) {
//                  return a + b + c + d + e;
//              }

// 2�� ��� ����
#include <iostream>
using namespace std;

void call(int a) {
	cout << "�μ� 1�� ȣ��\n";
}

// 
void call(int a, int b = 0) {
	cout << "�μ� 2�� ȣ��\n";
}

int main() {
	// call(1);       <- �� ��� 1��° �Լ��� ȣ���ؾ� �ϳ�?? �ƴϸ� 2��°�� defalut parameter�� �����ؾ� �ϳ�?
	call(2, 3);
	return 0;
}
