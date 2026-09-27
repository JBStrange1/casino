#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>
using namespace std;

class Symbol
{
private:
    std::string icon;

    Symbol* right;
    Symbol* up;
    Symbol* down;

public:
    Symbol(std::string icon);
    ~Symbol();

    Symbol* getRight();
    Symbol* getUp();
    Symbol* getDown();
    std::string getIcon();

    void print();
    void setRight(Symbol* right);
    void setUp(Symbol* up);
    void setDown(Symbol* down);
};

#endif