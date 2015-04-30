#ifndef ALLCLASS_H
#define ALLCLASS_H
#include <string>
#include <container.h>
#include <ourproject>

/*class Container
{
public:
    virtual Container() = 0;//виртуальный конструктор
    virtual ~Container() = 0;//виртуальный деструктор
    virtual void onClick(int x, int y) = 0;//обрабатывает возможное нажатие принимает координаты нажатия мыши,
    //вызывает функцию класа
    virtual void change(map<string,state>* allState) = 0;//вызывается при приходе очередного массива состояний.
    //вытаскивает нужное состояние по имени
    virtual img Drow();
protected:
    virtual void move(int newx,int newy, int angle) = 0;//функция перегружается для классов, где нужно движение
    //или поворот
    vector<img>* allImg;//массив изображений
    int isActive = 0;//индекс активного изображения.
    string* name;//имя модуля
};*/

class Minion:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
    string Ip;
};

class Arrow:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};


class Power:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class Batary:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class Microphone:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class dinamic:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class Map:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class btnMap:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class btnLidar:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class btnFpv:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class Speed:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

class Text:public Container{
public:
    Minion(read params);
    ~Minion();
    void onClick(int x, int y);
    void change(map<string, state> *allState);
    img Drow();
protected:
    void move(int newx,int newy, int angle){}
};

#endif // ALLCLASS_H
