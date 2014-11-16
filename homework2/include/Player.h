#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

#include "Card.h"

class Player {
public:
    /**
    * Method to communicate with player
    */
    virtual std::string getRoundChoise()=0;
};

#endif // PLAYER_H
