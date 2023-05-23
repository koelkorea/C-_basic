#include <iostream>
#include <string>
#include <list>
using namespace std

class customer {//�߻� Ŭ����
public:
    virtual ~customer() { cout << "�ֻ��� Ŭ���� �Ҹ���\n"; }
    virtual void customerinfo() = 0;
    virtual const int getprice() const = 0;
    virtual void login() = 0;
    virtual const string getname() const = 0;
    virtual const string getphone() const = 0;
    void MainMenu(int& main) {
        system("cls");
        cout << " [ �ް� Ŀ�� Kiosk ] \n";
        cout << "1. Ŀ�� \n";
        cout << "2. ������ & ������ & �ֽ� \n";
        cout << "3. ���̵� & �� \n";
        cout << "4. ����Ʈ \n";
        cout << "5. ����� �� �ݾ� \n";
        cout << "10. ���� \n";
        cout << "�޴��� �Է� �ϼ���. : ";
        while (!(cin >> main)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  �ٽ� �Է� �ϼ���. : ";
        }
        while (cin.get() != '\n');
    }
    void SubMenu1(int& sub1) {
        system("cls");
        cout << " [ �ް� Ŀ�� Kiosk ] \n";
        cout << "(1). �Ƹ޸�ī�� \n";
        cout << "(2). īǪġ�� \n";
        cout << "(3). ī���ī \n";
        cout << "(4). �ݵ��� \n";
        cout << "(10). ���� �޴���... \n";
        cout << "�޴��� �Է� �ϼ���. : ";
        while (!(cin >> sub1)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  �ٽ� �Է� �ϼ���. : ";
        }
        while (cin.get() != '\n');
    }
    void SubMenu2(int& sub1) {
        system("cls");
        cout << " [ �ް� Ŀ�� Kiosk ] \n";
        cout << "(1). �������������� \n";
        cout << "(2). �÷�����ũ���� \n";
        cout << "(3). ������������ \n";
        cout << "(4). ��Ʈ�κ���ġ��Ȧ�� \n";
        cout << "(10). ���� �޴���... \n";
        cout << "�޴��� �Է� �ϼ���. : ";
        while (!(cin >> sub1)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  �ٽ� �Է� �ϼ���. : ";
        }
        while (cin.get() != '\n');
    }
    void SubMenu3(int& sub1) {
        system("cls");
        cout << " [ �ް� Ŀ�� Kiosk ] \n";
        cout << "(1). ü���� \n";
        cout << "(2). ��緹���̵� \n";
        cout << "(3). ��׷��� \n";
        cout << "(4). ����ڸ���Ƽ \n";
        cout << "(10). ���� �޴���... \n";
        cout << "�޴��� �Է� �ϼ���. : ";
        while (!(cin >> sub1)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  �ٽ� �Է� �ϼ���. : ";
        }
        while (cin.get() != '\n');
    }
    void SubMenu4(int& sub1) {
        system("cls");
        cout << " [ �ް� Ŀ�� Kiosk ] \n";
        cout << "(1). �÷��� ũ���� \n";
        cout << "(2). Ƽ��̼� ����ũ \n";
        cout << "(3). ��׷��� �Ŀ�� \n";
        cout << "(4). ��õ ���ڻ� \n";
        cout << "(10). ���� �޴���... \n";
        cout << "�޴��� �Է� �ϼ���. : ";
        while (!(cin >> sub1)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  �ٽ� �Է� �ϼ���. : ";
        }
        while (cin.get() != '\n');
    }
    virtual void order() = 0;
};
class menu : public customer {
protected:
    string name;
    string phone;
    string product;
    int price;
    static unsigned long callnum;
public:
    menu(string _name = "Mega", string _phone = "010-0000-0000", string _product = "water", int _price = 0)
        :name(_name), phone(_phone), product(_product), price(_price) {
    }
    const int getprice() const { return price; }
    const string getname() const { return name; }
    const string getphone() const { return phone; }
    void login() {
        cout << " [ �ް� Ŀ�� Kiosk ] \n";
        cout << " (�̸��� ����ó�� �����ּ���.) \n";
        cout << "��    �� : ";
        getline(cin, name);
        cout << "�� �� ó : ";
        getline(cin, phone);
        callnum++;
    }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
    }
    void customerinfo() {
        cout << "��    �� : " << name << endl;
        cout << "�� �� ó : " << phone << endl;
        cout << "ȣ���ȣ : " << callnum << endl << endl;
    }
};
unsigned long menu::callnum;
class Americano : public menu {
protected:
    string variety;  //Ŀ�� ǰ�� Arabica, Robusta, Liberica
public:
    Americano(string _name = "Mega", string _phone = "010-0000-0000", string _variety = "Arabica", string _product = "Americano", int _price = 1500)
        :menu(_name, _phone, _product, _price), variety(_variety) {}
    const string& getvariety()const { return variety; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "Ŀ��ǰ�� : " << variety << endl << endl;
    }
};
class Cappuccino : public menu {
protected:
    string variety;  //Ŀ�� ǰ�� Arabica, Robusta, Liberica
public:
    Cappuccino(string _name = "Mega", string _phone = "010-0000-0000", string _variety = "Robusta", string _product = "Americano", int _price = 2700)
        :menu(_name, _phone, _product, _price), variety(_variety) {}
    const string& getvariety()const { return variety; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "Ŀ��ǰ�� : " << variety << endl << endl;
    }
};
class CafeMocha : public menu {
protected:
    string variety;  //Ŀ�� ǰ�� Arabica, Robusta, Liberica
public:
    CafeMocha(string _name = "Mega", string _phone = "010-0000-0000", string _variety = "Liberica", string _product = "CafeMocha", int _price = 3700)
        :menu(_name, _phone, _product, _price), variety(_variety) {}
    const string& getvariety()const { return variety; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "Ŀ��ǰ�� : " << variety << endl << endl;
    }
};
class Coldbrew : public menu {
protected:
    string variety;  //Ŀ�� ǰ�� Arabica, Robusta, Liberica
public:
    Coldbrew(string _name = "Mega", string _phone = "010-0000-0000", string _variety = "Robusta", string _product = "Coldbrew", int _price = 3300)
        :menu(_name, _phone, _product, _price), variety(_variety) {}
    const string& getvariety()const { return variety; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "Ŀ��ǰ�� : " << variety << endl << endl;
    }
};

