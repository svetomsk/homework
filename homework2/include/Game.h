#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>
#include <memory>
#include <time.h>
#include <algorithm>

#include <Rules.h>
#include "HumanPlayer.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerData.h"

class Game {
private:
    Deck deck; // current deck
    unsigned int bank; // current bank
    std::vector<std::shared_ptr<Player>> players; // list of players
    std::vector<std::shared_ptr<PlayerData>> data; // list of player data

    /**
    * Gives five cards to each players
    */
    void giveCards(int);

    /**
    * Perform round of auction
    */
    void performAuction();

    /**
    * Peform round of cards exchange
    */
    void performCardsExchange();

    /**
    * Displayes final standing
    */
    void performFinalStanding();

public:
    /**
    * Default constructor. Do nothing.
    */
    Game();

    static Card makeCard(Card::Suit s, Card::Value v, std::shared_ptr<Player> const & p) {
        return Deck::makeCard(s, v, p);
    }

    static Deck makeDeck() {
        static Deck d;
        return d;
    }

    /**
    * Starts game.
    * @param count is amount of players in game
    */
    void startGame(int count);
};

#endif // GAME_H
