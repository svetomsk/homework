#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "OpenCard.h"

class Player {
protected:
    int balance, points;
    std::vector<OpenCard> hand;

public:
    virtual void updateBalance(int) = 0;
    virtual void takeCard(OpenCard) = 0;
    virtual void flush() = 0;
    void sortCards();
    virtual std::string maxCombination()=0;
};

#endif // PLAYER_H
