// ��ü
//  : ����� Ŭ������ ������ �����ϸ� �ϳ��� ��ü��� ��

//   # class? ��ü? �ν��Ͻ� ����?
//     : �ڷ���(class, ��ü��) ����(��ü, �ν��Ͻ� ����)

//ACT act_1, act_2, act_3, act_4, act_5, act_6;
//��ü 1, ��ü 2, ��ü 3, ��ü 4, ��ü 5, ��ü 6,

//   # �� �̷� ������ �ϳ�?
//     : 

// class�� ��üȭ�� ���� �ﰢ�� ���ϱ� ����
#include <iostream>
using namespace std;
class Triangle {
public:
	int base, height; //�غ�, ����
	void SetTriangle(int _base, int _height);
	double GetArea();
};
void Triangle::SetTriangle(int _base, int _height) {
	base = _base;
	height = _height;
}
double Triangle::GetArea() {
	return base * height / 2.0;
}
int main() {
	cout << "�غ� : ";
	int base;
	cin >> base;

	cout << "���� : ";
	int height;
	cin >> height;

	Triangle t; //�ﰢ�� Ŭ����
	t.SetTriangle(base, height);

	cout << "�ﰢ���� ���̴� " << t.GetArea() << "�Դϴ�.\n";
}
