#include "../header_files/universe.h"

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

    for(int m=0;m<mult;++m){
        for(int i=0;i<this->planets.size();++i){
            for(int j=i+1;j<this->planets.size();++j){
                this->planets[i].calcVelocityFromGravity(this->planets[j], mult);
            }
        }

        for(int i=0;i<this->planets.size();++i){
            this->planets[i].movePlanet();
        }
    }
}

void Universe::drawUniverse(const double radius_const, const double orbital_const){
    for(int i=0;i<this->planets.size();++i){
        this->planets[i].drawPlanet(radius_const, orbital_const);
    }
}