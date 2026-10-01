#include "User.h"
#include <sstream>

User::User(string userName, string password){

}
User::~User(){

}
int User::login(string userName, string password){
    ifstream file("users.txt");
    string line;
    if(file.is_open()){
        while (getline(file,line)){
            string token;
            stringstream ss(line);
            vector<string> lineArr;
            int count = 0;
            while(getline(ss, token, ';')){
                if(token == userName && count < 4){
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
    }
    this->password = password;
    this->userName = userName;
    return 0;
    file.close();
}
void ::User::logout(){
    //should probably do something like rerun login or something;
}