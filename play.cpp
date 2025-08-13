#include "play.h"

std::string Main_Player::init_name()
{
	std::string name;
	std::cout << "이 세계에 온걸 환영한다. 용사여.... \n";
	std::cout << "너의 이름이 궁금하구나... \n";
	std::cout << "이름이 무엇인가? ";
	std::cin >> name;

	std::cout << "그렇구나 " << name << " 이여.. \n";
	std::cout << name << " 너는 이제부터 긴 여정을 떠나야 한다. 각오하도록...\n";

	return name;
}
