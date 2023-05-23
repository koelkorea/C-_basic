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


#include <iostream>
#include <list>

using namespace std;

int main() {

	// list()
	list <int> list01;

	// list(size Count)
	list <int> list02(7);

	// list(size Count, Type& Val)
	list <int> list03(6, 3);

	// list(size Count, Type & Val, Allocator & Al)
	list <int> list04(3, 7, list03.get_allocator());

	// list(_Alloc & _Al)
	list <int> list05(list03.get_allocator());

	// list(list& Right)
	list <int> list06(list04);

	list <int>::iterator list2_Iter = list02.begin();
	list2_Iter++;
	list2_Iter++;

	// list(Iterator First, Iterator Last)
	list <int> list07(list02.begin(), list2_Iter);

	int ary[] = { 9, 5, 1, 7, 5, 3, 4, 5, 6, 8, 5, 2, 0 };

	// list(Iterator First, Iterator Last)
	list <int> list08(ary + 2, ary + 6);

	list <int>::iterator list3_Iter = list03.begin();
	list3_Iter++;
	list3_Iter++;
	list3_Iter++;

	// list(Iterator First, Iterator Last, Allocator& Al)
	list <int> list09(list03.begin(), list3_Iter, list03.get_allocator());

	// list(Iterator First, Iterator Last, Allocator& Al)
	list <int> list10(ary + 1, ary + 8, list03.get_allocator());

	// list ����Լ� ����
	list <int>::iterator _Iter;

	cout << "list01 " << list01.size() << " ="; for (list <int>::iterator _Iter = list01.begin(); _Iter != list01.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list02 " << list02.size() << " ="; for (list <int>::iterator _Iter = list02.begin(); _Iter != list02.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list03 " << list03.size() << " ="; for (list <int>::iterator _Iter = list03.begin(); _Iter != list03.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list04 " << list04.size() << " ="; for (list <int>::iterator _Iter = list04.begin(); _Iter != list04.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list05 " << list05.size() << " ="; for (list <int>::iterator _Iter = list05.begin(); _Iter != list05.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list06 " << list06.size() << " ="; for (list <int>::iterator _Iter = list06.begin(); _Iter != list06.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list07 " << list07.size() << " ="; for (list <int>::iterator _Iter = list07.begin(); _Iter != list07.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list08 " << list08.size() << " ="; for (list <int>::iterator _Iter = list08.begin(); _Iter != list08.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list09 " << list09.size() << " ="; for (list <int>::iterator _Iter = list09.begin(); _Iter != list09.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list10 " << list10.size() << " ="; for (list <int>::iterator _Iter = list10.begin(); _Iter != list10.end(); _Iter++) cout << " " << *_Iter; cout << endl;

	// list(initializer_list<Type> IList, const Allocator& Al)
	list<int> list11({ 1, 2, 3, 4 });

	cout << "list11 " << list11.size() << " ="; for (list <int>::iterator _Iter = list11.begin(); _Iter != list11.end(); _Iter++) cout << " " << *_Iter; cout << endl;
}