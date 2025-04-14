#pragma once
#include <iostream>

constexpr uint8_t MAX_STRIKE = 3;

struct Answer {
	std::string text;
	int points;
	bool revealed = false; // have been already answeared?
};

enum TeamTurn {
	TeamA_Turn = 0u,
	TeamB_Turn = 1u
};