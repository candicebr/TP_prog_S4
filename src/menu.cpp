#include "menu.h"
#include "hangman/play_hangman.h"
#include "guessTheNumber/play_guess_the_number.h"
#include "common/get_input_from_user.h"

void getMenu() {

    // map command with game
    std::map<char, Game> games {
        {'1', {
            /*.m_name =*/ "Guess The Number", 
            /*.play =*/ &play_guess_the_number}},
        {'2', {
            /*.m_name =*/ "Hangman", 
            /*.play =*/ &play_hangman}},
    };

    bool quit = false;

    while(!quit)
    {
        show_list_options(games);
        char choice = get_input_from_user<char>();

        if (choice == 'q' || choice == 'Q') {
            quit = true;
        }
        else {
            const auto  gameToPlay = games.find(choice);
            if (gameToPlay != games.end()) {
                gameToPlay->second.play();
            }
            else {
                std::cout << "Sorry I don't know that command !" << std::endl;
            }
        }  
    }
}

void show_list_options(std::map<char, Game> games) {
    std::cout << "What do you want to do ?" << std::endl;

    for (const auto& option : games)
    {
        std::cout << option.first << ": Play '" << option.second.m_name << "'" << std::endl;
    }
    std::cout << "q : Quit" << std::endl;
}