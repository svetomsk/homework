#ifndef DECK_H
#define DECK_H
#include <vector>
#include <time.h>
#include "Card.h"

class Deck {
private:
    friend class Game;
    int stashSize = 52;
    int suitsCount = 4;
    int valuesCount = 13;
    std::vector<Card> stash;

    Deck();
    std::string open(Card &);
    void setSecret(Card &, int);
public:
    Card getCard();
    void shuffle();
    void display();
};

#endif // DECK_H
