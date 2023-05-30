// quiz - template를 이용해서, 적은 코드로도 범용성 높은 자료형을 포괄가능한 컨테이너 클래스인 stack의 class를 구현하라 

// stack class의 템플릿 parameter (어떤 자료형을 적용할건지, 초기 크기값 size)
#include <iostream>
#include <string>

using namespace std;

template <typename T, int size>

class stack {

	private:

		// 어떤 자료형의 동적할당된 메모리 위치 주소값 저장
		T* array;

		// 현재 스택의 저장값
		int top;

	public:
		stack() {
			array = new T[size];
			top = 0;
		}

		~stack() {
			delete[] array;
		}

		// 마지막 위치에 값 추가
		void push(T value) {

			if (isFull()) {

				cout << " ->> (주의) 현재 stack에 들어있는 데이터가 가득찼습니다!" << endl << endl;

				int newSize = top * 2;

				// 동적배열 구현위해 copy를 위해 미리 할당해 놓은 객체배열
				T* tmp = new T[newSize];
				copy(array, array + top, tmp);

				// 동적할당한게 객체배열이니, delete를 쓸때도 배열[]을 지우라고 제대로 써줘야 작동함
				delete[] array;

				array = new T[newSize];
				copy(tmp, tmp + top, array);

				// 동적할당한게 객체배열이니, delete를 쓸때도 배열[]을 지우라고 제대로 써줘야 작동함
				delete[] tmp;
			}

			array[top] = value;
			cout << " ->> 추가된 데이터 : " << array[top] << endl << endl;
			top++;
		}

		// 마지막 위치값 삭제
		inline void pop() {

			if (isEmpty() == false) {
				cout << " ->> 삭제된 데이터 : " << getTop() << endl << endl;
				top--;
			}
			else {
				cout << " ->> (주의) 현재 stack에 들어있는 데이터가 없습니다!" << endl << endl;
			}
			
		}

		// 스택 초기화(그냥 값 다 지우고 초기화)
		inline void clear() {

			cout << " ->> (주의) 현재 stack에 들어있는 데이터 전체 삭제합니다!" << endl << endl;
			top = 0;
		}

		// 마지막으로 입력된 값 반환 (const 함수는 const 함수끼리..)
		inline const T getTop() const {

			if (top == 0) {
				return 0;
			}

			return array[top - 1];
		}

		void print() const {

			for (int i = 0; i < top; i++) {
				cout << array[i] << ", ";
			}

			cout << endl << endl;

		}
		
		bool isEmpty() const {
			
			return (top == 0);
		}

		bool isFull() {

			return ((size - 1) == top);
		}
};

int main() {

	stack<string, 5> intStack;

	int flag = 99;

	while (flag != 0) {

		cout << "1. stack값 추가" << endl;
		cout << "2. stack값 삭제" << endl;
		cout << "3. stack clear" << endl;
		cout << "4. stack 전체 출력" << endl;
		cout << " ->> 원하시는 메뉴를 선택해주세요 (0 = exit) : ";
		cin >> flag;

		if (flag == 1) {

			string enter = "";

			cout << " ->> stack에 넣을 값을 입력해주세요 : ";
			cin >> enter;

			intStack.push(enter);

		}
		else if (flag == 2) {

			intStack.pop();
		}
		else if (flag == 3) {

			intStack.clear();
		}
		else if (flag == 4) {

			intStack.print();
		}
		else if(flag == 0) {
			cout << "프로그램 종료!";
			exit(0);
		}

	}

	return 0;
}