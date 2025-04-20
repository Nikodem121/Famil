#include "Question.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

static void from_json(const nlohmann::json& j, Answer& a);
static void from_json(const nlohmann::json& j, Question& q);

Question::Question(const std::string& m_text, const std::vector<Answer>& m_answers) : text(m_text), answers(m_answers) {}

const std::string& Question::get_text() const
{
	return text;
}

std::vector<Answer>& Question::access_answers()
{
	return answers;
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

bool Question::all_answers_revealed() const
{
	for (auto& ans : answers)
	{
		if (!ans.revealed)
		{
			return false;
		}
	}
	return true;
}

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

std::vector<Question> read_questions() 
{
    std::ifstream file("D:\\Projekty\\Cpp\\Famil\\resources\\pytania.json");
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku resources/pytania.json!" << std::endl;
        return std::vector<Question>{};
    }

    nlohmann::json data;
    try {
        file >> data;
    }
    catch (nlohmann::json::parse_error& e) {
        std::cerr << "Blad parsowania JSON: " << e.what() << std::endl;
        return std::vector<Question>{};;
    }

    std::vector<Question> questions;
    for (const auto& item : data) {
        std::string t = item.at("text").get<std::string>();
        std::vector<Answer> a = item.at("answers").get<std::vector<Answer>>();
        questions.push_back(Question(t, a));
    }

    return questions;
}


