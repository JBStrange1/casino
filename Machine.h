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
public:
    Machine(vector<int> dim);
    Machine();
    ~Machine();
    void print();
    void spin();
};

#endif