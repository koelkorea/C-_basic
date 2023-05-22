//  - vector 
//    : C++���� �������� �����迭(dynamic Arraylist)�� ���������� ������ class

//     # vector ��ü ���� ����
//       : vector<�ڷ���> vector��ü�� = new vector();   <- vector �����ڸ� ���� �������� vector ��ü �����Ҵ�

//     # vector �޼��� ȣ�� ����
//       : vector��ü��.�޼����(parameters....);


//     # vector Constructor(������)
//       1. vector()
//           : vector�� �⺻ ������(default constructor)
//    
//       2. vector(vector& node)
//           : vector�� ���� ������ (Ư�� node ���� ����)
//    
//       3. vector(vector&& node)
//           : vector�� �̵� ������ (Ư�� node ���� ����)
//    
//       4. vector(size Count)
//           : value ���� 0���� �ϴ� Count��ŭ�� ������ ���� node�� �����Ͽ� vector��ü �ʱ�ȭ��
//    
//       5. vector(size Count, �ڷ���& value)
//           : Count��ŭ�� ������ŭ, value ���� ���� array�� �����Ͽ� vector��ü �ʱ�ȭ��
//    
//       6. vector(Allocator& Al)
//           : �Ҵ��� ���� ������
//              -> (�߿�!) vector��ü�� �Ҵ��ڴ� vector.getAllocator()�� ����
//    
//       7. vector(size Count, �ڷ���& value, Allocator& Al)
//           : Count��ŭ�� ������ŭ, value ���� ���� array�� �����ϵ�, �Ҵ��ڱ��� �����ϴ� ������.. vector��ü �ʱ�ȭ��
//    
//       8. vector(vector<Type> VList, const Allocator& Al)
//           : ���ø��� �̿��� �ʱ�ȭ�� vector��ü�� VList�� �Ҵ��ڱ��� �����ϴ� vector ������.. 
//    
//       9. template <value�ڷ��� �����̳ʿ�Ҹ�>    
//           : ���� �����̳� class ��ü�� �����ϸ�, �� ������ value�ڷ����� ������ �ڷ������� ����
//    
//       10. vector(Iterator First, Iterator Last)
//           : (9���� template ���� ����) ���ͷ����͸� ���� �������̽� ������ ���� First ~ Last�� begin ~ end�� ��� �迭�� ����
//    
//       11. vector(Iterator First, Iterator Last, Allocator& Al)
//           : (9���� template ���� ����) ���ͷ����͸� ���� �������̽� ������ ���� First ~ Last�� begin ~ end�� ��� �迭�� �����ϰ�, �Ҵ��ڱ��� �����ϴ� vector ������.. 


//     # vector class method(����Լ�)
//       1. (const) value�ڷ���& front() (const);										
//           : 1��° Array list ��Ұ� ���� ��ȯ (value�� �ڷ����� �����͸�, ������ �Ұ�, ���ȭ)
//    
//       2. (const) value�ڷ���& back() (const);											
//           : ������ Array list ��� ���� ��ȯ (value�� �ڷ����� �����͸�, ������ �Ұ�, ���ȭ)
//    
//       3. iterator begin();		
//           : 1��° Array list ����� �ּҰ�
//    
//       4. iterator end();
//           : ������ Array list ����� ���� ��ġ�� �ּҰ�
//    
//       5. void clear();
//           : Array list�� ��� ��� ����
//    
//       6. void remove(const �ڷ���& value);												
//           : (��Ұ� ���� ����) Array list ������ ��� �� value ���� ��ġ�ϴ� ��ҵ� ���� ����
//    
//       7. iterator erase(iterator Where);
//           : (�ּ� ���� ����1) Array list���� ������ ��ġ���� ��Ұ��� ����
//    
//       8. iterator erase(iterator first, iterator last);
//           : (�ּ� ���� ����2) Array list���� �ּҰ��� first~last ������ ��ġ�ϴ� Array list�� ��ҵ��� ���±�� ����
//    
//       9. void pop_front();
//           : (pop ����1) Array list 1��°�� ��ġ�� ��Ҹ� ���� + 2��° ��ġ���� 1��° ��ġ������ ����
//    
//       10. void pop_back();
//           : (pop ����2) Array list �������� ��ġ�� ��Ҹ� ���� + ������ �� ��ġ�� ���� ��� �ּҰ� ����
//    
//       11. void push_front(�ڷ���&& value);
//           : (push �߰�1) Array list 1��° ��ġ�� ��Ұ��� value�� �迭��� �߰�
//    
//       12. void push_back(�ڷ���&& value);
//           : (push �߰�2) Array list ������ ��ġ�� ��Ұ��� value�� �迭��� �߰�
//    
//       13. void insert(iterator Where, �ڷ���&& value);
//           : (�ּ� ���� �߰�2) Array list���� ������ ��ġ���� ��Ұ��� value�� �迭��� �߰�
//    
//       14. void emplace(iterator Where, �ڷ���&& value);
//           : (�ּ� ���� �߰�2) Array list���� ������ ��ġ���� �����ϴ� ���� ���� + ��Ұ��� value�� ����
//    
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

