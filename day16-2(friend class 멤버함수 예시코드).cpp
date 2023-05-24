//   # friend 사용 대상에 따른 접근범위
//      : 그냥 friend 걸린 대상은 호출되거나 선언될 시 friend 선언해준 class 내부를 public 영역마냥 휘젓고 다닌다로 이해하면 됨
// 
//      1. 어떤 class의 멤버함수에 해당하는 대상만 특정 class의 friend로 규정하여 사용하는 경우
//          : 어떤 class의 특정 멤버함수만 필요하다면..? 
//             -> 그 멤버함수만 friend로 선언하여, 호출될 시 해당 class 자신의 private 영역에 접근할 수 있도록, 접근 허용 범위를 줄임
// 
//            # friend 멤버함수 코드 작성 위치 및 순서
//               (1) friend로 규정될 예정인 멤버함수를 포함한 '외부 class' 부터 위치
//               (2) 해당 멤버함수를 friend라고 선언할 '해당 class'가 위치
//               (3) friend 멤버함수의 정의부를 외부로 돌려 위치해두고, 내용을 입력함
// 
//            # friend 멤버함수 작성시 선행 순서가 중요한 이유?            
//               1. 대상이 되는 class의 멤버함수가 먼저 존재해야, 외부 class에서 friend로 선언할때 컴파일러가 '걔가 그래서 누군데?'라고 error룰 뿜지 않음..
//                   -> 변수를 사용하기 위해서는 먼저 상단에 선언이 되어야 하는것과 다른게 1도 없음
//               
//               2. 정의부를 가장 나중에 아예 외부영역에 두고 적는 이유는 a, b의 상황을 회피하고 컴파일러에게 아주 명확하게 코드의 로직을 전달하기 위함 
//                   -> a. 양 class의 내용이 전부 쓰일 가능성이 높은데, 이를 특정 class에 적으면 에러 가능성 증가
//                      b. 게다가 friend 대상 선언, friend 선언 단계랑 겹칠수도 있는 상황이라 컴파일러 입장에서 논리적 상황파악을 제대로 하기 까다로워서 error룰 뱉을 가능성 높음


// 특정 class의 멤버함수를 대상 class의 friend 멤버함수로 규정하여 연계해 사용하는 예시
#include <iostream>

// cout 객체의 경우 std namespace 것을 쓰겠다는 선언
using std::cout;

// Date class의 멤버함수인 OutToday()함수에서 Time 클래스를 사용하기 때문에 먼저 선언 
//  -> 안 그러면, 컴파일 과정에서 Time이 선언되지 않은 자료형이라 간주하고 error를 뿜음
class Time;

// (1) friend 선언될 멤버함수를 포함한 class 부터 가장 위에 있어야 함
//   -> 사용하기 전에 먼저 선언해야 하는게 세상 이치
class Date {

    private:
        int year, month, day;

    public:
        Date(int y, int m, int d) : year(y), month(m), day(d) {}

        // (중요!) friend로 지정할 예정인 Date의 멤버함수 OutToday의 원형 (선언부만 있고, 정의부는 없다는게 중요함)
        //   -> 이 부분이 parameter인 Time을 class로 인식하게 하기 위한 부분
        //       -> 정의부를 적지 않는 이유? 아직 Time class의 내용조차 제대로 선언이 안 되어 있음 
        void OutToday(Time& t);
};

// (2) friend 멤버함수를 friend라고 선언할 클래스
class Time {

    private:
        int hour, min, sec;

        // (중요!) Date클래스의 OutToday함수만 friend라고 규정해 준 Time클래스의 private멤버에 접근할 수 있음
        //   -> friend 함수는 Time 본 class의 함수가 아니니.. 당연히 정의부까지 적어주면 안 됨!
        friend void Date::OutToday(Time& t);

    public:
        Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
};

// (3) class Time의 friend 멤버함수인 Data class의 멤버함수 OutToday()의 내용을 외부에서 이제야 정의부를 적어줌
//       -> Date class의 멤버함수 OutToday()는 Time class의 friend
//           -> (중요!) 따라서 호출시 Time class private : int hour, min, sec;에도 접근 가능
void Date::OutToday(Time& t) {
    //t.hour = 15; t.min = 24; t.sec = 45;
    cout << "오늘은 " << year << "년 " << month << "월 " << day << "일이며\n";
    cout << "지금 시간은 " << t.hour << ":" << t.min << ":" << t.sec << "입니다.\n";
}

int main() {

    Date D(2023, 2, 14);
    Time T(10, 35, 27);

    // friend이기에 private인 Time class를 파라미터로 사용하여 쉽게 호출 가능
    D.OutToday(T);
    return 0;
}