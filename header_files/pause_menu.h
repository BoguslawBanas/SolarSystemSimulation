#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include <raylib.h>

class Pause_Menu{
    private:
    unsigned window_width;
    unsigned window_height;
    bool save_simulation_button;
    bool read_simulation_button;
    bool go_back_button;
    bool exit_buttton;

    public:
    Pause_Menu(const unsigned, const unsigned);

    ~Pause_Menu();

    bool getGoBackButton() const;

    bool getExitButton() const;

    bool getSaveSimulationButton() const;

    bool getReadSimulationButton() const;

    void drawMenu();
};

#endif