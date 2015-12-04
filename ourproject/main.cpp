#include <ourproject.h>
#include <allclass.h>
#include <container.h>
#include <SDL/SDL_image.h>
#include <Server.h>
#include <time.h>
#include <wrapper.h>
#include "Client.h"

using namespace std;

void parse_video(uint8_t* data, int read);

int main()
{
    wrapper wrap;
    wrap.add("frame","<frame>");
    wrap.add("video","<video>");
    wrap.add("audio", "<audio>");
    wrap.add("up", "<forward>");
    wrap.add("stop", "</forward>");
    wrap.add("battery2", "<battery2>");
    wrap.add("battery1", "<battery1>");
    queue<string> commands;
    OurProject* graphic = OurProject::getInstance(&commands)/*new OurProject(&commands)*/;
    graphic->init();
    graphic->makeClass("images.txt");
    Server server(53000);
    if(server.open() == 1){
        graphic->printText("TCP server opened!");
        cout << "TCP server opened!"<< endl;
    }
    else{
        graphic->printText("TCP server connection failed!");
        cout << "TCP server connection failed!" << endl;
    }
    SDL_Event event;
//    int client = 0;
    while(graphic->active){
        char data[BYTES2READ + 1];
//        int temp = server.checkNewClient();
//        if (!temp && temp != client){
//            graphic->printText("new client joined");
//        }
//        if (server.checkNewClient()){
//            client = server.checkNewClient();
//        }

        int read = server.readData(data);
        if (server.newClient){
            graphic->printText("I have new Client");
            graphic->change("stuart",1);
        }
        //  wrap.unpack((uint8_t*)"<video>", testSize);
        if(read > 0){
            wrap.unpack((uint8_t*)data, read);
            for(int i = 0; i < wrap.command.size(); i++){//вынести в отдельный класс command знающий команды
                if(wrap.command[i].first == "frame"){
                    graphic->putVideo(wrap.command[i].second.second,wrap.command[i].second.first);
                }
                if(wrap.command[i].first == "battery1"){
                    graphic->change(string("batteryOne"),(int)(wrap.command[i].second.second)[0]);
                }
                if(wrap.command[i].first == "battery2"){
                    graphic->change(string("batteryTow"),(int)(wrap.command[i].second.second)[0]);
                }
//                if(wrap.command[i].first == "selfie"){
//                    graphic->photo(wrap.command[i].second.first, (char*)wrap.command[i].second.second);
//                }
            }
        }
        graphic->MakeScreen();
        graphic->startScreen();
        graphic->choiceEvent(&event);
        while(!commands.empty()){
            if(commands.front() == "<lower>"){
                graphic->printText("i'm ready for selfie");
            }
            server.writeData(server.numsocks - 1,(char*)commands.front().c_str(),commands.front().size());
            commands.pop();
        }
    }
    delete graphic;
    return 0;
}



