#include "../header_files/slider_textfield_menu.h"
#include "../header_files/raygui.h"

SliderTextfieldMenu::SliderTextfieldMenu(const Rectangle slider_bounds, const Rectangle textfield_bounds, const float min, const float max){
    this->slider_bounds=slider_bounds;
    this->textfield_bounds=textfield_bounds;
    this->slider_result=min;
    this->slider_min=min;
    this->slider_max=max;
    this->is_textfield_chosen=false;
}

SliderTextfieldMenu::~SliderTextfieldMenu()=default;

float SliderTextfieldMenu::getSliderResult() const{
    return this->slider_result;
}

void SliderTextfieldMenu::setSliderResult(const float new_value){
    this->slider_result=new_value;
}

void SliderTextfieldMenu::drawMenu(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMousePosition().x>this->textfield_bounds.x && GetMousePosition().y>this->textfield_bounds.y && GetMousePosition().x<this->textfield_bounds.x+this->textfield_bounds.width && GetMousePosition().y<this->textfield_bounds.y+this->textfield_bounds.height){
        this->is_textfield_chosen=true;
        for(int i=0;i<30;++i){
            s2[i]=s[i];
        }
    }
    else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        this->is_textfield_chosen=false;
    }

    if(this->is_textfield_chosen){
        if(GuiTextBox(this->textfield_bounds, s2, 30, true)==1){
            this->is_textfield_chosen=false;
        }
        this->slider_result=atof(s2);
    }
    else{
        GuiTextBox(this->textfield_bounds, s, 30, false);
        snprintf(s, 30, "%f", this->slider_result);
    }
    GuiSlider(this->slider_bounds, "0", "max", &this->slider_result, this->slider_min, this->slider_max);
}