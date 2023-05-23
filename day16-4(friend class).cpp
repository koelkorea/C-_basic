/*
    friend Ŭ����
    - friend�� ����� Ŭ������ friend�� ������ Ŭ������ private��������� ���� �����ϴ�.
*/
#include <iostream>
using namespace std;
class Time {
private:
    int hour, min, sec;
public:
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
    friend class Date; //friend Ŭ����(DateŬ������ TimeŬ������ private����� ���� ����)
};
class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void OutToday(Time& t);
};
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
