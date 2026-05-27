#include "Delete_Planet_Menu_Controller.h"
#include "../header_files/raygui.h"

Delete_Planet_Menu_Controller::Delete_Planet_Menu_Controller(const unsigned window_width, const unsigned window_height, const unsigned amount_of_planets){
    this->model=new Delete_Planet_Menu_Model();
    this->view=new Delete_Planet_Menu_View(window_width, window_height);
    this->scrollBarVector=Vector2{};
    this->rectangleView=Rectangle{};
    this->state=DELETE_PLANET_MENU_STATE;
}   

Delete_Planet_Menu_Controller::~Delete_Planet_Menu_Controller(){
    delete this->model;
    delete this->view;
}

bool Delete_Planet_Menu_Controller::getErasingChosenPlanetsButton() const{
    return this->accept_erasing_planets_button;
}

bool Delete_Planet_Menu_Controller::getGoBackButton() const{
    return this->go_back_button; 
}

void Delete_Planet_Menu_Controller::calcLogic(const std::vector<Planet_Model*>&planets){
    if(this->erase_chosen_planets_button){
        this->state=DELETE_PLANET_MENU_ACCEPTING_STATE;
        this->erase_chosen_planets_button=false; 
    }
    else if(this->accept_erasing_planets_button){
        this->state=DELETE_PLANET_MENU_STATE;
        this->accept_erasing_planets_button=false;
    }
    else if(this->go_back_button2){
        this->state=DELETE_PLANET_MENU_STATE;
        this->go_back_button2=false;
    }
}

void Delete_Planet_Menu_Controller::requestDrawing(const std::vector<Planet_Model*>&planets){
    if(this->state==DELETE_PLANET_MENU_STATE){
        this->view->drawMenu();
        unsigned height=100;
        int counter=0;

        GuiScrollPanel(Rectangle{1100, 90, 300, 250}, NULL, Rectangle{1100, 90, 300, 700}, &this->scrollBarVector, &this->rectangleView);

        BeginScissorMode(this->rectangleView.x, this->rectangleView.y, this->rectangleView.width, this->rectangleView.height);
        for(int i=int(-this->scrollBarVector.y)/40;i<planets.size() && counter<6;++i){
            GuiCheckBox(Rectangle{1120, height-5.f, 10, 10}, planets[i]->getName(), planets[i]->getPtrToCheckToErase());
            height+=40;
            ++counter;
        }

        EndScissorMode();

        this->erase_chosen_planets_button=GuiButton(Rectangle{1100, 820, 90, 30}, "Erase planets.");
        this->go_back_button=GuiButton(Rectangle{1320, 820, 90, 30}, "Go back.");
    }
    else if(this->state==DELETE_PLANET_MENU_ACCEPTING_STATE){
        this->view->drawAcceptMenu();
        this->accept_erasing_planets_button=GuiButton(Rectangle{1100, 600, 90, 30}, "Accept");
        this->go_back_button2=GuiButton(Rectangle{1320, 600, 90, 30}, "Cancel");
    }
}