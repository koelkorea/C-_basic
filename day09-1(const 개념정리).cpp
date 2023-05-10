//상수화
//변하지 않는 데이터
//자료를 수정 할 수 없도록 대입 연산을 금지하는 것
//
//변수의 상수화
//변수 앞에 const 키워드를 붙이면 상수가 된다.
//(값 변경 시 에러 발생)
//
//상수는 반드시 선언과 초기화를 동시에 한다.
//변수는 지역변수 선언 시 쓰레기 값으로 초기화되기 때문이다.
//
//
//
//포인터 상수화
//const가 자료형 앞에 선언된 경우 - 포인터가 가리키는 값 변경 불가능
//(변수 a로 직접 대입은 가능, a = 20;)
//
//const가 변수명 앞에 선언된 경우 – 포인터에 저장된 주소 변경 불가능
//
//const가 자료형, 변수명 앞에 선언된 경우 - 포인터가 가리키는 값, 주소 변경 불가능
//(변수 a로 직접 대입은 가능, a = 20;)
//
//
//
//
//멤버변수 상수화
//메모리 할당 후, 쓰레기 값으로 초기화 되기 때문에 오류발생
//
//":" 콜론 초기화 <초기화 리스트(Initialize List)>
//생성자의 body 부분보다 먼저 수행된다.
//
//멤버함수 상수화
//멤버변수의 수정 불가능하다. (읽기전용)
//상수화된 함수는 일반함수 호출이 불가능
//상수화된 함수는 멤버변수의 주소 리턴 불가능
