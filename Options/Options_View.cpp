#include "Options_View.h"
#include "../header_files/raygui.h"

Options_View::Options_View(){}

Options_View::~Options_View()=default;

void Options_View::draw(){
    DrawText("Move forward: ", 100, 100, 15, WHITE);
    DrawText("Move backward: ", 100, 150, 15, WHITE);
    DrawText("Move left: ", 100, 200, 15, WHITE);
    DrawText("Move right: ", 100, 250, 15, WHITE);
    DrawText("Move up: ", 100, 300, 15, WHITE);
    DrawText("Move down: ", 100, 350, 15, WHITE);
    DrawText("Lock camera in place: ", 100, 400, 15, WHITE);
    DrawText("Pause simulation: ", 100, 450, 15, WHITE);
    DrawText("Music for main menu: ", 100, 500, 15, WHITE);
    DrawText("Music for simulation: ", 100, 550, 15, WHITE);
}