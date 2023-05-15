// quiz
//  : ���� ����� ��� Ȱ���ؼ� Hangman Game(String class) ������ �����ض�.. ������ ������ ����

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


// file ���� ���ڿ� �Է�(�б�), ���(����) �Լ�
//    : fopen_s�� ���� ���� ��Ʈ�� ������ ������ �� ��, �ش� ���� ��Ʈ���� ��� ������ �Է�(�б�), ���(����) �Լ�  
//      -> (�߿�) ��� = r, �Է�(�б�)�Լ��� ��밡�� <-> ��� = w, a, ���(����)�Լ��� ��밡��

//  1. File���� '���Ϲ���' �Է�(�б�), ���(����) �Լ�

//      # (���Ϲ��� ���(����) �Լ�)
//        fputc(��������, ���������� (=���Ͻ�Ʈ��) )
//			    : ��� File�� ���� ���ڸ� ���(����)�Ͽ� ��ȯ (= ��尡 r������ ��밡��) 
//			      (���� ���� �߻��� EOF(-1) ��ȯ)
//			        ex) int fputc(int c, FILE* stream);
//                    -> fputc(��������, ���Ͻ�Ʈ��);�� �ؼ�

//      # (���Ϲ��� �Է�(�б�) �Լ�)
//        fgetc(��������, ���������� (=���Ͻ�Ʈ��) )
//			     : ��� File���� ���� ���ڸ� ���������� �а�, �� ���ڸ� ��ȯ (= ��尡 w, a������ ��밡��) 
//			       (������ ���� �����ų�, �б� ���� �߻��� EOF(-1) ��ȯ)
//			         ex) int fputc(int c, FILE* stream);


// Hangman Game(String class)
#include <string>
#include <iostream>
#include <cstdlib>				//	srand(), rand() �Լ� ��� �����ϰ� ��
#include <ctime>
#define PLAY 1
#define EXIT 2
#define CHEAT 3
#define NEWTXT 4

using namespace std;

class hangman {

private:
	// ��, ��� ���ϸ���� �ҷ��ö� ���� ���ϸ�
	static string filename;

	// �ܾ��忡 ����� �ܾ��� ����
	static int wordsCnt;

	// ���� �ܾ�� ����� ���ڿ� (���Ͽ��� ����������, �����ؼ� �ִ���)
	static string words[1000];

	// ���� �ܾ� ���ڿ�
	string answer;

	// player�� �������� _���� �ܾ�
	string hideAnswer;

	// ���� �Էµ� ���ĺ��� (a~z���� �������)
	string cheaked;

	// ���� ����� (�ʱⰪ = 10��)
	int Life;

public:

	// �ܾ� ���� �Է�
	static void inputWords(string filename);

	// ���Ͽ� �Էµ� �ܾ� ���� ���� ���
	static void printFile();

	// ������ : ��� ���� �ʱ�ȭ
	hangman();

	// �޴� ���� �Լ�
	void menu(int& menu);

	// ���� ���� �� �ݺ� �� ������ ����
	void playLoop(int flag);

	// ������ �� �ܾ� ���� ���� �Լ�
	string& randomSelect();

	// �������� player ���� ��� �Լ� (menu�� 3�̸� ġƮ���)
	void printStatus(int flag = 1);

	// ��� Ȯ�� �Լ�
	int getLife();

	// �Է� ���ĺ� & ��ȿ� ���� ���� �Լ� (0 : ����, 1 : ����, 2 : �ߺ�)
	int matchOrNot(char letter);

	// player�� �ܾ �ϼ��ߴ��� Ȯ�� �Լ�
	bool checkCompletion();

	// �Էµ� ���ڰ� �̹� �ԷµǾ����� ���� �Լ�
	bool alreadyCheaked(char letter);

