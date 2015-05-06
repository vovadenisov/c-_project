#ifndef FORM_H
#define FORM_H
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

struct com{
    int x;
    int y;
    string path;//путь к картинке
};

struct read{
    string nameBlock;
    vector<com> images;
};

struct img{
    SDL_Rect desc; // координаты, куда нужно наложить часть.
    SDL_Surface* screen;//screen
    //bool visible = true;
};

struct state{
    string name;
    int x;//изменение кординаты по х
    int y;//изменение кординаты по у
    int angle = 0;//изменение угла
    int active = 0;// активный индекс
};


#endif // FORM_H
