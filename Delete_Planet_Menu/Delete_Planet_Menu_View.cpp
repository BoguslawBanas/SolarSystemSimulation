#include "Delete_Planet_Menu_View.h"

Delete_Planet_Menu_View::Delete_Planet_Menu_View(const unsigned window_width, const unsigned window_height){
    this->window_width=window_width;
    this->window_height=window_height;
}

Delete_Planet_Menu_View::~Delete_Planet_Menu_View()=default;

void Delete_Planet_Menu_View::draw(){
    DrawRectangle(this->window_width/4.f*3.f, 0.f, this->window_width/4.f, this->window_height, WHITE);
}