#include "guessTheNumber/play_guess_the_number.h"
#include "hangman/play_hangman.h"
#include "common/get_input_from_user.h"
#include <iostream>

void showMenu();

int main()
{
    bool quit = false;

    while(!quit)
    {
        showMenu();
        char choice = get_input_from_user<char>();
        switch(choice)
        {
            case '1': play_guess_the_number();
                break;
            case '2': play_hangman();
                break;
            case 'q':
            case 'Q': 
                return 0;
                break;
            default: std::cout << "Sorry I don't know that command !" << std::endl;
        }
    }

}

void showMenu() {
    std::cout << "What do you want to do ?" << std::endl;
    std::cout << "1: Play 'Guess the number'" << std::endl;
    std::cout << "2: Play 'Hangman'" << std::endl;
    std::cout << "q : Quit" << std::endl;
}

