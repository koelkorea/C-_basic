/*  friend 멤버함수
  - 클래스의 특정 멤버함수만 friend로 선언하여 접근 허용 범위를 줄인다.
  - friend 멤버함수는 순서가 중요하다.
    (1) friend 선언될 멤버함수를 포함한 클래스
    (2) friend 멤버함수를 선언할 클래스
    (3) friend 멤버함수 외부 정의*/
#include <iostream>
using std::cout;
class Time; // ## OutToday함수에서 Time 클래스를 사용하기 때문에 선언
class Date { //(1)friend 선언될 멤버함수를 포함한 클래스
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void OutToday(Time& t); // ##Time을 클래스로 인식하기 위해 선언
};
class Time { //(2) friend 멤버함수를 선언할 클래스
private:
    int hour, min, sec;
    friend void Date::OutToday(Time& t);//Date클래스의 OutToday함수만 Time클래스의 private멤버에 접근할 수 있다.
public:
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
};
void Date::OutToday(Time& t) { //(3) friend 멤버함수 외부 정의
    //t.hour = 15; t.min = 24; t.sec = 45;
    cout << "오늘은 " << year << "년 " << month << "월 " << day << "일이며\n";
    cout << "지금 시간은 " << t.hour << ":" << t.min << ":" << t.sec << "입니다.\n";
}
int main() {
    Date D(2023, 2, 14);
    Time T(10, 35, 27);
    D.OutToday(T);
    return 0;
}
