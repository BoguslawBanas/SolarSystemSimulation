#include <raylib.h>
#include <string>
#include "planet.h"

class ClickedPlanetMenu{
    private:
    unsigned window_width;
    unsigned window_height;
    unsigned menu_width;
    unsigned menu_height;
    int is_closed;
    char speed_str[25];
    char radius_str[25];
    char mass_str[25];
    Planet *planet;

    public:
    ClickedPlanetMenu(Planet* const, const unsigned, const unsigned, const unsigned, const unsigned);

    ~ClickedPlanetMenu();

    void changePlanet(Planet* const);

    bool shouldMenuBeClosed();

    void drawMenu();
};