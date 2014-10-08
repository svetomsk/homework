#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(int);
    void updateBalance(int);
    void takeCard(OpenCard);
    void flush();
};

#endif // HUMANPLAYER_H
