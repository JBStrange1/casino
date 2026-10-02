#include "Footer.h"
#include "ftxui/dom/elements.hpp"
#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

Footer::Footer(){
    this->myElement = hbox({
        text("This is a casino(Made by John Strange)") | hcenter | border | xflex
    });
}
Element Footer::getElement(){
    return this->myElement;
}