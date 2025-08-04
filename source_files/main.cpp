#define MASS_CONST 1e24
#define DISTANCE_CONST 1e6

#define DIVIDE_CONST 5e6

#include <iostream>
#include <vector>
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include "../header_files/rcamera.h"
#include "../header_files/planet.h"
#include "../header_files/universe.h"
#include "../header_files/solar_system_consts.h"

int main(){
    const int width=1440;
    const int height=920;

    double mult=1.0;
    double mult2=0.0;

    InitWindow(width, height, "Solar System");

    SetTargetFPS(60);

    Camera3D camera={0};
    camera.fovy=45.f;
    camera.target=(Vector3){0.f, 0.f, 0.f};
    camera.position=(Vector3){100.f, 100.f, 100.f};
    camera.up=(Vector3){0.f, 1.f, 0.f};
    camera.projection=CAMERA_PERSPECTIVE;

    Universe *universe=new Universe();

    // std::vector<Planet>planets;

    // planets.push_back(Planet(0.f, 0.f, 0.f, 0.f, 0.f, 0.f, SUN_RADIUS, 1*(SUN_MASS), YELLOW)); //Sun
    // planets.push_back(Planet(MERCURY_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000, 0.f, MERCURY_RADIUS, MERCURY_MASS, DARKBROWN)); //Mercury
    // planets.push_back(Planet(VENUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.73, 0.f, VENUS_RADIUS, VENUS_MASS, BROWN)); //Venus
    // planets.push_back(Planet(EARTH_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.622, 0.f, EARTH_RADIUS, EARTH_MASS, GREEN)); //Earth
    // planets.push_back(Planet(MARS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.503, 0.f, MARS_RADIUS, MARS_MASS, RED)); //Mars
    // planets.push_back(Planet(JUPITER_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.273, 0.f, JUPITER_RADIUS, JUPITER_MASS, LIGHTGRAY)); //Jupiter
    // planets.push_back(Planet(SATURN_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.203, 0.f, SATURN_RADIUS, SATURN_MASS, GRAY)); //Saturn
    // planets.push_back(Planet(URANUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.142, 0.f, URANUS_RADIUS, URANUS_MASS, BLUE)); //Uranus
    // planets.push_back(Planet(NEPTUNE_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.113, 0.f, NEPTUNE_RADIUS, NEPTUNE_MASS, BLUE)); //Neptune
    // planets.push_back(Planet(PLUTO_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.099, 0.f, PLUTO_RADIUS, PLUTO_MASS, GRAY)); //Pluto

    universe->addPlanetToUniverse(Planet(0.f, 0.f, 0.f, 0.f, 0.f, 0.f, SUN_RADIUS, 1*(SUN_MASS), YELLOW)); //Sun
    universe->addPlanetToUniverse(Planet(MERCURY_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000, 0.f, MERCURY_RADIUS, MERCURY_MASS, DARKBROWN)); //Mercury
    universe->addPlanetToUniverse(Planet(VENUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.73, 0.f, VENUS_RADIUS, VENUS_MASS, BROWN)); //Venus
    universe->addPlanetToUniverse(Planet(EARTH_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.622, 0.f, EARTH_RADIUS, EARTH_MASS, GREEN)); //Earth
    universe->addPlanetToUniverse(Planet(MARS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.503, 0.f, MARS_RADIUS, MARS_MASS, RED)); //Mars
    universe->addPlanetToUniverse(Planet(JUPITER_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.273, 0.f, JUPITER_RADIUS, JUPITER_MASS, LIGHTGRAY)); //Jupiter
    universe->addPlanetToUniverse(Planet(SATURN_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.203, 0.f, SATURN_RADIUS, SATURN_MASS, GRAY)); //Saturn
    universe->addPlanetToUniverse(Planet(URANUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.142, 0.f, URANUS_RADIUS, URANUS_MASS, BLUE)); //Uranus
    // universe->addPlanetToUniverse(Planet(NEPTUNE_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.113, 0.f, NEPTUNE_RADIUS, NEPTUNE_MASS, BLUE)); //Neptune
    // universe->addPlanetToUniverse(Planet(PLUTO_DISTANCE_FROM_SUN+SUN_RADIUS, 0.f, 0.f, 0.f, 1200000*0.099, 0.f, PLUTO_RADIUS, PLUTO_MASS, GRAY)); //Pluto

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_O)){
            mult+=(0.1*mult/10);
        }
        else if(IsKeyDown(KEY_P)){
            mult-=(0.1*mult/10);
        }

        // for(int i=1;i<planets.size();++i){
            // long double force=mult*(G*planets[0].getMass()*planets[i].getMass())/(planets[0].calcDistance(planets[i]));
            // long double force_x=force*(fabs(planets[i].getPosition().x))/(fabs(planets[i].getPosition().x)+fabs(planets[i].getPosition().y));
            // long double force_y=force*(fabs(planets[i].getPosition().y))/(fabs(planets[i].getPosition().x)+fabs(planets[i].getPosition().y));
            // if(planets[i].getPosition().x>0){
            //     force_x=-force_x;
            // }
            // if(planets[i].getPosition().y>0){
            //     force_y=-force_y;
            // }
            
            // planets[i].setVelocity((Vector2){planets[i].getVelocity().x+(force_x/planets[i].getMass()), planets[i].getVelocity().y+(force_y/planets[i].getMass())});
            // planets[i].setPosition((Vector2){planets[i].getPosition().x+planets[i].getVelocity().x, planets[i].getPosition().y+planets[i].getVelocity().y});
            // std::cout<<force_x<<' '<<force_y<<'\n';

            // std::cout<<mult<<'\n';
            mult2=mult;
            // for(int i=0;i<universe->planets.size();++i){
            //     for(int j=i+1;j<universe->planets.size();++j){
            //         universe->planets[j].calcVelocityFromGravity(universe->planets[i], mult2);
            //     }
            // }
            universe->calculateGravitiesOfPlanets(mult2);

            // for(int i=0;i<universe->planets.size();++i){
            //     universe->planets[i].movePlanet();
            // }

            std::cout<<universe->planets[0].getPosition().x<<' '<<universe->planets[0].getPosition().y<<'\n';
            // planets[i].movePlanet(planets[0], mult);
            // mult2=mult-round(mult);
        // }

        UpdateCameraCustom(&camera, CAMERA_FIRST_PERSON);

        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawSphere((Vector3){universe->planets[0].getPosition().x/DIVIDE_CONST, 0.f, universe->planets[0].getPosition().y/DIVIDE_CONST}, SUN_RADIUS/1e5, universe->planets[0].getColor());

        for(int i=1;i<universe->planets.size();++i){
            DrawSphere((Vector3){universe->planets[i].getPosition().x/DIVIDE_CONST, 0.f, universe->planets[i].getPosition().y/DIVIDE_CONST}, universe->planets[i].getRadius()/1e4, universe->planets[i].getColor());
        }

        // universe->planets[0].drawPlanet(DIVIDE_CONST, 1e5);
        // for(int i=0;i<universe->planets.size();++i){
        //     universe->planets[i].drawPlanet(DIVIDE_CONST, 1e4);
        // }

        EndMode3D();

        EndDrawing();
    }

    delete universe;
    CloseWindow();
    return 0;
}