// quiz : �������� ���� ���ϴ� �Լ��� ������ ������ �̿��� �ۼ��ϵ�, defalut parameter�� ����ؼ� �ۼ��ض� (a : ù°�� - �⺻1 , r : ���� - �⺻2 , n : ������ ��ü���� ���� - �⺻5)
//  -> (a * (r ^ n-1)) / (r-1)

#include <iostream>
#include <math.h>
using namespace std;

double geometric_sqc_sum(int a = 1, int r = 2, int n = 5) {

	if (r == 1) return n * a;

	return a * (pow(r, n) - 1) / (r - 1);
}

int main() {

	int input_int;
	double input_double;

	cout << geometric_sqc_sum() << endl;
	cout << geometric_sqc_sum(5) << endl;
	cout << geometric_sqc_sum(5, 2) << endl;
	cout << geometric_sqc_sum(5, 3, 6) << endl;

	return 0;

}
