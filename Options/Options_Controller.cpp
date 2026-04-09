#include "Options_Controller.h"

Options_Controller::Options_Controller(){
    this->model=new Options_Model();
    this->view=new Options_View();
}

Options_Controller::~Options_Controller(){
    delete this->model;
    delete this->view;
}

void Options_Controller::requestDrawing(){
    this->view->draw();
}