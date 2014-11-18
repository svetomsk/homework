#ifndef DECK_H
#define DECK_H
#include <vector>
#include <time.h>
#include <Rules.h>
#include "Card.h"

class Deck {
private:
    friend class Game;
    std::vector<Card> stash;
    /**
    * Constucts deck with standart set of cards
    */
    Deck();
    static Card makeCard(Card::Suit s, Card::Value v, std::shared_ptr<Player> const & p) {
        Card c(s, v);
        c.setOwner(p);
        return std::move(c);
    }
public:

    /**
    * Method to get card from the top of deck and
    * remove it from deck.
    * @return Returns card from the top of deck
    */
    Card getCard();

    /**
    * Makes random shuffle of cards.
    */
    void shuffle();
};

#endif // DECK_H
