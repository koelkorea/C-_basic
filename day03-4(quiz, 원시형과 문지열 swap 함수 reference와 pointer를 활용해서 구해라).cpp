// �츮�� poiner�� �ƴ϶� reference�� ��� �ϴ� ����?
//  : reference ������ �� ��ü�� ���°� �Ǵ� ���� ������ �ּҰ����� ������ �ִ� �������� ����
// 
//    -> ����1)  �Լ� ����ÿ� parameter�� reference������ Ÿ������ �����ϴ� ���, ������ �����Ҷ� �� ���� call by reference �������� �ּҰ��� �����ϴ� �� �� ��ü�� �ѱ�� ��
//               (= ������ ������ �������� �ʱ⿡, call by reference��� ������ ����ϸ� �ٸ� �������� ���� ����ϰ� ���� �Լ� ������ �����ϴ�!..)
//                   -> (�߿�!) �ش� �Լ��� �޴� param�� reference ��������, ȣ���Ҷ� �����ϴ� param�� ����ϰ� �Ϲ� ������ �ص� �����ϴ�.. 
//                             (= ���� ����, ���� �ٸ� reference ������ ����� ���� ���ص� �ȴ� �̸��̴�..)        
// 
//       ����2) �����͸� ���� ������ ������ ���� �޸𸮰����� �����Ӱ� Ȱ������ = ���� ����� ȥ���� �߱�..
//              (= ������ Ư�� ������ ��ġ������ �ǹ��ϴ� reference������ �׾��� ����ٵ� �� �ּҿ��� �ٸ� �ּҸ� ������ ����)

//   # (�߿�) reference ������ ����
//     : ������ ������ �Ұ�����, �迭�̳� ���ڿ� ���� �ʿ������� �޸� ������ �������� ���� �ڷ����� �ٷ��� ������

// quiz 
// 1. ����, ����, �Ǽ� ���� swap�ϴ� �Լ� reference�� ����...
// 2. ���ڿ� swap�ϴ� �Լ� pointer ������� ����...
#include <iostream>
#include <iomanip>
using namespace std;

// --------------------reference ������ parameter�� �޴� �Լ�----------------------
//  -> �� ���� ȣ��� �ѱ� parameter�� call by reference �������� �۵��Ͽ� �������� ������ ��ġ�� ���°� ��

// int swap
void swap(int& p1, double& p2) {
    int tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

// char swap
void swap(char& p1, char& p2) {
    char tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

// double swap
void swap(double& p1, double& p2) {
    double tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

// --------------------pointer ������ parameter�� �޴� �Լ�----------------------

// char�迭(= ���ڿ�) swap
void swap(char* p1, char* p2) {

    // �� ���ڿ��� ���� �������� ������ ���� ��� NULL�̸� �� ��ȯ�� �����
    while (*p1 != NULL || *p2 != NULL) {

        char tmp;
        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;

        p1++;
        p2++;
    }

}

int main() {

    int int1, int2 = 0;
    char char1, char2 = 0;
    double double1, double2 = 0.0;
    char char_array1[50], char_array2[50] = { 0 };

    cout << "int�� 2���� �Է��ض� : ";
    cin >> int1 >> int2;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
    }

    cout << "char�� 2���� �Է��ض� : ";
    cin >> char1 >> char2;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
    }

    cout << "double�� 2���� �Է��ض� : ";
    cin >> double1 >> double2;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
    }

    cin.ignore(sizeof(double2), '\n');

    cout << "���ڿ� char_array1 �Է�(50�� ����) : " ;
    cin.getline(char_array1, 50);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(50, '\n');
    }

    cout << "���ڿ� char_array2 �Է�(50�� ����) : " ;
    cin.getline(char_array2, 50);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(50, '\n');
    }

    cout << endl <<  "--------------------------[������ ����]-------------------------" << endl;
    cout << "int1 = " << int1 << " , int2 = " << int2 << endl;
    cout << "char1 = " << char1 << " , char2 = " << char2 << endl;
    cout << "double1 = " << double1 << " , double2 = " << double2 << endl;
    cout << "char_array1 = " << char_array1 << endl;
    cout << "char_array2 = " << char_array2 << endl << endl;

    swap(int1, int2);
    swap(char1, char2);
    swap(double1, double2);
    swap(char_array1, char_array2);

    cout << "--------------------------[swap ����� ����]-------------------------" << endl;
    cout << "int1 = " << int1 << " , int2 = " << int2 << endl;
    cout << "char1 = " << char1 << " , char2 = " << char2 << endl;
    cout << "double1 = " << double1 << " , double2 = " << double2 << endl;
    cout << "char_array1 = " << char_array1 << endl;
    cout << "char_array2 = " << char_array2 << endl << endl;

    return 0;
}
