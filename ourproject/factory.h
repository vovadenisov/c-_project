#ifndef FACTORY_H
#define FACTORY_H
#include <string>
#include "container.h"

using namespace std;

class AbstractCreator{
public:
    virtual Container* Create() const = 0;
};

template <class C>
class ContainerCreator : public AbstractCreator
{
public:
    virtual Container* Create() const { return new C(); }
};


template <class C>
class Factory{
public:
    typedef std::map<std::string, AbstractCreator*> FactoryMap;
    FactoryMap _factory;
    Factory();
    Container *craate(const string& name);
    void add(const std::string & id);
};

#endif // FACTORY_H
