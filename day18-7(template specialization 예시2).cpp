// ���ø� Ư��ȭ ����1
#include <iostream>
using namespace std;

template <typename T>
int GetSize(T data) {
	cout << typeid(data).name() << " Ÿ�� �Լ� ȣ��\n";
	return sizeof(data); //data�� ����Ʈ(byte)�� ����
}

// ���ø� Ư��ȭ1 : char* ���� ���ؼ� Ư��ȭ
template < >
int GetSize <char*>(char* data) {
	cout << typeid(data).name() << " Ÿ�� �Լ� ���ø� Ư��ȭ1\n";
	return strlen(data) + 1; //data ���ڿ��� ���̸� ����
}

// ���ø� Ư��ȭ2 : const char* ���� ���ؼ� Ư��ȭ
template < >
int GetSize <const char*>(const char* data) {
	cout << typeid(data).name() << " Ÿ�� �Լ� ���ø� Ư��ȭ2\n";
	return strlen(data) + 1; //data ���ڿ��� ���̸� ����
}
int main() {
	cout << GetSize(5) << "����Ʈ\n";
	cout << GetSize(3.14) << "����Ʈ\n";
	cout << GetSize('A') << "����Ʈ\n";
	cout << GetSize((char*)"Hello World") << "����Ʈ\n";
	cout << GetSize("Hello World") << "����Ʈ\n";
	return 0;
}