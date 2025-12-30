#ifndef SILDER_TEXTFIELD_MENU_CONTROLLER_H
#define SILDER_TEXTFIELD_MENU_CONTROLLER_H

#include "Slider_Textfield_Menu_Model.h"
#include "Slider_Textfield_Menu_View.h"

class Slider_Textfield_Menu_Controller{
    private:
    Slider_Textfield_Menu_Model *slider_model;
    Slider_Textfield_Menu_View *slider_view;
    bool is_textfield_chosen;
    char s[30];
    char s2[30];

    public:
    Slider_Textfield_Menu_Controller(const float, const float, const Rectangle&, const Rectangle&);

    ~Slider_Textfield_Menu_Controller();

    float getDirectValue() const;

    void setDirectValue(const float);

    void calcLogic();

    void requestDrawing();
};

#endif