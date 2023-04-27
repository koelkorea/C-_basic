#include <iostream>
#include<iomanip>  // left, right, setw(int : 칸수) : cout과 같이 사용하고, left나 right 선언 후 set(int)를 쓰면, 칸수에 해당하는 공백을 생성 후 왼쪽으로 공백을 보내냐(= 오른쪽정렬)? 오른쪽으록 공백을 보내냐(= 왼쪽정렬)를 구분

using namespace std;  // std:: 생략가능

int main() {

	cout << left;

	for (int i = 1; i <= 100; i++) {

		if (i % 2 == 0) {
			cout << right;
			cout << setw(5) << i;
			cout << endl;
		}
		else {
			cout << left;
			cout << setw(5) << i << "|";
		}
	}

	cout << endl;

	return 0;
}