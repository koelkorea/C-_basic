//   # friend 사용 대상에 따른 접근범위
//      : 그냥 friend 걸린 대상은 호출되거나 선언될 시 friend 선언해준 class 내부를 public 영역마냥 휘젓고 다닌다로 이해하면 됨

//      3. class에 해당하는 대상을 friend로 규정하여 사용하는 경우 
//         : friend로 선언된 class의 객체도 friend를 선언한 클래스의 private멤버까지도 접근 가능


// day16-2를 friend 클래스 ver로 변경
#include <iostream>
using namespace std;

class Time {

    private:
        int hour, min, sec;

    public:
        Time(int h, int m, int s) : hour(h), min(m), sec(s) {}

        // (중요) Date class를 Time class의 friend로 선언 (= 앞으로 Date class 객체는 Time클래스의 private 멤버에 맘대로 접근 가능)
        friend class Date; 
};

class Date {

    private:
        int year, month, day;

    public:
        Date(int y, int m, int d) : year(y), month(m), day(d) {}
        void OutToday(Time& t);
};

// 이미 Date class는 Time class의 friend로 선언되서, 멤버함수도 Time클래스의 private 멤버에 맘대로 접근 가능 
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
