//   # this포인터를 활용하기 유효한 경우
//      1. 멤버함수의 parameter가 멤버변수와 이름이 같은 경우
//          ex) class B {
//                 int i, j;
//                 void Set(int i, int j) {      <- 각각 멤버변수와 parameter의 이름이 i , j로 같음
//                    this->i = i;               <- this->i 라면 구분이 될 수 있으니 쉽게 해결 가능
//                    this->j = j; 
//                 }

//      2. 멤버함수에서 함수를 호출한 객체를 그 자체를 반환하는 경우
//          -> 하.. 이거 그 객체가 뭔지 내가 어떻게 알아? 라고 안하고
//             -> 해당 클래스 포인터변수 형식으로 객체의 주소값을 받는 this를 역참조한 객체값 *this을 return하면 됨! 

// this포인터를 활용하기 유효한 경우 1번의 예시
#include <iostream>
#include <iomanip>// setw

using namespace std;

class Telephone {

    private:
        int no;
        char name[20];
        char phone[20];

    public:

        Telephone() : no(0), name(""), phone("") {}

        Telephone(int no, const char* const name, const char* const phone) {

            this->no = no;

            strcpy_s(this->name, 20, name);
            strcpy_s(this->phone, 20, phone);

            cout << "Constructor complete" << endl;
        }

        int GetNo() const { 
            return this->no; 
        }

        const char* GetName() const {
            return this->name; 
        }

        const char* GetPhone() const {
            return this->phone; 
        }
};

int main() {
    char name[20], ph[20];
    cout << "** 전화번호부 **\n \n";
    cout << "이    름 : ";
    cin >> name;

    cout << "전화번호 : ";
    cin >> ph;

    //객체 생성시, 생성자 함수 사용 위한 parameter 전달   
    Telephone p(1, name, ph);    

    cout << " \n \n \t** 결과출력 **\n \n";
    cout << std::left << setw(5) << "No." << setw(20) << "이름" << setw(20) << "전화번호" << endl;
    cout << setw(5) << p.GetNo() << setw(20) << p.GetName() << setw(20) << p.GetPhone() << endl;

    return 0;
}

