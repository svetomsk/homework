#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <memory>

#include "InvalidAccessException.h"

class Player;

class Card {
public:
    friend class Deck;
    friend class Game;
    friend class SimpleTest;
    friend class PlayerData;

    // Possible card values
    enum Value {
        NONE = 0x00,
        D2 = 0x0002,
        D3 = 0x0003,
        D4 = 0x0004,
        D5 = 0x0005,
        D6 = 0x0006,
        D7 = 0x0007,
        D8 = 0x0008,
        D9 = 0x0009,
        D10 = 0x000A,
        KNAVE = 0x000B,
        QUEEN = 0x000C,
        KING = 0x000D,
        ACE = 0x000E,
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

    /**
    * Returns string value of card if owner is corrent
    * @param owner is who ask for access
    */
    std::pair<Card::Suit, Card::Value> tryLook(std::shared_ptr<Player> owner) const;

private:
    Value value;
    std::shared_ptr<Player> owner;
    Suit suit;
    static std::string suits[];
    static std::string values[];

    /**
    * Construct string equivalent of card
    * @return The returning string is graphics equivalent of card
    */
    std::string open();

    /**
    * Set an owner to card
    * @param owner is who must be new owner
    */
    void setOwner(std::shared_ptr<Player> const & owner);

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
