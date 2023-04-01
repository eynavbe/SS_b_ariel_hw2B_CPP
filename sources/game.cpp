#include "game.hpp"
using namespace std;
using namespace ariel;

void Game::playTurn() {
    int i = (this->p1).stacksize();
    int cardesTakenP1 = (this->p1).cardesTaken();
    int cardesTakenP2 = (this->p2).cardesTaken();
    i = 26 - i; 
    int r = playCurrentTurn(i);
    r = this->indexTurn -1;
    if((this->p1).cardesTaken() > cardesTakenP1){
        while(r > i){
            r = r-1;
            addCardsWinner((this->p1),(this->p1).getCards()[r],(this->p2).getCards()[r]);
            (this->p2).getCards()[r] = Card{0,""};
            (this->p1).getCards()[r] = Card{0,""};
        }
    }else{
        if((this->p2).cardesTaken() > cardesTakenP2){
            while(r > i){
                r = r-1;
                addCardsWinner((this->p2),(this->p2).getCards()[r],(this->p1).getCards()[r]);
                (this->p2).getCards()[r] = Card{0,""};
                (this->p1).getCards()[r] = Card{0,""};
            }
        }else{
            while(r > i){
                 r = r-1;
                 addCardToPlayer((this->p2),(this->p2).getCards()[r]);
                 addCardToPlayer((this->p1),(this->p1).getCards()[r]);
                (this->p2).getCards()[r] = Card{0,""};
                (this->p1).getCards()[r] = Card{0,""};
            }
        }
    }  
}
int Game::playCurrentTurn(int i){
    if(i < 26){
        int big = biggerCard((this->p1).getCards()[i],(this->p2).getCards()[i]);
        (this->typeTurn)[this->indexTurn] = big;
        this->indexTurn = this->indexTurn + 1;
        switch(big) {
            case 1:
                addCardsWinner((this->p1),(this->p1).getCards()[i],(this->p2).getCards()[i]);
                (this->p2).getCards()[i] = Card{0,""};
                (this->p1).getCards()[i] = Card{0,""};
                break;
            case 2:
                addCardsWinner((this->p2),(this->p2).getCards()[i],(this->p1).getCards()[i]);
                (this->p2).getCards()[i] = Card{0,""};
                (this->p1).getCards()[i] = Card{0,""};
                break;
            default:
                int z = i+1+1;
                this->indexTurn = this->indexTurn + 1;
                playCurrentTurn(z);
        }
    }else{
        this->indexTurn = 27;
  
    }
    return i; 
}

int Game::biggerCard(Card c1,Card c2){
    if(c2.getNum() > c1.getNum()){
        return 2;
    }else{
        if(c2.getNum() < c1.getNum()){
            return 1;
        }else{
            return 3;
        } 
    }
}

void Game::addCardsWinner(Player p1,Card c1,Card c2){
    int i = p1.cardesTaken();
    i = 26 + i; 
    p1.getCards()[i] = c1;
    p1.getCards()[i+1] = c2;
}

void Game::addCardToPlayer(Player p1,Card c1){
    int i = p1.cardesTaken();
    i = 26 + i; 
    p1.getCards()[i] = c1;
}

