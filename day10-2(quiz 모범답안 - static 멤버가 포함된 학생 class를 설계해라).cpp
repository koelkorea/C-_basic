// [quiz ������]
// static �������, ����Լ��� ���Ե� student class�� �����ض�, ������ ������ ����
 
// 1. private�������
//     - �й�
//     - �̸�
//     - ����
//     - �л��� (static �������)

// 2. public ����Լ�
//     - student ������           : �й��� 20230000���� ���ʷ� 1�� ���� �ǵ��� ����
//     - (const) print_info()     : �л� ���� ���
//     - (static) print_std_cnt() : �л� �� ���

#include <iostream>
#include <iomanip>

using namespace std;

class Student {

    private:
        int no;
        char name[20];
        int age;
        static int studentNum;  //�л���(�����������)

    public:

        static int GetStudentNum(); //��������Լ�
        Student() : no(0), name(""), age(0) {} //initializer lists
        Student(const char* const name, int age) {
            this->no = 20230000 + studentNum;
            ++studentNum;
            strcpy_s(this->name, 20, name);
            this->age = age;
            cout << "������ �ʱ�ȭ\n";
        }
        int GetNo() const { return no; }
        const char* GetName() const { return name; }
        int GetAge() const { return age; }
        void print_info() const;
        void print_std_cnt() const;
        void SetName(const char* const name) { strcpy_s(this->name, 20, name); }
        void SetAge(int age) { this->age = age; }
};

int Student::studentNum = 0; //����������� �ʱ�ȭ

int Student::GetStudentNum() {
    return studentNum;
}

void Student::print_info() const {
    cout << std::left << std::setw(10) << "�й�" << std::setw(20) << "�̸�" << std::setw(5) << "����" << endl;
    cout << std::setw(10) << this->GetNo() << std::setw(20) << this->GetName() << std::setw(5) << this->GetAge() << endl << endl;
}

void Student::print_std_cnt() const {
    cout << "��ü �л� ���� " << Student::GetStudentNum() << "�� �Դϴ�.\n";
}

int main() {
    cout << "��ü �л� ���� " << Student::GetStudentNum() << "�� �Դϴ�.\n"; //��������� Ŭ���������� ���� ����
    Student st1("michelin", 20);              st1.print_std_cnt();
    Student st2("christopher", 21);           st1.print_std_cnt();
    Student st3("charlie puth", 22);          st1.print_std_cnt();

    st1.print_info();    st2.print_info();    st3.print_info();

    st1.SetName("bruno mars");    st2.SetAge(23);
    cout << "\n\n������ �����߽��ϴ�.\n";
    st1.print_info();
    st2.print_info();
    st3.print_info();
    return 0;
}

