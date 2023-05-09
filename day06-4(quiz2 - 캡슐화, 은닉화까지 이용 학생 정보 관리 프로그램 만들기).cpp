// getter, setter 개념까지 이용한 c++의 동적할당, 해제 기능으로 'linked list'를 통해 다음의 기능을 가진 코드를 작성해라
// 1. 학생 정보 등록
// 2. 학생 정보 삭제
// 3. 학생 정보 전체 리스트 출력
// 4. 전체삭제
// 5. 종료
// -> 메뉴선택하여 실행하기

#include <iostream>
#include <iomanip>

using namespace std;

class student {
	private:
		char* name;
		char* phone;

	public:
		inline void init() {
			name = NULL;
			phone = NULL;
		}

		inline void DeleteData() {

			if (name != NULL) {
				delete[] name;
			}

			if (phone != NULL) {
				delete[] phone;
			}
		}

		inline char* getName() {
			return name;
		}

		inline char* getPhone() {
			return phone;
		}

		inline bool setName(char* _name) {
			name = _name;
			return true;
		}

		inline bool setPhone(char* _phone) {
			phone = _phone;
			return true;
		}
};

typedef student* NodeElement;

class Node {
	private:
		NodeElement value;
		Node* link;

	public:
		void init() {
			value = NULL;
			link = NULL;
		}

		void Delete(){

			delete value;
			delete link;
		}

		inline NodeElement getValue() {
			return value;
		}

		inline Node* getlink() {
			return link;
		}

		inline void setValue(NodeElement data) {
			value = data;
		}

		inline void setlink(Node* _link) {
			link = _link;
		}
};

class SingleList {
	private:
		Node* head;

	public:
		void init() {
			head = NULL;
		}

		void Delete() {
			delete head;
			head = NULL;
		}

