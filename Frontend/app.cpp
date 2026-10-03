#include "app.h"
#include "Toolbar.h"
#include "Footer.h"
#include "Login.h"
#include "Slot.h"
#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <map>
#include <string>


app::app(){

}
app::~app(){

}
void app::start(){
    auto emptyView = Renderer([] {
         return text("EMPTY VIEW") | center | flex;
    });
    map<string, Component> componentMap;
    componentMap["Slot Machine"] = emptyView;
    componentMap["Roulette"] = emptyView;
    componentMap["BlackJack"] = emptyView;
    componentMap["Profile"] = emptyView; 
    
    this->view = emptyView;
    bool isLoggedIn = false; 
    auto screen = App::Fullscreen();
    User* thisUser = new User();
    Toolbar* toolbar = new Toolbar([this ,&componentMap](string view){
        this->view = componentMap[view];
    });
    Footer* footer = new Footer();
    Login* login = new Login(thisUser, [&] {
        isLoggedIn = true;
    });
    
    auto container = Container::Horizontal({
        toolbar->getComponent(),
        login->getComponent(),
    });
    auto renderer = Renderer(container, [&] {
        if(!isLoggedIn){
            return 
                vbox({
                    toolbar->getComponent()->Render(),
                    login->getComponent()->Render(),
                    separator() ,
                    footer->getElement()
                }) | flex;
        }else{
            return 
                vbox({
                    toolbar->getComponent()->Render(),
                    this->view->Render(), // return the current
                    separator() ,
                    footer->getElement()
                }) | flex;
        }
    });
    screen.Loop(renderer);
} 