#ifndef DECK_H
#define DECK_H
#include <vector>
#include "OpenCard.h"

class Deck {
    std::vector<OpenCard> cards;    
public:
    Deck();
    void shuffle();
    OpenCard giveCard();
    void show();
};

#endif // DECK_H
