#include <map>
#include <string>
#include <functional>

struct Game {
    std::string m_name;
    std::function<void()> play;
};

void getMenu();
void show_list_options(std::map<char, Game> games);
