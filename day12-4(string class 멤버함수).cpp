//   # String(���ڿ�)�� Method(��� �Լ�) ȣ�� ����
//     : string��ü��.Method();

//      - ���ڿ��� Ư�� ��ġ�� [���� ��ȯ]
//         : string��ü��[n] ����� ��డ��

//         1. char& at(sizeũ���ڷ��� n)
//             : �ش� string class ��ü�� n��° ��ġ�� ���� ��ȯ (0 <= ���ڿ� < End)
//                -> (�߿�!) �ش� string class�� length�� ����� error

//         2. char& operator[] (sizeũ���ڷ��� n)
//             : �ش� string class ��ü�� n��° ��ġ�� ���� ��ȯ (0 <= ���ڿ� < End)
//                -> (�߿�!) �ش� string class�� length�� üũ���� ����

//         3. char& front()
//             : �ش� string class ��ü�� 0��° ��ġ�� ���� ��ȯ

//         4. char& back()
//             : �ش� string class ��ü�� ������ ��ġ�� ���� ��ȯ


//      - [���ڿ� ��ġ�� iterator(�ݺ��� �뵵�� ���� ������ �ּ�) ��ȯ] 
//         1. const_iterator begin() const
//             :  �ش� string class ��ü�� ���ڿ�[0]�� �ּҰ��� iterator(= ���� ������) ��ü������ ��ȯ

//         2. const_iterator end() const
//             : �ش� string class ��ü�� ���ڿ�[END + 1]�� �ּҰ��� iterator(= ���� ������) ��ü������ ��ȯ


//      - [���ڿ� ����] ���� ��ȯ
//         1. sizeũ���ڷ��� size() const == sizeũ���ڷ��� length() const
//             : �ش� string class ��ü�� ���ڿ� ���̰� ��ȯ

//         2. void resize(sizeũ���ڷ��� n)
//             : �ش� string class ��ü�� ���ڿ� ���̸� n���� ���� 
//                -> ���� str.size() < n : ���ڿ� ��ġ n ���� ����
//                   ���� str.size() > n : ���ڿ� ��ġ n ���� ����

//         3. void resize(sizeũ���ڷ��� n, char c)
//             : �ش� string class ��ü�� ���ڿ� ���̸� n���� ���߰� �� ��, ������ �ִٸ� �� �κ��� ���� c�� ����

//         4. string substr(sizeũ���ڷ��� start = 0, sizeũ���ڷ��� length = npos) const
//             : (���ڿ� �Ϻ� ����) �ش� string class ��ü�� ���ڿ� index�� start�� �κк��� len���� ���ڿ� ��ȯ
//                -> Ư���� �Է¾����� start = 0, length = -1 
//                   (= ���ڿ��� ��ȯ X)

//         5. string& replace(sizeũ���ڷ��� start, sizeũ���ڷ��� end, const string& str)
//             : (���ڿ� ��ü�ϱ�) �ش� string class ��ü�� ���ڿ� index�� start ~ end ��ġ�� str�� ������ �����, �ش� ���ڿ� ���۷��������� �����Ͽ� ����

//         6. bool empty() const
//             : �ش� string class ��ü�� ���ڿ��� ������� bool������ Ȯ���ϴ� �Լ�
//                -> ���� size == 0�� ���ڿ��� ���ٸ� -> true


//      - ���ڿ� [�߰�, ����, ���� ���]
//         1. void clear()
//             : �ش� string class ��ü�� ��� ���ڵ��� ����� �Լ� (�� ���� capacity ����)

//         2. iterator erase(iterator start, iterator end)
//             : �ش� string class ��ü index�� start ~ end�� �ش��ϴ� ���ڿ��� ������ ���� ��ġ�� iterator(= ���� ������) ��ü������ ��ȯ

//         3. iterator erase(iterator iter) : ���ڿ�[iter] ����
//             : �ش� string class ��ü index�� iter�� �ش��ϴ� ���ڿ�[iter]�� ������ ���� ��ġ�� iterator(= ���� ������) ��ü������ ��ȯ

//         4. string& erase(sizeũ���ڷ��� start = 0, sizeũ���ڷ��� count = npos)
//             : �ش� ���ڿ� index�� start���� count�� ����, �ش� ���ڿ� ���۷��������� �����Ͽ� ����
//                -> Ư���� �Է¾����� start = 0, count = -1 
//                   (= ���ڿ��� ���� X)

//         5. void push_back(char c)
//             : (��ġ�� �� �� �߰�) �ش� string class ��ü �� �� index�� ���� c�� �߰��ϴ� �Լ�

//         6. void pop_back()
//             : (��ġ�� �� �� ����) �ش� string class ��ü �� �� index�� �ִ� ���� 1�� ���� �Լ�


//      - ���ڿ� �޸� �Ҵ� ���� �Լ�
//         1. sizeũ���ڷ��� capacity() const
//             : �ش� string class ��ü�� ���ڿ� ������ ������ �뷮(�޸� ũ��, bytes)�� ��ȯ�ϴ� �Լ�

