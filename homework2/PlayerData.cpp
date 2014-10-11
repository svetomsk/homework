#include "PlayerData.h"

void PlayerData::takeCard(Card a) {
    cards.push_back(a);
}

int PlayerData::getBlind() {
    return 300;
}

Card PlayerData::getCard(int index) {
    Card cur = cards[index];
    cards.erase(cards.begin() + index);
    return cur;
}

bool PlayerData::isDealer() {
    return dealer;
}

void PlayerData::performCardChange(int index, Card card) {
    cards[index] = card;
}

