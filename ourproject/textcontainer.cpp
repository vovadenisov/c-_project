#include "textcontainer.h"


TextContainer::TextContainer(int textSize, int width, int height){
    //определить _size, _length, _inset
    //инициализируем шрифты
    _fonts = TTF_OpenFont("fonts/ARIAL.TTF", textSize);
    if (!_fonts){
        cout << "не нашел шрифты" << endl;
    }
    _width = width;
    _height = height;
    _textSize = textSize;
    lengthCalc();
    sizeCalc();
}

void TextContainer::lengthCalc(){
    int temp = _width - 2 * _padding_lr;//определяем реальную ширину текстового поля
    _length = (int)(temp / (_textSize / 1.2));//определяем количество символов в одной строке
}

void TextContainer::setPadding(size_t padding_top, size_t padding_lr){
    _padding_lr = padding_lr;
    _padding_top = padding_top;
    lengthCalc();
    sizeCalc();
}

void TextContainer::sizeCalc(){
    int temp = _height - 2* _padding_top;//реальная высота текстового поля
    _size = temp / (_textSize * 1.5);//определяем количество строк
    _inset = _textSize / 2;//определяем межстрочный интервал
}

TextContainer::~TextContainer(){
    while(!_container.empty()){
        delete(_container.back());
        _container.pop_back();
    }
}

void TextContainer::add(string added){
    vector<string*> oneString = parse(added);
    for (int i = 0; i < oneString.size(); i++){
        if(_container.size() == _size){
            delete _container.front();
            _container.erase(_container.begin());
        }
        _container.push_back(oneString[i]);
    }
}

int TextContainer::getInset(){
    return _inset;
}

const vector<string*>& TextContainer::print(){
    return _container;
}
//спросить у петрова const vector<strng*>& при возврате локального объекта
vector<string*> TextContainer::parse(string& added){
    vector<string*> formStr;
    if(added.size() < _length){
        string* buf = new string(added);
        formStr.push_back(buf);
        return formStr;
    }
    do{
        string* buf;
        if(added.size() > _length){
            int pos = added.rfind(" ",_length);
            if (pos != std::string::npos){
                buf = new string(added.begin(),added.begin()+ pos);
                added.erase(added.begin(), added.begin() + pos + 1);
            }
            else{
                buf = new string(added.begin(), added.begin() + _length);
                added.erase(added.begin(), added.begin() + _length);
            }
        }
        else{
            buf = new string(added);
            added.erase(added.begin(),added.end());
        }
        formStr.push_back(buf);
    }while(added.size() > 0);
    return formStr;
}

size_t TextContainer::getPadding_top(){
    return _padding_top;
}

size_t TextContainer::getPadding_lr(){
    return _padding_lr;
}

size_t TextContainer::getTextSize(){
    return _textSize;
}

TTF_Font* TextContainer::getFonts(){
    return _fonts;
}
