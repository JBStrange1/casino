#ifndef LOGIN_H
#define LOGIN_H

#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/ftxui.hpp>
#include "User.h"

using namespace ftxui;

class Login
{
private:
    string statusStr;
    string username;
    string password;
    Element status; 
    Component myComponent;
    Component userNameIn;
    Component passwordIn;
    Component loginBtn;
    Component newUsrBtn;
public:
    Login(User* thisUser);
    ~Login();
    Component getComponent();
};
#endif