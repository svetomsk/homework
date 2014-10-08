#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int bal) {
    balance = bal;
}

void HumanPlayer::updateBalance(int delta) {
    balance += delta;
}

void HumanPlayer::takeCard(OpenCard a) {
    hand.push_back(a);
}

void HumanPlayer::flush() {
    for(size_t i = 0; i < hand.size(); i++) {
        std::cout << hand[i].getValue() << " ";
    }
    std::cout << std::endl;
}
