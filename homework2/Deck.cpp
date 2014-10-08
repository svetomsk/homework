#include "Deck.h"
#include <sstream>
#include <cstdlib>
#include <time.h>

const std::string suits[] = { "♥", "♦", "♠", "♣" };
const std::string values[] = { "2", "3", "4", "5", "6",
                               "7", "8", "9", "10", "V",
                               "D", "K", "T"};


int deckSize = 48;

Deck::Deck() {

    for(size_t i = 0; i < 4; i++) {
        std::string suit = suits[i];
        for(size_t j = 0; j < 12; j++) {
            std::string value = values[j];
            cards.push_back(OpenCard(suit, value));
        }
    }
}

void Deck::shuffle() {
    srand (time(NULL));
    for(size_t i = 0; i < deckSize; i++) {
        int first = rand() % deckSize;
        int second = rand() % deckSize;
        cards[first].swap(cards[second]);
    }
}

OpenCard Deck::giveCard() {
    OpenCard result = cards.back();
    cards.pop_back();
    deckSize--;
    return result;
}
void Deck::show() {
    for(int i = 0; i < deckSize; i++) {
        std::cout << cards[i].getValue();
    }
}
