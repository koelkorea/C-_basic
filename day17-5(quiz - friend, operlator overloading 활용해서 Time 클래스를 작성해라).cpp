// quiz2 - friend �����, ������ �����ε��� Ȱ���� Time class �ۼ��ϰ� ���� ���ǿ� �´� �������Լ��� ä����
// 1. Time ��ü : ��, ��, �� ������ �ʿ� ���� �ݿø� �Ǿ�� �� (�ô� �ѷ��� ��Ÿ�� �뵵)
// 2. Time class ���� ����Լ� show()       => � Time ��ü�� �����͸� console�� ����ϴ� Time Ŭ���� ����Լ�
// 3. Time ��ü + int ����                  => � Time ��ü�� ������ŭ�� �ʷ� ����
// 4. Time ��ü + Time ��ü                 => � Time ��ü�� ��, ��, �ʿ� �ٸ� Time ��ü�� ��Ҹ� ������
// 5. Time ��ü - Time ��ü                 => � Time ��ü�� ��, ��, �ʿ� �ٸ� Time ��ü�� ��Ҹ� ����
// 6. Time ��ü * double ����               => � Time ��ü�� ������ŭ�� ���� ��, �ѷ����� ȯ��
// 7. double ���� * Time ��ü               => � Time ��ü�� ������ŭ�� ���� ��, �ѷ����� ȯ��������, 1��° �������� �ڷ����� ���� �ڷ��� double�� �Լ�
// 8. ��� Ŭ���� ostream ��ü << Time ��ü  => � ostream ��ü�� ��Ʈ������ <<�� ����Ͽ� Time ��ü�� 2���� ���������� ������, �׿� ���� �����͸� console�� ����ϴ� �Լ�

#include <iostream>
#include <time.h>    // time() : 1�� ���� ��ȯ

using namespace std;

// 1. Time ��ü : ������� - ��, ��, �� (�ʿ� ���� �ݿø� �Ǿ�� ��)
class Time {
	private:
		int hours;
		int minutes;
		int seconds;

	public:
		Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {

		}

		// 2. Time class ���� ����Լ� show() 
        //     -> � Time ��ü�� �����͸� console�� ����ϴ� Time Ŭ���� ����Լ�  
		//         -> ������ Time Ŭ������ ��ü�� �Ǵ� ����Լ�
		//             -> (�߿�!) ����, �۵������� ostream Ŭ������ ��� <<������ �Լ��� ������, �̹� �����ϴ� �����(int�� �̿��� ostream��ü���� ��Ʈ������ <<)�� �����
		void show() const {
			cout << hours << " �� " << minutes << " �� " << seconds << " �� ";
		}

