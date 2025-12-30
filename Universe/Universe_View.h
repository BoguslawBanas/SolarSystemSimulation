#ifndef UNIVERSE_VIEW_H
#define UNIVERSE_VIEW_H

#include "../Planet/Planet_Model.h"
#include "../Planet/Planet_View.h"
#include <vector>

class Universe_View{
    private:
    Planet_View *planet_view;
    float distance_divider;
    float radius_divider;

    public:
    Universe_View(const float, const float);

    ~Universe_View();

    void drawUniverse(const std::vector<Planet_Model*>&, const Planet_Model*);
};

#endif