//  # getter, setter와 class포인터를 통한 주의점
//    1. 멤버함수 get, set 역참조와 get, set을 통한 멤버변수 참조 및 수정은 근본적으로 같은 기능임.. 하지만 충분히 햇갈릴 수 있음..
//    2. class 객체의 유효범위 = 지역변수의 유효범위임을 명심하자..(= 객체도 일종의 변수이기 때문)
//    3. (중요!) C++에서 class 포인터와 new연산자를 통한 동적할당을 쓰는 이유?
//        :  C++에서 동적할당이란 크기가 필요할때마다 가변적으로 조절될 수 있다는 이점을 의미하지만, 다른 한편으로는 {}의 영향을 받지 않고 프로그램에서 메모리를 해제하기 전까지 존재함을 의미함
//          (= C++에서 new 연산자를 통해 지역객체로서 동적할당을 수행한다면, 2번의 약점을 넘어 전역변수나 전역객체가 아니라도 {}의 한계를 넘어 해당 객체나 변수에 접근이 가능하다!)
//             -> 동적할당한 메모리에 접근하기 위해서는 그 자료형의 주소값이 필요함 = C++에서 new 연산자를 받는 자료형이 '포인터변수'인 이유
//    4. 3을 역으로 말하면, main()에서 선언된 class의 객체에 대해서는 동적할당이고 그냥 선언이고 상관이 없음


// [quiz 풀이1 - easy... 최대한 주어진 메서드들에 맞춰 직관적으로..풀어보기]
// class와 getter, setter 개념까지 이용한 c++의 동적할당, 해제 기능으로 'linked list'를 통해 다음의 기능을 가진 코드를 작성해라
// 1. 학생 정보 등록
// 2. 학생 정보 삭제
// 3. 학생 정보 전체 리스트 출력
// 4. 전체삭제
// 5. 종료
// -> 메뉴선택하여 실행하기

#include <iostream>
#include <iomanip>

using namespace std;

// 학생 정보를 담는 class
class student {

	// 멤버변수인 이름, 전번은 private로 외부에서 접근불가
private:
	char* name;
	char* phone;

	// 학생정보 class의 멤버변수를 조작하는 멤버함수는 public
public:

	// 학생 class 생성자 with parameter -> 두 멤버변수 전부 NULL
	student(char* _name, char* _phone) {
		name = _name;
		phone = _phone;
	}

	// 학생 class 생성자 no parameter -> 두 멤버변수 전부 NULL
	student() {
		name = NULL;
		phone = NULL;
	}

	// 해당 학생 클래스의 char*로 동적할당 된 멤버변수 2개 전부 동적해제하는 소멸자
	//  -> 멤버 2개 전부 NULL이면, 동작하게 않게 조치 (= 포인터에 기록된 주소값이 NULL인데 뭔 접근이 되겄음?)
	~student() {

		if (name != NULL) {
			delete[] name;
		}

		if (phone != NULL) {
			delete[] phone;
		}
	}

	// char 포인터변수 name의 현 주소값 return함수
	inline char* getName() {
		return name;
	}

	// char 포인터변수 phone의 현 주소값 return함수
	inline char* getPhone() {
		return phone;
	}

	// char 포인터변수 name의 새 주소값을 parameter에 들어온 걸로 갱신해주는 boolean 함수
	inline bool setName(char* _name) {
		name = _name;
		return true;
	}

	// char 포인터변수 phone의 새 주소값을 parameter에 들어온 걸로 갱신해주는 boolean 함수
	inline bool setPhone(char* _phone) {
		phone = _phone;
		return true;
	}
};

// linkedList의 단위가 되는 Node의 단위값으로 student클래스의 포인터변수를 채택
//  -> 이걸로 student 객체를 선언 후 동적할당할 계획
typedef student* NodeElement;

// linkedList의 단위가 되는 Node 정보를 담는 class
class Node {

