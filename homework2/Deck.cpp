#include "Deck.h"

Deck::Deck() {
    std::cout << "DECK";
    for(size_t i = 0; i < suitsCount; i++) {
        for(size_t j = 0; j < valuesCount; j++) {
            Card cur(i, j);
            stash.push_back(cur);
        }
    }
}

Card Deck::getCard() {
    Card cur(stash.back());
    stash.pop_back();
    return cur;
}

void Deck::shuffle() {
    srand(time(NULL));
    int countOfSwaps = 100;
    for(size_t i = 0; i < countOfSwaps; i++) {
        int swap1 = rand() % stashSize;
        int swap2 = rand() % stashSize;
        stash[swap1].swap(stash[swap2]);
    }
}

std::string Deck::open(Card & card) {
    return card.open();
}

void Deck::display() {
    for(size_t i = 0; i < stashSize; i++) {
        std::cout << stash[i].open();
    }
}
