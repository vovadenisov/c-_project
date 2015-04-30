#include "ourproject.h"
#include <string>
#include <fstream>
#define BACK "0back"

using namespace std;

OurProject::OurProject(){
    moduls = new vector<Container>;
    //arr = new map<string, map<string, img> >;
    //state = new map<string, string>;
    back = NULL;
}

void OurProject::SelectClass(read& value, Container*& position){
    switch (value.nameBlock.c_str())
    case "minion":{
        break;
    }
    case "arrow":{
        break;
    }
    case "panic":{
        break;
    }
    case "start":{
        break;
    }
    case "map":{
        break;
    }
    case "batary":{
        break;
    }
        case ""
}

/*
struct com{
    string name;
    form params;
};

struct read{
    string nameBlock;
    vector<com>* images;
};
*/

bool OurProject::init(/*map<string, map<string, form> >* come*/ vector<read>& come /* кто мне подскажет кто расскажет, что мы принимаем...*/){
    //size = comSize;
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "1" << endl;
        return false;
    }
    //а тут начинается полный треш
    moduls = new vector<Container*>(come.size());
    for (int i = 0; i < come.size(); i++){
        selectClass( come[i], (*moduls)[i] );
    }//заполнили массив элементов

    /*arr = new map <string,map<string, img> >;
    for (map<string,map<string,form> >::iterator it = (*come).begin();it != (*come).end(); it++){
        for(map<string,form>::iterator on = (*come)[it->first].begin(); on != (*come)[it->first].end(); on++ ){
            (*arr)[it->first][on->first].desc.x = on->second.x;
            cout << (*arr)[it->first][on->first].desc.x;
            (*arr)[it->first][on->first].desc.y = on->second.y;
            (*arr)[it->first][on->first].screen = IMG_Load(on->second.path.c_str());
            if ((*arr)[it->first][on->first].screen == NULL){
                cout << "2" << endl;
                return false;
            }
        }
    }
    for (map<string,map<string,img> >::iterator it = (*arr).begin();it != (*arr).end(); it++){
        state[it->firts]= (it->second)
//        if((*arr)[it->first][on->first].visible){
//                SDL_BlitSurface( (*arr)[it->first][on->first].screen, NULL, back, &((*arr)[it->first][on->first].desc));
//        }
    }*/ //старый вариант

    //уже непонятно для чего это было нужно. супер старый вариант.
    //all = new img[size];
//    for (int i = 0; i < size; i++){
//        all[i].screen = NULL;
//    }
    //проходимся по массиву и создаем массив загруженных и проинициализированных картинок.
    /*for (int i = 0; i < size; i++){
        arr[i].desc.x = arr[i].x;
        all[i].desc.y = arr[i].y;
        cout << arr[i].path << endl;
        all[i].screen = IMG_Load(arr[i].path.c_str());
        if (all[i].screen == NULL){
            cout << "2" << endl;
            return false;
        }
    }*/
    back = SDL_SetVideoMode(1360, 768, 16, SDL_HWSURFACE);
    if ( !back )
    {
        cout << "3" << endl;
        return false;
    }
    return true;
}

bool OurProject::MakeScreen(){
    for (int i = 0; i < moduls->size(); i++){
        SDL_BlitSurface( (*moduls)[i].drow().screen, NULL, back, &((*moduls)[i].drow().desc));
    }
//    for (map<string,map<string,img> >::iterator it = (*arr).begin();it != (*arr).end(); it++){
//        for(map<string,img>::iterator on = (*arr)[it->first].begin(); on != (*arr)[it->first].end(); on++ ){
//            if((*arr)[it->first][on->first].visible){
//                SDL_BlitSurface( (*arr)[it->first][on->first].screen, NULL, back, &((*arr)[it->first][on->first].desc));
//            }
//        }
//    }
//    for (int i = 0; i < size; i++){
//        SDL_BlitSurface(all[i].screen, NULL, back, &all[i].desc);
//    }
}

bool OurProject::startScreen(){
    SDL_Flip(back);
}

//весь код ниже лег на плечи классов

//bool belong(int cord, int range, int come){
//    return (come > cord && come < cord + range);
//}

//bool OurProject::detectModule(int x, int y, string* name, string* state){
//    for (map<string,map<string,img> >::iterator it = (*arr).begin();it != (*arr).end(); it++){
//        for(map<string,img>::iterator on = (*arr)[it->first].begin(); on != (*arr)[it->first].end(); on++ ){
//            if( belong((*arr)[it->first][on->first].desc.x, (*arr)[it->first][on->first].screen->w, x) &&
//                 belong((*arr)[it->first][on->first].desc.y, (*arr)[it->first][on->first].screen->h, y)){
//                *name = it->first;
//                if (*name != BACK){
//                    *state = (*state[it->first]);
//                    return true;
//                }
//            }
//        }
//    }
//}



//void OurProject::selectFunc(string modName, int state){
//    if (modName == "1stuart"){
//        cout << "я стюарт" << endl;
//    }
//    else
//        cout << "я не стюарт" << endl;

//}
