// static 멤버변수, 멤버함수가 포함된 student class를 설계해라, 조건은 다음과 같음
// 
// 1. private멤버변수
//     - 학번
//     - 이름
//     - 나이
//     - 학생수 (static 멤버변수)

// 2. public 멤버함수
//     - student 생성자           : 학번은 20230000부터 차례로 1씩 증가 되도록 구현
//     - (const) print_info()     : 학생 정보 출력
//     - (static) print_std_cnt() : 학생 수 출력

#include <iostream>
#include <iomanip>

using namespace std;

// 학생 클래스
class student {

	private : 

		// 학번
		int studentNum;
		// 이름
		char* name;
		// 나이
		int age;

		// 현재 줄 학번(static)
		static int currentStudentNum;
		// 현재 학생 수(static)
		static int theNumOfStudent;

	public :

		student(char* _name, int _age) {
			theNumOfStudent++;
			studentNum = currentStudentNum++;
			name = _name;
			age = _age;
		}

		const void print_std_cnt() {
			cout << endl;
			cout << "       [학번 " << studentNum << "인 학생 정보]" << endl;
			cout << "        - 이름 " << *name << "인 학생 정보" << endl;
			cout << "        - 나이 " << age << "인 학생 정보" << endl << endl;
		}

		static void print_info() {
			cout << " ->> [중요] 현재 등록된 학생수는 총 " << theNumOfStudent << "입니다!" << endl << endl;
		}

		inline char* getName() {

			return name;
		}

};

int student::currentStudentNum = 20230000;
int student::theNumOfStudent = 0;

//---------------------------------------------------기존 cin.clear를 발전시킨 메서드 cinput--------------------------------------------
void cinclear() {
	if (cin.fail()) {
		cin.clear();
		while (cin.get() != '\n');
	}
	else while (cin.get() != '\n');
}

void cinput(int& n) {
	while (!(cin >> n)) {
		cinclear();
		cout << "(알림) 입력이 잘못되었습니다. 다시 입력하세요!" << endl << endl;
	}
}

void cinput(char& n) {
	while (!(cin >> n)) {
		cinclear();
		cout << "(알림) 입력이 잘못되었습니다. 다시 입력하세요!" << endl << endl;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------

int main() {

	int flag = 0;

	while(flag == 0){

		// 학생 수 입력 받기
		int studentCnt;

		cout << endl << "[학생개인정보 입력기능]" << endl << endl << "새로 입력할 학생 수를 입력해주십쇼 : ";
		cinput(studentCnt);

		// 각 입력값 크기에 해당하는 동적크기를 갖는 char배열을 만들기 위해, 일단 입력값 자체를 받기 위한 정적 배열을 하나 만들어 준다
		char inputName[100];
		int inputAge;

		// 입력할 학생 수만큼 이름, 전화번호 입력받기
		for (int i = 0; i < studentCnt; i++) {

			// 이름, 전번 정적배열에 입력
			cout << " ->> " << setw(3) << i + 1 << "번째로 입력할 학생의 '이름'과 '나이'를 입력해주세요 : ";
			cin >> inputName >> inputAge;

			// 'name' char 크기만큼의 동적배열을 메모리에 할당하여 생성 후,  
			//  -> 그들의 char 포인터값을 생성자 함수의 parameter로 대입하여 student 객체 인스턴스의 멤버변수 값으로 대입하여 객체 생성
			//     (= 현재 입력하는 학생정보(이름, 정보)를 현재 프로그램이 끝날 때까지 유지하고 접근할 목적으로 동적할당 + 객체 생성까지 세트메뉴로 완료하는 편한 방법)
			student* eachStudent = new student(new char[strlen(inputName) + 1], inputAge);

			// strcpy_s 함수를 통해 문자열 복사
			strcpy_s(eachStudent->getName(), strlen(inputName) + 1, inputName);

			// 멤버함수 실행
			eachStudent->print_std_cnt();
		}

		// static 멤버함수 실행
		student::print_info();

		cout << "(안내!) 전부 완료되었습니다. 계속하시겠습니까? (계속하고 싶으시면 0을 입력해주세요)";
		cin >> flag;

	}

	return 0;
}