		bool InsertNode(NodeElement data);
		bool DeleteNode(int deleteNodenum);
		bool DeleteAll();
		int PrintList();
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
void PrintMenu(int& menu, SingleList& head) {

	// 1. 학생정보 입력기능
	if (menu == 1) {

		// -----------------------------------------------------[학생 정보 STU 생성 & 작성]--------------------------------------------------------------------------
		// 학생 수 입력 받기
		int studentCnt;

		cout << endl << "[1번. 학생개인정보 입력기능]" << endl << endl << "새로 입력할 학생 수를 입력해주십쇼 : ";
		cinput(studentCnt);

		// 각 입력값 크기에 해당하는 동적크기를 갖는 char배열을 만들기 위해, 일단 입력값 자체를 받기 위한 정적 배열을 하나 만들어 준다
		char inputName[100];
		char inputPhoneNumber[100];

		// 입력할 학생 수만큼 이름, 전화번호 입력받기
		for (int i = 0; i < studentCnt; i++) {

			student* eachStudent = new student;
			
			eachStudent->init();

			cout << " ->> " << setw(3) << i + 1 << "번째로 입력할 학생의 '이름'과 '전화번호'를 입력해주세요 : ";
			cin >> inputName >> inputPhoneNumber;

			//------------------------------[Node에 연결된 STU 구조체에 입력한 이름, 전번 옮기기]---------------------------

			// 이름의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
			eachStudent->setName(new char[strlen(inputName) + 1]);

			// 정적배열에 입력된 이름 문자열을 새로 적은 문자열로 1자씩 복사
			for (int j = 0; j <= strlen(inputName); j++) {
				eachStudent->getName()[j] = inputName[j];

			}

			// 전화번호의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
			eachStudent->setPhone(new char[strlen(inputPhoneNumber) + 1]);

			// 정적배열에 입력된 전화번호 문자열을 새로 적은 문자열로 1자씩 복사
			for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
				eachStudent->getPhone()[j] = inputPhoneNumber[j];
			}

			//--------------------------------------------------------------------------------------------------------------

			// 입력 메서드에 입력한 학생 해당 정보와, Linked의 시작인 head노드의 시작주소값을 가지는 Node포인터변수를 param으로 수행
			//  -> 성공 실패 여부에따라 알림 달라지게 함
			if (head.InsertNode(eachStudent) == true) {
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
		int deleteFlag = head.PrintList();

		// 리스트의 학생이 1명 이상 존재할 시, 개별학생 삭제기능 수행!
		if (deleteFlag != 0) {

			// 삭제할 학생이 몇번째에 있을지 받을 변수
			int deleteNodenum = 0;

			cout << endl << "[2번. 개별 학생정보 입력기능]" << endl;

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
			if (head.DeleteNode(deleteNodenum) == true) {

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
		if (head.PrintList() != 0) {

			cout << "\t>>>> (알림) 학생 정보 출력완료!" << endl << endl;
		}
		else {
			cout << "\t>>>> (알림) 학생 정보가 없습니다.." << endl << endl;
		}

	}
	// 4. 전체 학생정보 삭제기능
	else if (menu == 4) {

		// 삭제 수행 여부에 따라, 성공문구 출력
		if (head.DeleteAll() == true) {

			cout << "\t>>>> (알림) 학생 정보 전체 삭제완료!" << endl << endl;
		}
		else {
			cout << "\t>>>> (알림) 학생 정보가 없거나, 전체 삭제 실패!" << endl << endl;
		}

	}
	else if (menu == 5) {

		// 종료 전에 전역변수인 LinkedList의 head에 할당된 메모리 해제를 잊지마라 
		head.DeleteAll();
		head.Delete();

		cout << "\t>>>> (알림) 학생관리 프로그램을 종료합니다..." << endl << endl;

		exit(0);
	}

}

int main() {

	// 학생정보 LinkedList를 시작할 head 생성
	//  : 소속 STU없음.. link는 1번째 노드가 있으면 그 노드주소.. 없으면 NULL
	SingleList LinkedHead;

	// LinkedList의 head의 link는 일단 NULL 초기화.. (등록된 학생정보가 없음)
	LinkedHead.init();

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
bool SingleList::InsertNode(NodeElement data) {

	bool flag = false;

	// 입력할 이름, 전화번호가 NULL이 아니면, 입력과정 진행
	if (data->getName() != NULL && data->getPhone() != NULL) {

		// 현재 linkedlist의 마지막으로 붙은 노드를 찾기위한 Node 포인터변수 tmp (head노드의 주소값으로 초기화)
		Node* tmp = head;
		
		// head에 붙어있는 노드를 의미하는 tmp->link를 시작으로 NULL이 나올때까지, tmp의 Node주소값을 tmp->link로 갱신
		while (tmp->getlink() != NULL) {

			tmp = tmp->getlink();
		}

		// 추가해줄 STU 구조체(new Node 할 때 같이 생성)를 가지는 linkedlist 생성
		Node* studentLinkedNode = new Node;
		studentLinkedNode->init();

		// 새로 만든 Node의 주소값를 기존 마지막의 link에 대입
		tmp->setlink(studentLinkedNode);

		// 새로 추가할 학생의 이름, 전화번호를 Node와 연결된 STU에 추가 + 추가된 노드의 다음 Node 주소값은 NULL
		studentLinkedNode->setValue(data);

		flag = true;
	}

	return flag;
}

// 2. 특정 학생의 정보들 모두를 삭제하는 기능(그 학생정보가 있는 Node를 메모리 해제)
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

		// 헤드 = 0이고, 루프가 끝날때, 다음 노드로 갱신
		tmpForCursor = tmpForCursor->getlink();
	}

	// 삭제노드의 주속값이 들어간 tmpForDelete의 주소를 이용해 메모리 해제
	delete tmpForDelete;


	return flag;
}

// 3. 전체 학생정보 출력 (몇 명의 학생이 존재하는지를 반환)
int SingleList::PrintList() {

	// 현재 리스트의 학생수를 받을 변수
	int studentNum = 0;

	// head를 시작으로 linked 리스트를 순회하며 노드의 주소값을 갱신받을 Node포인터 변수
	Node* tmp = head;

	// 노드에 연결된 다른 노드의 주소값인 link가 NULL이 나오는 녀석까지 노드의 주소값을 받을 변수
	while (tmp != NULL) {

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

// 4. 전체 학생정보 삭제
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
	head->init();

	return flag;

}