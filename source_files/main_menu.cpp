#include "../header_files/main_menu.h"

Main_Menu::Main_Menu(const unsigned window_width, const unsigned window_height){
    this->window_width=window_width;
    this->window_height=window_height;
    this->is_camera_locked=false;
    this->is_simulation_paused=false;
    this->speed_of_simulation_menu=new SliderTextfieldMenu((Rectangle){300, 24, 400, 30}, (Rectangle){750, 30, 150, 15}, 0.f, 100.f);
}

Main_Menu::~Main_Menu(){
    delete this->speed_of_simulation_menu;
}

bool Main_Menu::getIsCameraLocked() const{
    return this->is_camera_locked;
}

bool Main_Menu::getIsSimulationPaused() const{
    return this->is_simulation_paused;
}

float Main_Menu::getSpeed() const{
    if(this->speed_of_simulation_menu){
        return this->speed_of_simulation_menu->getSliderResult();
    }
    return 0.f;
}

void Main_Menu::changePauseSetting(){
    this->is_simulation_paused=!this->is_simulation_paused;
}

void Main_Menu::lockUnlockCamera(){
    this->is_camera_locked=!this->is_camera_locked;
}

void Main_Menu::drawMenu() const{
    this->speed_of_simulation_menu->drawMenu();
    if(this->is_camera_locked){
        DrawText("CAMERA LOCKED", 1000, 30, 15, RED);
    }
}