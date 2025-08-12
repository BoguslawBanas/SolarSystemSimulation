#include "../header_files/simulation.h"

Simulation::Simulation(Universe *universe){
    this->universe=universe;
    this->state=RUN;
}

Simulation::~Simulation(){
    delete this->universe;
}

Simulation_State Simulation::getState() const{
    return this->state;
}

void Simulation::changeState(Simulation_State new_state){
    this->state=new_state;
}