#ifndef SLIDER_TEXTFIELD_MENU_VIEW_H
#define SLIDER_TEXTFIELD_MENU_VIEW_H

#include <raylib.h>
#include <stdlib.h>
#include <string>
#include "../header_files/raygui.h"

class Slider_Textfield_Menu_View{
    private:
    Rectangle slider_bounds;
    Rectangle text_bounds;

    public: 
    Slider_Textfield_Menu_View(const Rectangle&, const Rectangle&);

    ~Slider_Textfield_Menu_View();

    const Rectangle& getSliderBounds() const;

    const Rectangle& getTextBounds() const;

    void draw(bool&, float&, const float, const float, char[], char[]);
};

#endif