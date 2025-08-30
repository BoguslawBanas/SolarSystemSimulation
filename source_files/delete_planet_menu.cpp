#include "../header_files/delete_planet_menu.h"
#include "../header_files/raygui.h"

Delete_Planet_Menu::Delete_Planet_Menu(const unsigned amount_of_planets){
    this->go_back_button=false;
    this->delete_planets=false;
    this->amount_of_planets=amount_of_planets;
    this->to_delete=std::vector<char>(amount_of_planets, 0);
}

Delete_Planet_Menu::~Delete_Planet_Menu()=default;

bool Delete_Planet_Menu::getGoBackButton() const{
    return this->go_back_button;
}

bool Delete_Planet_Menu::getDeletePlanets() const{
    return this->delete_planets;
}

const std::vector<char>& Delete_Planet_Menu::getToDelete() const{
    return this->to_delete;
}

void Delete_Planet_Menu::drawMenu(const std::vector<Planet>& planets){
    for(int i=0;i<planets.size();++i){
        GuiCheckBox((Rectangle){50, 30+i*50, 15, 15}, planets[i].getName(), (bool*)&this->to_delete[i]);
    }

    this->delete_planets=GuiButton((Rectangle){1100, 850, 100, 30}, "Delete planets."); //change later
    this->go_back_button=GuiButton((Rectangle){1300, 850, 100, 30}, "Go back."); //change later
}