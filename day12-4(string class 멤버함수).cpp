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

