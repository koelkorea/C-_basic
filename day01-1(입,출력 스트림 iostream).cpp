// c++.cpp : c++ ���� Ȯ����, �� ���Ͽ��� 'main' �Լ��� �⺻������ ���Ե�

#include <iostream>   // cin, cout, clog, cerr    <- stdio.h�� scanf, printf ��ü

int main() {

	int age = 0;

	// << , >> ��Ʈ������ = ��Ʈ�������� : ȭ��ǥ ������ ��Ʈ���� �帧�� �ǹ� (�̰ɷ� �Է½� ������ ���Ե� ���ڿ��� �� ����)

	std::cout << "���ڿ��� �Է������\n";
	std::cin >> age;                  // std::cin >> ������ : �ش� ������ ������ �����͸� �Է���(>>�� �Է½� ������ ���Ե� ���ڿ��� �� ����)
	std::cout << "Hello World\n";     // std::cout << "����" : �ش� "����"�� �������
	std::cout << age;                 // std::cout << "������" : �ش� ������ �Էµ� ������ �������
	std::cout << std::endl;           // endl : \n�� �ǹ�

	return 0;
}
