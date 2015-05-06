#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif
#include <SDL_ttf.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

#define COLOR_BLUE 0
#define COLOR_GREEN 1
#define COLOR_ORANGE 2
#define COLOR_RED 3
#define COLOR_VIOLETT 4
#define COLOR_YELLOW 5
#define maps 14

bool done;
char tmpch[100];
SDL_Surface * screen, * block[6];
SDL_Event event;
int xpos, ypos, map[maps][maps], startclr, step;

void DrawImage(SDL_Surface * img, int x, int y, int w, int h, int sx, int sy)
{
    SDL_Rect desc;
    desc.x = x;
    desc.y = y;
    SDL_Rect src;
    src.x = sx;
    src.y = sy;
    src.w = w;
    src.h = h;
    SDL_BlitSurface(img, &src, screen, &desc);
}

void CleanImage(int x, int y, int w, int h)
{
    SDL_Rect desc;
    desc.x = x;
    desc.y = y;
    desc.w = w;
    desc.h = h;
    SDL_FillRect(screen, &desc, 0);
}

int InitImages()
{
    for (int i = 0; i < 6; i++)
    {
        char path[20];
        for (int j = 0; j < 20; j++)
            path[j] = 0;
        sprintf(path, "Block%c.bmp", (char)(i + '0'));
        block[i] = SDL_LoadBMP(path);
        if (!block[i])
            return -1;
    }
    return 1;
}

void DrawBlock(int x, int y)
{
    DrawImage(block[map[x][y]], 30 * x, 30 * y, 30, 30, 0, 0);
}

void GenMap()
{
    for (int i = 0; i < maps; i++)
        for (int j = 0; j < maps; j++)
            map[i][j] = rand() % 6;
}

void dfs(int x, int y, int clr)
{
    map[x][y] = clr;
    DrawBlock(x, y);
    if (x - 1 >= 0 && map[x - 1][y] == startclr)
        dfs(x - 1, y, clr);
    if (x + 1 < maps && map[x + 1][y] == startclr)
        dfs(x + 1, y, clr);
    if (y - 1 >= 0 && map[x][y - 1] == startclr)
        dfs(x, y - 1, clr);
    if (y + 1 < maps && map[x][y + 1] == startclr)
        dfs(x, y + 1, clr);
}

void DrawMap()
{
    for (int i = 0; i < maps; i++)
        for (int j = 0; j < maps; j++)
            DrawBlock(i, j);
}

void AddColor(int clr)
{
    if (clr == map[0][0])
        return;
    step++;
    startclr = map[0][0];
    dfs(0, 0, clr);
}

void WriteText(int x, int y, char text[100], int sz, int r, int g, int b)
{
    SDL_Color clr;
    clr.r = r;
    clr.g = g;
    clr.b = b;
    TTF_Font * fnt = TTF_OpenFont("block.ttf", sz);
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_Surface * sText = TTF_RenderText_Blended(fnt, text, clr);
    SDL_BlitSurface(sText, NULL, screen, &dest);
    SDL_FreeSurface(sText);
    TTF_CloseFont(fnt);
}

bool FinishGame()
{
    int clr = map[0][0];
    for (int i = 0; i < maps; i++)
        for (int j = 0; j < maps; j++)
            if (map[i][j] != clr)
                return false;
    return true;
}

void DrawStep()
{
    CleanImage(430, 50, 150, 100);
    for (int i = 0; i < 100; i++)
        tmpch[i] = 0;
    if (FinishGame())
    {
        CleanImage(430, 50, 150, 20);
        for (int i = 0; i < 100; i++)
            tmpch[i] = 0;
        if (step <= 25)
            sprintf(tmpch, "You win!"), WriteText(430, 50, tmpch, 20, 0, 255, 0);
        else
            sprintf(tmpch, "Not bad!"), WriteText(430, 50, tmpch, 20, 255, 255, 0);
        for (int i = 0; i < 100; i++)
            tmpch[i] = 0;
        sprintf(tmpch, "Result:%d", step);
        WriteText(430, 80, tmpch, 20, 255, 255, 0);
        step = 0;
        GenMap();
        DrawMap();
    }
    else
    {
        sprintf(tmpch, "%d%s", step, "/25");
        if (step <= 25)
            WriteText(430, 50, tmpch, 20, 0, 255, 0);
        else
            WriteText(430, 50, tmpch, 20, 255, 0, 0);
    }
}

int main ( int argc, char** argv )
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    TTF_Init();
    srand(time(NULL));
    atexit(SDL_Quit);
    atexit(TTF_Quit);
    SDL_Surface * screen = SDL_SetVideoMode(550, 420, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        return 1;
    }
    if (InitImages() < 0)
    {
        printf("Unable to load image: %s\n", SDL_GetError());
        return 1;
    }

    for (int i = 0; i < 6; i++)
        DrawImage(block[i], 440, 200 + 30 * i, 30, 30, 0, 0);
    WriteText(470, 197, ":B", 35, 77, 109, 242);
    WriteText(470, 227, ":G", 35, 34, 176, 76);
    WriteText(470, 257, ":O", 35, 255, 193, 14);
    WriteText(470, 287, ":R", 35, 236, 28, 36);
    WriteText(470, 317, ":V", 35, 111, 49, 151);
    WriteText(470, 347, ":Y", 35, 255, 241, 0);
    GenMap();
    DrawMap();
    DrawStep();
    SDL_Flip(screen);
    while (!done)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            {
                done = true;
                break;
            }
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    {
                        done = true;
                        break;
                    }
                    case SDLK_b:
                    {
                        AddColor(COLOR_BLUE), DrawStep(), SDL_Flip(screen);
                        break;
                    }
                    case SDLK_g:
                    {
                        AddColor(COLOR_GREEN), DrawStep(), SDL_Flip(screen);
                        break;
                    }
                    case SDLK_o:
                    {
                        AddColor(COLOR_ORANGE), DrawStep(), SDL_Flip(screen);
                        break;
                    }
                    case SDLK_r:
                    {
                        AddColor(COLOR_RED), DrawStep(), SDL_Flip(screen);
                        break;
                    }
                    case SDLK_v:
                    {
                        AddColor(COLOR_VIOLETT), DrawStep(), SDL_Flip(screen);
                        break;
                    }
                    case SDLK_y:
                    {
                        AddColor(COLOR_YELLOW), DrawStep(), SDL_Flip(screen);
                    }
                }
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                if (event.button.button = SDL_BUTTON_LEFT)
                {
                    int x = event.button.x, y = event.button.y;
                    if (x < 30 * maps && y < 30 * maps)
                        AddColor(map[x / 30][y / 30]);
                    else
                        if (x >= 439 && x <= 470 && y >= 200 && y <= 410)
                            AddColor((y - 200) / 30);
                    DrawStep();
                    SDL_Flip(screen);
                }
                break;
            }
        }
    }
    printf("Exited cleanly\n");
    return 0;
}
