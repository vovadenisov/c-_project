#include "allclass.h"

//Описание roundBtn

bool RoundBtn::inRange(int x, int y){
    double xc = allImg[isActive].desc.x + allImg[isActive].screen->w/2;
    double yc = allImg[isActive].desc.y + allImg[isActive].screen->h/2;
    double dx = x - xc;
    double dy = y - yc;

    if ((allImg[isActive].screen->w/2 * allImg[isActive].screen->w/2) > (dx*dx + dy*dy)){
        return true;
    }
    return false;
}

//Описание rectBtn

bool RectBtn::inRange(int x, int y){
    if ( ( (x > allImg[isActive].desc.x) &&
           (x < allImg[isActive].desc.x + allImg[isActive].screen->w)) &&
         ( (y > allImg[isActive].desc.y) &&
           (y < allImg[isActive].desc.y + allImg[isActive].screen->h))){
        return true;
    }
    return false;
}

//описание всех классов наследников

Minion::Minion(read params, string IP):RectBtn(params), Ip(IP){
    group = 0;
}

void Minion::change(map<string, state> *allState){}

bool Minion::onClick(int x, int y){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
        }
        else{
            isActive = 0;
        }
        return true;
    }
    return false;
}

//========================================

Background::Background(read params): Container(params){}

//========================================

Panic::Panic(read params):RoundBtn(params){}

bool Panic::onClick(int x, int y){
    if (inRange(x,y)){
        cout << "PANIC" << endl;
        return true;
    }
    return false;
}

void Panic::change(map<string, state> *allState){}

//========================================

OffBtn::OffBtn(read params):RoundBtn(params){
    group = -2;
}

bool OffBtn::onClick(int x, int y){
    if (inRange(x,y)){
        return true;
    }
    return false;
}

//========================================

Battary::Battary(read params):Container(params){}

void Battary::change(map<string, state> *allState){}

//========================================

Speed::Speed(read params):Container(params){}

//========================================

Arrow::Arrow(read params):Container(params){}

void Arrow::change(map<string, state> *allState){}

void Arrow::move(int newx,int newy, int angle){}

//========================================

Map::Map(read params):RectBtn(params){}

void Map::change(map<string, state> *allState){}

bool Map::onClick(int x, int y){
    if (inRange(x,y))
    return false;
}

//========================================

BtnMap::BtnMap(read params):RectBtn(params){
    group = 2;
    isActive = 1;
}

bool BtnMap::onClick(int x, int y){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
        }
        else{
            isActive = 0;
        }
        return true;
    }
    return false;
}

void BtnMap::change(map<string, state> *allState){}

//========================================

BtnLid::BtnLid(read params):RectBtn(params){
    group = 2;
}

bool BtnLid::onClick(int x, int y){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
        }
        else{
            isActive = 0;
        }
        return true;
    }
    return false;
}

void BtnLid::change(map<string, state> *allState){}

//========================================

BtnFPV::BtnFPV(read params):RectBtn(params){
    group = 2;
}

bool BtnFPV::onClick(int x, int y){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
        }
        else{
            isActive = 0;
        }
        return true;
    }
    return false;
}

void BtnFPV::change(map<string, state> *allState){}

//========================================

MapMin::MapMin(read params):Container(params){}

void MapMin::change(map<string, state> *allState){}

void MapMin::move(int newx, int newy, int angle){

}

//========================================

Micro::Micro(read params):RectBtn(params){}

bool Micro::onClick(int x, int y){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
        }
        else{
            isActive = 0;
        }
        return true;
    }
    return false;
}

void Micro::change(map<string, state> *allState){

}

//========================================

Dinamic::Dinamic(read params):RectBtn(params){}

bool Dinamic::onClick(int x, int y){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
        }
        else{
            isActive = 0;
        }
        return true;
    }
    return false;
}

void Dinamic::change(map<string, state> *allState){

}

//========================================

Text::Text(read params):Container(params){}

void Text::change(map<string, state> *allState){

}
