class Team {
private:
	const std::string team_name;
	uint16_t points = 0;
	uint8_t strike = 0;


public:
	Team(std::string name);

	std::string get_name();
	uint16_t get_points();

	uint8_t get_strike() const;
	void inc_strike();
	bool is_max_strike() const;
};
