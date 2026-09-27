#include <iostream> 
#include <vector>
#include <random>
#include <string>
#include <thread>
#include <chrono>
#include "Machine.h"

using namespace std;

int rungame(int credits);
void createMachine();
void test();

int main(){
    int credits = 100;
    while(true){
        credits = rungame(credits);
        cin.get();
    }
    test();
}
int rungame(int credits){
    
}

void test(){
    vector<int> dim = {4,5};

    Machine* thisMachine = new Machine(dim);
    thisMachine->print();
}

