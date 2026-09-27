#include "Machine.h"
#include <iostream> 

using namespace std;
//The input is a touple of (rows, cols)
Machine::Machine(vector<int> dim){
    cout << "Welcome to the Strange slot" << endl;
    srand(time(nullptr));
    if(dim.size() > 2){
        cout << "Incorrect dimensions" << endl;
        return;
    }
    board.resize(size_t(dim[0]));
    for(int i = 0; i < dim[0]; i++){
        board[i].resize(size_t(dim[1]));
    }
}

//this creates a machine with a default size vector of 2x3
Machine::Machine(){

}

Machine::~Machine(){

}

void Machine::spin(){
    vector<string> symbolIcons = {"🌸","🔔","💎","🍒","🍆"};
    for(int i = 0; i < board.size(); i++){
        vector<Symbol*> row;
        for(int j = 0; j < board.at(i).size(); j++){
            row.push_back(new Symbol(symbolIcons[(rand() % symbolIcons.size())]));
        }
            board[i] = row;   
    }
    this->print();
}

void Machine::print(){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.at(i).size(); j++){
            board.at(i).at(j)->print();
            cout << ":";
        }
        cout << endl;
    }
}