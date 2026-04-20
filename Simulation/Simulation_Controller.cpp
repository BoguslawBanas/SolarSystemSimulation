#include "simulation_controller.h"
#include "../header_files/rcamera.h"

void Simulation_Controller::calcLogic(){
    Simulation_State state=this->simulation_model->getState();

    switch(state){
        case START_MENU:{
            this->start_menu->calcLogic();
            switch(this->start_menu->getState()){
                case TRANSITION_TO_SIMULATION:{
                    this->simulation_model->setState(SIMULATION);
                    this->getUniverseController()->addPlanet(Vector3{0.1l, 0.1l, 0.l}, Vector3{0.l, 0.l, 0.l}, SUN_RADIUS/6, SUN_MASS, YELLOW, "Sun", PATH_TO_SUN_TEXTURE); //Sun
                    this->getUniverseController()->addPlanet(Vector3{MERCURY_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000.l*1.l}, MERCURY_RADIUS, MERCURY_MASS, DARKBROWN, "Mercury", PATH_TO_MERCURY_TEXTURE); //Mercury
                    this->getUniverseController()->addPlanet(Vector3{VENUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000*0.73l}, VENUS_RADIUS, VENUS_MASS, BROWN, "Venus", PATH_TO_VENUS_TEXTURE); //Venus
                    this->getUniverseController()->addPlanet(Vector3{EARTH_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000*0.622l}, EARTH_RADIUS, EARTH_MASS, GREEN, "Earth", PATH_TO_EARTH_TEXTURE); //Earth
                    this->getUniverseController()->addPlanet(Vector3{MARS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000*0.503l}, MARS_RADIUS, MARS_MASS, RED, "Mars", PATH_TO_MARS_TEXTURE); //Mars
                    this->getUniverseController()->addPlanet(Vector3{JUPITER_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000*0.273l}, JUPITER_RADIUS, JUPITER_MASS, LIGHTGRAY, "Jupiter", PATH_TO_JUPITER_TEXTURE); //Jupiter
                    this->getUniverseController()->addPlanet(Vector3{SATURN_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000*0.203l}, SATURN_RADIUS, SATURN_MASS, GRAY, "Saturn", PATH_TO_SATURN_TEXTURE); //Saturn
                    this->getUniverseController()->addPlanet(Vector3{URANUS_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000*0.142l}, URANUS_RADIUS, URANUS_MASS, BLUE, "Uranus", PATH_TO_URANUS_TEXTURE); //Uranus
                    this->getUniverseController()->addPlanet(Vector3{NEPTUNE_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000*0.113l}, NEPTUNE_RADIUS, NEPTUNE_MASS, BLUE, "Neptune", PATH_TO_NEPTUNE_TEXTURE); //Neptune
                    // this->getUniverseController()->addPlanet(Vector3{PLUTO_DISTANCE_FROM_SUN+SUN_RADIUS, 0.l, 0.l}, Vector3{0.l, 0.l, 1200000*0.099l}, PLUTO_RADIUS, PLUTO_MASS, GRAY, "Pluto"); //Pluto

                    UnloadMusicStream(this->music);

                    this->music=LoadMusicStream("music/Aylex - Tension Rising (freetouse.com).mp3");
                    PlayMusicStream(this->music);
                    SetMusicVolume(this->music, 0.5f);
                } break;
                case START_MENU_EXIT:{
                    this->simulation_model->setState(EXIT);
                } break;
            }
        } break;
        case SIMULATION:{
            this->main_menu->calcLogic();
            if(this->grid){
                this->grid->calcLogic(this->getUniverseController()->getModel()->getPlanets());
            }
            if(!this->main_menu->getIsCameraLocked()){
                UpdateCameraCustom(&camera, 1);
            }
            if(this->main_menu->getIsAddNewPlanetButtonClicked()){
                this->simulation_model->setAddPlanet(true);
                this->getUniverseController()->addTmpPlanet();
            }
            if(this->simulation_model->getAddPlanet()){
                this->simulation_model->setAddPlanet(false);
                this->simulation_model->setState(ADD_PLANET_MENU);
                this->add_planet_menu=new Add_Planet_Menu_Controller(this->simulation_view->getWindowWidth(), this->simulation_view->getWindowHeight());
                this->universe_controller->addTmpPlanet();
            }
            this->universe_controller->updateNewPositionsOfPlanets(this->main_menu->getSliderResult());
        } break;
        case ADD_PLANET_MENU:{
            this->main_menu->calcLogic();
            this->add_planet_menu->calcLogic();
            this->universe_controller->updateTmpPlanet(this->add_planet_menu->getMass(), this->add_planet_menu->getRadius(), \
            this->add_planet_menu->getDistanceFromCenter(), this->add_planet_menu->getVelocity(), this->add_planet_menu->getColor());

            if(!this->main_menu->getIsCameraLocked()){
                UpdateCameraCustom(&camera, 1);
            }

            if(this->add_planet_menu->getAcceptNewPlanetButton()){
                this->getUniverseController()->addTmpPlanetToUniverse();
                this->simulation_model->setState(SIMULATION);
                this->getUniverseController()->deleteTmpPlanet();
                delete this->add_planet_menu;
                this->add_planet_menu=NULL;
            }
            else if(this->add_planet_menu->getGoBackButton()){
                this->simulation_model->setState(SIMULATION);
                this->getUniverseController()->deleteTmpPlanet();
                delete this->add_planet_menu;
                this->add_planet_menu=NULL;
            }
            this->universe_controller->updateNewPositionsOfPlanets(this->main_menu->getSliderResult());
        } break;
        case DELETE_PLANET_MENU:{
            
        } break;
        case PAUSE:{

        } break;
        case EXIT:{
            
        } break;
    }

    UpdateMusicStream(this->music);
}

