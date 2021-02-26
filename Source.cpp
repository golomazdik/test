#include <SDL.h>
#include<iostream>
using namespace std;

const int SCREEN_WIDTH = 640; //- размер 
const int SCREEN_HEIGHT = 480; // -размер 

struct Rect
{
    int x, y, dx, dy;
    int r, g, b;
};

void DrawRect(Rect rect[3], SDL_Window* window, SDL_Renderer* renderer)
{
    for (int i = 0; i < 3; i++)
    {
        SDL_SetRenderDrawColor(renderer, rect[i].r, rect[i].g, rect[i].b, 0);
        SDL_Rect rect2 = { rect[i].x, rect[i].y, rect[i].dx, rect[i].dy };
        SDL_RenderFillRect(renderer, &rect2);
    }
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL не смог запуститься! SDL_Error:" << SDL_GetError(); //- проверка на открытие окна;
    }
    else
    {
        SDL_Window* window = NULL; //окно 
        SDL_Surface* screenSurface = NULL; //Поверхность окна
        window = SDL_CreateWindow(u8"Лабораторная_20 задание №1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            cout << " SDL_Error:" << SDL_GetError();
        }
        else
        {
            SDL_Init(SDL_INIT_EVERYTHING);
            SDL_Window* window = SDL_CreateWindow("HI",
                100, 100,
                800, 600, SDL_WINDOW_SHOWN);
            SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

            SDL_SetRenderDrawColor(renderer, 10, 10, 50, 0);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);

            SDL_Event event;
            bool quit = false;

            Rect r[3] = { 0,0,50,50,50,50,100, 0,60,50,50,50,100,50, 0,120,50,50,100,50,50 };
            DrawRect(r, window, renderer);
            while (!quit)
            {
                SDL_PollEvent(&event);
                if (event.type == SDL_QUIT)
                    quit = true;
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    SDL_SetRenderDrawColor(renderer, 77, 88, 90, 0);
                    SDL_RenderClear(renderer); SDL_RenderPresent(renderer);
                }


                if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    SDL_SetRenderDrawColor(renderer, 45, 55, 66, 0);
                    SDL_RenderClear(renderer); SDL_RenderPresent(renderer);
                }


                if (event.button.button == SDL_BUTTON_LEFT) {
                    for (int i = 0; i < 3; i++)
                        if ((event.button.x >= r[i].x) && (event.button.x <= r[i].x + r[i].dx) && (event.button.y >= r[i].y) && (event.button.y <= r[i].y + r[i].dy))
                        {
                            SDL_SetRenderDrawColor(renderer, r[i].r + 30, r[i].g + 30, r[i].b + 30, 0);
                            SDL_RenderClear(renderer);
                            DrawRect(r, window, renderer);
                            SDL_RenderPresent(renderer);
                        }

                }

            }

            SDL_DestroyWindow(window);
            SDL_FreeSurface(screenSurface);
            SDL_Quit();
        }
        return 0;
    }
}