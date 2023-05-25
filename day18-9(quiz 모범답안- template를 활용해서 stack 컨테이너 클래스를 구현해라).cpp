// [������]
// quiz - template�� �̿��ؼ�, ���� �ڵ�ε� ���뼺 ���� �ڷ����� ���������� �����̳� Ŭ������ stack�� class�� �����϶� 

#include <iostream>
using namespace std;

template <typename T, int size> //Ÿ��(�ڷ���)�� �ƴ� �μ� ����
class stack {     //stackŬ���� ���ø�

    private:
        T* arr;       //���� �޸��� �ּҸ� ����
        int top;      //�迭�� ���� ��ġ

    public:
        stack() { arr = new T[size]; top = 0; }
        ~stack() { delete[] arr; }
        void push(T value) { if (top < size) { arr[top] = value; top++; } }
        inline void pop() { if (top > 0)top--; }
        inline void clear() { top = 0; }//���� �ʱ�ȭ
        inline T getTop() const { return arr[top - 1]; }//������ ���� �� ����
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

typedef char element; // ���� �ڷ��� ����
#define count 100 // ���� ���� ����

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
            return 0; //���α׷� ����
        }
        cout << "\n\n\t\t";
        system("pause");
    }
    return 0;
}
