//   # string Ŭ������ Constructor(������)�� ����
//      -> ���ڿ� ������ ���� ���� ����

//      1. string ��ü��();
//          :  default �����ڷ� ���ڿ��� ����
// 
//      2. string ��ü��(const char* �����ͺ�����);
//          : �ش� char ������ ��ġ�� �����ϴ� "���ڿ� ���(\0)" �� �Է�
// 
//      3. string ��ü��(const char* �����ͺ�����, ����n or sizeũ���ڷ��� ������)	;
//          : �ش� char ������ ��ġ�� ���ڿ��� ���� ~ n������ �ʱ�ȭ
//            -> (�߿�) char ������ ��ġ�� ���ڿ� ���̰� �ʱ�ȭ�� ũ�� n���� �۾Ƶ� ��)
// 
//      4. string ��ü��(const string & ���۷���������);
//          : string Ŭ������ ���� ������
//            ->  �̹� �����ϴ� string ��ü�� ���ڿ� ������ ���� �����Ͽ� ����
// 
//      5. string ��ü��(const string & ���۷���������, index�ڷ��� begin, index�ڷ��� end = npos)	
//          : string Ŭ������ ���� ������ Ȯ����
//            -> �̹� �����ϴ� string ��ü�� ���ڿ� ������ index�� begin ~ end������ �ش��ϴ� ���ڵ鸸 ���� �����Ͽ�, ���� �����Ͽ� ����
//                ex) string ex(str, 3, 4) == str[3] ~ str[4] = ex�� ���ڿ�
// 
//      6. string ��ü��(����n or sizeũ���ڷ��� ������, char ������);
//          : ���� C�� n���� ������ ���ڿ��� �����Ͽ� �ʱ�ȭ�� string ��ü ����
// 
//      7. string ��ü��(const char* ���������ͺ�����, const char* ���������ͺ�����)	
//          : ���������ͺ����� ��ϵ� char ������ ��ġ�� �������� ���������ͺ����� ��ϵ� char ������ ��ġ�� ������ �� ���ڿ� ������ ���� �����Ͽ� �����ϴ� string ��ü ����
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex�� ���ڿ�
// 
//      8. string ��ü��(Iterator begin, Iterator end)	
//          : (template <value�ڷ��� �����̳ʿ�Ҹ�> ���� �ʿ�) Iterator begin�� ��ϵ� char ������ ��ġ�� �������� Iterator end ��ϵ� char ������ ��ġ�� ������ �� ���ڿ� ������ ���� �����Ͽ� �����ϴ� string ��ü ����
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex�� ���ڿ�
//                  -> Iterater : ������ó�� ����ϴ� �ݺ��� class������ �����ϸ� ��


//   # string::npos�� �ǹ�
//      :  find() �Լ� ���� �ÿ� ã�� ���ڿ��� ���� �� ��ȯ�Ǵ� ��� -1�� �ǹ�


// string ������ ���� �����ڵ�
#include <iostream>
#include <string>
using namespace std;

int main() {// ������ 

    char ary[] = "The sun will shine on us again.";

    // 1. string()
    //  -> str1 == str1() == ''
    string str1;

    // 2. string(const char * const s)
    //  -> str2(ary) == 'hi!'
    string str2("hi!");

    // 3. string(char * s)
    //  -> str_2(ary) == 'The sun will shine on us again.'
    string str_2(ary);

    // 4. string(const string &str)
    //  -> str3(str2) == 'hi!'
    string str3(str2);

    // 6. string(size_type n, char c);
    //  -> str4(5, 'k') == 'kkkkk'
    string str4(5, 'k');

    // 7. string(const char* s, size_type n)
    //  ->  str5("Korea", 10) == 'Korea'
    string str5("Korea", 10);

    // 8. string(Iter begin, Iter end),(char* begin, char* end)
    //  -> str6(ary + 4, ary + 24) == 'sun will shine on us'
    string str6(ary + 4, ary + 24);

    // 9. string(const string& str, size pos, size n=npos)
    //  -> str7(str_2, 4, 14) == 'sun will shine'
    string str7(str_2, 4, 14);

    // 10. string(const char * str, size pos, size n=npos)
    //  -> str_7("new world string", 4, 5) == 'world'
    string str_7("new world string", 4, 5);

    cout << "=======================================" << endl;
    cout << "str 01  " << str1 << endl;
    cout << "str 02  " << str2 << endl;
    cout << "str 002 " << str_2 << endl;
    cout << "str 03  " << str3 << endl;
    cout << "str 04  " << str4 << endl;
    cout << "str 05  " << str5 << endl;
    cout << "str 06  " << str6 << endl;
    cout << "str 07  " << str7 << endl;
    cout << "str 007 " << str_7 << endl;
    cout << "=======================================" << endl;
    return 0;
}