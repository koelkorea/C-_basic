// 2. Up casting
//  : �������� ������ ���� '��Ʈ�� Ŭ���� ����'�� ����� �θ� class������ ������ ����, ���� class ��ü�� �����ϰ� �� �ּҰ��� �޾Ƶ� ���� �����ϰ� �ϴ°� 

//   - ��Ʈ�� Ŭ���� (Control Class)
//     : ������Ʈ ���ο� �����ϴ� ��� ���迡 ���� �پ��� Ŭ�������� ��� �Ѱ��� �����ϱ� ����, ��ü���� �� ���, ������ ��Ģ�� �԰��� class ����
//        -> �̸� ���� up casting �������� �θ�class�����͸� �̿��� �ڽ� class ��ü�� �����ϰ� �� �ּҰ��� �޾� ���� ������ 

//     # (��Ʈ�� Ŭ����) Up casting ����
//        : ����Ŭ������* ������ = new ���� Ŭ����

//     # (��Ʈ�� Ŭ����) Up casting ����
//        : [������]���� ��� ����
//           1. �θ� class ��ü �����ͷε� �� �Ʒ� �ļ� class�� ����� ��ü�� ��θ� ����ų �� ����
//           2. �ڽ� class ��ü�� �߰�, ���� �� ��쿡�� ������ ���� ����

//     # (��Ʈ�� Ŭ����) Up casting ������
//        : (�߿�!) [�θ� class ��ü�������� Ư¡ �� �Ѱ�]���� ��� ����
//          -> �θ� class�� ��ü �����ͷ� �ڽ� class ��ü�� ��ġ�� �޸� ��ġ���� ������ �� ������, BUT! �θ������ͷ� �ڽİ����� ������� ȣ�� �� ���� �Ұ���
//              1. override�� �ڽ� class�� ����Լ��� ȣ���ϰ� �; ��ġ�� �θ���� ȣ���
//              2. �θ� class������ ���� ������ �ּ� ���п�, delete�� �θ� class �Ҹ��ڷ� �۵���...
//                 (= ����class�� �Ҹ��ڴ� ȣ�� X = �ڽ� class ��������� ���� �޸𸮿� �������� = ��ũ������ ���� �� ġ���, ��Ͻ�Ÿũ�� ����� ��)

//     # (����) class ��ü������
//        : class ��ü�� �ּҰ��� �����ϴ� class ������ ����
//           -> ���� �Ҵ�� �޸𸮴� ���� classŸ���� �����͸��� ���ٰ���

//              ex) Class* p = new Class;
//                   -> Class* p : ��ü ������ ���� p
//                   -> new Class : new�� Class ������ �Լ��� ȣ���ϰ�, �� �����ڰ� ��ü ���� �� ����� �ʱ�ȭ�ϸ�, new�����ڸ� ���� �������� �޸� �Ҵ� �� �� �����ּ� ���� ����


// ��Ʈ�� Ŭ������ ���� Up casting ������2 ����
//  -> delete�� �θ� class �Ҹ��ڷ� �۵��ϴ� �ٶ���, ����class�� �Ҹ��ڴ� ȣ����� �ʴ� ��Ʈ�� Ŭ������ �θ� class������..
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

class Person {
private:
    char* name;
public:
    Person(const char* pN) { name = new char[strlen(pN) + 1]; strcpy(name, pN); cout << "\nPerson ����"; }
    ~Person() { cout << "\nPerson �Ҹ�\n"; delete[] name; }
    virtual void show() { cout << "\n\n�̸� : " << name; }
};

class Custom : public Person {
private:
    char* phone;
    char* nationality;
public:
    Custom(const char* pN, const char* pP, const char* pNa) : Person(pN) {
        phone = new char[strlen(pP) + 1];
        strcpy(phone, pP);
        nationality = new char[strlen(pNa) + 1];
        strcpy(nationality, pNa);
        cout << "\nCustom ����";
    }
    ~Custom() { cout << "\nCustom �Ҹ�"; delete[] phone, nationality; }
    virtual void show() { Person::show(); cout << "\n��ȣ : " << phone << "\n�ּ� : " << nationality << endl; }
};

int main() {

    Person* c1 = new Custom("michelin", "010-1234-5678", "South Korea");

    c1->show();

    // �θ� class�����͸� ���� �������̱⿡..
    // -> ��������δ� �ڽ� class�� �յ� �� ���
    delete c1;

    return 0;
}