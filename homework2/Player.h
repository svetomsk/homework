#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <utility>
#include "Card.h"

class Player {
  class Hand {
    void display();
    std::pair<std::string, std::string> getBestCombination();
    void takeCard();
    Card getCard();
  };
  int getBlind();
  Card giveCard(int);
  bool isDealer();
  std::string getRoundChoise();
  void performCardChange();
  void lose();
  void win();
};

#endif // PLAYER_H
