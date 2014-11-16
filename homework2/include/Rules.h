#ifndef RULES_H
#define RULES_H

#include <memory>
#include <vector>
#include <algorithm>
#include <set>

#include "Card.h"
#include "Player.h"
#include "PlayerData.h"

// Useful functions to implement poker rules
namespace Rules {
    // Mask for getCombinationRank result indicating best found cobbination.
    // LSB used to rank diffirent combinations of same type
    enum Combinations {
        StraightFlush	= 0x09000000,
        Quads			= 0x08000000,
        FullHouse		= 0x07000000,
        Flush			= 0x06000000,
        Straight		= 0x05000000,
        Set				= 0x04000000,
        TwoPairs		= 0x03000000,
        Pair			= 0x02000000,
        HighCard		= 0x01000000
    };
    // Default player bank size
    static unsigned int stdBank = 500;

    /**
    * Get rank of best combination in given cards.
    * @param cards Cards
    * @return Unsigned int value of best combination
    */
    unsigned int getCombinationRank(std::vector<Card> const & cards);

    /**
    * Get default deck size.
    * @return Default size of deck
    */
    unsigned int getDeckSize();

}

#endif // RULES_H
