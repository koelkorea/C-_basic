// new, delete를 이용한 c++의 동적할당, 해제 기능으로 다음의 기능을 가진 코드를 작성해라
// 1. 학생 수 입력 받기
// 2. 학생 수 만큼 STU 메모리 공간 동적 할당
// 3. 각 학생 수만큼 이름, 전화번호 입력받기
// 4. 이름, 전화번호 들의 문자열 길이만큼 동적할당
// 5. 각 학생 이름, 전화번호 들의 모두 출력

#include <iomanip>    // setw() 자리수 출력
#include <cstring>    
#include <iostream>

using namespace std;

typedef struct STU {
	char* name;
	char* phoneNumber;
}STU;

int main() {

	// 1. 학생 수 입력 받기
	int studentCnt;

	cout << "원하는 학생 수를 입력해주십쇼 : ";
	cin >> studentCnt;

	// 2. 학생 수 만큼 성적을 저장 할 메모리 공간 동적 할당
	// STU 구조체 포인터변수에 new 연산자를 통한 메모리에 입력한 학생수에 해당하는 만큼의 크기를 갖는 STU구조체 배열을 할당하고, 그 시작주소를 포인터변수에 대입 
	// (= 힙 영역에 생성된 STU 구조체의 주소값을 call by reference 형식의 레버런스 변수로 넘겨줌)
	//  : 자료형 * 변수명 = new 자료형;   <->   malloc(byte 크기), calloc 등을 쓰던 과거아 다름
	STU* student = new STU[studentCnt];

	cout << endl << "[학생들의 정보]" << endl << endl;

	// 각 입력값 크기에 해당하는 동적크기를 갖는 char배열을 만들기 위해, 일단 입력값 자체를 받기 위한 정적 배열을 하나 만들어 준다
	char inputName[13];
	char inputPhoneNumber[13];

	// 3. 각 학생 수만큼 이름, 전화번호 입력받기
	for (int i = 0; i < studentCnt; i++) {

		cout << "학생 " << setw(3) << i + 1 << "번의 이름과 전화번호를 입력해주세요 : ";
		cin >> inputName >> inputPhoneNumber;

		// 4. 이름, 전화번호 들의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
		student[i].name = new char[strlen(inputName) + 1];

		// 정적배열에 입력된 이름 문자열을 새로 적은 문자열로 1자씩 복사
		for (int j = 0; j <= strlen(inputName); j++) {
			student[i].name[j] = inputName[j];

		}

		// 4. 이름, 전화번호 들의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
		student[i].phoneNumber = new char[strlen(inputPhoneNumber) + 1];

		// 정적배열에 입력된 전화번호 문자열을 새로 적은 문자열로 1자씩 복사
		for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
			student[i].phoneNumber[j] = inputPhoneNumber[j];
		}

	}

	// 5. 각 학생 수만큼 이름, 전화번호 입력받기
	for (int i = 0; i < studentCnt; i++) {

		cout << endl << "학생 " << setw(3) << i + 1 << "번 정보" << endl;
		cout << " ->> 이름 : " << student[i].name << endl;
		cout << " ->> 전화번호 : " << setw(3) << student[i].phoneNumber << endl;

		delete[] student[i].name;
		delete[] student[i].phoneNumber;
	}

	// int 배열 메모리 동적해제
	//  : delete 변수명;  <->   free 등을 쓰던 과거아 다름
	delete[] student;

	return 0;

}