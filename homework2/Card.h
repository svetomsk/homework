#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
  std::string tryLook(int);
  void setOwner(int);
  std::string open();
};

#endif // CARD_H
