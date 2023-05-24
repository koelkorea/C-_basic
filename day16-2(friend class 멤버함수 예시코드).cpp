//   # friend ��� ��� ���� ���ٹ���
//      : �׳� friend �ɸ� ����� ȣ��ǰų� ����� �� friend �������� class ���θ� public �������� ������ �ٴѴٷ� �����ϸ� ��
// 
//      1. � class�� ����Լ��� �ش��ϴ� ��� Ư�� class�� friend�� �����Ͽ� ����ϴ� ���
//          : � class�� Ư�� ����Լ��� �ʿ��ϴٸ�..? 
//             -> �� ����Լ��� friend�� �����Ͽ�, ȣ��� �� �ش� class �ڽ��� private ������ ������ �� �ֵ���, ���� ��� ������ ����
// 
//            # friend ����Լ� �ڵ� �ۼ� ��ġ �� ����
//               (1) friend�� ������ ������ ����Լ��� ������ '�ܺ� class' ���� ��ġ
//               (2) �ش� ����Լ��� friend��� ������ '�ش� class'�� ��ġ
//               (3) friend ����Լ��� ���Ǻθ� �ܺη� ���� ��ġ�صΰ�, ������ �Է���
// 
//            # friend ����Լ� �ۼ��� ���� ������ �߿��� ����?            
//               1. ����� �Ǵ� class�� ����Լ��� ���� �����ؾ�, �ܺ� class���� friend�� �����Ҷ� �����Ϸ��� '�°� �׷��� ������?'��� error�� ���� ����..
//                   -> ������ ����ϱ� ���ؼ��� ���� ��ܿ� ������ �Ǿ�� �ϴ°Ͱ� �ٸ��� 1�� ����
//               
//               2. ���Ǻθ� ���� ���߿� �ƿ� �ܺο����� �ΰ� ���� ������ a, b�� ��Ȳ�� ȸ���ϰ� �����Ϸ����� ���� ��Ȯ�ϰ� �ڵ��� ������ �����ϱ� ���� 
//                   -> a. �� class�� ������ ���� ���� ���ɼ��� ������, �̸� Ư�� class�� ������ ���� ���ɼ� ����
//                      b. �Դٰ� friend ��� ����, friend ���� �ܰ�� ��ĥ���� �ִ� ��Ȳ�̶� �����Ϸ� ���忡�� ���� ��Ȳ�ľ��� ����� �ϱ� ��ٷο��� error�� ���� ���ɼ� ����


// Ư�� class�� ����Լ��� ��� class�� friend ����Լ��� �����Ͽ� ������ ����ϴ� ����
#include <iostream>

// cout ��ü�� ��� std namespace ���� ���ڴٴ� ����
using std::cout;

// Date class�� ����Լ��� OutToday()�Լ����� Time Ŭ������ ����ϱ� ������ ���� ���� 
//  -> �� �׷���, ������ �������� Time�� ������� ���� �ڷ����̶� �����ϰ� error�� ����
class Time;

// (1) friend ����� ����Լ��� ������ class ���� ���� ���� �־�� ��
//   -> ����ϱ� ���� ���� �����ؾ� �ϴ°� ���� ��ġ
class Date {

    private:
        int year, month, day;

    public:
        Date(int y, int m, int d) : year(y), month(m), day(d) {}

        // (�߿�!) friend�� ������ ������ Date�� ����Լ� OutToday�� ���� (����θ� �ְ�, ���Ǻδ� ���ٴ°� �߿���)
        //   -> �� �κ��� parameter�� Time�� class�� �ν��ϰ� �ϱ� ���� �κ�
        //       -> ���Ǻθ� ���� �ʴ� ����? ���� Time class�� �������� ����� ������ �� �Ǿ� ���� 
        void OutToday(Time& t);
};

// (2) friend ����Լ��� friend��� ������ Ŭ����
class Time {

    private:
        int hour, min, sec;

        // (�߿�!) DateŬ������ OutToday�Լ��� friend��� ������ �� TimeŬ������ private����� ������ �� ����
        //   -> friend �Լ��� Time �� class�� �Լ��� �ƴϴ�.. �翬�� ���Ǻα��� �����ָ� �� ��!
        friend void Date::OutToday(Time& t);

    public:
        Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
};

// (3) class Time�� friend ����Լ��� Data class�� ����Լ� OutToday()�� ������ �ܺο��� ������ ���Ǻθ� ������
//       -> Date class�� ����Լ� OutToday()�� Time class�� friend
//           -> (�߿�!) ���� ȣ��� Time class private : int hour, min, sec;���� ���� ����
void Date::OutToday(Time& t) {
    //t.hour = 15; t.min = 24; t.sec = 45;
    cout << "������ " << year << "�� " << month << "�� " << day << "���̸�\n";
    cout << "���� �ð��� " << t.hour << ":" << t.min << ":" << t.sec << "�Դϴ�.\n";
}

int main() {

    Date D(2023, 2, 14);
    Time T(10, 35, 27);

    // friend�̱⿡ private�� Time class�� �Ķ���ͷ� ����Ͽ� ���� ȣ�� ����
    D.OutToday(T);
    return 0;
}