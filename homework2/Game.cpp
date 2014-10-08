#include "Game.h"
#include <cstdlib>
#include <sstream>
#define print std::cout
#define read std::cin
static int defaultBalance = 300;
static int BANK = 0;

Game::Game(int count) {
    numberOfPlayers = count;
    for(size_t i = 0; i < numberOfPlayers; i++) {
        HumanPlayer* a = new HumanPlayer(defaultBalance);
        players.push_back(a);
        inGame.push_back(true);
    }
}

static bool gameCircle;
static int smallBlind, bigBlind;

void Game::startGame() {
    gameCircle = true;
    std::string input;
    Deck deck;
    deck.shuffle();

    //basic bets
    for(size_t i = 0; i < numberOfPlayers; i++) {
        print << "Player " << i << " goes first bet. ";
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
        BANK += bet;
        players[i]->updateBalance(-bet);
    }

    //first hand
    for(size_t i = 0; i < numberOfPlayers; i++) {
        players[i]->takeCard(deck.giveCard());
        players[i]->takeCard(deck.giveCard());
    }

    while(gameCircle) {
        //Pre-flop
        print << "Make your bets, please!\n";
        int lastBet = 0;
        for(size_t i = 0; i < numberOfPlayers; i++) {
            if(inGame[i]) {
                print << "Player " << i << " goes: ";
                read >> input;
                int curBet = 0;
                if(input == "fold") {
                    inGame[i] = false;
                    print << "OK. Fold.\n.";
                } else if(input == "call") {
                    if(lastBet) {
                        curBet = lastBet;
                    } else {
                        print << "You are the first!\n";
                        i--;
                        continue;
                    }
                } else if(input == "up") {
                    read >> input;
                    curBet = stringToInt(input);
                    if(curBet <= lastBet) {
                        print << "Your bet must be more than the last one!\n";
                        i--;
                        continue;
                    }
                    if(curBet > bigBlind || curBet < 2 * smallBlind) {
                        print << "Your bet must be less that bigBlind and less than 2 * smallBlind!\n";
                        i--;
                        continue;
                    }
                } else {
                    print << "Don't know what you mean!\n";
                    i--;
                    continue;
                }
                print << "OK. Your bet is " << curBet << "\n";
                players[i]->updateBalance(-curBet);
                lastBet = curBet;
                BANK += curBet;
            }

            //Flop
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
