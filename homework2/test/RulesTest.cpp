#include <gtest/gtest.h>
#include "Game.h"

TEST(rules, hightest_card) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D3, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D4, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D5, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D8, p));

    EXPECT_EQ(Rules::HighCard | Card::D8, Rules::getCombinationRank(cards));
}

TEST(rules, one_pair_check) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D4, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D5, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D8, p));

    EXPECT_EQ(Rules::Pair | Card::D2 << 8, Rules::getCombinationRank(cards));
}

TEST(rules, two_pair_check) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D4, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D4, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D8, p));

    EXPECT_EQ(Rules::TwoPairs | Card::D4 << 8 | Card::D2, Rules::getCombinationRank(cards));
}

TEST(rules, set_check) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D5, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D8, p));

    EXPECT_EQ(Rules::Set | Card::D2, Rules::getCombinationRank(cards));
}

TEST(rules, straight_check) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D3, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D4, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D5, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D6, p));

    EXPECT_EQ( Rules::Straight | Card::D6, Rules::getCombinationRank(cards));
}

TEST(rules, flush_check) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D3, p));
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D4, p));
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D5, p));
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D8, p));

    EXPECT_EQ( Rules::Flush | Card::D8, Rules::getCombinationRank(cards));

}

TEST(rules, full_house_check) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D5, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D5, p));

    EXPECT_EQ( Rules::FullHouse | Card::D5 << 8 | Card::D2, Rules::getCombinationRank(cards));
}

TEST(rules, quads_check) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Sprade, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Heart, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Diamond, Card::D5, p));

    EXPECT_EQ( Rules::Quads | Card::D2, Rules::getCombinationRank(cards));
}

TEST(rules, straight_flush_ckeck) {
    std::vector<Card> cards;
    auto p = std::make_shared<HumanPlayer>();
    cards.emplace_back(Game::makeCard(Card::Club, Card::D2, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D3, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D4, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D5, p));
    cards.emplace_back(Game::makeCard(Card::Club, Card::D6, p));

    EXPECT_EQ( Rules::StraightFlush | Card::D6, Rules::getCombinationRank(cards));
}