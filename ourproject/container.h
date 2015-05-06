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
#include <form.h>

using namespace std;


class Container{
public:
    Container(read Params);
    //обрабатывает возможное нажатие принимает координаты нажатия мыши,
    //вызывает функцию класа
    virtual bool onClick(int x, int y){ return false;}

    //вызывается при приходе очередного массива состояний. вытаскивает нужное состояние по имени
    virtual void change(map<string,state>* allState){}

    //возвращает объект картинки
    virtual img Drow() {
        return allImg[isActive];
    }

    //возвращает номер группы
    int Group(){
        return group;
    }

    //выключение модуля
    virtual void decont(){
        isActive = 0;
    }

protected:
    //функция перегружается для классов, где нужно движение или поворот
    virtual void move(int newx,int newy, int angle){}

    //массив изображений
    vector<img> allImg;

    //индекс активного изображения.
    int isActive = 0;

    //имя модуля
    string name;

    //группа по умолчанию -1 (без группы)
    int group = -1;
};

#endif // CONTAINER_H
