#include "symbol.h"

using namespace std;

class symbol
{
private:
    string icon;
    symbol* right;
    symbol* up;
    symbol* down;

public:
    symbol(string icon);
    ~symbol();
    symbol* getRight();
    symbol* getUp();
    symbol* getDown();
    string getIcon();

    void setRight(symbol* right);
    void setUp(symbol* up);
    void setDown(symbol* down);
};
void symbol::setRight(symbol* right){
    this->right = right;
}   
void symbol::setDown(symbol* up){
    this->up = up;
}
void symbol::setUp(symbol* down){
    this->down = down;
}
string symbol::getIcon(){
    return this->icon;
}
symbol* symbol::getRight(){
    return this->right;
}
symbol* symbol::getUp(){
    return this->up;
}
symbol* symbol::getDown(){
    return this->down;
}

symbol::symbol(string icon)
{
    this->icon = icon;
    this->right = nullptr;
    this->down = nullptr;
    this->up = nullptr;
}

symbol::~symbol()
{
}