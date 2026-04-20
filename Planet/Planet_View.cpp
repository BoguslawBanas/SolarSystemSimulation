#include "Planet_View.h"

Planet_View::Planet_View(){}

Planet_View::~Planet_View()=default;

// void Planet_View::draw(const Vector3 &position, const double radius, const Color &color, const double distance_div, const double radius_div){
    // Vector3 pos=Vector3{position.x/distance_div, position.y/distance_div, position.z/distance_div};
    // DrawSphere(pos, radius/radius_div, color);
    // DrawModel(this->model, pos, 1.f, WHITE);
// }

void Planet_View::draw(const Model &model, const Vector3 &position, const double distance_div, const double radius_div){
    Vector3 pos=Vector3{position.x/distance_div, position.y/distance_div, position.z/distance_div};
    DrawModel(model, pos, 1.0/radius_div, WHITE);
}

void Planet_View::markPlanet(const Vector3 &position, const double radius, const double distance_div, const double radius_div){
    Vector3 pos=Vector3{position.x/distance_div, position.y/distance_div, position.z/distance_div};
    DrawCircle3D(pos, radius/radius_div+0.1, Vector3{0.f, 0.f, 0.f}, 0.f, GREEN);
}