#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "Game.h"

using json = nlohmann::json;

void read_question()
{
	std::ifstream f("pytania.json");
	json data = json::parse(f);

	for (const auto& question : data)
	{
		std::cout << "Pytanie: " << question["text"] << std::endl;
		for (const auto& answer : question["answers"])
		{
			std::cout << "Odpowiedz: " << answer["text"] << ", punkty: " << answer["points"] << std::endl;
		}
	}
}

void create_teams() {

}

/* */
void famil()
{
	/* Read data with questions from json file*/
	
	//read_question();
	
	//create_teams();

	Game game("Kapki", "Smiecie");

	game.start();
	game.print_teams();

	/*
	while (!game.is_over())
	{
		game.next_question();
	}
	*/

}

int main()
{
	std::cout << "Hej\n";
	/* Run Familiada */
	famil();

	return 0;
}