#include <iostream>
#include "Team.h"
#include "famil_types.h"

Team::Team(std::string name) : m_team_name(name) { m_points = 0; m_strike = 0; }

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

void Team::set_last_chance()
{
	this->m_strike = LAST_CHANCE;
}

void Team::reset_strike()
{
	this->m_strike = MAX_CHANCE;
}

bool Team::is_max_strike() const
{
	if (this->m_strike >= MAX_STRIKE)
		return true;
	return false;
}
