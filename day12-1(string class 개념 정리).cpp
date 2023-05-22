// string 클래스
//  : 그 동안 char[] 형식으로 접근하느라 ㅈㄹ맞게 까다로웠던, 문자열을 본격적으로 객체로 사용하기 위해 제작된 namespace std 안의 class 타입
//     -> 단! char 배열을 사용하는 근본 자체는 변하지는 않는게, 멤버변수인 allocator class객체가 기존 char*를 사용한 동적배열 방식의 메모리 동적할당 및 해제를 해주기 때문


//   #  C언어와 C++에서 문자열을 저장하는 자료형
// 
//      - C언어 char 사용
//         : char 변수명[숫자] = "문자열 상수(\0)"  or '문자 상수 값'
// 
//           ex) char str1[15] = "Hello World!(\0)"      <- 거의 null문자가 세트로 붙음
//               char str2[15] = 'Hello World!'

//      - C++는 string 사용
//         : string 변수명("문자열 상수")  or  string 변수명 = "문자열 상수";
// 
//           ex) string str1("Hello World!");         <- 파라미터로 입력하는 법
//               str2 = "Hello World!";               <- 직접 문자열 값 대입하는 법


//   #  C++의 string 클래스의 멤버구조 해체
//      : 간단히 말해, C++에서 개별 string객체는 자신이 위치한 문자열 포인터값과 거기 저장된 문자열의 갯수 및 크기가 얼만지에 대한 정보를 제공함
//        (= 그러니까 string 객체가 직접 문자열 값을 저장하는게 아니라, 객체가 가진 데이터는 문자열을 추출하기 위한 일종의 metadata라 생각하면 편함) 
// 
//      ---------------------------------------------------------------------------------------------------------
//         #include <string>
		   
//         namespace std {                        <- (중요!) 그 입/출력 관련 비트연산자를 사용하는 cin, cout 객체와 같은 namespace에 위치
//          
//             class string {
//                 unsigned __int64 size;         <- 멤버변수1 : size      (= 저장 가능 문자열의 개수 -> 2^64개)
//                 unsigned __int64 capacity;     <- 멤버변수2 : capacity  (= 저장 가능 총 용량 크기 -> 2^64 byte)
//                 allocator<char> allocator;     <- 멤버변수2 : allocator (= 문자열 배열에 대한 메모리 할당 및 해제를 관리하는 class객체)
//             };
//         }
//      ---------------------------------------------------------------------------------------------------------

//   # (사전 지식) 컨테이너 클래스(Container Class) 관련 용어
//      1. 템플릿(Template) = JAVA의 제너릭스(generics)
//          : <자료형> 을 의미하는 기호로 일종의 list나 vector와 같은 가변형 동적배열이나, list계열의 linkedList를 특정 class의 객체배열로 사용하기 위해 입력 자료형을 지정하는 역할을 함 
//             -> 쉽게 말해, C언어에서 컨테이너 class 구현할때, node나 list 내부의 value값의 타입을 'typedef value자료형 컨테이너명_element;' 식으로 구현한걸 정식으로 기능화
//                (= 이를 통해 동일한 코드를 다양한 데이터 타입에 대해 재사용하기 쉬워진 효과를 같는 것 또한 동일)

//           - 함수 템플릿(function Template)
//              : 함수의 일반적인 동작을 정의, 함수 호출 시에 '지정된 자료형' 만을 인자로 받아 실제 함수를 생성
// 
//                ex) list(initializer_list<Type> IList, const Allocator& Al);
// 
//           - 클래스 템플릿(class Template)
//              : 클래스의 일반적인 구조를 정의, 클래스의 멤버 변수와 멤버 함수에 대해 '지정된 자료형' 만을 인자로 받아 실제 클래스를 생성

//                ex1) template <value자료형 컨테이너요소명>    
//                     -> 이후 컨테이너 class 객체를 생성하면, 그 내부의 value자료형을 지정한 자료형으로 구현

//                ex2) 컨테이너클래스명 <<value자료형> 객체명 = new 컨테이너클래스명(); 형식도 같은 역할 수행