void Simulation_Controller::drawNextFrame(){
    Simulation_State state=this->simulation_model->getState();
    unsigned window_width=this->simulation_view->getWindowWidth();
    unsigned window_height=this->simulation_view->getWindowHeight();

    BeginDrawing();
    ClearBackground(BLACK);

    switch(state){
        case START_MENU:{
            this->start_menu->requestDrawing();
        } break;
        case SIMULATION:{
            BeginMode3D(camera);
            if(this->grid){
                this->grid->requestDrawing();
            }
            this->universe_controller->requestDrawing(this->getUniverseController()->findPlanetPointedAt(this->camera));
            EndMode3D();

            this->main_menu->requestDrawing();

            if(this->add_planet_menu){
                this->add_planet_menu->requestDrawing();
            }
        } break;
        case ADD_PLANET_MENU:{
            BeginMode3D(camera);
            if(this->grid){
                this->grid->requestDrawing();
            }

            this->universe_controller->requestDrawing(this->getUniverseController()->findPlanetPointedAt(this->camera));
            EndMode3D();

            this->add_planet_menu->requestDrawing();
        } break;
        case DELETE_PLANET_MENU:{
            
        } break;
        case PAUSE:{

        } break;
        case EXIT:{

        } break;
    }

    EndDrawing();
}

Simulation_Controller::Simulation_Controller(const char *path){
    char str[512];
    unsigned window_width=1000;
    unsigned window_height=600;
    unsigned amount_of_nodes=50;

    double distance_div=3e6;
    double radius_div=1e4;
    double start_pos=-1e10;

    float default_height=-5.f;
    float camera_fov=45.f;
    Vector3 camera_target={};
    Vector3 camera_position={};
    camera_position.x=100.f;
    camera_position.y=100.f;
    camera_position.z=100.f;
    Vector3 camera_up={};
    camera_up.y=1.f;

    FILE *f=fopen(path, "r");
    if(f){
        while(fscanf(f, "%510s", str)==1){
            if(strcmp(str, "window_width")==0){
                fscanf(f, "%u", &window_width);
            }
            else if(strcmp(str, "window_height")==0){
                fscanf(f, "%u", &window_height);
            }
            else if(strcmp(str, "start_pos")==0){
                fscanf(f, "%lf", &start_pos);
            }
            else if(strcmp(str, "amount_of_nodes")==0){
                fscanf(f, "%u", &amount_of_nodes);
            }
            else if(strcmp(str, "default_height_of_the_grid")==0){
                fscanf(f, "%f", &default_height);
            }
            else if(strcmp(str, "camera_fov")==0){
                fscanf(f, "%f", &camera_fov);
            }
            else if(strcmp(str, "camera_target")==0){
                fscanf(f, "%f %f %f", &camera_target.x, &camera_target.y, &camera_target.z);
            }
            else if(strcmp(str, "camera_position")==0){
                fscanf(f, "%f %f %f", &camera_position.x, &camera_position.y, &camera_position.z);
            }
            else if(strcmp(str, "camera_up")==0){
                fscanf(f, "%f %f %f", &camera_up.x, &camera_up.y, &camera_up.z);
            }
            else if(strcmp(str, "distance_divider")==0){
                fscanf(f, "%lf", &distance_div);
            }
            else if(strcmp(str, "radius_divider")==0){
                fscanf(f, "%lf", &radius_div);
            }
        }
    }
    fclose(f);

    InitAudioDevice();
    // this->music=LoadMusicStream("Procedural_Jiggle_Bone.mp3");
    this->music=LoadMusicStream("music/Project Ex - Neo Nebula (freetouse.com).mp3");
    PlayMusicStream(this->music);
    SetMusicVolume(this->music, 0.3f);

    this->simulation_model=new Simulation_Model();
    this->simulation_view=new Simulation_View(window_width, window_height);
    this->universe_controller=new Universe_Controller(distance_div, radius_div);
    this->main_menu=new Main_Menu_Controller(window_width, window_height);
    this->grid=new Gravitational_Grid_2D_Controller(start_pos, amount_of_nodes, default_height, distance_div);
    this->start_menu=new Start_Menu_Controller(window_width, window_height);
    this->add_planet_menu=NULL;
    this->is_esc_clicked=false;

    this->camera={};
    this->camera.fovy=camera_fov;
    this->camera.position=camera_position;
    this->camera.target=camera_target;
    this->camera.up=camera_up;
}

Simulation_Controller::~Simulation_Controller(){
    delete this->simulation_model;
    delete this->simulation_view;
    delete this->universe_controller;
    delete this->grid;
    delete this->main_menu;
    delete this->add_planet_menu;
    delete this->options;
    UnloadMusicStream(this->music);
    CloseAudioDevice();
}

Universe_Controller* Simulation_Controller::getUniverseController(){
    return this->universe_controller;
}

void Simulation_Controller::simulationLoop(){
    while(!WindowShouldClose() && this->simulation_model->getState()!=EXIT){
        this->calcLogic();
        this->drawNextFrame();
    }
}