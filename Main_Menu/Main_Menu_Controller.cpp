#include "Main_Menu_Controller.h"

Main_Menu_Controller::Main_Menu_Controller(const unsigned window_width, const unsigned window_height){
    this->menu_model=new Main_Menu_Model(Rectangle{30, 850, 100, 30});
    this->menu_view=new Main_Menu_View();
    this->slider=new Slider_Textfield_Menu_Controller(0.f, 100.f, Rectangle{window_width/3.f, 30, 100.f+window_width/6.f, 50}, Rectangle{window_width/2.f+150.f, 40, window_width/10.f, 30});
    this->is_camera_locked=false;
    this->is_simulation_paused=false;
    this->add_new_planet=false;
    this->tmp_v=0.f;
}

Main_Menu_Controller::~Main_Menu_Controller(){
    delete this->slider;
    delete this->menu_view;
}

float Main_Menu_Controller::getSliderResult() const{
    return this->slider->getDirectValue();
}

void Main_Menu_Controller::lockUnlockCamera(){
    this->is_camera_locked=!this->is_camera_locked;
}

bool Main_Menu_Controller::getIsCameraLocked() const{
    return this->is_camera_locked;
}

void Main_Menu_Controller::pauseUnpauseSimulation(){
    //change later
    this->is_simulation_paused=!this->is_simulation_paused;
    float tmp_v2=this->slider->getDirectValue();

    if(this->is_simulation_paused){
        this->slider->setDirectValue(0.f);
    }
    else{
        this->slider->setDirectValue(tmp_v);
    }
    
    tmp_v=tmp_v2;
}

bool Main_Menu_Controller::getIsAddNewPlanetButtonClicked() const{
    // return GuiButton(Rectangle{30, 850, 100, 30}, "Add new planet.");
    const Rectangle bounds=this->menu_model->getPlanetButtonBounds();
    const unsigned mouse_position_x=GetMousePosition().x;
    const unsigned mouse_position_y=GetMousePosition().y;
    return (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mouse_position_x>=bounds.x && mouse_position_x<=bounds.x+bounds.width && mouse_position_y>=bounds.y && mouse_position_y<=bounds.y+bounds.width);
}

void Main_Menu_Controller::calcLogic(){
    if(IsKeyPressed(KEY_L)){
        this->lockUnlockCamera();
    }
    if(IsKeyPressed(KEY_P)){
        this->pauseUnpauseSimulation();
    }
    this->slider->calcLogic();
}

void Main_Menu_Controller::requestDrawing(){
    this->slider->requestDrawing();
    this->menu_view->draw(this->is_camera_locked, this->menu_model->getPlanetButtonBounds());
}