//      2. 할당자(allocator)
//          : 컨테이너 class 객체의 내부에서 컨테이너의 본체의 메모리를 동적으로 할당하고 해제하는 역할을 담당하는 멤버변수인 객체
//             -> 쉽게 말해, 컨테이너 class 객체를 내부의 컨테이터에 해당하는 부분을 통제하는 컨테이너 클래스의 껍데기이자 컨트롤러(= 파일럿) 같은 역할을 수행하는 존재 
//                (= this와 비슷하게 사용자는 보지 못하지만, 캡슐화된 객체인 이 녀석으로 컨테이너 클래스는 통제됨)

//            ex) 컨테이너객체명.get_allocator()
//                 -> 컨테이너 class 객체의 할당자 참조 방법

//      3. 할당자 복사 생성자(Allocator Copy Constructor)
//          : 어떤 컨테이너 class 객체를 생성하되, 특정 컨테이너 class 객체의 할당자(Allocator)를 복사하여 초기화하는 역할을 수행하는 생성자

//      4. 이터레이터(Iterator) class
//          : 컨테이너 class 객체 내의 각 요소에 접근하고 순회하기 위한 범용성 높은 [C++에서는 포인터와 비슷한 구조] '인터페이스를 제공하는 class'
//            (= 쉽게 말해, 컨테이너 class 계보에 속해 있다면, 공통의 표준화된 class 구조를 사용하여 [C++에서는 유사 포인터를 통한] 내부 요소 참조 및 순회를 가능하게 한다는 것)

//           - 이터레이터의 이점 : 각 자료구조 별로 제각각인 내부 요소 참조 및 접근을 위한 메서드를 쓰지 않아도 됨 

//              1. 컨테이너 class의 캡슐화 구현 달성
//                  : 컨테이너 class의 내부 구조에 대한 정보 없어도, 쉽게 이터레이터의 인터페이스를 써서 컨테이너의 원소를 순회하고 조작가능

//              2. 코드의 범용성과 유지보수성 증가
//                  : 컨테이너 별로 따로 메서드를 쓰지 않아도, 이터레이터의 인터페이스로 조작이 가능하니, 애지간해서는 동작이 보장됨
// 
//           - 이터레이터의 기능 예시
//              1. next()
//                  : 컨테이너 class 객체의 다음 iterator 위치의 데이터로 이동하고, 현재 원소를 반환
                
//              2. remove()
//                  : 컨테이너 class 객체의 현재 iterator 위치의 요소를 제거
                
//              3. get()
//                  : 컨테이너 class 객체의 현재 iterator 위치의 요소를 반환


//   # string 클래스의 Constructor(생성자)의 종류
//      -> 문자열 저장은 깊은 복사 전제

//      1. string 객체명();
//          :  default 생성자로 빈문자열이 저장
// 
//      2. string 객체명(const char* 포인터변수명);
//          : 해당 char 포인터 위치에 존재하는 "문자열 상수(\0)" 를 입력
// 
//      3. string 객체명(const char* 포인터변수명, 숫자n or size크기자료형 변수명)	;
//          : 해당 char 포인터 위치의 문자열의 시작 ~ n개까지 초기화
//            -> (중요) char 포인터 위치의 문자열 길이가 초기화할 크기 n보다 작아도 됨)
// 
//      4. string 객체명(const string & 레퍼런스변수명);
//          : string 클래스의 복사 생성자
//            ->  이미 존재하는 string 객체의 문자열 내용을 깊은 복사하여 대입
// 
//      5. string 객체명(const string & 레퍼런스변수명, index자료형 begin, index자료형 end = npos)	
//          : string 클래스의 복사 생성자 확장판
//            -> 이미 존재하는 string 객체의 문자열 내용중 index가 begin ~ end까지에 해당하는 문자들만 따로 추출하여, 깊은 복사하여 대입
//                ex) string ex(str, 3, 4) == str[3] ~ str[4] = ex의 문자열
// 
//      6. string 객체명(숫자n or size크기자료형 변수명, char 변수명);
//          : 문자 C를 n개로 구성한 문자열을 대입하여 초기화한 string 객체 생성
// 
//      7. string 객체명(const char* 시작포인터변수명, const char* 도착포인터변수명)	
//          : 시작포인터변수명에 기록된 char 포인터 위치를 시작으로 도착포인터변수명에 기록된 char 포인터 위치를 끝으로 한 문자열 내용을 깊은 복사하여 저장하는 string 객체 생성
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex의 문자열
// 
//      8. string 객체명(Iterator begin, Iterator end)	
//          : (template <value자료형 컨테이너요소명> 선행 필요) Iterator begin에 기록된 char 포인터 위치를 시작으로 Iterator end 기록된 char 포인터 위치를 끝으로 한 문자열 내용을 깊은 복사하여 저장하는 string 객체 생성
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex의 문자열
//                  -> Iterater : 포인터처럼 기능하는 반복자 class변수로 이해하면 됨


