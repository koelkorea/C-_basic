//  - vector 
//    : C++에서 가변길이 동적배열(dynamic Arraylist)를 공식적으로 구현한 class

//     # vector 객체 생성 형식
//       : vector<자료형> vector객체명 + (생성자 적용 parameters...);     <- new 연산자를 쓰지 않아도 원래 타 class에서는 객체포인터가 오는 부분에 바로 vector 생성자 함수를 적용해 힙영역에 vector 객체 동적할당
//          -> (중요) {배열값1 ... } 이런식으로 값을 주는거도 가능

//     # vector 메서드 호출 형식
//       : vector객체명.메서드명(parameters....);

//     # vector 이터레이터 변수 선언 형식
//       : vector<자료형> :: iterator list이터레이터객체명;
//          -> (중요) 이를 통해 vector 내부 요소의 유사주소값인 이터레이터 반환값을 대입하여 저장 가능 = vector의 다음 노드 주소값을 ++, --를 통해 쉽게 구해낼 수 있고 역참조 가능 


//     # vector Constructor(생성자)
//       : new 연산자에 사용X, 선언할때 바로 원래 class 객체포인터가 와야 할 위치인 vector객체명() 부분에 사용

//       1. vector()
//           : vector의 기본 생성자(default constructor)
 
//       2. vector(vector& arraylist)
//           : vector의 복사 생성자 (특정 arraylist 깊은 복사)
 
//       3. vector(vector&& arraylist)
//           : vector의 이동 생성자 (특정 arraylist 얕은 복사)
  
//       4. vector(size Count)
//           : value 값을 0으로 하는 Count만큼의 갯수를 배열 크기만큼 vector객체 초기화함
   
//       5. vector(size Count, 자료형& value)
//           : Count만큼의 개수만큼 배열 크기를 잡고, value 값을 지닌 array를 생성하여 vector객체 초기화함
  
//       6. vector(Allocator& Al)
//           : 할당자 복사 생성자
//              -> (중요!) vector객체의 할당자는 vector.getAllocator()로 추출
  
//       7. vector(size Count, 자료형& value, Allocator& Al)
//           : Count만큼의 개수만큼 배열 크기를 잡고, value 값을 지닌 array를 생성하되, 할당자까지 복사하는 생성자.. vector객체 초기화함
  
//       8. vector(vector<Type> VList, const Allocator& Al)
//           : 템플릿을 이용해 초기화한 vector객체인 VList에 할당자까지 복사하는 vector 생성자.. 
   
//       9. template <value자료형 컨테이너요소명>    
//           : 이후 컨테이너 class 객체를 생성하면, 그 내부의 value자료형을 지정한 자료형으로 구현
   
//       10. vector(Iterator First, Iterator Last)
//           : (9번의 template 선언 선행) 이터레이터를 통한 인터페이스 조작을 위한 First ~ Last를 begin ~ end로 삼는 배열을 생성
  
//       11. vector(Iterator First, Iterator Last, Allocator& Al)
//           : (9번의 template 선언 선행) 이터레이터를 통한 인터페이스 조작을 위한 First ~ Last를 begin ~ end로 삼는 배열을 생성하고, 할당자까지 복사하는 vector 생성자.. 


//     # vector class method(멤버함수)
//       1. (const) value자료형& front() (const);										
//           : 1번째 Array list 요소값 참조 반환 (value값 자료형이 포인터면, 역참조 불가, 상수화)
   
//       2. (const) value자료형& back() (const);											
//           : 마지막 Array list 요소 참조 반환 (value값 자료형이 포인터면, 역참조 불가, 상수화)

//       3. (const) value자료형& at(size자료형 index) (const);													
//           : 지정된 index의 Array list 요소값 참조 반환 (value값 자료형이 포인터면, 역참조 불가, 상수화)
//              -> vector 객체의 [] 연산자를 사용한 vector객체명[index]와 같음

//       4. iterator begin();	                          <->  rbegin();
//           : 1번째 Array list 요소의 주소값                     : 뒤에서 1번째 Array list 요소의 주소값
   
//       5. iterator end();	                              <->  rend();
//           : 마지막 Array list 요소의 다음 위치의 주소값         : 첫번째 Array list 요소의 이전 위치의 주소값
   
//       6. void clear();
//           : Array list의 모든 요소 삭제
  
//       7. iterator erase(iterator Where);
//           : (주소 기준 삭제1) Array list에서 지정된 위치값의 요소값을 제거
  
//       8. iterator erase(iterator first, iterator last);
//           : (주소 기준 삭제2) Array list에서 주소값이 first~last 범위에 위치하는 Array list의 요소들을 뭉태기로 제거

//       9. void pop_front();
//           : (pop 삭제1) Array list 1번째에 위치한 요소를 삭제 + 2번째 위치값을 1번째 위치값으로 지정

//       10. void pop_back();
//           : (pop 삭제2) Array list 마지막에 위치한 요소를 삭제 + 마지막 전 위치의 다음 노드 주소값 변경
    
//       11. void push_front(자료형&& value);
//           : (push 추가1) Array list 1번째 위치에 요소값이 value인 배열요소 추가
 
//       12. void push_back(자료형&& value);
//           : (push 추가2) Array list 마지막 위치에 요소값이 value인 배열요소 추가
  
//       13. void insert(iterator Where, 자료형&& value);
//           : (주소 기준 추가2) Array list에서 지정된 위치값의 요소값이 value인 배열요소 추가
  
//       14. void emplace(iterator Where, 자료형&& value);
//           : (주소 기준 추가2) Array list에서 지정된 위치값에 존재하는 기존 값을 + 요소값을 value로 변경
 
//       15. void assign(InputIterator First, InputIterator Last);
//           : 해당 vector 객체에, 어떤 컨테이너 class 객체의 First ~ Last까지의 값을 할당함 

//       16. bool empty() const;
//           : Array list가 비어 있는지 여부 bool로 반환

//       17. void swap(list<Type, Allocator>& 대상 list객체명);
//           : 2개의 Array list 간 요소를 교환

//       18. size_type size() const;
//           : Array list의 요소의 총 개수를 반환

//       19. get_allocator() const;
//           : 해당 컨테이너 class 객체(= vector)의 할당자 복사본 반환

//       20. void reverse();
//           : Array list 요소를 역순으로 순서를 변경해 둠

//       21. void sort();
//           : 목록의 요소를 정렬하여 순서를 변경해 둠 (오름차순)

//       22. void merge(Array<Type, Allocator>& 대상 list객체명);
//           : 리스트 합병 정렬 (오름차순)

//       22. void merge(Array<Type, Allocator>& 대상 list객체명);
//           : 리스트 합병 정렬 (오름차순)

//       23. size크기자료형 capacity() const
//           : 해당 Array list 객체에서 저장 가능한 용량(메모리 크기, bytes)을 반환하는 함수

//       24. void shrink_to_fit()
//           : 해당 Array list 객체에서  할당된 capacity(메모리) 중 안 쓰이는 부분을 줄이는 함수

//       25. void reserve(size크기자료형 n = 0)
//           : 해당 Array list 객체에서 n(메모리 크기, bytes)만큼 용량에 해당하는 capacity(메모리)를 할당하는 함수

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

	// list 멤버함수 관련
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