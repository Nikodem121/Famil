#include <iostream>
#include "Team.h"
#include "famil_types.h"

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

uint8_t Team::get_strike() const
{
	return this->strike;
}

void Team::inc_strike()
{
	this->strike++;
}

bool Team::is_max_strike() const
{
	if (this->strike >= MAX_STRIKE)
		return true;
	return false;
}
