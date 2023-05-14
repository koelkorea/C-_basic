// quiz : 객체 배열, 객체 포인터, 객체 포인터 개념과 생성자 함수를 이용
//  -> 학생의 이름, 전화번호를 멤버로 가지고 있는 Telephone 클래스에 해당하는 기능을 수행하는 코드를 완성 + 5명의 학생 객체를 저장하는 예제 프로그램을 작성
#include <conio.h>
#include <iostream>

using namespace std;

class Telephone {

    private:
        char name[20], phone[20];

    public:
        Telephone(char* pN, char* pP);
        void Show() const;
};

Telephone::Telephone(char* pN, char* pP) {

}

void Telephone::Show() const {

}

int main() {

    return 0;
}
