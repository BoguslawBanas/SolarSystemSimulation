#include "../header_files/simulation.h"
#include "../header_files/rcamera.h"

Simulation::Simulation(int width, int height){
    this->universe=new Universe();
    this->grid2d=new Gravitational_Grid_2D((Vector2){-7e9, -7e9}, 175, -5.0);
    this->main_menu=NULL;
    this->add_planet_menu=NULL;
    this->delete_planet_menu=NULL;
    this->clicked_planet_menu=NULL;

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
    delete this->main_menu;
    delete this->add_planet_menu;
    delete this->delete_planet_menu;
    CloseWindow();
}

Simulation_State Simulation::getState() const{
    return this->state;
}

void Simulation::calcLogic(){
    if(IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()){
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
        this->main_menu=new Main_Menu(this->window_width, this->window_height);
        universe->addPlanetToUniverse(Planet(0.1l, 0.1l, 0.l, 0.l, 0.l, 0.l, SUN_RADIUS/10, SUN_MASS, YELLOW, "Sun")); //Sun
        universe->addPlanetToUniverse(Planet(MERCURY_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000.l*1.l, MERCURY_RADIUS, MERCURY_MASS, DARKBROWN, "Mercury")); //Mercury
        universe->addPlanetToUniverse(Planet(VENUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.73l, VENUS_RADIUS, VENUS_MASS, BROWN, "Venus")); //Venus
        universe->addPlanetToUniverse(Planet(EARTH_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.622l, EARTH_RADIUS, EARTH_MASS, GREEN, "Earth")); //Earth
        universe->addPlanetToUniverse(Planet(MARS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.503l, MARS_RADIUS, MARS_MASS, RED, "Mars")); //Mars
        universe->addPlanetToUniverse(Planet(JUPITER_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.273l, JUPITER_RADIUS, JUPITER_MASS, LIGHTGRAY, "Jupiter")); //Jupiter
        universe->addPlanetToUniverse(Planet(SATURN_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.203l, SATURN_RADIUS, SATURN_MASS, GRAY, "Saturn")); //Saturn
        universe->addPlanetToUniverse(Planet(URANUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.142l, URANUS_RADIUS, URANUS_MASS, BLUE, "Uranus")); //Uranus
        universe->addPlanetToUniverse(Planet(NEPTUNE_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.113l, NEPTUNE_RADIUS, NEPTUNE_MASS, BLUE, "Neptune")); //Neptune
        universe->addPlanetToUniverse(Planet(PLUTO_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l, 0.l, 0.l, 1200000*0.099l, PLUTO_RADIUS, PLUTO_MASS, GRAY, "Pluto")); //Pluto
    }
    else if(buttons["Free_mode"]){
        buttons["Free_mode"]=false;
        this->state=SIMULATION;
        this->main_menu=new Main_Menu(this->window_width, this->window_height);
    }
    else if(buttons["Go_back"]){
        buttons["Go_back"]=false;
        if(this->state==START_MENU_2){
            this->state=START_MENU;
        }
        else if(this->state==ADD_PLANET_MENU){
            this->universe->deleteTmpPlanetFromUniverse();
            delete this->add_planet_menu;
            this->add_planet_menu=NULL;
            this->state=SIMULATION;
        }
        else if(this->state==DELETE_PLANET_MENU){
            delete this->delete_planet_menu;
            this->delete_planet_menu=NULL;
            this->state=SIMULATION;
        }
        else if(this->state==PAUSE){
            delete this->pause_menu;
            this->pause_menu=NULL;
            this->state=SIMULATION;
            this->main_menu->changePauseSetting();
        }
    }
    else if(buttons["Add_planet"]){
        buttons["Add_planet"]=false;
        this->state=ADD_PLANET_MENU;
        this->universe->addTmpPlanetToUniverse(WHITE);
        this->add_planet_menu=new Add_Planet_Menu(this->window_width/4, this->window_height, 3*this->window_width/4);
    }
    else if(buttons["Delete_planet"]){
        buttons["Delete_planet"]=false;
        this->state=DELETE_PLANET_MENU;
        this->delete_planet_menu=new Delete_Planet_Menu(universe->getPlanets().size(), this->window_width/4, this->window_height, 3*this->window_width/4);
    }
    else if(buttons["Pause"]){
        buttons["Pause"]=false;
        this->state=PAUSE;
        this->pause_menu=new Pause_Menu(this->window_width, this->window_height);
        if(this->main_menu->getIsSimulationPaused()){
            this->main_menu->changePauseSetting();
        }
    }
}

