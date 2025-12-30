#include "Slider_Textfield_Menu_Model.h"

Slider_Textfield_Menu_Model::Slider_Textfield_Menu_Model(const float min_value, const float max_value){
    this->slider_min=min_value;
    this->slider_max=max_value;
    this->slider_result=1.f;
}

Slider_Textfield_Menu_Model::~Slider_Textfield_Menu_Model()=default;

const float Slider_Textfield_Menu_Model::getSliderMax() const{
    return this->slider_max;
}

const float Slider_Textfield_Menu_Model::getSliderMin() const{
    return this->slider_min;
}

const float Slider_Textfield_Menu_Model::getSliderResult() const{
    return this->slider_result;
}

float* Slider_Textfield_Menu_Model::getSliderResultPointer(){
    return &this->slider_result;
}

void Slider_Textfield_Menu_Model::setDirectValue(const float new_value){
    this->slider_result=new_value;
}

void Slider_Textfield_Menu_Model::updateNextFrame(const float value){ //check later

}