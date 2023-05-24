// ���ø�(Template)
//  : function or class�� �ڷ� Ÿ�Կ� ���� ���������� �ٽ� �ۼ����� �ʾƵ�, parameter�� �ڷ����� Ȯ���ϰ� ������ �ܰ迡�� parameter �ڷ����� �´� function or class �������ִ� Ʋ�μ� �۵�
//    -> (�߿�) ������ �ܰ迡�� �۵��� = ���ø��� ���� ���� ������ �ӵ��� ������ <-> ���α׷� ó�� �ӵ��� ���� X
//        -> JAVA�� ���ʸ���(generics)�� ������ ��� (��! ���ʸ����� ������ ���������� Ÿ�� check��� �߰�)

//   # ���ø� ��� ����?
//      : ��¥ ����� ���� ���´ٸ�? �ڵ��� �ϼ����� ��������, �������� ���꼺 ȿ���� �����ϱ� ���� 
//         -> �̷��� ������ STL(Standard Template Library)ó�� ������ ���̺귯���� �Բ��� �ó����� ���� ����

//   # ���ø��� ���� 	   
//     2. Ŭ���� ���ø�(class Template)
//        : Ŭ������ �Ϲ����� ������ ����, Ŭ������ ��� ������ ��� �Լ��� ���� '������ �ڷ���' ���� ���ڷ� �޾� ���� Ŭ������ �����ϴ� Ʋ

//          ex1) template <value�ڷ��� �����̳ʿ�Ҹ�>    
//               -> ���� �����̳� class ��ü�� �����ϸ�, �� ������ value�ڷ����� ������ �ڷ������� ����

//          ex2) �����̳�Ŭ������ <value�ڷ���> ��ü�� = new �����̳�Ŭ������(); ���ĵ� ���� ���� ����


//Ŭ���� ���ø� ����2
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class dosomething{
	private:
		T1 a;
		T2 b;

	public:
		dosomething();
		dosomething(T1 a, T2 b);

		inline T1 getA() const {
			return a; 
		}

		inline T2 getB() const {
			return b; 
		}

		inline void setA(T1 a) {
			this->a = a; 
		}

		inline void setB(T2 b) {
			this->b = b; 
		}
};

template <typename T1, typename T2>
dosomething<T1, T2>::dosomething() : a(0), b(0) {}

template <typename T1, typename T2>
dosomething<T1, T2>::dosomething(T1 a, T2 b) : a(a), b(b) {}

int main(){

	dosomething<int, int> d1(1, 10);
	cout << "d1 = " << d1.getA() << ", " << d1.getB() << endl;

	dosomething<int, char> d2('A', 'B');
	cout << "d2 = " << d2.getA() << ", " << d2.getB() << endl;

	dosomething<char, char> d3('A', 'B');
	cout << "d3 = " << d3.getA() << ", " << d3.getB() << endl;

	dosomething<double, char> d4(3.14, 'Q');
	cout << "d4 = " << d4.getA() << ", " << d4.getB() << endl;

	dosomething<const char*, const char*> d5("C++", "Well done");
	cout << "d5 = " << d5.getA() << ", " << d5.getB() << endl;

	return 0;
}
