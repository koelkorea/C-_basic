// �����̳� Ŭ����(Container Class)
//  : (�߿�) ���� ���� ��Ҹ� ���� �� �ִ� ������ ������ �����ϴ� �����͸� �����ϰ� �����ϴ� class
//     -> �������� ����, ����, �˻� �� �پ��� �۾��� ���� ���� 
//        (= �˰��� Ǯ�̿� �ʼ��� ����)
// 
//        ex) �迭, ���Ḯ��Ʈ, ����, ť...


//   # �����̳� Ŭ����(Container Class) ����.. 
//      : �׳� ����� �˰� �ִ� �˰��� ���̴� ������ ����� �ڷᱸ�����̶� �����ϸ� ����

//        1. ����(Vector)
//           : ũ�⸦ �������� ���������� ���� �迭(Array)�� ������ class 

//        2. ����Ʈ(List)
//           : ���� ����Ʈ(linked list)�� ������ class

//        3. ť(Queue)
//           : ���Լ���(FIFO) ������ ������ ������ class

//        4. ����(Stack)
//           : ���Լ���(LIFO) ������ ������ ������ class

//        5. ��Ʈ(Set)
//           : �� ��Ұ� ������ �ߺ�X ������ �̷���� ���� �迭(Array)�� ������ class 

//        6. ��(Map) / ��ųʸ�(Dictionary)
//           : set�� ���� ������ key - ArrayList�� ���� value ������ �����͸� �����ϴ� �� �ڷᱸ���� ������ class

//        7. ��ũ(Deque)
//           : ���Լ���(FIFO), ���Լ���(LIFO)�� ��� ������ ������ ������ ������ class


//   # (�߿�!) �����̳� Ŭ����(Container Class) ���� ���

//      1. ���ø�(Template) = JAVA�� ���ʸ���(generics)
//          : <�ڷ���> �� �ǹ��ϴ� ��ȣ�� ������ list�� vector�� ���� ������ �����迭�̳�, list�迭�� linkedList�� Ư�� class�� ��ü�迭�� ����ϱ� ���� �Է� �ڷ����� �����ϴ� ������ �� 
//             -> ���� ����, C���� �����̳� class �����Ҷ�, node�� list ������ value���� Ÿ���� 'typedef value�ڷ��� �����̳ʸ�_element;' ������ �����Ѱ� �������� ���ȭ
//                (= �̸� ���� ������ �ڵ带 �پ��� ������ Ÿ�Կ� ���� �����ϱ� ������ ȿ���� ���� �� ���� ����)

//           - �Լ� ���ø�(function Template)
//              : �Լ��� �Ϲ����� ������ ����, �Լ� ȣ�� �ÿ� '������ �ڷ���' ���� ���ڷ� �޾� ���� �Լ��� ����
// 
//                ex) list(initializer_list<Type> IList, const Allocator& Al);
// 
//           - Ŭ���� ���ø�(class Template)
//              : Ŭ������ �Ϲ����� ������ ����, Ŭ������ ��� ������ ��� �Լ��� ���� '������ �ڷ���' ���� ���ڷ� �޾� ���� Ŭ������ ����

//                ex1) template <value�ڷ��� �����̳ʿ�Ҹ�>    
//                     -> ���� �����̳� class ��ü�� �����ϸ�, �� ������ value�ڷ����� ������ �ڷ������� ����

//                ex2) �����̳�Ŭ������ <<value�ڷ���> ��ü�� = new �����̳�Ŭ������(); ���ĵ� ���� ���� ����


//      2. �Ҵ���(allocator)
//          : �����̳� class ��ü�� ���ο��� �����̳��� ��ü�� �޸𸮸� �������� �Ҵ��ϰ� �����ϴ� ������ ����ϴ� ��������� ��ü
//             -> ���� ����, �����̳� class ��ü�� ������ �������Ϳ� �ش��ϴ� �κ��� �����ϴ� �����̳� Ŭ������ ���������� ��Ʈ�ѷ�(= ���Ϸ�) ���� ������ �����ϴ� ���� 
//                (= this�� ����ϰ� ����ڴ� ���� ��������, ĸ��ȭ�� ��ü�� �� �༮���� �����̳� Ŭ������ ������)

//            ex) �����̳ʰ�ü��.get_allocator()
//                 -> �����̳� class ��ü�� �Ҵ��� ���� ���


//      3. �Ҵ��� ���� ������(Allocator Copy Constructor)
//          : � �����̳� class ��ü�� �����ϵ�, Ư�� �����̳� class ��ü�� �Ҵ���(Allocator)�� �����Ͽ� �ʱ�ȭ�ϴ� ������ �����ϴ� ������


