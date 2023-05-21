// iostream
//  : C언어의 stdio.h를 대체하는 C++의 객체를 이용한 표준 입출력을 위한 클래스와 객체, 변수 등이 선언된 헤더파일

//   # (중요) iostream 특이사항 
//      : 데이터의 타입을 지정하지 않아도 cin, cout 객체를 통해 자체적으로 입, 출력

//         -> 예외1) 포인터에 저장 된 주소를 출력할 경우?
//                   -> 포인터나 int로 형변환 필요

//            예외2) 문자에 해당하는 아스키 코드 값을 출력하는 경우?
//                   -> int형으로 형변환 필요

//            예외3) 정수 to 문자로 출력?
//                   -> char형으로 형변환 필요

//            예외4) 실수는 유효 자릿수까지 출력 (경우에 따라 지수 형태로도 출력)

//            예외5) char형 포인터 입력시
//                   -> 주소부터 차례대로 문자열을 저장, 맨 뒤에 널 문자(‘\0’)를 자동 추가

//            예외6) char형 포인터 출력시
//                   -> 주소부터 널 문자(‘\0) 이전의 문자열을 출력

//  - 문자열 입/출력 코드 입력시 공통 사용법
//     1. 'endl' = '\n'
//         : 다음 줄로 이동
//           ex) cout << "Hello" << endl;

//     2. 데이터가 여러 개인 경우 쉬프트 연산자(<< , >> )로 구분

//     3. char형 포인터 입력시
//        ->주소부터 차례대로 문자열을 저장, 맨 뒤에 널 문자(‘\0’)를 자동 추가

//     4. char형 포인터 출력시
//        ->주소부터 널 문자(‘\0) 이전의 문자열을 출력


//  - iostream 헤더의 cin
//     : istream 클래스의 입력용도로 만들어진 객체... 

//     1. cin >> 변수명 
//        : (중요!) 입력 버퍼로 자료형에 관계없이 받은 값을 변수로 전달 
//          (= 대부분의 자료형에 연산자 오버로딩이 되어서 가능)
//            -> BUT! 문자열 입력 시 공백이 포함된 문자열은 못 받음..
//               -> 연속적인 데이터를 입력 받고 공백을 입력의 끝으로 처리하기 때문
//                   -> cin.getline(배열 이름, 배열 칸수)가 쓰이는 이유

//     2. cin.getline(배열 이름, 배열 칸수)
//        : c++에서 문자열을 띄어쓰기 포함해서 입력받는(enter키가 기준) 함수 
//          -> enter인 \n 키를 \0로 변경해 저장

//        # (중요) cin 특이사항
//           1) \n를 버퍼에 남김

//           2) 입력을 실패 할 경우 failbit = 1
//               -> 이 경우 cin.fail()애서 반환값 1을 받음

//           3) (중요) 우측 쉬프트(>> )의 특이점
//               : 문자열 입력 시 공백이 포함된 문자열은 못 받음..
//                 -> 연속적인 데이터를 입력 받고 공백을 입력의 끝으로 처리하기 때문
//                     -> cin.getline(배열 이름, 배열 칸수)가 쓰이는 이유

//        # (중요) cin 의 입력버퍼를 비우려면?
//           -> cin.ignore(int, '문자')
//               : 입력 버퍼에서 255개 문자를 읽고 이를 버퍼에서 없는 값으로 무시하되, '문자'에 해당하는 문자를 확인하면 중지

//                  ex) if (cin.fail()) {
//                          cin.clear();
//                          cin.ignore(255, '\n');
//                      }


//  - iostream 헤더의 출력 객체들
//     : ostream 클래스의 입력용도로 만들어진 객체... 

//       1. cout << "Hello";
//       2. clog << "World";
//       3. cerr << "C++";

//     # (중요) cout, clog , cerr 공통점, 차이점
//       - 공통점 : default 스트림은 콘솔창
//       - 차이점 : clog, cerr은 스트림을 변경하면 출력을 다른 파일로 할 수 있음

#include <iostream>   // cin, cout, clog, cerr    <- stdio.h의 scanf, printf 대체

int main() {

	int age = 0;

	// << , >> 비트연산자 = 스트림연산자 : 화살표 방향은 스트림의 흐름을 의미 (이걸로 입력시 공백이 포함된 문자열은 못 받음)

	std::cout << "문자열을 입력해줘라\n";
	std::cin >> age;                  // std::cin >> 변수명 : 해당 변수명에 임의적 데이터를 입력함(>>로 입력시 공백이 포함된 문자열은 못 받음)
	std::cout << "Hello World\n";     // std::cout << "내용" : 해당 "내용"을 출력해줌
	std::cout << age;                 // std::cout << "변수명" : 해당 변수명에 입력된 내용을 출력해줌
	std::cout << std::endl;           // endl : \n의 의미

	return 0;
}