	// 멤버변수인 노드요소(student 클래스 포인터변수), 다음 Node객체의 주소값을 담는 Node 클래스 포인터변수는 private로 외부에서 접근불가
private:
	NodeElement value;
	Node* link;

	// 대상 Node class의 멤버변수를 조작하는 멤버함수는 public
public:

	// Node 생성자 with parameter-> 두 멤버변수 전부 NULL
	Node(NodeElement _value, Node* _link) {
		value = _value;
		link = _link;
	}

	// Node 생성자 no parameter-> 두 멤버변수 전부 NULL
	Node() {
		value = NULL;
		link = NULL;
	}

	// 해당 Node 클래스의 Node*로 동적할당 된 멤버변수 2개 전부 동적해제하는 소멸자
	//  -> 멤버 2개 전부 NULL이면, 동작하게 않게 조치 (= 포인터에 기록된 주소값이 NULL인데 뭔 접근이 되겄음?)
	~Node() {

		if (value != NULL) {
			// delete 포인터 : 해당 포인터에 존재 및 연계된 포인터가 가르키는 동적할당된 객체를 제거한다 (소멸자에 잘못쓰면 연쇄 삭제 일어남..)
			delete value;
		}

		link = NULL;
	}

	// Node 클래스 포인터변수 value의 현 주소값 return함수
	inline NodeElement getValue() {
		return value;
	}

	// Node 클래스 포인터변수 link의 현 주소값 return함수
	inline Node* getlink() {
		return link;
	}

	// Node 클래스 포인터변수 value의 새 주소값을 parameter에 들어온 걸로 갱신해주는 함수
	inline void setValue(NodeElement data) {
		value = data;
	}

	// Node 클래스 포인터변수 link의 새 주소값을 parameter에 들어온 걸로 갱신해주는 함수
	inline void setlink(Node* _link) {
		link = _link;
	}
};

// linkedList의 시작점 주소를 점화해주는 헤드 Node의 위치값을 담는 class
class SingleList {

private:
	Node* head;

	// 대상 Node class의 멤버변수를 조작하는 멤버함수는 public
public:

	// SingleList 클래스 생성자 
	//  : 해당 클래스를 생성 = 사실상 헤드노드를 생성하는 것
	//    -> 헤드노드는 일단 무조건 존재해야 함(head노드의 위치는 NULL이면 안됨)
	SingleList() {
		head = new Node;
	}

	// 해당 Node 클래스의 Node*로 동적할당 된 멤버변수 2개 전부 동적해제하는 함수
	//  -> 멤버인 head가 NULL이면, 동작하게 않게 조치 (= 포인터에 기록된 주소값이 NULL인데 뭔 접근이 되겄음?)
	~SingleList() {

		if (head != NULL) {
			delete head;
			head = NULL;
		}
	}

	// student 객체 포인터변수를 parameter로 받으면, linkedList에 그 student 객체의 정보에 해당하는 노드 추가후 성공하면 연결하여 true 뱉는 함수
	bool InsertNode(NodeElement data);

	// 출력된 리스트를 보고 순번인 int를 parameter로 받으면, linkedList에 그 순번의 student 객체의 정보에 해당하는 노드 삭제하여 true 뱉는 함수
	bool DeleteNode(int deleteNodenum);

	// linkedList의 head부터 출발해서, 마지막 노드의 student 객체의 정보를 출력해주고, 출력완료시 총 학생수를 뱉는 함수 
	int PrintList();

	// linkedList의 모든 Node 정보 및 student객체 삭제하기
	bool DeleteAll();
	bool DeleteAll_old();
};

//---------------------------------------------------기존 cin.clear를 발전시킨 메서드 cinput--------------------------------------------
void cinclear() {
	if (cin.fail()) {
		cin.clear();
		while (cin.get() != '\n');
	}
	else while (cin.get() != '\n');
}

void cinput(int& n) {
	while (!(cin >> n)) {
		cinclear();
		cout << "(알림) 입력이 잘못되었습니다. 다시 입력하세요!" << endl << endl;
	}
}

