#include "C:/raylib/raylib/src/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../libs/raygui.h"

int main()
{
    const float width = 1060;
    const float height = 540;

    InitWindow(width, height, "Kairo");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            GuiButton((Rectangle){ 24, 24, 120, 30 }, "Start");
            GuiButton((Rectangle){ width/10, 24, 120, 30 }, "End");

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
