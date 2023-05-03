// new, delete를 이용한 c++의 동적할당, 해제 기능으로 'linked list'를 통해 다음의 기능을 가진 코드를 작성해라
// 1. 학생 정보 등록
// 2. 학생 정보 삭제
// 3. 학생 정보 전체 리스트 출력
// 4. 전체삭제
// 5. 종료
// -> 메뉴선택하여 실행하게

#include <iomanip>    // setw() 자리수 출력
#include <cstring>    
#include <iostream>

using namespace std;

// 구조체 STU : 학생 개개인의 개인정보... 
//  - 이름 : 문자열(string 아니고, char 배열로 받기에 char 포인터변수)
//  - 전화번호 : 문자열(string 아니고, char 배열로 받기에 char 포인터변수)
typedef struct STU {
	char* name;
	char* phoneNumber;
}STU;

typedef STU NodeElement;

// 구조체 Node : 학생 정보 구조체인 STU를 데이터로 받는 linkedList... 단위 Node
//  - value : STU 구조체 (포인터 아님 = 구조체 자체를 멤버로 둠)
//  - link  : 다음 데이터가 위치한 노드의 주소를 둔 Node구조체 포인터 변수
struct Node {

	// (중요) new Node로 하면 자동으로 할당
	NodeElement value;
	Node* link;
};

void PrintMenu(int& menu);
bool InsertNode(Node*& head, NodeElement data);
bool DeleteNode(Node*& head, int deleteNodenum);
bool DeleteAll(Node*& head);
bool PrintList(Node*& head);

void cinclear(int n) {

	if (cin.fail()) {
		cin.clear();
		cin.ignore(n, '\n');
	}
}

void cinput(int& n) {
	while (!(cin >> n)) {
		cin.clear();

		while (cin.get() != '\n') {
			continue;
		}
	}
}

void cinput(char& n) {
	while (!(cin >> n)) {
		cin.clear();

		while (cin.get() != '\n') {
			continue;
		}
	}
}

// 학생정보 LinkedList를 시작할 head
//  : 소속 STU없음.. link는 1번째 노드가 있으면 그 노드주소.. 없으면 NULL
Node* LinkedHead = new Node;

int main() {

	// ----------------------------------[Node 구조체 안의 STU구조체는 new Node;를 하면 자동으로 같이 힙 영역에 할당되는가 실험]-----------------------------

	// 각 입력값 크기에 해당하는 동적크기를 갖는 char배열을 만들기 위해, 일단 입력값 자체를 받기 위한 정적 배열을 하나 만들어 준다
	char* inputName = (char*) "헤드";
	char* inputPhoneNumber = (char*) "전화번호";

	// 이름의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
	LinkedHead->value.name = new char[strlen(inputName) + 1];

	// 정적배열에 입력된 이름 문자열을 새로 적은 문자열로 1자씩 복사
	for (int j = 0; j <= strlen(inputName); j++) {
		LinkedHead->value.name[j] = inputName[j];

	}

	// 전화번호의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
	LinkedHead->value.phoneNumber = new char[strlen(inputPhoneNumber) + 1];

	// 정적배열에 입력된 전화번호 문자열을 새로 적은 문자열로 1자씩 복사
	for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
		LinkedHead->value.phoneNumber[j] = inputPhoneNumber[j];
	}

	cout << "-------Node 구조체 안의 STU구조체는 new Node;를 하면 자동으로 같이 힙 영역에 할당되는가?--------- " << endl << endl;
	cout << " ->> new STU없이 선입력된 LinkedList 시작점에 데이터 입력" << endl;
	cout << " ->> (name) : "  << LinkedHead->value.name << ", (phoneNumber) : " << LinkedHead->value.phoneNumber << endl << endl;
	cout << "-------[결론] 안에 구조체가 있는 구조체를 new로 생성하면, 내부 구조체도 알아서 잘 생성해줌--------" << endl << endl;

	//--------------------------------------------------------------------------------------------------------------------------------------------------------

	// LinkedList의 head의 link는 일단 NULL 초기화.. (등록된 학생정보가 없음)
	LinkedHead->link = NULL;

	// 메뉴수행 번호 받아줄 변수 (초기값 0)
	int menuNum = 0;

	while (1) {

		cout << "1. 학생 정보 등록" << endl;
		cout << "2. 학생 정보 삭제" << endl;
		cout << "3. 학생 정보 전체 리스트 출력" << endl;
		cout << "4. 학생 정보 전체삭제" << endl;
		cout << "5. 프로그램 종료" << endl << endl;
		cout << "메뉴번호 선택 :";

		cin >> menuNum;

		PrintMenu(menuNum);

	}

	return 0;

}

