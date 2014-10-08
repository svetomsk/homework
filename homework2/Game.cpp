#include "Game.h"
#include <cstdlib>
#include <sstream>
#define print std::cout
#define read std::cin
static int defaultBalance = 300;

Game::Game(int count) {
    numberOfPlayers = count;
    for(size_t i = 0; i < numberOfPlayers; i++) {
        HumanPlayer* a = new HumanPlayer(defaultBalance);
        players.push_back(a);
    }
}

static bool gameCircle;
static int smallBlind, bigBlind;

void Game::startGame() {
    gameCircle = true;
    std::string input;
    Deck deck;
    deck.shuffle();
    //first bank up

    while(gameCircle) {

        //basic bets
        for(size_t i = 0; i < numberOfPlayers; i++) {
            print << "Player number " << i << " goes first bet. ";
            //checking for SmallBlind
            if(i == 0) {
                print << "You should enter SmallBlind: ";
            }
            //checking for BigBlind
            if(i == 1) {
                print << "You should enter BigBlind: ";
            }

            read >> input;
            int bet = stringToInt(input);
            if(i == 0) {
                if(bet <= defaultBalance / 2) {
                    smallBlind = bet;
                } else {
                    print << "SmallBlind must be less than half of bank.\n";
                    i--;
                    continue;
                }
            }
            if(i == 1) {
                if(bet <= defaultBalance && bet >= 2 * smallBlind) {
                    bigBlind = bet;
                } else {
                    print << "Your bet should be less than bank and more than 2 * smallBlind\n";
                    i--;
                    continue;
                }
            }
            if(bet > defaultBalance && bet < 2 * smallBlind) {
                print << "You bet should be less than bank and more that 2 * smallBlind\n";
                i--;
                continue;
            }
            players[i]->updateBalance(-bet);
        }

        //first hand
        for(size_t i = 0; i < numberOfPlayers; i++) {
            players[i]->takeCard(deck.giveCard());
            players[i]->takeCard(deck.giveCard());
            players[i]->flush();
        }

        gameCircle = false;
    }
}

Game::~Game() {
    for(size_t i = 0; i < numberOfPlayers; i++) {
        delete players[i];
    }
}

int Game::stringToInt(std::string s) {
    return atoi(s.c_str());
}

std::string Game::intToString(int a) {
    std::stringstream s;
    s << a;
    return s.str();
}
