#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

class symbol
{
private:
    std::string icon;

    symbol* right;
    symbol* up;
    symbol* down;

public:
    symbol(std::string icon);
    ~symbol();

    symbol* getRight();
    symbol* getUp();
    symbol* getDown();
    std::string getIcon();

    void setRight(symbol* right);
    void setUp(symbol* up);
    void setDown(symbol* down);
};

#endif