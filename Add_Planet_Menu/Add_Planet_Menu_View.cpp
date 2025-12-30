#include "Add_Planet_Menu_View.h"

Add_Planet_Menu_View::Add_Planet_Menu_View(const unsigned window_width, const unsigned window_height){
    this->window_width=window_width;
    this->window_height=window_height;
}

Add_Planet_Menu_View::~Add_Planet_Menu_View()=default;

void Add_Planet_Menu_View::draw(){
    DrawRectangle(this->window_width/4.f*3.f, 0.f, this->window_width/4.f, this->window_height, WHITE);
    DrawText("Add new planet to simulation.", this->window_width/4*3+20, 20, 15, GRAY);
    DrawText("Mass:", this->window_width/4*3+20, 80, 15, GRAY);
    DrawText("Radius:", this->window_width/4*3+20, 150, 15, GRAY);
    DrawText("Distance from center:", this->window_width/4*3+20, 230, 15, GRAY);
    DrawText("Velocity:", this->window_width/4*3+20, 400, 15, GRAY);
    DrawText("Color:", this->window_width/4*3+20, 580, 15, GRAY);
}