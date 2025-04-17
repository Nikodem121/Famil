#include "Team.h"
#include "famil_types.h"
#include "Question.h"

class Game
{
	Team TeamA;
	Team TeamB;

	TeamTurn m_team_turn = TeamA_Turn;

	std::vector<Question> questions;

	uint16_t round_points = 0;
	uint8_t question_index = 0;

public:
	Game(const std::vector<Question> questions_m, std::string name_a, std::string name_b);

	void start();
	bool is_game_finished();
	
	void fast_draw();
    void handle_round(Question& question);
    void handle_guess(Team& curr_team, std::vector<Answer>& answears);
	Question& get_next_question();
	
	void switch_team(std::vector<Answer>& answears);
	Team& get_currentTeam();

	const void print_teams();
	const void print_question(const Question& question); // debuging purpose
};