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
#include <utility>
#include "textcontainer.h"
#include <math.h>


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
    Minion(read params);
    bool onClick(int x, int y, queue<string>* commands);
    void change(pair<string,int>allState);
};

class OffBtn:public RoundBtn{
public:
    OffBtn(read params);
    bool onClick(int x, int y, queue<string>* commands);
};

class Battery:public Container{
public:
    Battery(read params);
    void change(pair<string,int>);
};

//class SpeedGroup:public Container{
//public:
//    SpeedGroup(read params);
//    void change(pair<string, int> allState);
//    void move(int angle);
//private:
//    img arrow;
//    img scale;

//};

class Speed:public Container{
public:
    Speed(read params);
    void change(pair<string, int> allState);
    void move(int angle){}
};

class Arrow:public Container{
public:
    Arrow(read params);
    void change(pair<string,int>allState){}
    void move(int newx,int newy, int angle){}
};

class Map:public RectBtn{
public:
    Map(read params);
    bool onClick(int x, int y, queue<string>* commands);
    void change(pair<string,int> allState);
};

class Video:public Container{
public:
    Video(read params, SDL_Surface**&);
};

class BtnMap:public RectBtn{
public:
    BtnMap(read params, bool* selfie);
    bool onClick(int x, int y, queue<string>* commands);
    void change(pair<string,int>allState);
private:
    bool *selfie;
};

class BtnLid:public RectBtn{
public:
    BtnLid(read params);
    bool onClick(int x, int y, queue<string>* commands);
    void change(pair<string,int>allState);
};

class BtnFPV:public RectBtn{
public:
    BtnFPV(read params);
    bool onClick(int x, int y, queue<string>* commands);
    void change(pair<string,int>allState);
};

class MapMin:public Container{
public:
    MapMin(read params);
    void change(pair<string,int>allState);
protected:
    void move(int newx,int newy, int angle);
};

class Micro:public RectBtn{
public:
    Micro(read params);
    bool onClick(int x, int y, queue<string>* commands);
    void change(pair<string,int>allState);
};

class Dinamic:public RectBtn{
public:
    Dinamic(read params);
    bool onClick(int x, int y, queue<string>* commands);
    void change(pair<string,int>allState){}
};

class Text:public Container{
public:
    Text(read params, size_t textSize);
    TextContainer *giveText();
    void change(pair<string,string>& allState);
private:
    TextContainer cont;
    SDL_Rect textPos;
    img base;
};

class Panic:public RoundBtn{
public:
    Panic(read params);
    bool onClick(int x, int y, queue<string>* commands);
    void change(pair<string,int>allState);
};

#endif // ALLCLASS_H
