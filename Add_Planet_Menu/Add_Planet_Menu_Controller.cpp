#include "Add_Planet_Menu_Controller.h"

Add_Planet_Menu_Controller::Add_Planet_Menu_Controller(const unsigned window_width, const unsigned window_height){
    this->view=new Add_Planet_Menu_View(window_width, window_height);
    this->model=new Add_Planet_Menu_Model();
    float w=3.f*window_width/4.f+30;
    this->mass_menu=new Slider_Textfield_Menu_Controller(0.f, SUN_MASS, Rectangle{w, 130, 180, 30}, Rectangle{w+220, 130, 100, 30});
    this->radius_menu=new Slider_Textfield_Menu_Controller(0.f, SUN_RADIUS*2.f, Rectangle{w, 200, 180, 30}, Rectangle{w+220, 200, 100, 30});
    this->distance_from_center_x_menu=new Slider_Textfield_Menu_Controller(-PLUTO_DISTANCE_FROM_SUN, PLUTO_DISTANCE_FROM_SUN, Rectangle{w, 280, 180, 30}, Rectangle{w+220, 280, 100, 30});
    this->distance_from_center_y_menu=new Slider_Textfield_Menu_Controller(-PLUTO_DISTANCE_FROM_SUN, PLUTO_DISTANCE_FROM_SUN, Rectangle{w, 330, 180, 30}, Rectangle{w+220, 330, 100, 30});
    this->distance_from_center_z_menu=new Slider_Textfield_Menu_Controller(-PLUTO_DISTANCE_FROM_SUN, PLUTO_DISTANCE_FROM_SUN, Rectangle{w, 380, 180, 30}, Rectangle{w+220, 380, 100, 30});
    this->velocity_x_menu=new Slider_Textfield_Menu_Controller(0.f, 1e6f, Rectangle{w, 460, 180, 30}, Rectangle{w+220, 460, 100, 30});
    this->velocity_y_menu=new Slider_Textfield_Menu_Controller(0.f, 1e6f, Rectangle{w, 510, 180, 30}, Rectangle{w+220, 510, 100, 30});
    this->velocity_z_menu=new Slider_Textfield_Menu_Controller(0.f, 1e6f, Rectangle{w, 560, 180, 30}, Rectangle{w+220, 560, 100, 30});
    this->color=Color{128, 0, 0, 255};
    this->name[0]='\0';
}

Add_Planet_Menu_Controller::~Add_Planet_Menu_Controller(){
    delete this->mass_menu;
    delete this->radius_menu;
    delete this->distance_from_center_x_menu;
    delete this->distance_from_center_y_menu;
    delete this->distance_from_center_z_menu;
    delete this->velocity_x_menu;
    delete this->velocity_y_menu;
    delete this->velocity_z_menu;
    delete this->view;
    delete this->model;
}

void Add_Planet_Menu_Controller::calcLogic(){
    this->mass_menu->calcLogic();
    this->radius_menu->calcLogic();
    this->distance_from_center_x_menu->calcLogic();
    this->distance_from_center_y_menu->calcLogic();
    this->distance_from_center_z_menu->calcLogic();
    this->velocity_x_menu->calcLogic();
    this->velocity_y_menu->calcLogic();
    this->velocity_z_menu->calcLogic();
}

void Add_Planet_Menu_Controller::requestDrawing(){
    this->view->draw();
    GuiTextBox(Rectangle{1160, 55, 200, 50}, this->name, 255, true);
    this->mass_menu->requestDrawing();
    this->radius_menu->requestDrawing();
    this->distance_from_center_x_menu->requestDrawing();
    this->distance_from_center_y_menu->requestDrawing();
    this->distance_from_center_z_menu->requestDrawing();
    this->velocity_x_menu->requestDrawing();
    this->velocity_y_menu->requestDrawing();
    this->velocity_z_menu->requestDrawing();
    GuiColorPicker(Rectangle{1100, 650, 250, 200}, "Choose color.", &this->color); //I'm not a big fan of that but it works.
    this->accept_new_planet=GuiButton(Rectangle{1100, 870, 90, 30}, "Accpet new planet.");
    this->go_back_button=GuiButton(Rectangle{1320, 870, 90, 30}, "Go back.");
}

bool Add_Planet_Menu_Controller::getAcceptNewPlanetButton() const{
    return this->accept_new_planet;
}

bool Add_Planet_Menu_Controller::getGoBackButton() const{
    return this->go_back_button;
}

float Add_Planet_Menu_Controller::getMass() const{
    return this->mass_menu->getDirectValue();
}

float Add_Planet_Menu_Controller::getRadius() const{
    return this->radius_menu->getDirectValue();
}

const Vector3 Add_Planet_Menu_Controller::getDistanceFromCenter() const{
    return Vector3{this->distance_from_center_x_menu->getDirectValue(), this->distance_from_center_y_menu->getDirectValue(), this->distance_from_center_z_menu->getDirectValue()};
}

const Vector3 Add_Planet_Menu_Controller::getVelocity() const{
    return Vector3{this->velocity_x_menu->getDirectValue(), this->velocity_y_menu->getDirectValue(), this->velocity_z_menu->getDirectValue()};
}

Color Add_Planet_Menu_Controller::getColor() const{
    return this->color;
}

const char* Add_Planet_Menu_Controller::getName() const{
    return this->name;
}