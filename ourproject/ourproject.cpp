#include "ourproject.h"
//описание графического класса

OurProject::OurProject(){
    back = NULL;
}

void OurProject::makeClass(char *file_name){
    ifstream pFile;
    pFile.open(file_name);

    if (pFile == NULL)
    {
        perror ("Error opening file");
    }
    size_t size;
    pFile >> size;
    for (size_t i = 0; i < size; i++){
        read buf;
        pFile >> buf.nameBlock;
        size_t modSize;
        pFile >> modSize;
        for (size_t j = 0; j < modSize; j++){
            com elBuf;
            pFile >> elBuf.x;
            pFile >> elBuf.y;
            pFile >> elBuf.path;
            buf.images.push_back(elBuf);
        }
        moduls.push_back(selectClass(buf));
    }
}

void OurProject::onClick(int x, int y){
    for (int i = moduls.size() - 1; i >= 0; i--){
        if (moduls[i]->onClick(x,y)){
            if (moduls[i]->Group() != -1){
                correctModule(i, moduls[i]->Group());
            }
            if (moduls[i]->Group() == -2){
                active = false;
            }
            break;
        }
    }
}

void OurProject::correctModule(int valid, int group){
    for (int i = 0; i < moduls.size(); i++){
        if ((group == moduls[i]->Group()) && i != valid){
            moduls[i]->decont();
        }
    }
}

//void OurProject::makeState(){
//    for (int i = 0; i < moduls[i].size(); i++){
//        state buf = moduls[i].getState();
//        for(int i = 0; i < actualState.size(); i++){
//            if (actualState[i].name == buf.name){
//                actualState[i].x = buf.x;
//                actualState[i].y = buf.y;
//                actualState[i].angle = buf.angle;
//                actualState[i].active = buf.active;
//            }
//        }
//        //
//    }
//}

bool OurProject::init(){
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "1" << endl;
        return false;
    }
    back = SDL_SetVideoMode(1360, 768, 16, SDL_HWSURFACE);
    if ( !back )
    {
        cout << "3" << endl;
        return false;
    }
    return true;
}

bool OurProject::MakeScreen(){
    for (size_t i = 0; i < moduls.size(); i++){
        img buf = (*(moduls[i])).Drow();
        SDL_BlitSurface( buf.screen, NULL, back, &(buf.desc));
    }
    return true;
}

bool OurProject::startScreen(){
    SDL_Flip(back);
    return true;
}

bool OurProject::choiceEvent(SDL_Event* event){
    while (SDL_PollEvent(event)){
        switch(event->type){
            case SDL_QUIT: // Событие выхода
                active = true;
            case SDL_MOUSEBUTTONDOWN:{
                if (event->button.button == SDL_BUTTON_LEFT){
                    onClick(event->button.x,event->button.y);
                }
                break;
            }
        }
    }
}

Container* OurProject::selectClass(read& value){
    //должен выбрать класс из всех возможных по имени и вернуть указатель на него, приведенный к контейнеру
    Container* refundable = NULL;
    if (value.nameBlock == "back"){
        Background* back = new Background(value);
        refundable = back;
    }
    if (value.nameBlock == "jerry"){
        Minion* jerry = new Minion(value,"192.268.0.1");
        refundable = jerry;
    }
    if (value.nameBlock == "jorge"){
        Minion* jorge = new Minion(value,"192.268.0.1");
        refundable = jorge;
    }
    if (value.nameBlock == "dave"){
        Minion* dave = new Minion(value,"192.268.0.1");
        refundable = dave;
    }
    if (value.nameBlock == "stuart"){
        Minion* stuart = new Minion(value,"192.268.0.1");
        refundable = stuart;
    }
    if (value.nameBlock == "mark"){
        Minion* mark = new Minion(value,"192.268.0.1");
        refundable = mark;
    }
    if (value.nameBlock == "tim"){
        Minion* tim = new Minion(value,"192.268.0.1");
        refundable = tim;
    }
    if (value.nameBlock == "phil"){
        Minion* phil = new Minion(value,"192.268.0.1");
        refundable = phil;
    }
    if (value.nameBlock == "panic"){
        Panic* panic = new Panic(value);
        refundable = panic;
    }
    if (value.nameBlock == "offBtn"){
        OffBtn* off = new OffBtn(value);
        refundable = off;
    }
    if (value.nameBlock == "battaryOne"){
        Battary* battaryOne = new Battary(value);
        refundable = battaryOne;
    }
    if (value.nameBlock == "battaryToo"){
        Battary* battaryToo = new Battary(value);
        refundable = battaryToo;
    }
    if (value.nameBlock == "speed"){
        Speed* speed = new Speed(value);
        refundable = speed;
    }
    if (value.nameBlock == "arrow"){
        Arrow* arrow = new Arrow(value);
        refundable = arrow;
    }
    if (value.nameBlock == "map"){
        Map* ourMap = new Map(value);
        refundable = ourMap;
    }
    if (value.nameBlock == "btnMap"){
        BtnMap* btnMap = new BtnMap(value);
        refundable = btnMap;
    }
    if (value.nameBlock == "btnLid"){
        BtnLid* btnLid = new BtnLid(value);
        refundable = btnLid;
    }
    if (value.nameBlock == "btnFPV"){
        BtnFPV* btnFPV = new BtnFPV(value);
        refundable = btnFPV;
    }
    if (value.nameBlock == "MapMin"){
        MapMin* mapMin =  new MapMin(value);
        refundable = mapMin;
    }
    if (value.nameBlock == "micro"){
        Micro* micro =  new Micro(value);
        refundable = micro;
    }
    if (value.nameBlock == "dinamic"){
        Dinamic* dinamic =  new Dinamic(value);
        refundable = dinamic;
    }
    if (value.nameBlock == "text"){
        Text* text =  new Text(value);
        refundable = text;
    }
    return refundable;
}
