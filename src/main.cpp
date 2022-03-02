#include "play_guess_the_number.h"

#include <string>
#include <vector>
#include <random>
#include <iostream>


std::string getRandomWord();
int getRandomIndex(int min, int max);
std::string get_char_from_user();

int main()
{
    //play_guess_the_number();

    std::string randomWord = getRandomWord();
    std::string guessingWord;

    for (size_t i = 0; i < randomWord.size(); ++i)
    {
        guessingWord += '-';
    }

    int numberLife = 8;
    std::string userLetter;
    bool endGame = false;

    std::cout << "Mot a trouver : " << randomWord << std::endl;

    while(!endGame)
    {
        std::cout << "Vie : " << numberLife << std::endl;
        std::cout << "Mot : " << guessingWord << std::endl;
        std::cout << "Choisis une lettre :" << std::endl;
        userLetter = get_char_from_user();

        // try to get the first occurence of the letter
        size_t found = randomWord.find(userLetter);

        if (found == std::string::npos) // if their isn't the letter
        {
            numberLife--;
            if(numberLife == 0)
            {
                endGame = true;
                std::cout << "Vie : " << numberLife << std::endl;
                std::cout << "Looser !" << std::endl;
                std::cout << "Le mot etait : " << randomWord << std::endl;
            }
        }
        else // replace each occurence of the letter
        {
            do 
            {
                guessingWord.replace(found, 1, userLetter);
                found = randomWord.find(userLetter, found+1); // search for other occurence of the letter
            } while (found != std::string::npos);
            
            if(guessingWord.find('-') == std::string::npos)
            {
                endGame = true;
                std::cout << "Vie : " << numberLife << std::endl;
                std::cout << "Mot : " << guessingWord << std::endl;
                std::cout << "Winner !" << std::endl;
            }
        }
    }
}

std::string getRandomWord()
{
    std::vector<std::string> WordList = {"rectangle", "affection", "annoter", "cuir", "enflammer", "lent", "continent", "poignard"};
    int lastIndex = static_cast<int>(WordList.size()-1);
    return WordList[getRandomIndex(0, lastIndex)];
}


int getRandomIndex(int min, int max)
{
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

std::string get_char_from_user()
{
    std::string userLetter;
    std::cin >> userLetter;

    return userLetter;
}
