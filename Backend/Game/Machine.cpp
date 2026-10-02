#include "Machine.h"
#include <iostream> 

using namespace std;
//The input is a touple of (rows, cols)
Machine::Machine(vector<int> dim){
    cout << "Welcome to the Strange slot" << endl;
    this->balance = 0;
    srand(time(nullptr));
    if(dim.size() > 2){
        cout << "Incorrect dimensions" << endl;
        return;
    }
    this->board.resize(size_t(dim[0]));
    for(int i = 0; i < dim[0]; i++){
        this->board[i].resize(size_t(dim[1]));
    }
}

//this creates a machine with a default size vector of 2x3
Machine::Machine(){

}

Machine::~Machine(){

}

int Machine::spin(int wager){
    if(wager > balance) {
        cout << "YOU SUCK AND RAN OUTA MONEY BUTT MUNCH" << endl;
        return 0;
    } 
    this->balance = this->balance - wager;
    int result = 0;
    vector<string> symbolIcons = {"🌸","🔔","💎","🍒","🍆"};
    for(int i = 0; i < this->board.size(); i++){
        vector<Symbol*> row;
        for(int j = 0; j < this->board.at(i).size(); j++){
            Symbol* newSymb = new Symbol(symbolIcons[(rand() % symbolIcons.size())]);
            row.push_back(newSymb);
        }
        this->board[i] = row;
    }
    this->connectSymbols();
    int winMulti = this->scoreLines();
    if(winMulti >= 0) {
        result = wager * winMulti;
        this->balance += result;
    }
    else return 0;
    this->print();
    return result;
}

int Machine::scoreLines(){
    int totalWin = 0;
    for(int i = 0; i < this->board.size(); i++){
        Symbol* startSym = this->board.at(i).at(0);
        int upDiagCount = this->scoreDiag(startSym, startSym->getIcon(), 1,"up");
        int downDiagCount = this->scoreDiag(startSym, startSym->getIcon(), 1, "down");
        int rightCount = this->scoreRight(startSym, startSym->getIcon(), 1);
        int upZCount = this->scoreZ(startSym, startSym->getIcon(), 1, "up");
        int downZCount = this->scoreZ(startSym, startSym->getIcon(), 1, "down");

        if(upDiagCount > 3) totalWin += (upDiagCount - 3);
        if(downDiagCount > 3) totalWin += (downDiagCount - 3);
        if(rightCount > 3) totalWin += (rightCount - 3);
        if(upZCount > 3) totalWin += (upZCount - 3);
        if(downZCount > 3) totalWin += (downZCount - 3);
    }
    return totalWin;
}
int Machine::scoreRight(Symbol* cur, string target, int count){
      if (cur == nullptr || cur->getIcon() != target) {
          return count;
      }
      return scoreRight(cur->getRight(), target, count + 1);
}
int Machine::scoreDiag(Symbol* cur, string target, int count, string direction){
    if (cur == nullptr || cur->getIcon() != target) {
        return count;
    }
    if(direction == "down"){
        return scoreDiag(cur->getDown(), target, count + 1, direction);
    }else if(direction == "up"){
        return scoreDiag(cur->getUp(), target, count + 1, direction);
    }
    return count;
}
int Machine::scoreZ(Symbol* cur, string target, int count, string direction){
    if (cur == nullptr || cur->getIcon() != target) {
        return count;
    }
    if(direction == "down"){
        direction = "up";
        return scoreZ(cur->getDown(), target, count + 1, direction);
    }else if(direction == "up"){
        direction = "down";
        return scoreZ(cur->getUp(), target, count + 1, direction);
    }
    return count;
}
void Machine::connectSymbols(){
    for(int i = 0; i < this->board.size(); i++){
        for(int j = 0; j < this->board.at(i).size(); j++){
            if(i > 0 && j < (this->board.at(i).size() - 1)){
                this->board.at(i).at(j)->setUp(this->board.at(i-1).at(j + 1));
            }if(j < (this->board.at(i).size() - 1)){
                this->board.at(i).at(j)->setRight(this->board.at(i).at(j+1));
            }if(i < (this->board.size() - 1) && j < (this->board.at(i).size() - 1)){
                this->board.at(i).at(j)->setDown(this->board.at(i+1).at(j+1));
            }
        }
    }
}
void Machine::deposit(int depo){
    if(depo <= 0) return;
    this->balance += depo;
}

int Machine::cashout(){
    int cash = this->balance;
    this->balance = 0;
    return cash;
}
int Machine::getBalance(){
    return this->balance;
}
void Machine::print(){
    for(int i = 0; i < this->board.size(); i++){
        for(int j = 0; j < this->board.at(i).size(); j++){
            this->board.at(i).at(j)->print();
            cout << ":";
        }
        cout << endl;
    }
}