class Realchocofrappe : public menu {
protected:
    string topping;
public:
    Realchocofrappe(string _name = "Mega", string _phone = "010-0000-0000", string _topping = "More Whipping cream", string _product = "Real chocolate frappe", int _price = 3900)
        :menu(_name, _phone, _product, _price), topping(_topping) {}
    const string& gettopping()const { return topping; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "�߰����� : " << topping << endl << endl;
    }
};
class Plainpongcrush : public menu {
protected:
    string topping;
public:
    Plainpongcrush(string _name = "Mega", string _phone = "010-0000-0000", string _topping = "Nothing", string _product = "Plain pongcrush", int _price = 3900)
        :menu(_name, _phone, _product, _price), topping(_topping) {}
    const string& gettopping()const { return topping; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "�߰����� : " << topping << endl << endl;
    }
};
class Unicornfrappe : public menu {
protected:
    string topping;
public:
    Unicornfrappe(string _name = "Mega", string _phone = "010-0000-0000", string _topping = "Nothing", string _product = "Unicorn frappe", int _price = 4800)
        :menu(_name, _phone, _product, _price), topping(_topping) {}
    const string& gettopping()const { return topping; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "�߰����� : " << topping << endl << endl;
    }
};
class  StrawberryCheeseholic : public menu {
protected:
    string topping;
public:
    StrawberryCheeseholic(string _name = "Mega", string _phone = "010-0000-0000", string _topping = "full of strawberry", string _product = "Strawberry Cheeseholic", int _price = 4500)
        :menu(_name, _phone, _product, _price), topping(_topping) {}
    const string& gettopping()const { return topping; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "�߰����� : " << topping << endl << endl;
    }
};

class  CherryCoke : public menu {
protected:
    string size;
public:
    CherryCoke(string _name = "Mega", string _phone = "010-0000-0000", string _size = "Grande", string _product = "Cherry Coke", int _price = 3000)
        :menu(_name, _phone, _product, _price), size(_size) {}
    const string& getsize()const { return size; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "����뷮 : " << size << endl << endl;
    }
};
class  Bluelemonade : public menu {
protected:
    string size;
public:
    Bluelemonade(string _name = "Mega", string _phone = "010-0000-0000", string _size = "Venti", string _product = "Blue lemonade", int _price = 3500)
        :menu(_name, _phone, _product, _price), size(_size) {}
    const string& getsize()const { return size; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "����뷮 : " << size << endl << endl;
    }
};
class  EarlGrey : public menu {
protected:
    string size;
public:
    EarlGrey(string _name = "Mega", string _phone = "010-0000-0000", string _size = "Grande", string _product = "Earl Grey", int _price = 2500)
        :menu(_name, _phone, _product, _price), size(_size) {}
    const string& getsize()const { return size; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "����뷮 : " << size << endl << endl;
    }
};
class  GrapefruitHoneyBlacktea : public menu {
protected:
    string size;
public:
    GrapefruitHoneyBlacktea(string _name = "Mega", string _phone = "010-0000-0000", string _size = "Venti", string _product = "Grapefruit Honey Black tea", int _price = 3500)
        :menu(_name, _phone, _product, _price), size(_size) {}
    const string& getsize()const { return size; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "����뷮 : " << size << endl << endl;
    }
};

