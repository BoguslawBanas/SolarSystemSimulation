#include "Delete_Planet_Menu_Controller.h"
#include "../header_files/raygui.h"

Delete_Planet_Menu_Controller::Delete_Planet_Menu_Controller(const unsigned window_width, const unsigned window_height, const unsigned amount_of_planets){
    this->model=new Delete_Planet_Menu_Model();
    this->view=new Delete_Planet_Menu_View(window_width, window_height);
    this->list_of_checkboxes=new bool[amount_of_planets];
    for(int i=0;i<amount_of_planets;++i){
        this->list_of_checkboxes[i]=false;
    }
    this->scrollBarVector=Vector2{};
    this->rectangleView=Rectangle{};
}   

Delete_Planet_Menu_Controller::~Delete_Planet_Menu_Controller(){
    delete this->model;
    delete this->view;
    delete[] this->list_of_checkboxes;
}

bool Delete_Planet_Menu_Controller::getErasingChosenPlanetsButton() const{
    return this->erase_chosen_planets_button;
}

bool Delete_Planet_Menu_Controller::getGoBackButton() const{
    return this->go_back_button; 
}

void Delete_Planet_Menu_Controller::requestDrawing(const std::vector<Planet_Model*>&planets){
    this->view->draw();
    unsigned height=100;
    int counter=0;

    GuiScrollPanel(Rectangle{1100, 90, 300, 250}, NULL, Rectangle{1100, 90, 300, 700}, &this->scrollBarVector, &this->rectangleView);

    BeginScissorMode(this->rectangleView.x, this->rectangleView.y, this->rectangleView.width, this->rectangleView.height);
    for(int i=int(-this->scrollBarVector.y)/40;i<planets.size() && counter<6;++i){
        GuiCheckBox(Rectangle{1120, height-5.f, 10, 10}, planets[i]->getName(), &this->list_of_checkboxes[counter]);
        height+=40;
        ++counter;
    }

    EndScissorMode();

    this->go_back_button=GuiButton(Rectangle{1100, 820, 90, 30}, "Go back.");
    this->erase_chosen_planets_button=GuiButton(Rectangle{1320, 820, 90, 30}, "Erase planets.");
}