#include "ourproject.h"
//описание графического класса


OurProject* OurProject::p_instance = 0;

OurProject* OurProject::getInstance(queue<string>* command) {
    if(!p_instance)
        p_instance = new OurProject(command);
    return p_instance;
}

OurProject::OurProject( queue<string>* myQueue){
    commands = myQueue;
    back = NULL;
}

void OurProject::change(string nameVal, int ValVal){
    pair<string, int> value;
    value.first = nameVal;
    value.second = ValVal;
    for (int i = moduls.size() - 1; i >= 0; i--){
        moduls[i]->change(value);
    }
}

void OurProject::makeClass(char *file_name){
    ifstream pFile;
    pFile.open(file_name);

    if (pFile == NULL)
    {
        perror ("Error opening file");//аварийное завершение
    }
    size_t size;
    pFile >> size;
    for (size_t i = 0; i < size; i++){
        read buf;
        pFile >> buf.nameBlock;
        size_t modSize;
        pFile >> modSize;
        for (size_t j = 0; j < modSize; j++){
            com elBuf;
            pFile >> elBuf.x;
            pFile >> elBuf.y;
            pFile >> elBuf.path;
            buf.images.push_back(elBuf);
        }
        moduls.push_back(selectClass(buf));
    }
}

void OurProject::onClick(int x, int y){
    for (int i = moduls.size() - 1; i >= 0; i--){
        if (moduls[i]->onClick(x, y, commands)){
            if (moduls[i]->Group() != -1){
                correctModule(i, moduls[i]->Group());
            }
            if (moduls[i]->Group() == -2){
                active = false;
            }
            break;
        }
    }
    parseCommand();
}


void OurProject::correctModule(int valid, int group){
    for (int i = 0; i < moduls.size(); i++){
        if ((group == moduls[i]->Group()) && i != valid){
            moduls[i]->decont();
        }
    }
}

bool OurProject::init(){
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL_INIT_VIDEO" << endl;
        return false;
    }
    back = SDL_SetVideoMode(1366, 768, 16, SDL_HWSURFACE);
    if ( !back )
    {
        cout << "make videoMode" << endl;
        return false;
    }
    if(TTF_Init()){
        cout << "ttf_init" << endl;
       return false;
    }
    return true;
}
//добавление текста в текстовое поле
void OurProject::printText(string com){
    pair<string, string> value;
    value.first = "textAria";
    value.second = com;
    for (int i = 0; i < moduls.size(); i++){
        moduls[i]->change(value);
    }
}

void OurProject::photo(int size, char* data){
    FILE *f;
    f = fopen("new.jpeg","wb");
    fwrite(data, sizeof(uint8_t), size, f);
}

bool OurProject::MakeScreen(){
    for (size_t i = 0; i < moduls.size(); i++){
        if ((*(moduls[i])).isVisible()){
            img buf = (*(moduls[i])).Drow();
            SDL_BlitSurface( buf.screen, buf.src, back, &(buf.desc));
        }
    }
    return true;
}

bool OurProject::startScreen(){
    SDL_Flip(back);
    return true;
}

void OurProject::choiceEvent(SDL_Event* event){
    while (SDL_PollEvent(event)){
        switch(event->type){
            case SDL_QUIT: // Событие выхода
                active = true;
            case SDL_MOUSEBUTTONDOWN:{
                if (event->button.button == SDL_BUTTON_LEFT){
                    onClick(event->button.x,event->button.y);
                }
                break;
            }
            case SDL_KEYDOWN://map событий.
            {
                switch(event->key.keysym.sym){
                    case SDLK_g:
                    {
                        commands->push("<swapCam>");
                        break;
                    }
                    case SDLK_w: // Клавиша B
                    {
                        if (selfie){
                            selfie = false;
                            change("selfie",0);
                            printText("Let's move!");
                            commands->push("<swapCam>");
                            commands->push("<up>");
                        }
                        commands->push("<forward>");
                        break;
                    }
                    case SDLK_s:
                    {
                        if (selfie){
                            selfie = false;
                            change("selfie",0);
                            printText("Let's move!");
                            commands->push("<swapCam>");
                            commands->push("<up>");
                        }
                        commands->push("<backward>");
                        break;
                    }
                    case SDLK_d:
                    {
                        if (selfie){
                            selfie = false;
                            change("selfie",0);
                            commands->push("<up>");
                            commands->push("<swapCam>");
                            printText("Let's move!");
                        }
                        commands->push("<right>");
                        break;
                    }
                    case SDLK_a:
                    {
                        if (selfie){
                            commands->push("<up>");
                            change("selfie",0);
                            commands->push("<swapCam>");
                            printText("Let's move!");
                            selfie = false;
                        }
                        commands->push("<left>");
                        break;
                    }
                }
                break;
            }
            case SDL_KEYUP:
            {
                switch (event->key.keysym.sym) {
                    case SDLK_w:
                    {

                        //printText("Do not go ahead");
                        commands->push("</forward>");
                        break;
                    }
                    case SDLK_s:
                    {
                        //printText("Do not go back");
                        commands->push("</backward>");
                        break;
                    }
                    case SDLK_d:
                    {
                        //printText("Do not go right");
                        commands->push("</right>");
                        break;
                    }
                    case SDLK_a:
                    {
                        //printText("Do not go left");
                        commands->push("</left>");
                        break;
                    }
                }
            }
        }
    }
}

