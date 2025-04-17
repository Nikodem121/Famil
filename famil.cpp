#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "Game.h"

using json = nlohmann::json;

void from_json(const nlohmann::json& j, Answer& a) {
	j.at("text").get_to(a.text);
	j.at("points").get_to(a.points);
	a.revealed = false;  // zawsze false przy wczytaniu
}

void from_json(const nlohmann::json& j, Question& q) {
	std::string t = j.at("text").get<std::string>();
	std::vector<Answer> a = j.at("answers").get<std::vector<Answer>>();

	q.set_data(t, a);
}


auto read_question()
{
	std::ifstream file("D:\\Projekty\\Cpp\\Famil\\resources\\pytania.json");
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku resources/pytania.json!" << std::endl;
		return std::vector<Question>{};
	}

	json data;
	try {
		file >> data;
	}
	catch (json::parse_error& e) {
		std::cerr << "Blad parsowania JSON: " << e.what() << std::endl;
	}

	return data.get<std::vector<Question>>();

	/*
	for (const auto& question : data)
	{
		std::cout << "Pytanie: " << question["text"] << std::endl;
		for (const auto& answer : question["answers"])
		{
			std::cout << "Odpowiedz: " << answer["text"] << ", punkty: " << answer["points"] << std::endl;
		}
	}
	*/
}

void create_teams() {

}

/* */
void famil()
{
	/* Read data with questions from json file*/
	
	auto data = read_question();
	//create_teams();

	Game game(data, "Jedynka", "Dwojka");

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