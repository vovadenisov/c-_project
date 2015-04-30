#include <ourproject.h>
#include <ReadFile.h>
#include <SDL/SDL_image.h>
using namespace std;

int main()
{
    OurProject graphic;
    map<string, map<string, form> > * arr;
    arr = read_file("images.txt");

    //проверка корректности чтения
    for (map<string,map<string,form> >::iterator it = (*arr).begin();it != (*arr).end(); it++){
        for(map<string,form>::iterator on = (*arr)[it->first].begin(); on != (*arr)[it->first].end(); on++ ){
            cout << it->first << " " << on->first << " " << on->second.x << " " << on->second.y << " " << on->second.path << endl;
        }
    }
    if (!graphic.init(arr)){
       cout << "я упал" << endl;
    }

    delete arr;

//    while (!done)
//    {
//        while (SDL_PollEvent(&event)) // Пока есть хоть одно необработанное событие
//        {
//            swtich(event.type)
//            {
//                case SDL_QUIT: // Событие выхода
//                    done = true;
//            }
//        }
//    }

    SDL_Event event;
    bool done = false;
    while(!done){
        graphic.MakeScreen();
        graphic.startScreen();
        while (SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT: // Событие выхода
                    done = true;
                case SDL_MOUSEBUTTONDOWN:{
                    if (event.button.button = SDL_BUTTON_LEFT){
                        string* modName = new string;
                        int* state = new int(0);
                        if (graphic.detectModule(event.button.x,event.button.y,modName,state)){
                            graphic.selectFunc(*modName, *state);
                            delete modName;
                            delete state;
                        }
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

