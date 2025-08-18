#include "../header_files/simulation.h"
#include "../header_files/rcamera.h"
#include "../header_files/raygui.h"

Simulation::Simulation(int width, int height){
    this->universe=new Universe();
    this->grid2d=new Gravitational_Grid_2D((Vector2){-5e9, -5e9}, 100, -5.0);

    this->camera={0};
    this->camera.fovy=45.f;
    this->camera.target=(Vector3){0.f, 0.f, 0.f};
    this->camera.position=(Vector3){100.f, 100.f, 100.f};
    this->camera.up=(Vector3){0.f, 1.f, 0.f};
    this->camera.projection=CAMERA_PERSPECTIVE;

    this->window_width=width;
    this->window_height=height;
    this->state=START_MENU;
    buttons.insert({"Start_sim", false});
    buttons.insert({"Exit", false});
    buttons.insert({"Solar_system", false});
    buttons.insert({"Free_mode", false});
    buttons.insert({"Go_back", false});
    buttons.insert({"Add_planet", false});
    buttons.insert({"Delete_planet", false});
    buttons.insert({"Pause", false});

    InitWindow(width, height, "Solar System");
    SetTargetFPS(60);
}

Simulation::~Simulation(){
    delete this->universe;
    delete this->grid2d;
    CloseWindow();
}

Simulation_State Simulation::getState() const{
    return this->state;
}

void Simulation::calcLogic(){
    if(IsKeyPressed(KEY_ESCAPE)){
        this->state=EXIT;
    }
    else if(buttons["Start_sim"]){
        buttons["Start_sim"]=false;
        this->state=START_MENU_2;
    }
    else if(buttons["Exit"]){
        buttons["Exit"]=false;
        this->state=EXIT;
    }
    else if(buttons["Solar_system"]){
        buttons["Solar_system"]=false;
        this->state=SIMULATION;
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
    }
    else if(buttons["Free_mode"]){
        buttons["Solar_system"]=false;
        this->state=SIMULATION;
    }
    else if(buttons["Go_back"]){
        buttons["Go_back"]=false;
        if(this->state==START_MENU_2){
            this->state=START_MENU;
        }
        //more conditions will be added later.
        else{
            this->state=START_MENU;
        }
    }
}

void Simulation::drawSimulation(){
    static float mult=1.f;
    static char mult_str[10];
    BeginDrawing();

    ClearBackground(BLACK);

    switch(this->state){
        case START_MENU:{
            buttons["Start_sim"]=GuiButton((Rectangle){this->window_width/3, this->window_height/2-20, 120, 40}, "Start simulation");
            buttons["Exit"]=GuiButton((Rectangle){2*this->window_width/3, this->window_height/2-20, 120, 40}, "Exit");
        }break;
        case START_MENU_2:{
            buttons["Solar_system"]=GuiButton((Rectangle){this->window_width/4, this->window_height/2-20, 80, 40}, "Solar system");
            buttons["Free_mode"]=GuiButton((Rectangle){this->window_width/2, this->window_height/2-20, 80, 40}, "Free mode");
            buttons["Go_back"]=GuiButton((Rectangle){3*this->window_width/4, this->window_height/2-20, 80, 40}, "Go back");
        }break;
        case SIMULATION:{
            universe->calculateGravitiesOfPlanets(mult);
            grid2d->calculateGrid(universe->planets);

            UpdateCameraCustom(&camera, CAMERA_FIRST_PERSON);

            BeginMode3D(camera);

            universe->drawUniverse(DIVIDE_CONST, DISTANCE_CONST);
            grid2d->drawGrid(DISTANCE_CONST);

            EndMode3D();

            GuiButton((Rectangle){24, 24, 120, 30}, "Add planet.");
            GuiButton((Rectangle){this->window_width-120-24, 24, 120, 30}, "Delete planet.");

            GuiSlider((Rectangle{300, 24, 400, 30}), "0", "100", &mult, 0.f, 100.f);
            snprintf(mult_str, 10, "%f", mult);
            DrawText(mult_str, 750, 30, 15, GREEN);

            buttons["Exit"]=GuiButton((Rectangle){24, this->window_height-40, 120, 30}, "Exit.");
        }break;
        case ADD_PLANET_MENU:{

        }break;
        case DELETE_PLANET_MENU:{

        }break;
        case PAUSE:{

        }break;
        case EXIT: break;
    }

    EndDrawing();
}