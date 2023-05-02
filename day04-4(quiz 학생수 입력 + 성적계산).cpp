// new, delete�� �̿��� c++�� �����Ҵ�, ���� ������� ������ ����� ���� �ڵ带 �ۼ��ض�
// 1. �л� �� �Է� �ޱ�
// 2. �л� �� ��ŭ ������ ���� �� �޸� ���� ���� �Ҵ�
// 3. �� �л� �� ���� �Է�(rand() : 0~100)
// 4. �� �л� ���� ��� �� ���
// 5. �� �л� ���� �л� �� ���
// 6. �� �л� ���� ǥ������ �� ���
// 7. �� �л� ���� ��� ���, ���, �л�, ǥ������ �� ���

#include <iomanip>    // setw() �ڸ��� ���
#include <cstdlib>    // srand() rand() ���� �� ���
#include <cmath>      // sqrt() ������ �Լ�
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

	// 1. �л� �� �Է� �ޱ�
	int studentCnt;

	cout << "���ϴ� �л� ���� �Է����ֽʼ� : ";
	cin >> studentCnt;

	// 2. �л� �� ��ŭ ������ ���� �� �޸� ���� ���� �Ҵ�
	// char �����ͺ����� new �����ڸ� ���� �޸𸮿� �Ҵ��ϰ�, �� �����ּҸ� �����ͺ����� ���� (= �� ������ ������ char�迭�� �ּҰ��� call by reference ������ �������� ������ �Ѱ���)
	//  : �ڷ��� * ������ = new �ڷ���;   <->   malloc(byte ũ��), calloc ���� ���� ���ž� �ٸ�
	int* studentScore = new int[studentCnt];

	srand((unsigned int)time(NULL));
	cout << endl << "[�л����� ����]" << endl << endl;

	// 3. �� �л� �� ���� �Է�(rand() : 0~100)
	for (int i = 0; i < studentCnt; i++) {

		// �����Ҵ� �� �迭�� �빮�� ���� 
		studentScore[i] = rand() % 101;
		cout << "�л� " << setw(3) << i + 1 << "�� : " << setw(3) << studentScore[i] << "��" << endl;
	}

	// 4. �� �л� ���� ��� �� ���
	float avg = average(studentScore, studentCnt);

	// 5. �� �л� ���� �л� �� ���
	float var = variance(studentScore, studentCnt, avg);

	// 6. �� �л� ���� ǥ������ �� ���
	// 7. �� �л� ���� ��� ���, ���, �л�, ǥ������ �� ���
	cout << endl << " ->> �б� ��    �� : " << avg << endl;
	cout << "     �б� ��    �� : " << var << endl;
	cout << "     �б� ǥ������ : " << standardDeviation(var) << endl;

	// int �迭 �޸� ��������
	//  : delete ������;  <->   free ���� ���� ���ž� �ٸ�
	delete[] studentScore;

	return 0;

}