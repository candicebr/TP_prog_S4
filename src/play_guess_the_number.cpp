#include "play_guess_the_number.h"

#include <iostream>
#include <random>

void play_guess_the_number() 
{
    int userNumber;
    int min;
    int max;
    int randomNumber;

    min = 0;
    max = 100;
    randomNumber = getRandomNumber(min, max);

    //std::cout << randomNumber << std::endl;

    std::cout << "Picked a number between " << min << " and " << max << std::endl;
    userNumber = get_int_from_user();

    while (userNumber != randomNumber)
    {
        if (userNumber < randomNumber)
            std::cout << "Greater" << std::endl;
        else if (userNumber > randomNumber)
            std::cout << "Smaller" << std::endl;  

        userNumber = get_int_from_user();    
    }

    std::cout << "Congrats, you won !" << std::endl;
}

int getRandomNumber(int min, int max)
{
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

int get_int_from_user()
{
    int userNumber;

    while (!(std::cin >> userNumber))
    {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter." << std::endl;
    }

    return userNumber;
}

