#include "../header_files/add_planet_menu.h"

Add_Planet_Menu::Add_Planet_Menu(unsigned menu_width, unsigned menu_height, unsigned start_menu_width){
    this->menu_width=menu_width;
    this->menu_height=menu_height;
    this->start_menu_width=start_menu_width;
    this->is_name_text_field_clicked=false;
    this->color=WHITE;
    this->mass_menu=new SliderTextfieldMenu((Rectangle){this->start_menu_width+20, 200, 180, 30}, (Rectangle){this->start_menu_width+230, 200, 120, 30}, 0.f, 1e24f);
    this->radius_menu=new SliderTextfieldMenu((Rectangle){this->start_menu_width+20, 300, 180, 30}, (Rectangle){this->start_menu_width+230, 300, 120, 30}, 0.f, 1e6f);
    this->angle_menu=new SliderTextfieldMenu((Rectangle){this->start_menu_width+20, 400, 180, 30}, (Rectangle){this->start_menu_width+230, 400, 120, 30}, 0.f, 2*M_PI);
    this->distance_from_center_menu=new SliderTextfieldMenu((Rectangle){this->start_menu_width+20, 500, 180, 30}, (Rectangle){this->start_menu_width+230, 500, 120, 30}, 0.f, 1e9f);
    this->velocity_menu=new SliderTextfieldMenu((Rectangle){this->start_menu_width+20, 600, 180, 30}, (Rectangle){this->start_menu_width+230, 600, 120, 30}, 0.f, 1e6f);
    this->name[0]='\0';
}

Add_Planet_Menu::~Add_Planet_Menu(){
    delete this->radius_menu;
    delete this->mass_menu;
    delete this->angle_menu;
    delete this->distance_from_center_menu;
    delete this->velocity_menu;
}

const char* Add_Planet_Menu::getName() const{
    return this->name;
}

float Add_Planet_Menu::getRadius() const{
    return this->radius_menu->getSliderResult();
}

float Add_Planet_Menu::getMass() const{
    return this->mass_menu->getSliderResult();
}

float Add_Planet_Menu::getAngle() const{
    return this->angle_menu->getSliderResult();
}

float Add_Planet_Menu::getDistanceFromCenter() const{
    return this->distance_from_center_menu->getSliderResult();
}

float Add_Planet_Menu::getvelocity() const{
    return this->velocity_menu->getSliderResult();
}

Color Add_Planet_Menu::getColor() const{
    return this->color;
}

void Add_Planet_Menu::drawMenu(){
    DrawRectangle(this->start_menu_width, 0, this->menu_width, this->menu_height, WHITE);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMousePosition().x>this->start_menu_width+20 && GetMousePosition().y>100 && GetMousePosition().x<this->start_menu_width+200 && GetMousePosition().y<130){
        this->is_name_text_field_clicked=true;
    }
    else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        this->is_name_text_field_clicked=false;
    }
    GuiTextBox((Rectangle){this->start_menu_width+20, 100, 180, 30}, this->name, 50, this->is_name_text_field_clicked);

    this->mass_menu->drawMenu();
    this->radius_menu->drawMenu();
    this->angle_menu->drawMenu();
    this->distance_from_center_menu->drawMenu();
    this->velocity_menu->drawMenu();

    GuiColorPicker((Rectangle){this->start_menu_width+20, 700, 180, 80}, "Choose color", &this->color);
}