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

void UI::add_button(const Button& b) 
{ 
    buttons.push_back(b); 
}

void UI::clear_buttons()
{
    buttons.clear(); 
}
void UI::draw(sf::RenderWindow& win)
{
    for (auto& btn : buttons) btn.draw(win);
}

void UI::main_menu_sfml() {
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Familiada - Menu");
    sf::RenderWindow window(sf::VideoMode(1024,1024), "Familiada - Menu");
    sf::Font font;

    if (!font.loadFromFile("D:/Projekty/Cpp/Famil/resources/Arial.ttf")) {
        std::cout << "Blad ladowania czcionki!" << std::endl;
        return;
    }

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("D:/Projekty/Cpp/Famil/resources/background.png")) {
        std::cout << "Nie udalo sie zaladowac tla!\n";
    }
    sf::Sprite background(backgroundTexture);

    //Button newGameBtn({ 400, 250 }, { 300, 50 }, "Nowa Gra", font);
    //Button exitGameBtn({ 400, 330 }, { 300, 50 }, "Wyjscie", font);

    add_button(Button({ 400,250 }, { 300,50 }, "Nowa Gra", font));
    add_button(Button({ 400,330 }, { 300,50 }, "Wyjście", font));

    while (window.isOpen()) {
        sf::Event event;
        window.clear();
        window.draw(background);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                for (auto& btn : buttons) {
                    if (btn.isMouseOver(window)) {
                        std::string label = btn.getLabel();

                        if (label == "Nowa Gra") {
                            std::cout << "Start gry!" << std::endl;
                            std::vector<Question> data = read_questions();
                            clear_buttons();
                            Game game(data, create_team(), create_team());
                            game.start();
                            window.close();
                        }
                        if (label == "Wyjscie") {
                            std::cout << "Wyjscie z gry!" << std::endl;
                            window.close();
                        }
                    }
                }
            }
        }

        for (auto& btn : buttons) {
            btn.draw(window);
        }

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
