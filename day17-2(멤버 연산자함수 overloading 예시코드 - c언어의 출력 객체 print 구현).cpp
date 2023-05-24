// ������ �����ε� (operlator overloading)
//  : (�߿�!) �Ϲ������� ���� ������ ���� ����ϴ� ������(+, -, / ...)�鵵 ����� 'operator������'��� �Լ����� ������ �ִ� �Լ��� ����
//     -> �� �༮���� ����ο� parameter�� �������� ����ڰ� �ۼ��� class ��ü���� ����ؼ� overloading��? ������!!!
//        (= ����ڴ� ������ �ڷ����� ����� ������ �ܿ���, class ��ü�� ����� �� �����ڸ� Ȱ���� ���� ��Ģ�� â���� �� ����!!)


//   # �������� ����
// 
//      1. �����ε� �Ұ����� ������
//         - .                 : class ��ü�� ��������� �����϶�� �ǹ�
//         - .*                : class ��ü�� ��� ������
//         - ::                : ���� ������
//         - ? true : false    : 3�� ������
//         - sizeof            : ������ ��ü�� Byte ũ�� ���
//         - typeid            : ������ ��ü�� �ڷ����� �����ϴ� RTTI ������
//         - static_cast       : type ���� casting
//         - dynamic_cast      : type ���� casting
//         - const_cast        : type ��� casting
//         - retinterpret_cast : ������ type���� casting ��� 

//      2. class�� ����Լ��θ� �����ε� ���� ������
//         - =   : ���� ������
//         - ()  : �Լ� ȣ�� ������
//         - []  : �迭 ���� ������
//         - ->  : �������Ͽ� class ��ü ������� ���� ������ ������

//      3. �� �� ��κ��� �����ڴ� ��Ʈ������(<<, >>), ���� ������(++, --) �����ؼ� overloading ����
//          -> (�߿�) istream, ostream class�� ��ü�� std�� cin, cout ��ü ���� �� ������ overloading


//   # ������ �Լ�(operator function)�� Ư¡
// 
//      1. �������� �Լ����� [operator + '������'] �������� �̷���

//         ex) operator+(), operator*(), operator>>()

//      2. (�߿�!) ���� ���� '����(��ü) + ����(��ü)'�� ���� �����ڴ� �������Լ��� ȣ���ڵ带 ���߸� ���̴�

//         ex) ��ü1.operator+(��ü2)  ->   ��ü1 + ��ü2

//      3. (�߿�!) �������Լ��� ȣ������ �ʰ�, �����ڸ��� ���� ���ȣ���� �� ��쿡 �װ��� � class�� ����������Լ� ȣ������? �����������Լ� ȣ������ ��� �����ϰ�, �켱���� �ֳ�?
//          -> � ���� �ϴ� ����������Լ��� �ش��ϴ� ������ �ִ��� ã�ƺ� �켱���� �ο���

//          - ������ ��� ȣ���, ȣ���� �������Լ� ã�� ���� ����
//             a. ����, ������ 1��°�� ���̴� ����� �ڷ����̳� class���� �������� ���� 
//             b. �� class�� ����������Լ� �� parameter�� ���� �ڷ������ ������ 2��° ������ ����� �ڷ����̳� class�� ������ ����ΰ� �ִ��� üũ��
//             c. ���⼭ parameter ������ 2��° ������ �������� �ڷ��� ������ ��ġ�ϴ� ����������Լ� �Լ��� �����ϴ°�?
//                 -> YES : ����������Լ� �������� ȣ�� 
//                    NO  : �����������Լ��� �������� �ִٸ�, �����������Լ��� ȣ���� (������, ������ �ܰ迡�� ������ �����)     


// [��� �������Լ� overloading �����ڵ�]
// stream Ŭ������ cout ��ü�� ��Ʈ������ <<�� operlator overloading�� ����Ͽ� �������� �����ڵ�
//  -> �̸� ���� print ��ü�� console ��±���� ��Ʈ�����ڸ� ���� ���� ���� ����
#include <stdio.h>

// namespace std; == namespace psk;
namespace psk {

    class o_str {

        public:
            // o_str class�� ��� �������Լ� operator<<�� �پ��� ������ case�� ���� ����� overloading�� 

            // o_str class ��ü�� char�����͸� �̿��� ���ڿ� 2��° ������(paramter)���� �־� ��Ʈ������ <<�� ���� �����ϴ� ����Լ� operator<<() 
            //  -> �� ��� printf("%s", str) �� ���ڿ��� consoleâ�� ����ϰ�, o_str class��ü �ڽ��� ��ȯ��
            o_str& operator<<(const char* const str) {
                printf("%s", str); 
                return *this; 
            }

            // o_str class ��ü�� int ���� 2��° ������(paramter)���� �־� ��Ʈ������ <<�� ���� �����ϴ� ����Լ� operator<<() 
            //  -> �� ��� printf("%d", i) �� ���ڸ� consoleâ�� ����ϰ�, o_str class��ü �ڽ��� ��ȯ��
            o_str& operator<< (int i) {
                printf("%d", i);
                return *this; 
            }

            // o_str class ��ü�� double ���� 2��° ������(paramter)���� �־� ��Ʈ������ <<�� ���� �����ϴ� ����Լ� operator<<() 
            //  -> �� ��� printf("%f", d) �� ���ڸ� consoleâ�� ����ϰ�, o_str class��ü �ڽ��� ��ȯ��
            o_str& operator<< (double d) {
                printf("%f", d);
                return *this
            }

            // o_str class ��ü�� char�� �̿��� ���ڸ� 2��° ������(paramter)���� �־� ��Ʈ������ <<�� ���� �����ϴ� ����Լ� operator<<() 
            //  -> �� ��� printf("%c", c) �� ���ڿ��� consoleâ�� ����ϰ�, o_str class��ü �ڽ��� ��ȯ��
            o_str& operator<< (char c) {
                printf("%c", c);
                return *this; 
            }
    };

    // class ���ο��� o_str �ڽ��� ��ü�� �̸� ���� 
    //  -> �̸� ���� cout ��� print�� �ᵵ ��
    o_str print;

    // class ���ο��� char�����ͺ��� endline�� ���� �� �ٲ� ���ڿ� "\n"�� ���� ����ϵ��� ��
    //  -> �̸� ���� endl��� endline�� �ᵵ "\n"�� ����ϰ� ��
    const char* const endline = "\n"; 
}

// namespace std; == namespace psk;
using namespace psk; 

// using ��ɾ ���� psk::endline�� ���� �ʾƵ�, �ٷ� psk namespace������ endline�̶�� ������ ���� ���� (= endl �Ƚᵵ ��)
using psk::endline; 

// using ��ɾ ���� psk::endline�� ���� �ʾƵ�, �ٷ� psk namespace������ print�̶�� ������ ���� ���� (= cout �Ƚᵵ ��)
using psk::print; 

int main() {

    // full�������Լ� ȣ������� �ٲܽ�
    //  -> print.operator<<("Hello World").(", ").(3.14).(", ").(endline (= "\n") ); �� ����
    print << "Hello World" << ", " << 3.14 << ", " << endline;

    // full�������Լ� ȣ������� �ٲܽ�
    //  -> print.operator<<(100).(", ").('3.14).('Q').(endline (= "\n") ); �� ����
    print << 100 << ", " << 'Q' << endline;

    return 0;
}
