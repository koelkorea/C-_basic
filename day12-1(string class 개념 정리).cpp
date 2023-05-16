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
//      -----------------------------------------------------------------------------------------------------
//      #include <string>
        
//      namespace std {                        <- (중요!) 그 입/출력 관련 비트연산자를 사용하는 cin, cout 객체와 같은 namespace에 위치
//       
//          class string {
//              unsigned __int64 size;         <- 멤버변수1 : size      (= 저장 가능 문자열의 개수 -> 2^64개)
//              unsigned __int64 capacity;     <- 멤버변수2 : capacity  (= 저장 가능 총 용량 크기 -> 2^64 byte)
//              allocator<char> allocator;     <- 멤버변수2 : allocator (= 문자열 배열에 대한 메모리 할당 및 해제를 관리하는 class객체)
//          };
//      }
//      ---------------------------------------------------------------------------------------------------------

//   #  string 클래스의 Constructor(생성자)의 종류
//       -> 문자열 저장은 깊은 복사 전제

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
//      8. string 객체명(Iter begin, Iter end)	
//          : Iterator begin에 기록된 char 포인터 위치를 시작으로 Iterator end 기록된 char 포인터 위치를 끝으로 한 문자열 내용을 깊은 복사하여 저장하는 string 객체 생성
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex의 문자열
//             -> Iterater : 포인터처럼 기능하는 반복자 class변수로 이해하면 됨

//   # string::npos의 의미
//      :  find() 함수 수행 시에 찾는 문자열이 없을 때 반환되는 상수 -1을 의미



//   # C언어와 C++에서 문자열을 입력하는 방법차이
// 
//      - C언어 : char 배열 사용한 문자열 입력 (= 기본적으로는 정적할당)
// 
//         1. cin과 비트연산자 사용한 입력 
//         
//            ex) char name[15];                      <-  최대 14(+'\0')개 저장 가능 (입력 stream 버퍼에는 '\n' 남아있음)
//                cin >> name; 
//                while (cin.get() != '\n');
// 
//         2. cin.get(char포인터변수명, 배열크기n) 
//             : char배열명에 해당하는 시작위치에 위치한 n크기 만큼의 배열에 문자열을 입력하면 '\n'까지를 기준으로 1행으로 입력받음 
//                -> (중요!) 단, 그러고 난뒤 입력 stream 버퍼에는 '\n' 남아있음
// 
//               ex) cin.get(name, 15);               <-  최대 14(+'\0')개 저장 가능 (입력 stream 버퍼에는 '\n' 남아있음)
// 
//         3. cin.getline(char포인터변수명, 배열크기n, '구분자' = '\n') 
//             : char배열명에 해당하는 시작위치에 위치한 n크기 만큼의 배열에 문자열을 입력하면, 구분자(기본 parameter = '\n')에 해당하는 문자까지만 1행으로 입력받음
//                -> getline 특성
//                    a. 입력 stream 버퍼에 남은 '\n'이나 '구분자'도 같이 없어짐  
//                          <-> 단! 구분자를 입력하면, 그 녀석과 이후 나머지 문자열은 입력버퍼에 남게 됨
//                    b. 구분자의 기본 parameter = '\n'
// 
//               ex) cin.getline(name, 15);           <-  최대 14(+'\0')개 저장 가능 (입력 stream 버퍼에 남은 '\n' 버림)
//                   cin.getline(name, 15, ':');      <-  최대 14(+'\0')개 저장 가능 (입력 stream 버퍼에 남은 ':' 버리지만, 그 이후 문자들이 남아있음)
// 
// 
//      - C++ :  string class를 통한 문자열 입력 (= 동적할당이 기본)
// 
//         1. cin과 비트연산자 사용한 입력 
//         
//            ex) string fullname;
//                cin >> fullname;                    <- 동적할당 된 문자열객체라 크기는 2^64자 까지.. 빈공간도 입력되며, '\n'까지를 기준으로 1행으로 입력받음 (입력 stream 버퍼에는 '\n' 남아있음)
//                while (cin.get() != '\n');
// 
//         2. getline(cin, string객체명, '구분자' = '\n') 
//             : string객체명에 cin 객체를 사용하여 문자열을 입력하면, 구분자(기본 parameter = '\n')에 해당하는 문자까지만 입력받음
//                -> getline 특성
//                    a. 입력 stream 버퍼에 남은 '\n'은 같이 없어짐  
//                          <-> 단! 구분자를 입력하면, 그 녀석과 이후 나머지 문자열은 입력버퍼에 남게 됨
//                    b. 구분자의 기본 parameter = '\n'
// 
//               ex) getline(cin, fullname);           <-  동동적할당 된 문자열객체라 크기는 2^64자 까지.. 빈공간도 입력되며, '\n'까지를 기준으로 1행으로 입력받음 (입력 stream 버퍼에 남은 '\n' 버림)
//                   getline(cin, fullname, ':');      <-  동동적할당 된 문자열객체라 크기는 2^64자 까지.. 빈공간도 입력되며, ':'까지를 기준으로 1행으로 입력받음 (입력 stream 버퍼에 남은 ':' 버리지만, 그 이후 문자들이 남아있음)


