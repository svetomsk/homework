#include "OpenCard.h"

OpenCard::OpenCard(std::string s, std::string v) : Card(s, v){}

std::string OpenCard::getValue() {
    std::string res;
    res.append(value);
    res.append(suit);
    res.append(" ");
    return res;
}

void OpenCard::swap(OpenCard & other) {
    std::swap(suit, other.suit);
    std::swap(value, other.value);
}

bool OpenCard::operator ==(const OpenCard& other) {
    if(other.suit == suit && other.value == value) return true;
    return false;
}
