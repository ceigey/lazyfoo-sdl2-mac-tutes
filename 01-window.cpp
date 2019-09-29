// Using SDL and standard IO
#include <SDL.h>
// #include <stdio.h>
#include <iostream>

using namespace std;

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    // Window to render to
    SDL_Window* window = NULL;
    // Surface contained by the window
    SDL_Surface* screenSurface = NULL;

    // Initialise
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // printf("SDL init karked it. SDL_Error: %s\n", SDL_GetError());
        cout << "SDL init karked it. SDL_Error: " << SDL_GetError() << "\n";
    } else {
        cout << "• SDL Initialised. \n";

        window = SDL_CreateWindow(
            "SDL_Tutorial",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);

        if (window == NULL) {
            cout << "SDL Window won't work. SDL_Error: " << SDL_GetError() << "\n";
        } else {
            cout << "• SDL Window created. \n";

            screenSurface = SDL_GetWindowSurface(window);

            SDL_FillRect(
                screenSurface,
                NULL,
                SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            SDL_UpdateWindowSurface(window);

            cout << "  • SDL Window updated. \n";

            bool quit = false;
            SDL_Event e;
            // On Mac you need an event loop
            // for the window to even show!
            while (!quit && SDL_PollEvent(&e) != 0) {
                SDL_Delay(2000);
                quit = true;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "• SDL Quitting... \n";
    return 0;
}