		// 3. Time ��ü + int ����                  
		//     -> � Time ��ü�� ������ŭ�� �ٷ� �ʷ� ���ؼ� ������ Time ���۷��� ������ ����ϰ� �� (= ������ �ٷ� ����)
		Time& operator+(const int s) {

			// �ش� time ��ü�� �ٷ� ������
			this->seconds = this->seconds + s;

			// ���ϰ� �� ��, �ʿ� ���� 60�� �������� �ݿø� �Ǿ�� �� (�ô� �ѷ��� ��Ÿ�� �뵵�� �׷��� �ʾƵ� ��)
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

		// 4. Time ��ü + Time ��ü (const �Լ��� Time ��ü�� �ɹ��� ���� �ٲ��� ���ϰ� ��)
		//     -> � Time ��ü�� ��, ��, �ʿ� �ٸ� Time ��ü�� ��Ҹ� ������ �ٸ� Time ��ü�� ���� (= ������ �� ����)
		Time operator+(const Time& t) const {

			Time time;

			// �������� �ƿ� �ٸ� ��ü�� ���� �ű⿡ ���� Time ��ü�� ���� ������
			time.seconds = this->seconds + t.seconds;
			time.minutes = this->minutes + t.minutes;
			time.hours = this->hours + t.hours;

			// ���ϰ� �� ��, �ʿ� ���� 60�� �������� �ݿø� �Ǿ�� �� (�ô� �ѷ��� ��Ÿ�� �뵵�� �׷��� �ʾƵ� ��)
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

		// 5. Time ��ü - Time ��ü (const �Լ��� Time ��ü�� �ɹ��� ���� �ٲ��� ���ϰ� ��)
		//     -> � Time ��ü�� ��, ��, �ʿ� �ٸ� Time ��ü�� ��Ҹ� ���� �ٸ� Time ��ü�� ���� (= ������ �� ����)
		Time operator-(const Time& t) const {

			Time time;

			// �������� �ƿ� �ٸ� ��ü�� ���� �ű⿡ ���� Time ��ü�� ���� ����
			time.hours = this->hours - t.hours;
			time.minutes = this->minutes - t.minutes;
			time.seconds = this->seconds - t.seconds;

			// ���ϰ� �� ��, �ʿ� ���� 0�� �������� �ݿø� �Ǿ�� �� (�ô� �ѷ��� ��Ÿ�� �뵵�� �ּҰ� 0�� �������� �α�)
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

		// 6. Time ��ü * double ����              
		//     -> � Time ��ü�� ������ŭ�� ���� ��, �ѷ����� ȯ��
		Time operator*(double m) {

			Time time;

			// �������� �ƿ� �ٸ� ��ü�� ���� �ű⿡ �Ǽ� m�� ���� ������
			time.hours = (int)(this->hours * m);
			time.minutes = (int)(this->minutes * m);
			time.seconds = (int)(this->seconds * m);

			// ���ϰ� �� ��, �ʿ� ���� 0�� �������� �ݿø� �Ǿ�� �� (�ô� �ѷ��� ��Ÿ�� �뵵�� �ּҰ� 0�� �������� �α�)
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

		// 7. double ���� * Time ��ü              
		//     -> � Time ��ü�� ������ŭ�� ���� ��, �ѷ����� ȯ��������, 1��° �������� �ڷ����� ���� �ڷ��� double�� �Լ�
		//         -> � ��ü�� ������ �� �� ���� ����� 1��° ���������� ���꿡 ���� ��� =  class ��� ������ �Լ��� ����Ҽ� ���� ��Ȳ
		//             -> friend �����Լ��� �ּ�, �Ǽ��� Time Ŭ���� ��ü�� ���ʷ� parameter(= ������)���� ������ �� ��ҿ� �����Ͽ� 3���� *�����ڸ� �����ϰ� ����
		friend Time operator*(double m, const Time& t);

		// 8. ��� Ŭ���� ostream ��ü << Time ��ü
		//     -> � ostream ��ü�� ��Ʈ������ <<�� ����Ͽ� Time ��ü�� 2���� ���������� ������, �׿� ���� �����͸� console�� ����ϵ��� ������ ostream ���۷��� ������ ����ϰ� �� (= ���� ostream ��ü ������ �ٷ� ����)
		//         -> �������� �־��� class ������ �������Լ��� �����ε� �ؾ� �ϴ� ��� = class ��� ������ �Լ��� ����Ҽ� ���� ��Ȳ
		//             -> friend �����Լ��� �ּ�, ostream Ŭ���� ��ü�� Time Ŭ���� ��ü�� ���ʷ� parameter(= ������)���� ������, Time Ŭ���� ��ü�� ��Ҹ� ostream Ŭ���� ��ü�ּ� ��Ʈ�����ڸ� Ȱ���� ��±���� ��� �۵����Ѿ� �ϴ��� ���Ǻο� ����
		friend ostream& operator<<(ostream& os, const Time& t);
};

// 7. double ���� * Time ��ü ���Ǻ�
Time operator*(double m, const Time& t) {

	Time time = t;
	return time * m;
}

// 8. ��� Ŭ���� ostream ��ü << Time ��ü ���Ǻ�
ostream& operator<<(ostream& os, const Time& t) {

	// ostreamŬ���� ��ü�� Time class ��ü�� Ȱ���ؼ� � ������ ��Ʈ <<������ �����ؾ� �ϴ��� ���Ǻθ� �ۼ� 
	os << t.hours << " �� " << t.minutes << " �� " << t.seconds << " �� ";

	// �� ������� ostreamŬ���� ��ü�� �������� ������ ��ȯ
	return os;
}

int main() {

	Time timer(12, 2, 50);
	Time wakeup(7, 20, 50);
	Time goWorkspace(9, 0, 40);
	Time goWorkOut(18, 11, 38);
	Time sleep(23, 30, 11);

	int before = 0, after = 0;

	// timer�� �ð��� 1�ʸ��� ���ŵǰ� �ۼ��ؾ� ��
	//  -> time(int) : 19xx����� ���ݱ����� �ð��� �ʹ̸��� ������ ȯ���� ���� ������ ��ȯ
	while (1) {

		before = time(0);

		// before�� after�� �ٸ��� ���̸�, after�� ������ (before�� while������ time()���� ����, ��� �����) + timer�� 1�߰�
		if (before != after) {

			system("cls");
			after = before;
			cout << "����ð� : " << timer << endl;
			timer + 1;

			cout << "��� : " << wakeup << endl;
			cout << "��� : " << goWorkspace << "    �ٹ� �ð� : " << goWorkOut - goWorkspace << endl;
			cout << "��� : " << goWorkOut << "   4.5�� �ٹ� : " << (goWorkOut - goWorkspace) * 4.5 << endl;
			cout << "��ħ : " << sleep << endl;
		}

	}
	return 0;
}