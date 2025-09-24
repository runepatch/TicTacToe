#include <iostream>
#include "Board.h"

int main()
{
    char spaces[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
    bool running = true;
    int move = 0;
    std::string winner = "";
    bool tie;
    std::string filler;

    // Game loop
    do {
        std::cout << winner;
        if (move == 9) {
            tie = Game::determineTie(spaces);
            if (tie) {
                std::cout << "*******************************\n";
                Game::drawBoard(spaces);
                std::cout << "It's a draw!\n";
                break;
            }
        }
        // Logic to make 'O' always go first
        (move % 2 == 0) ? Game::playerOMove(spaces, move) : Game::playerXMove(spaces, move);
        winner = Game::determineWin(spaces);
        if (winner != "") {
            Game::drawBoard(spaces);
            std::cout << winner << " has won the game!\n";
            break;
        }
    } while (true);
    std::cout << "Input field so window doesn't instantly close once done: \n";
    std::cin >> filler;
    return 0;
}