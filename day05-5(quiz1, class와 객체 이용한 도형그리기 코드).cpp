// �־��� class�� �ϼ��Ͽ� ������ ����� ���� �ڵ带 �ۼ��ض�
// 1. class �ۼ�
// 2. ��������� ��(����), ����(����), ��¸�� �Է� �ޱ�
// 3. �� ��� ������ ������ ���� �׸���
// 4. �簢�� �׸���
// 5. ������ ���� �ﰢ�� �׸���
// 6. ���� ���� �ﰢ�� �׸���
// 7. �̵ �ﰢ�� �׸���

// class�� Ȱ���� ���� �׸��� �ڵ� �ۼ�
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class figure {

	public:
		//-------------------------[�������]-----------------------------------
		//��(����), ����(����)
		int width, height; 

		// ��� ���
		char shape; 

		//-------------------------[����Լ� �����]-----------------------------
		// ��� �� �ʱ�ȭ
		void Setfigure(int _width, int _height, char _shape); 

		// �簢�� �׸���
		void print_rectangular(); 

		// ������ ���� �ﰢ�� �׸���
		void print_right_triangle(); 

		// ���� ���� �ﰢ�� �׸���
		void print_left_triangle(); 

		// �̵ �ﰢ�� �׸���
		void print_isosceles_triangle(); 
};


int main() {

	int width, height;
	char shape;
	cout << "[����] ���ݺ��� ������ �׸��� �۾��� �����ϰڽ��ϴ�. ���ϴ� '����' '����' '������ �׸� ���� ����'�� ������� �Է����ּ��� : ";
	cin >> width >> height >> shape;

	// ���� class�� ȣ�� (��������� �������� �ڷ����� �ʱ�ȭ��)
	figure inputedData;

	// �Է��� ���� �Ű��� class�� ������� �� �Է�
	inputedData.Setfigure(width, height, shape);
	inputedData.print_rectangular();
	inputedData.print_right_triangle();
	inputedData.print_left_triangle();
	
}
// ��� �� �ʱ�ȭ
void figure::Setfigure(int _width, int _height, char _shape) {
	width = _width;
	height = _height;
	shape = _shape;
}

// �簢�� �׸���
void figure::print_rectangular() {

	for (int i = 1; i <= height; i++) {

		for (int j = 1; j <= width; j++) {

			cout << shape;
		}
		cout << endl;
	}
	cout << endl;
}

// ������ ���� �ﰢ�� �׸���
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

// ���� ���� �ﰢ�� �׸���
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

// �̵ �ﰢ�� �׸���
//void figure::print_isosceles_triangle();