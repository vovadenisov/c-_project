#include "ourproject.h"

OurProject::OurProject(){
    back = NULL;
}

bool OurProject::init(form* arr, int size){
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        return false;
    }
    all = new img[size];
    for (int i = 0; i < size; i++){
        all[i]screen = NULL;
    }
    for (int i = 0; i < size; i++){
        all[i].desc.x = arr[i].x;
        all[i].desc.y = arr[i].y;
        all[i].screen = IMG_Load(arr[i].addr);
        if (all[i].screen == NULL){
            return false;
        }
    }

    back = SDL_SetVideoMode(1360, 768, 16, SDL_HWSURFACE | SDL_FULLSCREEN);
    if ( !back )
    {
        return false;
    }

    if (!back)
    {
        return false;
    }
}

bool OurProject::MakeScreen(){
    for (int i = 0; i < size; i++){
        SDL_BlitSurface(all[i].screen, NULL, back, &all[i].desc);
    }
}

bool OurProject::startScreen(){
    SDL_Flip(screen);
    SDL_Delay( 10000 );
}
