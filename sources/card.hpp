// #include "player.hpp"
// #include "game.hpp"
#include <iostream>

namespace ariel
{
#ifndef CARD_H
#define CARD_H
class Card {
  private:    
    int num;
    std::string type;
  public:
    Card();
    // Create a card with a card number and card type (Heart, Spade, Diamond, Club)
    Card(int, std::string);
    // Return the card number
    int getNum();
    // Return the type card 
    std::string getType();
    // Return the card as a string. example: Queen of Hearts, 5 of Spades
    std::string toString();
};
#endif

}
   