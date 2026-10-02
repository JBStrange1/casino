#include "User.h"
#include "Wallet.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

User::User(string userName, string password){
    int res = login(userName, password);
}
User::User(){
    
}
User::~User(){

}
int User::login(string userName, string password){
    ifstream f("userData.json");
    if(!f.is_open()) return -1;
    json data = json::parse(f);
    json Users = data.at("Users");
    f.close();
    try {
        for(int i = 0; i < Users.size(); i++){
            if(Users.at(i).at("userName") != userName) continue;
            else if(Users.at(i).at("password") == password){
                this->userName = userName;
                this->password = password;
                this->userWallet = new Wallet(Users.at(i).at("balance"));
                return 0; 
            }
        }
    }catch(exception e){
        cout << "Could Retrieve Users" << endl;
        return -1;
    }
    return -1;
}

void User::logout(){
    ifstream f("userData.json");
    if (!f.is_open()) return;
    try {
        json data = json::parse(f);
        f.close();
        json& users = data.at("Users");
        for (int i = 0; i < users.size(); i++) {
            if (users.at(i).at("userName") == this->userName) {
                users.at(i).at("balance") = this->getWallet()->getBalance();
                break;
            }
        }
        ofstream out("userData.json");
        if (!out.is_open()) return;
        out << data.dump(4);
    } catch (const exception& e) {
        cout << "Could not retrieve/write users" << endl;
        return;
    }
}

Wallet* User::getWallet(){
    return this->userWallet;
}