#include <array>
#include <string>

#include "chess.h"

#define BOARD_SIZE (8 * 8)

class Board {
public:

    std::string to_fen();
    void push_move();
    void pop_move();

private:
    std::array<Piece, BOARD_SIZE> board;
};