string Game::lastTurn(int z_p1,int z_p2,int index_turn) {    
    string string1 = "";
    switch((this->typeTurn)[index_turn]) {
        case 1:
            if((index_turn >= 2) && ((this->typeTurn)[index_turn-2] == 3)){
            if(z_p1 < 1){
                    string1 = (this->p1).getName() + " played " + (this->p2).getCards()[z_p2].toString() + " " + (this->p2).getName() + " played " + (this->p2).getCards()[z_p2-1].toString() +string1;
                    return string1 + lastTurn(z_p1-4,z_p2-4,index_turn-2) + ". " +(this->p1).getName() + " wins.";
                }else{
                    string1 = (this->p1).getName() + " played " + (this->p1).getCards()[z_p1].toString() + " " + (this->p2).getName() + " played " + (this->p1).getCards()[z_p1-1].toString() + string1;
                    return string1 + lastTurn(z_p1-4,z_p2-4,index_turn-2) + ". " +(this->p1).getName() + " wins.";
                }
            }else{
                if(z_p1 < 1){
                    string1 += (this->p1).getName() + " played " + (this->p2).getCards()[z_p2].toString() + " " + (this->p2).getName() + " played " + (this->p2).getCards()[z_p2-1].toString() + ". " +(this->p1).getName() + " wins.";
                }else{
                    string1 += (this->p1).getName() + " played " + (this->p1).getCards()[z_p1].toString() + " " + (this->p2).getName() + " played " + (this->p1).getCards()[z_p1-1].toString() + ". " +(this->p1).getName() + " wins.";
                }
                return string1;
            }
            break;
        case 2:
            if((index_turn >= 2) && ((this->typeTurn)[index_turn-2] == 3)){
                if(z_p1 < 1){
                    string1 += (this->p1).getName() + " played " + (this->p2).getCards()[z_p2].toString() + " " + (this->p2).getName() + " played " + (this->p2).getCards()[z_p2-1].toString() +string1;
                    return string1 + lastTurn(z_p1-4,z_p2-4,index_turn-2)  + ". " + (this->p2).getName() + " wins.";
                }else{
                    string1 += (this->p1).getName() + " played " + (this->p1).getCards()[z_p1].toString() + " " + (this->p2).getName() + " played " + (this->p1).getCards()[z_p1-1].toString() + string1;
                    return string1 + lastTurn(z_p1-4,z_p2-4,index_turn-2)  + ". " + (this->p2).getName() + " wins.";
                }
            }else{
                if(z_p1 < 1){
                    string1 += (this->p1).getName() + " played " + (this->p2).getCards()[z_p2].toString() + " " + (this->p2).getName() + " played " + (this->p2).getCards()[z_p2-1].toString() + ". " + (this->p2).getName() + " wins.";
                }else{
                    string1 += (this->p1).getName() + " played " + (this->p1).getCards()[z_p1].toString() + " " + (this->p2).getName() + " played " + (this->p1).getCards()[z_p1-1].toString() +  ". " + (this->p2).getName() + " wins.";
                }
                return string1;
            }
            break;
        case 3:
            if((index_turn >= 2) && ((this->typeTurn)[index_turn-2] == 3)){
                if(z_p1 < 1){
                    string1 = ". Draw. " +(this->p1).getName() + " played " + (this->p2).getCards()[z_p2].toString() + " " + (this->p2).getName() + " played " + (this->p2).getCards()[z_p2-1].toString() +string1;
                    return string1 + lastTurn(z_p1-4,z_p2-4,index_turn-2) ;

                }else{
                    string1 = ". Draw. " +(this->p1).getName() + " played " + (this->p1).getCards()[z_p1].toString() + " " + (this->p2).getName() + " played " + (this->p1).getCards()[z_p1-1].toString() + string1;
                    return string1 + lastTurn(z_p1-4,z_p2-4,index_turn-2) ;
                }
            }else{
                if(z_p1 < 1){
                    string1 = ". Draw. " +(this->p1).getName() + " played " + (this->p2).getCards()[z_p2].toString() + " " + (this->p2).getName() + " played " + (this->p2).getCards()[z_p2-1].toString() +string1;
                }else{
                    string1 = ". Draw. " +(this->p1).getName() + " played " + (this->p1).getCards()[z_p1].toString() + " " + (this->p2).getName() + " played " + (this->p1).getCards()[z_p1-1].toString() + string1;
                }
                return string1;
            }
            break;
        default:
            return "end in the middle of the game ";
    }
}

void Game::printLastTurn() {
    int z_p1 = p1.cardesTaken();
    z_p1 = 26 + z_p1 - 1;
    int z_p2 = p2.cardesTaken();
    z_p2 = 26 + z_p2 - 1;
    int index_turn = this->indexTurn - 1;
    if(index_turn > 25){
        index_turn = 25;
    }

    if((this->typeTurn)[index_turn] == 1){
        cout << lastTurn(z_p1,0,index_turn) << endl; 
    }
    if((this->typeTurn)[index_turn] == 2){
        cout << lastTurn(0,z_p2,index_turn) << endl; 
    }
    if((this->typeTurn)[index_turn] == 0){
        cout << "end in the middle of the game " << endl; 
    }
}

void Game::playAll() {
    while ((this->p1).stacksize() != 0) {
        playTurn();
    }
}

void Game::printWiner() {
    int cardesTakenP1 = (this->p1).cardesTaken();
    int cardesTakenP2 = (this->p2).cardesTaken();
    if(cardesTakenP1 > cardesTakenP2){
        cout << "Winer: " << (this->p1).getName() << endl; 
    }
    if(cardesTakenP2 > cardesTakenP1){
        cout << "Winer: " << (this->p2).getName() << endl; 
    }
    if(cardesTakenP2 == cardesTakenP1){
        cout << "No Winer " << endl; 
    } 
}

