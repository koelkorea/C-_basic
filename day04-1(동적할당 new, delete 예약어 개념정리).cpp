// 정적할당
//  : Compile(컴파일)시 할당될 메모리 크기가 결정 - Stack 영역과 Data 영역에 할당되는 메모리는 모두 정적 할당 - 전역 변수, 지역 변수, 정적 변수 모두 컴파일 시 할당될 정적 할당

// 동적 할당 (new 연산자 사용)
//  : Runtime(실행)중에 메모리가 할당 - 동적 할당된 메모리는 Heap영역에 할당 - Heap메모리 = 동적 메모리 할당


//  # C++동적 할당 형식
//    1. c++ 메모리 동적할당 (malloc, calloc -> new 자료형 예약어를 통한 힙영역에 생성)
//       : 자료형 * 변수명 = new 자료형;      <->    malloc(byte 크기), calloc 등을 쓰던 과거아 다름
//       : 자료형 * 변수명 = new 자료형[n]; 

//         ex) (일반변수) int* ip = new int;  ,  (배열)  int* ip = new int[5];

//    2. c++ 메모리 동적할당 해제(free -> delete 변수명 예약어를 통한 힙영역 메모리 회수)
//       : delete 변수명;      <->     free 등을 쓰던 과거아 다름
//       : delete[] 변수명; 

//         ex) (일반변수) delete ip;          ,  (배열) delete[] ip;


//  # new 연산자 의미 
//     : 메모리의 힙 영역에 동적 할당된 시작주소가 어딘지를 리턴해주는 연산자 (= c언어의 realloc, malloc, calloc 등의 함수를 통한 동적할당을 완전히 대체... 기능까지)
//        -> (중요) 기존 c언어의 동적할당 함수와 작동방식이 같음
//            = 이걸 받는 변수도 주소값을 저장하는 포인터변수여야 함
//            = 동적 할당된 데이터 형과 같은 타입의 포인터변수로 이 동적 메모리의 주소값을 받아야 함
//            = 동적으로 할당된 메모리는 반드시 해제가 필요
//              ->  delete 연산자 (c언어의 free 동적해제 대체) 등장


//  # Memory(메모리) 영역 할당주체에 따른 구분 
//    1. Heap
//       : 프로그래머에 의해 할당 및 해제가 이뤄지는 영역으로.. 동적으로 생성되는 자료형 데이터들이 위치하는 영역이고 거기 저장되는 값들도 실질적으로 저장되는 영역임
//          -> Stack과 사실상 전체적으로 같은 메모리 공간을 갈라먹는 처지.. (stack이 크면, heap이 작아지고... 그 반대로 가능)

//    2. stack, data
//       : Stack 영역과 Data 영역은 시스템에 의해 할당되고 해제되는 영역,

//  # {} 를 기준으로 따지는 변수의 종류
//   1. 전역변수 : 함수 밖이나 외부파일에서 선언 = 프로그램 전체에 걸쳐 사용될 수 있는 변수
//      -> 자동 초기화 ㅇ (숫자는 0)  
//      -> 생존기간  : forever  = 데이터 영역에 메모리(RSS)가 할당
//      -> 확장개념 : 외부 static함수, 외부변수(extern) 

//   2. 지역변수 :  선언된 블록이나 함수같은 특정 범위({} 스코프) 내에서만 통용되는 변수
//      -> 자동 초기화 X
//      -> 생존기간  : 임시로 사용(내부 static함수만 forever) = stack 영역에 메모리가 할당 
//      -> 확장개념 : 내부 static함수, 자동변수(auto), 레지스터변수(register)

//  - 기억클래스로 나누는 변수 (대충 세부기준이라 보면 편함)
//   1. 자동변수(auto) : 함수 스코프 안에서 선언되고, 그 함수 안에서만 사용되며, 함수가 종료되면 stack메모리에서 해제 (일종의 지역변수)
//      -> 자동 초기화 X (지역변수이기에)
//      -> 함수가 실행될 때마다, 새로 초기화 된다는 점 명심! 
//      -> auto라는 예약어는 생략가능
//
//   2. 정적 변수(static) : 컴파일 시 데이터 영역에 메모리(RSS)가 할당, 프로그램이 종료될때까지 값을 유지 (단! 자기 프로그램 내에서만 참조 가능)
//      -> 자동 초기화 ㅇ (프로그램 시작시, 딱 1번만 초기화 = 변경값은 끝까지 저장)
//          -> 생존기간  : forever
//      -> 세부구분
//          - 2.1 외부 staric 변수
//              : 함수 밖에서 선언되는 일반 static변수 (사실상 전역변수와 유사)
//          - 2.2 내부 static 변수
//              : 함수 안에서 선언되는 지역변수와 같은 static변수...  (그러니까 다른 {}차원에 존재하는 static변수)
//       -> (중요) 자동변수(auto)와의 비교
//          - 공통점 : 지역변수
//          - 차이점 : 함수 실행 때마다 초기화 되는 자동변수와 달리.. 해당 함수가 실행될 때만 변동이 생기지만, 변경값은 끝까지 저장..
//
//   3. 외부변수(extern) : extern으로 선언한 전역변수는 함수의 외부에 선언되는 일종의 전역변수 = 다른 파일에서 해당 값을 참조 가능 (전역변수, 일반 정적변수는 이게 불가능) 
//      -> 자동 초기화 ㅇ (프로그램 종료때까지 유지)
//          -> 생존기간  : forever
//      -> 메모리 할당은 static변수와 같음
//      -> (중요) 전역변수와의 비교
//          - 공통점 : 외부변수(extern)는 외부에서 선언된 전역변수와 비슷
//          - 차이점 : 전역변수는 아무리 그래도 파일 내부에 위치 + 다른 파일에서 참고는 불가능
//
//  4. 레지스터변수(register) : 지역변수지만, CPU의 레지스터에 저장되는 지역변수 (CPU에 저장된다는거 말고는 지역변수와 같음)
//      ->  기억 장소가 레지스터이므로 실행 속도가 제일 빠름
//      ->  레지스터 배정이 가능한 개수만큼 할당함 (그 이외는 자동 변수로 할당)