#include <ourproject.h>
#include <allclass.h>
#include <container.h>
#include <SDL/SDL_image.h>
using namespace std;

int main()
{
    OurProject* graphic;
    graphic = new OurProject;
    graphic->makeClass("images.txt");
    graphic->init();
    SDL_Event event;
    while(graphic->active){
        graphic->MakeScreen();
        graphic->startScreen();
        graphic->choiceEvent(&event);
    }
    return 0;
}