	// �Է¹��� �ҹ��ڷ� ��ȯ or �ٽ� �Է�
	char switchedSmall(char letter) {

		char result = (char)letter;

		// �빮�� -> �ҹ���
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

// static ������� �ʱ�ȭ
string hangman::filename;
int hangman::wordsCnt = 0;
string hangman::words[1000];

int main() {

	// ���� ���ϸ�(�Է¹ޱ� ������)
	string filename = "word.txt";

	// �ܾ��忡 �ܾ� �Է�
	hangman::inputWords(filename);

	// Ư���� ���� ������ ����
	while (1) {

		system("cls");

		// hangman Ŭ���� ��ü game�� ������� �ʱ�ȭ
		// (= ������ ���� ���� ���� �Ϸ�) 
		hangman* game = new hangman();

		int menu = 0;

		cout << "���Ͻô� �޴��� �Է��� �ּ���(1 : ���ӽ���, 2 : ����, 3 : ġƮ���, 4 : ���ο� �ܾ���.txt ���� �Է�) : " << endl;
		cin >> menu;
		while (cin.get() != '\n');

		game->menu(menu);

		system("pause");
	}
	return 0;
}

// �ܾ� ���� _filename�� �ش�Ǵ� ������ words �迭�� �Է�(= �̽�)
void hangman::inputWords(string _filename) {

	//file ������ ���� & �ʱ�ȭ (file�� �̹� ���ʺ��� struct �����ε�, typedef�� FILE�̶�� �����ǰ� �Ǿ� ����)
	FILE* fileStream = NULL;

	// ���Ͽ��� �ܾ �б� ���� string ��ü
	char tmp[1024];

	// static filename���ϸ� _filename�� �Է�
	hangman::filename = _filename;

	// static words �迭 �ʱ�ȭ
	for (int i = 0; i < 1000; i++) {
		words[i] = "";
	}

	// static wordsCnt �ʱ�ȭ
	hangman::wordsCnt = 0;

	// 2. 1���� ������ file �б� ��� :  fopen_s ���� �� 0 ��ȯ
	if (fopen_s(&fileStream, _filename.data(), "r") == 0) {

		// # (���ڿ� �Է� �Լ�) fgets(���ڿ� ����, �Է� �ִ� ���ڼ�, ����������)
		//    : ���Ϸ� ���ڿ��� �о�� char�� �迭�� �����ϴ� �Լ� = ���๮��('\n')�� �迭�� ���̸�ŭ �������� 

		// 1�� ������ str �迭�� ���ڿ��� �����ϴ� while�� (���ڿ��� ���� �������� NULL �����ؼ�  while�� ������)
		while (fgets(tmp, 1024, fileStream) != NULL) {

			words[wordsCnt] = tmp;
			wordsCnt++;
		}

		printFile();

		// fclose(file ������) : ���� ������ �ݱ�
		fclose(fileStream);

	}
	// ���� ���� ���� (fopen_s�� ����� 0�� ��ȯ���� ���� ��)
	else {      

		printf("File Open Fail\n");
	}

}

// ���� ������ �ܾ� ���� ���� ��� (= static ������� �迭 words�� �� �ԷµǾ��� Ȯ�ο�)
void hangman::printFile() {

	cout << "[���� ����]" << endl;

	for (int i = 0; i < wordsCnt; i++) {
		cout << "word[" << i << "] = " << words[i];
	}

	cout << endl << endl;
}

// ������ : �ܾ� ���� �Է� (string �迭 string words[1000]�� �Է� )
hangman::hangman() {

	// ���� �ܾ� ���� ����
	answer = randomSelect();

	// ������ ���� �ڷ����� char*�̰� �� ��ġ�� �������� \0�� �������� string �迭 words�� ������� = words�� �� ��Ҵ� ���ڿ��� ���� �˸��� \0 ����
	//  -> (�߿�) ���� player�� ���� ���ڿ��� ���� = words�� �� ��ҿ��� �������� ������ ���ڿ� answer���� 1ũ��
	//      -> �� ���� �����ִ� ����      
	answer.pop_back();

	// ���� �������� _���� �ܾ� ���� ���� 
	string tmp(answer.length(), '_');
	hideAnswer = tmp;

	// ���� �߸����� �ܾ� ����
	cheaked.resize(26, '_');

	// ���� ���� ����� (�ʱⰪ = 10)
	Life = 10;
}

// �޴� ���� �Լ�
void hangman::menu(int& menu) {

	// 1, 3�� ������, �÷����� (3�� ġƮ����, ������� ������)
	if (menu == PLAY || menu == CHEAT) {

		cout << " ->> �ܾ��忡�� �ܾ ���õǾ����ϴ�! ���ݺ��� 10���� ��ȸ�� ������, a ~ z ���� �̴ϼ��� ��������." << endl << endl;

		playLoop(menu);

		// ������ ���� ��, player�� �ܾ �ϼ��ߴٸ�?
		if (this->checkCompletion()) {
			cout << "\n[CONGRATUAION!! YOU WIN ~!!]\n  ->> thank you for playing \n";
		}
		else {
			cout << "\n[G.A.M.E O.V.E.R!!]\n  ->> thank you for playing.. please try again~! \n";
		}

		// 2�� ������ ����
	}
	else if (menu == EXIT) {

		cout << "\n [ ���α׷� ���� �մϴ�. ] \n";
		exit(0);
	}
	else if (menu == NEWTXT) {

		// ���� ���ϸ�(�Է¹ޱ� ������)
		string filename;

		cout << "�Է��ϰ� ���� txt������ �����ּ��� (���ϸ�.txt �������� �����ñ�) : ";
		cin >> filename;

		// �ܾ��忡 �ܾ� �Է�
		hangman::inputWords(filename);
	}
}

// ���� ���� �� �ݺ��Ǵ� �κ�
void hangman::playLoop(int flag) {

	// �ܾ �������� �ʰ� + ����� 0�� �̻� �������� ��� ����
	while (!this->checkCompletion() && this->getLife() > 0) {

		this->printStatus(flag);

		// 1. player�� ���Ĺ� letter �Է�
		char letter;
		cout << "    ->> input alphabet! : ";
		cin >> letter;
		while (cin.get() != '\n');

		// 2. �Է��� ���ĺ� letter�� ���ĺ����� ���� Ȯ��
		//  -> NULL�� ���ϵǸ� �ٽ� �Է¤���
		if (switchedSmall(letter) == NULL) {
			continue;
		}
		else {
			letter = switchedSmall(letter);
		}

		// 3. �Է�letter�� ����� ������ ���� ����� ���� ��� ����(0 : ����, 1 : ����, 2 : �ߺ�)
		int flag = this->matchOrNot(letter);

		if (flag == 0) {
			cout << "     ->> (anouncement!) good answer!" << (!this->checkCompletion() ? " keep going!" : " complete!!") << endl << endl;
		}
		else if (flag == 1) {
			cout << "     ->> (anouncement!) wrong answer! 1 life stock is gone...�Ф�" << endl << endl;
			Life--;
		}
		else if (flag == 2) {
			cout << "     ->> (anouncement!) you already entered this letter [" << letter << "], please enter another!" << endl << endl;
		}
	}
}

// ������ �� �ܾ� ���� ���� �Լ�
string& hangman::randomSelect() {

	srand((unsigned int)time(NULL));

	// �ܾ� �� ��ŭ�� ������ ���� �ش��ϴ� words�� index ä��
	return words[rand() % wordsCnt];
}

// �������� player ���� ��� �Լ� (menu�� 3�̸� ġƮ���)
void hangman::printStatus(int flag) {

	cout << "[current situation]" << endl;
	cout << " - life stock : " << Life << endl;
	cout << " - cheaked letters : " << cheaked << endl << endl;
	cout << " - player's word : " << hideAnswer << endl;

	if (flag != 1) {

		cout << " - (Cheat mode on) the answer : " << answer << endl;
	}
}

// ��� Ȯ�� �Լ�
int hangman::getLife() {
	return Life;
}

// ���ĺ� & ��� �� �Լ� (0 : ����, 1 : ����, 2 : �ߺ�)
int hangman::matchOrNot(char letter) {

	// �Է��� ���ĺ��� �̹� �Էµ� �༮���� ���� Ȯ��
	if (alreadyCheaked(letter) == true) {
		return 2;
	}

	// �Էµ� �༮�� �ƴϸ� cheacked ���� (char�� ���� index�� �̿�, ���������� a~z���� ������ cheaked�� �迭�� ����)
	cheaked[letter - 97] = letter;

	// �� �� �Էµ� ���ڰ� ���� ���信 �ִ��� Ȯ��
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

// player�� �ܾ �ϼ��ߴ��� Ȯ�� �Լ�
bool hangman::checkCompletion() {

	// player�� �ܾ� ���ڿ��� ���� ���ڿ��� ���ؼ�, ��ġ�� ������ true
	if (hideAnswer.compare(answer) == 0) {
		return true;
	}

	return false;
}

// �Էµ� ���ڰ� �̹� �ԷµǾ����� ����
bool hangman::alreadyCheaked(char letter) {

	// ���� cheak[���ĺ��� letter ����]�� �ش��ϴ� �κ��� ��ġ�ϸ�?
	//  -> �ߺ��Է� ����
	if (cheaked[letter - 97] == letter) {
		return true;
	}

	return false;
}

