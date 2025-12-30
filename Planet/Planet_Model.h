#ifndef PLANET_MODEL_H
#define PLANET_MODEL_H

#include <raylib.h>
#include <raymath.h>
#include <string.h>
#include "../header_files/solar_system_consts.h"
#include "../header_files/sim_math.h"

class Planet_Model{
    private:
    Vector3 position;
    Vector3 velocity;
    double radius;
    double mass;
    Color color;
    char name[256];

    public:
    Planet_Model();

    Planet_Model(const Vector3, const Vector3, const double, const double, const Color&, const char*);

    ~Planet_Model();

    const Vector3 &getPosition() const;

    const Vector3 &getVelocity() const;

    double getRadius() const;

    double getMass() const;

    Color getColor() const;

    const char* getName() const;

    void setPosition(const Vector3);

    void setVelocity(const Vector3);

    void setRadius(const double);

    void setMass(const double);

    void setColor(const Color&);

    void setName(const char*);

    double calcDistanceBetweenTwoPlanets(const Planet_Model&) const;

    void calcVelocityFromGravity(Planet_Model&);

    void movePlanet();
    
    bool isCursorOnPlanet(const Camera3D&, const double, const double) const;
};

#endif