//      4. ���ͷ�����(Iterator) class
//          : �����̳� class ��ü ���� �� ��ҿ� �����ϰ� ��ȸ�ϱ� ���� ���뼺 ���� [C++������ �����Ϳ� ����� ����] '�������̽��� �����ϴ� class'
//            (= ���� ����, �����̳� class �躸�� ���� �ִٸ�, ������ ǥ��ȭ�� class ������ ����Ͽ� [C++������ ���� �����͸� ����] ���� ��� ���� �� ��ȸ�� �����ϰ� �Ѵٴ� ��)

//           - ���ͷ������� ���� : �� �ڷᱸ�� ���� �������� ���� ��� ���� �� ������ ���� �޼��带 ���� �ʾƵ� �� 
//              1. �����̳� class�� ĸ��ȭ ���� �޼�
//                  : �����̳� class�� ���� ������ ���� ���� ���, ���� ���ͷ������� �������̽��� �Ἥ �����̳��� ���Ҹ� ��ȸ�ϰ� ���۰���

//              2. �ڵ��� ���뼺�� ���������� ����
//                  : �����̳� ���� ���� �޼��带 ���� �ʾƵ�, ���ͷ������� �������̽��� ������ �����ϴ�, �������ؼ��� ������ �����

//           - �����̳� Ŭ���� ��ü�� ���ͷ����� ���� ���� ����
//              : �����̳�Ŭ������<�ڷ���> :: iterator �����̳�Ŭ����_���ͷ����Ͱ�ü��;
//                 -> (�߿�) �̸� ���� � �����̳� Ŭ���� ��ü ����� �����ּҰ��� ���ͷ����� ��ȯ���� �����Ͽ� ���� ���� = �����̳� Ŭ���� ��ü�� ���� ��� �ּҰ��� ++, --�� ���� ���� ���س� �� �ְ� ������ ���� 

//           - ���ͷ������� ��� ����
//              1. next()
//                  : �����̳� class ��ü�� ���� iterator ��ġ�� �����ͷ� �̵��ϰ�, ���� ���Ҹ� ��ȯ

//              2. remove()
//                  : �����̳� class ��ü�� ���� iterator ��ġ�� ��Ҹ� ����

//              3. get()
//                  : �����̳� class ��ü�� ���� iterator ��ġ�� ��Ҹ� ��ȯ


//   # ���ø�(Template) vs ���ʸ���(generics)
//     : ���ø�(Template) + ������ ���������� Ÿ�� check��� �߰��� JAVA�� ���ø� ���


//   # C++������ �����̳� Ŭ����(Container Class) Ư¡ 
//      : C++�� ǥ�� ���̺귯��(STL)���� �����Ǹ�, �̵��� ���ø�(template)�� ����Ͽ� �����Ǿ� �־� �پ��� ������ Ÿ���� ����


//  - List 
//    : C++���� ���� ���� ����Ʈ(doubly linked list)�� ���������� ������ class

//     # List ��ü ���� ����
//       : list<�ڷ���> list��ü�� + (������ ���� parameters...);    <- new �����ڸ� ���� �ʾƵ� ���� Ÿ class������ ��ü�����Ͱ� ���� �κп� �ٷ� list �����ڸ� ������ �������� list ��ü �����Ҵ�

//     # List �޼��� ȣ�� ����
//       : list��ü��.�޼����(parameters....);

//     # List ���ͷ����� ���� ���� ����
//       : list<�ڷ���> :: iterator list���ͷ����Ͱ�ü��;
//          -> (�߿�) �̸� ���� list ���� ����� �����ּҰ��� ���ͷ����� ��ȯ���� �����Ͽ� ���� ���� = list�� ���� ��� �ּҰ��� ++, --�� ���� ���� ���س� �� �ְ� ������ ���� 


//     # list Constructor(������)
//       : new �����ڿ� ���X, �����Ҷ� �ٷ� ���� class ��ü�����Ͱ� �;� �� ��ġ�� list��ü��() �κп� ���

//       1. list()
//           : list�� �⺻ ������(default constructor) = ��� ���� ����

//       2. list(list& node)
//           : list�� ���� ������ (Ư�� node ���� ����)

//       3. list(list&& node)
//           : list�� �̵� ������ (Ư�� node ���� ����)

//       4. list(size Count)
//           : value ���� 0���� �ϴ� Count��ŭ�� ������ ���� node�� �����Ͽ� list��ü �ʱ�ȭ��

