//  - �����ͺ��� ���ȭ
//     : �����ͺ����� ������ Ư�� �ڷ����� �����Ͱ� ����� ��ġ �ּҳ� �̸� ������ ���� ������ �� ������, ���� ������ �����ϴ� ������ ������ ��ġ�ϴ� ��
//        -> (�߿�) const�� �����ͺ��� �տ� ���̳�? �ڿ� ���̳�?�� ���� �ǹ̰� �޶���
// 
//        1. const�� �ڷ��� �տ� ���� (const �ڷ���* �����ͺ����� = �ּҰ�; )
//             : �����Ϳ� ��ϵ� �ּҰ��� ��ġ�� �������� ������ �������Ͽ� �������� ��, �ʱ�ȭ ���� ������ �� ���� ����� �����ϰڴٴ� �ǹ�
//               (= ���ȭ �� ������ ���� �������� �ʰ�, �������� �ּҰ��� ���� ������������ �����Ͽ� �Ϲݻ���� �����ߴٰ� �����ϸ� ����)
//                  -> ��! �������� ���� ������ ������ != �ش� ������ ���� �����Ͽ� ������ ������
// 
//               # �����ͺ��� �������� �Ϲݺ��� ���ȭ ǥ��� (const �ڷ��� ������ = �� ������)
//                  : const �ڷ���* �����ͺ����� = �ּҰ�; 
// 	             
//                    ex) int const_int = 91;
//                        const int* const_p1 = &const_int;      <- *const_p1�� ���ȭ = const_int�� ���ȭ = �����ͺ����� ���� �Ϲݺ��� ���ȭ�� �� �Ͱ� ����
//                        (x) *const_p1 = 1; 
// 
//               # const �ڷ���* �����ͺ����� = �ּҰ�;  VS  const �ڷ��� ������ = ��
//                  -> (������) �� �� Ư�� ������ �ʱⰪ ���� ���� �Ұ��� �ϵ��� ������ٴ� ��
//                     (������) �� �� �ϳ��� ��� Ư�� ������ ���ȭ���״ٰ�, ���� �����̳� ������ ������ �Ѳ����� �� �������� ����
//                               -> �� ����� ���� ������ ���� ���� ������, �Ϲݺ����� �����ͳ� �� ���ȭ�ؼ� ����������� 
// 
//        2. const�� �ڷ��� �ڿ� ���� (�ڷ���* const �����ͺ����� = �ּҰ�; )
//             : �����Ϳ� ��ϵ� �ּҰ� ��ü�� �ʱ�ȭ ���� ������ �� ���� ����� �����ϰڴٴ� �ǹ�
// 
//               # �����ͺ��� ���ȭ ǥ���
//                  : �ڷ���* const �����ͺ����� = �ּҰ�; )
// 	             
//                    ex) int const_int = 91;
//                        int* const const_p1 = &const_int;      <- const_p1�� ����� const_int �ּҰ� ���� �Ұ���
//                        (x) const_p1 = &another_int; 
//
//        3. const�� �ڷ��� ��, �ڿ� ���� (const �ڷ���* const �����ͺ����� = �ּҰ�; )
//             : 1, 2�� Ư�� ��θ� �����Ѵٴ� �ǹ� (= ??? : �����Ϳ� ����� �ּҰ��� ����������, �װ� �������� �� ������ ������!)
// 
//               # �����ͺ��� ��ü�� �� ������������ ���ȭ ǥ���
//                  : const �ڷ���* const �����ͺ����� = �ּҰ�; )
// 	             
//                    ex) int const_int = 91;
//                        const int* const const_p1 = &const_int;      <- const_p1�� ����� const_int �ּҰ� ���� �Ұ��� + �������� *const_p1�� �� ���� �Ұ���
//                        (x) const_p1 = &another_int; 
//                        (x) *const_p1 = 1; 

// �����ͺ����� ���ȭ ���� �ڵ�
int main() {

    int a = 5, b = 10, c = 15, dummy = 0;

    // 1. const�� �ڷ��� �տ� ����
    //  : �����Ϳ� ��ϵ� �ּҰ��� ��ġ�� �������� ������ �������Ͽ� �������� ��, �ʱ�ȭ ���� ������ �� ���� ����� �����ϰڴٴ� �ǹ�
    //     -> ��! �׷��ٰ� ���� a�� ���� ������ ���� �������� �������� ����
    const int* p1 = &a;

    // [p1�� �Ұ����� ��]
    //  -> �������� ���� �� ������ �Ұ���!
    *p1 = 60; 

    // [p1�� ������ ��]
    //  -> p1�� ������ �ּҰ� ����
    p1 = &dummy;

    // �̰� �׳� ������ ������ (�����ͺ��� ���ȭ�� �ƹ� ��� ����)
    a = 100;

    // 2. const�� �ڷ��� �ڿ� ���� 
    //  : �����Ϳ� ��ϵ� �ּҰ� ��ü�� �ʱ�ȭ ���� ������ �� ���� ����� �����ϰڴٴ� �ǹ�
    int* const p2 = &b;

    // [p2�� �Ұ����� ��]
    //  -> p2�� ������ �ּҰ� ����
    p2 = &dummy;

    // [p1�� ������ ��]
     //  -> �������� ���� �� ������ ����!
    *p2 = 60;

    // 3. const�� �ڷ��� ��, �ڿ� ����
    //  : �����Ϳ� ����� �ּҰ��� &c�� ����������, �װ� �������� ���� c�� �� 15�� ������ ����
    const int* const p3 = &c;

    // [p3�� �Ұ����� �� = ������ ����, �ּҰ� ���� ���� �Ұ���]
    p3 = &a; //error
    *p3 = 60; //error

    return 0;
}