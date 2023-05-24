// quiz2 - friend 예약어, 연산자 오버로딩을 활용한 Time class 작성하고 다음 조건에 맞는 연산자함수를 채워라
// 1. Time 객체 : 시, 분, 초 구성에 초와 분은 반올림 되어야 함 (시는 총량을 나타낼 용도)
// 2. Time class 내부 멤버함수 show()       => 어떤 Time 객체의 데이터를 console에 출력하는 Time 클래스 멤버함수
// 3. Time 객체 + int 변수                  => 어떤 Time 객체에 변수만큼을 초로 더함
// 4. Time 객체 + Time 객체                 => 어떤 Time 객체의 시, 분, 초에 다른 Time 객체의 요소를 더해줌
// 5. Time 객체 - Time 객체                 => 어떤 Time 객체의 시, 분, 초에 다른 Time 객체의 요소를 빼줌
// 6. Time 객체 * double 변수               => 어떤 Time 객체에 변수만큼을 곱한 뒤, 총량으로 환산
// 7. double 변수 * Time 객체               => 어떤 Time 객체에 변수만큼을 곱한 뒤, 총량으로 환산하지만, 1번째 연산대상의 자료형이 원시 자료형 double인 함수
// 8. 출력 클래스 ostream 객체 << Time 객체  => 어떤 ostream 객체에 비트연산자 <<를 사용하여 Time 객체를 2번쨰 연산대상으로 놓으면, 그에 대한 데이터를 console에 출력하는 함수

#include <iostream>
#include <time.h>    // time() : 1초 단위 반환

using namespace std;

// 1. Time 객체 : 멤버변수 - 시, 분, 초 (초와 분은 반올림 되어야 함)
class Time {
	private:
		int hours;
		int minutes;
		int seconds;

	public:
		Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {

		}

		// 2. Time class 내부 멤버함수 show() 
        //     -> 어떤 Time 객체의 데이터를 console에 출력하는 Time 클래스 멤버함수  
		//         -> 엄연히 Time 클래스가 주체가 되는 멤버함수
		//             -> (중요!) 따라서, 작동구조는 ostream 클래스의 멤버 <<연산자 함수를 쓰지만, 이미 존재하는 선언부(int를 이용한 ostream객체와의 비트연산자 <<)를 사용함
		void show() const {
			cout << hours << " 시 " << minutes << " 분 " << seconds << " 초 ";
		}

		// 3. Time 객체 + int 변수                  
		//     -> 어떤 Time 객체에 변수만큼을 바로 초로 더해서 원본의 Time 레퍼런스 변수를 출력하게 함 (= 원본이 바로 변함)
		Time& operator+(const int s) {

			// 해당 time 객체에 바로 더해줌
			this->seconds = this->seconds + s;

			// 더하고 난 뒤, 초와 분은 60을 기준으로 반올림 되어야 함 (시는 총량을 나타낼 용도라 그러지 않아도 됨)
			if (this->seconds >= 60) {
				this->seconds -= 60;
				this->minutes = this->minutes + 1;
			}

			if (this->minutes >= 60) {
				this->minutes -= 60;
				this->hours = this->hours + 1;
			}

			//if (this->hours >= 24) {
			//	this->hours -= 24;
			//}

			return *this;
		}

		// 4. Time 객체 + Time 객체 (const 함수라 Time 객체의 맴버를 직접 바꾸지 못하게 됨)
		//     -> 어떤 Time 객체의 시, 분, 초에 다른 Time 객체의 요소를 더해준 다른 Time 객체로 리턴 (= 원본은 안 변함)
		Time operator+(const Time& t) const {

			Time time;

			// 원본과는 아예 다른 객체를 만들어서 거기에 기존 Time 객체의 값을 더해줌
			time.seconds = this->seconds + t.seconds;
			time.minutes = this->minutes + t.minutes;
			time.hours = this->hours + t.hours;

			// 더하고 난 뒤, 초와 분은 60을 기준으로 반올림 되어야 함 (시는 총량을 나타낼 용도라 그러지 않아도 됨)
			if (time.seconds >= 60) {
				time.seconds -= 60;
				time.minutes = this->minutes + 1;
			}

			if (time.minutes >= 60) {
				time.minutes -= 60;
				time.hours = this->hours + 1;
			}

			//if (time.hours >= 24) {
			//	time.hours -= 24;
			//}


			return time;
		}

