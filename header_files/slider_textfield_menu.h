#ifndef SLIDER_TEXTFIELD_MENU_H
#define SLIDER_TEXTFIELD_MENU_H

#include <raylib.h>
#include <string>

class SliderTextfieldMenu{
    private:
    Rectangle slider_bounds;
    Rectangle textfield_bounds;
    float slider_result;
    float slider_min;
    float slider_max;
    char s[30];
    char s2[30];
    bool is_textfield_chosen;

    public:
    SliderTextfieldMenu(const Rectangle, const Rectangle, const float, const float);

    ~SliderTextfieldMenu();

    float getSliderResult() const;

    void drawMenu();
};

#endif