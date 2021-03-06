#include "container.h"

//описание базового класса

Container::Container(read params){
    name = params.nameBlock;
    img buf;
    for (size_t i = 0; i < params.images.size(); i++){
        buf.desc.x = params.images[i].x;
        buf.desc.y = params.images[i].y;
        buf.screen = IMG_Load(params.images[i].path.c_str());
        if (buf.screen == NULL){
            cout << "2" << endl;
        }
        allImg.push_back(buf);
    }
}

void Container::decont(){
    isActive = 0;
}

void Container::enable(){
    isActive = 1;
}

bool Container::isName(string myName){
    if (name == myName){
        return true;
    }
    return false;
}

bool Container::isVisible(){
    return visible;
}

void Container::setVisible(bool param){
    visible = param;
}