//       5. list(size Count, �ڷ���& value)
//           : Count��ŭ�� ������ŭ, value ���� ���� node�� �����Ͽ� list��ü �ʱ�ȭ��

//       6. list(Allocator& Al)
//           : �Ҵ��� ���� ������
//              -> (�߿�!) list��ü�� �Ҵ��ڴ� list.getAllocator()�� ����

//       7. list(size Count, �ڷ���& value, Allocator& Al)
//           : Count��ŭ�� ������ŭ, value ���� ���� node�� �����ϵ�, �Ҵ��ڱ��� �����ϴ� ������.. list��ü �ʱ�ȭ��

//       8. list(list<Type> IList, const Allocator& Al)
//           : ���ø��� �̿��� �ʱ�ȭ�� list��ü�� IList�� �Ҵ��ڱ��� �����ϴ� list ������.. 

//       9. template <value�ڷ��� �����̳ʿ�Ҹ�>    
//           : ���� �����̳� class ��ü�� �����ϸ�, �� ������ value�ڷ����� ������ �ڷ������� ����

//       10. list(Iterator First, Iterator Last)
//           : (9���� template ���� ����) ���ͷ����͸� ���� �������̽� ������ ���� First ~ Last�� begin ~ end�� ��� ��尡 ����

//       11. list(Iterator First, Iterator Last, Allocator& Al)
//           : (9���� template ���� ����) ���ͷ����͸� ���� �������̽� ������ ���� First ~ Last�� begin ~ end�� ��� ��尡 �����ϰ�, �Ҵ��ڱ��� �����ϴ� list ������.. 


//     # list class method(����Լ�)
//       1. (const) value�ڷ���& front() (const);										
//           : 1��° linked list ��Ұ� ���� ��ȯ (value�� �ڷ����� �����͸�, ������ �Ұ�, ���ȭ)

//       2. (const) value�ڷ���& back() (const);											
//           : ������ linked list ��� ���� ��ȯ (value�� �ڷ����� �����͸�, ������ �Ұ�, ���ȭ)

//       3. iterator begin();		
//           : 1��° linked list ����� �ּҰ�

//       4. iterator end();
//           : ������ linked list ����� ���� ��ġ�� �ּҰ�

//       5. void clear();
//           : linked list�� ��� ��� ����

//       6. void remove(const �ڷ���& value);												
//           : (��Ұ� ���� ����) linked list ������ ��� �� value ���� ��ġ�ϴ� ��ҵ� ���� ����

//       7. iterator erase(iterator Where);
//           : (�ּ� ���� ����1) linked list���� ������ ��ġ���� ��Ұ��� ����

//       8. iterator erase(iterator first, iterator last);
//           : (�ּ� ���� ����2) linked list���� �ּҰ��� first~last ������ ��ġ�ϴ� linked list�� ��ҵ��� ���±�� ����

//       9. void pop_front();
//           : (pop ����1) linked list 1��°�� ��ġ�� ��Ҹ� ���� + 2��° ��ġ���� 1��° ��ġ������ ����

//       10. void pop_back();
//           : (pop ����2) linked list �������� ��ġ�� ��Ҹ� ���� + ������ �� ��ġ�� ���� ��� �ּҰ� ����

//       11. void push_front(�ڷ���&& value);
//           : (push �߰�1) linked list 1��° ��ġ�� ��Ұ��� value�� ��� �߰�

//       12. void push_back(�ڷ���&& value);
//           : (push �߰�2) linked list ������ ��ġ�� ��Ұ��� value�� ��� �߰�

//       13. void insert(iterator Where, �ڷ���&& value);
//           : (�ּ� ���� �߰�2) linked list���� ������ ��ġ���� ��Ұ��� value�� ��� �߰�

//       14. void emplace(iterator Where, �ڷ���&& value);
//           : (�ּ� ���� �߰�2) linked list���� ������ ��ġ���� �����ϴ� ���� ��带 ���� + ��Ұ��� value�� ��� ��ü�Ͽ� �߰�

//       15. void assign(InputIterator First, InputIterator Last);
//           : �ش� list ��ü��, � �����̳� class ��ü�� First ~ Last������ ���� �Ҵ��� 

//       16. bool empty() const;
//           : linked list�� ��� �ִ��� ���� bool�� ��ȯ

//       17. void swap(list<Type, Allocator>& ��� list��ü��);
//           : 2���� linked list �� ��Ҹ� ��ȯ

//       18. size_type size() const;
//           : linked list�� ����� �� ������ ��ȯ

