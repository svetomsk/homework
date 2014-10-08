#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card {
protected:
    std::string suit;
    std::string value;
public:
    Card(std::string, std::string);
    virtual std::string getValue()=0;
//    virtual operator == (const & Card)=0;
};

#endif // CARD_H
