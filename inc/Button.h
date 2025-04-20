#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Button
{
	sf::RectangleShape box;
	sf::Text text;

public:
	Button(sf::Vector2f position, sf::Vector2f size, const std::string& label, sf::Font& font);
	std::string getLabel() const;
	bool Button::isMouseOver(sf::RenderWindow& window) const;
	void Button::draw(sf::RenderWindow& window);

};