// ������(Constructor)
//  : ��ü�� [����]�� ���ÿ� ȣ���ϴ� 'Ŭ������'�� ������ �̸��� �Լ�, ��ü�� �����Ҵ� �������� new�� �Բ� ����ϸ� �ʱ�ȭ ������ ���Ա��� ������
//    -> ���� calloc, malloc, realloc�� ��ü��, 'new Ŭ������'�� ��� 'new Ŭ������()'�� ���� �ǹ��� �⺻ ������(default Constructor) �Լ� 
//       (= ������ ������ �� ū ���� ����)

//   # ������ �Լ� ����, ���ǹ�
//
//      1. �Ϲ����� �ʱ�ȭ ��� 
//          : �׳� void �Լ���� �����ϵ�, ������ �Լ��� �������� ��ü�� ������ ��ü�� ������� �ʱ�ȭ�� �ִٰ� �����ϸ� ����
//             -> Ŭ������(�ڷ��� parameter��...) { ������� = parameter ����ϰų� ������ �� }											
//                       
//                ex) class A ����� ������ ���� ���� ( int a; double b; char c; )
//                    
//                    A (int _a, double _b, char _c) {
//                        a = _a;
//                        b = _b;
//                        c = _a;
//                    }
//
//      2. �ʱ�ȭ ����Ʈ(Initialize List) 
//          : (�߿�!) �ݷ�(:)�� �̿��ϴ� �ʱ�ȭ��, ���Ǻκ��� �켱�Ͽ� ����ȴٴ� ������ �־�, const ��������� �ʱ�ȭ�� ����                        
//             -> Ŭ������(�ڷ��� parameter��...) : ����O �������(parameter��) , ...  { ����X ������� = parameter ����ϰų� ������ �� }												
//                                                            
//                ex) class A ����� ������ ���� ���� ( int a; double b; char c; )
//		          
//                    A (int _a, double _d, char _c) : a(_a), c(_c) {
//                        b = _b;
//                    }


//   # ����, ������ ������ �Լ� ���� �� ȣ���
//
//      1. defalut constructor
//
//        - defalut constructor ����
//           : (�߿�!) class�� �ƹ��͵� �� ��� ������ �⺻���� �����ϴ� parameter ���� �������Լ�
//              -> ��! ���Ǻδ� ����ֱ⿡, ������ �ʿ��ϸ� ä������
//
//        - defalut constructor ȣ���
//           : Ŭ������ * Ŭ���������͸� = new Ŭ������;     
//             Ŭ������ * Ŭ���������͸� = new Ŭ������();   
//
//             ex) point* ptr_pos_1 = new point;
//                 point* ptr_pos_1 = new point();
//
//      2. (�Ϲ�) constructor
//            
//        - (�Ϲ�) constructor ����
//           : defalut constructor �̿�, �����ε��� ������ �Լ� (= parameter ������ ���� �̷л� ���Ѱ��� �������Լ� ���� ������)
//              -> ������ parameter�� ������� ������ �����ϱ� ���� ���
//
//        - (�Ϲ�) constructor ȣ���
//           : Ŭ������* Ŭ���������͸� = new Ŭ������(parameter....);   
//
//             ex) point* ptr_pos_1 = new point(1, 1); 


// �ﰢ�� class�� ��������� �� ���̸� ���ϴ� �޼��带 ����ϴ� ������ ���� �����ִ� ������ ���� 3���� ���
#include <iostream>
using namespace std;

// �ﰢ�� class
class Triangle {

    public:

        double base, height;

        // 1. defalut constructor ����
        //  : (�߿�!) class�� �ƹ��͵� �� ��� ������ �⺻���� �����ϴ� parameter ���� �������Լ�
        Triangle() {

            // ��!���Ǻδ� ����ֱ⿡, ������ �ʿ��ϸ� ä������
            base = 0;
            height = 0;
            cout << "1. constructor call\n";
        }

        // 2. ������ {}�ȿ� parameter�� ���� ���� ����
        Triangle(double _base, double _height) {
            base = _base;
            height = _height;
            cout << "2. constructor call with parameter\n";
        }

        // 3. �ʱ�ȭ ����Ʈ(Initialize List)
        //  : (�߿�!) �ݷ�(:)�� �̿��ϴ� �ʱ�ȭ��, ���Ǻκ��� �켱�Ͽ� ����ȴٴ� ������ �־�, const ��������� �ʱ�ȭ�� ����
        //     -> Ŭ������(�ڷ��� parameter��...) : ����O �������(parameter��), ...  { ����X ������� = parameter ����ϰų� ������ �� }
        Triangle(double _base, double _height, int flag) : base(_base), height(_height) {
            cout << "3. constructor call with parameter (by Initialize List)\n";
            cout << "    -> flag �Ķ���ʹ� �⺻ ������ �Լ��� ������ ���� ���� ����ϴ�!\n";
        }

        // --------------------------------------- [���� �ʱ�ȭ �Լ��� ���� �ʱ�ȭ ��]------------------------------------------------
        void initialize();
        void initialize(double _base, double _height);
        //-------------------------------------------------------------------------------------------------------------------------

        double getArea() {
            return base * height / 2;
        }
};

// --------------------------------------- [���� �ʱ�ȭ �Լ��� ���� �ʱ�ȭ ��]------------------------------------------------
void Triangle::initialize() {
    base = 0;
    height = 0;
}

void Triangle::initialize(double _base, double _height) {
    base = _base;
    height = _height;
}
//-------------------------------------------------------------------------------------------------------------------------

int main() {

    double b, h;

    cout << "�غ� �Է� : ";
    cin >> b;

    cout << "���� �Է� : ";
    cin >> h;

    // 1. ���� Ŭ���� ���� ���� ��, �ʱ�ȭ �Լ��� ����� ������� �� ����  
    Triangle tri1;
    tri1.initialize(b, h);

    // 2. Ŭ���� �����ڸ� ���� ������� �� ������ Ŭ������ ��ü�� �����ϱ�
    Triangle tri2(b * 2, h * 3);
    Triangle tri3(b * 10, h * 10);

    cout << "�ﰢ�� tri1�� ���̴� " << tri1.getArea() << "�Դϴ�.\n";
    cout << "�ﰢ�� tri2�� ���̴� " << tri2.getArea() << "�Դϴ�.\n";
    cout << "�ﰢ�� tri3�� ���̴� " << tri3.getArea() << "�Դϴ�.\n";
    return 0;
}