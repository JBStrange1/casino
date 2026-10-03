#include "Login.h"
#include "ftxui/dom/elements.hpp"
#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>

void callLogin(User* user);

Login::Login(User* user){
    
    InputOption inOpt;
    inOpt.password = true;
    ButtonOption btnOpt;
    btnOpt.Border();
    btnOpt.label = "Login";
    btnOpt.on_click = [this, user]{
        int res = user->login(this->username, this->password);
        if(res == -1){
            this->statusStr = "Could Not login";
        }else{
            this->statusStr = "Login Sucessful";
        }
    };

    ButtonOption newUsrOpt;
    newUsrOpt.Border();
    newUsrOpt.label = "New User";
    
    this->userNameIn = Input(&this->username,"Enter Username");
    this->passwordIn = Input(&this->password,"Enter Password",inOpt);
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
            }),
            separatorEmpty(),
            separatorEmpty(),
            hbox({
                text(this->statusStr) | bold
            }) | border,
        }) | center | flex;
    });

    this->myComponent = renderer;
}
void callLogin(User* user){

}
Login::~Login()
{
}

Component Login::getComponent(){
    return this->myComponent;
}