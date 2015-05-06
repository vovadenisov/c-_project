#ifndef OURPROJECT_H
#define OURPROJECT_H
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
#include <container.h>
#include <allclass.h>
#include <form.h>

using namespace std;

class OurProject {
public:
    OurProject();

    //инициализация SDL lib
    bool init();

    //изменение отображаемой поверхности
    bool startScreen();

    //применение изменений
    bool MakeScreen();

    //чтение файла и наполнение классов объектов
    void makeClass(char* );

    //внешнее изменение состояния объектов.
    void change();

    //функция обработчик событий
    bool choiceEvent(SDL_Event* event);

    //надо ли отрисовываться
    bool active = true;

private:
    // востановление активности модулей. (только 1 модуль из группы должен быть активен)
    void correctModule(int, int);

    //запуск события onClick объектов и исправление ошибок состояний.
    void onClick(int, int);

    //вектор контейнеров
    vector<Container*> moduls;

    //выбор класса при по имени в value
    Container* selectClass(read& value);

    //основная отображаемая поверхность.
    SDL_Surface* back;
};
#endif // OURPROJECT_H
