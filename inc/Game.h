#include "Team.h"

class Game
{
	Team TeamA;
	Team TeamB;

public:
	Game(std::string name_a, std::string name_b);

	void start();
	void print_teams();

};