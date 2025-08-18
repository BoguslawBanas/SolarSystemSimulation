#include "../header_files/simulation.h"

int main(){
    const int width=1440;
    const int height=920;

    Simulation *simulation=new Simulation(width, height);

    while(simulation->getState()!=EXIT){
        simulation->calcLogic();
        simulation->drawSimulation();
    }

    delete simulation;
    return 0;
}