#include "Game.h"

std::vector<bool> inGame;

void Game::giveCards(int count) {
    for(int i = 0; i < count; i++) {
        players.push_back(new HumanPlayer);
        for (size_t j = 0; j < 5; j++) {
            data.push_back(new PlayerData(Rules::stdBank));
            data[i]->takeCard(deck.getCard());
        }
    }
}

void Game::performAuction() {
    int currentBet = 0;

    for(int i = 0; i < players.size(); i++) {
        if(inGame[i]) {
            std::cout << "Player " << i << " choise: ";
            std::string answer = players[i]->getRoundChoise();
            if (answer == "fold") {
                inGame[i] = false;
            } else if (answer == "check") {
                if (currentBet) {
                    i--;
                    std::cout << "You can't do 'check'.\n";
                }
            } else if (answer == "call") {
                if (currentBet == 0) {
                    i--;
                    std::cout << "Current bet is not defined yet. Try again\n";
                    continue;
                } else {
                    bank += currentBet;
                }
            } else if (answer == "raise") {
                std::string value;
                std::cin >> value;
                int curValue = atoi(value.c_str());
                if (curValue < currentBet) {
                    i--;
                    std::cout << "Raise shoud be more that current bet.\n";
                    continue;
                }
                bank += atoi(value.c_str());
                if (!currentBet) {
                    currentBet = curValue;
                }
            } else if (answer == "cards") {
                data[i]->display();
                std::cout << std::endl;
                i--;
            } else if (answer == "bank") {
                std::cout << data[i]->cash << std::endl;
                i--;
            } else if (answer == "help") {
                i--;
                std::cout << "fold call raise cards bank\n";
            } else {
                i--;
                std::cout << "Unknown input. Try 'help' for information\n";
            }
        }
    }
}

void Game::performCardsExchange() {
    for(int i = 0; i < players.size(); i++) {
        if(inGame[i]) {
            std::cout << "Do you want to exchange your cards, Player " << i << " ?\n";
            data[i]->display();
            std::string answer = players[i]->getRoundChoise();
            if(answer == "Yes") {
                std::cout << "How many and which ones?\n";
                answer = players[i]->getRoundChoise();
                int count = atoi(answer.c_str());
                int cur = 0;
                for(int j = 0; j < count; j++) {
                    answer = players[i]->getRoundChoise();
                    cur = atoi(answer.c_str());
                    data[i]->performCardChange(cur - 1, deck.getCard());
                }
            }
            data[i]->display();
        }
    }
}

Game::Game() {}

void Game::startGame(int count) {
    deck.shuffle();
    std::cout << "Hello!\n";
    std::cout << "Take your cards prease!\n";
    std::cout << "Type 'help' for list of commands. All comands are register dependent.\n";
    std::vector<bool> cur(count, true);
    inGame = cur;
    bank = 0;

    giveCards(count);
    std::cout << "First round of auction getting started now!\n";
    performAuction();
    std::cout << "Cards exchange round getting started now!\n";
    performCardsExchange();
    std::cout << "Second round of auction getting started now!\n";
    performAuction();

    int maxCombination = 0;
    std::vector<int> winners;
    winners.push_back(0);
    for(int i = 0; i < players.size(); i++) {
        if(inGame[i]) {
            int curCombination =  Rules::getCombinationRank(data[i]->cards);
            if(curCombination > maxCombination) {
                maxCombination = curCombination;
                winners.erase(winners.begin(), winners.end());
                winners.push_back(i + 1);
            } else if(curCombination == maxCombination) {
                winners.push_back(i + 1);
            }

        }
    }

    std::cout << "Final standing:\n";
    for(int i = 0; i < players.size(); i++) {
        std::cout << "Player " << i << " cards: ";
        data[i]->display();
    }
    std::cout << "Winner(-s): \n";
    int prize = bank/winners.size();
    for(int i = 0; i < winners.size(); i++) {
        std::cout << "Player " << winners[i] << " won " << prize << std::endl;
    }
}

Game::~Game() {
    for(size_t i = 0; i < players.size(); i++) {
        delete players[i];
    }
    for(size_t i = 0; i < data.size(); i++) {
        delete data[i];
    }
}
