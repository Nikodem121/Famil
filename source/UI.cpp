#include <iostream>
#include "UI.h"
#include "Game.h"
#include "Question.h"

UI::UI() {};

void UI::create_teams() {
    /* create teams*/
}

void UI::main_menu() {
    int choice = 0;
    std::cout << "=== Familiada ===\n";
    std::cout << "1. New Game\n";
    std::cout << "2. Exit\n";
    std::cin >> choice;

    if (choice == 1) {
        /* Create teams */
        create_teams();
        /* Read data with questions from json file*/
        auto data = read_questions();

        // New game
        Game game(data, "Jedynka", "Dwojka");
        game.start();  // Rozpoczęcie gry
    }
    else {
        std::cout << "Bye!\n";
    }
}
