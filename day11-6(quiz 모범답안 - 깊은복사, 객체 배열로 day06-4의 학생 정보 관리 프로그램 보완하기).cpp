// [모범답안]
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
    strcpy_s(name, strlen(pN) + 1, pN);
    strcpy_s(phone, strlen(pN) + 1, pP);
}

void Telephone::Show() const {
    cout << "이름 : " << name << "\t전화번호 : " << phone << endl;
}

int main() {

    //객체 포인터 배열
    Telephone* pT[5]; 

    //포인터명 - pT[0], pT[1], pT[2], pT[3], pT[4]
    char name[20], phone[20];
    cout << "\n ** 전화번호 입력 ** \n";

    for (int i = 0; i < 5; i++) {
        cout << "\n이    름 : ";
        cin >> name;
        cout << "전화번호 : ";
        cin >> phone;
        pT[i] = new Telephone(name, phone); //동적객체 생성 시 인수 전달
    }

    cout << "\n\n\t** 전화번호 출력**\n\n";

    for (int i = 0; i < 5; i++) {

        //객체주소->멤버 (객체.멤버)
        pT[i]->Show();
    }
        
    cout << endl << endl;

    // [] - 포인터가 가리키는 메모리가 배열인 경우
    for (int i = 0; i < 5; i++) {  

        //delete 포인터;
        delete /*[]*/ pT[i];   
        cout << "동적 메모리 해제\n";
    }
    return 0;
}
