//   # 접근제어자
//     : 클래스의 멤버변수의 변조 방지를 위해 코드 실행 중 접근위치에 따라 멤버변수의 값에 접근여부에 따른 제어권한을 의미 
//        -> 사실상 public과 private만 널리 사용되며, 이들이 getter setter 디자인패턴과 연관 

//       - private     : 해당 클래스 내에서만 해당 클래스의 멤버들에 접근할 수 있음 (= 오로지 클래스 선언시 미리 작성한 멤버변수 초기화 값과 멤버함수를 통해서만 값의 변조가 가능)
//       - protected   : 상속관계에서 해당 클래스의 멤버들에 접근허용 (= 해당 클래스와 상속관계에 이는 클래스가 선언될 때라면, 해당 멤버변수의 값에 접근 및 변조나 멤버함수의 사용이 가능) 
//       - public      : 어디서든 일단 멤버변수나 멤버메서드가 호출되거나 참조되면, 언제라도 해당 멤버변수의 값에 접근 및 변조나 멤버함수의 사용을 허용함 (사실상 자동문임)

//ACT.h 선언부를 위한 header
#pragma once
class ACT {

	private:
		int ACTId;              // 계좌번호
		char pw[5];             // 비밀번호
		char name[20];          // 이름
		int bal;                // 잔액

	public:
		void Init_act(int actid, const char* pw, const char* name, int bal);
		void showData();        // 계좌정보 출력
		void deposit();         // 입금 함수 & 출력
		void withdraw();        // 출금 함수 & 출력
};
