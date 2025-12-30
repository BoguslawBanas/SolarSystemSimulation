#ifndef ADD_PLANET_MENU_CONTROLLER_H
#define ADD_PLANET_MENU_CONTROLLER_H

#include "Add_Planet_Menu_Model.h"
#include "Add_Planet_Menu_View.h"
#include "../Slider_Textfield_Menu/Slider_Textfield_Menu_Controller.h"
#include "../header_files/solar_system_consts.h"

class Add_Planet_Menu_Controller{
    private:
    Add_Planet_Menu_View *view;
    Add_Planet_Menu_Model *model;
    Slider_Textfield_Menu_Controller *mass_menu;
    Slider_Textfield_Menu_Controller *radius_menu;
    Slider_Textfield_Menu_Controller *distance_from_center_x_menu;
    Slider_Textfield_Menu_Controller *distance_from_center_y_menu;
    Slider_Textfield_Menu_Controller *distance_from_center_z_menu;
    Slider_Textfield_Menu_Controller *velocity_x_menu;
    Slider_Textfield_Menu_Controller *velocity_y_menu;
    Slider_Textfield_Menu_Controller *velocity_z_menu;
    bool accept_new_planet;
    bool go_back_button;
    char name[256];
    Color color;

    public:
    Add_Planet_Menu_Controller(const unsigned, const unsigned);

    ~Add_Planet_Menu_Controller();

    void calcLogic();

    void requestDrawing();

    bool getAcceptNewPlanetButton() const;

    bool getGoBackButton() const;

    float getMass() const;

    float getRadius() const;

    const Vector3 getDistanceFromCenter() const;

    const Vector3 getVelocity() const;

    Color getColor() const;

    const char* getName() const;
};

#endif