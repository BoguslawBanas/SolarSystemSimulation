#include "Start_Menu_View.h"
#include "../header_files/raygui.h"

#define START_MENU_VIEW_HEIGHT_GRID -10.f

Start_Menu_View::Start_Menu_View(){}

Start_Menu_View::~Start_Menu_View()=default;

void Start_Menu_View::drawStartMenu1(const Rectangle &button1, const Rectangle &button2, const Rectangle &button3, const Camera3D &camera, const float alpha){
    GuiSetAlpha(alpha);
    BeginMode3D(camera);
    DrawSphere(Vector3{5.f, 0.f, 3.f}, 10.f, RED);
    DrawSphere(Vector3{10.f, 0.f, 50.f}, 5.f, BLUE);
    DrawSphere(Vector3{60.f, 0.f, -10.f}, 12.5f, YELLOW);
    DrawSphere(Vector3{50.f, 0.f, 25.f}, 6.25f, GREEN);
    DrawSphere(Vector3{-100.f, 0.f, -50.f}, 11.f, PURPLE);

    for(int i=0;i<51;++i){
        for(int j=0;j<51;++j){
            DrawLine3D(Vector3{-400.f+(i*16.f), START_MENU_VIEW_HEIGHT_GRID, -400.f}, Vector3{-400.f+(i*16.f), START_MENU_VIEW_HEIGHT_GRID, 400.f}, GRAY);
            DrawLine3D(Vector3{-400.f, START_MENU_VIEW_HEIGHT_GRID, -400.f+(j*16.f)}, Vector3{400.f, START_MENU_VIEW_HEIGHT_GRID, -400.f+(j*16.f)}, GRAY);
        }
    }
    EndMode3D();

    DrawText("Solar system simulation", 50, 50, 40, GREEN);
    GuiButton(button1, "Start simulation.");
    GuiButton(button2, "Settings.");
    GuiButton(button3, "Exit.");
}

void Start_Menu_View::drawStartMenu2(const Rectangle &button1, const Rectangle &button2, const Rectangle &button3, const Camera3D &camera, const float alpha){
    GuiSetAlpha(alpha);
    BeginMode3D(camera);
    DrawSphere(Vector3{5.f, 0.f, 3.f}, 10.f, RED);
    DrawSphere(Vector3{10.f, 0.f, 50.f}, 5.f, BLUE);
    DrawSphere(Vector3{60.f, 0.f, -10.f}, 12.5f, YELLOW);
    DrawSphere(Vector3{50.f, 0.f, 25.f}, 6.25f, GREEN);
    DrawSphere(Vector3{-100.f, 0.f, -50.f}, 11.f, PURPLE);

    for(int i=0;i<51;++i){
        for(int j=0;j<51;++j){
            DrawLine3D(Vector3{-400.f+(i*16.f), START_MENU_VIEW_HEIGHT_GRID, -400.f}, Vector3{-400.f+(i*16.f), START_MENU_VIEW_HEIGHT_GRID, 400.f}, GRAY);
            DrawLine3D(Vector3{-400.f, START_MENU_VIEW_HEIGHT_GRID, -400.f+(j*16.f)}, Vector3{400.f, START_MENU_VIEW_HEIGHT_GRID, -400.f+(j*16.f)}, GRAY);
        }
    }
    EndMode3D();

    DrawText("Solar system simulation", 50, 50, 40, GREEN);
    GuiButton(button1, "Solar system.");
    GuiButton(button2, "Free mode.");
    GuiButton(button3, "Go back.");
}