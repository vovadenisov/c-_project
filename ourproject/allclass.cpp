#define pi 3,14159
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

Minion::Minion(read params):RectBtn(params){
    group = 0;
}

void Minion::change(pair<string,int>allState){
    if (allState.first == name){
        isActive = allState.second;
    }
}

bool Minion::onClick(int x, int y, queue<string>* commands){
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

bool Panic::onClick(int x, int y, queue<string>* commands){
    if (inRange(x,y)){
        cout << "PANIC" << endl;
        return true;
    }
    return false;
}

void Panic::change(pair<string,int>allState){}

//========================================

OffBtn::OffBtn(read params):RoundBtn(params){
    group = -2;
}

bool OffBtn::onClick(int x, int y, queue<string>* commands){
    if (inRange(x,y)){
        return true;
    }
    return false;
}

//========================================

Battery::Battery(read params):Container(params){
    isActive = 4;
}

void Battery::change(pair<string, int> allState){
    cout << allState.first << "% :" << allState.second << endl;
    if (allState.first == name){
        if(allState.second < 0){
            isActive = 4;
        }
        if(allState.second >= 0){
            isActive = 3;
        }
        if(allState.second >= 10){
            isActive = 2;
        }
        if(allState.second > 30){
            isActive = 1;
        }
        if (allState.second > 70){
            isActive = 0;
        }
    }
}

//========================================

Speed::Speed(read params):Container(params){}

void Speed::change(pair<string,int>allState){}


//========================================

//    SpeedGroup::SpeedGroup(read params):Container(params){
//        scale = allImg[0];
//        arrow = allImg[1];
//    }

//    void change(pair<string, int> allState){};

//    void Speed::move(int angle){
//        SDL_Surface *surface;
//        Uint32 rmask, gmask, bmask, amask;
//        int w = allImg[1].screen->w;
//        #if SDL_BYTEORDER == SDL_BIG_ENDIAN
//        rmask = 0xff000000;
//        gmask = 0x00ff0000;
//        bmask = 0x0000ff00;
//        amask = 0x000000ff;
//        #else
//        rmask = 0x000000ff;
//        gmask = 0x0000ff00;
//        bmask = 0x00ff0000;
//        amask = 0xff000000;
//        #endif
//        int width = 0;
//        int height = 0;
//        if(angle < 90){
//            width = arrow.screen->w * cos((angle*pi / 180)) + arrow.screen->h * cos(((90 - angle ) * pi / 180));
//            height = arrow.screen->w * sin((angle*pi / 180)) + arrow.screen->h * sin(((90 - angle) * pi / 180));
//        }
//        else
//        {
//            width = arrow.screen->w * cos(((180 - angle)*pi / 180)) + arrow.screen->h * cos(((angle - 90) * pi / 180));
//            height = arrow.screen->w * sin(((180 - angle)*pi / 180)) + arrow.screen->h * sin(((angle - 90) * pi / 180));
//        }
//        surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, rmask, gmask, bmask, amask);
//        if(surface == NULL)
//        {
//            cout << "не могу создать поверхеность" << endl;
//        }
//        char* psrc = (char*)arrow.screen->pixels;
//        int bpp = arrow.screen->format->BytesPerPixel;
//    //    for (int i = 0; i < surface->h*surface->w; i++){
//    //        if ()
//    //    }

//    }

//========================================

Arrow::Arrow(read params):Container(params){}

//========================================

Map::Map(read params):RectBtn(params){}

void Map::change(pair<string,int>allState){}

bool Map::onClick(int x, int y, queue<string>* commands){
    if (inRange(x,y))
    return false;
}
//========================================

Video::Video(read params, SDL_Surface**& video):Container(params){
    //SDL_FreeSurface(allImg[0].screen);
    video = &(allImg[0].screen);
    allImg[0].src = new SDL_Rect;
    allImg[0].src->x = 0;
    allImg[0].src->y = 50;
    allImg[0].src->h = 420;
    allImg[0].src->w = 621;
}

//========================================

BtnMap::BtnMap(read params, bool* selfieFlag):RectBtn(params){
    group = 100;
    isActive = 0;
    selfie = selfieFlag;
}

bool BtnMap::onClick(int x, int y, queue<string>* commands){
    if(inRange(x,y)){
        if(isActive == 0 && !(*selfie)){
            cout << "lower" << endl;
            commands->push(("<swapCam>"));
            commands->push("<lower>");
            *selfie = true;
            isActive = 1;
        }
        else{
            cout << "foto" << endl;
            commands->push("<photo>");
        }
        return true;
    }
    return false;
}

void BtnMap::change(pair<string,int>allState){
    if (isActive == 1 && allState.first == "selfie"){
        isActive = 0;
        *selfie = false;
    }
}

//========================================

BtnLid::BtnLid(read params):RectBtn(params){
    group = 2;
}

bool BtnLid::onClick(int x, int y, queue<string>* commands){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
            commands->push("</video>");
        }
        else{
            isActive = 0;
        }
        return true;
    }
    return false;
}

