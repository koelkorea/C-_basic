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
#include <string>
#include <iostream>
#include <cstdlib>				//	srand(), rand() 함수 사용 가능하게 함
#include <ctime>
using namespace std;

class hangman {

	private:
		// 입, 출력 파일목록을 불러올때
		static string filename;

		// 현재 저장된 단어의 갯수
		static int wordsCnt;

		// 단어들 저장된 문자열 (파일에서 가져오던가, 대입해서 넣던가)
		static string words[1000];

		// 정답 단어 저장 변수
		string answer;

		// 현재 진행중인 _포함 단어 저장 변수
		string hideAnswer;

		// 현재 잘못뽑은 단어 모음
		string bad;

		// 현재 남은 생명령 (초기값 = 10)
		int Life;

	public:

		// 단어 파일 정보 출력
		static void printFile();

		// 생성자 : 단어 파일 입력
		hangman(string _words[], int size);

		// 멤버 변수 초기화
		void init(); 

		// 목숨 확인 함수
		int lifeCheck(); 

		// 정답 확인 함수
		bool isSolve(); 

		// 진행중인 답안 출력 함수
		void printAnswer(int flag = 1);

		// 메뉴 선택 함수
		void menu(int& menu); 

		// 단어 파일 재입력 함수
		void saveWord();

		// 제시 단어 랜덤 선택
		string& randomSelect(); 

		// 알파벳 & 답안 비교 함수
		bool guesses(char letter); 
};

string hangman::filename;
int hangman::wordsCnt = 0;
string hangman::words[1000];

