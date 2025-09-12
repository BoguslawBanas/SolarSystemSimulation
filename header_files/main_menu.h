#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <raylib.h>
#include <string>
#include "../header_files/slider_textfield_menu.h"

class Main_Menu{
    private:
    unsigned window_width;
    unsigned window_height;
    bool is_camera_locked;
    bool is_simulation_paused;
    SliderTextfieldMenu *speed_of_simulation_menu;

    public:
    Main_Menu(const unsigned, const unsigned);

    ~Main_Menu();

    bool getIsCameraLocked() const;

    bool getIsSimulationPaused() const;

    float getSpeed() const;

    void changePauseSetting();

    void lockUnlockCamera();

    void drawMenu() const;
};

#endif