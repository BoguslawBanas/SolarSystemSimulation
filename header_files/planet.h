#ifndef PLANET_H
#define PLANET_H

#include <raylib.h>
#include <math.h>
#include "solar_system_consts.h"

class Planet{
    private:
    Vector3 position;
    Vector3 velocity;
    long double radius;
    long double mass;
    Color color;

    public:
    Planet(long double, long double, long double, float, float, float, long double, long double, Color);

    ~Planet();

    Planet copyPlanet();

    const Vector3 &getPosition() const;

    const Vector3 &getVelocity() const;

    void setPosition(Vector3);

    void setVelocity(Vector3);

    long double getRadius() const;

    void setRadius(const long double);

    long double getMass() const;

    void setMass(const long double);

    Color getColor() const;

    void setColor(const Color);

    long double calcDistance(const Planet&) const;

    double calcVelocityFromGravity(Planet&, const double);

    void movePlanet();

    void drawPlanet(const double, const double);
};

#endif