//   # string::npos의 의미
//      :  find() 함수 수행 시에 찾는 문자열이 없을 때 반환되는 상수 -1을 의미


//   # C언어와 C++에서 문자열을 입력하는 방법차이

//      - C언어 : char 배열 사용한 문자열 입력 (= 기본적으로는 정적할당)

//         1. cin과 비트연산자 사용한 입력 
        
//            ex) char name[15];                      <-  최대 14(+'\0')개 저장 가능 (입력 stream 버퍼에는 '\n' 남아있음)
//                cin >> name; 
//                while (cin.get() != '\n');

//         2. cin.get(char포인터변수명, 배열크기n) 
//             : char배열명에 해당하는 시작위치에 위치한 n크기 만큼의 배열에 문자열을 입력하면 '\n'까지를 기준으로 1행으로 입력받음 
//                -> (중요!) 단, 그러고 난뒤 입력 stream 버퍼에는 '\n' 남아있음

//                   ex) cin.get(name, 15);               <-  최대 14(+'\0')개 저장 가능 (입력 stream 버퍼에는 '\n' 남아있음)

//         3. cin.getline(char포인터변수명, 배열크기n, '구분자' = '\n') 
//             : char배열명에 해당하는 시작위치에 위치한 n크기 만큼의 배열에 문자열을 입력하면, 구분자(기본 parameter = '\n')에 해당하는 문자까지만 1행으로 입력받음
//                -> getline 특성
//                    a. 입력 stream 버퍼에 남은 '\n'이나 '구분자'도 같이 없어짐  
//                        <-> 단! 구분자를 입력하면, 그 녀석과 이후 나머지 문자열은 입력버퍼에 남게 됨
//                    b. 구분자의 기본 parameter = '\n'

//               ex) cin.getline(name, 15);           <-  최대 14(+'\0')개 저장 가능 (입력 stream 버퍼에 남은 '\n' 버림)
//                   cin.getline(name, 15, ':');      <-  최대 14(+'\0')개 저장 가능 (입력 stream 버퍼에 남은 ':' 버리지만, 그 이후 문자들이 남아있음)


//      - C++ :  string class를 통한 문자열 입력 (= 동적할당이 기본)

//         1. cin과 비트연산자 사용한 입력 
       
//            ex) string fullname;
//                cin >> fullname;                    <- 동적할당 된 문자열객체라 크기는 2^64자 까지.. 빈공간도 입력되며, '\n'까지를 기준으로 1행으로 입력받음 (입력 stream 버퍼에는 '\n' 남아있음)
//                while (cin.get() != '\n');

//         2. getline(cin, string객체명, '구분자' = '\n') 
//             : string객체명에 cin 객체를 사용하여 문자열을 입력하면, 구분자(기본 parameter = '\n')에 해당하는 문자까지만 입력받음
//                -> getline 특성
//                    a. 입력 stream 버퍼에 남은 '\n'은 같이 없어짐  
//                        <-> 단! 구분자를 입력하면, 그 녀석과 이후 나머지 문자열은 입력버퍼에 남게 됨
//                    b. 구분자의 기본 parameter = '\n'

//               ex) getline(cin, fullname);           <-  동동적할당 된 문자열객체라 크기는 2^64자 까지.. 빈공간도 입력되며, '\n'까지를 기준으로 1행으로 입력받음 (입력 stream 버퍼에 남은 '\n' 버림)
//                   getline(cin, fullname, ':');      <-  동동적할당 된 문자열객체라 크기는 2^64자 까지.. 빈공간도 입력되며, ':'까지를 기준으로 1행으로 입력받음 (입력 stream 버퍼에 남은 ':' 버리지만, 그 이후 문자들이 남아있음)


//   # String(문자열)의 Method(멤버 함수) 호출 형식
//     : string객체명.Method();

//      - 문자열의 특정 위치의 [문자 반환]
//         : string객체명[n] 도출로 요약가능

