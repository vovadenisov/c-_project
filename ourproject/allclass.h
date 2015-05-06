#ifndef ALLCLASS_H
#define ALLCLASS_H
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
#include <form.h>
#include <ourproject.h>

using namespace std;

class RoundBtn:public Container{
public:
    RoundBtn(read params):Container(params){}
protected:
    virtual bool inRange(int x, int y);
};

class RectBtn:public Container{
public:
    RectBtn(read params):Container(params){}
protected:
    virtual bool inRange(int x, int y);
};

class Background:public Container{
public:
    Background(read params);
};

class Minion:public RectBtn{
public:
    Minion(read params, string IP);
    bool onClick(int x, int y);
    void change(map<string, state> *allState);
protected:
    string Ip;
};

class OffBtn:public RoundBtn{
public:
    OffBtn(read params);
    bool onClick(int x, int y);
};

class Battary:public Container{
public:
    Battary(read params);
    void change(map<string, state> *allState);
};

class Speed:public Container{
public:
    Speed(read params);
};

class Arrow:public Container{
public:
    Arrow(read params);
    void change(map<string, state> *allState);
protected:
    void move(int newx,int newy, int angle);
};

class Map:public RectBtn{
public:
    Map(read params);
    bool onClick(int x, int y);
    void change(map<string, state> *allState);
};

class BtnMap:public RectBtn{
public:
    BtnMap(read params);
    bool onClick(int x, int y);
    void change(map<string, state> *allState);
};

class BtnLid:public RectBtn{
public:
    BtnLid(read params);
    bool onClick(int x, int y);
    void change(map<string, state> *allState);
};

class BtnFPV:public RectBtn{
public:
    BtnFPV(read params);
    bool onClick(int x, int y);
    void change(map<string, state> *allState);
};

class MapMin:public Container{
public:
    MapMin(read params);
    void change(map<string, state> *allState);
protected:
    void move(int newx,int newy, int angle);
};

class Micro:public RectBtn{
public:
    Micro(read params);
    bool onClick(int x, int y);
    void change(map<string, state> *allState);
};

class Dinamic:public RectBtn{
public:
    Dinamic(read params);
    bool onClick(int x, int y);
    void change(map<string, state> *allState);
};

class Text:public Container{
public:
    Text(read params);
    void change(map<string, state> *allState);
};

class Panic:public RoundBtn{
public:
    Panic(read params);
    bool onClick(int x, int y);
    void change(map<string, state> *allState);
};

#endif // ALLCLASS_H
