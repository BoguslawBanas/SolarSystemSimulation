#include "Main_Menu_Model.h"

Main_Menu_Model::Main_Menu_Model(const Rectangle &add_new_planet_button_rectangle, const Rectangle &delete_planet_button_rectangle){
    this->add_planet_button_bounds=add_new_planet_button_rectangle;
    this->delete_planet_button_bounds=delete_planet_button_rectangle;
}

Main_Menu_Model::~Main_Menu_Model()=default;

Rectangle Main_Menu_Model::getAddPlanetButtonBounds() const{
    return this->add_planet_button_bounds;
}

Rectangle Main_Menu_Model::getDeletePlanetButtonBounds() const{
    return this->delete_planet_button_bounds;
}