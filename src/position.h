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