int main() {

	string word[] = { "inform", "advise", "service", "provide", "relationship", "behave", "improve", "individual", "require", "million",
			"social", "amount", "employ", "terrible", "attitude", "research", "audience", "volunteer", "influence", "international",
			"opportunity", "ability", "expense", "involve", "stress", "therefore", "average", "ride", "local", "encourage", "determine",
			"comfort", "consume", "object", "impress", "available", "contain", "diet", "recognize", "material", "positive",	"emotion",
			"amaze", "level", "mine", "essence", "benefit", "affect", "reduce", "chemistry", "immediate", "thus", "proper",	"profession",
			"economic", "cell", "focus", "issue", "poetry", "demand", "occur", "complex", "define", "proud", "aware", "contact", "performance",
			"detail", "approach", "participate", "fashion", "package", "disappear", "career", "secure", "novel", "despite", "background", "solution",
			"generate", "eventually", "decrease", "recycle", "desire", "balance", "publish", "congratulate", "compose", "digital", "negative", "occasion",
			"replace", "expert", "term", "relieve", "describe", "biology", "due", "equipment", "account", "birth", "constant", "genius", "reflect", "illness",
			"frequent", "steady", "extreme", "tend", "insist", "extend", "politics", "lonely", "habitat", "mental", "factor", "exchange", "active", "species",
			"athletic", "dental", "delight", "confident", "gradual", "electricity", "shadow", "access", "announce", "tense", "firm", "vary", "injure", "permit",
			"threat", "flood", "disabled", "lack", "signify", "concentrate", "emphasize", "astronomy", "commerce", "capable", "fuel", "manufacture", "movement",
			"combine", "gene", "response", "victim", "pressure", "accompany", "frustrate", "construct", "fiction", "laughter", "entertain", "predict", "apologize",
			"outdoor", "sight", "quantity", "conclude", "donate", "personality", "struggle", "electronic", "absorb", "advantage", "incredible", "enable", "instruction",
			"assume", "attempt", "variety", "confuse", "indicate", "analyze", "labor", "remark", "moral", "embarrass", "claim", "stock", "resident", "reasonable",
			"interrupt", "discount", "creature", "heal", "stranger", "revolution", "criticize", "convince", "feature", "tide", "establish", "obtain", "assist",
			"disaster", "efficient", "terrific", "react", "independent", "theory", "qualify", "clue", "recall", "risk", "cancer", "treatment", "specific", "engage",
			"motivate", "import", "elder", "depress", "fascinate", "violent", "alarm", "edge", "deserve", "route", "psychology", "mole", "passion", "weed", "conscience",
			"stripe", "salary", "pose", "purchase", "length", "occupy", "acquire", "interact", "grocer", "lifetime", "decade", "grain", "meaningful", "brief",
			"severe", "survival", "comment", "leap", "survey", "mechanic", "mood", "mere", "typical", "approve", "rural", "finance", "operation", "crime", "awful",
			"series", "exhausted", "flu", "surround", "display", "policy", "mass", "committee", "accurate", "arrange", "consult", "reward", "recover", "facility",
			"dust", "downtown", "attach", "monster", "enormous", "domestic", "elementary", "refer", "gap", "Renaissance", "journey", "plain", "previous", "slight",
			"leisure", "telescope", "stroke", "delicious", "breed", "muscle", "delay", "file", "ethic", "instant", "reveal", "junk", "urban", "witness", "admit",
			"device", "owe", "intend", "award", "preserve", "underground", "consequence", "aspect", "target", "headache", "horizon", "accomplish", "surf", "adopt",
			"potential", "slip", "civilization", "row", "atmosphere", "label", "decorate", "identify", "secretary", "scale", "addict", "evident", "seldom", "standard",
			"basis", "automatic", "region", "sake", "artificial", "possess", "substance", "realistic", "physics", "encounter", "differ", "principle", "memorize",
			"evaluate", "fulfill", "staff", "tremendous", "application", "vote", "railroad", "cooperate", "emit", "request", "guarantee", "resist", "grant", "permanent",
			"emergency", "rid", "impact", "theme", "rely", "hesitate", "location", "organism", "resolve", "curve", "suitable", "distribute", "restrict", "rainforest",
			"circumstance", "interpret", "recite", "annoy", "fright", "estimate", "cabin", "adventure", "entrance", "persuade", "gear", "ray", "release", "slave",
			"perceive", "rank", "nowadays", "symphony", "envy", "corporate", "autograph", "retire", "appeal", "identical", "innocence", "investment", "authority",
			"alternative", "infant", "calculate", "charity", "guilt", "whereas", "broad", "ignorant", "mummy", "pure", "extinct", "household", "chapter", "refund",
			"institute", "lately", "luxury", "ashamed", "dense", "rescue", "mount", "destination", "expand", "evolution", "isolate", "gravity", "genuine", "status",
			"compete", "military", "logic", "commit", "sensible", "sum", "conserve", "swing", "reproduce", "tone", "concept", "invitation", "precise", "formal",
			"particle", "cancel", "departure", "apparent", "visual", "agriculture", "rite", "poverty", "sculpture", "descend", "leak", "portion", "companion",
			"diligent", "distinct", "component", "shave", "universal", "trap", "eager", "legal", "demonstrate", "democracy", "mature", "brilliant", "annual", "faith",
			"spare", "transfer", "refrigerator", "oppose", "desperate", "remote", "offend", "awake", "spaceship", "insight", "trousers", "civil", "complicated",
			"backpack", "tropics", "minor", "duty", "pause", "option", "digest", "shortage", "laboratory", "generous", "laundry", "transform", "discipline",
			"kindergarten", "forbid", "ultimate", "thrive", "royal", "ruin", "manual", "evil", "horror", "worship", "afterward", "client", "insure", "scarce", "fancy",
			"surgery", "assign", "regulate", "shelf", "highway", "utility", "yield", "decline", "aside", "tolerate", "cottage", "coincidence", "contemporary", "bless",
			"prey", "prior", "necessity", "abstract", "league", "fuse", "confirm", "explain", "imitate", "defeat", "niece", "illustrate", "pupil", "intellect", "spice",
			"tempt", "inspire", "dine", "literal", "resort", "grab", "alien", "alcohol", "wreck", "triumph", "document", "suspect", "propose", "install", "prohibit",
			"appropriate", "scholarship", "execute", "trunk", "receipt", "defect", "commute", "trait", "split", "modest", "virtual", "nutrition", "inner", "contrary",
			"ensure", "supervise", "inhabit", "earthquake", "enroll", "seal", "greed", "debate", "spray", "abandon", "conquer", "nevertheless", "volcano", "contract",
			"retail", "prejudice", "agency", "nurture", "priest", "elegant", "lawn", "impose", "masterpiece", "harsh", "drought", "arise", "criteria", "extraordinary",
			"swallow", "dim", "general", "scream", "ladder", "spill", "glare", "modify", "usual", "routine", "eliminate", "deny", "sensitive", "tragic", "deprive",
			"interfere", "temporary", "council", "adolescent", "arctic", "capture", "mill", "associate", "warehouse", "crew", "barrier", "pedestrian", "welfare",
			"cliff", "irritate", "glance", "cruel", "fold", "trial", "tribe", "profound", "annals", "distinguish", "statement", "prevail", "infection", "widespread",
			"drastic", "fade", "needle", "weapon", "reinforcement", "germ", "endanger", "pile", "atom", "peer", "enrich", "galaxy", "renew", "adjust", "noble",
			"candidate", "ideal", "statistics", "ethnic", "foretell", "wonder", "wholesale", "debt", "representative", "oral", "realize", "excess", "appliance",
			"furthermore", "command", "ecosystem", "nap", "fame", "shift", "outstanding", "drift", "mislead", "dedicate", "eyesight", "initial", "beard", "haste",
			"crush", "confront", "destiny", "hardship", "valid", "idiom", "dispose", "fiber", "hydrogen", "thread", "dynasty", "scatter", "gamble", "temper", "craft",
			"undoubtedly", "raft", "rubber", "soak", "specialist", "combat", "cease", "ceiling", "unify", "perspective", "doom", "bump", "genre", "erase", "moderate",
			"graze", "vital", "incident", "session", "fragile", "review", "geometry", "budget", "suffix", "fur", "indifferent", "strain", "wrinkle", "ingredient",
			"dismiss", "glacier", "urge", "celebrity", "antique", "sphere", "inherit", "disgrace", "crawl", "scratch", "diabetes", "congestion", "constitute", "barter",
			"investigate", "circular", "chilly", "activate", "fierce", "vague", "editorial", "magnet", "chatter", "obstacle", "fertile", "abolish", "assure", "rehearse",
			"gender", "innovation", "emperor", "dwell", "opponent", "chore", "fossil", "glitter", "carve", "decay", "protein", "backward", "tissue", "refresh", "miniature",
			"acne", "lord", "substitute", "scan", "pottery", "layer", "scent", "radiant", "exclaim", "polish", "flavor", "imprint", "heritage", "strive", "property",
			"majesty", "portray", "subscribe", "shrug", "wage", "asset", "intimate", "merit", "launch", "conference", "reception", "administer", "vicious", "cherish",
			"accuse", "eternal", "robber", "overwhelm", "transmit", "copper", "orbit", "smash", "discard", "famine", "pill", "enhance", "immune", "superior", "string",
			"cope", "raw", "moist", "cattle", "loan", "obedient", "procedure", "bond", "therapy", "subtle", "depict", "radical", "angle", "caution", "persist", "reverse",
			"architecture", "territory", "strategy", "hence", "panic", "wilderness", "necklace", "category", "murder", "funeral", "clip", "flush", "omit", "outcome",
			"alert", "despair", "compact", "embassy", "astonish", "optimistic", "loyal", "humid", "rumor", "deluxe", "delicate", "inflate", "adequate", "physician",
			"joint", "via", "passage", "cradle", "vessel", "restore", "passive", "idiot", "marble", "classify", "fundamental", "transaction", "sufficient", "stable",
			"sympathy", "eyebrow", "edible", "federal", "bud", "trivial", "anxiety", "tablet", "dizzy", "liquid", "contend", "outlook", "roam", "decent", "tenant" };

	int size = sizeof(word) / sizeof(word[0]);

	hangman* game = new hangman(word, size);

	int menu = 0;

	while (1) {

		system("cls");

		cout << "메뉴를 입력해라(1 = 게임시작, 2 = 종료, 3 = 치트모드) : " << endl;
		cin >> menu;
		game->menu(menu);

		switch (menu) {
			case 3:
			case 1:
				game->init();
				while (!game->isSolve() && game->lifeCheck() > 0) {

					game->printAnswer(menu);

					char letter;
					cin >> letter;
					while (cin.get() != '\n');

					game->guesses(letter);

				}
				break;

			case 2:
				cout << "\n [ 프로그램 종료 합니다. ] \n";
				exit(0);

			case 4:
				game->saveWord();
				continue;
		}

		if (game->isSolve()) {

			game->printAnswer();
			cout << " 축하합니다. 정답을 맞추셨습니다.!! \n";

		}else {
			cout << " ㅠ.ㅠ 정답을 맞추지 못 했습니다. \n";
		}

		system("pause");
	}
	return 0;
}

