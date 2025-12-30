#include "Simulation_View.h"

Simulation_View::Simulation_View(const unsigned window_width, const unsigned window_height){
    this->window_width=window_width;
    this->window_height=window_height;

    InitWindow(window_width, window_height, "Solar system simulation.");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
}

Simulation_View::~Simulation_View(){
    CloseWindow();
}

const unsigned Simulation_View::getWindowWidth() const{
    return this->window_width;
}

const unsigned Simulation_View::getWindowHeight() const{
    return this->window_height;
}