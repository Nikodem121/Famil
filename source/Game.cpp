#include <iostream>
#include "Game.h"
#include <stdexcept>

Game::Game(const std::vector<Question> questions_m, const std::string name_a, const std::string name_b) : questions(questions_m), TeamA(name_a), TeamB(name_b)
{
	std::cout << "Witaj w klasie\n";
	print_teams();
}

void Game::start()
{
	while (!is_game_finished())
	{
		fast_draw();
		Question& q = get_next_question();
		handle_round(q);
		print_teams();
		// reset round data
	}
	std::cout << "Koniec XD\n";
}

bool Game::is_game_finished()
{
	if ((TeamA.get_points() >= MAX_TEAM_POINTS) || (TeamB.get_points() >= MAX_TEAM_POINTS))
		return true;
	return false;
	
}

Team& Game::get_currentTeam()
{
	return (m_team_turn == TeamA_Turn) ? TeamA : TeamB;
}

void Game::fast_draw()
{
	char team;
	std::cout << "Kto byl pierwszy? Team 1 / Team 2\n";
	std::cin >> team;
	m_team_turn = ('1' == team) ? TeamA_Turn : TeamB_Turn;

}


void Game::switch_team(std::vector<Answer>& answears)
{
	char decision;
	uint8_t idx = 0;
	unsigned int idx_temp = 0;

	std::cout << "Podmianka Teamow\n";
	m_team_turn = (TeamA_Turn == m_team_turn) ? TeamB_Turn : TeamA_Turn;

	std::cout << "Czy uznajesz odpowiedz n - nie, y - yes\n";
	std::cin >> decision;

	if (decision == 'n')
	{
		// do nothing
	}
	if (decision == 'y')
	{
		std::cout << "1-6 - numer odpowiedzi?\n";
		std::cin >> idx_temp;
		idx = static_cast<uint8_t>(idx_temp - 1);
		round_points += answears[idx].points;
		answears[idx].revealed = true;
	}
}

void Game::handle_guess(Team& curr_team, std::vector<Answer>& answears)
{
	uint8_t idx = 0;
	unsigned int idx_temp = 0;
	char decision;

	std::cout << "Czy uznajesz odpowiedz n - nie, y - yes\n";
	std::cin >> decision;

	if (decision == 'n')
	{
		curr_team.inc_strike();
	}
	if (decision == 'y')
	{
		std::cout << "1-6 - numer odpowiedzi?\n";
		std::cin >> idx_temp;
		idx = static_cast<uint8_t>(idx_temp - 1);
		//std::cout << "Ile pkt dostaniesz ? ? ? Tyle:" << answears[idx].points << std::endl;
		round_points += answears[idx].points;
		answears[idx].revealed = true;
	}
}
void Game::handle_round(Question& question)
{
	Team& curr_team = get_currentTeam();
	std::vector<Answer>& answears = question.access_answers();

	print_question(question); // debugging
	std::cout << "Pytanie: " << question.get_text() << std::endl;

	while ((!curr_team.is_max_strike()) && (!question.all_answers_revealed()))
	{
		handle_guess(curr_team, answears);
	}

	if (curr_team.is_max_strike())
	{
		switch_team(answears);
		// co jak nikt nie odpowie??
		// TO DO: fix point adding
	}

	if (question.all_answers_revealed())
	{
		curr_team.add_points(round_points);
	}
}

Question& Game::get_next_question()
{

	if (question_index > questions.size())
	{
		throw std::out_of_range("Brak więcej pytan\n");
	}
	return questions[question_index++];
}

const void Game::print_teams()
{
	std::cout << "Druzyna 1: " << TeamA.get_name() << std::endl;
	std::cout << "Punkty: " << TeamA.get_points() << std::endl;
	std::cout << "Druzyna 2: " << TeamB.get_name() << std::endl;
	std::cout << "Punkty: " << TeamB.get_points() << std::endl;
}

const void Game::print_question(const Question& question)
{
	/*
	for (auto& question : this->questions)
	{
		std::cout << "Pytanie: " << question.get_text() << std::endl;
		for (const auto& answer : question.get_answers())
		{
			std::cout << "Odpowiedz: " << answer.text << ", punkty: " << answer.points << std::endl;
		}
	}
	*/

	std::cout << "Pytanie: " << question.get_text() << std::endl;
	for (const auto& answer : question.get_answers())
	{
		std::cout << "Odpowiedz: " << answer.text << ", punkty: " << answer.points << std::endl;
	}
}