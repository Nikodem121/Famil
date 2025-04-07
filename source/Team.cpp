#include <iostream>
#include "Team.h"

Team::Team(std::string name) : team_name(name) {}

std::string Team::get_name()
{
	//std::cout << "Nazwa teamu: " << this->team_name << std::endl;
	return this->team_name;
}

uint16_t Team::get_points()
{
	//std::cout << "Nazwa teamu: " << this->team_name << std::endl;
	return this->points;
}
