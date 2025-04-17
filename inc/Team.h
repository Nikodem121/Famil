class Team {
private:
	const std::string m_team_name;
	uint16_t m_points = 0;
	uint8_t m_strike = 0;


public:
	Team(std::string name);

	std::string get_name();

	uint16_t get_points();
	void add_points(const uint8_t added_points);

	uint8_t get_strike() const;
	bool is_max_strike() const;
	void inc_strike();
};
