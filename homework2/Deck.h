#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"

class Deck {
  Card getCars();
  void shuffle();
  //copy = delete;
};

#endif // DECK_H
