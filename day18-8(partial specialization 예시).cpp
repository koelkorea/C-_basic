// 부분 특수화 예시 - 
#include <iostream>
using namespace std;

// 부분 특수화 : 템플릿의 매개변수가 여러개일 경우 매개변수 중 일부만 특수화
template <typename T, int count>

void display(T value) {
	for (int i = 0; i < count; i++) cout << value << ' ';
	cout << endl;
}

int main() {
	display<int, 5>(0);      //  <int, 5> 반드시 작성
	display<char, 10>('A');  //  <char, 10> 반드시 작성
	display<double, 3>(3.4); //  <double, 3> 반드시 작성
	return 0;
}