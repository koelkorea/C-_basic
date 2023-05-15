// String(문자열)의 Method(멤버 함수) = 객체.Method();

//  - 문자열의 특정 위치의 문자 반환
//    1. char& at(size_t n)
//        : 문자열 n칸 반환 (0 ≤ 문자열 < End)
//    2. char& operator[] (size_t n)
//        : 문자열 n칸 반환(0 ≤ 문자열 < End)
//    3. char& front()
//        : 문자열[0]칸에 해당하는 부분의 문자 반환
//    4. char& back()
//        : 문자열[End]칸에 해당하는 부분의 문자 반환

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

