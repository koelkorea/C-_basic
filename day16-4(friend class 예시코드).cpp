//   # friend ��� ��� ���� ���ٹ���
//      : �׳� friend �ɸ� ����� ȣ��ǰų� ����� �� friend �������� class ���θ� public �������� ������ �ٴѴٷ� �����ϸ� ��

//      3. class�� �ش��ϴ� ����� friend�� �����Ͽ� ����ϴ� ��� 
//         : friend�� ����� class�� ��ü�� friend�� ������ Ŭ������ private��������� ���� ����


// day16-2�� friend Ŭ���� ver�� ����
#include <iostream>
using namespace std;

class Time {

    private:
        int hour, min, sec;

    public:
        Time(int h, int m, int s) : hour(h), min(m), sec(s) {}

        // (�߿�) Date class�� Time class�� friend�� ���� (= ������ Date class ��ü�� TimeŬ������ private ����� ����� ���� ����)
        friend class Date; 
};

class Date {

    private:
        int year, month, day;

    public:
        Date(int y, int m, int d) : year(y), month(m), day(d) {}
        void OutToday(Time& t);
};

// �̹� Date class�� Time class�� friend�� ����Ǽ�, ����Լ��� TimeŬ������ private ����� ����� ���� ���� 
void Date::OutToday(Time& t) {
    cout << "���� ��¥�� " << year << "/" << month << "/" << day << "\n";
    cout << "���� �ð��� " << t.hour << ":" << t.min << ":" << t.sec << endl;
}

int main() {

    Date D(2023, 2, 14);
    Time T(10, 40, 15);

    D.OutToday(T);

    return 0;
}
