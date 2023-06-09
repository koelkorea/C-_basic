// ���� ����
//  : class ��ü �� ��ü���� ��� �� ��� 1:1�� ����
//     -> (�߿�) class ��ü�� ������ ���� �����°� �ƴ϶�, �޸��� ���������� ��ü�� ����� ��ġ���� �����ϴ� class �����ͺ���
//         -> ���� ������ ��ġ ���ٸ�, ��ü �� �ܼ��� ����� class������ �ּҰ��� ���� �����Ͽ�, ���� ��ġ�� ������ �������ϰڴٴ� �ǹ̰� �Ǿ������!
//             -> �Ҹ��ڷ� �� �� �ϳ��� �����ص� ������ �ϳ��� ������ �������� �Ǿ����.. (= dangled pointer �̽�)

//   # dangled pointer (���� ������ ����)
//     : �������� ��� �������� ����� ����ϸ� ���� �޸� �ּҰ����� ���� �ٸ� �����Ͱ� ����Ŵ
//        -> �̸� �Ҹ��� 'delete �����ͺ���'�� ���� ���� �޸� ������, �ٸ� �����ͺ����������� �� �ּҰ��� ���⿡, ���� �޸𸮸� �� �� �����ϸ� ���� �߻�!
//           -> (�ذ�å) ��ü �� ���翡�� ��ü�� �����ʹ� ��� ��ü�� �ּҰ��� �����ϴ� ���X -> �����Ͱ� ����Ű�� �޸𸮸�ŭ ���� �Ҵ� �޾� �����ؾ� �� (= ���� ������ ź��)

// ���� ����
//  : dangled pointer �̽� �ذ� ����, �����ϴ� class ��ü�� ����Ű�� �ּҿ� ��ġ�� ��ü�� �޸� ũ�⸸ŭ�� ������ ���� ���� ���� �Ҵ��Ͽ� ��ü�� ����������� ������ �����ϴ� ���
//     -> �̷��� �ϸ�, ����� ��ü�� ��� �������� ���� ��� ��ü�� ������, �������� ��ü �����Ͱ� ��ġ�� �ּҰ� �ٸ��⿡ ������ ��� ��ü�� ������� ������ ���� �ʴ� �������� ����!


// class ��ü �� �����
//  : class�� �ν��Ͻ���ü��1(�ν��Ͻ���ü��2)   or  class�� �ν��Ͻ���ü��1 = �ν��Ͻ���ü��2
//     -> =������ �����ε��� ���� �����ϰ� ��

//     1. �ڵ������� �����Ǵ� ���� �����ڿ� �ƹ��� ��ġ�� ������ �ʾ��� ���
//         -> ���� ���� �۵�
       
//            ex) MyString s3 = s1;     =>      s3�� ����Ű�� ��ü ��ġ == s1�� ����Ű�� ��ü ��ġ    
//                MyString s3(s1)
       
//     2. ���� �������� ���뿡 ���� �޸� �Ҵ��� ���� ���� ��ü�� ������ ������ ������ �������� ��ġ�ϵ��� ��ġ�� ���
//         -> ���� ���� �۵�
       
//            ex) MyString s3 = s1;     =>      s3�� ����Ű�� ��ü ��ġ != s1�� ����Ű�� ��ü ��ġ      
//                MyString s3(s1)


// ���� ������ ������ �̸� �ذ��� ���� ���� �ڵ� (���� ������ dangled pointer �̽� �ذ�)
#include <iostream>

using namespace std;

//----------------------------------------[���� ����]----------------------------------------------------------------------
class MyString_swallowCopy {
private:
    char* pStr;
public:
    MyString_swallowCopy(char* p);
    ~MyString_swallowCopy();
    void Show() const;

};

// ������
MyString_swallowCopy::MyString_swallowCopy(char* p) {
    pStr = new char[strlen(p) + 1];
    strcpy_s(pStr, strlen(p) + 1, p);
    cout << "������ ȣ��\n";
}

// �Ҹ���
MyString_swallowCopy::~MyString_swallowCopy() {
    delete[]pStr;
    cout << "�����޸� ����\n";
}

void MyString_swallowCopy::Show() const {
    cout << pStr << endl;
}


//----------------------------------------[���� ����]----------------------------------------------------------------------
class MyString_deepCopy {
private:
    char* pStr;
public:
    MyString_deepCopy(char* p);
    ~MyString_deepCopy();
    MyString_deepCopy(const MyString_deepCopy& MyString);
    void Show() const;

};

// ������
MyString_deepCopy::MyString_deepCopy(char* p) {
    pStr = new char[strlen(p) + 1];
    strcpy_s(pStr, strlen(p) + 1, p);
    cout << "������ ȣ��\n";
}

// �Ҹ���
MyString_deepCopy::~MyString_deepCopy() {
    delete[]pStr;
    cout << "�����޸� ����\n";
}

// ���� ���� ������
//  : �ش� class��ü�� ���۷��� ��ü�� �Ķ���ͷ� �޴� ���� �����ڰ� �����ϸ�?
//     -> ��ü ����� �ٸ� ��ü�� ������ �ʱ�ȭ�� �ش� ���� ������ �Լ��� ȣ��� 
//        -> �� �ܿ� �ش� class��ü�� ����Լ��� paramter�� �ش� ��ü ��ü�� �����ϴ� ���, call by value�� ���� �Լ� {}�� ���� �����ϱ� ���� ������ class ��ü�� ����� ���� ���� �����Ͽ� �Լ����� ����  
MyString_deepCopy::MyString_deepCopy(const MyString_deepCopy& string) {
    pStr = new char[strlen(string.pStr) + 1];
    strcpy_s(pStr, strlen(string.pStr) + 1, string.pStr);
    cout << "pStr �����Ͱ� ����Ű�� �����޸� ��� ���� -> ���� ���� �����ϴ� ���������\n";
}
void MyString_deepCopy::Show() const {
    cout << pStr << endl;
}


int main() {

    //----------------------------------------[���� ����]----------------------------------------------------------------------
    MyString_swallowCopy s1 = (char*)"Hello World";       // (�߿�!) s1�� �����Ҷ�, s3�ּ� �̹� ���� �ּҰ��� ��ġ�� �޸� ������ �����Ͽ��⿡ dangling pointer �� ���� �����߻�
    MyString_swallowCopy s2 = (char*)"C++ language";
    MyString_swallowCopy s3 = s1;                         // �ƹ� ������ ���� default ���� �����ڸ� �����ϹǷ�, ���� ���縦 ������ 

    s1.Show();
    s2.Show();
    s3.Show();

    //----------------------------------------[���� ����]----------------------------------------------------------------------

    // = MyString s1((char*)"Hello World");
    MyString_deepCopy s4 = (char*)"Hello World";

    // = MyString s1((char*)"C++ language");
    MyString_deepCopy s5 = (char*)"C++ language";
    MyString_deepCopy s6 = s4;                            // ���� ���� �����ڰ� ȣ��Ǿ� ����     

    s4.Show();
    s5.Show();
    s6.Show();

    return 0;
}

