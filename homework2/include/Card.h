#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

class Card {
public:
    friend class Deck;
    friend class Game;
    friend class SimpleTest;
    friend class PlayerData;

    // Possible card values
    enum Value {
        NONE = 0x00,
        D2 = 0x02,
        D3 = 0x03,
        D4 = 0x04,
        D5 = 0x05,
        D6 = 0x06,
        D7 = 0x07,
        D8 = 0x08,
        D9 = 0x09,
        D10 = 0x0A,
        KNAVE = 0x0B,
        QUEEN = 0x0C,
        KING = 0x0D,
        ACE = 0x0E,
    };

    // Possible card suits enumeration
    enum Suit {
        Sprade  = 0x100,
        Diamond = 0x101,
        Club     = 0x102,
        Heart   = 0x103,
    };

    /**
    * Gets a card's suit
    * @return Returns card's suit
    */
    Suit getSuit() const;

    /**
    * Gets a card's value
    * @return Returns card's value
    */
    Value getValue() const;

    Card() = delete;

    /**
    * Copy constructor
    * @param other is card to copy
    */
    Card(const Card&);

    /**
    * Assignment operator
    * @param other is card to assign
    */
    void operator = (const Card &);

private:
    Value value;
    Suit suit;
    static std::string suits[];
    static std::string values[];

    /**
    * Construct string equivalent of card
    * @return The returning string is graphics equivalent of card
    */
    std::string open();

    /**
    * Construct card based on Suit and Value in arguments
    * @param s is card suit
    * @param v  is card value
    */
    Card(Suit, Value);

    /**
    * Swaps two cards
    * @param other is card to swap
    */
    void swap(Card &);
};

#endif // CARD_H
