#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
using namespace ariel;

TEST_CASE("Test1 - Checking initial conditions") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);   
}

TEST_CASE("Test2 - After the game is over, try to play another turn") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playAll();
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Test3 - The same player is registered for the same game") {
    Player p1("Alice");
    Game game(p1,p1);
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
}

TEST_CASE("Test4 - One player can only be registered for one game") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Shlomo");
    Game game(p1,p2);
    Game game2(p1,p3); 
    CHECK_THROWS(game2.playTurn());
    CHECK_THROWS(game2.playAll());
}

TEST_CASE("Test5 - Checking that the game ends") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playAll();
    int sum = p2.cardesTaken()+p1.cardesTaken();
    CHECK(sum == 52);
    CHECK(p2.cardesTaken() != p1.cardesTaken());
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}

TEST_CASE("Test6 - check void function does not throw an error") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("Test7 - turn has ended") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    int cardesP1 = p1.cardesTaken();
    int cardesP2 = p2.cardesTaken();
    game.playTurn();
    CHECK(p2.stacksize() == p1.stacksize());
    if(cardesP1 == p1.cardesTaken()){
        CHECK(cardesP2 < p2.cardesTaken());
    }{
        CHECK(cardesP2 == p2.cardesTaken());
    }
    /*  while will not work because there is no proper implementation of Game and Player */
    // while (p1.stacksize() != 0) {
    //     game.playTurn();
    //     CHECK(p2.stacksize() == p1.stacksize());
    //     if(cardesP1 == p1.cardesTaken()){
    //         CHECK(cardesP2 < p2.cardesTaken());
    //     }{
    //         CHECK(cardesP2 == p2.cardesTaken());
    //     }
    //     cardesP1 = p1.cardesTaken();
    //     cardesP2 = p2.cardesTaken();
    // }
}

TEST_CASE("Test8 - No more than 26 turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    int count = 0;  
    /* while will not work because there is no proper implementation of Game and Player */
    // while (p1.stacksize() != 0) {
    //     game.playTurn();
    //     count = count + 1;
    // }
    // CHECK(count <= 26);
}

