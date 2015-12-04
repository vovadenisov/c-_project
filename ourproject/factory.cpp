#include "factory.h"

template <class C>
Factory<C>::Factory()
{
}

template <class C>
void Factory<C>::add(const std::string & id)
{
    typename FactoryMap::iterator it = _factory.find(id);
    if (it == _factory.end())
        _factory[id] = new ContainerCreator<C>();
}

