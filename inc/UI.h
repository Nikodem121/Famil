#pragma once
#include "Button.h"

class UI
{
	std::vector<Button> buttons;
public:
	UI();
	std::string create_team();
	void main_menu();
	void main_menu_sfml();
	void add_button(const Button& b);
	void clear_buttons();
	void draw(sf::RenderWindow& win);

};

