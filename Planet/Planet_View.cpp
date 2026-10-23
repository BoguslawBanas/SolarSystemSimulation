#include "Planet_View.h"
#include "raymath.h"

//I don't like that casting, change later...

void Planet_View::draw(const Model &model, const Vector3 &position, const double distance_div, const double radius_div, const float angle, const float tilt){
    Vector3 pos=Vector3{position.x/(float)distance_div, position.y/(float)distance_div, position.z/(float)distance_div};
    Matrix m=MatrixIdentity();
    m=MatrixMultiply(m, MatrixScale(1/radius_div, 1/radius_div, 1/radius_div));
    m=MatrixMultiply(m, MatrixRotateX(-90.f*DEG2RAD));
    m=MatrixMultiply(m, MatrixRotateY(angle*DEG2RAD));
    m=MatrixMultiply(m, MatrixRotateZ(tilt*DEG2RAD));
    m=MatrixMultiply(m, MatrixTranslate(pos.x, pos.y, pos.z));
    DrawMesh(model.meshes[0], model.materials[0], m);
}

void Planet_View::draw(const Model &model, const Vector3 &position, const double distance_div, const double radius_div, const float scale){
    Vector3 pos=Vector3{position.x/(float)distance_div, position.y/(float)distance_div, position.z/(float)distance_div};
    DrawModelEx(model, pos, (Vector3){1.f, 0.f, 0.f}, 270.f, (Vector3){scale, scale, scale}, WHITE);
}

void Planet_View::markPlanet(const Vector3 &position, const double radius, const double distance_div, const double radius_div){
    Vector3 pos=Vector3{position.x/(float)distance_div, position.y/(float)distance_div, position.z/(float)distance_div};
    DrawCircle3D(pos, radius/radius_div+0.1, Vector3{0.f, 0.f, 0.f}, 0.f, GREEN);
}