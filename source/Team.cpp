#include <iostream>
#include "Team.h"
#include "famil_types.h"

Team::Team(std::string name) : m_team_name(name) {}

std::string Team::get_name()
{
	//std::cout << "Nazwa teamu: " << this->team_name << std::endl;
	return this->m_team_name;
}

uint16_t Team::get_points()
{
	//std::cout << "Nazwa teamu: " << this->team_name << std::endl;
	return this->m_points;
}

void Team::add_points(const uint8_t added_points)
{
	this->m_points += added_points;
}

uint8_t Team::get_strike() const
{
	return this->m_strike;
}

void Team::inc_strike()
{
	this->m_strike++;
}

bool Team::is_max_strike() const
{
	if (this->m_strike >= MAX_STRIKE)
		return true;
	return false;
}
