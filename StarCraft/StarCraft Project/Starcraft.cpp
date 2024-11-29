#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
/*
class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;
public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(const Photon_Cannon& pc);

	void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	cout << "복사 생성자 호출! \n";
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
	cout << "생성자 호출! \n";
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}
void Photon_Cannon::show_status() {
	cout << "Photon Cannon \n";
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) \n";
	cout << " HP : " << hp << '\n';
}
*/

class Marine {
	static int total_marine_num;
	const static int i = 0;

	int hp;							// 마린 체력
	int coord_x, coord_y;			// 마린 위치
	bool is_dead;

	const int default_damage;

public:
	Marine();						// 생성자
	Marine(int x, int y);			// x, y 좌표에 마린 생성
	Marine(int x, int y, int default_damage);

	int attack() const;			// 데미지를 리턴
	Marine& be_attacked(int damage_earn);	//입는 데미지
	void move(int x, int y);				// 새로운 위치

	void show_status();						// 상태를 보여준다.
	static void show_total_marine();
	~Marine() { total_marine_num--; }
	
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
	cout << "전체 마린 수 : " << total_marine_num << '\n';
}

Marine::Marine()
	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}
Marine::Marine(int x, int y) 
	: hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {
	total_marine_num++;
}
Marine::Marine(int x, int y, int default_damage)
	: hp(50), 
	coord_x(x), coord_y(y), 
	default_damage(default_damage), 
	is_dead(false) {
	total_marine_num++;
}
void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() const { return default_damage; }

Marine& Marine::be_attacked(int damage_earn){
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;

	return *this;
}
void Marine::show_status() {
	cout << " *** Marine ***\n";
	cout << " Location : ( " << coord_x << ", " << coord_y << ") \n";
	cout << " HP : " << hp << '\n';
	cout << " 현재 총 마린 수 : " << total_marine_num << '\n';
}


int main() {
	
	Marine marine1(2, 3, 5);
	marine1.show_status();
	
	Marine marine2(3, 5, 10);
	marine2.show_status();

	cout << '\n' << "마린 1이 마린 2를 두 번 공격! " << '\n';
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

	return 0;
}