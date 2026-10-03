#ifndef APP_H
#define APP_H

#include "Views/Logout/Logout.h"
#include "Views/Slot/Slot.h"
#include <ftxui/component/app.hpp>
#include <ftxui/ftxui.hpp>

class app
{
private:
    ftxui::Component view; 
public:
    app();
    ~app();
    void start();
};
#endif