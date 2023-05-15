// quiz
//  : 파일 입출력 기능 활용해서 Hangman Game(String class) 게임을 구현해라.. 과정을 다음과 같다

// 1. 제시 단어 랜덤 선택 (방법1 - string으로 제시, 방법2 - 파일 입/출력로)
// 2. 글자 수만큼 밑줄(_) 표시
// 3. 알파벳 26개 중 1개 입력 받기
// 4. 알파벳이 있을 경우 알파벳 표시, 없을 경우 기회(life) 1개 소모.
// 5. 게임 진행하는 동안 찾기 실패한 알파벳 목록 표시
//    -> 중복된 입력의 경우 예외처리, 재입력
// 6. 총 기회(life) 10번을 다 소모하면 게임오버

// [필요 구현 기능]
// 1. 단어 입력 [string 배열 or 파일 입출력]
// 2. 제시 단어 랜덤 선택 & 숨김(_) 기능
// 3. 알파벳 1개를 입력 받아 제시 단어에서 일치하는 위치 표시
// 4. 게임 진행 상황 밑줄 단어로 표시 찾기 실패한 단어 목록 출력


// file 안의 문자열 입력(읽기), 출력(쓰기) 함수
//    : fopen_s를 통해 파일 스트림 생성을 생성해 준 뒤, 해당 파일 스트림에 사용 가능한 입력(읽기), 출력(쓰기) 함수  
//      -> (중요) 모드 = r, 입력(읽기)함수만 사용가능 <-> 모드 = w, a, 출력(쓰기)함수만 사용가능

//  1. File에서 '단일문자' 입력(읽기), 출력(쓰기) 함수

//      # (단일문자 출력(쓰기) 함수)
//        fputc(정수변수, 파일포인터 (=파일스트림) )
//			    : 대상 File에 단일 문자를 출력(쓰기)하여 반환 (= 모드가 r에서만 사용가능) 
//			      (쓰기 에러 발생시 EOF(-1) 반환)
//			        ex) int fputc(int c, FILE* stream);
//                    -> fputc(정수변수, 파일스트림);로 해석

//      # (단일문자 입력(읽기) 함수)
//        fgetc(정수변수, 파일포인터 (=파일스트림) )
//			     : 대상 File에서 단일 문자를 순차적으로 읽고, 그 문자를 반환 (= 모드가 w, a에서만 사용가능) 
//			       (파일의 끝을 만나거나, 읽기 에러 발생시 EOF(-1) 반환)
//			         ex) int fputc(int c, FILE* stream);


// Hangman Game(String class)
#include <string>
#include <iostream>
#include <cstdlib>				//	srand(), rand() 함수 사용 가능하게 함
#include <ctime>
#define PLAY 1
#define EXIT 2
#define CHEAT 3
#define NEWTXT 4

using namespace std;

class hangman {

private:
	// 입, 출력 파일목록을 불러올때 쓰는 파일명
	static string filename;

	// 단어장에 저장된 단어의 갯수
	static int wordsCnt;

	// 정답 단어들 저장된 문자열 (파일에서 가져오던가, 대입해서 넣던가)
	static string words[1000];

	// 정답 단어 문자열
	string answer;

	// player가 진행중인 _포함 단어
	string hideAnswer;

	// 현재 입력된 알파벳들 (a~z까지 순서대로)
	string cheaked;

	// 남은 생명력 (초기값 = 10개)
	int Life;

public:

	// 단어 파일 입력
	static void inputWords(string filename);

	// 파일에 입력된 단어 파일 정보 출력
	static void printFile();

	// 생성자 : 멤버 변수 초기화
	hangman();

	// 메뉴 선택 함수
	void menu(int& menu);

	// 게임 시작 후 반복 및 끝까지 진행
	void playLoop(int flag);

	// 정답이 될 단어 랜덤 선택 함수
	string& randomSelect();

	// 진행중인 player 상태 출력 함수 (menu가 3이면 치트모드)
	void printStatus(int flag = 1);

	// 목숨 확인 함수
	int getLife();

	// 입력 알파벳 & 답안에 포함 여부 함수 (0 : 정답, 1 : 오답, 2 : 중복)
	int matchOrNot(char letter);

	// player가 단어를 완성했는지 확인 함수
	bool checkCompletion();

	// 입력된 글자가 이미 입력되었는지 검증 함수
	bool alreadyCheaked(char letter);

