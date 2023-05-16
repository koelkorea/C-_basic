// String(���ڿ�)�� Method(��� �Լ�) = ��ü.Method();

//  - ���ڿ��� Ư�� ��ġ�� ���� ��ȯ
//    1. char& at(size_t n)
//        : ���ڿ� nĭ ��ȯ (0 �� ���ڿ� < End)
//    2. char& operator[] (size_t n)
//        : ���ڿ� nĭ ��ȯ(0 �� ���ڿ� < End)
//    3. char& front()
//        : ���ڿ�[0]ĭ�� �ش��ϴ� �κ��� ���� ��ȯ
//    4. char& back()
//        : ���ڿ�[End]ĭ�� �ش��ϴ� �κ��� ���� ��ȯ

//���ڿ� ���� ���� ��ȯ
//size_t size() const == size_t length() const : ���ڿ� ���� ��ȯ
//void resize(size_t n) : ���ڿ� ���� n�� ����(str.size() < n : ����, n < str.size() : ����)void resize(size_t n, char c) : ������ ���� c�� ����
//string substr(size_t st = 0, size_t len = npos) const : st���� len�� ��ȯ
//string & replace(size_t st, size_t len, const string & str) : st~len ��ġ�� str ���� �ֱ�
//bool empty() const : ������� Ȯ���ϴ� �Լ�(size == 0 : true)

//���ڿ� ����(���� �ٲٱ� or �߰� or ����)
//void clear() : ���ڿ��� ����� �Լ�(capacity ����)
//iterator erase(iterator st, iterator end) : st~end ���ڿ� ����
//iterator erase(iterator iter) : ���ڿ�[iter] ����
//string & erase(size_type offset = 0, size_type count = npos) : offset���� count�� ����
//void push_back(char c) : �� �ڿ� ���� c �߰� �Լ�
//void pop_back() : �� �ڿ� �ִ� ���� 1�� ���� �Լ�

//���ڿ� �޸�
//size_t capacity() const; ���ڿ� ���� ������ �뷮(�޸� ũ��, bytes) ��ȯ
//void shrink_to_fit() : capacity(�޸�)�� ���̴� �Լ�
//void reserve(size_t n = 0) : capacity�� �Ҵ� �Լ�(�޸� Ȯ��)

//C style ��ȯ
//const char* c_str() const : ���ڿ�(+\0) ��� ��ȯ[C style]
//const value_type* data() const noexcept; ���ڿ��� null�� ������ ���� �迭�� ��ȯ
//value_type* data() noexcept;

//���ڿ� ó��
//int compare(const string& str2) const : ���ڿ� ��(��ü.���� : > +, = 0, < -��ȯ)
//int compare(size_t st, size_t len, const string& str2) const
//int compare(size_t st, size_t len, const string& str2, size_t st2, size_t len2) const
//void swap(string& str1, string& str2) : str1�� str2�� ��ȯ
//size_t copy(char* arr, size_t len, size_t st = 0) const : ����, ����� ���� ��ȯ
//size_t find(const string& str, size_t st = 0) const : ��ü �� ���ڿ� �˻�, �ε��� ��ȯ
//size_t find(const char* arr, size_t st = 0) const : ��ü �� ���ڿ� �˻�, ���� npos ��ȯ

//���ڿ� ��ġ ���� iterator(�ݺ���, ������ �ּ�)
//const_iterator begin() const : ��ü[0]�� �ּ� ��ȯ[�ݺ���(iterator ������)]
//const_iterator end() const : ��ü[End + 1] �ּ� ��ȯ[�ݺ���(iterator ������)]

//���ڿ� ������ �����ε�
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

