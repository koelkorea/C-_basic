//  - vector 
//    : C++에서 가변길이 동적배열(dynamic Arraylist)를 공식적으로 구현한 class

//     # vector 객체 생성 형식
//       : vector<자료형> vector객체명 = new vector();   <- vector 생성자를 통해 힙영역에 vector 객체 동적할당

//     # vector 메서드 호출 형식
//       : vector객체명.메서드명(parameters....);


//     # vector Constructor(생성자)
//       1. vector()
//           : vector의 기본 생성자(default constructor)
//    
//       2. vector(vector& node)
//           : vector의 복사 생성자 (특정 node 깊은 복사)
//    
//       3. vector(vector&& node)
//           : vector의 이동 생성자 (특정 node 얕은 복사)
//    
//       4. vector(size Count)
//           : value 값을 0으로 하는 Count만큼의 갯수를 가진 node를 생성하여 vector객체 초기화함
//    
//       5. vector(size Count, 자료형& value)
//           : Count만큼의 개수만큼, value 값을 지닌 array를 생성하여 vector객체 초기화함
//    
//       6. vector(Allocator& Al)
//           : 할당자 복사 생성자
//              -> (중요!) vector객체의 할당자는 vector.getAllocator()로 추출
//    
//       7. vector(size Count, 자료형& value, Allocator& Al)
//           : Count만큼의 개수만큼, value 값을 지닌 array를 생성하되, 할당자까지 복사하는 생성자.. vector객체 초기화함
//    
//       8. vector(vector<Type> VList, const Allocator& Al)
//           : 템플릿을 이용해 초기화한 vector객체인 VList에 할당자까지 복사하는 vector 생성자.. 
//    
//       9. template <value자료형 컨테이너요소명>    
//           : 이후 컨테이너 class 객체를 생성하면, 그 내부의 value자료형을 지정한 자료형으로 구현
//    
//       10. vector(Iterator First, Iterator Last)
//           : (9번의 template 선언 선행) 이터레이터를 통한 인터페이스 조작을 위한 First ~ Last를 begin ~ end로 삼는 배열을 생성
//    
//       11. vector(Iterator First, Iterator Last, Allocator& Al)
//           : (9번의 template 선언 선행) 이터레이터를 통한 인터페이스 조작을 위한 First ~ Last를 begin ~ end로 삼는 배열을 생성하고, 할당자까지 복사하는 vector 생성자.. 


//     # vector class method(멤버함수)
//       1. (const) value자료형& front() (const);										
//           : 1번째 Array list 요소값 참조 반환 (value값 자료형이 포인터면, 역참조 불가, 상수화)
//    
//       2. (const) value자료형& back() (const);											
//           : 마지막 Array list 요소 참조 반환 (value값 자료형이 포인터면, 역참조 불가, 상수화)
//    
//       3. iterator begin();		
//           : 1번째 Array list 요소의 주소값
//    
//       4. iterator end();
//           : 마지막 Array list 요소의 다음 위치의 주소값
//    
//       5. void clear();
//           : Array list의 모든 요소 삭제
//    
//       6. void remove(const 자료형& value);												
//           : (요소값 기준 삭제) Array list 내부의 요소 중 value 값과 일치하는 요소들 전부 삭제
//    
//       7. iterator erase(iterator Where);
//           : (주소 기준 삭제1) Array list에서 지정된 위치값의 요소값을 제거
//    
//       8. iterator erase(iterator first, iterator last);
//           : (주소 기준 삭제2) Array list에서 주소값이 first~last 범위에 위치하는 Array list의 요소들을 뭉태기로 제거
//    
//       9. void pop_front();
//           : (pop 삭제1) Array list 1번째에 위치한 요소를 삭제 + 2번째 위치값을 1번째 위치값으로 지정
//    
//       10. void pop_back();
//           : (pop 삭제2) Array list 마지막에 위치한 요소를 삭제 + 마지막 전 위치의 다음 노드 주소값 변경
//    
//       11. void push_front(자료형&& value);
//           : (push 추가1) Array list 1번째 위치에 요소값이 value인 배열요소 추가
//    
//       12. void push_back(자료형&& value);
//           : (push 추가2) Array list 마지막 위치에 요소값이 value인 배열요소 추가
//    
//       13. void insert(iterator Where, 자료형&& value);
//           : (주소 기준 추가2) Array list에서 지정된 위치값의 요소값이 value인 배열요소 추가
//    
//       14. void emplace(iterator Where, 자료형&& value);
//           : (주소 기준 추가2) Array list에서 지정된 위치값에 존재하는 기존 값을 + 요소값을 value로 변경
//    
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