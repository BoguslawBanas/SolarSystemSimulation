#define RAYGUI_IMPLEMENTATION

#include "../header_files/simulation.h"

int main(){
    Simulation *simulation=new Simulation("../simulation_settings.conf");

    while(simulation->getState()!=EXIT){
        simulation->calcLogic();
        simulation->drawSimulation();
    }

    delete simulation;
    return 0;
}