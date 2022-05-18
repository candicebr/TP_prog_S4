#include "guessTheNumber/play_guess_the_number.h"
#include "hangman/play_hangman.h"
#include "menu.h"
#include <iostream>

#include "../p6/include/p6/p6.h"

void draw_board(int size, p6::Context& ctx);

int main() {
    //getMenu();

    const int window_width = 1200;
    const int window_height = 1200;
    auto ctx = p6::Context{{window_width, window_height, "Noughts and Crosses"}}; // Create a window

    ctx.update = [&]() {                    // Define the function that will be called in a loop once you call ctx.start()
        ctx.background({0.5f, 0.3f, 0.8f});
        ctx.use_stroke = true;
        ctx.stroke_weight = 0.01f;
        ctx.stroke = {1.f, 1.f, 1.f};
        ctx.fill = {0.5f, 0.7f, 0.7f};

        draw_board(3, ctx);
    };
    ctx.start(); 

    return 0;
}

void draw_board(int size, p6::Context& ctx)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{static_cast<float>(i), static_cast<float>(j)},
                                                    glm::vec2{0.f}, glm::vec2{static_cast<float>(size)},
                                                    glm::vec2{-1.f}, glm::vec2{1.f})},
                       p6::Radius{1.f / static_cast<float>(size)});
        }
    }
}



