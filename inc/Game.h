#include "Team.h"
#include "famil_types.h"
#include "Question.h"

class Game
{
	Team TeamA;
	Team TeamB;

	TeamTurn currentTeam = TeamA_Turn;

	std::vector<Question> questions;

public:
	Game(const std::vector<Question> questions_m, std::string name_a, std::string name_b);

	void start();
	void print_teams();
	
	void handle_guess(const std::string& guess);
	void next_question();

	Team& get_currentTeam();
};