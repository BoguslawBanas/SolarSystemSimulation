#ifndef START_MENU_CONTROLLER_H
#define START_MENU_CONTROLLER_H

#include <raylib.h>
#include <math.h>
#include "Start_Menu_Model.h"
#include "Start_Menu_View.h"

enum Start_Menu_State{
    START_MENU1,
    START_MENU2,
    TRANSITION_TO_START_MENU1,
    TRANSITION_TO_START_MENU2,
    TRANSITION_TO_SIMULATION,
    TRANSITION_TO_SIMULATION_FREE_MODE,
    START_MENU_SETTINGS,
    START_MENU_EXIT
};

class Start_Menu_Controller{
    private:
    Start_Menu_State state;
    Start_Menu_Model *model;
    Start_Menu_View *view;
    Camera3D camera;
    int counter;

    public:
    Start_Menu_Controller(const unsigned, const unsigned);

    ~Start_Menu_Controller();

    const Start_Menu_State getState() const;

    void calcLogic();

    void requestDrawing();
};

#endif