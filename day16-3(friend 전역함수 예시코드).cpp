//   # friend 사용 대상에 따른 접근범위
//      : 그냥 friend 걸린 대상은 호출되거나 선언될 시 friend 선언해준 class 내부를 public 영역마냥 휘젓고 다닌다로 이해하면 됨

//      2. 전역함수에 해당하는 대상을 friend로 규정하여 사용하는 경우 
//          : 전역함수의 경우 호출시 friend로 선언한 class의 private 멤버영역까지도 접근 가능
//             -> 전역함수를 friend 선언한 class 자신의 멤버함수처럼 접근해야 할 필요성이 있을 때 사용함
//                 -> 근데 이렇게 쓰는건 객체지향에 위배되기 때문에 가급적 사용하지 않는 것이 원칙
//                    (= 그럴바에는 걍 class부터 설계할 때 해당 함수를 포함해라..) 


// 특정 class의 멤버함수를 대상 class의 friend 멤버함수로 규정하여 연계해 사용하는 예시인 day16-2를 friend 전역함수 ver로 변경
#include <iostream>

using namespace std;

// 전역함수 OutToday 함수에서 Date클래스를 parameter로 사용하기 때문에 Date클래스 미리 선언 (안 하면, 미 선언된 함수로 간주해서 error 뿜뿜)
class Date; 

class Time {

	private:
		int hour, min, sec;

		// 전역함수인 outToday()는 호출 시 Time class의 private영역도 마음대로 가져다가 사용 가능
		friend void outToday(Date& d, Time& t);

	public:
		Time(int hour = 0, int min = 0, int sec = 0) : hour(hour), min(min), sec(sec) {}

};

class Date {
	private:
		int year, month, day;

		// 전역함수인 outToday()는 호출 시 Date class의 private영역도 마음대로 가져다가 사용 가능
		friend void outToday(Date& d, Time& t); 

	public:
		Date(int year, int month, int day) : year(year), month(month), day(day) {}
};

// 전역함수 outToday()는 Data, Time의 friend
//  -> (중요!) 따라서 호출시 Time class private : int hour, min, sec; & Date class private: int year, month, day; 접근 가능
void outToday(Date& d, Time& t){ 
	cout << "오늘은 " << d.year << "/" << d.month << "/" << d.day << ", " << t.hour << ":" << t.min << ":" << t.sec << endl;
}

int main() {

	Date d(2023, 02, 14); // Date 객체 생성
	Time t(10, 30, 28);   // Time 객체 생성

	// 전역함수 outToday()를 parameter인 Date 객체와, Time 객체와 함께 호출
	outToday(d, t); 
	return 0;
}
