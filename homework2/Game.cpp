#include "Game.h"
#include <cstdlib>
#include <utility>
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

static int ante = 15;
static bool gameCircle;
Deck deck;

void Game::startGame() {
    gameCircle = true;
    std::string input;
    deck.show();
    deck.shuffle();
    deck.show();


    while(gameCircle) {
        //three cards round
        distributeCards(3);
//        turn();
        sortCards();
        flushPlayers();
        findWinner();

//        //five cards round
        distributeCards(2);
//        turn();
        sortCards();
        flushPlayers();
        findWinner();

//        //seven cards round
        distributeCards(2);
//        turn();
        sortCards();
        flushPlayers();
        findWinner();

        gameCircle = false;
    }
}

void Game::turn() {
    std::string input;
    for(size_t i = 0; i < numberOfPlayers; i++) {
        print << "Are you in game?\n";
        read >> input;
        if(input == "yes") {
            inGame[i] = true;
        } else if(input == "no") {
            inGame[i] = false;
        } else {
            print << "Don't know what do you mean!\n";
            i--;
            continue;
        }
    }
}

void Game::distributeCards(int count) {
    for(size_t i = 0; i < numberOfPlayers; i++) {
        for(size_t j = 0; j < count; j++) {
            players[i]->takeCard(deck.giveCard());
        }
    }
}

void Game::flushPlayers() {
    for(size_t i = 0; i < numberOfPlayers; i++) {
        players[i]->flush();
    }
}

void Game::findWinner() {
    for(size_t i = 0; i < numberOfPlayers; i++) {
        print << players[i]->maxCombination() << "\n";
    }
}

void Game::sortCards() {
    for(size_t i = 0; i < numberOfPlayers; i++) {
        players[i]->sortCards();
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

