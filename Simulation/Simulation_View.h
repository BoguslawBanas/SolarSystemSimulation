#ifndef SIMULATION_VIEW_H
#define SIMULATION_VIEW_H

#include <raylib.h>

class Simulation_View{
    private:
    unsigned window_width;
    unsigned window_height;

    public:
    Simulation_View(const unsigned, const unsigned);

    ~Simulation_View();

    const unsigned getWindowWidth() const;
    
    const unsigned getWindowHeight() const;
};

#endif