#include <string>

class Team {
private:
	const std::string m_team_name;
	uint16_t m_points;
	uint8_t m_strike;


public:
	Team(std::string name);

	const std::string& Team::get_name() const;

	uint16_t get_points();
	void add_points(const uint8_t added_points);

	uint8_t get_strike() const;
	bool is_max_strike() const;
	void inc_strike();
	void reset_strike();
	void set_last_chance();
};
