// new, delete를 이용한 c++의 동적할당, 해제 기능으로 다음의 기능을 가진 코드를 작성해라
// 1. 학생 수 입력 받기
// 2. 학생 수 만큼 성적을 저장 할 메모리 공간 동적 할당
// 3. 각 학생 수 성적 입력(rand() : 0~100)
// 4. 반 학생 성적 평균 값 계산
// 5. 반 학생 성적 분산 값 계산
// 6. 반 학생 성적 표준편차 값 계산
// 7. 각 학생 성적 모두 출력, 평균, 분산, 표준편차 값 출력

#include <iomanip>    // setw() 자리수 출력
#include <cstdlib>    // srand() rand() 랜덤 값 출력
#include <cmath>      // sqrt() 제곱근 함수
#include <iostream>

using namespace std;

float average(int array[], int number) {

	float result = 0;

	for (int i = 0; i < number; i++) {
		result += array[i] / (float) number;
	}

	return result;
}

float variance(int array[], int number, float average) {

	float result = 0;

	for (int i = 0; i < number; i++) {

		float deviation  = (array[i] - average);
		result += deviation * deviation / (float) number;
	}

	return result;
}

float standardDeviation(float variance) {
	return sqrt(variance);
}

int main() {

	// 1. 학생 수 입력 받기
	int studentCnt;

	cout << "원하는 학생 수를 입력해주십쇼 : ";
	cin >> studentCnt;

	// 2. 학생 수 만큼 성적을 저장 할 메모리 공간 동적 할당
	// char 포인터변수에 new 연산자를 통한 메모리에 할당하고, 그 시작주소를 포인터변수에 대입 (= 힙 영역에 생성된 char배열의 주소값을 call by reference 형식의 레버런스 변수로 넘겨줌)
	//  : 자료형 * 변수명 = new 자료형;   <->   malloc(byte 크기), calloc 등을 쓰던 과거아 다름
	int* studentScore = new int[studentCnt];

	srand((unsigned int)time(NULL));
	cout << endl << "[학생들의 성적]" << endl << endl;

	// 3. 각 학생 수 성적 입력(rand() : 0~100)
	for (int i = 0; i < studentCnt; i++) {

		// 동적할당 된 배열에 대문자 생성 
		studentScore[i] = rand() % 101;
		cout << "학생 " << setw(3) << i + 1 << "번 : " << setw(3) << studentScore[i] << "점" << endl;
	}

	// 4. 반 학생 성적 평균 값 계산
	float avg = average(studentScore, studentCnt);

	// 5. 반 학생 성적 분산 값 계산
	float var = variance(studentScore, studentCnt, avg);

	// 6. 반 학생 성적 표준편차 값 계산
	// 7. 각 학생 성적 모두 출력, 평균, 분산, 표준편차 값 출력
	cout << endl << " ->> 학급 평    균 : " << avg << endl;
	cout << "     학급 분    산 : " << var << endl;
	cout << "     학급 표준편차 : " << standardDeviation(var) << endl;

	// int 배열 메모리 동적해제
	//  : delete 변수명;  <->   free 등을 쓰던 과거아 다름
	delete[] studentScore;

	return 0;

}