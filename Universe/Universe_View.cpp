#include "Universe_View.h"

Universe_View::Universe_View(const float distance_div, const float radius_div){
    this->planet_view=new Planet_View();
    this->distance_divider=distance_div;
    this->radius_divider=radius_div;
}

Universe_View::~Universe_View(){
    delete this->planet_view;
}

void Universe_View::drawUniverse(const std::vector<Planet_Model*>&planets, const Planet_Model *tmp_planet){
    for(auto it : planets){
        this->planet_view->draw(it->getPosition(), it->getRadius(), it->getColor(), this->distance_divider, this->radius_divider);
    }

    if(tmp_planet){
        this->planet_view->draw(tmp_planet->getPosition(), tmp_planet->getRadius(), tmp_planet->getColor(), this->distance_divider, this->radius_divider);
    }
}