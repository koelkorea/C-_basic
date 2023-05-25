// ���ø� Ư��ȭ ����1
#include <iostream>
#include <cstring>
using namespace std;

// �Լ� ���ø�
template <typename T>
T Max(const T a, const T b) {
    return a > b ? a : b;
}

// ���ø� Ư��ȭ1 : char* ��(���ڿ� ������)�� ���ؼ� Ư��ȭ
template <>
char* Max<char*>(char* a, char* b) {
    cout << "char* Max <char*> (char* a, char* b)" << endl;
    return strcmp(a, b) > 0 ? a : b; // ���� a <-> z ��
}

// ���ø� Ư��ȭ2 : const char* ��(��� ���ڿ� ������)�� ���ؼ� Ư��ȭ
template <>
const char* Max<const char*>(const char* a, const char* b) {
    cout << "const char* Max <const char*> (const char* a, const char* b)" << endl;
    return strlen(a) > strlen(b) ? a : b; // ���ڿ� ���� ��
}

//Ư��ȭ�ϴ� �ڷ��� ������ �����ϰ� �������� �ʰ� �� �ǹ��ϴ� �ٿ� ���̴� ������,(������ �������� ó��)
//�������̸� �ڷ��� ������ ����ϴ� ���� ���� ��Ȯ�� �ϴ� ���
int main() {
    cout << Max(11, 15) << endl; //Max<int>(11, 15) <int> ����
    cout << Max('T', 'Q') << endl; //Max<char>('T', 'Q') <char> ����
    cout << Max(3.5, 7.5) << endl; //Max<double>(3.5, 7.5) <double> ����

    char str1[] = "Simple", str2[] = "Balance";

    cout << Max(str1, str2) << endl << endl; //Max<char*>(str1, str2) <char*> ����
    cout << Max<char*>(str1, str2) << endl;
    cout << Max<const char*>(str1, str2) << endl;

    return 0;
}