/**
* @file board.h
* @brief Represent a chess board.
*
* @author Aidan D. Smith
*/

#ifndef BOARD_H_
#define BOARD_H_

#include <array>
#include <string>
#include <vector>

#include "chess.h"

#define BOARD_SIZE (8 * 8)

class Board {
public:
    Board();
    Board(const std::string &fen);
    Board(const char* fen) : Board(std::string(fen)) {}

    std::string fromFEN();

    std::vector<Move> genPseudoLegalMoves() const;
    std::vector<Move> genLegalMoves() const;

    bool pushMove();
    bool popMove();

private:

    class Castling {

    };

    std::array<Piece, BOARD_SIZE> board;
    // Bitboard white_pieces;
    // Bitboard black_pieces;
    // Bitboard pawns;  // Rank 1 and 8 indicate en passant in this file.
    // Bitboard bishops; // Bishops and Queens.
    // Bitboard rooks;  // Rooks and Queens>

    Castling castling;
};

#endif
