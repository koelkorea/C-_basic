//String(문자열) 입력

//C style
// : char 자료형 배열 사용한 문자열 입력(= 기본적으로는 정적할당)
//char name[15];
//cin >> name; // 공백문자 전까지 14(+'\0')개 저장 가능. [ 큐에 '\n' 남김 ]
//while (cin.get() != '\n');
//cin.get(name, 15); // 1행 입력 받기 [ 큐에 '\n' 남김 ]
//cin.getline(name, 15); // 1행 입력 받기 [ '\n'(Enter) 버림 ]
//cin.getline(name, 15, ':'); // 1행 입력 받기 [ ':' 버림 ]

//C++ style
// : string class를 통한 문자열 입력 (= 동적할당)
// 
//입력 받은 문자열 자동 크기 조절
//string fullname;
//cin >> fullname; // 공백문자 전까지 저장 가능. [ 큐에 '\n' 남김 ]
//while (cin.get() != '\n');
//getline(cin, fullname); // 1행 입력 받기 [ '\n'(Enter) 버림 ]
//getline(cin, fullname, ':'); // 1행 입력 받기 [ ':' 버림 ]

//제한 요소 : unsigned __int64(2 ^ 64)저장 가능한 문자열 개수, 메모리 크기