//         2. void shrink_to_fit()
//             : �ش� string class ��ü�� �Ҵ�� capacity(�޸�) �� �� ���̴� �κ��� ���̴� �Լ�

//         3. void reserve(sizeũ���ڷ��� n = 0)
//             : �ش� string class ��ü�� n(�޸� ũ��, bytes)��ŭ �뷮�� �ش��ϴ� capacity(�޸�)�� �Ҵ��ϴ� �Լ�


//      - string -> C style ���ڿ� �迭�� ��ȯ
//         1. const char* c_str() const
//             : �ش� string class ��ü�� null�� ������ ���ڿ��� C style�� char[] ����� ��ȯ���� ��ȯ

//         2. const string*(or char*) data() const noexcept
//             : �ش� string class ��ü�� ���ڿ��� null�� ������ ���� �迭�� ��ȯ ��, char �����ͻ���� string �����ͻ���� ��ȯ  
//                -> ���� X + ������ �Ұ��� 

//         3. string*(or char*) data() noexcept;
//             : �ش� string class ��ü�� ���ڿ��� null�� ������ ���� �迭�� ��ȯ ��, char �����ͻ���� string �����ͻ���� ��ȯ  
//                -> ���� X + ������ ����


//      - ���ڿ� �� �� �˻�, ����
//         1. int compare(const string& str2) const
//             : �ش� string class ��ü�� ��� ���ڿ� ��ü str2�� ���ڿ��� ���� �� �� ����� int������ ��ȯ
//                -> 1, -1 = �� ���ڿ� ��ġ X 
//                   0     = �� ���ڿ� ��ġ O

//         2. int compare(sizeũ���ڷ��� start, sizeũ���ڷ��� len, const string& str2) const
//             :�ش� string class ��ü�� index�� start�� �κк��� len���� ���ڿ� vs ��� ���ڿ� ��ü str2�� ���ڿ��� ���� ��, �� ����� int������ ��ȯ
//                -> 1, -1 = �� ���ڿ� ��ġ X 
//                   0     = �� ���ڿ� ��ġ O

//         3. int compare(sizeũ���ڷ��� start, sizeũ���ڷ��� len, const string& str2, sizeũ���ڷ��� start2, sizeũ���ڷ��� len2) const
//             : �ش� string class ��ü�� index�� start�� �κк��� len���� ���ڿ��� �ش��ϴ� �κ� vs ��� ���ڿ� ��ü str2�� ���ڿ��� index�� start2�� �κк��� len2���� ���ڿ��� �ش��ϴ� �κ� ���� ��, �� ����� int������ ��ȯ
//                -> 1, -1 = �� ���ڿ� ��ġ X 
//                   0     = �� ���ڿ� ��ġ O

//         4. void swap(string& str1, string& str2)
//             : (��ü�� ���� ȣ�� X) str1�� str2�� ���ڿ� ������ �ڽŵ��� �����ϴ� reference(�׷��ϱ� �� string��ü�� ������ ���ڿ� ���� ��ġ)�� ��ȯ�ؼ� ��ȯ�ϴ� �Լ�

//         5. sizeũ���ڷ��� copy(char* charArray, sizeũ���ڷ��� len, sizeũ���ڷ��� start = 0) const
//             : (char���ڿ� �迭�� string�� ���� �Լ�) �ش� string class ��ü�� charArray�� ��ġ�� ���ڿ��� index�� start�� �������� len�� ��ŭ�� �ش��ϴ� ���ڿ��� ������ ��, �ش� ����� �迭�� ���� ���� ��ȯ

//         6. sizeũ���ڷ��� find(const string& str, sizeũ���ڷ��� start = 0) const
//             : (string ���ڿ� �˻� �Լ�) �ش� string class ��ü �� ���ڿ� index�� start�� �ش��ϴ� �������� ��� ���ڿ� str�� �˻�, �� ����� index������ ��ȯ (<-> ���н� npos ��ȯ)

//         7. sizeũ���ڷ��� find(const char* charArray, sizeũ���ڷ��� start = 0) const
//             : (char���ڿ� �迭 �˻� �Լ�) �ش� string class ��ü �� ���ڿ� index�� start�� �ش��ϴ� �������� charArray�� ��ġ�� char���ڿ� �迭 ������ �ִ����� �˻�, �� ����� index������ ��ȯ (<-> ���н� npos ��ȯ)



//      - ���ڿ� ������(operator) �����ε�
//         1. ���ڿ������� ������ +
//             : String class ��ü�� ���ڿ��� �ٸ� ���ڿ�(char, char*�� �������� �� �迭, string ��ü, char�� ���ø� ó���� �����̳� ��ü) ���� ���̶�� ������ ������
//                ex) String1 + String2 = "(String1 ����)(String2 ����)" 

//         2. ���ڿ������� ������ =
//             : String class ��ü�� ���ڿ��� �ٸ� ���ڿ� �������� ������ �����϶�� ������ ������
//                ex) String1 = String2   ->   String1 = "(String2 ����)" 

//         3. String[n]
//             : �ش� string ��ü�� ���ڿ����� index�� n�� �ش��ϴ� ����(char)�� char �������������� ��ȯ