void cinput(char& n) {
	while (!(cin >> n)) {
		cinclear();
		cout << "(알림) 입력이 잘못되었습니다. 다시 입력하세요!" << endl << endl;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------

// 메뉴 입력화면에서 메뉴를 받으면 조건부로 기능진행
void PrintMenu(int& menu, SingleList*& head) {

	// 1. 학생정보 입력기능
	if (menu == 1) {

		// -----------------------------------------------------[학생 정보 작성]--------------------------------------------------------------------------
		// 학생 수 입력 받기
		int studentCnt;

		cout << endl << "[1번. 학생개인정보 입력기능]" << endl << endl << "새로 입력할 학생 수를 입력해주십쇼 : ";
		cinput(studentCnt);

		// 각 입력값 크기에 해당하는 동적크기를 갖는 char배열을 만들기 위해, 일단 입력값 자체를 받기 위한 정적 배열을 하나 만들어 준다
		char inputName[100];
		char inputPhoneNumber[100];

		// 입력할 학생 수만큼 이름, 전화번호 입력받기
		for (int i = 0; i < studentCnt; i++) {

			// 이름, 전번 정적배열에 입력
			cout << " ->> " << setw(3) << i + 1 << "번째로 입력할 학생의 '이름'과 '전화번호'를 입력해주세요 : ";
			cin >> inputName >> inputPhoneNumber;

			//------------------------------[student class객체 생성 + 입력한 이름, 전번 객체의 멤버변수로 옮기기]---------------------------

			// 이름의 문자열 길이만큼 char의 동적배열을 메모리에 할당하고, 그 시작주소값을 동적할당된 student 인스턴스 위치의 setName()의 patameter로 대입 후 역참조 실행
			//  -> 해당 student 인스턴스의 멤버변수인 char 포인터인 name의 값을 그 동적할당 char동적배열 시작주소값으로 대입


			// 'name', 'phoneNumber' 만큼의 char 크기만큼의 동적배열을 메모리에 할당하여 생성 후,  
			//  -> 그들의 char 포인터값을 생성자 함수의 parameter로 대입하여 student 객체 인스턴스의 멤버변수 값으로 대입하여 객체 생성
			//     (= 현재 입력하는 학생정보(이름, 정보)를 현재 프로그램이 끝날 때까지 유지하고 접근할 목적으로 동적할당 + 객체 생성까지 세트메뉴로 완료하는 편한 방법)
			student* eachStudent = new student(new char[strlen(inputName) + 1], new char[strlen(inputPhoneNumber) + 1]);

			// trcpy 함수를 통해 문자열 복사
			strcpy_s(eachStudent->getName(), strlen(inputName) + 1, inputName);
			strcpy_s(eachStudent->getPhone(), strlen(inputPhoneNumber) + 1, inputPhoneNumber);

			//--------------------------------------------------------------------------------------------------------------

			// 현 함수의 parameter인 LinkedList의 헤드노드 주소를 가지는 head(SingleList 클래스의 인스턴스)의 멤버함수 insertNode에 eachstudent( 동적할당하여 멤버변수 값을 넣은 student 클래스의 인스턴스)를 parameter로 넣어 실행 
			//  -> 성공 실패 여부에따라 알림 달라지게 함
			if (head->InsertNode(eachStudent) == true) {
				cout << "\t>>>> (알림) 학생 " << i + 1 << "의 정보가 입력 완료.." << endl << endl;
			}
			else {
				cout << "\t>>>> (알림) 학생 " << i + 1 << "의 정보가 입력 실패!" << endl << endl;
			}

		}

	}
	// 2. 특정 학생의 정보 삭제기능
	else if (menu == 2) {

		// 리스트의 학생 수 받음
		int deleteFlag = head->PrintList();

		// 리스트의 학생이 1명 이상 존재할 시, 개별학생 삭제기능 수행!
		if (deleteFlag != 0) {

			cout << endl << "[2번. 개별 학생정보 입력기능]" << endl;

			// 삭제할 학생이 몇번째에 있을지 받을 변수
			int deleteNodenum = 0;

			// 최소한 1번은 삭제할 학생의 index 입력받는데, 그 값이 0보다 크면서, deleteFlag의 값보다 같거나 커야함 (= 삭제 가능 학생index를 입력받으라는 말)
			do {
				cout << endl << " ->> 몇 번째 학생의 정보를 지우고 싶으신가요? : ";
				cinput(deleteNodenum);

				if (deleteNodenum <= 0 && deleteNodenum > deleteFlag) {
					cout << endl << "\t>>>> (경고) 0보다 크고, 존재하는 학생번호의 값을 입력해주세요!" << endl;
				}

			} while (deleteNodenum <= 0 && deleteNodenum > deleteFlag);


			// 삭제 메서드에  Linked의 시작인 head노드의 지울 학생이 몇번째에 있는지 여부를 param으로 수행
			//  -> 성공 실패 여부에따라 알림 달라지게 함
			if (head->DeleteNode(deleteNodenum) == true) {

				cout << "\t>>>> (알림) " << deleteNodenum << "번째 학생 정보 삭제 완료!" << endl << endl;
			}
			else {
				cout << "\t>>>> (알림) " << deleteNodenum << "번째 학생 정보 삭제 실패!" << endl << endl;
			}

		}
		// 리스트의 학생이 0명이면, 삭제 불가 판정
		else {
			cout << "\t>>>> (알림) 현재 삭제할 학생 정보가 존재하지 않음!" << endl << endl;
		}
	}
	// 3. 전체 학생정보 출력기능
	else if (menu == 3) {

		// 리스트의 학생이 1명 이상 존재할 시, 성공문구 출력
		if (head->PrintList() != 0) {

			cout << "\t>>>> (알림) 학생 정보 출력완료!" << endl << endl;
		}
		else {
			cout << "\t>>>> (알림) 학생 정보가 없습니다.." << endl << endl;
		}

	}
	// 4. 전체 학생정보 삭제기능
	else if (menu == 4) {

		if (head->DeleteAll() == true) {
			cout << "\t>>>> (알림) 학생 정보 전체 삭제완료!" << endl << endl;
		}
		else {
			cout << "\t>>>> (알림) 학생 정보가 없거나, 전체 삭제 실패!" << endl << endl;
		}

	}
	else if (menu == 5) {

		// 종료 전에 LinkedList의 SingleList 클래스 기반 동적객체 head노드에 할당된 메모리 해제를 잊지마라 
		head->DeleteAll();
		delete head;

		cout << "\t>>>> (알림) 학생관리 프로그램을 종료합니다..." << endl << endl;

		exit(0);
	}

}

int main() {

	// 학생정보 LinkedList를 시작할 SingleList 클래스 객체를 생성자 함수를 통해 생성후 동적할당(멤벼변수인 head노드까지 생성하고 초기화후 동적할당)하여 
	//  -> 그 메모리 위치를 SingleList 객체 포인터변수 LinkedHead에 대입
	//     (= head의 link는 일단 NULL 초기화.. 등록된 학생정보가 없기 때문)
	SingleList* LinkedHead = new SingleList;

	// 메뉴수행 번호 받아줄 변수 (초기값 0)
	int menuNum = 0;

	while (1) {

		cout << "1. 학생 정보 등록" << endl;
		cout << "2. 학생 정보 삭제" << endl;
		cout << "3. 학생 정보 전체 리스트 출력" << endl;
		cout << "4. 학생 정보 전체삭제" << endl;
		cout << "5. 프로그램 종료" << endl << endl;
		cout << "메뉴번호 선택 :";

		cinput(menuNum);
		PrintMenu(menuNum, LinkedHead);
	}

	return 0;

}




// 1. 개별 학생의 이름, 전화번호를 가진 student 클래스를 데이터로 삼는 Node를 생성하고 그 노드를 linked리스트에 추가 
//    -> 'student 객체 포인터변수'를 parameter로 받으면, linkedList에 그 student 객체의 정보에 해당하는 노드 추가후 성공하면 연결하여 true 뱉는 함수
bool SingleList::InsertNode(NodeElement data) {

	bool flag = false;

	// 입력할 이름, 전화번호가 NULL이 아니면, 입력과정 진행
	if (data->getName() != NULL && data->getPhone() != NULL) {

		// 현재 linkedlist의 마지막으로 붙은 노드를 찾기위한 Node 포인터변수 tmp (현 SingleList 객체의 멤버변수인 Node 클래스 포인터변수인 head(head노드의 주소값)로 초기화)
		Node* tmp = head;

		// head에 붙어있는 1번째 노드를 의미하는 tmp->getlink()를 시작으로 NULL이 나올때까지, tmp의 Node주소값을 tmp->getlink()->getLink()로 갱신
		while (tmp->getlink() != NULL) {

			tmp = tmp->getlink();
		}

		// LinkedList에 추가해줄 Node 객체를 동적할당하고 생성자함수의 parameter로 학생정보에 해당하는 parameter를 통해 전달된 입력된 이름, 전번이 위치한 student 객체의 주소값인 data만 제외 link의 주소값은 NULL로 투입
		//  -> 그 메모리 위치를 Node 객체 포인터변수 studentLinkedNode에 대입
		Node* studentLinkedNode = new Node(data, NULL);

		// (기존 노드 link값 수정) 새로 만든 Node의 주소값을 기존 마지막Node가 위치값을 가지는 Node객체 포인터변수 tmp를 역참조하여 실행한 setlink()의 parameter로 투입
		//  -> 현 마지막 노드에 연결된 Node의 주소값인 link 값을 생성된 Node객체가 위치한 주소값으로 갱신 
		tmp->setlink(studentLinkedNode);

		flag = true;
	}

	return flag;
}

// 2. 특정 학생의 정보들 모두를 삭제하는 기능(그 학생정보가 있는 Node를 메모리 해제)
//    -> 출력된 리스트를 보고 순번인 int를 parameter로 받으면, linkedList에 그 순번의 student 객체의 정보에 해당하는 노드 추가후 연결하여 true 뱉는 함수
bool SingleList::DeleteNode(int deleteNodenum) {

	bool flag = true;

	// 사용자가 0을 입력했을때, 에러를 피하도록 조치 (물론 애초에 0 < deleteNodenum < print에 찍힌 return값 이도록 조치)
	if (deleteNodenum == 0) {

		// 경고문과 함께 false입력
		cout << "\t>>>> (경고!) 0번째 데이터는 존재하지 않는 데이터이므로 삭제할 수 없습니다." << endl;
		return flag = false;
	}

	// 노드의 주소값을 찍을 커서로서 linkedList용 노드포인터
	Node* tmpForCursor = head;

	// 삭제 노드의 주소값을 저장할 linkedList용 노드포인터 (NULL로 초기화 시켜놓음.. tmpForCursor를 직접 삭제 안하는 이유는.. 그 초기값이 head라 예측못한 경우의 수에 head가 지워질수 있음)
	Node* tmpForDelete = NULL;

	// linkedList 헤드 = 0, deleteNodenum에 해당하는 횟수만큼 link를 타서, tmpForDelete값을 찍을 예정
	for (int i = 0; i < deleteNodenum; i++) {

		// 삭제할 노드의 위치 전에 위치한 노드에 도달할 경우?
		if (i == deleteNodenum - 1) {

			// 삭제할 노드의 주소를 받을 tmpForDelete에 삭제노드의 주소를 대입(삭제 전 노드의 link에 입력된 주소값)
			//  -> 삭제 노드를 미리 지정하는 이유
			//     : 1번째 노드가 마지막 노드일때도 head를 기준으로 해당 노드값을 얻을 수 있게 삭제 가능하게 하기 위함 (그전에는 1번노드의 경우 head->getlink() 이런식으로 예외처리 지정)
			tmpForDelete = tmpForCursor->getlink();

			// 삭제할 노드의 다음 노드가 마지막 노드가 아니라면? (= 삭제할 노드가 리스트의 중간에 위치)
			if (tmpForCursor->getlink()->getlink() != NULL) {

				// 삭제 전 노드의 link값을 삭제노드 다음 노드의 주소로 대입
				tmpForCursor->setlink(tmpForCursor->getlink()->getlink());
			}
			// 삭제할 노드의 다음 노드가 마지막 노드라면? (= 삭제할 노드가 리스트의 끝에 위치)
			else {

				// 삭제할 노드 이전노드의 link를 NULL로 저장
				tmpForCursor->setlink(NULL);
			}

		}

		// 루프가 끝날때, 다음 노드로 갱신 (시작인 0의미 = 헤드노드의 주소값)
		tmpForCursor = tmpForCursor->getlink();
	}

	// 삭제노드의 주소값이 들어간 tmpForDelete의 주소를 이용해 Node 객체의 메모리 해제
	delete tmpForDelete;

	return flag;
}


// 3. 전체 학생정보 출력 (몇 명의 학생이 존재하는지를 반환)
//    -> linkedList의 head부터 출발해서, 마지막 노드의 student 객체의 정보를 출력해주고, 출력완료시 총 학생수를 뱉는 함수 
int SingleList::PrintList() {

	// 현재 리스트의 학생수를 받을 변수
	int studentNum = 0;

	// head를 시작으로 linked 리스트를 순회하며 노드의 주소값을 갱신받을 Node포인터 변수
	Node* tmp = head;

	// 노드에 연결된 다른 노드의 주소값인 link가 NULL이 나오는 녀석까지 노드의 주소값을 받을 변수
	while (tmp->getlink() != NULL) {

		tmp = tmp->getlink();

		// 학생값의 갱신은 ++연산자로..
		cout << endl << "학생 " << setw(3) << ++studentNum << "번 정보" << endl;
		cout << " ->> 이름 : " << tmp->getValue()->getName() << endl;
		cout << " ->> 전화번호 : " << setw(3) << tmp->getValue()->getPhone() << endl;
	}

	cout << endl;

	// 몇명의 학생정보가 있는지 갱신
	return studentNum;
}

// 4. 학생정보 리스트 모두를 삭제하는 기능 (전체 노드 삭제기능 포함)
//    -> 출력된 리스트를 보고 순번인 int를 parameter로 받으면, 그 linkedList에 그 순번 이후의 student 객체의 정보에 해당하는 노드 전부를 삭제하여 true 뱉는 함수
bool SingleList::DeleteAll() {

	bool flag = false;

	// head가 가리키는 link의 주소값의 다른 노드의 주소값이 시작
	Node* tmpForNext = head->getlink();
	Node* tmpForDelete = NULL;

	// 애초에 1번째 노드가 존재하지 않는다면, 메서드를 시작하지도 않고, link가 NULL인 끝노드에 도착하면 중단
	//  -> 1개 이상의 학생정보 노드가 존재한다면? 순회하면서 삭제
	while (tmpForNext != NULL) {

		// 삭제 가능함으로 true로
		flag = true;

		// 현재 노드를 삭제할 노드의 주소를 받을 포인터변수에 대입
		tmpForDelete = tmpForNext;

		// 커서노드는 link에 연결된 다음 노드의 주소값을 대입
		tmpForNext = tmpForNext->getlink();

		// 삭제노드를 메모리에 할당된 영역까지 해제헤서 삭제
		delete tmpForDelete;
	}

	// 다 삭제했으면, head의 link 멤버를 null로..
	head->setlink(NULL);

	return flag;


}