//   # String(문자열)의 Method(멤버 함수) = 객체.Method();

//     - 문자열의 특정 위치의 문자 반환
//       1. char& at(size_t n)
//           : 문자열 n칸 반환 (0 ≤ 문자열 < End)
//       2. char& operator[] (size_t n)
//           : 문자열 n칸 반환(0 ≤ 문자열 < End)
//       3. char& front()
//           : 문자열[0]칸에 해당하는 부분의 문자 반환
//       4. char& back()
//           : 문자열[End]칸에 해당하는 부분의 문자 반환

//문자열 길이 관련 반환
//size_t size() const == size_t length() const : 문자열 길이 반환
//void resize(size_t n) : 문자열 길이 n개 맞춤(str.size() < n : 공백, n < str.size() : 삭제)void resize(size_t n, char c) : 공백을 문자 c로 설정
//string substr(size_t st = 0, size_t len = npos) const : st부터 len개 반환
//string & replace(size_t st, size_t len, const string & str) : st~len 위치로 str 끼워 넣기
//bool empty() const : 비었는지 확인하는 함수(size == 0 : true)

//문자열 수정(내용 바꾸기 or 추가 or 삭제)
//void clear() : 문자열을 지우는 함수(capacity 유지)
//iterator erase(iterator st, iterator end) : st~end 문자열 제거
//iterator erase(iterator iter) : 문자열[iter] 제거
//string & erase(size_type offset = 0, size_type count = npos) : offset부터 count개 제거
//void push_back(char c) : 맨 뒤에 문자 c 추가 함수
//void pop_back() : 맨 뒤에 있는 문자 1개 제거 함수

//문자열 메모리
//size_t capacity() const; 문자열 저장 가능한 용량(메모리 크기, bytes) 반환
//void shrink_to_fit() : capacity(메모리)를 줄이는 함수
//void reserve(size_t n = 0) : capacity를 할당 함수(메모리 확보)

//C style 변환
//const char* c_str() const : 문자열(+\0) 상수 반환[C style]
//const value_type* data() const noexcept; 문자열을 null로 끝나는 문자 배열로 변환
//value_type* data() noexcept;

//문자열 처리
//int compare(const string& str2) const : 문자열 비교(객체.변수 : > +, = 0, < -반환)
//int compare(size_t st, size_t len, const string& str2) const
//int compare(size_t st, size_t len, const string& str2, size_t st2, size_t len2) const
//void swap(string& str1, string& str2) : str1과 str2를 교환
//size_t copy(char* arr, size_t len, size_t st = 0) const : 복사, 복사된 길이 반환
//size_t find(const string& str, size_t st = 0) const : 객체 내 문자열 검색, 인덱스 반환
//size_t find(const char* arr, size_t st = 0) const : 객체 내 문자열 검색, 실패 npos 반환

//문자열 위치 접근 iterator(반복자, 포인터 주소)
//const_iterator begin() const : 객체[0]의 주소 반환[반복자(iterator 포인터)]
//const_iterator end() const : 객체[End + 1] 주소 반환[반복자(iterator 포인터)]

//문자열 연산자 오버로딩
//String + String
//string & operator+(char _ch) :
//string & operator+(const char* const _ptr) :
//string & operator+(const string & _Right) :
//string & operator+(initializer_list<char> &_ilist) :
//String = String
//string & operator=(char _ch) :
//string & operator=(const char* const _ptr) :
//string & operator=(const string & _Right) :
//string & operator=(initializer_list<char> &_ilist) :
//String[n]
//char& operator[] (const size_t n) :
//const char& operator[] (const size_t n) const :
