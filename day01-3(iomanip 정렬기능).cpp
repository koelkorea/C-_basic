// iomanip
//  : 출력시 특정 위치 기준으로 정렬하거나, 표기공간을 확보하는 명령어 
//    - left : 왼쪽 정렬, 선언 위치를 기준으로 한번 설정 후 계속 적용
//    - right : 오른쪽 정렬, 선언 위치를 기준으로 한번 설정 후 계속 적용(디폴트는 오른쪽 정렬)
//    - setw(int : 칸수) : 공간 확보, setw명령 뒤 한 개의 데이터에 적용


#include <iostream>
#include<iomanip>  // left, right, setw(int : 칸수) : cout과 같이 사용하고, left나 right 선언 후 set(int)를 쓰면, 칸수에 해당하는 공백을 생성 후 왼쪽으로 공백을 보내냐(= 오른쪽정렬)? 오른쪽으록 공백을 보내냐(= 왼쪽정렬)를 구분

using namespace std;  // std:: 생략가능

//     [출력 결과]
//     1   |    2
//     3   |    4
//     5   |    6
//     7   |    8
//     9   |   10
//     11  |   12
//       ......
int main() {

	cout << left;

	// 1 ~ 100까지 표기
	for (int i = 1; i <= 100; i++) {

		// 현재 수가 짝수면
		if (i % 2 == 0) {

			// 그 부분을 오른쪽 정렬로 출력시작
			cout << right;

			// 5개의 표기공간 마련 후, 오른쪽 정렬로 i입력
			cout << setw(5) << i;

			// 줄바꿈
			cout << endl;
		}
		// 현재 수가 홀수면
		else {

			// 그 부분을 왼쪽 정렬로 출력시작
			cout << left;

			// 5개의 표기공간 마련 후, 왼쪽 정렬로 i출력 후 '|' 츌력
			cout << setw(5) << i << "|";
		}
	}

	cout << endl;

	return 0;
}

