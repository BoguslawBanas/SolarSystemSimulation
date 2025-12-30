#include "Slider_Textfield_Menu_Controller.h"

Slider_Textfield_Menu_Controller::Slider_Textfield_Menu_Controller(const float min_v, const float max_v, const Rectangle &slider_bounds, const Rectangle &text_bounds){
    this->is_textfield_chosen=false;
    this->slider_model=new Slider_Textfield_Menu_Model(min_v, max_v);
    this->slider_view=new Slider_Textfield_Menu_View(slider_bounds, text_bounds);
    snprintf(s, 30, "%f", this->slider_model->getSliderResult());
    snprintf(s2, 30, "%f", this->slider_model->getSliderResult());
}

Slider_Textfield_Menu_Controller::~Slider_Textfield_Menu_Controller(){
    delete this->slider_model;
    delete this->slider_view;
}

float Slider_Textfield_Menu_Controller::getDirectValue() const{
    return this->slider_model->getSliderResult();
}

void Slider_Textfield_Menu_Controller::setDirectValue(const float new_value){
    this->slider_model->setDirectValue(new_value);
}

void Slider_Textfield_Menu_Controller::calcLogic(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && 
        GetMousePosition().x>this->slider_view->getTextBounds().x &&
        GetMousePosition().x<this->slider_view->getTextBounds().x+this->slider_view->getTextBounds().width &&
        GetMousePosition().y>this->slider_view->getTextBounds().y &&
        GetMousePosition().y<this->slider_view->getTextBounds().y+this->slider_view->getTextBounds().height){
            snprintf(s2, 30, "%f", this->slider_model->getSliderResult());
            this->is_textfield_chosen=true;
    }
    else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        this->is_textfield_chosen=false;
    }

    if(this->is_textfield_chosen){
        this->slider_model->setDirectValue(atof(this->s2));
    }
    else{
        snprintf(s, 30, "%f", this->slider_model->getSliderResult());
    }
}

void Slider_Textfield_Menu_Controller::requestDrawing(){
    this->slider_view->draw(is_textfield_chosen, *slider_model->getSliderResultPointer(), slider_model->getSliderMin(), slider_model->getSliderMax(), s, s2);
}