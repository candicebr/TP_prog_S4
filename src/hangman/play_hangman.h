#include <string>

void play_hangman();
std::string get_random_word();
void show_number_of_life(int numberLife);
void show_word_guessing_state(std::string guessingWord);
bool word_contains(std::string word, char letter);
void update_guessingWord_with_letter(std::string &guessingWord, char letter, std::string wordToFind);
bool player_is_alive(int numberLife);
bool player_won(std::string guessingWord);
void show_winning_message();
void show_loosing_message(std::string wordToFind);