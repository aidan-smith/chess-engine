/**
* @file position.h
* @brief Represent a chess position.
*
* @author Aidan D. Smith
*/

#ifndef POSITION_H_
#define POSITION_H_

#include "board.h"

class Position {
public:
    Position() = default;


private:
    Board board;
    int repetitions;
    int rule50_ply;
    int game_ply;
};

#endif
