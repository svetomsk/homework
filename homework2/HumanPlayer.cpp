#include "HumanPlayer.h"
#include <utility>

HumanPlayer::HumanPlayer(int bal) {
    balance = bal;
    points = 0;
}

void HumanPlayer::updateBalance(int delta) {
    balance += delta;
}

void HumanPlayer::takeCard(OpenCard a) {
    hand.push_back(a);
}

//flesh royal 9
//strit flash 8
//care 7
//full house 6
//flash 5
//strit 4
//trips 3
//two pairs 2
//pair 1
//greatest card 0

std::string HumanPlayer::maxCombination() {
    bool sameSuit = true;
    bool inOrder = true;
    bool fourSame = false;
    bool threeSame = false;
    bool fullHouse = false;
    int pairCount = 0;

    //check for same suit
    for(size_t i = 0; i < hand.size(); i++) {
        if(hand[i].suit != hand[0].suit) sameSuit = false;
    }

    //check for order in cards
    for(size_t i = 0; i < hand.size() - 1; i++) {
        if(!(hand[i].isNext(hand[i + 1]))) inOrder = false;
    }

    //check for 4 same cards
    if(hand.size() > 3) {
        for(size_t i = 0; i < hand.size() - 3; i++) {
            std::string a = hand[i].value, b = hand[i + 1].value, c = hand[i + 2].value, d = hand[i + 3].value;
            if(a == b && b == c && c == d) fourSame = true;
        }
    }

    //count pairs
    for(size_t i = 0; i < hand.size() - 1; i++) {
        if(hand[i].value == hand[i + 1].value) {
            pairCount++;
            i++;
        }
    }
    //check for 3 same cards
    for(size_t i = 0; i < hand.size() - 2; i++) {
        std::string a = hand[i].value, b = hand[i + 1].value, c = hand[i + 2].value;
        if(a == b && b == c) threeSame = true;
    }

    //check full house
    if(hand.size() >= 5) {
        for(size_t i = 0; i < hand.size() - 4; i++) {
            std::string a = hand[i].value, b = hand[i + 1].value, c = hand[i + 2].value, d = hand[i + 3].value, e = hand[i + 4].value;
            if((a == b && c == d && d == e) ||
                (a == b && b == c && d == e)) fullHouse = true;
        }
    }

    //flesh royal
    if(hand[hand.size() - 1].value == "T" && sameSuit && inOrder) return "Flesh royal";
    //strit flash
    if(sameSuit && inOrder) return "Strit flash";
    //care
    if(fourSame) return "Care";
    //full house
    if(fullHouse) return "Full house";
    //flash
    if(sameSuit) return "Flash";
    //strit
    if(inOrder) return "Strit";
    //trips
    if(threeSame) return "Set";
    //two pairs
    if(pairCount >= 2) return "Two pairs";
    //pair
    if(pairCount == 1) return "Pair";
    //greatest card
    return hand[hand.size() - 1].value;
}

void HumanPlayer::flush() {
    for(size_t i = 0; i < hand.size(); i++) {
        std::cout << hand[i].getValue() << " ";
    }
    std::cout << std::endl;
}
