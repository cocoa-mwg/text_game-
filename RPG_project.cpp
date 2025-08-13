#include "play.h"

int main()
{
	
	Main_Player player;
	player.set_name(player.init_name());
	player.set_player(std::make_unique<Warrior>());
	player.weapon(std::make_unique<OneHandSword>());
	player.player_attack();
	std::cout << "\n" << player.get_job() << std::endl;
	std::cout << player.get_weapon_name() << std::endl;

}
