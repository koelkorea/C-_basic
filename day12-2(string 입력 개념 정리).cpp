//String(���ڿ�) �Է�

//C style
// : char �ڷ��� �迭 ����� ���ڿ� �Է�(= �⺻�����δ� �����Ҵ�)
//char name[15];
//cin >> name; // ���鹮�� ������ 14(+'\0')�� ���� ����. [ ť�� '\n' ���� ]
//while (cin.get() != '\n');
//cin.get(name, 15); // 1�� �Է� �ޱ� [ ť�� '\n' ���� ]
//cin.getline(name, 15); // 1�� �Է� �ޱ� [ '\n'(Enter) ���� ]
//cin.getline(name, 15, ':'); // 1�� �Է� �ޱ� [ ':' ���� ]

//C++ style
// : string class�� ���� ���ڿ� �Է� (= �����Ҵ�)
// 
//�Է� ���� ���ڿ� �ڵ� ũ�� ����
//string fullname;
//cin >> fullname; // ���鹮�� ������ ���� ����. [ ť�� '\n' ���� ]
//while (cin.get() != '\n');
//getline(cin, fullname); // 1�� �Է� �ޱ� [ '\n'(Enter) ���� ]
//getline(cin, fullname, ':'); // 1�� �Է� �ޱ� [ ':' ���� ]

//���� ��� : unsigned __int64(2 ^ 64)���� ������ ���ڿ� ����, �޸� ũ��
