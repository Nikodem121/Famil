﻿#include <iostream>
#include "Game.h"
#include <stdexcept>

Game::Game(std::vector<Question>& questions, const std::string& name_a, const std::string& name_b) : m_questions(questions), m_teamA(name_a), m_teamB(name_b)
{
	std::cout << "Witaj w klasie\n";
	print_teams();
}

void Game::start()
{
	while (!is_1_stage_finished())
	{
		Question& q = get_next_question();
		RoundManager round(q, m_teamA, m_teamB);
		round.start();
		print_teams();
	}
	final_stage();
	std::cout << "Koniec XD\n";
}

bool Game::is_1_stage_finished()
{
	if ((m_teamA.get_points() >= MAX_TEAM_POINTS) || (m_teamB.get_points() >= MAX_TEAM_POINTS))
		return true;
	return false;
	
}

void Game::final_stage()
{
	for (uint8_t i = 0; i < NUM_OF_FINAL_QUESTIONS; i++)
	{
		Question& q = get_next_question();
		// to do

	}
}

Question& Game::get_next_question()
{

	if (question_index >= m_questions.size())
	{
		throw std::out_of_range("Brak więcej pytan\n");
	}
	return m_questions[question_index++];
}

void Game::print_teams()
{
	std::cout << "Druzyna 1: " << m_teamA.get_name() << std::endl;
	std::cout << "Punkty: " << m_teamA.get_points() << std::endl;
	std::cout << "Druzyna 2: " << m_teamB.get_name() << std::endl;
	std::cout << "Punkty: " << m_teamB.get_points() << std::endl;
}

void Game::print_question(const Question& question) const
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
