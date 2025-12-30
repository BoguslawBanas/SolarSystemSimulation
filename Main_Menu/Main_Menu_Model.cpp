#include "Main_Menu_Model.h"

Main_Menu_Model::Main_Menu_Model(const Rectangle &add_planet_button_bounds){
    this->add_planet_button_bounds=add_planet_button_bounds;
}

Main_Menu_Model::~Main_Menu_Model()=default;

Rectangle Main_Menu_Model::getPlanetButtonBounds() const{
    return this->add_planet_button_bounds;
}