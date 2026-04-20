#include "Planet_Model.h"

Planet_Model::Planet_Model(){
    this->position=(Vector3){0.f, 0.f, 0.f};
    this->velocity=(Vector3){0.f, 0.f, 0.f};
    this->radius=0.0;
    this->mass=0.0;
    this->color=(Color){0, 0, 0};
    this->name[0]='\0';
}

Planet_Model::Planet_Model(const Vector3 position, const Vector3 velocity, const double radius, const double mass, const Color &color, const char *name, const char *path_to_image){
    this->position=position;
    this->velocity=velocity;
    this->radius=radius;
    this->mass=mass;
    this->color=color;
    strncpy(this->name, name, 255);

    Image image=LoadImage(path_to_image);
    ImageFlipHorizontal(&image);
    ImageRotateCCW(&image);
    this->texture=LoadTextureFromImage(image);
    UnloadImage(image);

    this->mesh=GenMeshSphere(this->radius, 32, 32);
    this->model=LoadModelFromMesh(mesh);
    SetMaterialTexture(&this->model.materials[0], MATERIAL_MAP_DIFFUSE, this->texture);
}

Planet_Model::~Planet_Model(){
    UnloadTexture(this->texture);
    UnloadMesh(this->mesh);
    UnloadModel(this->model);
}

const Vector3& Planet_Model::getPosition() const{
    return this->position;
}

const Vector3& Planet_Model::getVelocity() const{
    return this->velocity;
}

double Planet_Model::getRadius() const{
    return this->radius;
}

double Planet_Model::getMass() const{
    return this->mass;
}

Color Planet_Model::getColor() const{
    return this->color;
}

const char* Planet_Model::getName() const{
    return this->name;
}

const Model& Planet_Model::getModel() const{
    return this->model;
}

void Planet_Model::setPosition(Vector3 new_position){
    this->position=new_position;
}

void Planet_Model::setVelocity(Vector3 new_velocity){
    this->velocity=new_velocity;
}

void Planet_Model::setRadius(const double new_radius){
    this->radius=new_radius;
}

void Planet_Model::setMass(const double new_mass){
    this->mass=new_mass;
}

void Planet_Model::setColor(const Color &new_color){
    this->color=new_color;
}

void Planet_Model::setName(const char *new_name){
    strncpy(this->name, new_name, 255);
}

double Planet_Model::calcDistanceBetweenTwoPlanets(const Planet_Model &another_planet) const{
    return calcDistanceWithoutSqrt(this->getPosition(), another_planet.getPosition());
}

void Planet_Model::calcVelocityFromGravity(Planet_Model &another_planet){
    double force=(G*this->getMass()*another_planet.getMass())/(this->calcDistanceBetweenTwoPlanets(another_planet));
    double relative_distance=fabs(this->getPosition().x-another_planet.getPosition().x)+fabs(this->getPosition().y-another_planet.getPosition().y)+fabs(this->getPosition().z-another_planet.getPosition().z);

    double force_x=force*((fabs(this->getPosition().x-another_planet.getPosition().x))/relative_distance);
    double force_y=force*((fabs(this->getPosition().y-another_planet.getPosition().y))/relative_distance);
    double force_z=force*((fabs(this->getPosition().z-another_planet.getPosition().z))/relative_distance);

    if(this->getPosition().x>another_planet.getPosition().x){
        force_x=-force_x;
    }
    if(this->getPosition().y>another_planet.getPosition().y){
        force_y=-force_y;
    }
    if(this->getPosition().z>another_planet.getPosition().z){
        force_z=-force_z;
    }
            
    this->setVelocity((Vector3){this->getVelocity().x+(force_x/this->getMass()), this->getVelocity().y+(force_y/this->getMass()), this->getVelocity().z+(force_z/this->getMass())});
    another_planet.setVelocity((Vector3){another_planet.getVelocity().x-(force_x/another_planet.getMass()), another_planet.getVelocity().y-(force_y/another_planet.getMass()), another_planet.getVelocity().z-(force_z/another_planet.getMass())});
    // return mult-round(mult);
}

void Planet_Model::movePlanet(){
    this->setPosition((Vector3){this->getPosition().x+this->getVelocity().x, this->getPosition().y+this->getVelocity().y, this->getPosition().z+this->getVelocity().z});
}
    
bool Planet_Model::isCursorOnPlanet(const Camera3D &camera, const double radius_divider, const double distance_divider) const{
    Ray ray=GetMouseRay(GetMousePosition(), camera);
    Vector3 planet_pos=this->getPosition();
    planet_pos.x/=distance_divider;
    planet_pos.y/=distance_divider;
    planet_pos.z/=distance_divider;
    RayCollision ray_collision=GetRayCollisionSphere(ray, planet_pos, this->getRadius()/radius_divider);
    return ray_collision.hit;
}