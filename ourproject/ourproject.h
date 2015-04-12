#ifndef OURPROJECT_H
#define OURPROJECT_H
#include <string>
#include <SDL/SDL.h>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <ourproject.h>
#include <SDL/SDL_image.h>

using namespace std;

struct form{
    int x;
    int y;
    string addr;
};

struct img{
    SDL_Rect desc; // координаты, куда нужно наложить часть.
    SDL_Surface* screen;
};

class OurProject {
public:
    OurProject();
    bool init(form*,int);
    bool startScreen();
    bool MakeScreen();

private:
    img* all;
    SDL_Surface* back;
    size_t size;

};
#endif // OURPROJECT_H
