
/*  cin���� Point ��ü �Է� / cout���� Point ��ü ���
     - cin�� istream Ŭ������ ��ü, cout�� ostream Ŭ������ ��ü.
     - istream�̳� ostream Ŭ������ ������ �Ұ��� (����Լ��� ���� ������ �����ε��� �Ұ���)
        -> �����Լ��� ���� �����ε����� ó��
*/
#include <iostream>
using namespace std;

class Point {

	private:
		int x, y;

	public:
		Point(int x = 0, int y = 0) : x(x), y(y) {}
		inline void SetX(int x) { this->x = x; }
		inline void SetY(int y) { this->y = y; }
		inline int GetX() const { return x; }
		inline int GetY() const { return y; }

		// friend �����Լ�
		friend ostream& operator<<(ostream& out, Point& p); 
		friend istream& operator>>(istream& in, Point& p);
};

// �����Լ� ���Ǻ� ����
// : ���class�� ostream class��ü�� << ������
ostream& operator<<(ostream& out, Point& p) {
	out << p.x << ", " << p.y; 
	return out; 
} 

// �����Լ� ���Ǻ� ����
// : �Է�class�� istream class��ü�� << ������
istream& operator>>(istream& in, Point& p) {
	in >> p.x >> p.y;
	return in; 
}

int main() {
	int x, y;
	cout << "\n x, y��ǥ �Է� (���鱸��) : ";
	cin >> x >> y;

	//��ü ����
	Point p1(x, y); 

	// cout���� point  ��ü ���
	cout << "p1( " << p1 << ")\n";  

	// �����Լ��� ����Ǿ� �ִ�����, ����Լ� ���� cout.opearator<<(p1); �Ұ���
	//  -> �����Լ��� ���� �����ε����� �ذ�
	operator<<(cout, p1);

	Point p2;
	cout << "\n x, y��ǥ �Է� (���鱸��) : ";

	// �����Լ��� ���� �����ε����� �ذ�
	cin >> p2; 

	// cout���� point ��ü ���
	cout << "p2( " << p2 << ")\n";

	// �����Լ��� ����Ǿ� �ִ�����, ����Լ� ���� cout.opearator>>(p2); �Ұ���
	//  -> �����Լ��� ���� �����ε����� �ذ�
	operator<<(cout, p2);

	return 0;
}
