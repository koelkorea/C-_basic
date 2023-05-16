// [������]
// quiz
//  : string Ŭ������ ����ؼ� Hangman Game(String class) ������ �����ض�.. ������ ������ ����

// 1. ���� �ܾ� ���� ���� (���1 - string���� ����, ���2 - ���� ��/��·�)
// 2. ���� ����ŭ ����(_) ǥ��
// 3. ���ĺ� 26�� �� 1�� �Է� �ޱ�
// 4. ���ĺ��� ���� ��� ���ĺ� ǥ��, ���� ��� ��ȸ(life) 1�� �Ҹ�.
// 5. ���� �����ϴ� ���� ã�� ������ ���ĺ� ��� ǥ��
//    -> �ߺ��� �Է��� ��� ����ó��, ���Է�
// 6. �� ��ȸ(life) 10���� �� �Ҹ��ϸ� ���ӿ���

// [�ʿ� ���� ���]
// 1. �ܾ� �Է� [string �迭 or ���� �����]
// 2. ���� �ܾ� ���� ���� & ����(_) ���
// 3. ���ĺ� 1���� �Է� �޾� ���� �ܾ�� ��ġ�ϴ� ��ġ ǥ��
// 4. ���� ���� ��Ȳ ���� �ܾ�� ǥ�� ã�� ������ �ܾ� ��� ���

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
        cout << "���ӿ� ����� �ܾ� ���� �̸��� �Է��ϼ���.( .txt Ȯ���� ����, End ����) :";
        while (getline(cin, filename)) {
            ifstream readFile;
            string end("end"), End("End");
            if ((filename.compare(end) == 0) || (filename.compare(End) == 0)) exit(0);
            readFile.open(filename);    //���� ����
            if (readFile.is_open()) {    //������ ���ȴ��� Ȯ��
                for (wordsCnt = 0; !readFile.eof(); wordsCnt++) {    //���� ������ �о����� Ȯ��
                    string str;
                    getline(readFile, str);
                    words[wordsCnt] = str;
                    //cout << "�ܾ� ���� " << wordsCnt + 1 << " : " << words[wordsCnt] << endl;
                }
                readFile.close();    //���� �ݱ�
                break;
            }
            else {
                cout << "���ӿ� ����� �ܾ� ���� �̸��� �Է��ϼ���.( .txt Ȯ���� ����, End ����) :";
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
        cout << " �����ϴ� �ܾ� ������ " << filename << " �Դϴ�.\n";
        cout << " �ܾ� ���� : " << wordsCnt << endl << endl;
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
        cout << " �޴��� �Է��ϼ���. : ";
        do {
            while (!(cin >> menu)) {
                cin.clear();
                while (getchar() != '\n');
                cout << " �޴��� �Է��ϼ���. : ";
            }
            while (getchar() != '\n');
        } while (menu <= 0 || 5 <= menu);

    }
    void saveWord() {
        cout << "���ӿ� ����� �ܾ� ���� �̸��� �Է��ϼ���.( .txt Ȯ���� ����, End ����) :";
        while (getline(cin, filename)) {
            ifstream readFile;
            string end("end"), End("End");
            if ((filename.compare(end) == 0) || (filename.compare(End) == 0))
                exit(0);
            readFile.open(filename);    //���� ����
            if (readFile.is_open()) {    //������ ���ȴ��� Ȯ��
                for (wordsCnt = 0; !readFile.eof(); wordsCnt++) {    //���� ������ �о����� Ȯ��
                    string str;
                    getline(readFile, str);
                    words[wordsCnt] = str;
                    //cout << "�ܾ� ���� " << wordsCnt + 1 << " : " << words[wordsCnt] << endl;
                }
                readFile.close();    //���� �ݱ�
                break;
            }
            else {
                cout << "���ӿ� ����� �ܾ� ���� �̸��� �Է��ϼ���.( .txt Ȯ���� ����, End ����) :";
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
            cout << " �̹� �õ��� ���ĺ� �Դϴ�. \n";
            return false;
        }
        else {
            int pos = answer.find(letter);
            if (pos == string::npos)
            {
                cout << " Ʋ�Ƚ��ϴ�. \n\n";
                bad += letter; // add to string
                Life--;
            }
            else
            {
                cout << " ã�ҽ��ϴ�. \n\n";
                do {
                    hideAnswer[pos] = letter;
                    pos = answer.find(letter, pos + 1);
                } while (pos != string::npos);
            }
            if (answer != hideAnswer) {
                if (bad.length() > 0)
                    cout << "������ ���ĺ� : " << bad << endl;
                cout << Life << " �� ��ȸ�� ���ҽ��ϴ�.\n\n";
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
            cout << "\n [ ���α׷� ���� �մϴ�. ] \n";
            exit(0);
        case ReplaceWord:
            game.saveWord();
            continue;
        }
        if (game.isSolve()) {
            game.printAnswer();
            cout << " �����մϴ�. ������ ���߼̽��ϴ�.!! \n";
        }
        else cout << " ��.�� ������ ������ �� �߽��ϴ�. \n";
        system("pause");
    }
    return 0;
}