void Simulation::drawSimulation(){
    static int marked_planet=-1;
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
            if(IsKeyPressed(KEY_L)){
                this->main_menu->lockUnlockCamera();
            }

            if(IsKeyPressed(KEY_P)){
                this->main_menu->changePauseSetting();
            }

            universe->calculateGravitiesOfPlanets(this->main_menu->getSpeed());
            grid2d->calculateGrid(universe->getPlanets());

            marked_planet=this->universe->findPlanetPointedAt(camera, DIVIDE_CONST, DISTANCE_CONST);

            BeginMode3D(camera);

            universe->drawUniverse(DIVIDE_CONST, DISTANCE_CONST);
            grid2d->drawGrid(DISTANCE_CONST);

            if(this->clicked_planet_menu && this->clicked_planet_menu->shouldMenuBeClosed()){
                delete this->clicked_planet_menu;
                this->clicked_planet_menu=NULL;
            }

            if(marked_planet!=-1){
                this->universe->getPlanets()[marked_planet].markPlanet(camera, DIVIDE_CONST, DISTANCE_CONST);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    if(this->clicked_planet_menu){
                        delete this->clicked_planet_menu;
                    }
                    this->clicked_planet_menu=new ClickedPlanetMenu(&this->universe->getPlanets()[marked_planet], this->window_width, this->window_height, 300, 400);
                }
            }

            EndMode3D();

            if(this->clicked_planet_menu){
                this->clicked_planet_menu->drawMenu();
            }

            if(!this->main_menu->getIsCameraLocked()){
                UpdateCameraCustom(&camera, CAMERA_FIRST_PERSON);
            }

            buttons["Add_planet"]=GuiButton((Rectangle){24, 24, 120, 30}, "Add planet.");
            buttons["Delete_planet"]=GuiButton((Rectangle){this->window_width-120-24, 24, 120, 30}, "Delete planet.");

            this->main_menu->drawMenu();

            buttons["Pause"]=GuiButton((Rectangle){this->window_width-144, this->window_height-40, 120, 30}, "Pause.");
        }break;
        case ADD_PLANET_MENU:{
            universe->calculateGravitiesOfPlanets(this->main_menu->getSpeed());
            grid2d->calculateGrid(universe->getPlanets());

            BeginMode3D(camera);

            universe->drawUniverse(DIVIDE_CONST, DISTANCE_CONST);
            grid2d->drawGrid(DISTANCE_CONST);

            EndMode3D();

            this->add_planet_menu->drawMenu();

            this->universe->setOptionsForTmpPlanet(add_planet_menu->getRadius(), add_planet_menu->getMass(), add_planet_menu->getAngle(), add_planet_menu->getDistanceFromCenter(), add_planet_menu->getvelocity(), add_planet_menu->getColor(), add_planet_menu->getName());

            buttons["Go_back"]=GuiButton((Rectangle){5*this->window_width/6, 850, 100, 30}, "Go back.");

            if(GuiButton((Rectangle){5*this->window_width/6+130, 850, 100, 30}, "Accept planet.")){
                universe->acceptPlanetToUniverse();
                buttons["Go_back"]=true;
            }
        }break;
        case DELETE_PLANET_MENU:{
            universe->calculateGravitiesOfPlanets(this->main_menu->getSpeed());
            grid2d->calculateGrid(universe->getPlanets());

            BeginMode3D(camera);

            universe->drawUniverse(DIVIDE_CONST, DISTANCE_CONST);
            grid2d->drawGrid(DISTANCE_CONST);

            EndMode3D();

            delete_planet_menu->drawMenu(this->universe->getPlanets());

            if(delete_planet_menu->getGoBackButton()){
                buttons["Go_back"]=true;
            }
            else if(delete_planet_menu->getDeletePlanets()){
                universe->deletePlanetsFromUniverse(delete_planet_menu->getToDelete());
                buttons["Go_back"]=true;
            }
        }break;
        case PAUSE:{
            if(this->pause_menu->getGoBackButton()){
                this->buttons["Go_back"]=true;
            }
            else if(this->pause_menu->getExitButton()){
                this->buttons["Exit"]=true;
            }
            this->pause_menu->drawMenu();
        }break;
        default: break;
    }

    EndDrawing();
}