// Ŭ���� ���ø� case�� �����ڵ�
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------------
// (����1) ����Լ��� ���Ǻθ� ���� ���� �Լ� ���ø����� �����ϴ� Ŭ���� ���ø� ����
//   -> ��� ����Լ� paramter��� ��������� �ٸ��� ���ְų� this�� ���� �Ǵ� ���� �̷� �ʿ���� (= ����2�� �����ص� ��)

// Dummy Ŭ���� ���ø�
//  -> ���ø� parameter�� T�� � �ڷ����� ����Ű�Ŀ� ���� ��������� ����Լ��� parameter�� �ڷ��� ��θ� �����ϴ� ���� 
template <typename T>
class Dummy {

    private:
        T a;

    public:
        // ��, ��Ģ������ ����Լ��� parameter��� ��������� �޶�� �ϹǷ�... ����Լ����� ���Ǻο� �ش��ϴ� ������ ���� �ܺη� ���� �Լ� ���ø��� ����Ͽ� ������
        Dummy(T a);                    // Dummy<T>(T a); �� ����
        inline void SetA(T a);         // inline void SetA<T>(T a); �� ����
        inline T GetA() const;         // inline T GetA()<T> const; �� ����
};

// ������ �Լ� - �Լ� ���ø� ��� + �ʱ�ȭ ����Ʈ (Initialize List) ����Ͽ� ���Ǻ� �ۼ�
template <typename T>
Dummy<T>::Dummy(T a) : a(a) {}         // Dummy<T>::Dummy<T>(T a) : a(a) {} �� ����

// set ����Լ� - �Լ� ���ø� ����ؼ� ���Ǻ� �ۼ�
template <typename T>
inline void Dummy<T>::SetA(T a) {       // inline void Dummy<T>::SetA<T>(T a) {} �� ����
    this->a = a; 
}

// get ����Լ� - �Լ� ���ø� ����ؼ� ���Ǻ� �ۼ�
template <typename T>
inline T Dummy<T>::GetA() const {        // inline T Dummy<T>::GetA<T>() const {} �� ����
    return a; 
}


//-----------------------------------------------------------------------------------------------------------------------
// (����2) Ŭ���� ���ø� �ϳ��� ����Լ��� �ڷ������� ���� + ���ø� parameter�� �������� Ŭ���� ���ø� ����
//   -> this�� �ᵵ �ǰ�, ������� != paramter�� �ص� ��

// dosomething Ŭ���� ���ø�
//  -> ���ø� parameter�� T1, T2�� � �ڷ����� ����Ű�Ŀ� ���� ��������� ����Լ��� parameter�� a, b�� �ڷ����� �����ϴ� ���� 
template <typename T1, typename T2>
class dosomething {

    private:
        T1 a;
        T2 b;

    public:       

        dosomething() : a(0), b(0) {};
        dosomething(T1 a, T2 b) : a(a), b(b) {}  // dosomething<T1, T2>(T1 a, T2 b); �� ����

        inline T1 getA() const {                 // inline T1 getA<T1>() const; �� ����
            return a;
        }

        inline T2 getB() const {                 // inline T2 getB<T2>() const; �� ����
            return b;
        }

        inline void setA(T1 a) {                 // inline void setA<T1>(T1 a); �� ����
            this->a = a;
        }

        inline void setB(T2 b) {                 // inline void setB<T2>(T2 b); �� ����
            this->b = b;
        }
};

// ������ �Լ� - �Լ� ���ø� ��� + �ʱ�ȭ ����Ʈ (Initialize List) ����Ͽ� ���Ǻ� �ۼ�
//template <typename T1, typename T2>
//dosomething<T1, T2>::dosomething() : a(0), b(0) {}

// ������ �Լ� - �Լ� ���ø� ��� + �ʱ�ȭ ����Ʈ (Initialize List) ����Ͽ� ���Ǻ� �ۼ�
//template <typename T1, typename T2>
//dosomething<T1, T2>::dosomething(T1 a, T2 b) : a(a), b(b) {}


int main() {

    //-----------------------------------------------------------------------------------------------------------------------
    // (����1) ����Լ��� ���Ǻθ� ���� ���� �Լ� ���ø����� �����ϴ� Ŭ���� ���ø� ����
    //   -> (�߿�) ������ �Լ��� ����, ���ø� typename�� ����Ǿ���
    //      (= ���� ���� ���ø� paramter�� ����ϴ� ����Լ��� ȣ��ÿ��� ���� <���� �ڷ���>�� ���� �ʾƵ�, �����Ϸ��� ��Ȯ�� class ������ �� ����� �ڷ����� ����ؼ� ���ø� ȣ�� �κ��� �ۼ�)

    Dummy<int> d1(10);
    cout << d1.GetA() << endl;     // d1.GetA<int>() = ���� 10

    Dummy<int> d2('A');
    cout << d2.GetA() << endl;     // d1.GetA<int>() = ���� 'A' = 65

    Dummy<char> d3('A');
    cout << d3.GetA() << endl;     // d1.GetA<char>() = ���� 'A' = 65

    Dummy<double> d4(3.14);
    cout << d4.GetA() << endl;     // d1.GetA<double>() = �Ǽ� 3.14

    Dummy<const char*> d5("C++");
    cout << d5.GetA() << endl;     // d1.GetA<char*>() = ���ڿ� "C++"

    //-----------------------------------------------------------------------------------------------------------------------
    // (����2) Ŭ���� ���ø� �ϳ��� ����Լ��� �ڷ������� ���� + ���ø� parameter�� �������� Ŭ���� ���ø� ����
    //   -> (�߿�) ������ �Լ��� ����, ���ø� typename�� ����Ǿ���
    //      (= ���� ���� ���ø� paramter�� ����ϴ� ����Լ��� ȣ��ÿ��� ���� <���� �ڷ���>�� ���� �ʾƵ�, �����Ϸ��� ��Ȯ�� class ������ �� ����� �ڷ����� ����ؼ� ���ø� ȣ�� �κ��� �ۼ�)

    dosomething<int, int> f1(1, 10);
    cout << "d1 = " << f1.getA() << ", " << f1.getB() << endl;

    dosomething<int, char> f2('A', 'B');
    cout << "d2 = " << f2.getA() << ", " << f2.getB() << endl;

    dosomething<char, char> f3('A', 'B');
    cout << "d3 = " << f3.getA() << ", " << f3.getB() << endl;

    dosomething<double, char> f4(3.14, 'Q');
    cout << "d4 = " << f4.getA() << ", " << f4.getB() << endl;

    dosomething<const char*, const char*> f5("C++", "Well done");
    cout << "d5 = " << f5.getA() << ", " << f5.getB() << endl;

    return 0;
}