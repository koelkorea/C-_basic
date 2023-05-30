// [모범답안]
// quiz - template를 이용해서, 적은 코드로도 범용성 높은 자료형을 포괄가능한 컨테이너 클래스인 stack의 class를 구현하라 

#include <iostream>
using namespace std;

template <typename T, int size> //타입(자료형)이 아닌 인수 전달
class stack {     //stack클래스 템플릿

    private:
        T* arr;       //동적 메모리의 주소를 저장
        int top;      //배열의 저장 위치

    public:
        stack() { arr = new T[size]; top = 0; }
        ~stack() { delete[] arr; }
        void push(T value) { if (top < size) { arr[top] = value; top++; } }
        inline void pop() { if (top > 0)top--; }
        inline void clear() { top = 0; }//스택 초기화
        inline T getTop() const { return arr[top - 1]; }//마지막 저장 값 리턴
        void print() const;
        bool isEmpty();
};

template <typename T, int size>
void stack<T, size>::print() const {
    cout << "stack display (LIFO) : ";
    for (int i = top - 1; i >= 0; i--) cout << arr[i] << ' ';
    cout << endl;
}

template <typename T, int size>
bool stack<T, size>::isEmpty() {
    if (top == 0) return true;
    else return false;
}

typedef char element; // 스택 자료형 변경
#define count 100 // 스택 수량 변경

int main() {
    stack<element, count> stk;
    while (true) {
        system("cls");
        cout << "\n\n\t\t *** stack *** \n\n";
        cout << "1. push    2. pop    3. clear    4. print    0. terminate\n";
        cout << "choice : ";
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cout << "Wrong Input. Retry" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        element data = 0;
        switch (choice) {
        case 1:
            cout << "value push : ";
            cin >> data;
            if (cin.fail()) {
                cout << "Wrong Input. Retry" << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
            else stk.push(data);
            break;
        case 2:
            if (!stk.isEmpty())
            {
                cout << "\n\n\t\t[" << stk.getTop() << "] pop!!!\n";
                stk.pop();
            }
            break;
        case 3:
            stk.clear();
            break;
        case 4:
            stk.print();
            break;
        case 0:
            return 0; //프로그램 종료
        }
        cout << "\n\n\t\t";
        system("pause");
    }
    return 0;
}
