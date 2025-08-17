#define DISTANCE_CONST 5e6l
#define DIVIDE_CONST 1e4l

#define RAYGUI_IMPLEMENTATION

#include <iostream>
#include <vector>
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include "../header_files/rcamera.h"
#include "../header_files/raygui.h"
#include "../header_files/planet.h"
#include "../header_files/universe.h"
#include "../header_files/solar_system_consts.h"
#include "../header_files/gravitational_grid_2d.h"

int main(){
    const int width=1440;
    const int height=920;

    float mult=1.f;
    bool camera_mode=true;
    char mult_str[10];

    InitWindow(width, height, "Solar System");

    SetTargetFPS(60);

    Camera3D camera={0};
    camera.fovy=45.f;
    camera.target=(Vector3){0.f, 0.f, 0.f};
    camera.position=(Vector3){100.f, 100.f, 100.f};
    camera.up=(Vector3){0.f, 1.f, 0.f};
    camera.projection=CAMERA_PERSPECTIVE;

    Universe *universe=new Universe();
    Gravitational_Grid_2D *grid_2d=new Gravitational_Grid_2D((Vector2){-5e8, -5e8}, 100, -5.0);

    universe->addPlanetToUniverse(Planet(0.1l, 0.1l, 0.l, 0.l, 0.l, 0.l, SUN_RADIUS/10, SUN_MASS, YELLOW)); //Sun
    universe->addPlanetToUniverse(Planet(MERCURY_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000.l*1.l, MERCURY_RADIUS, MERCURY_MASS, DARKBROWN)); //Mercury
    universe->addPlanetToUniverse(Planet(VENUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.73l, VENUS_RADIUS, VENUS_MASS, BROWN)); //Venus
    universe->addPlanetToUniverse(Planet(EARTH_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.622l, EARTH_RADIUS, EARTH_MASS, GREEN)); //Earth
    universe->addPlanetToUniverse(Planet(MARS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.503l, MARS_RADIUS, MARS_MASS, RED)); //Mars
    universe->addPlanetToUniverse(Planet(JUPITER_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.273l, JUPITER_RADIUS, JUPITER_MASS, LIGHTGRAY)); //Jupiter
    universe->addPlanetToUniverse(Planet(SATURN_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.203l, SATURN_RADIUS, SATURN_MASS, GRAY)); //Saturn
    universe->addPlanetToUniverse(Planet(URANUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.142l, URANUS_RADIUS, URANUS_MASS, BLUE)); //Uranus
    universe->addPlanetToUniverse(Planet(NEPTUNE_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.113l, NEPTUNE_RADIUS, NEPTUNE_MASS, BLUE)); //Neptune
    universe->addPlanetToUniverse(Planet(PLUTO_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.099l, PLUTO_RADIUS, PLUTO_MASS, GRAY)); //Pluto

    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_I)){
            camera_mode=true;
        }
        else if(IsKeyPressed(KEY_O)){
            camera_mode=false;
        }

        universe->calculateGravitiesOfPlanets(mult);
        grid_2d->calculateGrid(universe->planets);

        if(camera_mode){
            UpdateCameraCustom(&camera, CAMERA_FIRST_PERSON);
        }

        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);

        universe->drawUniverse(DIVIDE_CONST, DISTANCE_CONST);
        grid_2d->drawGrid(DISTANCE_CONST);

        EndMode3D();

        //functionality will be added later
        GuiButton((Rectangle){24, 24, 120, 30}, "Add planet.");
        GuiButton((Rectangle){width-120-24, 24, 120, 30}, "Delete planet.");

        GuiSlider((Rectangle{300, 24, 400, 30}), "0", "100", &mult, 0.f, 100.f);

        snprintf(mult_str, 10, "%f", mult);
        DrawText(mult_str, 750, 30, 15, GREEN);

        EndDrawing();
    }

    delete universe;
    delete grid_2d;
    CloseWindow();
    return 0;
}