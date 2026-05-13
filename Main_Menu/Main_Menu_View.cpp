#include "Main_Menu_View.h"
#include "../header_files/raygui.h"

Main_Menu_View::Main_Menu_View(){}

Main_Menu_View::~Main_Menu_View()=default;

void Main_Menu_View::draw(const bool is_camera_locked, const Rectangle &add_button, const Rectangle &delete_button){
    if(is_camera_locked){
        DrawText("Camera locked.", 250, 45, 15, RED); //change position later
    }
    GuiButton(add_button, "Add new planet.");
    GuiButton(delete_button, "Delete planet.");   
}