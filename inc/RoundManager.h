#pragma once
#include "Team.h"
#include "Question.h"

class RoundManager
{
    uint16_t m_round_points;
    TeamTurn m_team_turn;
    Question& m_question;
    Team& m_teamA;
    Team& m_teamB;
public:
    RoundManager(Question& question, Team& teamA, Team& teamB);
    void start();
    void fast_draw();
    void switch_team();
    void reset_round_data();
    Team* get_currentTeam();
    void handle_round(Question& question);
    void handle_guess(Team* curr_team, std::vector<Answer>& answears);
};

