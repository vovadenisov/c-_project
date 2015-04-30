#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include <map>
#include <SDL/SDL.h>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

using namespace std;

struct img{
    SDL_Rect desc; // координаты, куда нужно наложить часть.
    SDL_Surface* screen;//screen
    //bool visible = true;
};

struct state{
    int dX;//изменение кординаты по х
    int dY;//изменение кординаты по у
    int dAngle;//изменение угла
    int active;// активный индекс
};

class Container
{
public:
    Container(){}//виртуальный конструктор
    ~Container(){}//виртуальный деструктор
    virtual void onClick(int x, int y) = 0;//обрабатывает возможное нажатие принимает координаты нажатия мыши,
    //вызывает функцию класа
    virtual void change(map<string,state>* allState) = 0;//вызывается при приходе очередного массива состояний.
    //вытаскивает нужное состояние по имени
    virtual img Drow();
private:
    virtual void move(int newx,int newy, int angle) = 0;//функция перегружается для классов, где нужно движение
    //или поворот
    vector<img>* allImg;//массив изображений
    int isActive = 0;//индекс активного изображения.
    string* name;//имя модуля
};

#endif // CONTAINER_H
