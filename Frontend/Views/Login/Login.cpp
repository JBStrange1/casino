#include "Login.h"
#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/dom/elements.hpp>

Login::Login(User* thisUser){
    string username;
    string password;
    
    InputOption inOpt;
    inOpt.password = true;
    
    ButtonOption btnOpt;
    btnOpt.Border();
    btnOpt.label = "Login";
    
    ButtonOption newUsrOpt;
    newUsrOpt.Border();
    newUsrOpt.label = "New User";
    
    this->userNameIn = Input(username,"Enter Username");
    this->passwordIn = Input(password,"Enter Passwordd",inOpt);
    
    this->loginBtn = Button(btnOpt);
    this->newUsrBtn = Button(newUsrOpt);
    auto container = Container::Vertical({
        userNameIn,
        passwordIn,
        loginBtn,
        newUsrBtn
    });

    auto renderer = Renderer(container,[&]{
        return vbox({
            filler(),
            userNameIn->Render(),
            separatorEmpty(),
            passwordIn->Render(),
            separatorEmpty(),
            separatorEmpty(),
            hbox({
                loginBtn->Render(),
                text("   "),
                newUsrBtn->Render()
            })
        }) | center | flex;
    });
    this->myComponent = renderer;
}

Login::~Login()
{
}

Component Login::getComponent(){
    return this->myComponent;
}