#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#ifndef GAME_H
#define GAME_H
namespace ariel
{
  class Game {
    private:    
      Player p1;
      Player p2;
      Card* cards;
      int *typeTurn; //Every turn what was the result
     // 0 - There was no comparison between the cards
      // 1 - Player 1 won
      // 2 - Player 2 won
      // 3 - a draw
      int indexTurn;
    public:
      Game();
      ~Game();
      // Create two players with their names 
      Game(Player,Player);
      //playes the game 
      void playTurn();
      // print the last turn stats.
      void printLastTurn();
      //playes the game untill the end
      void playAll();
       // prints the name of the winning player
      void printWiner();
      // prints all the turns played one line per turn 
      void printLog();
      //for each player prints basic statistics: win rate, cards won. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
      void printStats();
      // A deck of cards with 52 cards is randomly shuffled and divided equally between the two players
      void initCards();
      // Adding the 2 cards the player won to the array of cards the player has
      void addCardsWinner(Player,Card,Card);
      // Adding one card to the player, in case the game ends and the remaining cards need to be dealt back to the player
      void addCardToPlayer(Player,Card);
      // check when there are two cards which player is the winner in the current turn
      int biggerCard(Card,Card);
      // To play the current turn, when checking in biggerCard function if it is player 1 or 2 then add these two cards to the winning players, and the position of these cards in the array changes to 0. If it's a tie, then move 2 cards forward and compare it, etc.
      int playCurrentTurn(int);
      // void changeCardTaken();
      // The amount of draws there was in the game, if there was more than one draw in a row count them all
      int amountOfDraws();
      // The amount of turn there was in the game
      int amountOfTurn();
      int winRate(int);
      // Returns the move that was in the last turn.
      // For example:
      // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
      // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
      string lastTurn(int,int,int);
       // set the card array the game has with other card arrays
      void setCards(Card*);
  };
#endif
}

   