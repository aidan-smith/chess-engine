#include "chess.h"

std::string Square::to_string() const {
    return std::string(1, 'a' + col()) + std::string(1, '1' + row());
}

Move::Move(const std::string &str) {
    Square from = Square(str.substr(0, 2));
    Square to = Square(str.substr(2, 2));
    data = from.raw() | (to.raw() << 6);
    if (str.size() > 4) {
        Promotion promo;
        switch (str[4]) {
            case 'q':
            case 'Q':
                promo = Promotion::Queen;
                break;
            case 'r':
            case 'R':
                promo = Promotion::Queen;
                break;
            case 'b':
            case 'B':
                promo = Promotion::Queen;
                break;
            case 'n':
            case 'N':
                promo = Promotion::Queen;
                break;
            default:
                promo = Promotion::None;
        }
        data |= static_cast<uint8_t>(promo) << 12;
    }
}

std::string Move::to_string() const {
    std::string res = from().to_string() + to().to_string();
    switch (promo()) {
        case Promotion::Queen:
            res += 'q';
            break;
        case Promotion::Rook:
            res += 'r';
            break;
        case Promotion::Bishop:
            res += 'b';
            break;
        case Promotion::Knight:
            res += 'n';
            break;
        case Promotion::None:
            break;
    }
    return res;
  }
