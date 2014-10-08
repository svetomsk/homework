#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card {
public:
    std::string suit;
    std::string value;

    Card(std::string, std::string);
    virtual std::string getValue()=0;
};

#endif // CARD_H
