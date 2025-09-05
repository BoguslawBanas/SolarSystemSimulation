#ifndef ADD_PLANET_MENU_H
#define ADD_PLANET_MENU_H

#include <raylib.h>
#include <string>
#include "raygui.h"
#include "slider_textfield_menu.h"
#include <math.h>

class Add_Planet_Menu{
    private:
    unsigned menu_width;
    unsigned menu_height;
    unsigned start_menu_width;
    Color color;
    char name[50];
    bool is_name_text_field_clicked;
    SliderTextfieldMenu *radius_menu;
    SliderTextfieldMenu *mass_menu;
    SliderTextfieldMenu *angle_menu;
    SliderTextfieldMenu *distance_from_center_menu;
    SliderTextfieldMenu *velocity_menu;

    public:
    Add_Planet_Menu(unsigned, unsigned, unsigned);

    ~Add_Planet_Menu();

    const char* getName() const;

    float getRadius() const;

    float getMass() const;

    float getAngle() const;

    float getDistanceFromCenter() const;

    float getvelocity() const;

    Color getColor() const;

    void drawMenu();
};

#endif