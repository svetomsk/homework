#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include <iostream>
#include <vector>

#include "Card.h"

// contains all data of player
class PlayerData {
public:
    std::vector<Card> cards; // player's hand
    int cash; // current cash of player

    /**
    * Creates a new player's data with current cash.
    * @param dcash is cash to set
    */
    PlayerData(unsigned int dcash);

    /**
    * Method to give card to player
    * @param card is card to take
    * @param p is owner for card
    */
    void takeCard(Card card, std::shared_ptr<Player> const & p);

    /**
    * Gets card position and exchange it
    * @param pos is position of changing card
    * @param other is card to insert instead
    */
    void performCardChange(int pos, Card other);

    /**
    * Displays hand on screen
    */
    void display();
};

#endif // PLAYERDATA_H