// 파일 읽을시 단어 파일 정보 출력
void hangman::printFile() {

}

// 생성자 : 단어 파일 입력 (string 배열 string words[1000]에 입력 )
hangman::hangman(string _words[], int size) {

	for (int i = 0; i < size; i++) {
		words[i] = _words[i];
		wordsCnt++;
	}
}

// 멤버 변수 초기화
void hangman::init() {

	// 정답 단어 저장 변수
	answer = randomSelect();

	// 현재 진행중인 _포함 단어 저장 변수
	string tmp(answer.length(), '_');
	hideAnswer = tmp;

	// 현재 잘못뽑은 단어 모음
	bad.resize(26, '_');

	// 현재 남은 생명령 (초기값 = 10)
	Life = 10;
}

// 목숨 확인 함수
int hangman::lifeCheck() {
	return Life;
}

// 정답 확인 함수
bool hangman::isSolve() {
	if (hideAnswer.compare(answer) == 0) {
		return true;
	}

	return false;
}

// 진행중인 답안 출력 함수
void hangman::printAnswer(int flag) {

	cout << "player's word : " << hideAnswer << endl;

	if (flag != 1) {

		cout << "(Cheat mode on) the answer : " << answer << endl;
	}
}

// 메뉴 선택 함수
void hangman::menu(int& menu) {

}

// 단어 파일 재입력 함수
void hangman::saveWord() {
	cout << "your choice letters : " << bad << endl;
}

// 제시 단어 랜덤 선택
string& hangman::randomSelect() {

	srand((unsigned int)time(NULL));
	return words[rand() % wordsCnt];
}

// 알파벳 & 답안 비교 함수
bool hangman::guesses(char letter) {

	if (answer.find(letter) == true) {

		for (int i = 0; i < wordsCnt; i++) {

			if (answer[i] == letter) {
				hideAnswer[i] = answer[i];
			}
		}

		return true;
	}

	return false;
}