//   # C++�� ���� ���� (header.h / source.cpp / main.cpp)�� class�� ����
//     : ��� ����(.h)   : class�� �����, inline �Լ� �ۼ�
//     : �ҽ� ����(.cpp) : fuction�̳� class�� fuction ���Ǻ� �ۼ�
//     : ���� ����(.cpp) : main()�Լ� �ۼ�

//main.cpp
#include <iostream>
#include "day05-3�� ���.h"
using namespace std;
int main() {
	ACT act_1;
	act_1.Init_act(1234, "5678", "christopher", 10000);
	act_1.showData();       //�ܾ���ȸ ��� �Լ� ȣ��
	act_1.deposit();        //�Ա� ��� �Լ� ȣ��
	act_1.withdraw();       //��� ��� �Լ� ȣ��
	act_1.showData();       //�ܾ���ȸ ��� �Լ� ȣ��
	return 0;
}
