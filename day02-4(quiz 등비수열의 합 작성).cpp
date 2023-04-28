// quiz : 등비수열의 합을 구하는 함수를 다음의 공식을 이용해 작성하되, defalut parameter를 사용해서 작성해라 (a : 첫째항 - 기본1 , r : 공비 - 기본2 , n : 수열의 전체항의 갯수 - 기본5)
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
