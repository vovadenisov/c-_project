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
#include <queue>
#include <utility>

using namespace std;


class Container{
public:
    Container(read Params);
    //обрабатывает возможное нажатие принимает координаты нажатия мыши,
    //вызывает функцию класа
    virtual bool onClick(int x, int y, queue<string>* commands){ return false;}

    //вызывается при приходе очередного массива состояний. вытаскивает нужное состояние по имени
    virtual void change(pair<string, int> allState){}
    virtual void change(pair<string, string>& allState){}

    //возвращает объект картинки
    virtual img Drow() {
        return allImg[isActive];
    }

    //возвращает номер группы
    int Group(){
        return group;
    }

    virtual bool isName(string name);

    //включение модуля и связанных с ним сущностей
    virtual void enable();

    //выключение модуля и связанных с ним сущностей
    virtual void decont();

    //проверка видимости объекта
    bool isVisible();

    void setVisible(bool param);

protected:
    //функция перегружается для классов, где нужно движение или поворот
    virtual void move(int angle){}

    //массив изображений
    vector<img> allImg;

    //индекс активного изображения.
    int isActive = 0;

    //имя модуля
    string name;

    //группа по умолчанию -1 (без группы), кнопка выключения -2
    int group = -1;

    //видимость объекта
    bool visible = true;
};

#endif // CONTAINER_H
