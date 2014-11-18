add_subdirectory(gtest-1.6.0)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES
    ../src/Card.cpp
    ../src/Deck.cpp
    ../src/Game.cpp
    ../src/HumanPlayer.cpp
    ../src/PlayerData.cpp
    ../src/Rules.cpp
    ../include/Card.h
    ../include/Deck.h
    ../include/Game.h
    ../include/HumanPlayer.h
    ../include/Player.h
    ../include/PlayerData.h
    ../include/Rules.h
)

add_library(PokerLib ${SOURCE_FILES})

set(TEST_SOURCE
    CardTest.cpp
    RulesTest.cpp
    PlayerDataTest.cpp
    TestDeck.cpp
)

add_executable( test_runner ${TEST_SOURCE})
target_link_libraries(test_runner PokerLib gtest gtest_main)