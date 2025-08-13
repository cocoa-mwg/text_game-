#pragma once
#include <iostream>
#include <string>
#include <memory>

class Main_Player;

class IPlayer {
public:
	virtual void attack(const Main_Player&) = 0;
	virtual std::string get_job(const Main_Player&) = 0;
	virtual ~IPlayer(){}
};

class Beginner : public IPlayer {
	void attack(const Main_Player&)
	{
		std::cout << "공격";
	}
	
	std::string get_job(const Main_Player&) override
	{
		return "초보자";
	}
};

class Warrior : public IPlayer {
	void attack(const Main_Player&) 
	{
		std::cout << "칼 공격";
	}

	std::string get_job(const Main_Player&) override
	{
		return "전사";
	}
};

class Wizard : public IPlayer {
	void attack(const Main_Player&) 
	{
		std::cout << "마법 공격";
	}

	std::string get_job(const Main_Player&) override
	{
		return "마법사";
	}
};


class IWeapon {
public:
	virtual int get_weapon_damege(const Main_Player&) = 0;
	virtual int get_weapon_speed(const Main_Player&) = 0;
	virtual std::string get_weapon_name(const Main_Player&) = 0;
	virtual ~IWeapon(){}
};
class OneHandSword : public IWeapon {
private:
	std::string name = "한손검";
	int damege = 50;
	int speed = 10;
	int get_weapon_damege(const Main_Player&) override { return damege; }
	int get_weapon_speed(const Main_Player&) override { return speed; }
	std::string get_weapon_name(const Main_Player&) override { return name; }
};

class TwoHandSword : public IWeapon {
private:
	std::string name = "두손검";
	int damege = 80;
	int speed = 6;
	int get_weapon_damege(const Main_Player&) override { return damege; }
	int get_weapon_speed(const Main_Player&) override { return speed; }
	std::string get_weapon_name(const Main_Player&) override { return name; }
};

class Main_Player {
private:

	std::unique_ptr<IPlayer> set_job;
	std::unique_ptr<IWeapon> set_weapon;
	std::string name;
	int hp;
	int gold;
	int damege;
	int speed;

public:
	Main_Player() : name(""), hp(100), gold(0), damege(10), speed(0), set_job(nullptr), set_weapon(nullptr) {}

	// 무기, 직업 setting code
	void set_player(std::unique_ptr<IPlayer> other) { set_job = std::move(other); }
	
	void weapon(std::unique_ptr<IWeapon> other){ set_weapon = std::move(other); }
	
	// 무기 update code
	void update_damege() { damege += set_weapon->get_weapon_damege(*this); }
	
	void update_speed() { speed += set_weapon->get_weapon_speed(*this); }

	std::string get_weapon_name() { return set_weapon->get_weapon_name(*this); }

	// 직업 setting code
	std::string get_job() { return set_job->get_job(*this); }

	void set_name(std::string _name) { name = _name; }

	void player_attack() { set_job->attack(*this); }

	std::string init_name();

};
