#include <gtest/gtest.h>
#include "Game.h"

TEST(cards, suit_test) {
    EXPECT_EQ(Card::Sprade, Game::makeCard(Card::Sprade, Card::D2, std::shared_ptr<HumanPlayer>()).getSuit());
}

TEST(cards, value_test) {
    EXPECT_EQ(Card::D2, Game::makeCard(Card::Sprade, Card::D2, std::shared_ptr<HumanPlayer>()).getValue());
}

TEST(cards, throwable_test) {
    auto p = std::make_shared<HumanPlayer>();
    auto p1 = std::make_shared<HumanPlayer>();
    EXPECT_THROW(Game::makeCard(Card::Heart , Card::D2, p).tryLook(p1), InvalidAccess);
}
