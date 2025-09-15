#include "../header_files/clicked_planet_menu.h"
#include "../header_files/raygui.h"

ClickedPlanetMenu::ClickedPlanetMenu(Planet* const planet, const unsigned window_width, const unsigned window_height, const unsigned menu_width, const unsigned menu_height){
    this->planet=planet;
    this->window_width=window_width;
    this->window_height=window_height;
    this->menu_width=menu_width;
    this->menu_height=menu_height;
    this->mass_str[0]='\0';
    this->speed_str[0]='\0';
    this->radius_str[0]='\0';
}

ClickedPlanetMenu::~ClickedPlanetMenu(){
    this->planet=NULL;
}

void ClickedPlanetMenu::changePlanet(Planet * const new_planet){
    this->planet=new_planet;
}

bool ClickedPlanetMenu::shouldMenuBeClosed(){
    return this->is_closed!=0;
}

void ClickedPlanetMenu::drawMenu(){
    float speed=fabs(this->planet->getVelocity().x)+fabs(this->planet->getVelocity().y)+fabs(this->planet->getVelocity().z);
    snprintf(this->mass_str, 25, "%1.4Le", this->planet->getMass());
    snprintf(this->speed_str, 25, "%1.4e", speed);
    snprintf(this->radius_str, 25, "%1.4Le", this->planet->getRadius());

    DrawRectangle(0, this->window_height-this->menu_height, this->menu_width, this->menu_height, WHITE);

    DrawText("Planet's name: ", this->menu_width/10, this->window_height-this->menu_height+50, 15, GRAY);
    DrawText(this->planet->getName(), this->menu_width/10+110, this->window_height-this->menu_height+50, 15, GRAY);

    DrawText("Planet's radius: ", this->menu_width/10, this->window_height-this->menu_height+100, 15, GRAY);
    DrawText(this->radius_str, this->menu_width/10+122, this->window_height-this->menu_height+100, 15, GRAY);

    DrawText("Planet's mass: ", this->menu_width/10, this->window_height-this->menu_height+150, 15, GRAY);
    DrawText(this->mass_str, this->menu_width/10+110, this->window_height-this->menu_height+150, 15, GRAY);

    DrawText("Planet's velocity: ", this->menu_width/10, this->window_height-this->menu_height+200, 15, GRAY);
    DrawText(this->speed_str, this->menu_width/10+130, this->window_height-this->menu_height+200, 15, GRAY);

    // DrawText("Planet's distance: ", this->menu_width/10, this->window_height-this->menu_height+250, 15, GRAY);
    // DrawText(this->planet->getName(), this->menu_width/5, this->window_height-this->menu_height+250, 15, GRAY);

    this->is_closed=GuiButton((Rectangle){this->menu_width/3, this->window_height-50, this->menu_width/3, 30}, "Exit.");
}