// 메뉴 입력화면에서 메뉴를 받으면 조건부로 기능진행
void PrintMenu(int& menu) {

	// 1. 학생정보 입력기능
	if (menu == 1) {

		// -----------------------------------------------------[학생 정보 STU 생성 & 작성]--------------------------------------------------------------------------
		// 학생 수 입력 받기
		int studentCnt;

		cout << "새로 입력할 학생 수를 입력해주십쇼 : ";
		cin >> studentCnt;

		// 각 입력값 크기에 해당하는 동적크기를 갖는 char배열을 만들기 위해, 일단 입력값 자체를 받기 위한 정적 배열을 하나 만들어 준다
		char inputName[100];
		char inputPhoneNumber[100];

		// 입력할 학생 수만큼 이름, 전화번호 입력받기
		for (int i = 0; i < studentCnt; i++) {

			// STU 구조체 포인터변수에 new 연산자를 통한 메모리에 입력한 학생수에 해당하는 만큼의 크기를 갖는 STU구조체 배열을 할당하고, 그 시작주소를 포인터변수에 대입 
			// (= 힙 영역에 생성된 STU 구조체의 주소값을 call by reference 형식의 레버런스 변수로 넘겨줌)
			//  : 자료형 * 변수명 = new 자료형;   <->   malloc(byte 크기), calloc 등을 쓰던 과거아 다름
			STU* student = new STU;

			cout << " ->> "  << setw(3) << i + 1 << "번째로 입력할 학생의 '이름'과 '전화번호'를 입력해주세요 : ";
			cin >> inputName >> inputPhoneNumber;

			//------------------------------[Node에 연결된 STU 구조체에 입력한 이름, 전번 옮기기]---------------------------

			// 이름의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
			student->name = new char[strlen(inputName) + 1];

			// 정적배열에 입력된 이름 문자열을 새로 적은 문자열로 1자씩 복사
			for (int j = 0; j <= strlen(inputName); j++) {
				student->name[j] = inputName[j];

			}

			// 전화번호의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
			student->phoneNumber = new char[strlen(inputPhoneNumber) + 1];

			// 정적배열에 입력된 전화번호 문자열을 새로 적은 문자열로 1자씩 복사
			for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
				student->phoneNumber[j] = inputPhoneNumber[j];
			}

			//--------------------------------------------------------------------------------------------------------------

			// 입력 메서드에 입력한 학생 해당 정보와, Linked의 시작인 head노드의 시작주소값을 가지는 Node포인터변수를 param으로 수행
			//  -> 성공 실패 여부에따라 알림 달라지게 함
			if (InsertNode(LinkedHead, *student) == true) {

				cout << "   >>>> (알림) 학생 " << i + 1 << "의 정보가 입력 완료.." << endl << endl;
				delete student;
			}
			else {
				cout << "   >>>> (알림) 학생 " << i + 1 << "의 정보가 입력 실패!" << endl << endl;
				delete student;
			}

		}

	}
	// 2. 특정 학생의 정보 삭제기능
	else if (menu == 2) {

		// 현재 등록된 모든 학생들의 정보를 나열함
		//  -> 리스트 출력이 성공하면?
		if (PrintList(LinkedHead) == true) {

			// 삭제할 학생이 몇번째에 있을지 받을 변수
			int deleteNodenum = 0;

			cout << "몇 번째 노드를 지우고 싶으신가요? : ";
			cin >> deleteNodenum;

			// 삭제 메서드에  Linked의 시작인 head노드의 지울 학생이 몇번째에 있는지 여부를 param으로 수행
			//  -> 성공 실패 여부에따라 알림 달라지게 함
			if (DeleteNode(LinkedHead, deleteNodenum) == true) {

				cout << "      >>>> (알림)" << deleteNodenum << "번째 학생 정보 삭제 완료!" << endl << endl;
			}
			else {
				cout << "      >>>> (알림)" << deleteNodenum << "번째 학생 정보 삭제 실패!" << endl << endl;
			}
		}
		//  -> 리스트 출력이 실패시?
		else {
			cout << "      >>>> (알림) 현재 삭제할 학생 정보가 존재하지 않음!" << endl << endl;
		}
	}
	else if (menu == 3) {

		if (PrintList(LinkedHead) == true) {

			cout << " >>>> (알림) 학생 정보 출력완료!" << endl << endl;
		}
		else {
			cout << " >>>> (알림) 학생 정보가 없거나, 출력이 실패!" << endl << endl;
		}

	}
	else if (menu == 4) {

		if (DeleteAll(LinkedHead) == true) {

			cout << " >>>> (알림) 학생 정보 전체 삭제완료!" << endl << endl;
		}
		else {
			cout << " >>>> (알림) 학생 정보가 없거나, 전체 삭제 실패!" << endl << endl;
		}

	}
	else if (menu == 5) {
		cout << " >>>> (알림) 학생관리 프로그램을 종료합니다..." << endl << endl;

		delete LinkedHead;
		exit(0);
	}

}