void BtnLid::change(pair<string,int>allState){}

//========================================

BtnFPV::BtnFPV(read params):RectBtn(params){
    group = 2;
}

bool BtnFPV::onClick(int x, int y, queue<string>* commands){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
            commands->push("<video>");
        }
        else{
            isActive = 0;
            commands->push("</video>");
        }
        return true;
    }
    return false;
}

void BtnFPV::change(pair<string,int>allState){}

//========================================

MapMin::MapMin(read params):Container(params){}

void MapMin::change(pair<string,int>allState){}

void MapMin::move(int newx, int newy, int angle){

}

//========================================

Micro::Micro(read params):RectBtn(params){}

bool Micro::onClick(int x, int y, queue<string>* commands){
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

void Micro::change(pair<string,int>allState){

}

//========================================

Dinamic::Dinamic(read params):RectBtn(params){}

bool Dinamic::onClick(int x, int y, queue<string>* commands){
    if(inRange(x,y)){
        if(isActive == 0){
            isActive = 1;
            commands->push("<music>");
        }
        else{
            isActive = 0;
        }
        return true;
    }
    return false;
}


//========================================
//создание текстового контейнера на базе картинки и текстового контейнера.
Text::Text(read params, size_t textSize):Container(params), cont(textSize, allImg[0].screen->w, allImg[0].screen->h){
    base.desc = allImg[0].desc;
    base.desc.x = 0;
    base.desc.y = 0;
    base.screen = SDL_DisplayFormatAlpha(allImg[0].screen);
    if (base.screen == NULL){
        cout << "2" << endl;
    }
    textPos = allImg[0].desc;
}

void Text::change(pair<string, string>& allState){
    if (allState.first != name){
        cout << "имя не подошло" << endl;
        return;
    }
    cout << "имя подошло" << endl;
    cont.add(allState.second);
    vector<string*> temp = cont.print();
    cout << *(temp[0]) << endl;
    SDL_BlitSurface(base.screen, NULL, allImg[0].screen, &base.desc);
    for(int i = 0; i < temp.size(); i++){
        SDL_Color clr;
        clr.r = 0;
        clr.g = 0;
        clr.b = 0;
        SDL_Surface *sText = TTF_RenderText_Blended( cont.getFonts(), (temp[i])->c_str(), clr);
        SDL_Rect position = textPos;
        position.y = (cont.getTextSize() + cont.getInset()) * i + cont.getPadding_top();
        position.x = cont.getPadding_lr();
        SDL_Rect basePos = textPos;
        basePos.h = sText->h;
        basePos.w = sText->w;
        basePos.x = 0;
        basePos.y = 0;    
        if (!sText){
            cout << "пустой сурф" << endl;
        }
        SDL_BlitSurface( sText, NULL, allImg[0].screen, &position );
        //allImg[0].screen = sText;
        SDL_FreeSurface( sText );
    }
}
