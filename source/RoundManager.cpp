#include "RoundManager.h"

RoundManager::RoundManager(Question& question, Team& teamA, Team& teamB) : m_question(question), m_teamA(teamA), m_teamB(teamB), m_round_points(0), m_team_turn(teamA_Turn) {}


void RoundManager::reset_round_data()
{
	this->m_round_points = 0;
	m_teamA.reset_strike();
	m_teamB.reset_strike();
}

void RoundManager::fast_draw()
{
	char team;
	std::cout << "Kto byl pierwszy? Team 1 / Team 2\n";
	std::cin >> team;
	m_team_turn = ('1' == team) ? teamA_Turn : teamB_Turn;

}

void RoundManager::switch_team()
{
	std::cout << "Podmianka Teamow\n";
	this->m_team_turn = (teamA_Turn == m_team_turn) ? teamB_Turn : teamA_Turn;
}


Team* RoundManager::get_currentTeam()
{
	return (m_team_turn == teamA_Turn) ? &m_teamA : &m_teamB;
}


void RoundManager::start()
{
	fast_draw();
	handle_round(m_question);
	reset_round_data();
}

void RoundManager::handle_guess(Team* curr_team, std::vector<Answer>& answears)
{
	uint8_t idx = 0;
	unsigned int idx_temp = 0;
	char decision;

	std::cout << "Czy uznajesz odpowiedz n - nie, y - yes\n";
	std::cin >> decision;

	if (decision == 'n')
	{
		curr_team->inc_strike();
	}
	if (decision == 'y')
	{
		std::cout << "1-6 - numer odpowiedzi?\n";
		std::cin >> idx_temp;
		idx = static_cast<uint8_t>(idx_temp - 1);
		//std::cout << "Ile pkt dostaniesz ? ? ? Tyle:" << answears[idx].points << std::endl;
		m_round_points += answears[idx].points;
		answears[idx].revealed = true;
	}
}
void RoundManager::handle_round(Question& question)
{
	Team* curr_team = get_currentTeam();
	std::vector<Answer>& answears = question.access_answers();

	//print_question(question); // debugging
	std::cout << "Pytanie: " << question.get_text() << std::endl;

	while ((!curr_team->is_max_strike()) && (!question.all_answers_revealed()))
	{
		handle_guess(curr_team, answears);
	}

	if (question.all_answers_revealed())
	{
		curr_team->add_points(m_round_points);
	}
	else if (curr_team->is_max_strike())
	{
		switch_team();

		curr_team = get_currentTeam();
		curr_team->set_last_chance();
		handle_guess(curr_team, answears);
		if (!curr_team->is_max_strike())
		{
			curr_team->add_points(m_round_points);
		}
	}
}
