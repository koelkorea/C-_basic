//friend
//기본적으로 외부에서 클래스 멤버로 접근하지 못하도록 private 제한
//특정 상황에서 필요한 경우 friend 선언된 다른 클래스(or 함수) 에
//private 및 protected 멤버에 접근 허용
//friend 키워드로 명시하지 않은 경우 접근 불가(개별적으로 모두 키워드를 써야 한다.)
//
//형식
//friend 키워드를 클래스(or 함수) 앞에 사용
//
//friend class Date; //friend class (클래스 이름);
//friend void OutToday(Date& d, Time& t); // friend +(함수 원형);
//
//friend 멤버함수
//클래스의 특정 멤버함수만 friend로 선언하여 접근 허용 범위를 줄인다.
//friend 멤버함수는 순서가 중요하다.(1) friend 로 선언될 멤버함수를 포함한 클래스(2) friend 멤버함수를 선언할 클래스(3) friend 멤버함수 외부 정의

/* friend 전역함수
전역함수는 friend를 선언한 클래스의 private멤버까지도 접근 가능
객체지향에 위배되기 때문에 가급적 사용하지 않는 것이 원칙이다.
특별한 경우에 전역함수를 자신의 멤버함수처럼 필요할 때 선언한다.
*/

/*  friend 멤버함수
  - 클래스의 특정 멤버함수만 friend로 선언하여 접근 허용 범위를 줄인다.
  - friend 멤버함수는 순서가 중요하다.
    (1) friend 선언될 멤버함수를 포함한 클래스
    (2) friend 멤버함수를 선언할 클래스
    (3) friend 멤버함수 외부 정의*/

/*
    friend 클래스
    - friend로 선언된 클래스는 friend를 선언한 클래스의 private멤버까지도 접근 가능하다.
*/

