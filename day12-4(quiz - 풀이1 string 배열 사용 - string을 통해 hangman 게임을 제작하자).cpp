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
#define PLAY 1
#define EXIT 2
#define CHEAT 3

using namespace std;

class hangman {

private:

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
	static void inputWords(string _words[], int size);

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

	// 단어장에 단어 입력
	hangman::inputWords(word, sizeof(word) / sizeof(word[0]));

	// 특별한 이유 없으면 종료
	while (1) {

		system("cls");

		// hangman 클래스 객체 game의 멤버변수 초기화
		// (= 생성자 통한 게임 세팅 완료) 
		hangman* game = new hangman();

		int menu = 0;

		cout << "원하시는 메뉴를 입력해 주세요(1 : 게임시작, 2 : 종료, 3 : 치트모드) : " << endl;
		cin >> menu;
		while (cin.get() != '\n');

		game->menu(menu);

		system("pause");
	}
	return 0;
}

// 단어 파일 입력
void hangman::inputWords(string _words[], int size) {

	for (int i = 0; i < size; i++) {
		words[i] = _words[i];
		wordsCnt++;
	}
}

// 생성자 : 단어 파일 입력 (string 배열 string words[1000]에 입력 )
hangman::hangman() {

	// 정답 단어 저장 변수
	answer = randomSelect();

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

