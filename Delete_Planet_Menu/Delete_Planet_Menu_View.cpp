#include "Delete_Planet_Menu_View.h"

Delete_Planet_Menu_View::Delete_Planet_Menu_View(const unsigned window_width, const unsigned window_height){
    this->window_width=window_width;
    this->window_height=window_height;
}

Delete_Planet_Menu_View::~Delete_Planet_Menu_View()=default;

void Delete_Planet_Menu_View::drawMenu(){
    DrawRectangle(this->window_width/4.f*3.f, 0.f, this->window_width/4.f, this->window_height, WHITE);
    DrawText("Delete planets from the simulation.", this->window_width/4*3+20, 20, 15, GRAY);
}

void Delete_Planet_Menu_View::drawAcceptMenu(){
    DrawRectangle(this->window_width/4.f*3.f, 0.f, this->window_width/4.f, this->window_height, WHITE);
    DrawText("Do you want to accept erasing process?", this->window_width/4*3+20, this->window_height/2-30, 15, GRAY);
}