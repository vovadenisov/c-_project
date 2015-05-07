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
    Uint32 start;
    while(graphic->active){
        start = SDL_GetTicks();
        graphic->MakeScreen();
        graphic->startScreen();
        graphic->choiceEvent(&event);
        if (1000/19 < SDL_GetTicks() - start){
            cout << "низкий фпс" << endl;
        }
    }
    return 0;
}
