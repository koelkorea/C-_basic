// �κ� Ư��ȭ ���� - 
#include <iostream>
using namespace std;

// �κ� Ư��ȭ : ���ø��� �Ű������� �������� ��� �Ű����� �� �Ϻθ� Ư��ȭ
template <typename T, int count>

void display(T value) {
	for (int i = 0; i < count; i++) cout << value << ' ';
	cout << endl;
}

int main() {
	display<int, 5>(0);      //  <int, 5> �ݵ�� �ۼ�
	display<char, 10>('A');  //  <char, 10> �ݵ�� �ۼ�
	display<double, 3>(3.4); //  <double, 3> �ݵ�� �ۼ�
	return 0;
}