//         1. char& at(size크기자료형 n)
//             : 해당 string class 객체의 n번째 위치의 문자 반환 (0 <= 문자열 < End)
//                -> (중요!) 해당 string class의 length를 벗어나면 error
           
//         2. char& operator[] (size크기자료형 n)
//             : 해당 string class 객체의 n번째 위치의 문자 반환 (0 <= 문자열 < End)
//                -> (중요!) 해당 string class의 length를 체크하지 않음
           
//         3. char& front()
//             : 해당 string class 객체의 0번째 위치의 문자 반환
           
//         4. char& back()
//             : 해당 string class 객체의 마지막 위치의 문자 반환


//      - [문자열 위치값 iterator(반복자 용도의 유사 포인터 주소) 반환] 
//         1. const_iterator begin() const
//             :  해당 string class 객체의 문자열[0]의 주소값을 iterator(= 유사 포인터) 객체값으로 반환

//         2. const_iterator end() const
//             : 해당 string class 객체의 문자열[END + 1]의 주소값을 iterator(= 유사 포인터) 객체값으로 반환
           
        
//      - [문자열 길이] 관련 반환
//         1. size크기자료형 size() const == size크기자료형 length() const
//             : 해당 string class 객체의 문자열 길이값 반환
           
//         2. void resize(size크기자료형 n)
//             : 해당 string class 객체의 문자열 길이를 n개로 맞춤 
//                -> 만약 str.size() < n : 문자열 위치 n 이후 공백
//                   만약 str.size() > n : 문자열 위치 n 이후 삭제
           
//         3. void resize(size크기자료형 n, char c)
//             : 해당 string class 객체의 문자열 길이를 n개로 맞추고 난 뒤, 공백이 있다면 그 부분을 문자 c로 설정
           
//         4. string substr(size크기자료형 start = 0, size크기자료형 length = npos) const
//             : (문자열 일부 추출) 해당 string class 객체의 문자열 index가 start인 부분부터 len개의 문자열 반환
//                -> 특별한 입력없으면 start = 0, length = -1 
//                   (= 문자열을 반환 X)
           
//         5. string& replace(size크기자료형 start, size크기자료형 end, const string& str)
//             : (문자열 대체하기) 해당 string class 객체의 문자열 index가 start ~ end 위치에 str을 끼워서 덮어쓰고, 해당 문자열 레퍼런스변수를 생성하여 리턴
           
//         6. bool empty() const
//             : 해당 string class 객체의 문자열이 비었는지 bool값으로 확인하는 함수
//                -> 만약 size == 0인 문자열에 쓴다면 -> true
        
        
//      - 문자열 [추가, 삭제, 제거 기능]
//         1. void clear()
//             : 해당 string class 객체의 모든 문자들을 지우는 함수 (총 길이 capacity 유지)
        
//         2. iterator erase(iterator start, iterator end)
//             : 해당 string class 객체 index의 start ~ end에 해당하는 문자열을 제거한 뒤의 위치를 iterator(= 유사 포인터) 객체값으로 반환
        
//         3. iterator erase(iterator iter) : 문자열[iter] 제거
//             : 해당 string class 객체 index의 iter에 해당하는 문자열[iter]을 제거한 뒤의 위치를 iterator(= 유사 포인터) 객체값으로 반환
        
//         4. string& erase(size크기자료형 start = 0, size크기자료형 count = npos)
//             : 해당 문자열 index의 start부터 count개 제거, 해당 문자열 레퍼런스변수를 생성하여 리턴
//                -> 특별한 입력없으면 start = 0, count = -1 
//                   (= 문자열을 삭제 X)
        
//         5. void push_back(char c)
//             : (닥치고 맨 뒤 추가) 해당 string class 객체 맨 뒤 index에 문자 c를 추가하는 함수
        
//         6. void pop_back()
//             : (닥치고 맨 뒤 제거) 해당 string class 객체 맨 뒤 index에 있는 문자 1개 제거 함수
         
        
//      - 문자열 메모리 할당 관련 함수
//         1. size크기자료형 capacity() const
//             : 해당 string class 객체의 문자열 저장이 가능한 용량(메모리 크기, bytes)을 반환하는 함수
        
//         2. void shrink_to_fit()
//             : 해당 string class 객체에 할당된 capacity(메모리) 중 안 쓰이는 부분을 줄이는 함수
        
