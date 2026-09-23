#include <string>   
    
    
    
    symbol(string icon);
    ~symbol();
    symbol* getRight();
    symbol* getUp();
    symbol* getDown();
    string getIcon();

    void setRight(symbol* right);
    void setUp(symbol* up);
    void setDown(symbol* down);