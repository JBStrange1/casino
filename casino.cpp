#include <iostream> 
#include <vector>
#include <random>
#include <string>
#include <thread>
#include <chrono>
#include "symbol.h"

using namespace std;

int rungame(int credits);
void createMachine();

int main(){
    int credits = 100;
    srand(time(nullptr));
    while(true){
        credits = rungame(credits);
        cin.get();
    }
}
int rungame(int credits){
    if(credits <= 9){
        cout << "Sorry not enough credits \n";
        return credits;
    }

    credits -= 10;
    vector<string> symbols = {"🌸","🔔","💎","🍒","🍆"};
    string symbol1 = symbols[rand() % symbols.size()];
    string symbol2 = symbols[rand() % symbols.size()];
    string symbol3 = symbols[rand() % symbols.size()];

    for (int i = 0; i < 14; i++) {
        cout << symbols[rand() % symbols.size()] << " : " << symbols[rand() % symbols.size()] << " : " << symbols[rand() % symbols.size()] << "     \n" << flush;
        if ((i + 1) % 3 == 0 ) {
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "\033[3F";
        }
    }

    cout << symbol1 << " : " << symbol2 << " : " << symbol3 << "     " << endl;

    if(symbol1 == symbol2 && symbol1 == symbol3){
        credits += 200;
        cout << "Congratulations :) Credits left: " << credits << endl;
    }else{
        cout << "Sorry try again :( Credits left: " << credits << endl;
    }
    return credits;
}

void createMachine(int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; i++){
            
        }
    }
}


