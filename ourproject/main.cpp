#include <iostream>
#include <stdio.h>
#include <ctime>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <ourproject.h>

using namespace std;

int main()
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    SDL_Surface * screen = SDL_SetVideoMode(550, 420, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        return 1;
    }

    if (!screen)
    {
        printf("Can't set videomode: %s", SDL_GetError());
        return 1;
    }

    SDL_Flip(screen);
    while(1){
        cout << 1 << endl;
    }
    return 0;

}

