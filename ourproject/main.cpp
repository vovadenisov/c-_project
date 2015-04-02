#include <iostream>
#include <SDL/SDL.h>
#include <cstdlib>
using namespace std;

int main()
{
   // SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface* screen = NULL; // сначала ее нет

     if(SDL_Init( SDL_INIT_EVERYTHING ) == -1) // инициализируем видео-подсистему
     {
     //printf("SDL_Init failed: %s\n", SDL_GetError() ); return false;
     }

       // инициализируем экранную поверхность
    //  screen = SDL_SetVideoMode( 640, 480, 0, SDL_HWSURFACE | SDL_DOUBLEBUF );

     // if ( screen == NULL )
   //   {
     // printf("Unable to set 640x480 video: %s\n", SDL_GetError()); return false;
   //   }

     // ждем 3 секунды
    //  SDL_Delay(3000);

      // освобождаем ресурсы подсистем и экранную поверхность
   //   SDL_Quit();
    //cout << "Hello World!" << endl;
    return 0;
}

