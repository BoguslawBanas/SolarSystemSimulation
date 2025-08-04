#include "../header_files/universe.h"
#include <raylib.h>

Universe::Universe(){
    this->planets=std::vector<Planet>();
}

Universe::~Universe(){
    this->planets.clear();
}

void Universe::addPlanetToUniverse(const Planet &planet){
    this->planets.push_back(planet);
}

void Universe::calculateGravitiesOfPlanets(const double mult){
    if(this->planets.size()<2){
        return;
    }

    for(int j=1;j<this->planets.size();++j){
        this->planets[j].calcVelocityFromGravity(this->planets[0], mult);
    }
}

void Universe::drawUniverse(const double radius_const, const double orbital_const){
    // for(auto &it : this->planets){
    //     it.drawPlanet();
    // }
    //change later
    for(int i=0;i<this->planets.size();++i){
        if(i==0){
            this->planets[i].drawPlanet(1e5, orbital_const);
        }
        else{
            this->planets[i].drawPlanet(radius_const, orbital_const);
        }
    }
}