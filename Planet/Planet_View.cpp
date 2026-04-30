#include "Planet_View.h"

//I don't like that casting, change later...

void Planet_View::draw(const Model &model, const Vector3 &position, const double distance_div, const double radius_div){
    Vector3 pos=Vector3{position.x/(float)distance_div, position.y/(float)distance_div, position.z/(float)distance_div};
    DrawModelEx(model, pos, Vector3{1.f, 0.f, 0.f}, 270.f, Vector3{1.f/(float)radius_div, 1.f/(float)radius_div, 1.f/(float)radius_div}, WHITE);
}

void Planet_View::draw(const Model &model, const Vector3 &position, const double distance_div, const double radius_div, const float scale){
    Vector3 pos=Vector3{position.x/(float)distance_div, position.y/(float)distance_div, position.z/(float)distance_div};
    DrawModelEx(model, pos, Vector3{1.f, 0.f, 0.f}, 270.f, Vector3{scale/(float)radius_div, scale/(float)radius_div, scale/(float)radius_div}, WHITE);
}

void Planet_View::markPlanet(const Vector3 &position, const double radius, const double distance_div, const double radius_div){
    Vector3 pos=Vector3{position.x/(float)distance_div, position.y/(float)distance_div, position.z/(float)distance_div};
    DrawCircle3D(pos, radius/radius_div+0.1, Vector3{0.f, 0.f, 0.f}, 0.f, GREEN);
}