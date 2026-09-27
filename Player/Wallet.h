#ifndef WALLET_H
#define WALLET_H


class Wallet
{
private:
    int balance;
public:
    void deposit(int deposit);
    Wallet();
    Wallet(int initDepo);
    ~Wallet();
    int getBalance();
};

#endif