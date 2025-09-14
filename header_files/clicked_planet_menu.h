#include <raylib.h>
#include "planet.h"

class ClickedPlanetMenu{
    private:
    unsigned window_width;
    unsigned window_height;
    unsigned menu_width;
    unsigned menu_height;
    int is_closed;
    Planet *planet;

    public:
    ClickedPlanetMenu(Planet* const, const unsigned, const unsigned, const unsigned, const unsigned);

    ~ClickedPlanetMenu();

    void changePlanet(Planet* const);

    bool shouldMenuBeClosed();

    void drawMenu();
};