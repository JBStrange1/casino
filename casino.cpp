#include <iostream> 
#include <vector>
#include <random>
#include <string>
#include <chrono>
#include "Machine.h"
#include "Wallet.h"

using namespace std;

int rungame(vector<int> dimensions);
void createMachine();

int main(){
    int balance = 100;
    Wallet* myWallet = new Wallet(balance);

    vector<int> dim = {10,20};
    int gameResult = rungame(dim);
    myWallet->deposit(gameResult);
}
int rungame(vector<int> dimensions){
    Machine* thisMachine = new Machine(dimensions);
    int deposit = 0;
    cout << "How many credits would you like to deposit? :";
    cin >> deposit;
    cout << endl;
    if(deposit < 1){
        cout << "Minimum deposit is 10 dollars" << endl;
        return 0;
    }
    thisMachine->deposit(deposit);

    int wager = 0;
    cout << "Enter your wager: ";
    cin >> wager;
    cout << endl;

    if(wager < 1){
        cout << "Sorry need to wager 1 or more dollars";
        return 0;
    }
    while(true){
        int result = thisMachine->spin(wager);
        if (result > (wager * 4)){
            cout << "BIG WIN!!!!" << endl;
        }else if(result > (wager * 2)) cout << "Alright win!" << endl;
        cout << "Win: " << result << " Balance: " << thisMachine->getBalance() << endl; 
        cout << "Would you like to spin again? <press enter> or type c to change bet" << endl;
        char input = cin.get();
        if(input == 'c') break;
    }
    return thisMachine->cashout();
}