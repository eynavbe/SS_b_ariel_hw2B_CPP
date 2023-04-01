#include "player.hpp"
using namespace std;
using namespace ariel;

Player::Player() {}
Player::Player(string name) {
    name1 = name;
    // 26 cards the player gets + 52 cards the player can win
    this->cards = new Card[78];
     for (int i=0; i<78; ++i){
        this->cards[i] = Card{0,""};
    }
}


string Player::getName(){
    return name1;
}

// Player::~Player() {
//     delete[] this->cards;
// }

int Player::cardesTaken() {
    int i = 26;
    while(this->cards[i].getNum() != 0){
        i++;
    }
    return i - 26;
}

int Player::stacksize() {
    int i = 0;
    while(this->cards[i].getNum() == 0){
        i++;
    }
    return 26-i;
}

std::string Player::toString(){
    std::string toString1 = "";
    for (int i=0; i<78; ++i){
        if(this->cards[i].getNum()  != 0){
            toString1 += (this->cards)[i].toString()  + "\n";
        } 
    }
    return toString1;
}

std::string Player::cardesWin(){
    std::string toString1 = "";
    for (int i=26; i<78; ++i){
        if(this->cards[i].getNum() != 0){
            toString1 += (this->cards)[i].toString() + "   ";
        } 
    }
    return toString1;
}

Card* Player::getCards(){
    return this->cards;
}

void Player::setCards(Card* c1){
    this->cards = c1;
}
// Player::~Player() {
//     delete[] cards;
// }