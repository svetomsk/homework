#include "HumanPlayer.h"

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

//flesh royal
//strit flash
//care
//full house
//flash
//strit
//trips
//two pairs
//pair
//greatest card

std::string HumanPlayer::maxCombination() {
    bool sameSuit = true;
    bool inOrder = true;

    for(size_t i = 0; i < hand.size(); i++) {
        if(hand[i].suit != hand[0].suit) sameSuit = false;
    }

    for(size_t i = 0; i < hand.size() - 1; i++) {
        if(!(hand[i].isNext(hand[i + 1]))) inOrder = false;
    }

    //flesh royal
    if(hand[hand.size() - 1].value == "T" && sameSuit && inOrder) return "Flesh royal";
    //strit flash
    if(sameSuit && inOrder) return "Strit flash";
    //care

    return "NO RETURN";
}

void HumanPlayer::flush() {
    for(size_t i = 0; i < hand.size(); i++) {
        std::cout << hand[i].getValue() << " ";
    }
    std::cout << std::endl;
}