void Game::printLog() {
    int z_p1 = p1.cardesTaken();
    z_p1 = 26 + z_p1 - 1;
    int z_p2 = p2.cardesTaken();
    z_p2 = 26 + z_p2 - 1;
    int index_turn = this->indexTurn - 1;
    if(index_turn > 25){
        index_turn = 25;
    }
    string string1 = "";
    while(index_turn >= 0){
        if((this->typeTurn)[index_turn] == 0 || (this->typeTurn)[index_turn] == 3){
            while((this->typeTurn)[index_turn] == 0 || (this->typeTurn)[index_turn] == 3){
                index_turn = index_turn-1;
            }
            string1 += "end in the middle of the game "; 
        }
        if((this->typeTurn)[index_turn] == 1){
            string1 = lastTurn(z_p1,0,index_turn) + "\n" +string1; 
            while((index_turn >= 2) && ((this->typeTurn)[index_turn-2] == 3)){
                z_p1 = z_p1-4;
                index_turn = index_turn-2;
            }
            index_turn = index_turn-1;
            z_p1 = z_p1-2;
        }
        if((this->typeTurn)[index_turn] == 2){
           string1 = lastTurn(0,z_p2,index_turn) + "\n"+string1; 

           while((index_turn >= 2) && ((this->typeTurn)[index_turn-2] == 3)){
                z_p2 = z_p2-4;
                index_turn = index_turn-2;
            }
            index_turn = index_turn-1;
            z_p2 = z_p2-2;
        }
    }
    cout << string1 << endl; 
}

void Game::printStats() {
    cout << "Stats " << (this->p1).getName() << ": "<< endl; 
    cout << "win rate: " << winRate(1) << " / " << amountOfTurn()<< endl; 
    cout << "amount cards won: " << (this->p1).cardesTaken() << endl; 
    cout << "cards won: " << (this->p1).cardesWin()  << endl; 
    cout << endl; 

    cout << "Stats " << (this->p2).getName() << ": "<< endl; 
    cout << "win rate: " << winRate(2) << " / " << amountOfTurn()<< endl; 
    cout << "amount cards won: " << (this->p2).cardesTaken() << endl; 
    cout << "cards won: " << (this->p2).cardesWin()  << endl; 
    cout << endl; 
  
    cout << "draw rate: " << amountOfDraws() << " / " << amountOfTurn() << endl; 
    cout << "amount of draws: " << amountOfDraws() << endl;    
}

int Game::amountOfDraws(){
    int count = 0;
    for (int i=0; i<26; ++i){
        if(typeTurn[i] == 3){
            count = count + 1;
        }
    }
    return count;
}

int Game::amountOfTurn(){
    int count = 0;
    for (int i=0; i<26; ++i){
        if(typeTurn[i] == 1 || typeTurn[i] == 2){
            count = count + 1;
        }
    }
    return count;
}

int Game::winRate(int indexPlayer){
    int count = 0;
    for (int i=0; i<26; ++i){
        if(typeTurn[i] == indexPlayer){
            count = count + 1;
        }
    }
    return count;
}


void Game::initCards() {
    for (int i=0; i<13; ++i){
        cards[((i+1)*4)-4] = Card{i+1,"Heart"};
        cards[((i+1)*4)-3] = Card{i+1, "Spade"};
        cards[((i+1)*4)-2] = Card{i+1, "Diamond"};
        cards[((i+1)*4)-1] = Card{i+1, "Club"};
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards, cards + 52, g);

    for (int i=0; i<26; ++i){
        (this->p1).getCards()[i] = Card{cards[i].getNum(),cards[i].getType()};
        typeTurn[i] = 0;
    }
    for (int i=26; i<52; ++i){
        (this->p2).getCards()[i-26] = Card{cards[i].getNum(),cards[i].getType()};
    }
}

Game::Game() {}

Game::Game(Player p1, Player p2) {
	this->p1 = p1;
    this->p2 = p2;
    this->indexTurn = 0;
    cards = new Card[52];
    typeTurn = new int[26];
    initCards();
}

void Game::setCards(Card* c1){
    this->cards = c1;
}

Game::~Game() {
    delete[] cards;
    delete[] typeTurn;
    delete[] (this->p1).getCards();
    delete[] (this->p2).getCards();

    
}