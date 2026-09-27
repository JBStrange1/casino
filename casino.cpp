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

int main(){
    int credits = 100;
    vector<int> dim = {4,5};
    Machine* thisMachine = new Machine(dim);
    while(true){
        thisMachine->spin();
        cin.get();
    }
}
int rungame(int credits){

    return credits;
}

