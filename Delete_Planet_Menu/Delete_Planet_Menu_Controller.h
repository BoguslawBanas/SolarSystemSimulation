#ifndef DELETE_PLANET_MENU_CONTROLLER_H
#define DELETE_PLANET_MENU_CONTROLLER_H

#include "Delete_Planet_Menu_Model.h"
#include "Delete_Planet_Menu_View.h"
#include "../Planet/Planet_Model.h"
#include <vector>

class Delete_Planet_Menu_Controller{
    private:
    enum Delete_Planet_Menu_State{
        DELETE_PLANET_MENU_STATE,
        DELETE_PLANET_MENU_ACCEPTING_STATE
    };

    Delete_Planet_Menu_Model *model;
    Delete_Planet_Menu_View *view;
    unsigned amount_of_planets;
    bool *list_of_checkboxes;
    bool go_back_button;
    bool erase_chosen_planets_button;
    bool go_back_button2;
    bool accept_erasing_planets_button;
    Vector2 scrollBarVector;
    Rectangle rectangleView;
    Delete_Planet_Menu_State state;

    public:
    Delete_Planet_Menu_Controller(const unsigned, const unsigned, const unsigned);

    ~Delete_Planet_Menu_Controller();

    bool getErasingChosenPlanetsButton() const;

    bool getGoBackButton() const;

    const std::vector<int> getPlanetsToDelete() const;

    void calcLogic(const std::vector<Planet_Model*>&);

    void requestDrawing(const std::vector<Planet_Model*>&);
};

#endif