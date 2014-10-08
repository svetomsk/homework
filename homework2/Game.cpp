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

static int ant = 15;
static bool gameCircle;
static bool roundState;
Deck deck;

void Game::startGame() {
    gameCircle = true;
    std::string input;
    deck.shuffle();
    print << "Hi! This is 3-5-7 poker!\n";
    while(gameCircle) {
        roundState = true;
        //three cards round
        print << "First turn is coming!\n";
        ante();
        distributeCards(3);
        turn();
        sortCards();
        flushPlayers();
        findWinner();

//        //five cards round
        if(roundState) {
            print << "Second turn is coming!\n";
            distributeCards(2);
            turn();
            sortCards();
            flushPlayers();
            findWinner();
        }

//        //seven cards round
        if(roundState) {
            print << "Third turn is coming!\n";
            distributeCards(2);
            turn();
            sortCards();
            flushPlayers();
            findWinner();
        }

        print << "Another one?\n";
        while(input != "yes" && input != "no") {
            read >> input;
            if(input == "yes") {
                gameCircle = true;
            } else if(input == "no") {
                gameCircle = false;
                print << "OK. Goodbuy!\n";
            }else {
                print << "Don't know what do you mean!\n";
            }
        }
    }
}

void Game::turn() {
    std::string input;
    int countInGame = 0;
    for(size_t i = 0; i < numberOfPlayers; i++) {
        print << "Your cards: ";
        players[i]->flush();
        print << "Player " << i << ", are you in game?\n";
        read >> input;
        if(input == "yes") {
            inGame[i] = true;
            countInGame++;
        } else if(input == "no") {
            inGame[i] = false;
        } else {
            print << "Don't know what do you mean!\n";
            i--;
            continue;
        }
    }
    if(countInGame == 1) {
        roundState = false;
        for(size_t i = 0; i < numberOfPlayers; i++) {
            if(inGame[i]) {
                players[i]->increasePoints();
                print << "Player " << i << " got point!\n";
            }
        }
    }
    if(countInGame == 0) {
        roundState = false;
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
        if(inGame[i])
            players[i]->flush();
    }
}

void Game::findWinner() {
    for(size_t i = 0; i < numberOfPlayers; i++) {
        if(inGame[i])
            print << players[i]->maxCombination() << "\n";
    }
}

void Game::sortCards() {
    for(size_t i = 0; i < numberOfPlayers; i++) {
        players[i]->sortCards();
    }
}

void Game::ante() {
    for(size_t i = 0; i < numberOfPlayers; i++) {
        BANK += ant;
        players[i]->updateBalance(-ant);
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

