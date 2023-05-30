// ���ø� Ư��ȭ case�� �����ڵ�
#include <iostream>
#include <cstring>
using namespace std;

//-------------------------------------------------------------------------------------
// Max �Լ� ���ø�
template <typename T>
T Max(const T a, const T b) {
    return a > b ? a : b;
}

// Max �Լ� ���ø� Ư��ȭ1 : char* ��(���ڿ� ������)�� ���ؼ� Ư��ȭ
template <>
char* Max<char*>(char* a, char* b) {
    cout << "char* Max <char*> (char* a, char* b)" << endl;
    return strcmp(a, b) > 0 ? a : b; // ���� a <-> z ��
}

// Max �Լ� ���ø� Ư��ȭ2 : const char* ��(��� ���ڿ� ������)�� ���ؼ� Ư��ȭ
template <>
const char* Max<const char*>(const char* a, const char* b) {
    cout << "const char* Max <const char*> (const char* a, const char* b)" << endl;
    return strlen(a) > strlen(b) ? a : b; // ���ڿ� ���� ��
}

//-------------------------------------------------------------------------------------
// GetSize �Լ� ���ø�
template <typename T>
int GetSize(T data) {
    cout << typeid(data).name() << " Ÿ�� �Լ� ȣ��\n";
    return sizeof(data); //data�� ����Ʈ(byte)�� ����
}

// GetSize ���ø� Ư��ȭ1 : char* ���� ���ؼ� Ư��ȭ
template < >
int GetSize <char*>(char* data) {
    cout << typeid(data).name() << " Ÿ�� �Լ� ���ø� Ư��ȭ1\n";
    return strlen(data) + 1; //data ���ڿ��� ���̸� ����
}

// GetSize ���ø� Ư��ȭ2 : const char* ���� ���ؼ� Ư��ȭ
template < >
int GetSize <const char*>(const char* data) {
    cout << typeid(data).name() << " Ÿ�� �Լ� ���ø� Ư��ȭ2\n";
    return strlen(data) + 1; //data ���ڿ��� ���̸� ����
}

// Ư��ȭ�ϴ� �ڷ��� ������ �����ϰ� �������� �ʰ� �� �ǹ��ϴ� �ٿ� ���̴� ������,(������ �������� ó��) �������̸� �ڷ��� ������ ����ϴ� ���� ���� ��Ȯ�� �ϴ� ���
//  -> ��Ȥ string, char* or int, char, string �� ���� �κп��� �̹��ϰ� ���� ���ϴ� ����� ���� �� ����
//      -> ����, Ư��ȭ �Լ� ���ø� ȣ��� ���ø� �Ķ������ �ڷ����� �������� �ʾҴٸ�, �Լ� �Ķ���ͷ� ���� �ڷ����̶� ��Ȯ�� ���ֵ��� ���� (= �׷� �����Ϸ��� �� ��������) 
int main() {

    //----------------------------------------------------------------------------------
    cout << Max(11, 15) << endl;            // Max<int>(11, 15);�� ����
    cout << Max('T', 'Q') << endl;          // Max<char>('T', 'Q');�� ����
    cout << Max(3.5, 7.5) << endl;          // Max<double>(3.5, 7.5);�� ����

    char str1[] = "Simple", str2[] = "Balance";

    cout << Max(str1, str2) << endl << endl; // Max<char*>(str1, str2);�� ����
    cout << Max<char*>(str1, str2) << endl;
    cout << Max<const char*>(str1, str2) << endl;

    //----------------------------------------------------------------------------------
    cout << GetSize(5) << "����Ʈ\n";                          // GetSize<int>(5);�� ����
    cout << GetSize(3.14) << "����Ʈ\n";                       // GetSize<double>(3.14);�� ����
    cout << GetSize('A') << "����Ʈ\n";                        // GetSize<char>(3.14);�� ����
    cout << GetSize((char*)"Hello World") << "����Ʈ\n";       // <- ����, Ư��ȭ �Լ� ���ø� ȣ��� ���ø� �Ķ������ �ڷ����� �������� �ʾҴٸ�, �Լ� �Ķ���ͷ� ���� �ڷ����̶� ��Ȯ�� ���ֵ��� ���� (= �׷� �����Ϸ��� �� ��������) 
    cout << GetSize("Hello World") << "����Ʈ\n";              //     ex) "Hello World"�� �ڷ����� string���� char[]���� char* const���� �� ���� �� �� ���� (�� ��� ���α׷��� ȯ�漳���� �켱������ �ۿ���)

    return 0;
}