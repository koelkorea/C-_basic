// quiz2 - friend �����, ������ �����ε��� Ȱ���� Time class �ۼ�

#include <iostream>
#include <time.h>    // time() : 1�� ���� ��ȯ

using namespace std;

class Time {
	private:
		int hours;
		int minutes;
		int seconds;

	public:
		Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
		
		}

		void show() const {
			cout << hours << " �� " << minutes << " �� " << seconds << " �� ";
		}

		// ��ü + const ���� (= ���)
		Time& operator+(const int s) {

			this->seconds = this->seconds + s;

			if (this->seconds >= 60) {
				this->seconds -= 60;
				this->minutes = this->minutes + 1;
			}

			if (this->minutes >= 60) {
				this->minutes -= 60;
				this->hours = this->hours + 1;
			}

			if (this->hours >= 24) {
				this->hours -= 24;
			}
			
			return *this;
		}

		// ��ü + const ��ü
		Time operator+(const Time& t) const {

			Time time;

			time.seconds = this->seconds + t.seconds;
			time.minutes = this->minutes + t.minutes;
			time.hours   = this->hours   + t.hours;

			if (time.seconds >= 60) {
				time.seconds -= 60;
				time.minutes = this->minutes + 1;
			}

			if (time.minutes >= 60) {
				time.minutes -= 60;
				time.hours = this->hours + 1;
			}

			if (time.hours >= 24) {
				time.hours -= 24;
			}


			return time;
		}

		// ��ü - const ��ü
		Time operator-(const Time& t) const {

			Time time;

			time.hours   = this->hours   - t.hours;
			time.minutes = this->minutes - t.minutes;
			time.seconds = this->seconds - t.seconds;

			if (time.seconds <= 0) {
				time.seconds += 60;
				time.minutes = this->minutes - 1;
			}

			if (time.minutes <= 0) {
				time.minutes += 60;
				time.hours = this->hours - 1;
			}

			if (time.hours <= 0) {
				time.hours += 24;
			}

			return time;
		}

		// ��ü * �Ǽ�
		Time operator*(double m) {

			Time time;

			time.hours   = (int) (this->hours   * m);
			time.minutes = (int) (this->minutes * m);
			time.seconds = (int) (this->seconds * m);

			if (time.seconds >= 60) {
				time.minutes = this->minutes + time.seconds/60;
				time.seconds %= 60;
			}

			if (time.minutes >= 60) {
				time.hours = this->hours + time.minutes / 60;
				time.minutes %= 60;
			}

			//if (time.hours >= 24) {
			//	time.hours %= 24;
			//}

			return time;
		}

		// �Ǽ� * ��ü
		friend Time operator*(double m, const Time& t);

		// cout ���
		friend ostream& operator<<(ostream& os, const Time& t);
};

Time operator*(double m, const Time& t) {

	Time time = t;
	return time * m;
}


ostream& operator<<(ostream& os, const Time& t) {
	os << t.hours << " �� " << t.minutes << " �� " << t.seconds << " �� ";
	return os;
}

int main() {

	Time timer(12, 2, 50);
	Time wakeup(7, 20, 50);
	Time goWorkspace(9, 0, 40);
	Time goWorkOut(18, 11, 38);
	Time sleep(23, 30, 11);

	int tmp = 0, temp = 0;

	while (1) {

		tmp = time(0);

		if (tmp != temp) {

			system("cls");
			temp = tmp;
			cout << "����ð� : " << timer << endl;
			timer + 1;

			cout << "��� : " << wakeup << endl;
			cout << "��� : " << goWorkspace << "    �ٹ� �ð� : " << goWorkOut - goWorkspace << endl;
			cout << "��� : " << goWorkOut   << "   4.5�� �ٹ� : " << (goWorkOut - goWorkspace) * 4.5 << endl;
			cout << "��ħ : " << sleep << endl;
		}

		

	}
	return 0;
}