	// 입력문자 소문자로 변환 or 다시 입력
	char switchedSmall(char letter) {

		char result = (char)letter;

		// 대문자 -> 소문자
		if (letter >= 65 && letter <= 90) {

			result += (char)32;
			cout << "     ->> (anouncement!) you entered Capital.. So switched input to [" << result << endl << endl;
		}
		else if (!(letter >= 97 && letter <= 122)) {

			result = NULL;
			cout << "     ->> (anouncement!) please, enter god demn alphabet!" << endl << endl;
		}

		return result;
	}
};

// static 멤버변수 초기화
string hangman::filename;
int hangman::wordsCnt = 0;
string hangman::words[1000];

int main() {

	// 읽을 파일명(입력받기 귀찮음)
	string filename = "word.txt";

	// 단어장에 단어 입력
	hangman::inputWords(filename);

	// 특별한 이유 없으면 종료
	while (1) {

		system("cls");

		// hangman 클래스 객체 game의 멤버변수 초기화
		// (= 생성자 통한 게임 세팅 완료) 
		hangman* game = new hangman();

		int menu = 0;

		cout << "원하시는 메뉴를 입력해 주세요(1 : 게임시작, 2 : 종료, 3 : 치트모드, 4 : 새로운 단어장.txt 파일 입력) : " << endl;
		cin >> menu;
		while (cin.get() != '\n');

		game->menu(menu);

		system("pause");
	}
	return 0;
}

// 단어 파일 _filename에 해당되는 내용을 words 배열에 입력(= 이식)
void hangman::inputWords(string _filename) {

	//file 포인터 선언 & 초기화 (file은 이미 애초부터 struct 형식인데, typedef로 FILE이라는 재정의가 되어 있음)
	FILE* fileStream = NULL;

	// 파일에서 단어를 읽기 위한 string 객체
	char tmp[1024];

	// static filename파일명 _filename로 입력
	hangman::filename = _filename;

	// static words 배열 초기화
	for (int i = 0; i < 1000; i++) {
		words[i] = "";
	}

	// static wordsCnt 초기화
	hangman::wordsCnt = 0;

	// 2. 1에서 생성한 file 읽기 모드 :  fopen_s 성공 시 0 반환
	if (fopen_s(&fileStream, _filename.data(), "r") == 0) {

		// # (문자열 입력 함수) fgets(문자열 변수, 입력 최대 문자수, 파일포인터)
		//    : 파일로 문자열을 읽어와 char형 배열에 저장하는 함수 = 개행문자('\n')나 배열의 길이만큼 문자읽음 

		// 1행 단위로 str 배열에 문자열에 저장하는 while문 (문자열이 없는 마지막은 NULL 리턴해서  while문 마무리)
		while (fgets(tmp, 1024, fileStream) != NULL) {

			words[wordsCnt] = tmp;
			wordsCnt++;
		}

		printFile();

		// fclose(file 포인터) : 파일 포인터 닫기
		fclose(fileStream);

	}
	// 파일 생성 실패 (fopen_s의 결과로 0을 반환하지 못할 시)
	else {      

		printf("File Open Fail\n");
	}

}

// 파일 읽을시 단어 파일 정보 출력 (= static 멤버변수 배열 words에 잘 입력되었나 확인용)
void hangman::printFile() {

	cout << "[파일 내용]" << endl;

	for (int i = 0; i < wordsCnt; i++) {
		cout << "word[" << i << "] = " << words[i];
	}

	cout << endl << endl;
}

// 생성자 : 단어 파일 입력 (string 배열 string words[1000]에 입력 )
hangman::hangman() {

	// 정답 단어 저장 변수
	answer = randomSelect();

	// 파일을 읽은 자료형이 char*이고 그 위치를 시작으로 \0을 기준으로 string 배열 words에 집어넣음 = words의 각 요소는 문자열이 끝을 알리는 \0 포함
	//  -> (중요) 따라서 player가 읽을 문자열의 길이 = words의 각 요소에서 랜덤으로 가져온 문자열 answer보다 1크다
	//      -> 맨 끝을 지워주는 이유      
	answer.pop_back();

	// 현재 진행중인 _포함 단어 저장 변수 
	string tmp(answer.length(), '_');
	hideAnswer = tmp;

	// 현재 잘못뽑은 단어 모음
	cheaked.resize(26, '_');

	// 현재 남은 생명령 (초기값 = 10)
	Life = 10;
}

