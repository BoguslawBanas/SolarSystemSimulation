#ifndef DELETE_PLANET_MENU_CONTROLLER_H
#define DELETE_PLANET_MENU_CONTROLLER_H

#include "Delete_Planet_Menu_Model.h"
#include "Delete_Planet_Menu_View.h"
#include "../Planet/Planet_Model.h"
#include <vector>

class Delete_Planet_Menu_Controller{
    private:
    Delete_Planet_Menu_Model *model;
    Delete_Planet_Menu_View *view;
    bool *list_of_checkboxes;
    bool go_back_button;
    bool erase_chosen_planets_button;

    public:
    Delete_Planet_Menu_Controller(const unsigned, const unsigned, const unsigned);

    ~Delete_Planet_Menu_Controller();

    bool getErasingChosenPlanetsButton() const;

    bool getGoBackButton() const;

    void requestDrawing(const std::vector<Planet_Model*>&);
};

#endif