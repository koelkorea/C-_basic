// ���� �Ҹ��� �Լ�(Virtual destructor function)
//  : ���� �Լ��� ������ �����Ͽ�, up casting�Ͽ� ������ �ڽ� class��ü�� ������� ����� �θ� class�����ͷ� ����� �ְ� �ϴ� �Ҹ��� �Լ�
//     -> ����ϰ� �� ��, ��� ���� ���� ������ ���ļ� Ŭ���� �Ҹ��ں��� �ֻ��� Ŭ���� �Ҹ��ڱ��� ��� ȣ���ϰ� �Ǿ� ��θ� ����� �ϴ� ����
//
//   # ���� �Ҹ��� �Լ�(Virtual destructor function) ����
//      : virtual ~Ŭ������() {  ����  };
//         -> �ֻ��� class �Ҹ��ڿ��� virtual�� �߰��� �����ص�, ���� class ���� ��� ���� �Ҹ��� ����ǰ� ������


// day 13-10 �����ڵ带 ���� �Ҹ��� �Լ� �����Ͽ� ������ ����
#include <iostream>
#pragma warning (disable : 4996)

using namespace std;

class Person {

    private:
        char* name;

    public:
        Person(const char* pN) { name = new char[strlen(pN) + 1]; strcpy(name, pN); cout << "\nPerson ����"; }
        virtual ~Person() { cout << "\nPerson �Ҹ�\n"; delete[] name; }
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
        void show() { Person::show(); cout << "\n��ȣ : " << phone << "\n�ּ� : " << nationality << endl; }
};

int main() {
    Person* c1 = new Custom("michelin", "010-1234-5678", "South Korea");
    c1->show();
    delete c1;
    return 0;
}
