//  - class�� ������� ���ȭ
//     : C++������ Ŭ������ ��������� ������ �� �ʱ�ȭ ���� �����ϴ°� ��ü�� ��� X�Ǵ� ������ ���� �߻�
//       (= ������ �Լ��� ���� class ��ü�� ���� �Ҵ�� ���ÿ� ���� �����Ϸ��� �غ���, �̹� ��ü�� �����Ǵ� �������� ���� ����� ��������� �����Ⱚ�� ������ �ʱ�ȭ�� ���Ĺ����� ��)
//          -> ������ ������ ���� ��ü�� ����� ���� ���� ����� �ʱ�ȭ�� ���� ������ �� �־�� �ϴ� ����� �ʿ���..
//              -> �ʱ�ȭ ����Ʈ(Initialize List)�� ����  ":" �ݷ��� ����� ������� �ʱ�ȭ���� �����ϴ� ����� ������ �Լ��� ���Ǻκ��� ���� ����ȴٴ� ���� �̿���
// 
//      # class�� ������� ���ȭ ����
// 	  
//           ex) class TMP{
//                  const int const_int;                <- �ʱ�ȭ �Ұ���
//                  TMP(int num) : const_int(num) { }

// class ������ �ڵ� ��� ���� �ڵ�
#include <iostream>
#include <cstring>

class Student {

    private:

        // const �⺭���� �����
        const int number;
        char name[20];
        int age;

    public:

        // [class �������� �ʱ�ȭ�Ϸ���, �Ϲ� �����ڷδ� �Ұ���]
        // Student(int Num, const char* pN, int a) {
        //     number = Num;
        //     strcpy_s(name, strlen(pN) + 1, pN);
        //     age = a;
        // }

        // �ʱ�ȭ ����Ʈ(Initialize List) ������� class ������ number�� :�����ڸ� ���� �����ϸ� ����
        Student(int Num, const char* pN, int a) : number(Num) {
            //number = Num;   <- ���� �� ������δ� ������ ���� �� ������ �Ұ���
            strcpy_s(name, strlen(pN) + 1, pN);
            age = a;
        }
};

int main() {

    Student s1(20221234, "michelin", 21);
    Student s2(20231234, "christopher", 20);

    return 0;
}
