#include <iostream>
#include "Board.h"

void Game::drawBoard(char* spaces) {
    std::cout << "  " << spaces[0] << "  " << "|  " << spaces[1] << "  |  " << spaces[2] << " \n";
    std::cout << "-----------------\n";
    std::cout << "  " << spaces[3] << "  " << "|  " << spaces[4] << "  |  " << spaces[5] << " \n";
    std::cout << "-----------------\n";
    std::cout << "  " << spaces[6] << "  " << "|  " << spaces[7] << "  |  " << spaces[8] << " \n";
}
void Game::playerOMove(char* spaces, int& turn) {
    int choice;
    do {
        Game::drawBoard(spaces);
        std::cout << "Player O's turn!\n";
        std::cout << "Choose an available spot to place your marker (1-9): \n";
        std::cin >> choice;
        if (spaces[choice - 1] == ' ') {
            spaces[choice - 1] = 'O';
            std::cout << "*******************************\n\n";
            std::cout << "Placed a " << 'O' << " at spot #" << choice << '\n';
            turn++;
            break;
        }
        else {
            std::cout << "That spot isn't available! Try another spot.\n";
        }
    } while (true);
}
void Game::playerXMove(char* spaces, int& turn) {
    int choice;
    do {
        Game::drawBoard(spaces);
        std::cout << "Player X's turn!\n";
        std::cout << "Choose an available spot to place your marker (1-9): \n";
        std::cin >> choice;
        if (spaces[choice - 1] == ' ') {
            spaces[choice - 1] = 'X';
            std::cout << "*******************************\n\n";
            std::cout << "Placed a " << 'X' << " at spot #" << choice << '\n';
            turn++;
            break;
        }
        else {
            std::cout << "That spot isn't available! Try another spot.\n";
        }
    } while (true);
}
std::string Game::determineWin(char* spaces) {
    std::string winner = "";
    // Checking for horizontal wins
    if (spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0] != ' ') {
        spaces[0] == 'O' ? winner = "Player O" : winner = "Player X";
    }
    else if (spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[3] != ' ') {
        spaces[3] == 'O' ? winner = "Player O" : winner = "Player X";
    }
    else if (spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[6] != ' ') {
        spaces[6] == 'O' ? winner = "Player O" : winner = "Player X";
    }
    // Checking for vertical wins
    else if (spaces[0] == spaces[3] && spaces[3] == spaces[6] && spaces[0] != ' ') {
        spaces[0] == 'O' ? winner = "Player O" : winner = "Player X";
    }
    else if (spaces[1] == spaces[4] && spaces[4] == spaces[7] && spaces[1] != ' ') {
        spaces[1] == 'O' ? winner = "Player O" : winner = "Player X";
    }
    else if (spaces[2] == spaces[5] && spaces[5] == spaces[8] && spaces[2] != ' ') {
        spaces[2] == 'O' ? winner = "Player O" : winner = "Player X";
    }
    // Checking for diagonals
    else if (spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' ') {
        spaces[0] == 'O' ? winner = "Player O" : winner = "Player X";
    }
    else if (spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[6] != ' ') {
        spaces[2] == 'O' ? winner = "Player O" : winner = "Player X";
    }
    // Return true if the winner variable contains a string.
    if (winner == "") {
        return "";
    }
    else {
        return winner;
    }
}
bool Game::determineTie(char* spaces) {
    if (Game::determineWin(spaces) == "") {
        return true;
    }
    return false;
}