#include "../header_files/pause_menu.h"
#include "../header_files/raygui.h"

Pause_Menu::Pause_Menu(const unsigned window_width, const unsigned window_height){
    this->window_width=window_width;
    this->window_height=window_height;
    this->go_back_button=false;
    this->exit_buttton=false;
    this->save_simulation_button=false;
    this->read_simulation_button=false;
}

Pause_Menu::~Pause_Menu()=default;

bool Pause_Menu::getGoBackButton() const{
    return this->go_back_button;
}

bool Pause_Menu::getExitButton() const{
    return this->exit_buttton;
}

bool Pause_Menu::getSaveSimulationButton() const{
    return this->save_simulation_button;
}

bool Pause_Menu::getReadSimulationButton() const{
    return this->read_simulation_button;
}

void Pause_Menu::drawMenu(){
    this->go_back_button=GuiButton((Rectangle){this->window_width/5, this->window_height/2-20, 100, 40}, "Go back.");
    this->exit_buttton=GuiButton((Rectangle){2*this->window_width/5, this->window_height/2-20, 100, 40}, "Exit simulation.");
    this->save_simulation_button=GuiButton((Rectangle){3*this->window_width/5, this->window_height/2-20, 100, 40}, "Save simulation.");
    this->read_simulation_button=GuiButton((Rectangle){4*this->window_width/5, this->window_height/2-20, 100, 40}, "Read simulation.");
}