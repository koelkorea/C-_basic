// string Ŭ����
//  : �� ���� char[] �������� �����ϴ��� �����°� ��ٷο���, ���ڿ��� ���������� ��ü�� ����ϱ� ���� ���۵� namespace std ���� class Ÿ��
//     -> ��! char �迭�� ����ϴ� �ٺ� ��ü�� �������� �ʴ°�, ��������� allocator class��ü�� ���� char*�� ����� �����迭 ����� �޸� �����Ҵ� �� ������ ���ֱ� ����


//   #  C���� C++���� ���ڿ��� �����ϴ� �ڷ���
// 
//      - C��� char ���
//         : char ������[����] = "���ڿ� ���(\0)"  or '���� ��� ��'
// 
//           ex) char str1[15] = "Hello World!(\0)"      <- ���� null���ڰ� ��Ʈ�� ����
//               char str2[15] = 'Hello World!'

//      - C++�� string ���
//         : string ������("���ڿ� ���")  or  string ������ = "���ڿ� ���";
// 
//           ex) string str1("Hello World!");         <- �Ķ���ͷ� �Է��ϴ� ��
//               str2 = "Hello World!";               <- ���� ���ڿ� �� �����ϴ� ��


//   #  C++�� string Ŭ������ ������� ��ü
//      : ������ ����, C++���� ���� string��ü�� �ڽ��� ��ġ�� ���ڿ� �����Ͱ��� �ű� ����� ���ڿ��� ���� �� ũ�Ⱑ ������ ���� ������ ������
//        (= �׷��ϱ� string ��ü�� ���� ���ڿ� ���� �����ϴ°� �ƴ϶�, ��ü�� ���� �����ʹ� ���ڿ��� �����ϱ� ���� ������ metadata�� �����ϸ� ����) 
// 
//      -----------------------------------------------------------------------------------------------------
//      #include <string>
        
//      namespace std {                        <- (�߿�!) �� ��/��� ���� ��Ʈ�����ڸ� ����ϴ� cin, cout ��ü�� ���� namespace�� ��ġ
//       
//          class string {
//              unsigned __int64 size;         <- �������1 : size      (= ���� ���� ���ڿ��� ���� -> 2^64��)
//              unsigned __int64 capacity;     <- �������2 : capacity  (= ���� ���� �� �뷮 ũ�� -> 2^64 byte)
//              allocator<char> allocator;     <- �������2 : allocator (= ���ڿ� �迭�� ���� �޸� �Ҵ� �� ������ �����ϴ� class��ü)
//          };
//      }
//      ---------------------------------------------------------------------------------------------------------

//   #  string Ŭ������ Constructor(������)�� ����
//       -> ���ڿ� ������ ���� ���� ����

//      1. string ��ü��();
//          :  default �����ڷ� ���ڿ��� ����
// 
//      2. string ��ü��(const char* �����ͺ�����);
//          : �ش� char ������ ��ġ�� �����ϴ� "���ڿ� ���(\0)" �� �Է�
// 
//      3. string ��ü��(const char* �����ͺ�����, ����n or sizeũ���ڷ��� ������)	;
//          : �ش� char ������ ��ġ�� ���ڿ��� ���� ~ n������ �ʱ�ȭ
//            -> (�߿�) char ������ ��ġ�� ���ڿ� ���̰� �ʱ�ȭ�� ũ�� n���� �۾Ƶ� ��)
// 
//      4. string ��ü��(const string & ���۷���������);
//          : string Ŭ������ ���� ������
//            ->  �̹� �����ϴ� string ��ü�� ���ڿ� ������ ���� �����Ͽ� ����
// 
//      5. string ��ü��(const string & ���۷���������, index�ڷ��� begin, index�ڷ��� end = npos)	
//          : string Ŭ������ ���� ������ Ȯ����
//            -> �̹� �����ϴ� string ��ü�� ���ڿ� ������ index�� begin ~ end������ �ش��ϴ� ���ڵ鸸 ���� �����Ͽ�, ���� �����Ͽ� ����
//                ex) string ex(str, 3, 4) == str[3] ~ str[4] = ex�� ���ڿ�
// 
//      6. string ��ü��(����n or sizeũ���ڷ��� ������, char ������);
//          : ���� C�� n���� ������ ���ڿ��� �����Ͽ� �ʱ�ȭ�� string ��ü ����
// 
//      7. string ��ü��(const char* ���������ͺ�����, const char* ���������ͺ�����)	
//          : ���������ͺ����� ��ϵ� char ������ ��ġ�� �������� ���������ͺ����� ��ϵ� char ������ ��ġ�� ������ �� ���ڿ� ������ ���� �����Ͽ� �����ϴ� string ��ü ����
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex�� ���ڿ�
// 
//      8. string ��ü��(Iter begin, Iter end)	
//          : Iterator begin�� ��ϵ� char ������ ��ġ�� �������� Iterator end ��ϵ� char ������ ��ġ�� ������ �� ���ڿ� ������ ���� �����Ͽ� �����ϴ� string ��ü ����
//             ex) string ex(str + 3, str + 34) == str[3] ~ str[34] = ex�� ���ڿ�
//             -> Iterater : ������ó�� ����ϴ� �ݺ��� class������ �����ϸ� ��

