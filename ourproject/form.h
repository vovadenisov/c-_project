#ifndef FORM_H
#define FORM_H

#include <string>
#include <vector>

using namespace std;

//struct state{
//    int value;
//};

struct form{
    int x;
    int y;
    std::string path;
};



struct com{
    string name;
    form params;
};

struct read{
    string nameBlock;
    vector<com>* images;
};

template <class T>
struct element{
    string name;
    T* el;
    element* next;
};

#endif // FORM_H
