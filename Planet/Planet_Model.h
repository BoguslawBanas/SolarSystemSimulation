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
    char name[256];
    char texture_path[512];
    bool check_to_erase;
    Texture texture;
    Model model;
    float rotation_angle;
    float rotation_speed;
    float tilt;

    public:
    Planet_Model();

    Planet_Model(const Vector3, const Vector3, const double, const double, const Color&, const char*, const char*, const float, const float);

    ~Planet_Model();

    const Vector3 &getPosition() const;

    const Vector3 &getVelocity() const;

    double getRadius() const;

    double getMass() const;

    Color getColor() const;

    const char* getName() const;

    const bool getCheckToErase() const;

    bool* getPtrToCheckToErase();

    const char* getTexturePath() const;

    const Model& getModel() const;

    const float getRotationAngle() const;

    const float getTilt() const;

    void setPosition(const Vector3);

    void setVelocity(const Vector3);

    void setRadius(const double);

    void setMass(const double);

    void setColor(const Color&);

    void setName(const char*);

    void setTexturePath(const char*);

    double calcDistanceBetweenTwoPlanets(const Planet_Model&) const;

    void calcVelocityFromGravity(Planet_Model&);

    void movePlanet();

    void updateSpin();
    
    bool isCursorOnPlanet(const Camera3D&, const double, const double) const;

    void confirmModel();

    long long int calculateChecksum() const;
};

#endif