class  Plaincroiffle : public menu {
protected:
    string packaging;
public:
    Plaincroiffle(string _name = "Mega", string _phone = "010-0000-0000", string _packaging = "Packaging", string _product = "Plain croiffle", int _price = 2500)
        :menu(_name, _phone, _product, _price), packaging(_packaging) {}
    const string& getpackaging()const { return packaging; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "�Ļ�&���� : " << packaging << endl << endl;
    }
};
class  TiramisuCake : public menu {
protected:
    string packaging;
public:
    TiramisuCake(string _name = "Mega", string _phone = "010-0000-0000", string _packaging = "Packaging", string _product = "Tiramisu Cake", int _price = 2500)
        :menu(_name, _phone, _product, _price), packaging(_packaging) {}
    const string& getpackaging()const { return packaging; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "�Ļ�&���� : " << packaging << endl << endl;
    }
};
class  EarlGreyPound : public menu {
protected:
    string packaging;
public:
    EarlGreyPound(string _name = "Mega", string _phone = "010-0000-0000", string _packaging = "Packaging", string _product = "Earl Grey Pound", int _price = 2500)
        :menu(_name, _phone, _product, _price), packaging(_packaging) {}
    const string& getpackaging()const { return packaging; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "�Ļ�&���� : " << packaging << endl << endl;
    }
};
class  Potatobread : public menu {
protected:
    string packaging;
public:
    Potatobread(string _name = "Mega", string _phone = "010-0000-0000", string _packaging = "Packaging", string _product = "Potato bread", int _price = 2500)
        :menu(_name, _phone, _product, _price), packaging(_packaging) {}
    const string& getpackaging()const { return packaging; }
    void order() {
        cout << "�� ǰ �� : " << product << endl;
        cout << "��    �� : " << price << endl;
        cout << "�Ļ�&���� : " << packaging << endl << endl;
    }
};
int main() {
    customer* Neworder = nullptr;

    customer* KIOSK = new menu;
    list< customer* > list1;
    list1.clear();
    list< customer* >::iterator itr;
    int menu1 = 0, menu2 = 0;
    double total = 0;

    KIOSK->login();
    while (1) {

        KIOSK->MainMenu(menu1);
        switch (menu1) {
        case 1:
            KIOSK->SubMenu1(menu2);
            switch (menu2) {
            case 1: Neworder = new Americano(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 2: Neworder = new Cappuccino(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 3: Neworder = new CafeMocha(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 4: Neworder = new Coldbrew(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            }
            break;
        case 2:
            KIOSK->SubMenu2(menu2);
            switch (menu2) {
            case 1: Neworder = new Realchocofrappe(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 2: Neworder = new Plainpongcrush(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 3: Neworder = new Unicornfrappe(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 4: Neworder = new StrawberryCheeseholic(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            }
            break;
        case 3:
            KIOSK->SubMenu3(menu2);
            switch (menu2) {
            case 1: Neworder = new CherryCoke(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 2: Neworder = new Bluelemonade(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 3: Neworder = new EarlGrey(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 4: Neworder = new GrapefruitHoneyBlacktea(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            }
            break;
        case 4:
            KIOSK->SubMenu4(menu2);
            switch (menu2) {
            case 1: Neworder = new Plaincroiffle(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 2: Neworder = new TiramisuCake(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 3: Neworder = new EarlGreyPound(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            case 4: Neworder = new Potatobread(KIOSK->getname(), KIOSK->getphone()); list1.push_back(Neworder); break;
            }
            break;
        case 5:
            KIOSK->customerinfo();
            for (itr = list1.begin(); itr != list1.end(); itr++)
            {
                (*itr)->order();
                total += (*itr)->getprice();
            }
            cout << " �� ����Ͻ� �ݾ��� : " << total << " �� �Դϴ�. \n\n";
            total = 0;
            list1.clear();
            system("pause");
            break;
        case 10:
            cout << " [ ���α׷� ���� �մϴ�. ] \n\n\n";
            exit(0);
        }
    }
    return 0;
}
