/*
    friend 클래스
    - friend로 선언된 클래스는 friend를 선언한 클래스의 private멤버까지도 접근 가능하다.
*/
#include <iostream>
using namespace std;
class Time {
private:
    int hour, min, sec;
public:
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
    friend class Date; //friend 클래스(Date클래스는 Time클래스의 private멤버에 접근 가능)
};
class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void OutToday(Time& t);
};
void Date::OutToday(Time& t) {
    cout << "오늘 날짜는 " << year << "/" << month << "/" << day << "\n";
    cout << "지금 시간은 " << t.hour << ":" << t.min << ":" << t.sec << endl;
}
int main() {
    Date D(2023, 2, 14);
    Time T(10, 40, 15);
    D.OutToday(T);
    return 0;
}
