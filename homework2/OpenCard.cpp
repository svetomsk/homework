#include "OpenCard.h"
#include <cstdlib>

OpenCard::OpenCard(std::string s, std::string v) : Card(s, v){}

std::string OpenCard::getValue() {
    std::string res;
    res.append(value);
    res.append(suit);
    res.append(" ");
    return res;
}

void OpenCard::swap(OpenCard & other) {
    std::swap(suit, other.suit);
    std::swap(value, other.value);
}

int OpenCard::compare(const OpenCard & c) {
    std::string s1 = value; std::string s2 = c.value;
    int a1 = 0, a2 = 0;

    if(s1 == "V") a1 = 11;
    else if(s1 == "D") a1 = 12;
    else if(s1 == "K") a1 = 13;
    else if(s1 == "T") a1 = 14;
    else a1 = atoi(s1.c_str());

    if(s2 == "V") a2 = 11;
    else if(s2 == "D") a2 = 12;
    else if(s2 == "K") a2 = 13;
    else if(s2 == "T") a2 = 14;
    else a2 = atoi(s2.c_str());
    if(a1 > a2) return 1;
    if(a1 < a2) return -1 ;
    if(a1 == a2 && suit == c.suit) return 0;
    return 2;
}

bool OpenCard::isNext(const OpenCard& c) {
    std::string s1 = value; std::string s2 = c.value;
    int a1 = 0, a2 = 0;
    if(s1 == "V") a1 = 11;
    else if(s1 == "D") a1 = 12;
    else if(s1 == "K") a1 = 13;
    else if(s1 == "T") a1 = 14;
    else a1 = atoi(s1.c_str());

    if(s2 == "V") a2 = 11;
    else if(s2 == "D") a2 = 12;
    else if(s2 == "K") a2 = 13;
    else if(s2 == "T") a2 = 14;
    else a2 = atoi(s2.c_str());

    if(a1 + 1 == a2) return true;
    return false;
}

bool OpenCard::operator ==(const OpenCard& other) {
    if(compare(other) == 0) return true;
    return false;
}

bool OpenCard::operator <(const OpenCard& other) {
    if(compare(other) < 0) return true;
    return false;
}

bool OpenCard::operator >(const OpenCard& other) {
    if(compare(other) > 0) return true;
    return false;
}
