#include "machine.h"
#include "symbol.h"
#include <vector>
#include <string>

using namespace std;

class machine
{
private:
    vector<vector<symbol>> board;
public:
    machine(int dim[]);
    ~machine();
};

//The input is a touple of (rows, cols)
machine::machine(int dim[])
{
    if(sizeof(dim) > 8){
        return;
    }
    for(int i = 0; i < dim[0]; i++){
        for(int j = 0; i < dim[1]; j++){
            //make the constructor pick from the array of symbols a random one 
            // board[i][j] = new symbol()
        }
    }
}

machine::~machine()
{
}
