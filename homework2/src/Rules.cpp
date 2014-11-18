#include "Rules.h"

namespace{
    unsigned int checkHighCard(std::vector<Card> const & cards) {
        Card::Value high = Card::NONE;
        for(auto & c : cards) {
            high = std::max(high, c.getValue());
        }
        return Rules::HighCard | high;
    }

    unsigned int checkPairs(std::vector <Card> const & cards) {
        size_t values[Card::ACE + 1] = { 0 };

        Card::Value highestCard = Card::NONE;
        Card::Value secondCard = Card::NONE;

        for (auto & c : cards) {
            Card::Value curValue = c.getValue();
            if (++values[curValue - Card::D2] == 2) {
                if (curValue > highestCard) {
                    secondCard = highestCard;
                    highestCard = curValue;
                }
                else if (curValue > secondCard)
                    secondCard = curValue;
            }
        }

        if(highestCard == Card::NONE) return checkHighCard(cards);
        return (secondCard != Card::NONE ? Rules::TwoPairs : Rules::Pair) | highestCard << 8 | secondCard;
    }

    unsigned int checkFlush(std::vector<Card> const & cards) {
        Card::Value high = Card::NONE;
        Card::Suit  suit = cards.cbegin()->getSuit();

        for (auto & c : cards) {
            high = std::max(high, c.getValue());
            if (c.getSuit() != suit)
                return 0;
        }
        return high | Rules::Flush;
    }

    unsigned int checkStraight(std::vector<Card> const & cards) {
        size_t values[Card::ACE + 1] = { 0 };
        for (auto & c : cards) {
            Card::Value current = c.getValue();
            ++values[current - Card::D2];
        }

        auto high = Card::NONE;
        auto count = 0;

        for (int i = Card::ACE; i >= Card::D2; --i) {
            if (values[i - Card::D2]) {
                if (high != Card::NONE) {
                    ++count;
                }
                else {
                    high = (Card::Value)i;
                    count = 1;
                }
            }
            else {
                high = Card::NONE;
            }
        }

        if (count == 5 || (count == 4 && high == Card::D5 && values[Card::ACE - Card::D2])) {
            return Rules::Straight | high;
        }

        return 0;
    }

    unsigned int checkFullHouse(std::vector<Card> const & cards) {
        size_t values[Card::ACE + 1] = { 0 };
        Card::Value twoValue = Card::NONE;
        Card::Value threeValue = Card::NONE;
        for(auto & c : cards) {
            Card::Value curValue = c.getValue();
            values[curValue - Card::D2]++;
            if(values[curValue - Card::D2] == 2) {
                twoValue = std::max(twoValue, curValue);
            }
            if(values[curValue - Card::D2] == 3) {
                if(threeValue < curValue) {
                    threeValue = curValue;
                    twoValue = Card::NONE;
                }
            }
        }
        if(twoValue == Card::NONE || threeValue == Card::NONE) {
            return 0;
        }
        return Rules::FullHouse | std::max(twoValue, threeValue) << 8 | std::min(twoValue, threeValue);
    }

    unsigned int checkQuads(std::vector<Card> const & cards) {
        size_t values[Card::ACE + 1] = { 0 };
        Card::Value high = Card::NONE;
        for(auto & c : cards) {
            Card::Value current = c.getValue();
            if(++values[current - Card::D2] == 4) {
                high = std::max(high, current);
            }
        }
        return (high != Card::NONE) ? Rules::Quads | high : 0;
    }
}

namespace Rules {
    unsigned int getCombinationRank(std::vector <Card> const & cards) {
        size_t values[Card::ACE + 1] = { 0 };

        Card::Value highestCard = Card::NONE;
        if(unsigned int quads = checkQuads(cards))
            return quads;
        if(unsigned int fullHouse = checkFullHouse(cards))
            return fullHouse;
        if (unsigned flushResult = checkFlush(cards))
        if (unsigned int straightResult = checkStraight(cards))
            return straightResult & 0x00FFFFFF | Rules::StraightFlush;
        else
            return flushResult;

        if (unsigned int straightResult = checkStraight(cards))
            return straightResult;

        for (auto & c : cards) {
            Card::Value curValue = c.getValue();
            if (++values[curValue - Card::D2] == 3) {
                highestCard = std::max(highestCard, curValue);
            }
        }
        return highestCard == Card::NONE ? checkPairs(cards) : Rules::Set | highestCard;
    }

    unsigned int getDeckSize() {
        return 52;
    }
}