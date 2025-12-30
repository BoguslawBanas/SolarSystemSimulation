#ifndef MAIN_MENU_CONTROLLER_H
#define MAIN_MENU_CONTROLLER_H

#include "Main_Menu_Model.h"
#include "Main_Menu_View.h"
#include "../Slider_Textfield_Menu/Slider_Textfield_Menu_Controller.h"

class Main_Menu_Controller{
    private:
    Main_Menu_Model *menu_model;
    Main_Menu_View *menu_view;
    Slider_Textfield_Menu_Controller *slider;
    bool is_camera_locked;
    bool is_simulation_paused;
    bool add_new_planet;
    float tmp_v;

    public:
    Main_Menu_Controller(const unsigned, const unsigned);

    ~Main_Menu_Controller();

    float getSliderResult() const;
    
    void lockUnlockCamera();

    bool getIsCameraLocked() const;

    void pauseUnpauseSimulation();

    bool getIsAddNewPlanetButtonClicked() const;

    void calcLogic();

    void requestDrawing();
};

#endif