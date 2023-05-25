// quiz - template�� �̿��ؼ�, ���� �ڵ�ε� ���뼺 ���� �ڷ����� ���������� �����̳� Ŭ������ stack�� class�� �����϶� 

// stack class�� ���ø� parameter (� �ڷ����� �����Ұ���, �ʱ� ũ�Ⱚ size)
#include <iostream>
#include <string>

using namespace std;

template <typename T, int size>

class stack {

	private:

		// � �ڷ����� �����Ҵ�� �޸� ��ġ �ּҰ� ����
		T* array;

		// ���� ������ ���尪
		int top;

	public:
		stack() {
			array = new T[size];
			top = 0;
		}

		~stack() {
			delete[] array;
		}

		// ������ ��ġ�� �� �߰�
		void push(T value) {

			if (isFull()) {

				cout << " ->> (����) ���� stack�� ����ִ� �����Ͱ� ����á���ϴ�!" << endl << endl;

				int newSize = top * 2;

				// �����迭 �������� copy�� ���� �̸� �Ҵ��� ���� ��ü�迭
				T* tmp = new T[newSize];
				copy(array, array + top, tmp);

				// �����Ҵ��Ѱ� ��ü�迭�̴�, delete�� ������ �迭[]�� ������ ����� ����� �۵���
				delete[] array;

				array = new T[newSize];
				copy(tmp, tmp + top, array);

				// �����Ҵ��Ѱ� ��ü�迭�̴�, delete�� ������ �迭[]�� ������ ����� ����� �۵���
				delete[] tmp;
			}

			array[top] = value;
			cout << " ->> �߰��� ������ : " << array[top] << endl << endl;
			top++;
		}

		// ������ ��ġ�� ����
		inline void pop() {

			if (isEmpty() == false) {
				cout << " ->> ������ ������ : " << getTop() << endl << endl;
				top--;
			}
			else {
				cout << " ->> (����) ���� stack�� ����ִ� �����Ͱ� �����ϴ�!" << endl << endl;
			}
			
		}

		// ���� �ʱ�ȭ(�׳� �� �� ����� �ʱ�ȭ)
		inline void clear() {

			cout << " ->> (����) ���� stack�� ����ִ� ������ ��ü �����մϴ�!" << endl << endl;
			top = 0;
		}

		// ���������� �Էµ� �� ��ȯ (const �Լ��� const �Լ�����..)
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

		cout << "1. stack�� �߰�" << endl;
		cout << "2. stack�� ����" << endl;
		cout << "3. stack clear" << endl;
		cout << "4. stack ��ü ���" << endl;
		cout << " ->> ���Ͻô� �޴��� �������ּ��� (0 = exit) : ";
		cin >> flag;

		if (flag == 1) {

			string enter = "";

			cout << " ->> stack�� ���� ���� �Է����ּ��� : ";
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
			cout << "���α׷� ����!";
			exit(0);
		}

	}

	return 0;
}