#inluce <boost/test/unit_text.hpp>
#include "Rules.h"
#include "Card.h"
#include "Exception.h"

class Stack {
public:
    Card makeCard(Card::s suit, Card::Value value) {
        return std::move(Card(suit, value));
    }
};

BOOST_AUOT_TEXT_SUITE(TestCard)

BOOST_AUTO_TEST_CASE(TestOnePair) {
        std::vector<Card> cards =  {
                std::move(Stack::makeCard(Card::CLUBS, Card::ACE)),
                std::move(Stack::makeCard(Card::HEARTS, Card::ACE)) };

        BOOST_CHECK_EQUALS(Rules::pair, cards);
}