#include "Symbol.h"

using namespace std;

void Symbol::setRight(Symbol* right){
    this->right = right;
}   
void Symbol::setUp(Symbol* up){
    this->up = up;
}
void Symbol::setDown(Symbol* down){
    this->down = down;
}
string Symbol::getIcon(){
    return this->icon;
}
Symbol* Symbol::getRight(){
    return this->right;
}
Symbol* Symbol::getUp(){
    return this->up;
}
Symbol* Symbol::getDown(){
    return this->down;
}
void Symbol::print(){
    cout << this->icon ;
}
Symbol::Symbol(string icon)
{
    this->icon = icon;
    this->right = nullptr;
    this->down = nullptr;
    this->up = nullptr;
}

Symbol::~Symbol()
{
}