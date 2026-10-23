#include "Universe_Model.h"

Universe_Model::Universe_Model(){
    this->planets=std::vector<Planet_Model*>();
    this->tmp_planet=NULL;
    this->calc_speed=0.f;
}

Universe_Model::~Universe_Model(){
    for(auto it : this->planets){
        delete it;
    }
    this->planets.clear();
    delete this->tmp_planet;
}

const std::vector<Planet_Model*>& Universe_Model::getPlanets() const{
    return this->planets;
}

const Planet_Model* Universe_Model::getTmpPlanet() const{
    return this->tmp_planet;
}

void Universe_Model::addPlanet(Planet_Model *planet_model){
    this->planets.push_back(planet_model);
}

void Universe_Model::addPlanet(const Planet_Model &planet){
    Planet_Model *new_planet=new Planet_Model();
    new_planet->setMass(planet.getMass());
    new_planet->setName(planet.getName());
    new_planet->setPosition(planet.getPosition());
    new_planet->setRadius(planet.getRadius());
    new_planet->setVelocity(planet.getVelocity());
    new_planet->setColor(planet.getColor());
    new_planet->setTexturePath(planet.getTexturePath());
    new_planet->confirmModel();
    this->planets.push_back(new_planet);
}


void Universe_Model::removePlanets(){
    int already_removed=0;
    for(int i=0;i<this->planets.size();++i){
        if(this->planets[i-already_removed]->getCheckToErase()){
            delete this->planets[i-already_removed];
            this->planets[i-already_removed]=NULL;
            this->planets.erase(this->planets.begin()+i-already_removed);
            ++already_removed;
        }
    }
}

void Universe_Model::removeAllPlanets(){
    for(auto it : this->planets){
        delete it;
    }
    this->planets.clear();
}

void Universe_Model::createTmpPlanet(){
    this->tmp_planet=new Planet_Model();
}

void Universe_Model::updateTmpPlanetProperties(const double mass, const double radius, const Vector3& distance_from_center, const Vector3& velocity, const Color &color){
    this->tmp_planet->setMass(mass);
    this->tmp_planet->setRadius(radius);
    this->tmp_planet->setPosition(distance_from_center);
    this->tmp_planet->setVelocity(velocity);
    this->tmp_planet->setColor(color);
}

void Universe_Model::updateTmpPlanetName(const char *name){
    this->tmp_planet->setName(name);
}

void Universe_Model::deleteTmpPlanet(){
    delete this->tmp_planet;
    this->tmp_planet=NULL;
}

void Universe_Model::calcNewPositionsOfPlanets(const float speed){
    this->calc_speed+=speed;
    if(this->calc_speed<1.f){
        // for(int i=0;i<this->planets.size();++i){
        //     for(int j=i+1;j<this->planets.size();++j){
        //         this->planets[i]->calcVelocityFromGravity(*planets[j]); //change later
        //     }
        // }
        
        // for(auto it : this->planets){
        //     it->movePlanet();
        // }
        // this->calc_speed=0.f;
    }
    else{
        while(this->calc_speed>=1.f){
            for(int i=0;i<this->planets.size();++i){
                for(int j=i+1;j<this->planets.size();++j){
                    this->planets[i]->calcVelocityFromGravity(*planets[j]); //change later
                }
            }
        
            for(auto it : this->planets){
                it->movePlanet();
                it->updateSpin();
            }
            this->calc_speed-=1.f;
        }
    }
}

const long long int Universe_Model::calculateChecksum() const{
    long long int checksum=0;
    checksum+=this->getPlanets().size();
    for(const Planet_Model* const planet : this->getPlanets()){
        checksum+=planet->calculateChecksum();
    }
    return checksum;
}