#include "Slider_Textfield_Menu_View.h"

Slider_Textfield_Menu_View::Slider_Textfield_Menu_View(const Rectangle &slider_bounds, const Rectangle &text_bounds){
    this->slider_bounds=slider_bounds;
    this->text_bounds=text_bounds;
}

Slider_Textfield_Menu_View::~Slider_Textfield_Menu_View()=default;

const Rectangle& Slider_Textfield_Menu_View::getTextBounds() const{
    return this->text_bounds;
}

const Rectangle& Slider_Textfield_Menu_View::getSliderBounds() const{
    return this->slider_bounds;
}

void Slider_Textfield_Menu_View::draw(bool &is_textfield_chosen, float &value, const float min, const float max, char s[], char s2[]){
    if(is_textfield_chosen){
        if(GuiTextBox(this->getTextBounds(), s2, 30, true)==1){
            is_textfield_chosen=false;
        }
    }
    else{
        GuiTextBox(this->getTextBounds(), s, 30, false);
    }
    GuiSlider(this->slider_bounds, "min", "max", &value, min, max);
}