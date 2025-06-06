#pragma once
#include <iostream>

constexpr uint8_t MAX_STRIKE = 3;
constexpr uint8_t MAX_CHANCE = 0;
constexpr uint8_t LAST_CHANCE = 2;
constexpr uint16_t MAX_TEAM_POINTS = 300;
constexpr uint8_t NUM_OF_FINAL_QUESTIONS = 5;

struct Answer {
	std::string text;
	uint16_t points;
	bool revealed = false; // have been already answeared?
};

enum TeamTurn {
	teamA_Turn = 0u,
	teamB_Turn = 1u
};