// 1. 개별 학생의 이름, 전화번호를 가진 STU구조체를 데이터로 삼는 Node를 생성하고 그 노드를 linked리스트에 추가 
bool InsertNode(Node*& head, NodeElement data) {

	bool flag = false;

	// 입력할 이름, 전화번호가 NULL이 아니면, 입력과정 진행
	if (data.name != NULL && data.phoneNumber != NULL) {

		// 현재 linkedlist의 마지막으로 붙은 노드를 찾기위한 Node 포인터변수 tmp (head노드의 주소값으로 초기화)
		Node* tmp = head;

		// head에 붙어있는 노드를 의미하는 tmp->link를 시작으로 NULL이 나올때까지, tmp의 Node주소값을 tmp->link로 갱신
		while (tmp->link != NULL) {

			tmp = tmp->link;
		}

		// 추가해줄 STU 구조체(new Node 할 때 같이 생성)를 가지는 linkedlist 생성
		Node* studentLinked = new Node;

		// 새로 만든 Node의 주소값를 기존 마지막의 link에 대입
		tmp->link = studentLinked;

		// 새로 추가할 학생의 이름, 전화번호를 Node와 연결된 STU에 추가 + 추가된 노드의 다음 Node 주소값은 NULL
		studentLinked->value.name = data.name;
		studentLinked->value.phoneNumber = data.phoneNumber;
		studentLinked->link = NULL;

		flag = true;
	}

	return flag;
}

// 2. 특정 학생의 정보들 모두를 삭제하는 기능(그 학생정보가 있는 Node를 메모리 해제)
bool DeleteNode(Node*& head, int deleteNodenum) {

	bool flag = false;

	// 1번째로 연결된 노드를 삭제하는 경우
	if (deleteNodenum == 1) {

		// Node 포인터변수에 기존 head의 link된 1번쨰 노드 주소 복사
		Node* tmp = head->link;

		// head에 연결된 Node주소를 현재 2번째 노드의 주소값으로 변경 (= 순서변경)
		head->link = head->link->link;

		// 기존 1번쨰 노드 주소를 찾아가서 그 노드의 메모리를 해제
		delete tmp;

		flag = true;

	}
	else {

		Node* tmpForNext = head;
		Node* tmpForDelete = NULL;

		for (int i = 1; i <= deleteNodenum; i++) {

			tmpForNext = tmpForNext->link;
			
			// 삭제할 노드의 위치 전에 위치한 노드에 도달할 경우?
			if (i == deleteNodenum - 1) {

				// 삭제할 노드의 주소를 받을 tmpForDelete에 삭제노드의 주소를 대입(삭제 전 노드의 link에 입력된 주소값)
				tmpForDelete = tmpForNext->link;

				// 삭제할 노드의 다음 노드가 마지막 노드가 아니라면? (= 삭제할 노드가 리스트의 중간에 위치)
				if (tmpForNext->link->link != NULL) {

					// 삭제 전 노드의 link값을 삭제노드 다음 노드의 주소로 대입
					tmpForNext->link = tmpForNext->link->link;
				}
				// 삭제할 노드의 다음 노드가 마지막 노드라면? (= 삭제할 노드가 리스트의 끝에 위치)
				else {

					// 삭제할 노드 이전노드의 link를 NULL로 저장
					tmpForNext->link = NULL;
				}

			}
			// 삭제할 노드 위치에 도달하는 경우
			//  -> 삭제노드의 주속값이 들어간 tmpForDelete의 주소를 이용해 메모리 해제
			else if (i == deleteNodenum) {

				delete tmpForDelete;
			}
		}
		flag = true;
	}

	return flag;
}

bool PrintList(Node*& head) {

	bool flag = false;
	int studentNum = 0;

	Node* tmp = head;

	while (tmp->link != NULL) {

		flag = true;
		tmp = tmp->link;

		cout << endl << "학생 " << setw(3) << ++studentNum << "번 정보" << endl;
		cout << " ->> 이름 : " << tmp->value.name << endl;
		cout << " ->> 전화번호 : " << setw(3) << tmp->value.phoneNumber << endl;
	}

	cout << endl;

	return flag;
}

bool DeleteAll(Node*& head) {

	bool flag = false;

	Node* tmpForNext = head->link;
	Node* tmpForDelete = head;

	while (tmpForNext != NULL) {

		flag = true;

		tmpForDelete = tmpForNext;
		tmpForNext = tmpForNext->link;

		delete tmpForDelete;
	}

	head->link = NULL;

	return flag;

}