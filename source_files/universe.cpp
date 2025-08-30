#include "../header_files/universe.h"

Universe::Universe(){
    this->planets=std::vector<Planet>();
    this->tmp_planet=NULL;
}

Universe::~Universe(){
    this->planets.clear();
    delete this->tmp_planet;
}

std::vector<Planet>& Universe::getPlanets(){
    return this->planets;
}

Planet* Universe::getTmpPlanet() const{
    return this->tmp_planet;
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

    if(tmp_planet){
        this->tmp_planet->drawPlanet(radius_const, orbital_const);
    }
}

void Universe::addTmpPlanetToUniverse(const Color color){
    this->tmp_planet=new Planet(0.l, 0.l, 0.l, 0.l, 0.l, 0.l, 0.1l, SUN_MASS, color, "");
}

void Universe::deleteTmpPlanetFromUniverse(){
    delete this->tmp_planet;
    this->tmp_planet=NULL;
}

void Universe::setOptionsForTmpPlanet(const long double radius, const long double mass, const float angle, const long double distance_from_sun, const long double velocity, const Color new_color){
    this->tmp_planet->setRadius(radius);
    this->tmp_planet->setMass(mass);
    this->tmp_planet->setPosition((Vector3){distance_from_sun, this->tmp_planet->getPosition().y, this->tmp_planet->getPosition().z});
    this->tmp_planet->setColor(new_color);
    this->tmp_planet->setVelocity((Vector3){velocity, 0.f, 0.f});
    
    float tan_an=tanf(angle);
    long double x_2=(distance_from_sun*distance_from_sun)/(1.f+tan_an*tan_an);
    long double y_2=(distance_from_sun*distance_from_sun)-x_2;

    long double x=sqrtl(x_2);
    long double y=sqrtl(y_2);
    
    if(angle>M_PI_2 && angle<(3*M_PI_2)){
        x=-x;
    }
    if(angle>M_PI && angle<(2*M_PI)){
        y=-y;
    }

    this->tmp_planet->setPosition((Vector3){x, this->tmp_planet->getPosition().y, y});
}

void Universe::acceptPlanetToUniverse(){
    Planet new_planet=this->tmp_planet->copyPlanet();
    this->addPlanetToUniverse(new_planet);
    deleteTmpPlanetFromUniverse();
}

void Universe::deletePlanetsFromUniverse(const std::vector<char>&planets_to_delete){
    //tmp, change later
    std::vector<const char*>planets_to_remove;
    for(int i=0;i<this->planets.size();++i){
        if(planets_to_delete[i]){
            planets_to_remove.push_back(planets[i].getName());
        }
    }

    int i=0;
    int j=0;
    while(i<this->planets.size()){
        if(this->planets[i].getName()==planets_to_remove[j]){
            this->planets.erase(this->planets.begin()+i);
            ++j;
        }
        else{
            ++i;
        }
    }
}