#include "guessTheNumber/play_guess_the_number.h"
#include "hangman/play_hangman.h"
#include "menu.h"
#include <iostream>

#include "../p6/include/p6/p6.h"

int main() {
    //getMenu();

    auto ctx = p6::Context{{1280, 720, "Noughts and Crosses"}}; // Create a window

    ctx.update = [&]() {                    // Define the function that will be called in a loop once you call ctx.start()
        ctx.background({0.5f, 0.3f, 0.8f});
        ctx.square(p6::Center{ctx.mouse()},
                   p6::Radius{0.3f});
    };
    ctx.start(); 

    return 0;
}



