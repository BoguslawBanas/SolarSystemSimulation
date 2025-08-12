#ifndef SIMULATION_H
#define SIMULATION_H

#include "universe.h"

enum Simulation_State{
    RUN,
    PAUSE
};

class Simulation{
    private:
    Universe *universe;
    Simulation_State state;

    Simulation(Universe*);

    ~Simulation();

    Simulation_State getState() const;

    void changeState(Simulation_State);
};

#endif