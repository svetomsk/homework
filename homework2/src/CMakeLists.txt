set(SOURCE_FILES
    Card.cpp
    Deck.cpp
    Game.cpp
    HumanPlayer.cpp
    Main.cpp
    PlayerData.cpp
    Rules.cpp
    ../include/Card.h
    ../include/Deck.h
    ../include/Game.h
    ../include/HumanPlayer.h
    ../include/Player.h
    ../include/PlayerData.h
    ../include/Rules.h
)

add_executable(Poker ${SOURCE_FILES})