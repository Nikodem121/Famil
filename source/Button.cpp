#include "Button.h"

Button::Button(sf::Vector2f position, sf::Vector2f size, const std::string& label, sf::Font& font) {
    box.setPosition(position);
    box.setSize(size);
    box.setFillColor(sf::Color(100, 100, 255));

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    // Lekko centrowanie tekstu względem przycisku
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    text.setPosition(
        position.x + size.x / 2,
        position.y + size.y / 2
    );
}

std::string Button::getLabel() const
{
    return text.getString();
}

bool Button::isMouseOver(sf::RenderWindow& window) const {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    return box.getGlobalBounds().contains(mousePos);
}

void Button::draw(sf::RenderWindow& window) {
    if (isMouseOver(window)) {
        box.setFillColor(sf::Color(150, 150, 255));
    }
    else {
        box.setFillColor(sf::Color(100, 100, 255));
    }
    window.draw(box);
    window.draw(text);
}
