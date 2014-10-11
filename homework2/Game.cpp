#include "Game.h"
#include <algorithm>
void Game::foo() {
    Card cur = deck.getCard();
    deck.setSecret(cur, 300);
}
