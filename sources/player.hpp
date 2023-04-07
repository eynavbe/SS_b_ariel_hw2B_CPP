#include <string>
#include <iostream>
#include "card.hpp"

using namespace std;
namespace ariel
{
#ifndef PLAYER_H
#define PLAYER_H
class Player {
  private:    
    std::string name1;
    int *pointer;
    Card* cards;
  public:
    Player();
    // create a player who receives a name, an array is also created that represents the cards the player has
    Player(string);
    //prints the amount of cards left.
    int stacksize();
     // prints the amount of cards this player has won. 
    int cardesTaken();
    // return the player name
    std::string getName();
    // Returns the pointer to the player's memory - to check if the players are different if they have the same name
    int *getPointer();
    // Return the array of cards the player has
    Card* getCards();
    // set the card array the player has with other card arrays
    void setCards(Card*);
    // Return all the cards the player has as a string
    std::string toString();
    // Return all the cards the player won
    std::string cardesWin();

};
#endif

}

