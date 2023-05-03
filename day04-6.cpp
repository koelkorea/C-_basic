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

typedef struct STU {
	char* name;
	char* phoneNumber;
}STU;

typedef STU NodeElement;

struct Node {
	NodeElement value;
	Node* link;
};

void PrintMenu(int& menu);
bool InsertNode(Node*& head, NodeElement data);
bool DeleteNode(Node*& head, NodeElement data, int deleteNodenum);
bool DeleteAll(Node*& head);
bool PrintList(Node*& head);

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

void cinclear(int n) {

	if (cin.fail()) {
		cin.clear();
		cin.ignore(n, '\n');
	}
}

Node* LinkedHead = new Node;

int main() {

	LinkedHead->value;
	LinkedHead->link = NULL;

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

void PrintMenu(int& menu) {

	if (menu == 1) {

		// -----------------------------------------------------[학생 정보 STU 생성 & 작성]--------------------------------------------------------------------------
		// 1. 학생 수 입력 받기
		int studentCnt;

		cout << "새로 입력할 학생 수를 입력해주십쇼 : ";
		cin >> studentCnt;

		// 각 입력값 크기에 해당하는 동적크기를 갖는 char배열을 만들기 위해, 일단 입력값 자체를 받기 위한 정적 배열을 하나 만들어 준다
		char inputName[20];
		char inputPhoneNumber[20];

		// 3. 각 학생 수만큼 이름, 전화번호 입력받기
		for (int i = 0; i < studentCnt; i++) {

			// 2. 학생 수 만큼 성적을 저장 할 메모리 공간 동적 할당
			// STU 구조체 포인터변수에 new 연산자를 통한 메모리에 입력한 학생수에 해당하는 만큼의 크기를 갖는 STU구조체 배열을 할당하고, 그 시작주소를 포인터변수에 대입 
			// (= 힙 영역에 생성된 STU 구조체의 주소값을 call by reference 형식의 레버런스 변수로 넘겨줌)
			//  : 자료형 * 변수명 = new 자료형;   <->   malloc(byte 크기), calloc 등을 쓰던 과거아 다름
			STU* student = new STU;

			cout << setw(3) << i + 1 << "번째로 입력할 학생의 '이름'과 '전화번호'를 입력해주세요 : ";
			cin >> inputName >> inputPhoneNumber;

			// 4. 이름, 전화번호 들의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
			student->name = new char[strlen(inputName) + 1];

			// 정적배열에 입력된 이름 문자열을 새로 적은 문자열로 1자씩 복사
			for (int j = 0; j <= strlen(inputName); j++) {
				student->name[j] = inputName[j];

			}

			// 4. 이름, 전화번호 들의 문자열 길이만큼 동적할당 (NULL 문자도 포함해야..)
			student->phoneNumber = new char[strlen(inputPhoneNumber) + 1];

			// 정적배열에 입력된 전화번호 문자열을 새로 적은 문자열로 1자씩 복사
			for (int j = 0; j <= strlen(inputPhoneNumber); j++) {
				student->phoneNumber[j] = inputPhoneNumber[j];
			}

			if (InsertNode(LinkedHead, *student) == true) {

				cout << " >>>> (알림) 학생 " << i + 1 << "의 정보가 입력 완료.." << endl << endl;
			}
			else {
				cout << " >>>> (알림) 학생 " << i + 1 << "의 정보가 입력 실패!" << endl << endl;
			}

		}

	}
	else if (menu == 2) {

		int deleteNodenum = 0;

		PrintList(LinkedHead);

		cout << "몇 번째 노드를 지우고 싶으신가요? : ";
		cin >> deleteNodenum;

		Node* tmp = LinkedHead;

		for (int i = 0; i < deleteNodenum; i++) {
			tmp = tmp->link;
		}

		STU* deleteStudentInfo = new STU;

		*deleteStudentInfo = tmp->value;

		if (DeleteNode(LinkedHead, *deleteStudentInfo, deleteNodenum) == true) {

			cout << " >>>> (알림)" << deleteNodenum << "번째 학생 정보 삭제 완료!" << endl << endl;
		}
		else {
			cout << " >>>> (알림)" << deleteNodenum << "번째 학생 정보 삭제 실패!" << endl << endl;
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
		exit(0);
	}

}

bool InsertNode(Node*& head, NodeElement data) {

	bool flag = false;

	if (data.name != NULL && data.phoneNumber != NULL) {

		Node* tmp = head;

		while (tmp->link != NULL) {

			flag = true;
			tmp = tmp->link;
		}

		Node* studentLinked = new Node;

		studentLinked->value.name = data.name;
		studentLinked->value.phoneNumber = data.phoneNumber;

		studentLinked->link = NULL;

		tmp->link = studentLinked;

		flag = true;
	}

	return flag;
}

bool DeleteNode(Node*& head, NodeElement data, int deleteNodenum) {

	bool flag = false;

	if (deleteNodenum == 1) {

		head->link = head->link->link;
		delete head->link;

		flag = true;

	}else{

		Node* tmp = head;

		for (int i = 1; i <= deleteNodenum; i++) {

			tmp = tmp->link;

			if (i == deleteNodenum - 1) {

				if (tmp->link->link != NULL) {

					tmp->link = tmp->link->link;
				}
				else {
					tmp->link = NULL;
				}

			}
			else if (i == deleteNodenum) {
				delete tmp;
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

	Node* tmp = head;
	Node* tmpForDelete = head;

	while (tmp->link != NULL) {

		flag = true;
		tmpForDelete = tmp;
		tmp = tmp->link;

		delete tmpForDelete;
	}

	head->link = NULL;

	return flag;

}