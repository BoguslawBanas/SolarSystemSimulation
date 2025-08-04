#include "../header_files/planet.h"

Planet::Planet(long double x, long double y, long double z, float velX, float velY, float velZ, long double radius, long double mass, Color color){
    this->position=(Vector3){x, y, z};
    this->velocity=(Vector3){velX, velY, velZ};
    this->radius=radius;
    this->mass=mass;
    this->color=color;
}

Planet::~Planet()=default;

const Vector3& Planet::getPosition() const{
    return this->position;
}

const Vector3& Planet::getVelocity() const{
    return this->velocity;
}

void Planet::setPosition(Vector3 newPosition){
    this->position=newPosition;
}

void Planet::setVelocity(Vector3 newVelocity){
    this->velocity=newVelocity;
}

long double Planet::getRadius() const{
    return this->radius;
}

long double Planet::getMass() const{
    return this->mass;
}

Color Planet::getColor() const{
    return this->color;
}

long double Planet::calcDistance(const Planet &planet) const{
    return (this->getPosition().x-planet.getPosition().x)*(this->getPosition().x-planet.getPosition().x)+
    (this->getPosition().y-planet.getPosition().y)*(this->getPosition().y-planet.getPosition().y)+
    (this->getPosition().z-planet.getPosition().z)*(this->getPosition().z-planet.getPosition().z);
}

double Planet::calcVelocityFromGravity(Planet &planet, const double mult){
    for(int i=0;i<mult;++i){
        long double force=(G*this->getMass()*planet.getMass())/(this->calcDistance(planet));
        long double force_x=force*(fabs(this->getPosition().x))/(fabs(this->getPosition().x)+fabs(this->getPosition().y)+fabs(this->getPosition().z));
        long double force_y=force*(fabs(this->getPosition().y))/(fabs(this->getPosition().x)+fabs(this->getPosition().y)+fabs(this->getPosition().z));
        long double force_z=force*(fabs(this->getPosition().z))/(fabs(this->getPosition().x)+fabs(this->getPosition().y)+fabs(this->getPosition().z));
        if(this->getPosition().x>planet.getPosition().x){
            force_x=-force_x;
        }
        if(this->getPosition().y>planet.getPosition().y){
            force_y=-force_y;
        }
        if(this->getPosition().z>planet.getPosition().z){
            force_z=-force_z;
        }
            
        this->setVelocity((Vector3){this->getVelocity().x+(force_x/this->getMass()), this->getVelocity().y+(force_y/this->getMass()), this->getVelocity().z+(force_z/this->getMass())});
        planet.setVelocity((Vector3){planet.getVelocity().x-(force_x/planet.getMass()), planet.getVelocity().y-(force_y/planet.getMass()), planet.getVelocity().z-(force_z/planet.getMass())});
        this->setPosition((Vector3){this->getPosition().x+this->getVelocity().x, this->getPosition().y+this->getVelocity().y, this->getPosition().z+this->getVelocity().z});
        // planet.setPosition((Vector3){planet.getPosition().x+planet.getVelocity().x, planet.getPosition().y+planet.getVelocity().y, planet.getPosition().z+planet.getVelocity().z});
    }
    return mult-round(mult);
}

void Planet::movePlanet(){
    this->setPosition((Vector3){this->getPosition().x+this->getVelocity().x, this->getPosition().y+this->getVelocity().y, this->getPosition().z+this->getVelocity().z});
}

void Planet::drawPlanet(const double radius_const, const double orbital_const){
    Vector3 v{this->position.x/orbital_const, this->position.y/orbital_const, this->position.z/orbital_const};
    DrawSphere(v, this->radius/radius_const, this->color);
}