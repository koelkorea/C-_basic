// ��ü���� �з�����
//  : ���� ���� �����ϴ� �繰�� ���, �� ����� �ൿ�� ��ü�� �ٶ󺸴� ��� ���� ��üȭ �ϴ� ���α׷����� ������
//
//��ü : 1�� �̻��� ������(�ڷ�)�� 1�� �̻��� ���(�޼ҵ� : �Լ�)
//
//Ŭ����(��ü�� Ʋ)
//������ ���� ����� �����ϰ� �߻����� ������ ��ġȭ�� ����
//��ġȭ�� �������� ������ �޼ҵ�(�Լ�)�� ó��

class point {
private:
	int x, y; //x��ǥ, y��ǥ
public:
	bool init_pos(int x_pos, int y_pos);
	int get_x();
	int get_y();
	bool set_x(int x_pos);
	bool set_y(int y_pos);
};

int main() {
	point pos_1, pos_2; // ��ü ����
	point* ptr_pos_1 = new point; //�����Ҵ�

	return 0;
}
