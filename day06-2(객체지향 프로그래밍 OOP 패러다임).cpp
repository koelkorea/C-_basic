// 객체지향 패러다임
//  : 현실 세상에 존재하는 사물과 대상, 그 대상의 행동을 객체로 바라보는 사고를 통해 실체화 하는 프로그래밍적 사고방향
//
//객체 : 1개 이상의 데이터(자료)와 1개 이상의 기능(메소드 : 함수)
//
//클래스(객체의 틀)
//목적에 따라 대상을 설정하고 추상적인 개념을 수치화로 정의
//수치화된 데이터의 연산을 메소드(함수)로 처리

class point {
private:
	int x, y; //x좌표, y좌표
public:
	bool init_pos(int x_pos, int y_pos);
	int get_x();
	int get_y();
	bool set_x(int x_pos);
	bool set_y(int y_pos);
};

int main() {
	point pos_1, pos_2; // 객체 생성
	point* ptr_pos_1 = new point; //동적할당

	return 0;
}
