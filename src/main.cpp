#include "guessTheNumber/play_guess_the_number.h"
#include "hangman/play_hangman.h"
#include "menu.h"
#include <iostream>
#include <vector>

#include "../p6/include/p6/p6.h"

struct Cell {
    int index_x;
    int index_y;
};

std::vector<Cell> make_cells(int size);
void draw_board(std::vector<Cell> cells, int size, p6::Context& ctx);
void draw_cell(Cell cell, int size, p6::Context& ctx);
std::optional<Cell> hovered_cell(glm::vec2 mouse_pos, int size);

int main() {
    //getMenu();

    const int window_width = 1200;
    const int window_height = 1200;
    auto ctx = p6::Context{{window_width, window_height, "Noughts and Crosses"}}; // Create a window
    const int board_size = 3;
    std::vector<Cell> cells = make_cells(board_size);

    ctx.update = [&]() {                    // Define the function that will be called in a loop once you call ctx.start()
        ctx.background({0.1f, 0.4f, 0.4f});
        ctx.use_stroke = true;
        ctx.stroke_weight = 0.01f;
        ctx.stroke = {1.f, 1.f, 1.f};
        ctx.fill = {0.5f, 0.7f, 0.7f};

        draw_board(cells, board_size, ctx);

        // test hover
        auto cellHovered = hovered_cell(ctx.mouse(), board_size);
        if(cellHovered.has_value())
            std::cout << cellHovered.value().index_x << " " << cellHovered.value().index_y << std::endl;
        else
            std::cout << "no cell under the mouse" << std::endl;

    };
    ctx.start(); 

    return 0;
}

std::vector<Cell> make_cells(int size)
{
    std::vector<Cell> cells;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cells.push_back(Cell{i,j});
        }
    }
    return cells;
}

void draw_board(std::vector<Cell> cells, int size, p6::Context& ctx)
{
    for (const auto& cell : cells) {
        draw_cell(cell, size, ctx);
    }
}

void draw_cell(Cell cell, int size, p6::Context& ctx)
{
    ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{static_cast<float>(cell.index_x), static_cast<float>(cell.index_y)},
                                                    glm::vec2{0.f}, glm::vec2{static_cast<float>(size)},
                                                    glm::vec2{-1.f}, glm::vec2{1.f})},
                       p6::Radius{1.f / static_cast<float>(size)});
}

std::optional<Cell> hovered_cell(glm::vec2 mouse_pos, int size)
{
   
    const auto position = p6::map(mouse_pos,
                             glm::vec2{-1.f}, glm::vec2{1.f},
                             glm::vec2{0.f}, glm::vec2{static_cast<float>(size)});

    const auto cell = Cell{
        static_cast<int>(std::floor(position.x)),
        static_cast<int>(std::floor(position.y))};

    // if there is a cell under the mouse
    if (cell.index_x >= 0 && cell.index_x < size && cell.index_y >= 0 && cell.index_y < size) {
        return std::make_optional(cell);
    }

    return std::nullopt;
}




