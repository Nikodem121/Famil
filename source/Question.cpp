#include "Question.h"

Question::Question(const std::string& m_text, const std::vector<Answer>& m_answers) : text(m_text), answers(m_answers) {}

const std::string& Question::get_text() const
{
	return text;
}

const std::vector<Answer>& Question::get_answers() const
{
	return answers;
}

void Question::set_data(const std::string& m_text, const std::vector<Answer>& m_answers)
{
	text = m_text;
	answers = m_answers;
}

bool Question::reveal_answer(const std::string& guess, int& points_out)
{
	return false;
}

bool Question::all_answers_revealed()
{
	return false;
}


