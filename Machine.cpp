#include "Machine.h"
#include <iostream> 

using namespace std;
//The input is a touple of (rows, cols)
Machine::Machine(vector<int> dim){
    srand(time(nullptr));
    vector<string> symbolIcons = {"🌸","🔔","💎","🍒","🍆"};
    if(dim.size() > 2){
        cout << "Incorrect dimensions" << endl;
        return;
    }
    for(int i = 0; i < dim[0]; i++){
        vector<Symbol*> row;
        for(int j = 0; j < dim[1]; j++){
            row.push_back(new Symbol(symbolIcons[(rand() % symbolIcons.size())]));
        }
            board.push_back(row);   
    }
    
}
void Machine::print(){
    cout << "Welcome to the Strange slot" << endl;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.at(i).size(); j++){
            board.at(i).at(j)->print();
            cout << ":";
        }
        cout << endl;
    }
}
void initBoard(){

}
//this creates a machine with a default size vector of 2x3
Machine::Machine(){

}

Machine::~Machine(){

}

void Machine::spin(){

}