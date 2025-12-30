#define RAYGUI_IMPLEMENTATION

#include "Simulation/Simulation_Controller.h"
#include <rlgl.h>

int main(){
    // rlSetClipPlanes(1.0, 1000.0);
    // const unsigned width=1440;
    // const unsigned height=920;

    const char *path="simulation_settings.conf";

    Simulation_Controller *simulation=new Simulation_Controller(path);

    simulation->simulationLoop();

    delete simulation;
    return 0;
}