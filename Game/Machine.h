#ifndef MACHINE_H
#define MACHINE_H

#include "Symbol.h"
#include <vector>
#include <string>

using namespace std;

class Machine
{
private:
    vector<vector<Symbol*>> board;
    int balance; 
    void print();
    void connectSymbols();
    int scoreLines();
    int scoreRight(Symbol* current, string target, int count);
    int scoreDiag(Symbol* current, string target, int count, string direction);
    int scoreZ(Symbol* current, string target, int count, string direction);

public:
    Machine(vector<int> dim);
    Machine();
    ~Machine();
    void deposit(int depo);
    int cashout();
    int spin(int wager);
};

#endif 