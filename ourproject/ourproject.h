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
#include <queue>
#include "textcontainer.h"
#include <cstdlib>

using namespace std;

class OurProject {
public:

    static OurProject * getInstance(queue<string>* command);

    //инициализация SDL lib
    bool init();

    //изменение отображаемой поверхности
    bool startScreen();

    //применение изменений
    bool MakeScreen();

    //чтение файла и наполнение классов объектов
    void makeClass(char* );

    //внешнее изменение состояния объектов.
    void change(string, int);

    //функция обработчик событий
    void choiceEvent(SDL_Event* event);

    //надо ли отрисовываться
    bool active = true;

    //прием файла от сервера
    void  putVideo(uint8_t* data, int size);

    void parseCommand();

    void ActivateComm(string comm);
    //пишем текст в текстовое поле
    void printText(string);

    void photo(int size, char* data);

private:

    static OurProject* p_instance;

    OurProject(queue<string>*);

    //печать одной строки текста
    void printLineText(string, int);

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

    SDL_Surface** video = NULL;

    TTF_Font *fnt;
    //max legth = 54; 11 lines;
    TextContainer* textContainer;

    bool selfie = false;

    queue<string>* commands;
};

#endif // OURPROJECT_H
