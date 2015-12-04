#ifndef TEXTCONTAINER_H
#define TEXTCONTAINER_H
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <SDL/SDL_ttf.h>
#include <iostream>


using namespace std;

class TextContainer
{
public:
    TextContainer(int textSize, int width, int height);
    ~TextContainer();
    void add(string added);
    const vector<string*>& print();
    int getInset();
    TTF_Font* getFonts();
    size_t getPadding_lr();
    size_t getPadding_top();
    size_t getTextSize();
    void setPadding(size_t _padding_top, size_t _padding_lr);
private:
    size_t _size;
    size_t _inset;
    size_t _length;
    size_t _padding_top = 5;
    size_t _padding_lr = 5;
    size_t _width;
    size_t _height;
    size_t _textSize;
    void lengthCalc();
    void sizeCalc();
    TTF_Font* _fonts;
    vector<string*> parse(string&);
    vector<string*> _container;
};

#endif // TEXTCONTAINER_H
