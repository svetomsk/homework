#ifndef OPENCARD_H
#define OPENCARD_H
#include "Card.h"

class OpenCard: public Card {
public:
    OpenCard(std::string, std::string);
    std::string getValue();
    void swap(OpenCard &);
    bool operator == (OpenCard const&);
};

#endif // CLOSEDCARD_H
