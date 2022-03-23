#include "play_hangman.h"
#include "../common/get_input_from_user.h"
#include "../common/rand.h"

#include <vector>
#include <random>
#include <iostream>

void play_hangman() 
{
    std::string wordToFind = get_random_word();
    std::string guessingWord;

    for (size_t i = 0; i < wordToFind.size(); ++i)
    {
        guessingWord += '_';
    }

    int numberLife = 8;

    std::cout << "Word to Find : " << wordToFind << std::endl;

    while(player_is_alive(numberLife) && !player_won(guessingWord))
    {
        show_number_of_life(numberLife);
        show_word_guessing_state(guessingWord);
        std::cout << "Choose a letter : ";
        char userLetter = get_input_from_user<char>();
        std::cout << std::endl;

        if (word_contains(wordToFind, userLetter)) {
            update_guessingWord_with_letter(guessingWord, userLetter, wordToFind);
        }
        else {
            numberLife--;
        }
    }

    if(!player_is_alive(numberLife))
    {
        show_number_of_life(numberLife);
        show_loosing_message(wordToFind);
    }
    else if(player_won(guessingWord))
    {
        show_number_of_life(numberLife);
        show_word_guessing_state(guessingWord);
        show_winning_message();
    }
}

std::string get_random_word() 
{
    std::vector<std::string> WordList = {"rectangle", "affection", "annotate", "leather", "inflame", "slow", "continent", "dagger"};
    size_t lastIndex = WordList.size()-1;
    return WordList[getRandomNumber<size_t>(0, lastIndex)];
}

void show_number_of_life (int numberLife) {
    std::cout << "Life : " << numberLife << std::endl;
}

void show_word_guessing_state(std::string guessingWord) {
    std::cout << "Word : ";
    for (auto& letter : guessingWord)
    {
        std::cout << letter << " ";
    }
    std::cout << std::endl;
}

bool word_contains(std::string word, char letter) {
    return word.find(letter) != std::string::npos;
}

void update_guessingWord_with_letter(std::string &guessingWord, char letter, std::string wordToFind)
{
    size_t index = wordToFind.find(letter); // get the first occurence of the letter
    while (index != std::string::npos)
    {
        guessingWord.replace(index, 1, 1, letter);
        index = wordToFind.find(letter, index+1); // search for other occurence of the letter
    } 
}

bool player_is_alive(int numberLife) {
    return numberLife > 0;
}

bool player_won(std::string guessingWord) {
    return guessingWord.find('_') == std::string::npos;
}

void show_winning_message() {
    std::cout << "Winner !" << std::endl;
}

void show_loosing_message(std::string wordToFind) {
    std::cout << "Looser !" << std::endl;
    std::cout << "The word was : " << wordToFind << std::endl;
}