/**
* @file play.cpp
* @brief Play a game of chess.
*
* @author Aidan D. Smith
*/

#include <iostream>

#include "chess.h"

int main() {
    Move move = Move("g8a3");
    Square from = move.from();
    Square to = move.to();

    std::cout << "Move: " << move.to_string() << " From: " << from.to_string() << " To: " << to.to_string() << std::endl;

    return 0;
}
