#include <iostream>
#include "UI.h"
#include "Game.h"
#include "Question.h"
#include "string"
#include <SFML/Graphics.hpp>

UI::UI() {};

std::string UI::create_team() {
    /* create teams*/
    std::string team_name;
    std::cout << "Wprowadz nazwe zespolu: \n";
    std::cin >> team_name;
    return team_name;
}

void UI::main_menu_sfml() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Familiada - Menu");

    sf::Font font;
    if (!font.loadFromFile("D:/Projekty/Cpp/Famil/resources/Arial.ttf")) {
        // Obsługa błędu ładowania czcionki
        return;
    }

    sf::Text title("=== Familiada ===", font, 50);
    title.setPosition(150, 100);

    sf::Text newGame("1. Nowa Gra", font, 30);
    newGame.setPosition(150, 200);

    sf::Text exitGame("2. Wyjscie", font, 30);
    exitGame.setPosition(150, 260);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    auto data = read_questions();
                    Game game(data, create_team(), create_team());
                    game.start();  // w tym miejscu później możesz też robić osobny SFML loop dla gry
                }
                if (event.key.code == sf::Keyboard::Num2) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color(30, 30, 30));
        window.draw(title);
        window.draw(newGame);
        window.draw(exitGame);
        window.display();
    }
}

void UI::main_menu() {
    int choice = 0;
    std::cout << "=== Familiada ===\n";
    std::cout << "1. New Game\n";
    std::cout << "2. Exit\n";
    std::cin >> choice;

    if (choice == 1) {
        /* Read data with questions from json file*/
        auto data = read_questions();

        // New game
        //Game game(data, "Jedynka", "Dwojka");
        Game game(data, create_team(), create_team());
        game.start();  // Rozpoczęcie gry
    }
    else {
        std::cout << "Bye!\n";
    }
}
