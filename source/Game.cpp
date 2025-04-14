#include <iostream>
#include "Game.h"

Game::Game(const std::vector<Question> questions_m, const std::string name_a, const std::string name_b) : questions(questions_m), TeamA(name_a), TeamB(name_b)
{
	std::cout << "Witaj w klasie\n";
	print_teams();
}

void Game::start()
{
	next_question();
}

void Game::print_teams()
{
	std::cout << "Druzyna 1: " << TeamA.get_name() << std::endl;
	std::cout << "Punkty: " << TeamA.get_points() << std::endl;
	std::cout << "Druzyna 2: " << TeamB.get_name() << std::endl;
	std::cout << "Punkty: " << TeamB.get_points() << std::endl;

}

Team& Game::get_currentTeam()
{
	return (currentTeam == TeamA_Turn) ? TeamA : TeamB;
}

void Game::handle_guess(const std::string& guess)
{
	// czy drużyna odpowiedziała poprawnie?
	std::cout << "Czy uznajesz odpowiedz n - nie, 1-6 - numer odpowiedzi?/n";

	Team& curr_team = get_currentTeam();

	while (curr_team.is_max_strike())
	{
		char decision;
		std::cin >> decision;

		if (decision == 'n')
		{
			curr_team.inc_strike();
		}
	}
	


}

void Game::next_question()
{
	for (auto& question : this->questions)
	{
		std::cout << "Pytanie: " << question.get_text() << std::endl;
		for (const auto& answer : question.get_answers())
		{
			std::cout << "Odpowiedz: " << answer.text << ", punkty: " << answer.points << std::endl;
		}
	}
}