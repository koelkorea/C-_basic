#include<stdio.h>
#include<iostream>

int main() {

	//----------------------C언어---------------------
	int a, b;
	char x, y;
	printf("[C언어 Ver]\n");
	printf("두 수와 두 문자 입력 : ");
	scanf_s("%d %d %c %c", &a , &b , &x, sizeof(char), &y, 1);
	printf("입력결과 : %d, %d, %c, %c\n\n", a, b, x, y);

	//----------------------C++-----------------------
	std::cout << "[C++ Ver]" << std::endl;
	std::cout << "두 수와 두 문자 입력 : ";
	int c, d;
	char v, w;
	std::cin >> c >> d >> v >> w;
	std::cout << "입력결과 : " << c << ", " << d << ", " << v << ", " << w << std::endl << std::endl;

	//------------------------------------------------

	return 0;
}