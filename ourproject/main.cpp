#include <ourproject.h>
#include <SDL/SDL_image.h>
using namespace std;

int main()
{
    /*if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    SDL_Surface * screen = SDL_SetVideoMode(1360, 768, 16, SDL_HWSURFACE | SDL_FULLSCREEN);
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

    SDL_Surface* block = IMG_Load("1687588.jpg");
    SDL_Rect desc; // координаты, куда нужно наложить часть.
    desc.x = 100;
    desc.y = 100;
    SDL_Rect src; // накладываемый прямоугольник.
    src.x = 0;
    src.y = 0;
    src.w = 100;
    src.h = 100;
    SDL_BlitSurface(block, NULL, screen, &desc);
    SDL_Flip(screen);
    SDL_Delay( 10000 );*/
    OurProject a;
    a.init();
    a.MakeScreen();
    a.startScreen();
    return 0;
}

