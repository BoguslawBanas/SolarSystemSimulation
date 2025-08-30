#ifndef DELETE_PLANET_MENU_H
#define DELETE_PLANET_MENU_H

#include <vector>
#include <raylib.h>
#include "planet.h"

class Delete_Planet_Menu{
    private:
    unsigned amount_of_planets;
    bool go_back_button;
    bool delete_planets;
    std::vector<char>to_delete;

    public:
    Delete_Planet_Menu(const unsigned);

    ~Delete_Planet_Menu();

    bool getGoBackButton() const;

    bool getDeletePlanets() const;

    const std::vector<char>& getToDelete() const;

    void drawMenu(const std::vector<Planet>&);
};

#endif