void  OurProject::putVideo(uint8_t* data, int size){
    if(*video){
        //cout << "удалил" << endl;
        SDL_FreeSurface(*video);
        *video = NULL;
    }
    cout << "обработка кадра" << endl;
    //printf("%x %x \n",data[0], data[size-1]);
    SDL_RWops *rw = SDL_RWFromMem(data,size);
    SDL_Surface *temp = IMG_Load_RW(rw, 1);
    if (temp){
        *video = SDL_DisplayFormat(temp);
        //Free the temporary surface
        SDL_FreeSurface(temp);
    }

}

void OurProject::parseCommand(){
    queue<string> buf;
    while(!commands->empty()){
        string strBuf = commands->front();
        ActivateComm(strBuf);
        commands->pop();
        buf.push(strBuf);
    }
    while(!buf.empty()){
        string strBuf = buf.front();
        buf.pop();
        commands->push(strBuf);
    }
}

void OurProject::ActivateComm(string comm){
    for (int i = 0; i < moduls.size(); i++){
        if (comm == "<video>"){
            if (moduls[i]->isName("video")){
                moduls[i]->setVisible( true );
            }
            if (moduls[i]->isName("map")){
                moduls[i]->setVisible( false );
            }
            if (moduls[i]->isName("MapMin")){
                moduls[i]->setVisible( false );
            }
        }
        if (comm == "</video>"){
            if (moduls[i]->isName("video")){
                moduls[i]->setVisible( false );
            }
            if (moduls[i]->isName("map")){
                moduls[i]->setVisible( true );
            }
            if (moduls[i]->isName("MapMin")){
                moduls[i]->setVisible( true );
            }
        }
    }
}

Container* OurProject::selectClass(read& value){
    //должен выбрать класс из всех возможных по имени и вернуть указатель на него, приведенный к контейнеру
    Container* refundable = NULL;
    if (value.nameBlock == "back"){
        Background* back = new Background(value);
        refundable = back;
    }
    if (value.nameBlock == "jerry"){
        Minion* jerry = new Minion(value);
        refundable = jerry;
    }
    if (value.nameBlock == "jorge"){
        Minion* jorge = new Minion(value);
        refundable = jorge;
    }
    if (value.nameBlock == "dave"){
        Minion* dave = new Minion(value);
        refundable = dave;
    }
    if (value.nameBlock == "stuart"){
        Minion* stuart = new Minion(value);
        refundable = stuart;
    }
    if (value.nameBlock == "mark"){
        Minion* mark = new Minion(value);
        refundable = mark;
    }
    if (value.nameBlock == "tim"){
        Minion* tim = new Minion(value);
        refundable = tim;
    }
    if (value.nameBlock == "phil"){
        Minion* phil = new Minion(value);
        refundable = phil;
    }
    if (value.nameBlock == "panic"){
        Panic* panic = new Panic(value);
        refundable = panic;
    }
    if (value.nameBlock == "offBtn"){
        OffBtn* off = new OffBtn(value);
        refundable = off;
    }
    if (value.nameBlock == "batteryOne"){
        Battery* battaryOne = new Battery(value);
        refundable = battaryOne;
    }
    if (value.nameBlock == "batteryTow"){
        Battery* battaryToo = new Battery(value);
        refundable = battaryToo;
    }
    if (value.nameBlock == "speed"){
        Speed* speed = new Speed(value);
        refundable = speed;
    }
    if (value.nameBlock == "arrow"){
        Arrow* arrow = new Arrow(value);
        refundable = arrow;
    }
    if (value.nameBlock == "map"){
        Map* ourMap = new Map(value);
        refundable = ourMap;
    }
    if (value.nameBlock == "video"){
        Video* myVideo = new Video(value, video);
        myVideo->setVisible(false);
        refundable = myVideo;
    }
    if (value.nameBlock == "btnMap"){
        BtnMap* btnMap = new BtnMap(value, &selfie);
        refundable = btnMap;
    }
    if (value.nameBlock == "btnLid"){
        BtnLid* btnLid = new BtnLid(value);
        refundable = btnLid;
    }
    if (value.nameBlock == "btnFPV"){
        BtnFPV* btnFPV = new BtnFPV(value);
        refundable = btnFPV;
    }
    if (value.nameBlock == "MapMin"){
        MapMin* mapMin =  new MapMin(value);
        refundable = mapMin;
    }
    if (value.nameBlock == "micro"){
        Micro* micro =  new Micro(value);
        refundable = micro;
    }
    if (value.nameBlock == "dinamic"){
        Dinamic* dinamic =  new Dinamic(value);
        refundable = dinamic;
    }
    if (value.nameBlock == "textAria"){
        Text* textArea =  new Text(value, 20);

        refundable = textArea;
    }
    return refundable;
}
