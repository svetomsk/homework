#include "Deck.h"

Deck::Deck() {
    for(int i = Card::Sprade; i <= Card::Heart; i++) {
        for(int j = Card::D2; j <= Card::ACE; j++) {
            Card cur((Card::Suit)i, (Card::Value)j);
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
        int swap1 = rand() % Rules::getDeckSize();
        int swap2 = rand() % Rules::getDeckSize();
        stash[swap1].swap(stash[swap2]);
    }
}
