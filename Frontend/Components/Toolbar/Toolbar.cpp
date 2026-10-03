#include "Toolbar.h"
#include <string>

Toolbar::Toolbar(function<void(string)> callback){
    auto option = MenuOption::HorizontalAnimated();
    option.underline.SetAnimation(std::chrono::milliseconds(1000), animation::easing::ElasticOut);
    option.on_change = [this, callback] {
         callback(this->entries[this->selected]);
    };
    option.entries_option.transform = [&](EntryState state) {
        Element e = text(state.label) | hcenter | flex;
        if (state.active && state.focused) {
            e = e | bold;
        }
        if (!state.focused && !state.active) {
            e = e | dim;
        }
        return e;
    };
    option.underline.color_inactive = Color::Default;
    option.underline.color_active = Color::Red;
    this->myComponent = Menu(this->entries, &this->selected ,option) | xflex; 
}

Component Toolbar::getComponent(){
    return this->myComponent;
}