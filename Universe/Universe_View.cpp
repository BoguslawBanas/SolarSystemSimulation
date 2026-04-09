#include "Universe_View.h"

Universe_View::Universe_View(const float distance_div, const float radius_div){
    this->planet_view=new Planet_View();
    this->distance_divider=distance_div;
    this->radius_divider=radius_div;
}

Universe_View::~Universe_View(){
    delete this->planet_view;
}

const float Universe_View::getDistanceDivider() const{
    return this->distance_divider;
}

const float Universe_View::getRadiusDivider() const{
    return this->radius_divider;
}

void Universe_View::drawUniverse(const std::vector<Planet_Model*>&planets, const Planet_Model *tmp_planet, const Planet_Model *planet_pointed){
    for(auto it : planets){
        this->planet_view->draw(it->getPosition(), it->getRadius(), it->getColor(), this->distance_divider, this->radius_divider);
    }

    if(planet_pointed){
        Vector3 position_div={planet_pointed->getPosition().x/this->distance_divider+0.1f, planet_pointed->getPosition().y/this->distance_divider+0.1f, planet_pointed->getPosition().z/this->distance_divider+0.1f};
        DrawCircle3D(position_div, planet_pointed->getRadius()/this->radius_divider, Vector3{}, 0.f, GREEN);
    }

    if(tmp_planet){
        this->planet_view->draw(tmp_planet->getPosition(), tmp_planet->getRadius(), tmp_planet->getColor(), this->distance_divider, this->radius_divider);
    }
}