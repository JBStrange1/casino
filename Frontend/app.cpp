#include "app.h"
#include "Toolbar.h"
#include "Footer.h"
#include "Login.h"
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>


app::app(){

}
app::~app(){

}
void app::start(){
    auto screen = App::Fullscreen();
    User* thisUser = new User();
    Toolbar* toolbar = new Toolbar();
    Footer* footer = new Footer();
    Login* login = new Login(thisUser);
    
    auto container = Container::Horizontal({
        toolbar->getComponent(),
        login->getComponent(),
    });
    auto renderer = Renderer(container, [&] {
        return 
            vbox({
                toolbar->getComponent()->Render(),
                login->getComponent()->Render(),
                separator() ,
                footer->getElement()
            }) | flex;
    });
    screen.Loop(renderer);
} 