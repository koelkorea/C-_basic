/* friend 전역함수
전역함수는 friend를 선언한 클래스의 private멤버까지도 접근 가능
객체지향에 위배되기 때문에 가급적 사용하지 않는 것이 원칙이다.
특별한 경우에 전역함수를 자신의 멤버함수처럼 필요할 때 선언한다.
*/
#include <iostream>
using namespace std;
class Date; //OutToday함수에서 Date클래스를 사용하기 때문에 Date클래스 선언
class Time {
	private:
		int hour, min, sec;
		friend void outToday(Date& d, Time& t);  //프렌드 함수, Data가 클래스로 인식하기 위해 선언
	public:
		Time(int hour = 0, int min = 0, int sec = 0) : hour(hour), min(min), sec(sec) {}
};
class Date {
	private:
		int year, month, day;
		friend void outToday(Date& d, Time& t);  //프렌드 함수
	public:
		Date(int year, int month, int day) : year(year), month(month), day(day) {}
};
void outToday(Date& d, Time& t)
{ //전역함수, Time class private : int hour, min, sec; & Date class private: int year, month, day; 접근 가능
	cout << "오늘은 " << d.year << "/" << d.month << "/" << d.day << ", " << t.hour << ":" << t.min << ":" << t.sec << endl;
}
int main() {
	Date d(2023, 02, 14); // Date 객체 생성
	Time t(10, 30, 28); // Time 객체 생성
	outToday(d, t); // 전역 함수 호출
	return 0;
}
