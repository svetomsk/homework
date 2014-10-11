#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

class Card {

    friend class Deck;
    int value, suit, secret;
    static std::string suits[];
    static std::string values[];

    std::string open();
    Card(int,int, int);
    void swap(Card &);

public:
    static int suitsCount;
    static int valuesCount;
    static enum { HEARTS, KARO, CLUBS, SPADES } s;
    static enum { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } v;

    Card() = delete;
    Card(const Card&);
    void operator = (const Card &);

    std::string tryLook(int);
    void setOwner(int);
};

#endif // CARD_H
