#ifndef USER_H
#define USER_H

#include "Wallet.h"
#include <string>
#include <vector>
#include <fstream>
#include "Wallet.h"
#include <sstream>

using namespace std;

class User{
private:
    string userName;
    string password; 
    Wallet* userWallet;
public:
    User(string userName, string password);
    User();
    ~User();
    int login(string userName, string password);
    void logout();
    Wallet*getWallet();
};

#endif 