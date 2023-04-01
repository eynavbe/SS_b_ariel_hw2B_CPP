#include "card.hpp"
using namespace std;
using namespace ariel;

Card::Card() {}

Card::Card(int num, std::string type) {
    this->num = num;
    this->type = type;
}

int Card::getNum() {
    return this->num;
}

std::string Card::getType(){
    return this->type;
}

std::string Card::toString(){
    string toString1 = "";
    switch(this->num) {
        case 11:
                toString1 = "Prince of " + this->type;
            break;
        case 12:
                toString1 = "Queen of " + this->type;
            break;
        case 13:
                toString1 = "King of " + this->type;
            break;
        default:
            toString1 = "" + std::to_string(this->num) + " of " + this->type;
    }
    return toString1;
}

