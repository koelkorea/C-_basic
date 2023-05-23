// 컨테이너 클래스(Container Class)
//  : (중요) 여러 개의 요소를 담을 수 있는 데이터 구조를 제공하는 데이터를 저장하고 관리하는 class
//     -> 데이터의 삽입, 삭제, 검색 등 다양한 작업을 수행 가능 
//        (= 알고리즘 풀이에 필수인 이유)
// 
//        ex) 배열, 연결리스트, 스택, 큐...


//   # 컨테이너 클래스(Container Class) 종류.. 
//      : 그냥 당신이 알고 있는 알고리즘에 쓰이는 데이터 저장용 자료구조들이라 생각하면 편함

//        1. 벡터(Vector)
//           : 크기를 동적으로 조정가능한 동적 배열(Array)을 구현한 class 

//        2. 리스트(List)
//           : 연결 리스트(linked list)를 구현한 class

//        3. 큐(Queue)
//           : 선입선출(FIFO) 데이터 구조를 가지는 class

//        4. 스택(Stack)
//           : 후입선출(LIFO) 데이터 구조를 가지는 class

//        5. 세트(Set)
//           : 각 요소가 고유한 중복X 값으로 이루어진 동적 배열(Array)을 구현한 class 

//        6. 맵(Map) / 딕셔너리(Dictionary)
//           : set과 같은 고유한 key - ArrayList와 같은 value 쌍으로 데이터를 저장하는 맵 자료구조를 구현한 class

//        7. 데크(Deque)
//           : 선입선출(FIFO), 후입선출(LIFO)이 모두 가능한 데이터 구조를 가지는 class


//   # (중요!) 컨테이너 클래스(Container Class) 관련 용어

//      1. 템플릿(Template) = JAVA의 제너릭스(generics)
//          : <자료형> 을 의미하는 기호로 일종의 list나 vector와 같은 가변형 동적배열이나, list계열의 linkedList를 특정 class의 객체배열로 사용하기 위해 입력 자료형을 지정하는 역할을 함 
//             -> 쉽게 말해, C언어에서 컨테이너 class 구현할때, node나 list 내부의 value값의 타입을 'typedef value자료형 컨테이너명_element;' 식으로 구현한걸 정식으로 기능화
//                (= 이를 통해 동일한 코드를 다양한 데이터 타입에 대해 재사용하기 쉬워진 효과를 같는 것 또한 동일)

//           - 함수 템플릿(function Template)
//              : 함수의 일반적인 동작을 정의, 함수 호출 시에 '지정된 자료형' 만을 인자로 받아 실제 함수를 생성
// 
//                ex) list(initializer_list<Type> IList, const Allocator& Al);
// 
//           - 클래스 템플릿(class Template)
//              : 클래스의 일반적인 구조를 정의, 클래스의 멤버 변수와 멤버 함수에 대해 '지정된 자료형' 만을 인자로 받아 실제 클래스를 생성

//                ex1) template <value자료형 컨테이너요소명>    
//                     -> 이후 컨테이너 class 객체를 생성하면, 그 내부의 value자료형을 지정한 자료형으로 구현

//                ex2) 컨테이너클래스명 <<value자료형> 객체명 = new 컨테이너클래스명(); 형식도 같은 역할 수행


//      2. 할당자(allocator)
//          : 컨테이너 class 객체의 내부에서 컨테이너의 본체의 메모리를 동적으로 할당하고 해제하는 역할을 담당하는 멤버변수인 객체
//             -> 쉽게 말해, 컨테이너 class 객체를 내부의 컨테이터에 해당하는 부분을 통제하는 컨테이너 클래스의 껍데기이자 컨트롤러(= 파일럿) 같은 역할을 수행하는 존재 
//                (= this와 비슷하게 사용자는 보지 못하지만, 캡슐화된 객체인 이 녀석으로 컨테이너 클래스는 통제됨)

//            ex) 컨테이너객체명.get_allocator()
//                 -> 컨테이너 class 객체의 할당자 참조 방법


//      3. 할당자 복사 생성자(Allocator Copy Constructor)
//          : 어떤 컨테이너 class 객체를 생성하되, 특정 컨테이너 class 객체의 할당자(Allocator)를 복사하여 초기화하는 역할을 수행하는 생성자


//      4. 이터레이터(Iterator) class
//          : 컨테이너 class 객체 내의 각 요소에 접근하고 순회하기 위한 범용성 높은 [C++에서는 포인터와 비슷한 구조] '인터페이스를 제공하는 class'
//            (= 쉽게 말해, 컨테이너 class 계보에 속해 있다면, 공통의 표준화된 class 구조를 사용하여 [C++에서는 유사 포인터를 통한] 내부 요소 참조 및 순회를 가능하게 한다는 것)

//           - 이터레이터의 이점 : 각 자료구조 별로 제각각인 내부 요소 참조 및 접근을 위한 메서드를 쓰지 않아도 됨 
//              1. 컨테이너 class의 캡슐화 구현 달성
//                  : 컨테이너 class의 내부 구조에 대한 정보 없어도, 쉽게 이터레이터의 인터페이스를 써서 컨테이너의 원소를 순회하고 조작가능

//              2. 코드의 범용성과 유지보수성 증가
//                  : 컨테이너 별로 따로 메서드를 쓰지 않아도, 이터레이터의 인터페이스로 조작이 가능하니, 애지간해서는 동작이 보장됨

//           - 컨테이너 클래스 객체의 이터레이터 변수 선언 형식
//              : 컨테이너클래스명<자료형> :: iterator 컨테이너클래스_이터레이터객체명;
//                 -> (중요) 이를 통해 어떤 컨테이너 클래스 객체 요소의 유사주소값인 이터레이터 반환값을 대입하여 저장 가능 = 컨테이너 클래스 객체의 다음 노드 주소값을 ++, --를 통해 쉽게 구해낼 수 있고 역참조 가능 

//           - 이터레이터의 기능 예시
//              1. next()
//                  : 컨테이너 class 객체의 다음 iterator 위치의 데이터로 이동하고, 현재 원소를 반환

//              2. remove()
//                  : 컨테이너 class 객체의 현재 iterator 위치의 요소를 제거

//              3. get()
//                  : 컨테이너 class 객체의 현재 iterator 위치의 요소를 반환


//   # 템플릿(Template) vs 제너릭스(generics)
//     : 템플릿(Template) + 컴파일 과정에서의 타입 check기능 추가된 JAVA의 템플릿 기능


//   # C++에서의 컨테이너 클래스(Container Class) 특징 
//      : C++의 표준 라이브러리(STL)에서 제공되며, 이들은 템플릿(template)을 사용하여 구현되어 있어 다양한 데이터 타입을 지원


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