//         3. void reserve(size크기자료형 n = 0)
//             : 해당 string class 객체에 n(메모리 크기, bytes)만큼 용량에 해당하는 capacity(메모리)를 할당하는 함수
        

//      - string -> C style 문자열 배열로 변환
//         1. const char* c_str() const
//             : 해당 string class 객체의 null을 포함한 문자열을 C style의 char[] 상수로 변환시켜 반환

//         2. const string*(or char*) data() const noexcept
//             : 해당 string class 객체의 문자열을 null로 끝나는 문자 배열로 변환 후, char 포인터상수나 string 포인터상수로 반환  
//                -> 예외 X + 역참조 불가능 

//         3. string*(or char*) data() noexcept;
//             : 해당 string class 객체의 문자열을 null로 끝나는 문자 배열로 변환 후, char 포인터상수나 string 포인터상수로 반환  
//                -> 예외 X + 역참조 가능

        
//      - 문자열 비교 및 검색, 복사
//         1. int compare(const string& str2) const
//             : 해당 string class 객체와 대상 문자열 객체 str2의 문자열을 비교한 뒤 그 결과를 int값으로 반환
//                -> 1, -1 = 두 문자열 일치 X 
//                   0     = 두 문자열 일치 O

//         2. int compare(size크기자료형 start, size크기자료형 len, const string& str2) const
//             :해당 string class 객체의 index가 start인 부분부터 len개의 문자열 vs 대상 문자열 객체 str2의 문자열을 비교한 뒤, 그 결과를 int값으로 반환
//                -> 1, -1 = 두 문자열 일치 X 
//                   0     = 두 문자열 일치 O

//         3. int compare(size크기자료형 start, size크기자료형 len, const string& str2, size크기자료형 start2, size크기자료형 len2) const
//             : 해당 string class 객체의 index가 start인 부분부터 len개의 문자열에 해당하는 부분 vs 대상 문자열 객체 str2의 문자열의 index가 start2인 부분부터 len2개의 문자열에 해당하는 부분 비교한 뒤, 그 결과를 int값으로 반환
//                -> 1, -1 = 두 문자열 일치 X 
//                   0     = 두 문자열 일치 O

//         4. void swap(string& str1, string& str2)
//             : (객체를 통한 호출 X) str1과 str2의 문자열 내용을 자신들의 참조하는 reference(그러니까 각 string객체가 가지는 문자열 시작 위치)를 교환해서 교환하는 함수

//         5. size크기자료형 copy(char* charArray, size크기자료형 len, size크기자료형 start = 0) const
//             : (char문자열 배열을 string에 복사 함수) 해당 string class 객체에 charArray에 위치한 문자열을 index가 start인 지점부터 len개 만큼에 해당하는 문자열을 복사한 후, 해당 복사된 배열의 길이 값이 반환

//         6. size크기자료형 find(const string& str, size크기자료형 start = 0) const
//             : (string 문자열 검색 함수) 해당 string class 객체 내 문자열 index가 start에 해당하는 지점에서 대상 문자열 str을 검색, 그 결과를 index값으로 반환 (<-> 실패시 npos 반환)

//         7. size크기자료형 find(const char* charArray, size크기자료형 start = 0) const
//             : (char문자열 배열 검색 함수) 해당 string class 객체 내 문자열 index가 start에 해당하는 지점에서 charArray에 위치한 char문자열 배열 내용이 있는지를 검색, 그 결과를 index값으로 반환 (<-> 실패시 npos 반환)
        

        
//      - 문자열 연산자(operator) 오버로딩
//         1. 문자열에서의 연산자 +
//             : String class 객체의 문자열에 다른 문자열(char, char*를 시작으로 한 배열, string 객체, char로 템플릿 처리된 컨테이너 객체) 내용 붙이라는 내용의 연산자
//                ex) String1 + String2 = "(String1 내용)(String2 내용)" 

//         2. 문자열에서의 연산자 =
//             : String class 객체의 문자열에 다른 문자열 내용으로 대입해 변경하라는 내용의 연산자
//                ex) String1 = String2   ->   String1 = "(String2 내용)" 

//         3. String[n]
//             : 해당 string 객체의 문자열에서 index가 n에 해당하는 문자(char)를 char 레버런스변수로 반환