#include <gtest/gtest.h>
#include "Game.h"

TEST(deck, creation_test) {
    Deck d(Game::makeDeck());
    bool check = true;
    for(int i = Card::Heart; i >= Card::Sprade; i--) {
        for(int j = Card::ACE; j >= Card::D2; j--) {
            if(!(d.getCard() == Game::makeCard((Card::Suit)i, (Card::Value)j, std::make_shared<HumanPlayer>()))) {
                check = false;
            }
        }
    }
    EXPECT_TRUE(check);
}

TEST(deck, shuffle_test) {
    Deck d(Game::makeDeck());
    bool suits[Card::Heart - Card::Sprade] = {0};
    bool values[Card::ACE - Card::D2] = {0};
    for(int i = Card::Sprade; i <= Card::Heart; i++) {
        for(int j = Card::D2; j <= Card::ACE; j++) {
            Card c(d.getCard());
            suits[c.getSuit() - Card::Sprade] = true;
            values[c.getValue() - Card::D2] = true;
        }
    }
    bool result = true;
    for(int i = 0; i < Card::Heart - Card::Sprade; i++) {
        result |= suits[i];
    }
    for(int i = 0; i < Card::ACE - Card::D2; i++) {
        result |= values[i];
    }
    EXPECT_TRUE(result);
}

TEST(deck, get_card_test) {
    Deck d(Game::makeDeck());
    Card c(d.stash.back());
    EXPECT_EQ(c, d.getCard());
}