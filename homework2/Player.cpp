#include "Player.h"

void Player::sortCards(){
    for(int i = 0; i < hand.size(); i++) {
        for(int j = 0; j < hand.size() - i - 1; j++) {
            if(hand[j] > hand[j + 1] || hand[j + 1] == hand[j]) {
                hand[j + 1].swap(hand[j]);
            }
        }
    }
}
