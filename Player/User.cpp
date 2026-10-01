#include "User.h"
#include <iostream>
User::User(string userName, string password){

}
User::User(){

}
User::~User(){

}
int User::login(string userName, string password){
    ifstream file("users.txt");
    string line;
    vector<string> lineArr;
    bool foundUser = false;
    int count = 0;
    if(file.is_open()){
        while (getline(file,line)){
            string token; 
            stringstream ss(line);
            while(getline(ss, token, ';')){
                
                if((token == userName || foundUser) && count < 4){
                    foundUser = true;
                    lineArr.push_back(token);
                    count++;
                }
                if(count == 3){
                    break;
                }
            }
            if(count == 0){
                return -1;
            }
        }
    }else{
        cout << "could not open file" << endl;
    }
    this->password = password;
    this->userName = userName;
    cout << lineArr.size();
    if(count == 3) this->userWallet = new Wallet(stoi(lineArr.at(2)));
    return 0;
    file.close();
}
void ::User::logout(){
    //should probably do something like rerun login or something;
}

Wallet* User::getWallet(){
    return this->userWallet;
}