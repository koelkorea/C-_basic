// string Ŭ����
//  : �� ���� char[] �������� �����ϴ��� �����°� ��ٷο���, ���ڿ��� ���������� ��ü�� ����ϱ� ���� ���۵� namespace std���� class Ÿ��


//C style
//char str[15] = "Hello World!(\0)"
//(ū ����ǥ : "���ڿ� ���(\0)", ���� ����ǥ : '���� ��� ��')

//C++ style
//string str1("Hello World!"), str2 = "Hello World!";

//#include <string>
//namespace std {
//    class string {
//        unsigned __int64 size;         <- ����� ���ڿ��� ���� = 2^64���� ���ڿ�
//        unsigned __int64 capacity;     <- ���� ������ �� �뷮 = 2^64���� ���ڿ�
//        allocator<char> allocator;     <- �迭�� ���� �޸� �Ҵ� �� ������ ����
//    };
//}

//Constructor(������)

//Constructor(������)	�ǹ�
//��ü��()	ũ�Ⱑ 0�� default ������
//��ü��(const char* s)	"���ڿ� ���(\0)"
//��ü��(const string & str)	string ��ü�� ���� ������
//��ü��(size_type n, char c)	���� C�� n�� ������ ���ڿ�
//��ü��(const char* s, size n)	���ڿ� ������� n������ �ʱ�ȭ
//s�� ���ڿ� ���� < n ����
//    template<class Iter>
//��ü��(Iter begin, Iter end)	begin �� ���ڿ� < end �ʱ�ȭ
//    Iterater : �ݺ���, ������
//    ��ü��(const string& str, size pos, size n = npos)	str[pos] �� ���ڿ� < str[n]


//String(���ڿ�) �Է�

//C style
// : char �ڷ��� �迭 ����� ���ڿ� �Է�(= �⺻�����δ� �����Ҵ�)
//char name[15];
//cin >> name; // ���鹮�� ������ 14(+'\0')�� ���� ����. [ ť�� '\n' ���� ]
//while (cin.get() != '\n');
//cin.get(name, 15); // 1�� �Է� �ޱ� [ ť�� '\n' ���� ]
//cin.getline(name, 15); // 1�� �Է� �ޱ� [ '\n'(Enter) ���� ]
//cin.getline(name, 15, ':'); // 1�� �Է� �ޱ� [ ':' ���� ]

//C++ style
// : string class�� ���� ���ڿ� �Է� (= �����Ҵ�)
// 
//�Է� ���� ���ڿ� �ڵ� ũ�� ����
//string fullname;
//cin >> fullname; // ���鹮�� ������ ���� ����. [ ť�� '\n' ���� ]
//while (cin.get() != '\n');
//getline(cin, fullname); // 1�� �Է� �ޱ� [ '\n'(Enter) ���� ]
//getline(cin, fullname, ':'); // 1�� �Է� �ޱ� [ ':' ���� ]

//���� ��� : unsigned __int64(2 ^ 64)���� ������ ���ڿ� ����, �޸� ũ��


// String(���ڿ�)�� Method(��� �Լ�) = ��ü.Method();

//  - ���ڿ��� Ư�� ��ġ�� ���� ��ȯ
//    1. char& at(size_t n)
//        : ���ڿ� nĭ ��ȯ (0 �� ���ڿ� < End)
//    2. char& operator[] (size_t n)
//        : ���ڿ� nĭ ��ȯ(0 �� ���ڿ� < End)
//    3. char& front()
//        : ���ڿ�[0]ĭ�� �ش��ϴ� �κ��� ���� ��ȯ
//    4. char& back()
//        : ���ڿ�[End]ĭ�� �ش��ϴ� �κ��� ���� ��ȯ

//���ڿ� ���� ���� ��ȯ
//size_t size() const == size_t length() const : ���ڿ� ���� ��ȯ
//void resize(size_t n) : ���ڿ� ���� n�� ����(str.size() < n : ����, n < str.size() : ����)void resize(size_t n, char c) : ������ ���� c�� ����
//string substr(size_t st = 0, size_t len = npos) const : st���� len�� ��ȯ
//string & replace(size_t st, size_t len, const string & str) : st~len ��ġ�� str ���� �ֱ�
//bool empty() const : ������� Ȯ���ϴ� �Լ�(size == 0 : true)

//���ڿ� ����(���� �ٲٱ� or �߰� or ����)
//void clear() : ���ڿ��� ����� �Լ�(capacity ����)
//iterator erase(iterator st, iterator end) : st~end ���ڿ� ����
//iterator erase(iterator iter) : ���ڿ�[iter] ����
//string & erase(size_type offset = 0, size_type count = npos) : offset���� count�� ����
//void push_back(char c) : �� �ڿ� ���� c �߰� �Լ�
//void pop_back() : �� �ڿ� �ִ� ���� 1�� ���� �Լ�

//���ڿ� �޸�
//size_t capacity() const; ���ڿ� ���� ������ �뷮(�޸� ũ��, bytes) ��ȯ
//void shrink_to_fit() : capacity(�޸�)�� ���̴� �Լ�
//void reserve(size_t n = 0) : capacity�� �Ҵ� �Լ�(�޸� Ȯ��)

//C style ��ȯ
//const char* c_str() const : ���ڿ�(+\0) ��� ��ȯ[C style]
//const value_type* data() const noexcept; ���ڿ��� null�� ������ ���� �迭�� ��ȯ
//value_type* data() noexcept;

//���ڿ� ó��
//int compare(const string& str2) const : ���ڿ� ��(��ü.���� : > +, = 0, < -��ȯ)
//int compare(size_t st, size_t len, const string& str2) const
//int compare(size_t st, size_t len, const string& str2, size_t st2, size_t len2) const
//void swap(string& str1, string& str2) : str1�� str2�� ��ȯ
//size_t copy(char* arr, size_t len, size_t st = 0) const : ����, ����� ���� ��ȯ
//size_t find(const string& str, size_t st = 0) const : ��ü �� ���ڿ� �˻�, �ε��� ��ȯ
//size_t find(const char* arr, size_t st = 0) const : ��ü �� ���ڿ� �˻�, ���� npos ��ȯ

//���ڿ� ��ġ ���� iterator(�ݺ���, ������ �ּ�)
//const_iterator begin() const : ��ü[0]�� �ּ� ��ȯ[�ݺ���(iterator ������)]
//const_iterator end() const : ��ü[End + 1] �ּ� ��ȯ[�ݺ���(iterator ������)]

//���ڿ� ������ �����ε�
//String + String
//string & operator+(char _ch) :
//string & operator+(const char* const _ptr) :
//string & operator+(const string & _Right) :
//string & operator+(initializer_list<char> &_ilist) :
//String = String
//string & operator=(char _ch) :
//string & operator=(const char* const _ptr) :
//string & operator=(const string & _Right) :
//string & operator=(initializer_list<char> &_ilist) :
//String[n]
//char& operator[] (const size_t n) :
//const char& operator[] (const size_t n) const :




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
