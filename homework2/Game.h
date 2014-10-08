#ifndef GAME_H
#define GAME_H
#include <vector>
#include "HumanPlayer.h"
#include "Deck.h"

class Game {
protected:
    std::vector<Player*> players;
    std::vector<bool> inGame;
    int numberOfPlayers;

    void turn();
    void distributeCards(int);
    void flushPlayers();
    void findWinner();
    void sortCards();
    void ante();

public:
    Game(int);
    void startGame();
    int stringToInt(std::string);
    std::string intToString(int);
    ~Game();
};

#endif // GAME_H