#include <iostream>
#include <vector>

using namespace std;

int main() {

	// vector()
	vector <int> list01;

	// vector(size Count)
	vector <int> list02(7);

	// list(size Count, Type& Val)
	vector <int> list03(6, 3);

	// list(size Count, Type & Val, Allocator & Al)
	vector <int> list04(3, 7, list03.get_allocator());

	// list(_Alloc & _Al)
	vector <int> list05(list03.get_allocator());

	// list(list& Right)
	vector <int> list06(list04);

	vector <int>::iterator list2_Iter = list02.begin();
	list2_Iter++;
	list2_Iter++;

	// list(Iterator First, Iterator Last)
	vector <int> list07(list02.begin(), list2_Iter);

	int ary[] = { 9, 5, 1, 7, 5, 3, 4, 5, 6, 8, 5, 2, 0 };

	// list(Iterator First, Iterator Last)
	vector <int> list08(ary + 2, ary + 6);

	vector <int>::iterator list3_Iter = list03.begin();
	list3_Iter++;
	list3_Iter++;
	list3_Iter++;

	// list(Iterator First, Iterator Last, Allocator& Al)
	vector <int> list09(list03.begin(), list3_Iter, list03.get_allocator());

	// list(Iterator First, Iterator Last, Allocator& Al)
	vector <int> list10(ary + 1, ary + 8, list03.get_allocator());

	// list ����Լ� ����
	vector <int>::iterator _Iter;

	cout << "list01 " << list01.size() << " ="; for (vector <int>::iterator _Iter = list01.begin(); _Iter != list01.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list02 " << list02.size() << " ="; for (vector <int>::iterator _Iter = list02.begin(); _Iter != list02.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list03 " << list03.size() << " ="; for (vector <int>::iterator _Iter = list03.begin(); _Iter != list03.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list04 " << list04.size() << " ="; for (vector <int>::iterator _Iter = list04.begin(); _Iter != list04.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list05 " << list05.size() << " ="; for (vector <int>::iterator _Iter = list05.begin(); _Iter != list05.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list06 " << list06.size() << " ="; for (vector <int>::iterator _Iter = list06.begin(); _Iter != list06.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list07 " << list07.size() << " ="; for (vector <int>::iterator _Iter = list07.begin(); _Iter != list07.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list08 " << list08.size() << " ="; for (vector <int>::iterator _Iter = list08.begin(); _Iter != list08.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list09 " << list09.size() << " ="; for (vector <int>::iterator _Iter = list09.begin(); _Iter != list09.end(); _Iter++) cout << " " << *_Iter; cout << endl;
	cout << "list10 " << list10.size() << " ="; for (vector <int>::iterator _Iter = list10.begin(); _Iter != list10.end(); _Iter++) cout << " " << *_Iter; cout << endl;

	// list(initializer_list<Type> IList, const Allocator& Al)
	vector<int> list11({ 1, 2, 3, 4 });

	cout << "list11 " << list11.size() << " ="; for (vector <int>::iterator _Iter = list11.begin(); _Iter != list11.end(); _Iter++) cout << " " << *_Iter; cout << endl;
}