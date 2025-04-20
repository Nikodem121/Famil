#pragma once
#include <iostream>
#include <vector>
#include "famil_types.h"

class Question
{
	std::string text;
	std::vector<Answer> answers;

public:
	Question(const std::string& m_text, const std::vector<Answer>& m_answers);
	//Question() = default;

	const std::string& get_text() const;

	std::vector<Answer>& access_answers();
	const std::vector<Answer>& get_answers() const;

	void set_data(const std::string& m_text, const std::vector<Answer>& m_answers);

	//bool reveal_answer(const std::string& guess, int& points_out);

	bool all_answers_revealed();


};

std::vector<Question> read_questions();
