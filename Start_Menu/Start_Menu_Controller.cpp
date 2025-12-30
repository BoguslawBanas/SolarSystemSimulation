#include "Start_Menu_Controller.h"

Start_Menu_Controller::Start_Menu_Controller(const unsigned window_width, const unsigned window_height){
    this->state=START_MENU1;
    this->model=new Start_Menu_Model(window_width, window_height);
    this->view=new Start_Menu_View();
}

Start_Menu_Controller::~Start_Menu_Controller(){
    delete this->model;
    delete this->view;
}

const Start_Menu_State Start_Menu_Controller::getState() const{
    return this->state;
}

void Start_Menu_Controller::calcLogic(){
    switch(this->state){
        case START_MENU1:{
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton1())){
                this->state=START_MENU2;
            }
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton2())){

            }
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton3())){

            }
        } break;
        case START_MENU2:{
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton1())){
                this->state=TRANSITION_TO_SIMULATION;
            }
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton2())){

            }
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton3())){

            }
        } break;
    }
}

void Start_Menu_Controller::requestDrawing(){
    switch(this->state){
        case START_MENU1:{
            this->view->drawStartMenu1(this->model->getButton1(), this->model->getButton2(), this->model->getButton3());
        } break;
        case START_MENU2:{
            this->view->drawStartMenu2(this->model->getButton1(), this->model->getButton2(), this->model->getButton3());
        } break;
    }
}