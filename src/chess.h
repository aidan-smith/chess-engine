#pragma once

#include <cstdint>
#include <string>

typedef uint64_t Bitboard;

class Square {
public:
    // R/C indexing from bottom left:
    // a1 := [0, 0] => 0
    // b1 := [0, 1] => 1
    // a2 := [1, 0] => 8
    // e4 := [3, 4] => 28
    // h8 := [7, 7] => 63
    Square() = default;
    Square(uint8_t pos) : data(pos) {}
    Square(int row, int col) : Square(col + 8 * row) {}
    Square(const std::string &str) : Square(str[1] - '1', str[0] - 'a') {}
    Square(const char* str) : Square(std::string(str)) {}

    int raw() const { return data; }
    int row() const { return data / 8; }
    int col() const { return data % 8; }
    std::string to_string() const;

private:
    uint8_t data; // 6 bits used.
};

class Move {
public:
    enum class Promotion : uint8_t {None, Queen, Rook, Bishop, Knight};

    Move() = default;
    Move(Square from, Square to) : data(from.raw() + (to.raw() << 6)) {}
    Move(Square from, Square to, Promotion promo)
        : data(from.raw() + (to.raw() << 6) +
               (static_cast<uint8_t>(promo) << 12)) {}
    Move(const std::string &str);
    Move(const char* str) : Move(std::string(str)) {}

    int raw() const { return data; }
    Square from() const { return Square(data & kFromMask); }
    Square to() const { return Square((data & kToMask) >> 6); }
    Promotion promo() const { return Promotion((data & kPromoMask) >> 12); }
    std::string to_string() const;

private:
    enum Masks : uint16_t {
        kFromMask  = 0x003F, // 0:5
        kToMask    = 0x0FC0, // 6:11
        kPromoMask = 0x8000, // 12:14
    };

    uint16_t data; // 14 bits used.
};

class Piece {
public:
    enum class Type : uint8_t {None, Pawn, Knight, Bishop, Rook, Queen, King};
    enum class Color : uint8_t {None, White, Black};

    Piece() = default;
    Piece(Type type, Color color, bool en_passant = false)
        : data(static_cast<uint8_t>(type) +
               (static_cast<uint8_t>(color) << 4) + (en_passant << 6)) {}

    int raw() { return data; }
    Type type() { return Type(data & kPieceMask); }
    Color color() { return Color((data & kColorMask) >> 4); }
    bool en_passant() { return (data & kEnPassantMask) >> 6; }

private:
    enum Masks : uint8_t {
        kPieceMask = 0x0E,     // 0:3
        kColorMask = 0x18,     // 4:5
        kEnPassantMask = 0x20, // 6
    };

    uint8_t data; // 7 bits used.
};
