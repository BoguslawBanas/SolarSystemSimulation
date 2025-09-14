#include "../header_files/clicked_planet_menu.h"
#include "../header_files/raygui.h"

ClickedPlanetMenu::ClickedPlanetMenu(Planet* const planet, const unsigned window_width, const unsigned window_height, const unsigned menu_width, const unsigned menu_height){
    this->planet=planet;
    this->window_width=window_width;
    this->window_height=window_height;
    this->menu_width=menu_width;
    this->menu_height=menu_height;
}

ClickedPlanetMenu::~ClickedPlanetMenu(){
    this->planet=NULL;
}

void ClickedPlanetMenu::changePlanet(Planet * const new_planet){
    this->planet=new_planet;
}

bool ClickedPlanetMenu::shouldMenuBeClosed(){
    return this->is_closed==0;
}

void ClickedPlanetMenu::drawMenu(){
    DrawRectangle(0, this->window_height-this->menu_height, this->menu_width, this->menu_height, WHITE);
    this->is_closed=GuiButton((Rectangle){this->menu_width/3, this->window_height-50, this->menu_width/3, 30}, "Exit.");
}