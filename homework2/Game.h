#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>
#include "Deck.h"

class Game {
private:
    Deck deck;
    Deck& makeSingletonDeck();

public:
  void foo();
};

#endif // GAME_H
