#include "PlayerData.h"

PlayerData::PlayerData(unsigned int cash) {
    this->cash = cash;
}

void PlayerData::takeCard(Card a) {
    cards.push_back(a);
}

void PlayerData::performCardChange(int index, Card card) {
    cards[index].suit = card.suit;
    cards[index].value = card.value;
}

void PlayerData::display() {
    for(size_t i = 0; i < cards.size(); i++) {
        std::cout << cards[i].open() << " ";
    }
    std::cout << std::endl;
}

