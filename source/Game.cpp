#include <iostream>
#include "Game.h"

Game::Game(const std::string name_a, const std::string name_b) : TeamA(name_a), TeamB(name_b)
{
	//std::cout << "Witaj w klasie\n";
}

void Game::start()
{

}

void Game::print_teams()
{
	std::cout << "Druzyna 1: " << TeamA.get_name() << std::endl;
	std::cout << "Punkty: " << TeamA.get_points() << std::endl;
	std::cout << "Druzyna 2: " << TeamB.get_name() << std::endl;
	std::cout << "Punkty: " << TeamB.get_points() << std::endl;

}