#ifndef START_MENU_MODEL_H
#define START_MENU_MODEL_H

#include <raylib.h>
#include "../header_files/sim_math.h"

class Start_Menu_Model{
    private:
    Rectangle button1_bounds;
    Rectangle button2_bounds;
    Rectangle button3_bounds;

    public:
    Start_Menu_Model(const unsigned, const unsigned);

    ~Start_Menu_Model();

    const Rectangle& getButton1() const;

    const Rectangle& getButton2() const;

    const Rectangle& getButton3() const;
};

#endif