#pragma once

#include "famil_types.h"
#include "RoundManager.h"

class Game
{
	Team teamA;
	Team teamB;

	std::vector<Question> m_questions;

	uint8_t question_index = 0;

public:
	Game(const std::vector<Question> questions_m, std::string name_a, std::string name_b);

	void start();
	bool is_game_finished();
	void final_stage();

	Question& get_next_question();


	const void print_teams();
	const void print_question(const Question& question); // debuging purpose
};