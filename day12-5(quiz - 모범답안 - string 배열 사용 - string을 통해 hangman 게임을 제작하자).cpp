// [모범답안]
// quiz
//  : string 클래스를 사용해서 Hangman Game(String class) 게임을 구현해라.. 과정을 다음과 같다

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

// Hangman Game(String class)
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
enum menu { Play = 1, Terminate, Cheat, ReplaceWord };
class hangman {
private:
    static string filename;
    static int wordsCnt;
    string words[1000];
    string answer;
    string hideAnswer;
    string bad;
    int Life;
public:
    hangman() {
        srand(time(0));
        cout << "게임에 사용할 단어 파일 이름을 입력하세요.( .txt 확장자 포함, End 종료) :";
        while (getline(cin, filename)) {
            ifstream readFile;
            string end("end"), End("End");
            if ((filename.compare(end) == 0) || (filename.compare(End) == 0)) exit(0);
            readFile.open(filename);    //파일 열기
            if (readFile.is_open()) {    //파일이 열렸는지 확인
                for (wordsCnt = 0; !readFile.eof(); wordsCnt++) {    //파일 끝까지 읽었는지 확인
                    string str;
                    getline(readFile, str);
                    words[wordsCnt] = str;
                    //cout << "단어 저장 " << wordsCnt + 1 << " : " << words[wordsCnt] << endl;
                }
                readFile.close();    //파일 닫기
                break;
            }
            else {
                cout << "게임에 사용할 단어 파일 이름을 입력하세요.( .txt 확장자 포함, End 종료) :";
                continue;
            }
        }
    }
    void init() {
        Life = 10;
        bad.clear();
        printFile();
        randomSelect();
    }
    int lifeCheck() { return Life; }
    static void printFile() {
        cout << " 참고하는 단어 파일은 " << filename << " 입니다.\n";
        cout << " 단어 개수 : " << wordsCnt << endl << endl;
    }
    void printAnswer(int n = 0) {
        if (n == 3) cout << answer << endl;
        cout << hideAnswer << endl;
    }
    void menu(int& menu) {
        cout << " [ Hangman Game !! ] \n";
        cout << " 1. Play \n";
        cout << " 2. Exit \n";
        cout << " 3. Cheat\n";
        cout << " 4. ReplaceWord\n";
        cout << " 메뉴를 입력하세요. : ";
        do {
            while (!(cin >> menu)) {
                cin.clear();
                while (getchar() != '\n');
                cout << " 메뉴를 입력하세요. : ";
            }
            while (getchar() != '\n');
        } while (menu <= 0 || 5 <= menu);

    }
    void saveWord() {
        cout << "게임에 사용할 단어 파일 이름을 입력하세요.( .txt 확장자 포함, End 종료) :";
        while (getline(cin, filename)) {
            ifstream readFile;
            string end("end"), End("End");
            if ((filename.compare(end) == 0) || (filename.compare(End) == 0))
                exit(0);
            readFile.open(filename);    //파일 열기
            if (readFile.is_open()) {    //파일이 열렸는지 확인
                for (wordsCnt = 0; !readFile.eof(); wordsCnt++) {    //파일 끝까지 읽었는지 확인
                    string str;
                    getline(readFile, str);
                    words[wordsCnt] = str;
                    //cout << "단어 저장 " << wordsCnt + 1 << " : " << words[wordsCnt] << endl;
                }
                readFile.close();    //파일 닫기
                break;
            }
            else {
                cout << "게임에 사용할 단어 파일 이름을 입력하세요.( .txt 확장자 포함, End 종료) :";
                continue;
            }
        }
    }
    string& randomSelect() {
        answer = words[rand() % wordsCnt];
        int length = answer.length();
        string temp(length, '_');
        hideAnswer = temp;
        return answer;
    }
    bool isSolve() {
        if (answer.compare(hideAnswer) == 0) {
            return true;
        }
        return false;
    }
    bool guesses(char letter) {
        if (bad.find(letter) != string::npos || hideAnswer.find(letter) != string::npos) {
            cout << " 이미 시도한 알파벳 입니다. \n";
            return false;
        }
        else {
            int pos = answer.find(letter);
            if (pos == string::npos)
            {
                cout << " 틀렸습니다. \n\n";
                bad += letter; // add to string
                Life--;
            }
            else
            {
                cout << " 찾았습니다. \n\n";
                do {
                    hideAnswer[pos] = letter;
                    pos = answer.find(letter, pos + 1);
                } while (pos != string::npos);
            }
            if (answer != hideAnswer) {
                if (bad.length() > 0)
                    cout << "실패한 알파벳 : " << bad << endl;
                cout << Life << " 번 기회가 남았습니다.\n\n";
                return false;
            }
            return true;
        }
    }
};
int hangman::wordsCnt;
string hangman::filename;
int main() {
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
        case ReplaceWord:
            game.saveWord();
            continue;
        }
        if (game.isSolve()) {
            game.printAnswer();
            cout << " 축하합니다. 정답을 맞추셨습니다.!! \n";
        }
        else cout << " ㅠ.ㅠ 정답을 맞추지 못 했습니다. \n";
        system("pause");
    }
    return 0;
}