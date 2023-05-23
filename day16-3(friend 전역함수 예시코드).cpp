//   # friend ��� ��� ���� ���ٹ���
//      : �׳� friend �ɸ� ����� ȣ��ǰų� ����� �� friend �������� class ���θ� public �������� ������ �ٴѴٷ� �����ϸ� ��

//      2. �����Լ��� �ش��ϴ� ����� friend�� �����Ͽ� ����ϴ� ��� 
//          : �����Լ��� ��� ȣ��� friend�� ������ class�� private ������������� ���� ����
//             -> �����Լ��� friend ������ class �ڽ��� ����Լ�ó�� �����ؾ� �� �ʿ伺�� ���� �� �����
//                 -> �ٵ� �̷��� ���°� ��ü���⿡ ����Ǳ� ������ ������ ������� �ʴ� ���� ��Ģ
//                    (= �׷��ٿ��� �� class���� ������ �� �ش� �Լ��� �����ض�..) 


// Ư�� class�� ����Լ��� ��� class�� friend ����Լ��� �����Ͽ� ������ ����ϴ� ������ day16-2�� friend �����Լ� ver�� ����
#include <iostream>

using namespace std;

// �����Լ� OutToday �Լ����� DateŬ������ parameter�� ����ϱ� ������ DateŬ���� �̸� ���� (�� �ϸ�, �� ����� �Լ��� �����ؼ� error �ջ�)
class Date; 

class Time {

	private:
		int hour, min, sec;

		// �����Լ��� outToday()�� ȣ�� �� Time class�� private������ ������� �����ٰ� ��� ����
		friend void outToday(Date& d, Time& t);

	public:
		Time(int hour = 0, int min = 0, int sec = 0) : hour(hour), min(min), sec(sec) {}

};

class Date {
	private:
		int year, month, day;

		// �����Լ��� outToday()�� ȣ�� �� Date class�� private������ ������� �����ٰ� ��� ����
		friend void outToday(Date& d, Time& t); 

	public:
		Date(int year, int month, int day) : year(year), month(month), day(day) {}
};

// �����Լ� outToday()�� Data, Time�� friend
//  -> (�߿�!) ���� ȣ��� Time class private : int hour, min, sec; & Date class private: int year, month, day; ���� ����
void outToday(Date& d, Time& t){ 
	cout << "������ " << d.year << "/" << d.month << "/" << d.day << ", " << t.hour << ":" << t.min << ":" << t.sec << endl;
}

int main() {

	Date d(2023, 02, 14); // Date ��ü ����
	Time t(10, 30, 28);   // Time ��ü ����

	// �����Լ� outToday()�� parameter�� Date ��ü��, Time ��ü�� �Բ� ȣ��
	outToday(d, t); 
	return 0;
}