// 메뉴 선택 함수
void hangman::menu(int& menu) {

	// 1, 3을 누르면, 플레이함 (3은 치트모드로, 정답까지 보여줌)
	if (menu == PLAY || menu == CHEAT) {

		cout << " ->> 단어장에서 단어가 선택되었습니다! 지금부터 10번의 기회가 있으니, a ~ z 까지 이니셜을 찍으세요." << endl << endl;

		playLoop(menu);

		// 게임이 끝난 뒤, player가 단어를 완성했다면?
		if (this->checkCompletion()) {
			cout << "\n[CONGRATUAION!! YOU WIN ~!!]\n  ->> thank you for playing \n";
		}
		else {
			cout << "\n[G.A.M.E O.V.E.R!!]\n  ->> thank you for playing.. please try again~! \n";
		}

		// 2를 누르면 종료
	}
	else if (menu == EXIT) {

		cout << "\n [ 프로그램 종료 합니다. ] \n";
		exit(0);
	}
	else if (menu == NEWTXT) {

		// 읽을 파일명(입력받기 귀찮음)
		string filename;

		cout << "입력하고 싶은 txt파일을 적어주세요 (파일명.txt 형식으로 적으시길) : ";
		cin >> filename;

		// 단어장에 단어 입력
		hangman::inputWords(filename);
	}
}

// 게임 시작 후 반복되는 부분
void hangman::playLoop(int flag) {

	// 단어가 밝혀지지 않고 + 목숨이 0개 이상 남았으면 계속 진행
	while (!this->checkCompletion() && this->getLife() > 0) {

		this->printStatus(flag);

		// 1. player의 알파뱃 letter 입력
		char letter;
		cout << "    ->> input alphabet! : ";
		cin >> letter;
		while (cin.get() != '\n');

		// 2. 입력한 알파벳 letter이 알파벳인지 여부 확인
		//  -> NULL이 리턴되면 다시 입력ㄱㄱ
		if (switchedSmall(letter) == NULL) {
			continue;
		}
		else {
			letter = switchedSmall(letter);
		}

		// 3. 입력letter를 정답과 대조한 따른 결과에 따른 결과 리턴(0 : 정답, 1 : 오답, 2 : 중복)
		int flag = this->matchOrNot(letter);

		if (flag == 0) {
			cout << "     ->> (anouncement!) good answer!" << (!this->checkCompletion() ? " keep going!" : " complete!!") << endl << endl;
		}
		else if (flag == 1) {
			cout << "     ->> (anouncement!) wrong answer! 1 life stock is gone...ㅠㅠ" << endl << endl;
			Life--;
		}
		else if (flag == 2) {
			cout << "     ->> (anouncement!) you already entered this letter [" << letter << "], please enter another!" << endl << endl;
		}
	}
}

// 정답이 될 단어 랜덤 선택 함수
string& hangman::randomSelect() {

	srand((unsigned int)time(NULL));

	// 단어 수 만큼의 나머지 값에 해당하는 words의 index 채택
	return words[rand() % wordsCnt];
}

// 진행중인 player 상태 출력 함수 (menu가 3이면 치트모드)
void hangman::printStatus(int flag) {

	cout << "[current situation]" << endl;
	cout << " - life stock : " << Life << endl;
	cout << " - cheaked letters : " << cheaked << endl << endl;
	cout << " - player's word : " << hideAnswer << endl;

	if (flag != 1) {

		cout << " - (Cheat mode on) the answer : " << answer << endl;
	}
}

// 목숨 확인 함수
int hangman::getLife() {
	return Life;
}

// 알파벳 & 답안 비교 함수 (0 : 정답, 1 : 오답, 2 : 중복)
int hangman::matchOrNot(char letter) {

	// 입력한 알파벳이 이미 입력된 녀석인지 여부 확인
	if (alreadyCheaked(letter) == true) {
		return 2;
	}

	// 입력된 녀석이 아니면 cheacked 갱신 (char의 문자 index를 이용, 순차적으로 a~z까지 나열된 cheaked의 배열에 접근)
	cheaked[letter - 97] = letter;

	// 그 후 입력된 문자가 현재 정답에 있는지 확인
	if (answer.find(letter) == string::npos) {

		return 1;

	}else {

		for (int i = 0; i < answer.length(); i++) {

			if (answer[i] == letter) {
				hideAnswer[i] = answer[i];
			}
		}

		return 0;
	}
}

// player가 단어를 완성했는지 확인 함수
bool hangman::checkCompletion() {

	// player의 단어 문자열과 정답 문자열을 비교해서, 일치가 나오면 true
	if (hideAnswer.compare(answer) == 0) {
		return true;
	}

	return false;
}

// 입력된 글자가 이미 입력되었는지 검증
bool hangman::alreadyCheaked(char letter) {

	// 만약 cheak[알파벳의 letter 순서]에 해당하는 부분이 일치하면?
	//  -> 중복입력 판정
	if (cheaked[letter - 97] == letter) {
		return true;
	}

	return false;
}

