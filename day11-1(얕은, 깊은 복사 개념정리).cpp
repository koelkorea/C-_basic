// 얕은 복사
//  : class 객체 대 객체간의 멤버 대 멤버 1:1로 복사
//     -> (중요) class 객체는 스스로 값을 가지는게 아니라, 메모리의 힙영역에서 객체의 저장된 위치값을 저장하는 class 포인터변수
//         -> 따라서 별도의 조치 없다면, 객체 간 단순한 복사는 class포인터 주소값을 같게 복사하여, 같은 위치의 값들을 역참조하겠다는 의미가 되어버린다!
//             -> 소멸자로 둘 중 하나만 해제해도 나머지 하나는 낙동강 오리알이 되어버림.. (= dangled pointer 이슈)
// 
//   # 얕은 복사법
//      -> 클래스명 인스턴스명 = 타 인스턴스명	

//         ex) MyString s3 = s1;     =>      s3이 가리키는 객체 위치 -> 힙영역의 객체위치 <- s1이 가르키는 객체 위치                 

//   # dangled pointer (얕은 복사의 문제)
//     : 포인터의 경우 얕은복사 방식을 사용하면 같은 메모리 주소값을를 서로 다른 포인터가 가리킴
//        -> 이를 소멸자 'delete 포인터변수'를 통해 동적 메모리 해제시, 다른 포인터변수명이지만 그 주소값은 같기에, 같은 메모리를 두 번 해제하며 오류 발생!
//           -> (해결책) 객체 간 복사에서 객체의 포인터는 대상 객체의 주소값을 복사하는 방식X -> 포인터가 가리키는 메모리만큼 동적 할당 받아 복사해야 함 (= 깊은 복사의 탄생)

// 깊은 복사
//  : dangled pointer 이슈 해결 위해, 복사하는 class 객체가 가르키는 주소에 위치한 객체의 메모리 크기만큼의 영역을 따로 떼어 동적 할당하여 객체의 멤버변수들의 내용을 복사하는 방식
//     -> 이렇게 하면, 복사된 객체는 모든 데이터의 값은 대상 객체와 같더라도, 힙영역에 객체 데이터가 위치한 주소가 다르기에 원본인 대상 객체가 사라져도 영향을 받지 않는 독립성을 유지!

//얕은 복사의 문제와 이를 해결한 깊은 복사 코드 (얕은 복사의 dangled pointer 이슈 해결)
#include <iostream>

using namespace std;

//----------------------------------------[얕은 복사]----------------------------------------------------------------------
class MyString_swallowCopy {
    private:
        char* pStr;
    public:
        MyString_swallowCopy(char* p);
        ~MyString_swallowCopy();
        MyString_swallowCopy(const MyString_swallowCopy& MyString);
        void Show() const;

};

MyString_swallowCopy::MyString_swallowCopy(char* p) {//생성자
    pStr = new char[strlen(p) + 1];
    strcpy_s(pStr, strlen(p) + 1, p);
    cout << "생성자 호출\n";
}

MyString_swallowCopy::~MyString_swallowCopy() {//소멸자
    delete[]pStr;
    cout << "동적메모리 해제\n";
}

MyString_swallowCopy::MyString_swallowCopy(const MyString_swallowCopy& string) { //깊은 복사 생성자
    pStr = new char[strlen(string.pStr) + 1];
    strcpy_s(pStr, strlen(string.pStr) + 1, string.pStr);
    cout << "pStr 포인터가 가리키는 동적메모리 모두 복사 -> 깊은 복사 수행하는 복사생성자\n";
}

void MyString_swallowCopy::Show() const {
    cout << pStr << endl;
}


//----------------------------------------[깊은 복사]----------------------------------------------------------------------
class MyString_deepCopy {
private:
    char* pStr;
public:
    MyString_deepCopy(char* p);
    ~MyString_deepCopy();
    MyString_deepCopy(const MyString_deepCopy& MyString);
    void Show() const;

};
MyString_deepCopy::MyString_deepCopy(char* p) {//생성자
    pStr = new char[strlen(p) + 1];
    strcpy_s(pStr, strlen(p) + 1, p);
    cout << "생성자 호출\n";
}
MyString_deepCopy::~MyString_deepCopy() {//소멸자
    delete[]pStr;
    cout << "동적메모리 해제\n";
}
MyString_deepCopy::MyString_deepCopy(const MyString_deepCopy& string) { //깊은 복사 생성자
    pStr = new char[strlen(string.pStr) + 1];
    strcpy_s(pStr, strlen(string.pStr) + 1, string.pStr);
    cout << "pStr 포인터가 가리키는 동적메모리 모두 복사 -> 깊은 복사 수행하는 복사생성자\n";
}
void MyString_deepCopy::Show() const {
    cout << pStr << endl;
}


int main() {

    //----------------------------------------[얕은 복사]----------------------------------------------------------------------
    MyString_swallowCopy s1 = (char*)"Hello World";  //MyString s1((char*)"Hello World");
    MyString_swallowCopy s2 = (char*)"C++ language"; //MyString s1((char*)"C++ language");
    MyString_swallowCopy s3 = s1;   //깊은 복사 생성자
    s1.Show();
    s2.Show();
    s3.Show();

    //----------------------------------------[깊은 복사]----------------------------------------------------------------------
    MyString_deepCopy s4 = (char*)"Hello World";  //MyString s1((char*)"Hello World");
    MyString_deepCopy s5 = (char*)"C++ language"; //MyString s1((char*)"C++ language");
    MyString_deepCopy s6 = s4;   //깊은 복사 생성자
    s4.Show();
    s5.Show();
    s6.Show();

    return 0;
}

