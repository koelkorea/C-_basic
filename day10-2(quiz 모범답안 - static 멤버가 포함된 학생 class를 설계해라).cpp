// [quiz 모범답안]
// static 멤버변수, 멤버함수가 포함된 student class를 설계해라, 조건은 다음과 같음
 
// 1. private멤버변수
//     - 학번
//     - 이름
//     - 나이
//     - 학생수 (static 멤버변수)

// 2. public 멤버함수
//     - student 생성자           : 학번은 20230000부터 차례로 1씩 증가 되도록 구현
//     - (const) print_info()     : 학생 정보 출력
//     - (static) print_std_cnt() : 학생 수 출력

#include <iostream>
#include <iomanip>

using namespace std;

class Student {

    private:
        int no;
        char name[20];
        int age;
        static int studentNum;  //학생수(정적멤버변수)

    public:

        static int GetStudentNum(); //정적멤버함수
        Student() : no(0), name(""), age(0) {} //initializer lists
        Student(const char* const name, int age) {
            this->no = 20230000 + studentNum;
            ++studentNum;
            strcpy_s(this->name, 20, name);
            this->age = age;
            cout << "생성자 초기화\n";
        }
        int GetNo() const { return no; }
        const char* GetName() const { return name; }
        int GetAge() const { return age; }
        void print_info() const;
        void print_std_cnt() const;
        void SetName(const char* const name) { strcpy_s(this->name, 20, name); }
        void SetAge(int age) { this->age = age; }
};

int Student::studentNum = 0; //정적멤버변수 초기화

int Student::GetStudentNum() {
    return studentNum;
}

void Student::print_info() const {
    cout << std::left << std::setw(10) << "학번" << std::setw(20) << "이름" << std::setw(5) << "나이" << endl;
    cout << std::setw(10) << this->GetNo() << std::setw(20) << this->GetName() << std::setw(5) << this->GetAge() << endl << endl;
}

void Student::print_std_cnt() const {
    cout << "전체 학생 수는 " << Student::GetStudentNum() << "명 입니다.\n";
}

int main() {
    cout << "전체 학생 수는 " << Student::GetStudentNum() << "명 입니다.\n"; //정적멤버는 클래스명으로 접근 가능
    Student st1("michelin", 20);              st1.print_std_cnt();
    Student st2("christopher", 21);           st1.print_std_cnt();
    Student st3("charlie puth", 22);          st1.print_std_cnt();

    st1.print_info();    st2.print_info();    st3.print_info();

    st1.SetName("bruno mars");    st2.SetAge(23);
    cout << "\n\n정보를 수정했습니다.\n";
    st1.print_info();
    st2.print_info();
    st3.print_info();
    return 0;
}

