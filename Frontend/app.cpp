#include "app.h"
#include "Toolbar.h"
#include "Footer.h"
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
    Footer* footer = new Footer();
    auto container = Container::Horizontal({toolbar->getComponent()}) ;
    auto renderer = Renderer(container, [&] {
        return 
            vbox({
                toolbar->getComponent()->Render() | xflex,
                filler() ,
                separator() ,
                footer->getElement() | xflex
            }) | flex;
    });
    screen.Loop(renderer);
}