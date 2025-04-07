class Team {
private:
	const std::string team_name;
	uint16_t points = 0;

public:
	Team(std::string name);

	std::string get_name();
	uint16_t get_points();
};
