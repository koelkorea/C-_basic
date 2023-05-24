//   # (�߿�!) ������ �����ε�(operator overloading)�� ���ǻ���
//      1. ������ �������� ����� �� � ����� ������ ���� �ǹ̷� ���� �� �ֵ��� �ۼ�
//          -> ��ü�� ���� ���� �����ڸ� �ٸ� ������� ó���ϴ� ������ �ۼ����� ����� ��
//      2. ������ ���� �켱������ ���ռ��� �ٲ��� ����
//      3. defalut parameter ������ �Ұ���!
//      4. (�߿�!) �⺻ ����Ǿ� �����Ǵ� �������Լ���, �������� �־��� class ������ ��쿡�� �� ��� �������Լ��� �����ε� �Ұ���!
//          ->  �����Լ��� ���� �����ε����� ó���ؼ� �ذ� ����
// 
//              ex) istream�̳� ostream Ŭ������ ����������Լ��� ���� ������ �ǵ�� ���� (= ����Լ��� ���� �� class�� ��Ʈ������ �����ε��� �Ұ���)
//                   -> (�߿�) ostream&, istream&�� ��ȯ�ϴ� ���� �������Լ�operator<<�� ���� �����ε����� ó������

//   # ���� �������Լ��� ���� ����
//      1. �������� �־��� class ������ ��쿡�� �� ��� �������Լ��� �����ε��Ͽ� �߰��ϴ� ���� �Ұ����ϱ� ������
//          -> �׷��� �����Լ��� �̸� ä���ִ� ������ �ذ���
//      2. � ��ü�� ������ �� �� ���� ����� 1��° ���������� ���꿡 ���� ��쿡��, ��� �������Լ��� ȣ���� �Ұ����ϱ� ����
//          -> �ܼ��� ��� �������� ������ ����� ������� overloading �ؼ� parameter�� �־� �߰� ���� �� �����ϸ� �勯��, ���� �������Լ� ���


// [���� �������Լ� overloading �����ڵ�1 - �������� �־��� class ������ ��쿡�� �� ��� �������Լ��� �����ε��Ͽ� �߰��ϴ� ���� �Ұ����� case]
// 
// friend �����Լ��� operator overloading�� ����, ostream�� iostream class�� ��Ʈ������(<<, >>) overloading�ϱ�
//  : cin�� istream Ŭ������ ��ü, cout�� ostream Ŭ������ ��ü == �� �� class�� �������� ������ overloading �ؼ� �߰������ ��
// 
//   1. '<<' overloading ���� ���� 
//      : istream ��ü cin�� ostream ��ü cout�� ��Ʈ������(<<, >>)�� ����� ���� class ��ü�� ���ؼ� ��� ���� �Ǿ����� ���� = ��Ʈ������ �鳯 ����� ����� class��ü�� ��/��� ���˵� �� ����
// 
//   2. ��ġ�ؾ� �ϴ� ��
//      : ostream�� iostream�� ����� class��ü�� �ܺο������� ���������� ���� ���, �̸� ������ �� �ֵ��� ��Ʈ������(<<. >> )�Լ��� ���� overloading�� ������ �ۼ�
//         -> ���������� �ܺο������� ����� ���� class ��ü�� ���ؼ��� cin, cout ��ü�� ��Ʈ�����ڸ� ���� ��,����� �����ϵ��� ��ġ�ϱ�

// cin���� ����� ���� class Point�� ��ü�� ������ �Է� / cout���� ����� ���� class Point�� ��ü�� ������ ��°����ϰ�, ostream�� iostream class�� ��Ʈ������(<<, >>)�Լ��� overloading�ϴ� �����ڵ�
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
		//  ->  istream�̳� ostream Ŭ������ ����������Լ��� ���� ������ �ǵ�� ���� (= ����Լ��� ���� �� class�� ��Ʈ������ �����ε��� �Ұ���)
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
