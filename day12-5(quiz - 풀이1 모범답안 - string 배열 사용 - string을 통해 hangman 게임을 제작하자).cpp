// [������]
// quiz
//  : (���1 - string���� ����) string Ŭ������ ����ؼ� Hangman Game(String class) ������ �����ض�.. ������ ������ ����

// 1. ���� �ܾ� ���� ���� 
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
        static string* words; // �ܾ� ��� ���� �Ҵ�
        static int wordsCnt; // �ܾ� ��� �� ����
        string answer; // ���� ���� ���
        string hideAnswer; // ���� ���� ���� ���
        string bad; // ���� ��� ��� ���
        int Life; // �� ��ȸ 10��

    public:

        // words ���� �Ҵ� ����
        ~hangman() { 
            if (words != NULL) delete[] words;
        }

        // ��� ���� �ʱ�ȭ
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

        // life �� Ȯ��
        int lifeCheck() { 
            return Life; 
        } 

        // ��� ���� ���� ���
        void printAnswer(int n = 0) { 

            if (n == 3) {
                cout << answer << endl;
            }

            cout << hideAnswer << endl;
        }

        // ���� �޴��� ���
        void menu(int& menu) { 
            cout << " [ Hangman Game !! ] \n";
            cout << " 1. Play \n";
            cout << " 2. Exit \n";
            cout << " 3. Cheat\n";
            cout << " �޴��� �Է��ϼ���. : ";
            do {

                while (!(cin >> menu)) {

                    cin.clear();
                    while (getchar() != '\n');

                    cout << " �޴��� �Է��ϼ���. : ";
                }

                while (getchar() != '\n');

            } while (menu <= 0 || 4 <= menu);

        }

        // ���� Ȯ�� �Լ�
        bool isSolve() { 

            if (answer.compare(hideAnswer) == 0) {
                return true;
            }
            return false;
        }

        // �Է¹��� ���ĺ� & ��� ��
        bool guesses(char letter) {

            if (bad.find(letter) != string::npos || hideAnswer.find(letter) != string::npos) {
                cout << " �̹� �õ��� ���ĺ� �Դϴ�. \n";
                return false;
            }else {

                int pos = answer.find(letter);

                if (pos == string::npos){

                    cout << " Ʋ�Ƚ��ϴ�. \n\n";
                    bad += letter; // add to string
                    Life--;

                }else{

                    cout << " ã�ҽ��ϴ�. \n\n";

                    do {

                        hideAnswer[pos] = letter;
                        pos = answer.find(letter, pos + 1);

                    } while (pos != string::npos);
                }

                if (!isSolve()) {

                    if (bad.length() > 0) {
                        cout << "������ ���ĺ� : " << bad << endl;
                    }

                    cout << Life << " �� ��ȸ�� ���ҽ��ϴ�.\n\n";

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
                cout << "\n [ ���α׷� ���� �մϴ�. ] \n";
                exit(0);
        }

        if (game.isSolve()) {

            game.printAnswer();
            cout << " �����մϴ�. ������ ���߼̽��ϴ�.!! \n";

        }else {
            cout << " ��.�� ������ ������ �� �߽��ϴ�. \n";
        }

        system("pause");
    }
    return 0;
}
