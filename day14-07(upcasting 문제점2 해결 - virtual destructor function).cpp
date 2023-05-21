// 3. �����Լ� (virtual function)

//   - ���� �Ҹ��� �Լ�(Virtual destructor function)
//     : ���� �Լ��� ������ �����Ͽ�, up casting�Ͽ� ������ �ڽ� class��ü�� ������� ����� �θ� class�����ͷ� ����� �ְ� �ϴ� �Ҹ��� �Լ�
//        -> ����ϰ� �� ��, ��� ���� ���� ������ ���ļ� Ŭ���� �Ҹ��ں��� �ֻ��� Ŭ���� �Ҹ��ڱ��� ��� ȣ���ϰ� �Ǿ� ��θ� ����� �ϴ� ����
//   
//     # ���� �Ҹ��� �Լ�(Virtual destructor function) ����
//        : virtual ~Ŭ������() {  ����  };
//           -> �ֻ��� class �Ҹ��ڿ��� virtual�� �߰��� �����ص�, ���� class ���� ��� ���� �Ҹ��� ����ǰ� ������

// day 14-05 �����ڵ带 ���� �Ҹ��� �Լ� �����Ͽ� ������ ����
#include <iostream>
#pragma warning (disable : 4996)

using namespace std;

// ��� class
class Person {

    private:
        char* name;

    public:

        // Person ������ 
        //  : �̸��� char�迭�� ���ڿ��� parameter�� ������ char�迭�� �ް�, �̸� char�迭�� �����Ҵ��� char�������� ������� name�� ��ġ�� �ش��ϴ� ���� ������
        Person(const char* pN) {
            name = new char[strlen(pN) + 1]; 
            strcpy(name, pN); 

            cout << "\nPerson ����"; 
        }

        // ���� �Ҹ��� �Լ�(Virtual destructor function)
        //  : ���� �Լ��� ������ �����Ͽ�, up casting�Ͽ� ������ �ڽ� class��ü�� ������� ����� �θ� class�����ͷ� ����� �ְ� �ϴ� �Ҹ��� �Լ�
        //     -> ����ϰ� �� ��, ��� ���� ���� ������ ���ļ� Ŭ���� �Ҹ��ں��� �ֻ��� Ŭ���� �Ҹ��ڱ��� ��� ȣ���ϰ� �Ǿ� ��θ� ����� �ϴ� ����

        // virtual ~Ŭ������() {  ����  };
        //  -> �ֻ��� class �Ҹ��ڿ��� virtual�� �߰��� �����ص�, ���� class ���� ��� ���� �Ҹ��� ����ǰ� ������
        virtual ~Person() {
            cout << "\nPerson �Ҹ�\n"; 
            delete[] name; 
        }

        // �����Լ� show
        //  : �̰ɷ� person�� ��ӹ��� Ŭ������ �̸� override�ϸ� ȣ�� ����
        virtual void show() {
            cout << "\n\n�̸� : " << name; 
        }
};

// ��� class�� ��ӹ��� custom 
class Custom : public Person {

    private:
        char* phone;
        char* nationality;

    public:

        // Custom ������ 
        //  : 1��° parameter�� �̸����� ���� Person ������ �����ϰ�, ������ 2���� ��ȭ��ȣ�� ������ Custom ��ü�� char�迭�� �����Ҵ��� char�������� 2���� ������� phone, nationality�� ��ġ�� �ش��ϴ� ���� ������
        Custom(const char* pN, const char* pP, const char* pNa) : Person(pN) {

            phone = new char[strlen(pP) + 1];
            strcpy(phone, pP);

            nationality = new char[strlen(pNa) + 1];
            strcpy(nationality, pNa);

            cout << "\nCustom ����";
        }

        ~Custom() {
            cout << "\nCustom �Ҹ�"; 
            delete[] phone, nationality; 
        }

        // �θ�class ����Լ� override �� 
        void show() {
            Person::show(); 
            cout << "\n��ȣ : " << phone << "\n�ּ� : " << nationality << endl; 
        }
};

int main() {

    Person* c1 = new Custom("michelin", "010-1234-5678", "South Korea");
    c1->show();

    delete c1;

    return 0;
}