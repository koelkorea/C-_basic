// 가상 소멸자 함수(Virtual destructor function)
//  : 가상 함수의 원리를 적용하여, up casting하여 생성된 자식 class객체를 생성당시 사용한 부모 class포인터로 지울수 있게 하는 소멸자 함수
//     -> 사용하게 될 시, 상속 관계 계층 구조상 최후손 클래스 소멸자부터 최상위 클래스 소멸자까지 모두 호출하게 되어 모두를 지우게 하는 원리
//
//   # 가상 소멸자 함수(Virtual destructor function) 형식
//      : virtual ~클래스명() {  내용  };
//         -> 최상위 class 소멸자에만 virtual을 추가로 선언해도, 하위 class 까지 모두 가상 소멸자 적용되게 설계함


// day 13-10 예시코드를 가상 소멸자 함수 적용하여 수정한 예시
#include <iostream>
#pragma warning (disable : 4996)

using namespace std;

class Person {

    private:
        char* name;

    public:
        Person(const char* pN) { name = new char[strlen(pN) + 1]; strcpy(name, pN); cout << "\nPerson 생성"; }
        virtual ~Person() { cout << "\nPerson 소멸\n"; delete[] name; }
        virtual void show() { cout << "\n\n이름 : " << name; }
};

class Custom : public Person {

    private:
        char* phone;
        char* nationality;

    public:
        Custom(const char* pN, const char* pP, const char* pNa) : Person(pN) {
            phone = new char[strlen(pP) + 1];
            strcpy(phone, pP);
            nationality = new char[strlen(pNa) + 1];
            strcpy(nationality, pNa);
            cout << "\nCustom 생성";
        }
        ~Custom() { cout << "\nCustom 소멸"; delete[] phone, nationality; }
        void show() { Person::show(); cout << "\n번호 : " << phone << "\n주소 : " << nationality << endl; }
};

int main() {
    Person* c1 = new Custom("michelin", "010-1234-5678", "South Korea");
    c1->show();
    delete c1;
    return 0;
}
