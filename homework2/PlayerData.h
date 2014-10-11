#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include <iostream>
#include "Card.h"
#include <vector>

class PlayerData {
    bool dealer;
    std::vector<Card> cards;

    void takeCard(Card);
    Card getCard(int);
    void performCardChange(int, Card);
    int getBlind();
    bool isDealer();
public:
    void display();
    std::pair<std::string, std::string> getBestCombination();
};

#endif // PLAYERDATA_H
