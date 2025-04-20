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
	std::cout << "Kto byl pierwszy? 1." << m_teamA.get_name() << " / 2." << m_teamB.get_name()<<std::endl;
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
	handle_round();
	reset_round_data();
}

void RoundManager::handle_guess(Team* curr_team, std::vector<Answer>& answers)
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
		std::cout << "1-" << answers.size() << " - numer odpowiedzi?\n";
		std::cin >> idx_temp;
		idx = static_cast<uint8_t>(idx_temp - 1);
		//std::cout << "Ile pkt dostaniesz ? ? ? Tyle:" << answers[idx].points << std::endl;
		m_round_points += answers[idx].points;
		answers[idx].revealed = true;
	}
}
void RoundManager::handle_round()
{
	Team* curr_team = get_currentTeam();
	std::vector<Answer>& answers = m_question.access_answers();

	//print_question(question); // debugging
	std::cout << "Pytanie: " << m_question.get_text() << std::endl;

	while ((!curr_team->is_max_strike()) && (!m_question.all_answers_revealed()))
	{
		handle_guess(curr_team, answers);
	}

	if (m_question.all_answers_revealed())
	{
		curr_team->add_points(m_round_points);
	}
	else if (curr_team->is_max_strike())
	{
		switch_team();

		curr_team = get_currentTeam();
		curr_team->set_last_chance();
		handle_guess(curr_team, answers);
		if (!curr_team->is_max_strike())
		{
			curr_team->add_points(m_round_points);
		}
	}
}
