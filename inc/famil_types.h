#pragma once
#include <iostream>

constexpr uint8_t MAX_STRIKE = 3;
constexpr uint16_t MAX_TEAM_POINTS = 300;

struct Answer {
	std::string text;
	uint16_t points;
	bool revealed = false; // have been already answeared?
};

enum TeamTurn {
	TeamA_Turn = 0u,
	TeamB_Turn = 1u
};