#include<stdio.h>
#include<iostream>

int main() {

	//----------------------C���---------------------
	int a, b;
	char x, y;
	printf("[C��� Ver]\n");
	printf("�� ���� �� ���� �Է� : ");
	scanf_s("%d %d %c %c", &a , &b , &x, sizeof(char), &y, 1);
	printf("�Է°�� : %d, %d, %c, %c\n\n", a, b, x, y);

	//----------------------C++-----------------------
	std::cout << "[C++ Ver]" << std::endl;
	std::cout << "�� ���� �� ���� �Է� : ";
	int c, d;
	char v, w;
	std::cin >> c >> d >> v >> w;
	std::cout << "�Է°�� : " << c << ", " << d << ", " << v << ", " << w << std::endl << std::endl;

	//------------------------------------------------

	return 0;
}