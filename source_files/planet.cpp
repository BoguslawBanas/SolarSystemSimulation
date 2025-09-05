#include "../header_files/planet.h"

Planet::Planet(long double x, long double y, long double z, float velX, float velY, float velZ, long double radius, long double mass, Color color, const char *name){
    this->position=(Vector3){x, y, z};
    this->velocity=(Vector3){velX, velY, velZ};
    this->radius=radius;
    this->mass=mass;
    this->color=color;
    this->name=name;
}

Planet::~Planet()=default;

Planet Planet::copyPlanet(){
    Vector3 new_pos=this->position;
    Vector3 new_vel=this->velocity;
    long double new_radius=this->radius;
    long double new_mass=this->mass;
    Color new_color=this->color;

    return Planet(new_pos.x, new_pos.y, new_pos.z, new_vel.x, new_vel.y, new_vel.z, new_radius, new_mass, new_color, this->name);
}

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

void Planet::setRadius(const long double new_radius){
    this->radius=new_radius;
}

long double Planet::getMass() const{
    return this->mass;
}

void Planet::setMass(const long double new_mass){
    this->mass=new_mass;
}

Color Planet::getColor() const{
    return this->color;
}

void Planet::setColor(const Color new_color){
    this->color=new_color;
}

const char* Planet::getName() const{
    return this->name;
}

void Planet::setName(const char* new_name){
    this->name=new_name;
}

long double Planet::calcDistance(const Planet &planet) const{
    return (this->getPosition().x-planet.getPosition().x)*(this->getPosition().x-planet.getPosition().x)+
    (this->getPosition().y-planet.getPosition().y)*(this->getPosition().y-planet.getPosition().y)+
    (this->getPosition().z-planet.getPosition().z)*(this->getPosition().z-planet.getPosition().z);
}

double Planet::calcVelocityFromGravity(Planet &planet, const double mult){
    long double force=(G*this->getMass()*planet.getMass())/(this->calcDistance(planet));
    long double relative_distance=fabsl(this->getPosition().x-planet.getPosition().x)+fabsl(this->getPosition().y-planet.getPosition().y)+fabsl(this->getPosition().z-planet.getPosition().z);

    long double force_x=force*((fabsl(this->getPosition().x-planet.getPosition().x))/relative_distance);
    long double force_y=force*((fabsl(this->getPosition().y-planet.getPosition().y))/relative_distance);
    long double force_z=force*((fabsl(this->getPosition().z-planet.getPosition().z))/relative_distance);

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
    return mult-round(mult);
}

void Planet::movePlanet(){
    this->setPosition((Vector3){this->getPosition().x+this->getVelocity().x, this->getPosition().y+this->getVelocity().y, this->getPosition().z+this->getVelocity().z});
}

void Planet::drawPlanet(const double radius_const, const double orbital_const){
    Vector3 v{this->position.x/orbital_const, this->position.y/orbital_const, this->position.z/orbital_const};
    DrawSphere(v, this->radius/radius_const, this->color);
}