//       19. get_allocator() const;
//           : �ش� �����̳� class ��ü(= list)�� �Ҵ��� ���纻 ��ȯ

//       20. void reverse();
//           : linked list ��Ҹ� �������� ������ ������ ��

//       21. void sort();
//           : ����� ��Ҹ� �����Ͽ� ������ ������ �� (��������)

//       22. void merge(list<Type, Allocator>& ��� list��ü��);
//           : ����Ʈ �պ� ���� (��������)

//       23. sizeũ���ڷ��� capacity() const
//           : �ش� Array list ��ü���� ���� ������ �뷮(�޸� ũ��, bytes)�� ��ȯ�ϴ� �Լ�

//       24. void shrink_to_fit()
//           : �ش� Array list ��ü����  �Ҵ�� capacity(�޸�) �� �� ���̴� �κ��� ���̴� �Լ�

//       25. void reserve(sizeũ���ڷ��� n = 0)
//           : �ش� Array list ��ü���� n(�޸� ũ��, bytes)��ŭ �뷮�� �ش��ϴ� capacity(�޸�)�� �Ҵ��ϴ� �Լ�


//  - vector 
//    : C++���� �������� �����迭(dynamic Arraylist)�� ���������� ������ class

//     # vector ��ü ���� ����
//       : vector<�ڷ���> vector��ü�� + (������ ���� parameters...);     <- new �����ڸ� ���� �ʾƵ� ���� Ÿ class������ ��ü�����Ͱ� ���� �κп� �ٷ� vector ������ �Լ��� ������ �������� vector ��ü �����Ҵ�
//          -> (�߿�) {�迭��1 ... } �̷������� ���� �ִ°ŵ� ����

//     # vector �޼��� ȣ�� ����
//       : vector��ü��.�޼����(parameters....);

//     # vector ���ͷ����� ���� ���� ����
//       : vector<�ڷ���> :: iterator list���ͷ����Ͱ�ü��;
//          -> (�߿�) �̸� ���� vector ���� ����� �����ּҰ��� ���ͷ����� ��ȯ���� �����Ͽ� ���� ���� = vector�� ���� ��� �ּҰ��� ++, --�� ���� ���� ���س� �� �ְ� ������ ���� 


//     # vector Constructor(������)
//       : new �����ڿ� ���X, �����Ҷ� �ٷ� ���� class ��ü�����Ͱ� �;� �� ��ġ�� vector��ü��() �κп� ���

//       1. vector()
//           : vector�� �⺻ ������(default constructor)

//       2. vector(vector& arraylist)
//           : vector�� ���� ������ (Ư�� arraylist ���� ����)

//       3. vector(vector&& arraylist)
//           : vector�� �̵� ������ (Ư�� arraylist ���� ����)

//       4. vector(size Count)
//           : value ���� 0���� �ϴ� Count��ŭ�� ������ �迭 ũ�⸸ŭ vector��ü �ʱ�ȭ��

//       5. vector(size Count, �ڷ���& value)
//           : Count��ŭ�� ������ŭ �迭 ũ�⸦ ���, value ���� ���� array�� �����Ͽ� vector��ü �ʱ�ȭ��

//       6. vector(Allocator& Al)
//           : �Ҵ��� ���� ������
//              -> (�߿�!) vector��ü�� �Ҵ��ڴ� vector.getAllocator()�� ����

//       7. vector(size Count, �ڷ���& value, Allocator& Al)
//           : Count��ŭ�� ������ŭ �迭 ũ�⸦ ���, value ���� ���� array�� �����ϵ�, �Ҵ��ڱ��� �����ϴ� ������.. vector��ü �ʱ�ȭ��

//       8. vector(vector<Type> VList, const Allocator& Al)
//           : ���ø��� �̿��� �ʱ�ȭ�� vector��ü�� VList�� �Ҵ��ڱ��� �����ϴ� vector ������.. 

//       9. template <value�ڷ��� �����̳ʿ�Ҹ�>    
//           : ���� �����̳� class ��ü�� �����ϸ�, �� ������ value�ڷ����� ������ �ڷ������� ����

//       10. vector(Iterator First, Iterator Last)
//           : (9���� template ���� ����) ���ͷ����͸� ���� �������̽� ������ ���� First ~ Last�� begin ~ end�� ��� �迭�� ����

//       11. vector(Iterator First, Iterator Last, Allocator& Al)
//           : (9���� template ���� ����) ���ͷ����͸� ���� �������̽� ������ ���� First ~ Last�� begin ~ end�� ��� �迭�� �����ϰ�, �Ҵ��ڱ��� �����ϴ� vector ������.. 


