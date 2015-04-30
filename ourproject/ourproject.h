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
#include <map>
#include <vector>
#include "form.h"
#include "elemcont.h"
#include <container.h>

using namespace std;

//struct img{
//    SDL_Rect desc; // координаты, куда нужно наложить часть.
//    SDL_Surface* screen;//screen
//    bool visible = true;
//};



//struct block{
//    string name;
//    element<T>* elements;
//    block* next;
//};



class OurProject {
public:
    OurProject();
    bool init(/*map<string, map<string, form> >**/ vector<com>&);
    bool startScreen();
    bool MakeScreen();
    //bool detectModule(int, int, string*, string*);//определение блока, на который мы тыкнули
    //void selectFunc(string, string);//определение функции подходящей для этого модуля
private:
    vector<Container*>* moduls;
    void selectClass(read& value, Container*& position);
//    map <string,map<string, img> > *arr;
//    map <string, string > *state;
    SDL_Surface* back;
};
#endif // OURPROJECT_H
