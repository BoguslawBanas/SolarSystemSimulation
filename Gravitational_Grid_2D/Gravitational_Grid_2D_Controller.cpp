#include "Gravitational_Grid_2D_Controller.h"

Gravitational_Grid_2D_Controller::Gravitational_Grid_2D_Controller(const double start_position, const unsigned amount_of_nodes, const double default_height_of_the_grid, const double distance_divider){
    this->model=new Gravitational_Grid_2D_Model(start_position, amount_of_nodes, default_height_of_the_grid);
    this->view=new Gravitational_Grid_2D_View(distance_divider);
}

Gravitational_Grid_2D_Controller::~Gravitational_Grid_2D_Controller(){
    delete this->model;
    delete this->view;
}

void Gravitational_Grid_2D_Controller::calcLogic(const std::vector<Planet_Model*>&planets){
    this->model->calcLogic(planets);
}

void Gravitational_Grid_2D_Controller::requestDrawing(){
    this->view->draw(this->model->getStartPosition(), this->model->getAmountOfNodes(), this->model->getGridDelta(), this->model->getGrid());
}