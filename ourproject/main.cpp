#include <iostream>
#include "ourproject.h"
#include <SDL/SDL.h>
#include <cstdlib>
using namespace std;

int main()
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        {
            printf( "Unable to init SDL");
            return 1;
        }
    SDL_Surface * screen = SDL_SetVideoMode(550, 420, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);

    return 0;
}

