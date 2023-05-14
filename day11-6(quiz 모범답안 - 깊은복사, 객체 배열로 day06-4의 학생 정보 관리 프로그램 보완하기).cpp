// [������]
// quiz : ��ü �迭, ��ü ������, ��ü ������ ����� ������ �Լ��� �̿�
//  -> �л��� �̸�, ��ȭ��ȣ�� ����� ������ �ִ� Telephone Ŭ������ �ش��ϴ� ����� �����ϴ� �ڵ带 �ϼ� + 5���� �л� ��ü�� �����ϴ� ���� ���α׷��� �ۼ�
#include <conio.h>
#include <iostream>

using namespace std;

class Telephone {

    private:
        char name[20], phone[20];

    public:
        Telephone(char* pN, char* pP);
        void Show() const;
};

Telephone::Telephone(char* pN, char* pP) {
    strcpy_s(name, strlen(pN) + 1, pN);
    strcpy_s(phone, strlen(pN) + 1, pP);
}

void Telephone::Show() const {
    cout << "�̸� : " << name << "\t��ȭ��ȣ : " << phone << endl;
}

int main() {

    //��ü ������ �迭
    Telephone* pT[5]; 

    //�����͸� - pT[0], pT[1], pT[2], pT[3], pT[4]
    char name[20], phone[20];
    cout << "\n ** ��ȭ��ȣ �Է� ** \n";

    for (int i = 0; i < 5; i++) {
        cout << "\n��    �� : ";
        cin >> name;
        cout << "��ȭ��ȣ : ";
        cin >> phone;
        pT[i] = new Telephone(name, phone); //������ü ���� �� �μ� ����
    }

    cout << "\n\n\t** ��ȭ��ȣ ���**\n\n";

    for (int i = 0; i < 5; i++) {

        //��ü�ּ�->��� (��ü.���)
        pT[i]->Show();
    }
        
    cout << endl << endl;

    // [] - �����Ͱ� ����Ű�� �޸𸮰� �迭�� ���
    for (int i = 0; i < 5; i++) {  

        //delete ������;
        delete /*[]*/ pT[i];   
        cout << "���� �޸� ����\n";
    }
    return 0;
}
