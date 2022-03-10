#include <iostream>

template<typename T>
T get_input_from_user() 
{
    T userInput;

    while (!(std::cin >> userInput))
    {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter." << std::endl;
    }

    return userInput;
}