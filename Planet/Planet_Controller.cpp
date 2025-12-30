#include "Planet_Controller.h"

Planet_Controller::Planet_Controller(){
    this->model=new Planet_Model();
    this->view=new Planet_View();
}

Planet_Controller::Planet_Controller(const Vector3 position, const Vector3 velocity, const double radius, const double mass, const Color color, const char *name){
    this->model=new Planet_Model(position, velocity, radius, mass, color, name);
    this->view=new Planet_View();
}

Planet_Controller::~Planet_Controller(){
    delete this->model;
    delete this->view;
}

void Planet_Controller::calcNewPosition() const{
    this->model->movePlanet();
}

void Planet_Controller::requestDrawing(const double distance_div, const double radius_div) const{
    this->view->draw(this->model->getPosition(), this->model->getRadius(), this->model->getColor(), distance_div, radius_div);
}

bool Planet_Controller::isCursorOnThePlanet(const Camera3D &camera, const double distance_div, const double radius_div) const{
    Ray ray=GetMouseRay(GetMousePosition(), camera);
    Vector3 planet_pos=this->model->getPosition();
    planet_pos.x/=distance_div;
    planet_pos.y/=distance_div;
    planet_pos.z/=distance_div;
    RayCollision ray_collision=GetRayCollisionSphere(ray, planet_pos, this->model->getRadius()/radius_div);
    return ray_collision.hit;
}