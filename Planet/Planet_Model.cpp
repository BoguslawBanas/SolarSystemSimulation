#include "Planet_Model.h"

Planet_Model::Planet_Model(){
    this->position=(Vector3){0.f, 0.f, 0.f};
    this->velocity=(Vector3){0.f, 0.f, 0.f};
    this->radius=1.0;
    this->mass=0.0;
    this->name[0]='\0';
    this->texture_path[0]='\0';
    this->check_to_erase=false;

    this->texture=Texture2D{0};
    Mesh mesh=GenMeshSphere(this->radius, 32, 32);
    this->model=LoadModelFromMesh(mesh);
    this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].color=WHITE;
    this->rotation_speed=0.f;
    this->rotation_angle=0.f;
    this->tilt=0.f;
}

Planet_Model::Planet_Model(const Vector3 position, const Vector3 velocity, const double radius, const double mass, const Color &color, const char *name, const char *path_to_image, const float rotation_speed, const float tilt){
    this->position=position;
    this->velocity=velocity;
    this->radius=radius;
    this->mass=mass;
    this->check_to_erase=false;
    strncpy(this->name, name, 255);
    strncpy(this->texture_path, path_to_image, 511);

    if(IsFileExtension(this->texture_path, ".png;.jpg")){ //add later other extensions
        Image image=LoadImage(this->texture_path);
        ImageFlipHorizontal(&image);
        ImageRotateCCW(&image);
        this->texture=LoadTextureFromImage(image);
        UnloadImage(image);

        Mesh mesh=GenMeshSphere(this->radius, 32, 32);
        this->model=LoadModelFromMesh(mesh);
        SetMaterialTexture(&this->model.materials[0], MATERIAL_MAP_DIFFUSE, this->texture);
    }
    else{
        this->texture=Texture2D{0};
        Mesh mesh=GenMeshSphere(this->radius, 32, 32);
        this->model=LoadModelFromMesh(mesh);
        this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].color=color;
    }
    this->rotation_speed=rotation_speed;
    this->rotation_angle=0.f;
    this->tilt=tilt;
}

Planet_Model::~Planet_Model(){
    UnloadModel(this->model);
    UnloadTexture(this->texture);
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
    return this->model.materials[MATERIAL_MAP_DIFFUSE].maps[0].color;
}

const char* Planet_Model::getName() const{
    return this->name;
}

const bool Planet_Model::getCheckToErase() const{
    return this->check_to_erase;
}

bool* Planet_Model::getPtrToCheckToErase(){
    return &this->check_to_erase;
}

const char* Planet_Model::getTexturePath() const{
    return this->texture_path;
}

const Model& Planet_Model::getModel() const{
    return this->model;
}

const float Planet_Model::getRotationAngle() const{
    return this->rotation_angle;
}

const float Planet_Model::getTilt() const{
    return this->tilt;
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
    this->model.materials[MATERIAL_MAP_DIFFUSE].maps[0].color=new_color;
}

void Planet_Model::setName(const char *new_name){
    strncpy(this->name, new_name, 255);
}

void Planet_Model::setTexturePath(const char *texture_path){
    strncpy(this->texture_path, texture_path, 511);
}

double Planet_Model::calcDistanceBetweenTwoPlanets(const Planet_Model &another_planet) const{
    return calcDistanceWithoutSqrt(this->getPosition(), another_planet.getPosition());
}

void Planet_Model::calcVelocityFromGravity(Planet_Model &another_planet){
    double force=(G*this->getMass()*another_planet.getMass())/(this->calcDistanceBetweenTwoPlanets(another_planet));
    // double relative_distance=fabs(this->getPosition().x-another_planet.getPosition().x)+fabs(this->getPosition().y-another_planet.getPosition().y)+fabs(this->getPosition().z-another_planet.getPosition().z);
    double x=this->getPosition().x-another_planet.getPosition().x;
    double y=this->getPosition().y-another_planet.getPosition().y;
    double z=this->getPosition().z-another_planet.getPosition().z;
    double distance=sqrt(x*x+y*y+z*z);

    double force_x=force*((fabs(this->getPosition().x-another_planet.getPosition().x))/distance);
    double force_y=force*((fabs(this->getPosition().y-another_planet.getPosition().y))/distance);
    double force_z=force*((fabs(this->getPosition().z-another_planet.getPosition().z))/distance);

    //test
    // if(!strcmp(this->getName(), "Mercury")){
    //     printf("%lf %lf %lf\n", force_x, force_y, force_z);
    // }

    if(this->getPosition().x>another_planet.getPosition().x){
        force_x=-force_x;
    }
    if(this->getPosition().y>another_planet.getPosition().y){
        force_y=-force_y;
    }
    if(this->getPosition().z>another_planet.getPosition().z){
        force_z=-force_z;
    }
            
    this->setVelocity((Vector3){this->getVelocity().x+float(force_x/this->getMass()), this->getVelocity().y+float(force_y/this->getMass()), this->getVelocity().z+float(force_z/this->getMass())});
    another_planet.setVelocity((Vector3){another_planet.getVelocity().x-float(force_x/another_planet.getMass()), another_planet.getVelocity().y-float(force_y/another_planet.getMass()), another_planet.getVelocity().z-float(force_z/another_planet.getMass())});
}

void Planet_Model::movePlanet(){
    this->setPosition((Vector3){this->getPosition().x+this->getVelocity().x, this->getPosition().y+this->getVelocity().y, this->getPosition().z+this->getVelocity().z});
}

void Planet_Model::updateSpin(){
    this->rotation_angle+=this->rotation_speed*GetFrameTime();
    if(this->rotation_angle>=360.f){
        this->rotation_angle-=360.f;
    }
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

void Planet_Model::confirmModel(){
    UnloadTexture(this->texture);
    Color tmp_color=this->getColor();

    UnloadModel(this->model);
    Mesh mesh=GenMeshSphere(this->radius, 32, 32);
    this->model=LoadModelFromMesh(mesh);

    if(IsFileExtension(this->texture_path, ".png;.jpg")){ //add later other extensions
        Image image=LoadImage(this->texture_path);
        ImageFlipHorizontal(&image);
        ImageRotateCCW(&image);
        this->texture=LoadTextureFromImage(image);
        UnloadImage(image);

        Mesh mesh=GenMeshSphere(this->radius, 32, 32);
        this->model=LoadModelFromMesh(mesh);
        SetMaterialTexture(&this->model.materials[0], MATERIAL_MAP_DIFFUSE, this->texture);
    }
    else{
        this->texture=Texture2D{0};
        Mesh mesh=GenMeshSphere(this->radius, 32, 32);
        this->model=LoadModelFromMesh(mesh);
        this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].color=tmp_color;
    }
}

long long int Planet_Model::calculateChecksum() const{
    long long int checksum=0;
    Color color=this->getColor();
    Vector3 position=this->getPosition();
    Vector3 velocity=this->getVelocity();
    checksum+=(color.a+color.b+color.g+color.r);
    checksum+=(long long int)this->getMass();
    checksum+=(long long int)position.x+(long long int)position.y+(long long int)position.z;
    checksum+=(long long int)this->getRadius();
    checksum+=(long long int)velocity.x+(long long int)velocity.y+(long long int)velocity.z;
    return checksum;
}