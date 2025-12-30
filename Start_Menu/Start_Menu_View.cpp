#include "Start_Menu_View.h"
#include "../header_files/raygui.h"

Start_Menu_View::Start_Menu_View(){}

Start_Menu_View::~Start_Menu_View()=default;

void Start_Menu_View::drawStartMenu1(const Rectangle &button1, const Rectangle &button2, const Rectangle &button3){
    GuiButton(button1, "Start simulation.");
    GuiButton(button2, "Settings.");
    GuiButton(button3, "Exit.");
}

void Start_Menu_View::drawStartMenu2(const Rectangle &button1, const Rectangle &button2, const Rectangle &button3){
    GuiButton(button1, "Solar system.");
    GuiButton(button2, "Free mode.");
    GuiButton(button3, "Go back.");
}