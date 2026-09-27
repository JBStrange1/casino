#include "Wallet.h"

Wallet::Wallet(){
    this->balance = 0;
}
Wallet::Wallet(int initDepo){
    this->balance = initDepo;
}
Wallet::~Wallet(){
}
int Wallet::getBalance(){
    return this->balance;
}
void Wallet::deposit(int deposit){
    if(deposit <= 0){
        return;    
    }
    this->balance += deposit;
}