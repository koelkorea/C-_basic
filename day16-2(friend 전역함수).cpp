/* friend �����Լ�
�����Լ��� friend�� ������ Ŭ������ private��������� ���� ����
��ü���⿡ ����Ǳ� ������ ������ ������� �ʴ� ���� ��Ģ�̴�.
Ư���� ��쿡 �����Լ��� �ڽ��� ����Լ�ó�� �ʿ��� �� �����Ѵ�.
*/
#include <iostream>
using namespace std;
class Date; //OutToday�Լ����� DateŬ������ ����ϱ� ������ DateŬ���� ����
class Time {
	private:
		int hour, min, sec;
		friend void outToday(Date& d, Time& t);  //������ �Լ�, Data�� Ŭ������ �ν��ϱ� ���� ����
	public:
		Time(int hour = 0, int min = 0, int sec = 0) : hour(hour), min(min), sec(sec) {}
};
class Date {
	private:
		int year, month, day;
		friend void outToday(Date& d, Time& t);  //������ �Լ�
	public:
		Date(int year, int month, int day) : year(year), month(month), day(day) {}
};
void outToday(Date& d, Time& t)
{ //�����Լ�, Time class private : int hour, min, sec; & Date class private: int year, month, day; ���� ����
	cout << "������ " << d.year << "/" << d.month << "/" << d.day << ", " << t.hour << ":" << t.min << ":" << t.sec << endl;
}
int main() {
	Date d(2023, 02, 14); // Date ��ü ����
	Time t(10, 30, 28); // Time ��ü ����
	outToday(d, t); // ���� �Լ� ȣ��
	return 0;
}
