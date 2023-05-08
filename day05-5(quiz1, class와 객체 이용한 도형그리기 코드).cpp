// 주어진 class를 완성하여 다음의 기능을 가진 코드를 작성해라
// 1. class 작성
// 2. 멤버변수인 폭(가로), 높이(세로), 출력모양 입력 받기
// 3. 각 멤버 변수의 값으로 도형 그리기
// 4. 사각형 그리기
// 5. 오른쪽 직각 삼각형 그리기
// 6. 왼쪽 직각 삼각형 그리기
// 7. 이등변 삼각형 그리기

// class를 활용한 도형 그리기 코드 작성
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class figure {

	public:
		//-------------------------[멤버변수]-----------------------------------
		//폭(가로), 높이(세로)
		int width, height; 

		// 출력 모양
		char shape; 

		//-------------------------[멤버함수 선언부]-----------------------------
		// 멤버 값 초기화
		void Setfigure(int _width, int _height, char _shape); 

		// 사각형 그리기
		void print_rectangular(); 

		// 오른쪽 직각 삼각형 그리기
		void print_right_triangle(); 

		// 왼쪽 직각 삼각형 그리기
		void print_left_triangle(); 

		// 이등변 삼각형 그리기
		void print_isosceles_triangle(); 
};


int main() {

	int width, height;
	char shape;
	cout << "[개요] 지금부터 도형을 그리는 작업을 실행하겠습니다. 원하는 '가로' '세로' '도형을 그릴 단위 문자'를 순서대로 입력해주세요 : ";
	cin >> width >> height >> shape;

	// 도형 class를 호출 (멤버변수의 개별값은 자료형의 초기화값)
	figure inputedData;

	// 입력한 값을 매개로 class의 멤버변수 값 입력
	inputedData.Setfigure(width, height, shape);
	inputedData.print_rectangular();
	inputedData.print_right_triangle();
	inputedData.print_left_triangle();
	
}
// 멤버 값 초기화
void figure::Setfigure(int _width, int _height, char _shape) {
	width = _width;
	height = _height;
	shape = _shape;
}

// 사각형 그리기
void figure::print_rectangular() {

	for (int i = 1; i <= height; i++) {

		for (int j = 1; j <= width; j++) {

			cout << shape;
		}
		cout << endl;
	}
	cout << endl;
}

// 오른쪽 직각 삼각형 그리기
void figure::print_right_triangle() {

	int floorUp = (int) ceil((double)height / width);

	for (int i = 1; i <= height; i++) {

		for (int j = 1; j <= width; j++) {
			
			if (j <= i * floorUp) {

				cout << shape;
			}
			else {

				cout << " ";
			}
		}

		cout << endl;
	}
	cout << endl;
}

// 왼쪽 직각 삼각형 그리기
void figure::print_left_triangle() {

	int floorUp = (int)ceil((double)height / width);

	for (int i = 1; i <= height; i++) {

		for (int j = 1; j <= width; j++) {

			if (j <= width - i * floorUp) {

				cout << shape;
			}
			else {

				cout << " ";
			}
		}

		cout << endl;
	}
	cout << endl;
}

// 이등변 삼각형 그리기
//void figure::print_isosceles_triangle();