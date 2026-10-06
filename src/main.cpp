#include "C:/raylib/raylib/src/raylib.h"
#include <string>
#include <sstream>

#define RAYGUI_IMPLEMENTATION
#include "../libs/raygui.h"

// Global Constats
const float width = 1060.f;
const float height = 540.f;

struct Time {
    int hours { 0 };
    int minutes { 0 };
    int seconds { 0 };
};

// COLORS
const Color Background{ .r = 216, .g = 216, .b = 216, .a = 1 };

// Function Declarations
void DrawLeftPanel();
void DrawRightPanel(std::string);

int main()
{
    Time time{};

    std::ostringstream oss;
    oss << time.hours << ":" << time.minutes << ":" << time.seconds;
    std::string timeString = oss.str();

    // Initialize the window
    InitWindow(width, height, "Kairo");

    // Target FPS
    SetTargetFPS(60);

    // Game loop
    while (!WindowShouldClose())
    {
        // Input interactions

        // Draw
        BeginDrawing();

            ClearBackground(Background);

            // GuiDisable(); --Can be used later on to disable GUI input?
            // ------------ LEFT PANEL -----------------
            DrawLeftPanel();

            // ------------ RIGHT PANEL -----------------
            DrawRightPanel(timeString);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Function Definitions
void DrawRightPanel(std::string time) {
    float panelPosX { (width/2.f) + (width/225.f) };
    float panelPosY { height/75.f };
    float panelWidth { (width/2.f) - 10.f };
    float panelHeight { (height/1.005f) - 10.f };

    Rectangle panel { panelPosX, panelPosY, panelWidth, panelHeight };
    GuiGroupBox(panel, "Right Panel");

    // Time
    Rectangle timePanel { panelPosX + 22.5f, panelPosY + 25.f, 200.f, 100.f };
    GuiLabel(timePanel, "Yo");

    // Maybe I should make this a slider inside the application for debugging and creating? Maybe that'll be the next steps of this project, that'd be cool
    // Figure out what is panelPosX in debugger? Why is it shifted so much to the right even though it should only be 25?
    // Figure out the math, this should've worked
    float startButtonPosX = panelPosX + 22.5f;
    float startButtonPosY = panelPosY + 100.f;
    Rectangle startButtonBounds { startButtonPosX, startButtonPosY, 200.f, 75.f };
    GuiButton(startButtonBounds, "START / PAUSE");

    Rectangle endButtonBounds { startButtonPosX + 200.f + 75.f, startButtonPosY, 200.f, 75.f };
    GuiButton(endButtonBounds, "END SESSION");
}

void DrawLeftPanel() {
    Rectangle bounds { (width/125.f), (height/75.f), (width/2.f) - 10.f, (height/1.005f) - 10.f };
    GuiGroupBox(bounds, "Left Panel");
}