		// 5. Time 객체 - Time 객체 (const 함수라 Time 객체의 맴버를 직접 바꾸지 못하게 됨)
		//     -> 어떤 Time 객체의 시, 분, 초에 다른 Time 객체의 요소를 빼준 다른 Time 객체로 리턴 (= 원본은 안 변함)
		Time operator-(const Time& t) const {

			Time time;

			// 원본과는 아예 다른 객체를 만들어서 거기에 기존 Time 객체의 값을 빼줌
			time.hours = this->hours - t.hours;
			time.minutes = this->minutes - t.minutes;
			time.seconds = this->seconds - t.seconds;

			// 더하고 난 뒤, 초와 분은 0을 기준으로 반올림 되어야 함 (시는 총량을 나타낼 용도라 최소값 0을 기준으로 두기)
			if (time.seconds <= 0) {
				time.seconds += 60;
				time.minutes = this->minutes - 1;
			}

			if (time.minutes <= 0) {
				time.minutes += 60;
				time.hours = this->hours - 1;
			}

			if (time.hours <= 0) {
				time.hours = 0;
			}

			return time;
		}

		// 6. Time 객체 * double 변수              
		//     -> 어떤 Time 객체에 변수만큼을 곱한 뒤, 총량으로 환산
		Time operator*(double m) {

			Time time;

			// 원본과는 아예 다른 객체를 만들어서 거기에 실수 m의 값을 곱해줌
			time.hours = (int)(this->hours * m);
			time.minutes = (int)(this->minutes * m);
			time.seconds = (int)(this->seconds * m);

			// 곱하고 난 뒤, 초와 분은 0을 기준으로 반올림 되어야 함 (시는 총량을 나타낼 용도라 최소값 0을 기준으로 두기)
			if (time.seconds >= 60) {
				time.minutes = this->minutes + time.seconds / 60;
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

		// 7. double 변수 * Time 객체              
		//     -> 어떤 Time 객체에 변수만큼을 곱한 뒤, 총량으로 환산하지만, 1번째 연산대상의 자료형이 원시 자료형 double인 함수
		//         -> 어떤 객체나 변수가 될 수 없는 상수가 1번째 연산대상으로 연산에 들어가는 경우 =  class 멤버 연산자 함수로 사용할수 없는 상황
		//             -> friend 전역함수로 둬서, 실수와 Time 클래스 객체를 차례로 parameter(= 연산대상)으로 받으면 그 요소에 접근하여 3번의 *연산자를 실행하게 조정
		friend Time operator*(double m, const Time& t);

		// 8. 출력 클래스 ostream 객체 << Time 객체
		//     -> 어떤 ostream 객체에 비트연산자 <<를 사용하여 Time 객체를 2번쨰 연산대상으로 놓으면, 그에 대한 데이터를 console에 출력하도록 원본의 ostream 레퍼런스 변수를 출력하게 함 (= 원본 ostream 객체 내용이 바로 변함)
		//         -> 본래부터 있었던 class 내부의 연산자함수를 오버로딩 해야 하는 경우 = class 멤버 연산자 함수로 사용할수 없는 상황
		//             -> friend 전역함수로 둬서, ostream 클래스 객체와 Time 클래스 객체를 차례로 parameter(= 연산대상)으로 받으면, Time 클래스 객체의 요소를 ostream 클래스 객체애서 비트연산자를 활용한 출력기능을 어떻게 작동시켜야 하는지 정의부에 쓰자
		friend ostream& operator<<(ostream& os, const Time& t);
};

// 7. double 변수 * Time 객체 정의부
Time operator*(double m, const Time& t) {

	Time time = t;
	return time * m;
}

// 8. 출력 클래스 ostream 객체 << Time 객체 정의부
ostream& operator<<(ostream& os, const Time& t) {

	// ostream클래스 객체가 Time class 객체를 활용해서 어떤 식으로 비트 <<연산을 수행해야 하는지 정의부를 작성 
	os << t.hours << " 시 " << t.minutes << " 분 " << t.seconds << " 초 ";

	// 그 결과값을 ostream클래스 객체의 레버런스 변수로 반환
	return os;
}

int main() {

	Time timer(12, 2, 50);
	Time wakeup(7, 20, 50);
	Time goWorkspace(9, 0, 40);
	Time goWorkOut(18, 11, 38);
	Time sleep(23, 30, 11);

	int before = 0, after = 0;

	// timer의 시간은 1초마다 갱신되게 작성해야 함
	//  -> time(int) : 19xx년부터 지금까지의 시간을 초미만의 단위로 환산한 값을 정수로 반환
	while (1) {

		before = time(0);

		// before와 after가 다른게 보이면, after를 갱신함 (before은 while구문과 time()으로 인해, 계속 변경됨) + timer에 1추가
		if (before != after) {

			system("cls");
			after = before;
			cout << "현재시간 : " << timer << endl;
			timer + 1;

			cout << "기상 : " << wakeup << endl;
			cout << "출근 : " << goWorkspace << "    근무 시간 : " << goWorkOut - goWorkspace << endl;
			cout << "퇴근 : " << goWorkOut << "   4.5일 근무 : " << (goWorkOut - goWorkspace) * 4.5 << endl;
			cout << "취침 : " << sleep << endl;
		}

	}
	return 0;
}