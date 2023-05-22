// [모범답안]
// quiz
//  : (방법1 - string으로 제시) string 클래스를 사용해서 Hangman Game(String class) 게임을 구현해라.. 과정을 다음과 같다

// 1. 제시 단어 랜덤 선택 
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

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum menu { Play = 1, Terminate, Cheat, ReplaceWord };

string wordlist[] = { "apiary", "beetle", "cereal",
  "danger", "ensign", "florid", "garage", "health", "insult",
  "jackal", "keeper", "loaner", "manage", "nonce", "onset",
  "plaid", "quilt", "remote", "stolid", "train", "useful",
  "valid", "whence", "xenon", "yearn", "zippy" };

class hangman {

    private:
        static string* words; // 단어 목록 동적 할당
        static int wordsCnt; // 단어 목록 총 수량
        string answer; // 게임 진행 답안
        string hideAnswer; // 게임 진행 숨긴 답안
        string bad; // 실패 기록 답안 목록
        int Life; // 총 기회 10번

    public:

        // words 동적 할당 해제
        ~hangman() { 
            if (words != NULL) delete[] words;
        }

        // 멤버 변수 초기화
        void init() { 

            if (wordsCnt == 0) {
                wordsCnt = sizeof(wordlist) / sizeof(wordlist[0]);
                words = new string[wordsCnt];
                for (int i = 0; i < wordsCnt; i++) {
                    words[i] = wordlist[i];
                }
            }

            answer = words[rand() % wordsCnt];
            string temp(answer.length(), '_');
            hideAnswer = temp;
            Life = 10;
            bad.clear();
        }

        // life 값 확인
        int lifeCheck() { 
            return Life; 
        } 

        // 답안 진행 상태 출력
        void printAnswer(int n = 0) { 

            if (n == 3) {
                cout << answer << endl;
            }

            cout << hideAnswer << endl;
        }

        // 게임 메뉴판 출력
        void menu(int& menu) { 
            cout << " [ Hangman Game !! ] \n";
            cout << " 1. Play \n";
            cout << " 2. Exit \n";
            cout << " 3. Cheat\n";
            cout << " 메뉴를 입력하세요. : ";
            do {

                while (!(cin >> menu)) {

                    cin.clear();
                    while (getchar() != '\n');

                    cout << " 메뉴를 입력하세요. : ";
                }

                while (getchar() != '\n');

            } while (menu <= 0 || 4 <= menu);

        }

        // 정답 확인 함수
        bool isSolve() { 

            if (answer.compare(hideAnswer) == 0) {
                return true;
            }
            return false;
        }

        // 입력받은 알파벳 & 답안 비교
        bool guesses(char letter) {

            if (bad.find(letter) != string::npos || hideAnswer.find(letter) != string::npos) {
                cout << " 이미 시도한 알파벳 입니다. \n";
                return false;
            }else {

                int pos = answer.find(letter);

                if (pos == string::npos){

                    cout << " 틀렸습니다. \n\n";
                    bad += letter; // add to string
                    Life--;

                }else{

                    cout << " 찾았습니다. \n\n";

                    do {

                        hideAnswer[pos] = letter;
                        pos = answer.find(letter, pos + 1);

                    } while (pos != string::npos);
                }

                if (!isSolve()) {

                    if (bad.length() > 0) {
                        cout << "실패한 알파벳 : " << bad << endl;
                    }

                    cout << Life << " 번 기회가 남았습니다.\n\n";

                    return false;
                }

                return true;
            }
        }
};

string* hangman::words;
int hangman::wordsCnt;

int main() {

    srand(time(0));
    hangman game;

    int menu = 0;

    while (1) {

        system("cls");

        game.menu(menu);

        switch (menu) {
            case Cheat:
            case Play:

                game.init();

                while (!game.isSolve() && game.lifeCheck() > 0) {

                    game.printAnswer(menu);

                    char letter;
                    cin >> letter;
                    while (cin.get() != '\n');

                    game.guesses(letter);
                }
                break;
            case Terminate:
                cout << "\n [ 프로그램 종료 합니다. ] \n";
                exit(0);
        }

        if (game.isSolve()) {

            game.printAnswer();
            cout << " 축하합니다. 정답을 맞추셨습니다.!! \n";

        }else {
            cout << " ㅠ.ㅠ 정답을 맞추지 못 했습니다. \n";
        }

        system("pause");
    }
    return 0;
}
