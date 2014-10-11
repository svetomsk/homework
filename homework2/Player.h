#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <utility>
#include "Card.h"

class Player {
private:
    int secret;
public:
    Player();
    std::string getRoundChoise();
};

#endif // PLAYER_H
