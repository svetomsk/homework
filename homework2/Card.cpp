#include "Card.h"

std::string Card::suits[] = { "♥", "♦", "♣", "♠" };
std::string Card::values[] = { "2", "3", "4", "5", "6",
                               "7", "8", "9", "10", "J",
                               "Q", "K", "A" };
int Card::suitsCount = 4;
int Card::valuesCount = 13;

Card::Card(int s, int v, int sec) : suit(s), value(v), secret(sec) {}

Card::Card(const Card & other) : suit(other.suit), value(other.value), secret(other.secret) {}

void Card::operator =(const Card & other) {
    suit = other.suit;
    value = other.value;
    secret = other.secret;
}

std::string Card::open() {
    std::string res;
    res.append("|");
    res.append(values[value]);
    res.append(suits[suit]);
    res.append("| ");
    return res;
}

void Card::swap(Card & other) {
    std::swap(suit, other.suit);
    std::swap(value, other.value);
}
