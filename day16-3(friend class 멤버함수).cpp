/*  friend ����Լ�
  - Ŭ������ Ư�� ����Լ��� friend�� �����Ͽ� ���� ��� ������ ���δ�.
  - friend ����Լ��� ������ �߿��ϴ�.
    (1) friend ����� ����Լ��� ������ Ŭ����
    (2) friend ����Լ��� ������ Ŭ����
    (3) friend ����Լ� �ܺ� ����*/
#include <iostream>
using std::cout;
class Time; // ## OutToday�Լ����� Time Ŭ������ ����ϱ� ������ ����
class Date { //(1)friend ����� ����Լ��� ������ Ŭ����
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void OutToday(Time& t); // ##Time�� Ŭ������ �ν��ϱ� ���� ����
};
class Time { //(2) friend ����Լ��� ������ Ŭ����
private:
    int hour, min, sec;
    friend void Date::OutToday(Time& t);//DateŬ������ OutToday�Լ��� TimeŬ������ private����� ������ �� �ִ�.
public:
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
};
void Date::OutToday(Time& t) { //(3) friend ����Լ� �ܺ� ����
    //t.hour = 15; t.min = 24; t.sec = 45;
    cout << "������ " << year << "�� " << month << "�� " << day << "���̸�\n";
    cout << "���� �ð��� " << t.hour << ":" << t.min << ":" << t.sec << "�Դϴ�.\n";
}
int main() {
    Date D(2023, 2, 14);
    Time T(10, 35, 27);
    D.OutToday(T);
    return 0;
}
