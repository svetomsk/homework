#include "Card.h"

std::string Card::suits[] = { "♥", "♦", "♣", "♠" }; // array of symbols for suits
std::string Card::values[] = { "2", "3", "4", "5", "6",
                               "7", "8", "9", "10", "J",
                               "Q", "K", "A" }; // array of symbols for values

Card::Card(Card::Suit s, Card::Value v) : suit(s), value(v) {}

Card::Card(const Card & other) : suit(other.suit), value(other.value) {}

void Card::operator =(const Card & other) {
    suit = other.suit;
    value = other.value;
}

bool Card::operator ==(const Card & other) const {
    return (suit == other.suit && value == other.value);
}

void Card::setOwner(std::shared_ptr<Player> const & own) {
    owner = own;
}

std::pair<Card::Suit, Card::Value> Card::tryLook(std::shared_ptr<Player> owner) const{
    if(owner == this->owner) {
        return std::make_pair(suit, value);
    } else {
        throw InvalidAccess();
    }
}

std::string Card::open() {
    std::string res;
    res.append("|");
    res.append(values[value - Card::D2]);
    res.append(suits[suit - Card::Sprade]);
    res.append("| ");
    return res;
}

void Card::swap(Card & other) {
    std::swap(suit, other.suit);
    std::swap(value, other.value);
}

Card::Suit Card::getSuit()const{
    return suit;
}

Card::Value Card::getValue() const{
    return value;
}
