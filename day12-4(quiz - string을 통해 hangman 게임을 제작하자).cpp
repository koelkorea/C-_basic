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
#include <string>
#include <iostream>
#include <cstdlib>				//	srand(), rand() �Լ� ��� �����ϰ� ��
#include <ctime>
using namespace std;

class hangman {

	private:
		// ��, ��� ���ϸ���� �ҷ��ö�
		static string filename;

		// ���� ����� �ܾ��� ����
		static int wordsCnt;

		// �ܾ�� ����� ���ڿ� (���Ͽ��� ����������, �����ؼ� �ִ���)
		static string words[1000];

		// ���� �ܾ� ���� ����
		string answer;

		// ���� �������� _���� �ܾ� ���� ����
		string hideAnswer;

		// ���� �߸����� �ܾ� ����
		string bad;

		// ���� ���� ����� (�ʱⰪ = 10)
		int Life;

	public:

		// �ܾ� ���� ���� ���
		static void printFile();

		// ������ : �ܾ� ���� �Է�
		hangman(string _words[], int size);

		// ��� ���� �ʱ�ȭ
		void init(); 

		// ��� Ȯ�� �Լ�
		int lifeCheck(); 

		// ���� Ȯ�� �Լ�
		bool isSolve(); 

		// �������� ��� ��� �Լ�
		void printAnswer(int flag = 1);

		// �޴� ���� �Լ�
		void menu(int& menu); 

		// �ܾ� ���� ���Է� �Լ�
		void saveWord();

		// ���� �ܾ� ���� ����
		string& randomSelect(); 

		// ���ĺ� & ��� �� �Լ�
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

		cout << "�޴��� �Է��ض�(1 = ���ӽ���, 2 = ����, 3 = ġƮ���) : " << endl;
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
				cout << "\n [ ���α׷� ���� �մϴ�. ] \n";
				exit(0);

			case 4:
				game->saveWord();
				continue;
		}

		if (game->isSolve()) {

			game->printAnswer();
			cout << " �����մϴ�. ������ ���߼̽��ϴ�.!! \n";

		}else {
			cout << " ��.�� ������ ������ �� �߽��ϴ�. \n";
		}

		system("pause");
	}
	return 0;
}

// ���� ������ �ܾ� ���� ���� ���
void hangman::printFile() {

}

// ������ : �ܾ� ���� �Է� (string �迭 string words[1000]�� �Է� )
hangman::hangman(string _words[], int size) {

	for (int i = 0; i < size; i++) {
		words[i] = _words[i];
		wordsCnt++;
	}
}

// ��� ���� �ʱ�ȭ
void hangman::init() {

	// ���� �ܾ� ���� ����
	answer = randomSelect();

	// ���� �������� _���� �ܾ� ���� ����
	string tmp(answer.length(), '_');
	hideAnswer = tmp;

	// ���� �߸����� �ܾ� ����
	bad.resize(26, '_');

	// ���� ���� ����� (�ʱⰪ = 10)
	Life = 10;
}

// ��� Ȯ�� �Լ�
int hangman::lifeCheck() {
	return Life;
}

// ���� Ȯ�� �Լ�
bool hangman::isSolve() {
	if (hideAnswer.compare(answer) == 0) {
		return true;
	}

	return false;
}

// �������� ��� ��� �Լ�
void hangman::printAnswer(int flag) {

	cout << "player's word : " << hideAnswer << endl;

	if (flag != 1) {

		cout << "(Cheat mode on) the answer : " << answer << endl;
	}
}

// �޴� ���� �Լ�
void hangman::menu(int& menu) {

}

// �ܾ� ���� ���Է� �Լ�
void hangman::saveWord() {
	cout << "your choice letters : " << bad << endl;
}

// ���� �ܾ� ���� ����
string& hangman::randomSelect() {

	srand((unsigned int)time(NULL));
	return words[rand() % wordsCnt];
}

// ���ĺ� & ��� �� �Լ�
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