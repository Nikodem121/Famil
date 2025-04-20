#pragma once

#include "famil_types.h"
#include "RoundManager.h"

class Game
{
	Team m_teamA;
	Team m_teamB;

	std::vector<Question>& m_questions;

	uint8_t question_index = 0;

public:
	Game(std::vector<Question>& questions, const std::string& name_a, const std::string& name_b);

	void start();
	bool is_1_stage_finished();
	void final_stage();

	Question& get_next_question();


	void print_teams();
	void print_question(const Question& question) const; // debuging purpose
};