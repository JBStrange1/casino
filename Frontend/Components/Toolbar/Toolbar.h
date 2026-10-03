#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <ftxui/component/app.hpp>
#include <ftxui/ftxui.hpp>
#include <string>
#include <vector>

using namespace ftxui;
using namespace std;

class Toolbar
{
private:
    Component myComponent; 
    vector<string> entries{"Slot Machine", "Roulette","BlackJack", "Profile"};
    int selected = 0;
public:
    Toolbar();
    ~Toolbar();
    Component getComponent();
};
#endif