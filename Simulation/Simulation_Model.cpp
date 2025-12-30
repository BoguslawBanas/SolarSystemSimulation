#include "Simulation_Model.h"

Simulation_Model::Simulation_Model(){
    this->simulation_state=START_MENU;
    this->start_sim=false;
    this->exit=false;
    this->settings=false;
    this->solar_system=false;
    this->free_mode=false;
    this->go_back=false;
    this->add_planet=false;
    this->delete_planet=false;
    this->pause-false;
    this->save_file=false;
    this->read_file=false;
}

Simulation_Model::~Simulation_Model()=default;

Simulation_State Simulation_Model::getState() const{
    return this->simulation_state;
}

void Simulation_Model::setState(Simulation_State new_state){
    this->simulation_state=new_state;
}

bool Simulation_Model::getStartSim() const{
    return this->start_sim;
}

void Simulation_Model::setStartSim(const bool new_value){
    this->start_sim=new_value;
}

bool Simulation_Model::getExit() const{
    return this->exit;
}

void Simulation_Model::setExit(const bool new_value){
    this->exit=new_value;
}

bool Simulation_Model::getSettings() const{
    return this->settings;
}

void Simulation_Model::setSettings(const bool new_value){
    this->settings=new_value;
}

bool Simulation_Model::getSolarSystem() const{
    return this->solar_system;
}

void Simulation_Model::setSolarSystem(const bool new_value){
    this->solar_system=new_value;
}

bool Simulation_Model::getFreeMode() const{
    return this->free_mode;
}

void Simulation_Model::setFreeMode(const bool new_value){
    this->free_mode=new_value;
}

bool Simulation_Model::getGoBack() const{
    return this->go_back;
}

void Simulation_Model::setGoBack(const bool new_value){
    this->go_back=new_value;
}

bool Simulation_Model::getAddPlanet() const{
    return this->add_planet;
}

void Simulation_Model::setAddPlanet(const bool new_value){
    this->add_planet=new_value;
}

bool Simulation_Model::getDeletePlanet() const{
    return this->delete_planet;
}

void Simulation_Model::setDeletePlanet(const bool new_value){
    this->delete_planet=new_value;
}

bool Simulation_Model::getPause() const{
    return this->pause;
}

void Simulation_Model::setPause(const bool new_value){
    this->pause=new_value;
}

bool Simulation_Model::getSaveFile() const{
    return this->save_file;
}

void Simulation_Model::setSaveFile(const bool new_value){
    this->save_file=new_value;
}

bool Simulation_Model::getReadFile() const{
    return this->read_file;
}

void Simulation_Model::setReadFile(const bool new_value){
    this->read_file=new_value;
}