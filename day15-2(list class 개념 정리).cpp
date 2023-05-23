//  - List 
//    : C++에서 이중 연결 리스트(doubly linked list)를 공식적으로 구현한 class

//     # List 객체 생성 형식
//       : list<자료형> list객체명 + (생성자 적용 parameters...);    <- new 연산자를 쓰지 않아도 원래 타 class에서는 객체포인터가 오는 부분에 바로 list 생성자를 적용해 힙영역에 list 객체 동적할당

//     # List 메서드 호출 형식
//       : list객체명.메서드명(parameters....);

//     # List 이터레이터 변수 선언 형식
//       : list<자료형> :: iterator list이터레이터객체명;
//          -> (중요) 이를 통해 list 내부 요소의 유사주소값인 이터레이터 반환값을 대입하여 저장 가능 = list의 다음 노드 주소값을 ++, --를 통해 쉽게 구해낼 수 있고 역참조 가능 


//     # list Constructor(생성자)
//       : new 연산자에 사용X, 선언할때 바로 원래 class 객체포인터가 와야 할 위치인 list객체명() 부분에 사용

//       1. list()
//           : list의 기본 생성자(default constructor) = 노드 없는 상태
   
//       2. list(list& node)
//           : list의 복사 생성자 (특정 node 깊은 복사)
   
//       3. list(list&& node)
//           : list의 이동 생성자 (특정 node 얕은 복사)
 
//       4. list(size Count)
//           : value 값을 0으로 하는 Count만큼의 갯수를 가진 node를 생성하여 list객체 초기화함
   
//       5. list(size Count, 자료형& value)
//           : Count만큼의 개수만큼, value 값을 지닌 node를 생성하여 list객체 초기화함
  
//       6. list(Allocator& Al)
//           : 할당자 복사 생성자
//              -> (중요!) list객체의 할당자는 list.getAllocator()로 추출
 
//       7. list(size Count, 자료형& value, Allocator& Al)
//           : Count만큼의 개수만큼, value 값을 지닌 node를 생성하되, 할당자까지 복사하는 생성자.. list객체 초기화함
  
//       8. list(list<Type> IList, const Allocator& Al)
//           : 템플릿을 이용해 초기화한 list객체인 IList에 할당자까지 복사하는 list 생성자.. 
  
//       9. template <value자료형 컨테이너요소명>    
//           : 이후 컨테이너 class 객체를 생성하면, 그 내부의 value자료형을 지정한 자료형으로 구현
  
//       10. list(Iterator First, Iterator Last)
//           : (9번의 template 선언 선행) 이터레이터를 통한 인터페이스 조작을 위한 First ~ Last를 begin ~ end로 삼는 노드가 생성
   
//       11. list(Iterator First, Iterator Last, Allocator& Al)
//           : (9번의 template 선언 선행) 이터레이터를 통한 인터페이스 조작을 위한 First ~ Last를 begin ~ end로 삼는 노드가 생성하고, 할당자까지 복사하는 list 생성자.. 


//     # list class method(멤버함수)
//       1. (const) value자료형& front() (const);										
//           : 1번째 linked list 요소값 참조 반환 (value값 자료형이 포인터면, 역참조 불가, 상수화)
 
//       2. (const) value자료형& back() (const);											
//           : 마지막 linked list 요소 참조 반환 (value값 자료형이 포인터면, 역참조 불가, 상수화)
 
//       3. iterator begin();		
//           : 1번째 linked list 요소의 주소값
  
//       4. iterator end();
//           : 마지막 linked list 요소의 다음 위치의 주소값
 
//       5. void clear();
//           : linked list의 모든 요소 삭제

//       6. void remove(const 자료형& value);												
//           : (요소값 기준 삭제) linked list 내부의 요소 중 value 값과 일치하는 요소들 전부 삭제
 
//       7. iterator erase(iterator Where);
//           : (주소 기준 삭제1) linked list에서 지정된 위치값의 요소값을 제거
 
//       8. iterator erase(iterator first, iterator last);
//           : (주소 기준 삭제2) linked list에서 주소값이 first~last 범위에 위치하는 linked list의 요소들을 뭉태기로 제거
 
//       9. void pop_front();
//           : (pop 삭제1) linked list 1번째에 위치한 요소를 삭제 + 2번째 위치값을 1번째 위치값으로 지정
 
//       10. void pop_back();
//           : (pop 삭제2) linked list 마지막에 위치한 요소를 삭제 + 마지막 전 위치의 다음 노드 주소값 변경
  
//       11. void push_front(자료형&& value);
//           : (push 추가1) linked list 1번째 위치에 요소값이 value인 노드 추가
 
//       12. void push_back(자료형&& value);
//           : (push 추가2) linked list 마지막 위치에 요소값이 value인 노드 추가
   
//       13. void insert(iterator Where, 자료형&& value);
//           : (주소 기준 추가2) linked list에서 지정된 위치값의 요소값이 value인 노드 추가
 
//       14. void emplace(iterator Where, 자료형&& value);
//           : (주소 기준 추가2) linked list에서 지정된 위치값에 존재하는 기존 노드를 삭제 + 요소값이 value인 노드 대체하여 추가
    
//       15. void assign(InputIterator First, InputIterator Last);
//           : 해당 list 객체에, 어떤 컨테이너 class 객체의 First ~ Last까지의 값을 할당함 

//       16. bool empty() const;
//           : linked list가 비어 있는지 여부 bool로 반환

//       17. void swap(list<Type, Allocator>& 대상 list객체명);
//           : 2개의 linked list 간 요소를 교환

//       18. size_type size() const;
//           : linked list의 요소의 총 개수를 반환

//       19. get_allocator() const;
//           : 해당 컨테이너 class 객체(= list)의 할당자 복사본 반환

//       20. void reverse();
//           : linked list 요소를 역순으로 순서를 변경해 둠

//       21. void sort();
//           : 목록의 요소를 정렬하여 순서를 변경해 둠 (오름차순)

//       22. void merge(list<Type, Allocator>& 대상 list객체명);
//           : 리스트 합병 정렬 (오름차순)

//       23. size크기자료형 capacity() const
//           : 해당 Array list 객체에서 저장 가능한 용량(메모리 크기, bytes)을 반환하는 함수

//       24. void shrink_to_fit()
//           : 해당 Array list 객체에서  할당된 capacity(메모리) 중 안 쓰이는 부분을 줄이는 함수

//       25. void reserve(size크기자료형 n = 0)
//           : 해당 Array list 객체에서 n(메모리 크기, bytes)만큼 용량에 해당하는 capacity(메모리)를 할당하는 함수


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

	// list 멤버함수 관련
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