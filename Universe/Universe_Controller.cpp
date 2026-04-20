#include "Universe_Controller.h"

Universe_Controller::Universe_Controller(const double distance_div, const double radius_div){
    this->model=new Universe_Model();
    this->view=new Universe_View(distance_div, radius_div);
}

Universe_Controller::~Universe_Controller(){
    delete this->model;
    delete this->view;
}

const Universe_Model* const Universe_Controller::getModel() const{
    return this->model;
}

void Universe_Controller::addPlanet(const Vector3 position, const Vector3 velocity, const double radius, const double mass, const Color color, const char *name, const char *path_to_image){
    Planet_Model *planet_m=new Planet_Model(position, velocity, radius, mass, color, name, path_to_image);
    this->model->addPlanet(planet_m);
}

void Universe_Controller::removePlanet(const std::vector<int>&planet_numbers){
    this->model->removePlanet(planet_numbers);
}

void Universe_Controller::removeAllPlanets(){
    this->model->removeAllPlanets();
}

void Universe_Controller::addTmpPlanet(){
    this->model->createTmpPlanet();
}

void Universe_Controller::addTmpPlanetToUniverse(){
    this->model->addPlanet(*this->model->getTmpPlanet());
}

void Universe_Controller::deleteTmpPlanet(){
    this->model->deleteTmpPlanet();
}

void Universe_Controller::updateNewPositionsOfPlanets(const float mult){
    this->model->calcNewPositionsOfPlanets(mult);
}

void Universe_Controller::updateTmpPlanet(const double mass, const double radius, const Vector3& distance_from_center, const Vector3& velocity, const Color &color){
    this->model->updateTmpPlanet(mass, radius, distance_from_center, velocity, color);
}

const Planet_Model* Universe_Controller::findPlanetPointedAt(const Camera3D &camera) const{
    Planet_Model *planet_pointed=NULL;
    for(auto it : this->getModel()->getPlanets()){
        if(it->isCursorOnPlanet(camera, this->view->getRadiusDivider(), this->view->getDistanceDivider())){
            if(!planet_pointed){
                planet_pointed=it;
            }
            else{
                float f1=calcDistanceWithoutSqrt(camera.position, planet_pointed->getPosition());
                float f2=calcDistanceWithoutSqrt(camera.position, it->getPosition());
                if(f2>f1){
                    planet_pointed=it;
                }
            }
        }
    }
    return planet_pointed;
}

void Universe_Controller::requestDrawing(const Planet_Model *planet_pointed){
    this->view->drawUniverse(this->model->getPlanets(), this->model->getTmpPlanet(), planet_pointed);
}