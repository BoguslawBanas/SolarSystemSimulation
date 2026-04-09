#include "Start_Menu_Controller.h"

Start_Menu_Controller::Start_Menu_Controller(const unsigned window_width, const unsigned window_height){
    this->state=START_MENU1;
    this->model=new Start_Menu_Model(window_width, window_height);
    this->view=new Start_Menu_View();
    this->options=NULL;
    this->camera.fovy=45.f;
    this->camera.position=Vector3{-150.f, 80.f, -150.f};
    this->camera.projection=0;
    this->camera.target=Vector3{30.f, 0.f, 30.f};
    this->camera.up=Vector3{0.f, 1.f, 0.f};
    this->counter=0;
    this->alpha_counter=0;
}

Start_Menu_Controller::~Start_Menu_Controller(){
    delete this->model;
    delete this->view;
}

const Start_Menu_State Start_Menu_Controller::getState() const{
    return this->state;
}

void Start_Menu_Controller::calcLogic(){
    ++this->counter;
    this->counter%=5000;
    if(this->counter<2500){
        this->camera.target.x-=0.01f;
    }
    else{
        this->camera.target.x+=0.01f;
    }
    switch(this->state){
        case START_MENU1:{
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton1())){
                this->state=TRANSITION_TO_START_MENU2;
            }
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton2())){
                this->state=TRANSITION_TO_START_MENU_SETTINGS;
            }
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton3())){
                this->state=START_MENU_EXIT;
            }

            if(this->options){
                this->options->requestDrawing();
            }
        } break;
        case TRANSITION_TO_START_MENU1:{
            ++this->alpha_counter;
            if(alpha_counter>80){
                this->state=START_MENU1;
                this->alpha_counter=0;
            }
        } break;
        case START_MENU2:{
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton1())){
                this->state=TRANSITION_TO_SIMULATION;
            }
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton2())){
                this->state=TRANSITION_TO_SIMULATION_FREE_MODE;
            }
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isPointInsideRectangle(GetMousePosition(), this->model->getButton3())){
                this->state=TRANSITION_TO_START_MENU1;
            }
        } break;
        case TRANSITION_TO_START_MENU2:{
            ++this->alpha_counter;
            if(alpha_counter>80){
                this->state=START_MENU2;
                this->alpha_counter=0;
            }
        } break;
        case TRANSITION_TO_START_MENU_SETTINGS:{
            this->options=new Options_Controller();
            this->state=START_MENU_SETTINGS;
        } break;
    }
}

void Start_Menu_Controller::requestDrawing(){
    switch(this->state){
        case START_MENU1:{
            this->view->drawStartMenu1(this->model->getButton1(), this->model->getButton2(), this->model->getButton3(), this->camera, 1.f);
        } break;
        case TRANSITION_TO_START_MENU1:{
            if(this->alpha_counter<40){
                this->view->drawStartMenu2(this->model->getButton1(), this->model->getButton2(), this->model->getButton3(), this->camera, 1.f-this->alpha_counter/40.f);
            }
            else{
                this->view->drawStartMenu1(this->model->getButton1(), this->model->getButton2(), this->model->getButton3(), this->camera, this->alpha_counter/40.f-1.f);
            }
        } break;
        case START_MENU2:{
            this->view->drawStartMenu2(this->model->getButton1(), this->model->getButton2(), this->model->getButton3(), this->camera, 1.f);
        } break;
        case TRANSITION_TO_START_MENU2:{
            if(this->alpha_counter<40){
                this->view->drawStartMenu1(this->model->getButton1(), this->model->getButton2(), this->model->getButton3(), this->camera, 1.f-this->alpha_counter/40.f);
            }
            else{
                this->view->drawStartMenu2(this->model->getButton1(), this->model->getButton2(), this->model->getButton3(), this->camera, this->alpha_counter/40.f-1.f);
            }
        } break;
        case START_MENU_SETTINGS:{
            this->options->requestDrawing();
        } break; 
    }
}