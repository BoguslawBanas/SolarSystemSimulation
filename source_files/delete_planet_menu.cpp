#include "../header_files/delete_planet_menu.h"
#include "../header_files/raygui.h"

Delete_Planet_Menu::Delete_Planet_Menu(const unsigned amount_of_planets, const unsigned width, const unsigned height, const unsigned start_width){
    this->go_back_button=false;
    this->delete_planets=false;
    this->menu_width=width;
    this->menu_height=height;
    this->start_menu_width=start_width;
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
    static Vector2 v2={};
    static char s[20]={};
    snprintf(s, 20, "%f", v2.y);
    DrawRectangle(this->start_menu_width, 0, this->menu_width, this->menu_height, WHITE);
    DrawText("Choose planets to delete from universe.", this->start_menu_width+10, 30, 15, RED);

    GuiScrollPanel((Rectangle){this->start_menu_width+20, 80, this->menu_width-40, 300}, NULL, (Rectangle){this->start_menu_width+20, 80, this->menu_width-40, 800}, &v2, NULL);

    DrawText(s, 30, 30, 15, BLUE);

    int i=-v2.y/(517/(planets.size()-6+1));
    int j=i+6;

    for(int k=0;k<6 && i<planets.size();++k){
        GuiCheckBox((Rectangle){this->start_menu_width+30, 90+k*50, 15, 15}, planets[i].getName(), (bool*)&this->to_delete[i]);
        ++i;
    }

    this->delete_planets=GuiButton((Rectangle){this->start_menu_width+50, this->menu_height-100, 100, 30}, "Delete planets."); //change later
    this->go_back_button=GuiButton((Rectangle){this->start_menu_width+220, this->menu_height-100, 100, 30}, "Go back."); //change later
}