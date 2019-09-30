// Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool initSDL();
bool loadMedia();
void closeSDL();


int main(int argc, char* args[])
{
    bool initialized = initSDL();
    if (!initialized) {
        printf("Didn't init...");
    }

    bool loaded = loadMedia();
    if (!loaded) {
        printf("Didn't load...");
    }

    SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
    SDL_UpdateWindowSurface(gWindow);

    bool quit = false;
    SDL_Event e;
    // On Mac you need an event loop
    // for the window to even show!
    while (!quit && SDL_PollEvent(&e) != 0) {
        SDL_Delay(2000);
        quit = true;
    }

    closeSDL();
    
    return 0;
}


bool initSDL()
{
    int status = SDL_Init(SDL_INIT_VIDEO);
    if (status < 0) {
        printf("- SDL init failed. SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    printf("- SDL Initialized");
    gWindow = SDL_CreateWindow(
        "SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    gScreenSurface = SDL_GetWindowSurface(gWindow);
    return true;
}


bool loadMedia()
{
    gHelloWorld = SDL_LoadBMP("assets/hello_world.bmp");
    if (gHelloWorld == NULL) {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        return false;
    }
    return true;
}


void closeSDL()
{
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}