#include "app.h"
#include "Toolbar.h"
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>


app::app(){

}
app::~app(){

}
void app::start(){
    auto screen = App::Fullscreen();
    Toolbar* toolbar = new Toolbar();
    auto container = Container::Horizontal({toolbar->getComponent()});
    auto renderer = Renderer(container, [&] {
        return 
            hbox({
                vbox({
                    toolbar->getComponent()->Render()
                })
            });
    });
    screen.Loop(renderer);
}

void renderLogin(){

}
