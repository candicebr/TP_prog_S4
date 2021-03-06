#include "play_guess_the_number.h"
#include "../common/get_input_from_user.h"
#include "../common/rand.h"

#include <iostream>
#include <random>

void play_guess_the_number() 
{
    const int min = 0;
    const int max = 100;
    const int randomNumber = getRandomNumber<int>(min, max);

    //std::cout << randomNumber << std::endl;

    std::cout << "Picked a number between " << min << " and " << max << std::endl;
    int userNumber = get_input_from_user<int>();

    while (userNumber != randomNumber)
    {
        if (userNumber < randomNumber)
        {
            std::cout << "Greater" << std::endl;
        }
        else if (userNumber > randomNumber)
        {
            std::cout << "Smaller" << std::endl;  
        }

        userNumber = get_input_from_user<int>();    
    }

    std::cout << "Congrats, you won !" << std::endl;
}

