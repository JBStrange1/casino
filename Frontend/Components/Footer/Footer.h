#ifndef FOOTER_H
#define FOOTER_H
#include <ftxui/component/app.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/ftxui.hpp> 

using namespace ftxui;

class Footer{
private:
    Element myElement;
public:
    Footer();
    ~Footer();
    Element getElement();
};

#endif