//   # string::npos�� �ǹ�
//      :  find() �Լ� ���� �ÿ� ã�� ���ڿ��� ���� �� ��ȯ�Ǵ� ��� -1�� �ǹ�



//   # C���� C++���� ���ڿ��� �Է��ϴ� �������
// 
//      - C��� : char �迭 ����� ���ڿ� �Է� (= �⺻�����δ� �����Ҵ�)
// 
//         1. cin�� ��Ʈ������ ����� �Է� 
//         
//            ex) char name[15];                      <-  �ִ� 14(+'\0')�� ���� ���� (�Է� stream ���ۿ��� '\n' ��������)
//                cin >> name; 
//                while (cin.get() != '\n');
// 
//         2. cin.get(char�����ͺ�����, �迭ũ��n) 
//             : char�迭�� �ش��ϴ� ������ġ�� ��ġ�� nũ�� ��ŭ�� �迭�� ���ڿ��� �Է��ϸ� '\n'������ �������� 1������ �Է¹��� 
//                -> (�߿�!) ��, �׷��� ���� �Է� stream ���ۿ��� '\n' ��������
// 
//               ex) cin.get(name, 15);               <-  �ִ� 14(+'\0')�� ���� ���� (�Է� stream ���ۿ��� '\n' ��������)
// 
//         3. cin.getline(char�����ͺ�����, �迭ũ��n, '������' = '\n') 
//             : char�迭�� �ش��ϴ� ������ġ�� ��ġ�� nũ�� ��ŭ�� �迭�� ���ڿ��� �Է��ϸ�, ������(�⺻ parameter = '\n')�� �ش��ϴ� ���ڱ����� 1������ �Է¹���
//                -> getline Ư��
//                    a. �Է� stream ���ۿ� ���� '\n'�̳� '������'�� ���� ������  
//                          <-> ��! �����ڸ� �Է��ϸ�, �� �༮�� ���� ������ ���ڿ��� �Է¹��ۿ� ���� ��
//                    b. �������� �⺻ parameter = '\n'
// 
//               ex) cin.getline(name, 15);           <-  �ִ� 14(+'\0')�� ���� ���� (�Է� stream ���ۿ� ���� '\n' ����)
//                   cin.getline(name, 15, ':');      <-  �ִ� 14(+'\0')�� ���� ���� (�Է� stream ���ۿ� ���� ':' ��������, �� ���� ���ڵ��� ��������)
// 
// 
//      - C++ :  string class�� ���� ���ڿ� �Է� (= �����Ҵ��� �⺻)
// 
//         1. cin�� ��Ʈ������ ����� �Է� 
//         
//            ex) string fullname;
//                cin >> fullname;                    <- �����Ҵ� �� ���ڿ���ü�� ũ��� 2^64�� ����.. ������� �ԷµǸ�, '\n'������ �������� 1������ �Է¹��� (�Է� stream ���ۿ��� '\n' ��������)
//                while (cin.get() != '\n');
// 
//         2. getline(cin, string��ü��, '������' = '\n') 
//             : string��ü�� cin ��ü�� ����Ͽ� ���ڿ��� �Է��ϸ�, ������(�⺻ parameter = '\n')�� �ش��ϴ� ���ڱ����� �Է¹���
//                -> getline Ư��
//                    a. �Է� stream ���ۿ� ���� '\n'�� ���� ������  
//                          <-> ��! �����ڸ� �Է��ϸ�, �� �༮�� ���� ������ ���ڿ��� �Է¹��ۿ� ���� ��
//                    b. �������� �⺻ parameter = '\n'
// 
//               ex) getline(cin, fullname);           <-  �������Ҵ� �� ���ڿ���ü�� ũ��� 2^64�� ����.. ������� �ԷµǸ�, '\n'������ �������� 1������ �Է¹��� (�Է� stream ���ۿ� ���� '\n' ����)
//                   getline(cin, fullname, ':');      <-  �������Ҵ� �� ���ڿ���ü�� ũ��� 2^64�� ����.. ������� �ԷµǸ�, ':'������ �������� 1������ �Է¹��� (�Է� stream ���ۿ� ���� ':' ��������, �� ���� ���ڵ��� ��������)


//   # String(���ڿ�)�� Method(��� �Լ�) = ��ü.Method();

//     - ���ڿ��� Ư�� ��ġ�� ���� ��ȯ
//       1. char& at(size_t n)
//           : ���ڿ� nĭ ��ȯ (0 �� ���ڿ� < End)
//       2. char& operator[] (size_t n)
//           : ���ڿ� nĭ ��ȯ(0 �� ���ڿ� < End)
//       3. char& front()
//           : ���ڿ�[0]ĭ�� �ش��ϴ� �κ��� ���� ��ȯ
//       4. char& back()
//           : ���ڿ�[End]ĭ�� �ش��ϴ� �κ��� ���� ��ȯ

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
