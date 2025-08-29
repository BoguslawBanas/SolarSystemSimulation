#include "../header_files/add_planet_menu.h"

Add_Planet_Menu::Add_Planet_Menu(unsigned menu_width, unsigned menu_height, unsigned start_menu_width){
    this->menu_width=menu_width;
    this->menu_height=menu_height;
    this->start_menu_width=start_menu_width;
    this->radius=0.1f;
    this->mass=0.1f;
    this->distance_from_center=0.1f;
    this->angle=0.f;
    this->color=WHITE;
}

Add_Planet_Menu::~Add_Planet_Menu()=default;

float Add_Planet_Menu::getRadius() const{
    return this->radius;
}

float Add_Planet_Menu::getMass() const{
    return this->mass;
}

float Add_Planet_Menu::getAngle() const{
    return this->angle;
}

float Add_Planet_Menu::getDistanceFromCenter() const{
    return this->distance_from_center;
}

float Add_Planet_Menu::getvelocity() const{
    return this->velocity;
}

Color Add_Planet_Menu::getColor() const{
    return this->color;
}

void Add_Planet_Menu::drawMenu(){
    snprintf(this->radius_str, 15, "%f", this->radius);
    snprintf(this->mass_str, 15, "%f", this->mass);
    snprintf(this->angle_str, 15, "%f", this->angle);
    snprintf(this->distance_from_center_str, 15, "%f", this->distance_from_center);
    snprintf(this->velocity_str, 15, "%f", this->velocity);

    DrawRectangle(this->start_menu_width, 0, this->menu_width, this->menu_height, WHITE);

    GuiSlider((Rectangle){this->start_menu_width+20, 120, 180, 30}, "0", "max", &this->mass, 0.f, 1e24f);
    GuiTextBox((Rectangle){this->start_menu_width+230, 120, 120, 30}, this->mass_str, 10, true);

    GuiSlider((Rectangle){this->start_menu_width+20, 120, 180, 30}, "0", "max", &this->mass, 0.f, 1e24f);
    GuiTextBox((Rectangle){this->start_menu_width+230, 120, 120, 30}, this->mass_str, 10, false);

    GuiSlider((Rectangle){this->start_menu_width+20, 240, 180, 30}, "0", "max", &this->radius, 0.f, 1e6f);
    GuiTextBox((Rectangle){this->start_menu_width+230, 240, 120, 30}, this->radius_str, 10, false);

    GuiSlider((Rectangle){this->start_menu_width+20, 360, 180, 30}, "0", "6.28", &this->angle, 0.f, 2*M_PI);
    GuiTextBox((Rectangle){this->start_menu_width+230, 360, 120, 30}, this->angle_str, 10, false);

    GuiSlider((Rectangle){this->start_menu_width+20, 480, 180, 30}, "0", "max", &this->distance_from_center, 0.f, 1e9f);
    GuiTextBox((Rectangle){this->start_menu_width+230, 480, 120, 30}, this->distance_from_center_str, 10, false);

    GuiSlider((Rectangle){this->start_menu_width+20, 600, 180, 30}, "0", "max", &this->velocity, 0.f, 1e6f);
    GuiTextBox((Rectangle){this->start_menu_width+230, 600, 120, 30}, this->velocity_str, 10, false);

    GuiColorPicker((Rectangle){this->start_menu_width+20, 750, 180, 30}, "Choose color", &this->color);
}