//   # this�����͸� Ȱ���ϱ� ��ȿ�� ���
//      1. ����Լ��� parameter�� ��������� �̸��� ���� ���
//          ex) class B {
//                 int i, j;
//                 void Set(int i, int j) {      <- ���� ��������� parameter�� �̸��� i , j�� ����
//                    this->i = i;               <- this->i ��� ������ �� �� ������ ���� �ذ� ����
//                    this->j = j; 
//                 }

//      2. ����Լ����� �Լ��� ȣ���� ��ü�� �� ��ü�� ��ȯ�ϴ� ���
//          -> ��.. �̰� �� ��ü�� ���� ���� ��� �˾�? ��� ���ϰ�
//             -> �ش� Ŭ���� �����ͺ��� �������� ��ü�� �ּҰ��� �޴� this�� �������� ��ü�� *this�� return�ϸ� ��! 

// this�����͸� Ȱ���ϱ� ��ȿ�� ��� 1���� ����
#include <iostream>
#include <iomanip>// setw

using namespace std;

class Telephone {

    private:
        int no;
        char name[20];
        char phone[20];

    public:

        Telephone() : no(0), name(""), phone("") {}

        Telephone(int no, const char* const name, const char* const phone) {

            this->no = no;

            strcpy_s(this->name, 20, name);
            strcpy_s(this->phone, 20, phone);

            cout << "Constructor complete" << endl;
        }

        int GetNo() const { 
            return this->no; 
        }

        const char* GetName() const {
            return this->name; 
        }

        const char* GetPhone() const {
            return this->phone; 
        }
};

int main() {
    char name[20], ph[20];
    cout << "** ��ȭ��ȣ�� **\n \n";
    cout << "��    �� : ";
    cin >> name;

    cout << "��ȭ��ȣ : ";
    cin >> ph;

    //��ü ������, ������ �Լ� ��� ���� parameter ����   
    Telephone p(1, name, ph);    

    cout << " \n \n \t** ������ **\n \n";
    cout << std::left << setw(5) << "No." << setw(20) << "�̸�" << setw(20) << "��ȭ��ȣ" << endl;
    cout << setw(5) << p.GetNo() << setw(20) << p.GetName() << setw(20) << p.GetPhone() << endl;

    return 0;
}