//     # vector class method(����Լ�)
//       1. (const) value�ڷ���& front() (const);										
//           : 1��° Array list ��Ұ� ���� ��ȯ (value�� �ڷ����� �����͸�, ������ �Ұ�, ���ȭ)

//       2. (const) value�ڷ���& back() (const);											
//           : ������ Array list ��� ���� ��ȯ (value�� �ڷ����� �����͸�, ������ �Ұ�, ���ȭ)

//       3. (const) value�ڷ���& at(size�ڷ��� index) (const);													
//           : ������ index�� Array list ��Ұ� ���� ��ȯ (value�� �ڷ����� �����͸�, ������ �Ұ�, ���ȭ)
//              -> vector ��ü�� [] �����ڸ� ����� vector��ü��[index]�� ����

//       4. iterator begin();	                          <->  rbegin();
//           : 1��° Array list ����� �ּҰ�                     : �ڿ��� 1��° Array list ����� �ּҰ�

//       5. iterator end();	                              <->  rend();
//           : ������ Array list ����� ���� ��ġ�� �ּҰ�         : ù��° Array list ����� ���� ��ġ�� �ּҰ�

//       6. void clear();
//           : Array list�� ��� ��� ����

//       7. iterator erase(iterator Where);
//           : (�ּ� ���� ����1) Array list���� ������ ��ġ���� ��Ұ��� ����

//       8. iterator erase(iterator first, iterator last);
//           : (�ּ� ���� ����2) Array list���� �ּҰ��� first~last ������ ��ġ�ϴ� Array list�� ��ҵ��� ���±�� ����

//       9. void pop_front();
//           : (pop ����1) Array list 1��°�� ��ġ�� ��Ҹ� ���� + 2��° ��ġ���� 1��° ��ġ������ ����

//       10. void pop_back();
//           : (pop ����2) Array list �������� ��ġ�� ��Ҹ� ���� + ������ �� ��ġ�� ���� ��� �ּҰ� ����

//       11. void push_front(�ڷ���&& value);
//           : (push �߰�1) Array list 1��° ��ġ�� ��Ұ��� value�� �迭��� �߰�

//       12. void push_back(�ڷ���&& value);
//           : (push �߰�2) Array list ������ ��ġ�� ��Ұ��� value�� �迭��� �߰�

//       13. void insert(iterator Where, �ڷ���&& value);
//           : (�ּ� ���� �߰�2) Array list���� ������ ��ġ���� ��Ұ��� value�� �迭��� �߰�

//       14. void emplace(iterator Where, �ڷ���&& value);
//           : (�ּ� ���� �߰�2) Array list���� ������ ��ġ���� �����ϴ� ���� ���� + ��Ұ��� value�� ����

//       15. void assign(InputIterator First, InputIterator Last);
//           : �ش� vector ��ü��, � �����̳� class ��ü�� First ~ Last������ ���� �Ҵ��� 

//       16. bool empty() const;
//           : Array list�� ��� �ִ��� ���� bool�� ��ȯ

//       17. void swap(list<Type, Allocator>& ��� list��ü��);
//           : 2���� Array list �� ��Ҹ� ��ȯ

//       18. size_type size() const;
//           : Array list�� ����� �� ������ ��ȯ

//       19. get_allocator() const;
//           : �ش� �����̳� class ��ü(= vector)�� �Ҵ��� ���纻 ��ȯ

//       20. void reverse();
//           : Array list ��Ҹ� �������� ������ ������ ��

//       21. void sort();
//           : ����� ��Ҹ� �����Ͽ� ������ ������ �� (��������)

//       22. void merge(Array<Type, Allocator>& ��� list��ü��);
//           : ����Ʈ �պ� ���� (��������)

//       22. void merge(Array<Type, Allocator>& ��� list��ü��);
//           : ����Ʈ �պ� ���� (��������)

//       23. sizeũ���ڷ��� capacity() const
//           : �ش� Array list ��ü���� ���� ������ �뷮(�޸� ũ��, bytes)�� ��ȯ�ϴ� �Լ�

//       24. void shrink_to_fit()
//           : �ش� Array list ��ü����  �Ҵ�� capacity(�޸�) �� �� ���̴� �κ��� ���̴� �Լ�

//       25. void reserve(sizeũ���ڷ��� n = 0)
//           : �ش� Array list ��ü���� n(�޸� ũ��, bytes)��ŭ �뷮�� �ش��ϴ� capacity(�޸�)�� �Ҵ��ϴ� �Լ