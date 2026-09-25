#include "C:/raylib/raylib/src/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../libs/raygui.h"

// Global constants
const float width = 1060.f;
const float height = 540.f;

// Function Declarations
void DrawLeftPanel();

void DrawRightPanel();


// Main Function
int main()
{
    InitWindow(width, height, "Kairo");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(GetColor(999999)); 

            // GuiDisable(); --Can be used later on to disable GUI input?
            // ------------ LEFT PANEL -----------------
            DrawLeftPanel();

            // ------------ RIGHT PANEL -----------------
            DrawRightPanel();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Function Definitions
void DrawRightPanel() {
    Rectangle bounds { (width/2.f + width/225.f), (height/75.f), (width/2.f) - 10.f, (height/1.005f) - 10.f };
    GuiWindowBox(bounds, "Right Panel");
}

void DrawLeftPanel() {
    Rectangle bounds { (width/125.f), (height/75.f), (width/2.f) - 10.f, (height/1.005f) - 10.f };
    GuiWindowBox(bounds, "Left Panel");
}

