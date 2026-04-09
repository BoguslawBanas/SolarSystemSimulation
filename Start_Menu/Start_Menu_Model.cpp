#include "Start_Menu_Model.h"

Start_Menu_Model::Start_Menu_Model(const unsigned window_width, const unsigned window_height){
    this->button1_bounds=Rectangle{50.f, 4.f*window_height/8.f, 200.f, 100.f};
    this->button2_bounds=Rectangle{50.f, 5.f*window_height/8.f, 200.f, 100.f};
    this->button3_bounds=Rectangle{50.f, 6.f*window_height/8.f, 200.f, 100.f};
}

Start_Menu_Model::~Start_Menu_Model()=default;

const Rectangle& Start_Menu_Model::getButton1() const{
    return this->button1_bounds;
}

const Rectangle& Start_Menu_Model::getButton2() const{
    return this->button2_bounds;
}

const Rectangle& Start_Menu_Model::getButton3() const{
    return this->button3_bounds;
}