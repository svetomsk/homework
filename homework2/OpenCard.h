#ifndef OPENCARD_H
#define OPENCARD_H
#include "Card.h"

class OpenCard: public Card {
protected:
    int compare(OpenCard const&);
public:
    OpenCard(std::string, std::string);
    std::string getValue();
    void swap(OpenCard &);
    bool isNext(OpenCard const&);
    bool operator < (OpenCard const&);
    bool operator > (OpenCard const&);
    bool operator == (OpenCard const&);
};

#endif // CLOSEDCARD_H
