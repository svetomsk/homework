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
    std::vector<Player*> players; // list of players
    std::vector<PlayerData*> data; // list of player data

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
public:
    /**
    * Default constructor. Do nothing.
    */
    Game();

    /**
    * Destructor clears memory
    */
    ~Game();

    /**
    * Starts game.
    * @param count is amount of players in game
    */
    void startGame(int count);
};

#endif // GAME_H
