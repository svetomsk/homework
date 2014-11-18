#include <gtest/gtest.h>
#include "Game.h"

TEST(player_data, cash_check) {
    PlayerData data(300);
    EXPECT_EQ(data.cash, 300);
}

TEST(player_data, take_card_check) {
    PlayerData data(100);
    std::vector<Card> cards;
    Card c = Game::makeCard(Card::Sprade, Card::D2, std::make_shared<HumanPlayer>());
    cards.push_back(c);
    data.takeCard(c);
    EXPECT_EQ(cards[0], data.cards[0]);
}

TEST(player_data, exchange_card_check) {
    PlayerData data(100);
    Card c = Game::makeCard(Card::Sprade, Card::D2, std::make_shared<HumanPlayer>());
    Card c1 = Game::makeCard(Card::Sprade, Card::D2, std::make_shared<HumanPlayer>());
    data.takeCard(c);
    data.performCardChange(0, c1);

    EXPECT_EQ(data.cards[0], c1);
}